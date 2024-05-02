//
// FlightSimAdventureCreator 1.0
//
// (c) Paul Alan Freshney 2023-2024
//
// paul@freshney.org
// 
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
// 
// 

#include <algorithm>
#include <format>
#include <fstream>
#include <iostream>

#include "AirlineHandler.h"
#include "AirportHandler.h"
#include "Constants.h"
#include "Formatting.h"
#include "FSACAirportData.h"
#include "RunwayHandler.h"


namespace FSACAirportData
{
	// this takes a vanilla airports.csv (get it from outairports.com/data) and another CSV that contains an msfs_compatible field and combines them
	// (note that both files must be in the EXACT SAME FORMAT with the msfs_compatible field as the 26th (Z in Excel))
	// once it's correctly tagged airports from airports.csv it saves the new file to fsac.csv
	// it's not optimised, it's a bit rough, but it works!
	void ExportAirports()
	{
		std::wcout << L"\n";

		AirportHandler airporthandler(SystemConstants::OurAirportsFileName);

		AirportHandler airporthandlermsfs(SystemConstants::MSFSCompatSourceFileName);	// this will need tweaking before use, airport type is in the wrong position! and airport type values are different to airports.csv

		if (airporthandler.Loaded && airporthandlermsfs.Loaded)
		{
			int count = 0;

			for (int t = 0; t < airporthandlermsfs.Airports.size(); t++)
			{
				if (airporthandlermsfs.Airports[t].MSFSCompatible)
				{
					int index = airporthandler.GetIndexFromICAO(airporthandlermsfs.Airports[t].Ident);

					if (index != -1)
					{
						airporthandler.Airports[index].MSFSCompatible = true;

						count++;
					}
				}
			}

			if (count != 0)
			{
				std::wcout << std::format(L"\n  Found {0} MSFS compatible airports :)", count) << L"\n\n";

				if (airporthandler.Save(SystemConstants::AirportsFileName, true))
				{
					std::wcout << L"  Saved successfully.\n\n";
				}
			}

			return;
		}

		std::wcout << L"Couldn't load both files, exiting :(\n\n";
	}


	// this takes a list of airports and removes runways belonging to airports not in the list
	// outputs a new runways file containing only runways belonging to the airports we have in the master list
	// it's rough, but it works!
	void ExportRunways()
	{
		std::wcout << L"\n";

		AirportHandler airporthandler(SystemConstants::AirportsFileName);

		RunwayHandler runwayhandler(SystemConstants::RunwaysFileName);

		if (airporthandler.Loaded && runwayhandler.Loaded)
		{
			int count = 0;
			int runways_found = 0;

			for (int t = 0; t < airporthandler.Airports.size(); t++)
			{
				int rwf = runwayhandler.FindAndSet(airporthandler.Airports[t].Ident);

				if (rwf != 0)
				{
					count++;

					runways_found += rwf;
				}
			}

			if (count != 0)
			{
				std::wcout << std::format(L"\n  Found {0} airports with {1} runways :)", count, runways_found) << L"\n\n";

				if (runwayhandler.Save(L"__" + SystemConstants::RunwaysFileName, true))
				{
					std::wcout << L"  Saved successfully.\n\n";
				}
			}

			return;
		}

		std::wcout << std::format(L"Couldn't load data files (\"{0}\" and \"{1}\"), exiting :(\n\n", SystemConstants::AirportsFileName, SystemConstants::RunwaysFileName);
	}

