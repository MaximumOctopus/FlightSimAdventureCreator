//
// FlightSimAdventureCreator 1.0 (GUI Version)
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
// https://www.fsdeveloper.com/forum/threads/auto-detect-msfs-2020-community-path.449293/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <shlobj.h>
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
// airliner=			; aircraft.cfg, [fltsim.x] ui_typerole 
// military=			; aircraft.cfg, [fltsim.x] atc_parking_types could contain either MIL_COMBAT or MIL_CARGO (indicats military) (though not 100% reliable if not set)
// seaplane=0			; if runwaywater.flt or finalwater.flt exists then this is a seaplane
// minrunway=			; cannot get this value from MSFS data files


namespace MSFSSystem
{
	// this is the list according to the MS SDK, but it appears a developer can put anything they like in the ui_typerole field (eg Milviz use Fighter/Bomber for thier Corsair)
	static const std::wstring TypeRoles[] = { L"commercial airliner", L"747 - 400 v3",	L"747 - 400bcf v3",	L"747 - 400d v3", L"747 - 400er v3", L"747 - 400erf v3", L"747 - 400f v3", L"747 - 400m v3",
			L"single engine prop", L"twin engine prop", L"single engine turboprop", L"twin engine turboprop", L"twin engine jet", L"regional jet", L"single engine jet", L"helicopter" };

	static const int TypeRoleToAircraftType[] = { 1, 1, 1, 1, 1, 1, 1, 1, 0, 4, 5, 6, 1, 1, 1, 2 };
	static const bool IsAirliner[] = { true, true, true, true, true, true, true, true, false, false, false, false, false, true, false, false };

	// this generates the custom_aircraft.txt file automatically from the contents of the \Community\ folder
	// passing false to this function will cause it to scan the \Official\OneStore\ folder, this stores all default aircraft and marketplace purchases
	// however, many marketplace aircraft are mising aircraft.cfg and can't be added accurately to the default_aircraft.txt file :(
	bool CreateAircraftList(bool community)
	{
		std::vector<std::wstring> msfsfolders;
		std::vector<Aircraft> aircraft;

		std::wstring community_folder = GetCommunityFolderPath(community);

		if (community_folder != L"")
		{
			std::wcout << L"  Found community folder path: " << community_folder << L"\n";

			FindFolder(msfsfolders, community_folder);

			if (msfsfolders.size() != 0)
			{
				std::wcout << L"\n  Found " << msfsfolders.size() << L" folders.\n\n";

				for (int t = 0; t < msfsfolders.size(); t++)
				{
					ProcessContentsFolder(aircraft, community_folder + msfsfolders[t]);
				}

				if (aircraft.size() != 0)
				{
					std::wcout << L"\n  Found " << aircraft.size() << L" aircraft.\n\n";

					std::wstring FileName = L"";

					if (community)
					{
						FileName = L"__" + SystemConstants::CustomAircraft;
					}
					else
					{
						FileName = L"__" + SystemConstants::DefaultAircraft;
					}

					SaveCustomAircraftFile(aircraft, FileName);
				}
			}

            return true;
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
							std::transform(atype.begin(), atype.end(), atype.begin(), ::tolower);

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

							bool is_seaplane = false;

							if (WindowsUtility::FileExists(folder + L"\\SimObjects\\Airplanes\\" + simobjects[t] + L"\\runwaywater.flt") ||
								WindowsUtility::FileExists(folder + L"\\SimObjects\\Airplanes\\" + simobjects[t] + L"\\finalwater.flt"))
							{
								is_seaplane = true;
							}

							// =====================================================================================================================

							Ini* confige = new Ini(folder + L"\\SimObjects\\Airplanes\\" + simobjects[t] + L"\\flight_model.cfg");

							int cruise = 0;

							if (confige->Loaded)
							{
								cruise = confige->ReadInteger(L"reference speeds", L"cruise_speed", 0);
							}

							delete confige;

							// =====================================================================================================================

							if (cruise != 0)
							{
								if (aircraft_type == -1)
								{
									//std::wcout << std::format(L" Unknown aircraft type \"{0}\" for \"{1}\". Will be added to file, user should edit.\n", atype, Name);
								}

								Aircraft a(Name, cruise, range, 0, AircraftConstants::MSFSVersion::All, Utility::GetAircraftTypeFromInt(aircraft_type), is_airliner, is_military, is_seaplane);

								found_aircraft.push_back(a);
							}
							else
							{
								//std::wcout << std::format(L" Ignored, \"{0}\", suspect not an aircraft. Cruise speed is set to zero.\n", Name);
							}			
						}
					}

