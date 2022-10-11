//
// FlightSimAdventureCreator 1.0
//
// (c) Paul Alan Freshney 2022
//
// paul@freshney.org
// 
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
// 
// 

// https://docs.flightsimulator.com/html/Content_Configuration/SimObjects/Aircraft_SimO/aircraft_cfg.htm
// https://docs.flightsimulator.com/html/Content_Configuration/SimObjects/Aircraft_SimO/flight_model_cfg.htm

#include <algorithm>
#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

#include "Aircraft.h"
#include "AircraftConstants.h"
#include "Constants.h"
#include "Formatting.h"
#include "Ini.h"
#include "MSFSSystem.h"
#include "Utility.h"
#include "WindowsUtility.h"


// name=				; aircraft.cfg, [fltsim.x] ui_manufacturer and ui_type (unless localised, see code below)
// cruise=				; flight_model.cfg, [reference speeds], cruise_speed
// range=				; aircraft.cfg, [fltsim.x] ui_max_range
// availability=99		; all custom aircraft have this value
// type=				; aircraft.cfg, [fltsim.x] ui_typerole 
// military=			; aircraft.cfg, [fltsim.x] atc_parking_types could contain either MIL_COMBAT or MIL_CARGO (indicats military) (though not 100% reliable if not set)
// airliner=			; aircraft.cfg, [fltsim.x] ui_typerole 
// minrunway=			; cannot get this value from MSFS data files


namespace MSFSSystem
{
	static const std::wstring TypeRoles[] = { L"Commercial Airliner", L"747 - 400 V3",	L"747 - 400BCF V3",	L"747 - 400D V3", L"747 - 400ER V3", L"747 - 400ERF V3", L"747 - 400F V3", L"747 - 400M V3",
		L"Single Engine Prop", L"Twin Engine Prop", L"Single Engine TurboProp", L"Twin Engine TurboProp", L"Twin Engine Jet", L"Regional Jet", L"Single Engine Jet", L"Helicopter" };

	static const int TypeRoleToAircraftType[] = { 1, 1, 1, 1, 1, 1, 1, 1, 0, 4, 5, 6, 1, 1, 1, 2 };
	static const bool IsAirliner[] = { true, true, true, true, true, true, true, true, false, false, false, false, false, true, false, false };

	// this generates the custom_aircraft.txt file automatically from the Community folder
	bool CreateAircraftList(const std::wstring community_folder)
	{
		std::vector<std::wstring> msfsfolders;
		std::vector<Aircraft> aircraft;

		FindFolder(msfsfolders, community_folder);

		if (msfsfolders.size() != 0)
		{
			std::wcout << L"Found " << msfsfolders.size() << L" folders.\n";

			for (int t = 0; t < msfsfolders.size(); t++)
			{
				ProcessContentsFolder(aircraft, community_folder + msfsfolders[t]);
			}

			if (aircraft.size() != 0)
			{
				std::wcout << L"Found " << aircraft.size() << L" aircraft.\n";

				SaveCustomAircraftFile(aircraft, L"__" + SystemConstants::CustomAircraft);
			}
		}

		return false;
	}


	bool ProcessContentsFolder(std::vector<Aircraft>& found_aircraft, const std::wstring folder)
	{
		std::vector<std::wstring> simobjects;

		FindFolder(simobjects, folder + L"\\SimObjects\\Airplanes\\");

		if (simobjects.size() != 0)
		{
			for (int t = 0; t < simobjects.size(); t++)
			{
				if (WindowsUtility::FileExists(folder + L"\\SimObjects\\Airplanes\\" + simobjects[t] + L"\\aircraft.cfg"))
				{
					Ini* config = new Ini(folder + L"\\SimObjects\\Airplanes\\" + simobjects[t] + L"\\aircraft.cfg");

					if (config->Loaded)
					{
						std::wstring category = config->ReadString(L"FLTSIM.0", L"isUserSelectable", L"0");

						if (category == L"1")
						{
							std::wstring NameM = config->ReadString(L"fltsim.0", L"ui_manufacturer", L"");
							std::wstring NameT = config->ReadString(L"fltsim.0", L"ui_type", L"");

							std::wstring Name = NameM + L" / " + NameT;

							if (NameM.find(L"TT:") != std::wstring::npos || NameT.find(L"TT:") != std::wstring::npos)
							{
								Name = GetNameFromUSLocalisation(folder);
							}

							// =====================================================================================================================

							int range = config->ReadInteger(L"fltsim.0", L"ui_max_range", 0);

							// =====================================================================================================================

							std::wstring atype = config->ReadString(L"fltsim.0", L"ui_typerole", L"");

							int aircraft_type = -1;
							bool is_airliner = false;

							for (int x = 0; x < 16; x++)
							{
								if (TypeRoles[x] == atype)
								{
									aircraft_type = TypeRoleToAircraftType[x];

									is_airliner = IsAirliner[x];
								}
							}

							// =====================================================================================================================

							bool is_military = false;

							std::wstring atc_parking = config->ReadString(L"fltsim.0", L"atc_parking_types", L"");	// military aircraft can have either MIL_COMBAT or MIL_CARGO (or "MIL COMBAT" (I assume a typo))
							std::transform(atc_parking.begin(), atc_parking.end(), atc_parking.begin(), ::toupper);

							if (atc_parking.find(L"MIL") != std::wstring::npos)
							{
								is_military = true;
							}

							// =====================================================================================================================

							Ini* confige = new Ini(folder + L"\\SimObjects\\Airplanes\\" + simobjects[t] + L"\\flight_model.cfg");

							int cruise = 0;

							if (confige->Loaded)
							{
								cruise = confige->ReadInteger(L"reference speeds", L"cruise_speed", 0);
							}

							delete confige;

							if (cruise != 0)
							{
								Aircraft a(Name, cruise, range, 0, AircraftConstants::MSFSVersion::All, Utility::GetAircraftTypeFromInt(aircraft_type), is_military, is_airliner);

								found_aircraft.push_back(a);
							}
							else
							{
								std::wcout << std::format(L" Ignored, \"{0}\", suspect not an aircraft. Cruise speed is set to zero.\n", Name);
							}							
						}
					}
					else
					{
						std::wcout << std::format(L"\nCouldn't load file \"\\{0}\\aircraft.cfg\" :(\n", simobjects[t]);
					}

					delete config;
				}
			}
		}

		return false;
	}