	// this takes a routes file from openroutes.org file and exports an FSAC routes file
	// AirlineID,IATA_FROM,ICAO_FROM,IATA_TO,ICAO_TO,Codeshare,Stops,Equip
	void ExportRoutes()
	{
		std::wcout << L"\n";

		AirlineHandler airlinehandler(SystemConstants::RawAirlineFileName);
		AirportHandler airporthandler(SystemConstants::AirportsFileName);

		std::wifstream file(SystemConstants::RawRoutes);

		std::vector<std::wstring> Airlines;
		std::vector<std::wstring> Data;

		if (file)
		{
			std::vector<std::wstring> FromCache;
			std::vector<std::wstring> ToCache;

			int rows = 0;
			std::wstring s;
			std::wstring field(L"");
			int column = 0;
			bool canadd = true;

			std::wstring FromIATA = L"";
			std::wstring ToIATA = L"";
			std::wstring FromICAO = L"";
			std::wstring ToICAO = L"";
			std::wstring FromLocation = L"";
			std::wstring ToLocation = L"";
			std::wstring Equipment = L"";
			std::wstring OldCode = L"";
			std::wstring AirlineCache = L"";

			while (std::getline(file, s))
			{
				if (s != L"")
				{
					canadd = true;
					field = L"";
					column = 0;

					for (int t = 0; t < s.length(); t++)
					{
						if (s[t] == L',' || t == s.length() - 1)
						{
							if (column == 2 || column == 4)
							{
								switch (column)
								{
								case 2:
									FromIATA = field;
									break;
								case 4:
									ToIATA = field;
									break;
								}

								int index = airporthandler.GetIndexFromIATA(field);

								if (index == -1)
								{
									canadd = false;
								}
								else
								{
									switch (column)
									{
									case 2:
										FromICAO = airporthandler.Airports[index].Ident;
										FromLocation = airporthandler.Airports[index].Country + L"," +
											airporthandler.Airports[index].Continent + L"," +
											airporthandler.Airports[index].Region;
										break;
									case 4:
										ToICAO = airporthandler.Airports[index].Ident;
										ToLocation = airporthandler.Airports[index].Country + L"," +
											airporthandler.Airports[index].Continent + L"," +
											airporthandler.Airports[index].Region;
										break;
									}
								}
							}
							else if (column == 8)
							{
								Equipment = field;
							}

							field = L"";
							column++;
						}
						else
						{
							field += s[t];
						}
					}

					if (canadd)
					{
						std::wstring code = s.substr(0, 2);

						std::wstring name = AirlineCache;

						if (code != OldCode)
						{
							name = airlinehandler.FindWithCode(code);

							if (name != L"")
							{
								Airlines.push_back(name + L"," + code);
							}
						}

						if (name != L"")
						{
							double d = airporthandler.DistanceBetweenTwoAirports(FromICAO, ToICAO);

							if (d > 1)
							{ 
								std::wstring output = name + L"," + FromIATA + L"," + FromICAO + L"," + ToIATA + L"," + ToICAO + L"," + Equipment;

								output += L"," + std::to_wstring(d) + L"," + FromLocation + L"," + ToLocation;

								Data.push_back(output);

								if (std::find(FromCache.begin(), FromCache.end(), FromICAO) == FromCache.end())
								{
									FromCache.push_back(FromICAO);
								}

								if (std::find(ToCache.begin(), ToCache.end(), ToICAO) == ToCache.end())
								{
									ToCache.push_back(ToICAO);
								}
							}

							OldCode = code;

							AirlineCache = name;
						}
					}

					rows++;
				}
			}

			file.close();

			// ==================================================================================

			std::ofstream ffile(SystemConstants::AirlineFileName);

			if (ffile)
			{
				std::sort(Airlines.begin(), Airlines.end());

				ffile << Formatting::to_utf8(L"// AirlineName,AirlineIATA\n");

				for (int t = 0; t < Airlines.size(); t++)
				{
					ffile << Formatting::to_utf8(Airlines[t] + L"\n");
				}
			}

			ffile.close();

			std::wcout << L"\n  Found " << Airlines.size() << L" airlines from " << rows << L" rows. \n";

			// ==================================================================================

			std::ofstream ofile(SystemConstants::RoutesFileName);

			if (ofile)
			{
				ofile << Formatting::to_utf8(L"// AirlineID,IATA_FROM,ICAO_FROM,IATA_TO,ICAO_TO,Equipment,Distance(nm),FromCountry,FromContinent,FromRegion,ToCountry,ToContinent,ToRegion\n");

				for (int t = 0; t < Data.size(); t++)
				{
					ofile << Formatting::to_utf8(Data[t] + L"\n");
				}
			}

			ofile.close();

			std::wcout << L"\n  Found " << Data.size() << L" routes from " << rows << L" rows. \n";

			// ==================================================================================

			std::sort(FromCache.begin(), FromCache.end());

			std::ofstream fcfile(SystemConstants::RoutesFromCacheFileName);

			if (fcfile)
			{
				for (int t = 0; t < FromCache.size(); t++)
				{
					fcfile << Formatting::to_utf8(FromCache[t] + L"\n");
				}
			}

			fcfile.close();

			std::wcout << L"\n  Found " << FromCache.size() << L" route starting airports. \n";

			// ==================================================================================

			std::sort(ToCache.begin(), ToCache.end());

			std::ofstream tcfile(SystemConstants::RoutesToCacheFileName);

			if (tcfile)
			{
				for (int t = 0; t < ToCache.size(); t++)
				{
					tcfile << Formatting::to_utf8(ToCache[t] + L"\n");
				}
			}

			tcfile.close();

			std::wcout << L"\n  Found " << ToCache.size() << L" route ending airports. \n";

			// ==================================================================================
		}
		else
		{
			std::wcout << L"Couldn't load \"" << SystemConstants::RawRoutes << L"\"\n";
		}
	}