					delete config;
				}
				else
				{
					//std::wcout << std::format(L"Couldn't find file \"\\{0}\\aircraft.cfg\" :(\n", simobjects[t]);
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

			ofile << Formatting::to_utf8(L"// {\n");
			ofile << Formatting::to_utf8(L"// name=\n");
			ofile << Formatting::to_utf8(L"// cruise=\n");
			ofile << Formatting::to_utf8(L"// range=          { cannot be zero }\n");
			ofile << Formatting::to_utf8(L"// availability=   { all = 0, deluxe edition = 1, 2 = premium deluxe, 99 = third party (everything in custom_aircraft }\n");
			ofile << Formatting::to_utf8(L"// type=           { must be one of these: 0 = prop, 1 = jet, 2 = heli, 3 = glider, 4 = twin prop, 5 = turbo prop, 6 = twin turbo prop, 7 = balloon }\n");
			ofile << Formatting::to_utf8(L"// military=0      { 1 = is military aircraft }\n");
			ofile << Formatting::to_utf8(L"// airliner=0      { 1 = is airliner }\n");
			ofile << Formatting::to_utf8(L"// seaplane=0      { 1 = is seaplane/float plane 0 = no }\n");
			ofile << Formatting::to_utf8(L"// minrunway=0     { in feet, 0 = doesn't matter }\n");
 			ofile << Formatting::to_utf8(L"// }\n\n");

			for (int t = 0; t < found_aircraft.size(); t++)
			{
				ofile << Formatting::to_utf8(L"{\n");
				ofile << Formatting::to_utf8(L"name=" + found_aircraft[t].Name + L"\n");
				ofile << Formatting::to_utf8(L"cruise=" + std::to_wstring(found_aircraft[t].CruiseSpeed) + L"\n");
				ofile << Formatting::to_utf8(L"range=" + std::to_wstring(found_aircraft[t].Range) + L"\n");
				ofile << Formatting::to_utf8(L"availability=99\n");
				ofile << Formatting::to_utf8(L"type=" + std::to_wstring(Utility::GetAircraftTypeToConfigType(found_aircraft[t].Type)) + L"\n");
				ofile << Formatting::to_utf8(L"airliner=" + std::to_wstring(found_aircraft[t].Airliner) + L"\n");
				ofile << Formatting::to_utf8(L"military=" + std::to_wstring(found_aircraft[t].Military) + L"\n");
				ofile << Formatting::to_utf8(L"seaplane=" + std::to_wstring(found_aircraft[t].Seaplane) + L"\n");
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


	// this gets the location of the install folder from either of two possible
	// locations, depending on how MSFS2020 was installed
	std::wstring GetCommunityFolderPath(bool community_folder)
	{
		std::wstring path = L"";
		PWSTR path_tmp;

		auto attempt_1 = SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, nullptr, &path_tmp);

		path = path_tmp;

		if (WindowsUtility::FileExists(path + L"\\Packages\\Microsoft.FlightSimulator_8wekyb3d8bbwe\\LocalCache\\UserCfg.opt"))
		{
			std::wcout << L"  Found file (Microsoft Store install): " << path << L"\\Packages\\Microsoft.FlightSimulator_8wekyb3d8bbwe\\LocalCache\\UserCfg.opt\n";

			return ExtractPathFromOptionFile(path + L"\\Packages\\Microsoft.FlightSimulator_8wekyb3d8bbwe\\LocalCache\\UserCfg.opt", community_folder);
		}

		auto attempt_2 = SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &path_tmp);

		path = path_tmp;

		if (WindowsUtility::FileExists(path))
		{
			std::wcout << L"  Found file (Steam install): " << path << L"\\Microsoft Flight Simulator\\UserCfg.opt\n";

			return ExtractPathFromOptionFile(path + L"\\Microsoft Flight Simulator\\UserCfg.opt", community_folder);
		}

		return L"";
	}


	// this gets the install root from the UserCfg.opt file, then adds the community location
	std::wstring ExtractPathFromOptionFile(std::wstring path, bool community_folder)
	{
		std::wifstream file(path);

		if (file)
		{
			std::wstring s = L"";
			std::wstring path = L"";

			while (std::getline(file, s))
			{
				auto a = s.find(L"InstalledPackagesPath");

				if (a != std::wstring::npos)
				{
					if (community_folder)
					{
						path = StripFromJSON(L"InstalledPackagesPath:" + s.substr(a + 22)) + L"\\Community\\";
					}
					else
					{
						path = StripFromJSON(L"InstalledPackagesPath:" + s.substr(a + 22)) + L"\\Official\\OneStore\\";
					}					
				}
			}

			file.close();

			return path;
		}

		return L"";
	}
}