	// so, the simobject system in MSFS allows developers to localise values in config files.
	// these can be found in the form TT:<key> where <key> is a key of a JSON key/value pair stored in a separate language file
	// we only need to look for two. it's worth noting that I've only seen one aircraft use this feature
	// but doesn't bother to actually localise the data. all of the language files contain the same English text.
	// yes, A1R Design Bureau, I'm looking at you!
	std::wstring GetNameFromUSLocalisation(const std::wstring folder)
	{
		std::wifstream file(folder + L"\\en-US.locPak");

		if (file)
		{
			std::wstring s = L"";

			std::wstring NameM = L"";
			std::wstring NameT = L"";

			while (std::getline(file, s))
			{
				if (s != L"")
				{
					if (s.find(L"AIRCRAFT.UI_MANUFACTURER") != std::wstring::npos)
					{
						NameM = StripFromJSON(s);
					}
					else if (s.find(L"AIRCRAFT.UI_MODEL") != std::wstring::npos)
					{
						NameT = StripFromJSON(s);
					}
				}
			}

			file.close();

			return NameM + L" / " + NameT;
		}

		return L"";
	}


	// this take an input in the form "TT:KEY.NAME" : "VALUE"
	// and returns VALUE without the quotes.
	std::wstring StripFromJSON(const std::wstring input)
	{
		auto i = input.find(L':');

		if (i != std::wstring::npos)
		{
			std::wstring Name = L"";
			bool inquotes = false;

			for (auto t = i; t < input.length(); t++)
			{
				if (input[t] == L'\"')
				{
					inquotes = !inquotes;
				}
				else
				{
					if (inquotes)
					{
						Name += input[t];
					}
				}
			}

			return Name;
		}

		return L"";
	}


	bool SaveCustomAircraftFile(std::vector<Aircraft>& found_aircraft, const std::wstring file_name)
	{
		std::ofstream ofile(file_name);

		if (ofile)
		{
			std::wcout << L"Saving config file: " << file_name << L"\n\n";

			for (int t = 0; t < found_aircraft.size(); t++)
			{
				ofile << Formatting::to_utf8(L"{\n");
				ofile << Formatting::to_utf8(L"name=" + found_aircraft[t].Name + L"\n");
				ofile << Formatting::to_utf8(L"cruise=" + std::to_wstring(found_aircraft[t].CruiseSpeed) + L"\n");
				ofile << Formatting::to_utf8(L"range=" + std::to_wstring(found_aircraft[t].Range) + L"\n");
				ofile << Formatting::to_utf8(L"availability=99\n");
				ofile << Formatting::to_utf8(L"type=" + std::to_wstring(Utility::GetAircraftTypeToConfigType(found_aircraft[t].Type)) + L"\n");
				ofile << Formatting::to_utf8(L"military=" + std::to_wstring(found_aircraft[t].Military) + L"\n");
				ofile << Formatting::to_utf8(L"airliner=" + std::to_wstring(found_aircraft[t].Airliner) + L"\n");
				ofile << Formatting::to_utf8(L"minrunway=0\n");
				ofile << Formatting::to_utf8(L"}\n\n");
			}

			ofile.close();

			return true;
		}
		else
		{
			// error
		}

		return false;
	}


	std::wstring GetFirstFolder(const std::wstring& location)
	{
		std::wstring tmp = location + L"*";
		std::wstring first_folder = L"";

		WIN32_FIND_DATAW file;

		HANDLE search_handle = FindFirstFileW(tmp.c_str(), &file);

		if (search_handle != INVALID_HANDLE_VALUE)
		{
			do
			{
				if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if ((!lstrcmpW(file.cFileName, L".")) || (!lstrcmpW(file.cFileName, L"..")))
						continue;

					first_folder = file.cFileName;
					break;
				}

			} while (FindNextFileW(search_handle, &file));

			FindClose(search_handle);
		}

		return first_folder;
	}


	void FindFolder(std::vector<std::wstring>& folders, const std::wstring& location)
	{
		std::wstring tmp = location + L"*";

		WIN32_FIND_DATAW file;

		HANDLE search_handle = FindFirstFileW(tmp.c_str(), &file);

		if (search_handle != INVALID_HANDLE_VALUE)
		{
			do
			{
				if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if ((!lstrcmpW(file.cFileName, L".")) || (!lstrcmpW(file.cFileName, L"..")))
						continue;

					folders.push_back(file.cFileName);
				}

			} while (FindNextFileW(search_handle, &file));

			FindClose(search_handle);
		}
	}
}