	// takes a set of route files, in the format:
	// IATA FROM, IATA TO, AIRLINE NAME
	// and outputs them into the FSAC format
	void ExportRoutes2()
	{
		std::wcout << L"\n";

		std::vector<std::wstring> Data;
		int rows = 0;

		AirportHandler airporthandler(SystemConstants::AirportsFileName);

		std::wifstream filelist(SystemConstants::RouteFileList);

		if (filelist)
		{
			std::wstring file_name = L"";

			while (std::getline(filelist, file_name))
			{
				if (file_name != L"")
				{
					std::wifstream file(file_name);

					if (file)
					{
						std::wcout << L"Processing: " << file_name << L".txt\n";

						std::wstring aFromIATA = L"";
						std::wstring aToIATA = L"";
						std::wstring aFromICAO = L"";
						std::wstring aToICAO = L"";
						std::wstring FromLocation = L"";
						std::wstring ToLocation = L"";
						std::wstring s;
						std::wstring field(L"");
						int column = 0;
						bool canadd = true;

						while (std::getline(file, s))
						{
							if (s != L"")
							{
								canadd = true;
								field = L"";
								column = 0;

								for (int t = 0; t < s.length(); t++)
								{
									if (s[t] == L',')
									{
										if (column == 0 || column == 1)
										{
											switch (column)
											{
											case 0:
												aFromIATA = field;
												break;
											case 1:
												aToIATA = field;
												break;
											}

											// if the airport can't be found in our master list then ignore it.
											// (it hasn't been verified as being available in MSFS)
											int index = airporthandler.GetIndexFromIATA(field);

											if (index == -1)
											{
												canadd = false;
											}
											else
											{
												switch (column)
												{
												case 0:
													aFromICAO = airporthandler.Airports[index].Ident;
													FromLocation = airporthandler.Airports[index].Country + L"," +
														airporthandler.Airports[index].Continent + L"," +
														airporthandler.Airports[index].Region + L",";
													break;
												case 1:
													aToICAO = airporthandler.Airports[index].Ident;
													ToLocation = airporthandler.Airports[index].Country + L"," +
														airporthandler.Airports[index].Continent + L"," +
														airporthandler.Airports[index].Region + L",";
													break;
												}
											}
										}

										field = L"";
										column++;
									}
									else
									{
										field += s[t];
									}
								}

								if (canadd)
								{
									s += L"," + aFromICAO + L"," + aToICAO + L"," +
										FromLocation + L"," + ToLocation + L"," +
										std::to_wstring(airporthandler.DistanceBetweenTwoAirports(aFromICAO, aToICAO));

									Data.push_back(s);
								}

								rows++;
							}
						}

						file.close();
					}
				}
			}


			std::ofstream ofile(SystemConstants::RoutesFileName);

			if (ofile)
			{
				ofile << Formatting::to_utf8(L"// AirlineID,IATA_FROM,IATA_TO,AIRLINE,ICAO_FROM,ICAO_TO,Distance\n");

				for (int t = 0; t < Data.size(); t++)
				{
					ofile << Formatting::to_utf8(Data[t] + L"\n");
				}

				ofile.close();
			}

			std::wcout << L"Found " << Data.size() << L" routes from " << rows << L" rows. \n";
		}
	}
}