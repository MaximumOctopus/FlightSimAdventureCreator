//
// FlightSimAdventureCreator 1.0 (GUI Version)
//
// (c) Paul Alan Freshney 2022-2023
//
// paul@freshney.org
//
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
//
//

#pragma once

#include <algorithm>
#include <format>
#include <fstream>
#include <iostream>
#include <string>

#include "AirportHandler.h"
#include "Constants.h"
#include "Locations.h"
#include "MSFSFlightPlan.h"
#include "RouteHandler.h"
#include "TextItinerary.h"
#include "Utility.h"


RouteHandler* GRouteHandler;

extern AirportHandler* GAirportHandler;


RouteHandler::RouteHandler(const std::wstring file_name, bool _Silent, bool _ExtraDetail, bool _ExportMSFSPlan, bool _ExportTextReport)
{
	Silent = _Silent;
	ExtraDetail = _ExtraDetail;

	ExportMSFSPlan = _ExportMSFSPlan;
	ExportTextReport = _ExportTextReport;

	Loaded = LoadRoutes(file_name);

	if (!LoadFromCache(SystemConstants::RoutesFromCacheFileName))
	{
		Loaded = false;
	}

	if (!LoadToCache(SystemConstants::RoutesToCacheFileName))
	{
		Loaded = false;
    }
}


int RouteHandler::GenerateRoutes(RouteFilter& rf)
{
	int attempts = 0;
	int Generated = 0;

	do
	{
		if (rf.ICAO.empty())
		{
			Generated = TryGenerateRoutesNoAirport(rf);

			if (Generated == 0)
			{
				if (!rf.KeepTrying)
				{
					return 0;
				}

				rf.Next(attempts);
			}
		}
		else
		{
			Generated = TryGenerateRoutes(rf);
			
			if (Generated == 0)
			{
				if (!rf.KeepTrying)
				{
					return 0;
				}

				rf.Next(attempts);
			}
		}

		attempts++;
	}
	while (Generated == 0 && attempts < DataDefaults::MaximumAttempts);

	return attempts;
}


// generate random routes with either a start or end airport
int RouteHandler::TryGenerateRoutes(RouteFilter& rf)
{
	int GeneratedRoutes = 0;
	int RoutesChecked = 0;

	int AirportFrom = 0;
	int AirportTo = 0;

	if (rf.DirectionFrom)
	{
		AirportTo = GAirportHandler->GetIndexFromICAO(rf.ICAO);
	}
	else
	{
		AirportFrom = GAirportHandler->GetIndexFromICAO(rf.ICAO);
	}

	while (GeneratedRoutes < rf.RouteCount && RoutesChecked < 15001)
	{
		bool found = false;
		bool cancontinue = true;

		int Route = rand() % Routes.size();

		if (rf.SpecificAirline)                                           		// airline
		{
			if (Routes[Route].Airline.find(rf.Airline) != 0)
			{
				cancontinue = false;
            }
		}

		if (rf.InternalOnly)                                                    // internal only
		{
			if (Routes[Route].FromCountry != Routes[Route].ToCountry)
			{
				cancontinue = false;
			}
		}

		if (rf.ExternalOnly)                                                    // external only
		{
			if (Routes[Route].FromCountry == Routes[Route].ToCountry)
			{
				cancontinue = false;
			}
		}

		if (cancontinue)
		{
			if (rf.DirectionFrom)
			{
				if (Routes[Route].FromICAO == rf.ICAO)   				// ICAO
				{
					if (Routes[Route].Distance > rf.DistanceMin &&		// distance
						Routes[Route].Distance < rf.DistanceMax)
					{
						AirportTo = GAirportHandler->GetIndexFromICAO(Routes[Route].ToICAO);

						if (AirportTo != -1)
						{
							found = true;
						}
					}
				}
			}
			else
			{
				if (Routes[Route].ToICAO == rf.ICAO)     				// ICAO
				{
					if (Routes[Route].Distance > rf.DistanceMin &&		// distance
						Routes[Route].Distance < rf.DistanceMax)
					{
						AirportFrom = GAirportHandler->GetIndexFromICAO(Routes[Route].FromICAO);

						if (AirportFrom != -1)
						{
							found = true;
						}
					}
				}
			}
		}

		if (found)
		{
			RouteFound(GeneratedRoutes, Route, AirportFrom, AirportTo);

			GeneratedRoutes++;

			if (GeneratedRoutes == rf.RouteCount)
			{
				return GeneratedRoutes;
			}
		}
	}

	return GeneratedRoutes;
}


// generate random routes where there is no specified start or end airport
int RouteHandler::TryGenerateRoutesNoAirport(RouteFilter& rf)
{
	int GeneratedRoutes = 0;
	int RoutesChecked = 0;

	while (GeneratedRoutes < rf.RouteCount && RoutesChecked < 15001)
	{
		bool found = false;
		bool cancontinue = true;

		int Route = rand() % Routes.size();

		int AirportFrom = 0;
		int AirportTo = 0;

		if (rf.SpecificAirline)                                           		// airline
		{
			if (Routes[Route].Airline.find(rf.Airline) != 0)
			{
				cancontinue = false;
            }
		}

		if (rf.InternalOnly)                                                    // internal only
		{
			if (Routes[Route].FromCountry != Routes[Route].ToCountry)
			{
				cancontinue = false;
			}
		}

		if (rf.ExternalOnly)                                                    // external only
		{
			if (Routes[Route].FromCountry == Routes[Route].ToCountry)
			{
				cancontinue = false;
			}
        }

		if (cancontinue)
		{
			if (Routes[Route].Distance > rf.DistanceMin &&      	// distance
				Routes[Route].Distance < rf.DistanceMax)
			{
				AirportFrom = GAirportHandler->GetIndexFromICAO(Routes[Route].FromICAO);
				AirportTo = GAirportHandler->GetIndexFromICAO(Routes[Route].ToICAO);

				if (AirportFrom != -1 && AirportTo != -1)
				{
					found = true;
				}
			}
		}

		if (found)
		{
			RouteFound(GeneratedRoutes, Route, AirportFrom, AirportTo);

			GeneratedRoutes++;

			if (GeneratedRoutes == rf.RouteCount)
			{
				return GeneratedRoutes;
			}
		}

		RoutesChecked++;
	}

	return GeneratedRoutes;
}


void RouteHandler::RouteFound(int routeid, int routeindex, int from, int to)
{
	std::wcout << L"\n == Route #" << routeid << " =======================================================\n\n";

	Airports.clear();

	Airports.push_back(GAirportHandler->GetAirport(from));
	Airports.push_back(GAirportHandler->GetAirport(to));

	Airports.back().Distance = GAirportHandler->DistanceBetweenTwoAirports(Airports.front().Ident, Airports.back().Ident);

	Airports.front().Angle = Utility::AngleBetween(Airports.front().LatitudeR, Airports.front().LongitudeR,
		Airports.back().LatitudeR, Airports.back().LongitudeR);

	std::wcout << L"   " << std::format(L"{0} --> {1}, {2} ({3:.1f} nm), @ {4:.1f}°; {5}\n", Airports.front().Ident, Airports.back().Ident, Airports.back().Country, Airports.back().Distance, Airports.front().Angle, Routes[routeindex].Airline);

	if (ExtraDetail)
	{
		std::wcout << L"   " << Airports.front().Name << L" --> " << Airports.back().Name << L"\n";
	}

	if (ExportMSFSPlan || ExportTextReport)
	{
		if (ExportMSFSPlan)
		{
			if (!MSFSFlightPlan::Export(Airports, L"Plans\\" + Airports.front().Ident + L"_to_" + Airports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".pln"))
			{
				std::wcout << L"\n\nError saving plan file :( \n";
			}
		}

		if (ExportTextReport)
		{
			if (!TextItinerary::Export(Airports, L"Reports\\" + Airports.front().Ident + L"_to_" + Airports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".txt"))
			{
				std::wcout << L"\n\nError saving text file :( \n";
			}
		}
	}
}


bool RouteHandler::LoadRoutes(const std::wstring file_name)
{
	std::wifstream file(file_name);

	//file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

	if (file)
	{
		std::wstring s = L"";

		int count = 0;
		int ignored = 0;

		while (std::getline(file, s))
		{
			if (s != L"")
			{
				if (s[0] == L'\"' || s[0] == L'/')
				{
					// comment or first row of csv, do nothing
				}
				else
				{
					if (ImportFromRow(s))
					{
						count++;
					}
					else
					{
						ignored++;
					}
				}
			}
		}

        Stats.Average = static_cast<int>((double)Stats.Total / (double)Routes.size());

		if (!Silent)
		{
			std::wcout << "  Loaded " << count << " routes.\n";
		}

		file.close();
    }
    else
    {
		return false;
	}

	return true;
}


// AirlineID,IATA_FROM,ICAO_FROM,IATA_TO,ICAO_TO,Equipment,Distance,FromCountry,FromContinent,FromRegion,ToCountry,ToContinent,ToRegion
bool RouteHandler::ImportFromRow(const std::wstring row)
{
	if (row.length() != 0)
	{
		std::wstring Airline = L"";
		std::wstring FromIATA = L"";
		std::wstring FromICAO = L"";
		std::wstring ToIATA = L"";
		std::wstring ToICAO = L"";
		std::wstring Equipment = L"";
		double Distance = 0;
		std::wstring FromCountry = L"";
		std::wstring FromContinent = L"";
		std::wstring FromRegion = L"";
		std::wstring ToCountry = L"";
		std::wstring ToContinent = L"";
		std::wstring ToRegion = L"";

		std::wstring field = L"";
        int field_position = 0;

        bool inquotes = false;

        for (int t = 0; t < row.length(); t++)
        {
			if ((row[t] == L',' && !inquotes) || t == row.length())
            {
                switch (field_position)
                {
				case kFieldAirline:
					Airline = field;
                    break;
				case kFieldFromIATA:
					FromIATA = field;
					break;
				case kFieldFromICAO:
					FromICAO = field;
                    break;
				case kFieldToIATA:
					ToIATA = field;
					break;
				case kFieldToICAO:
					ToICAO = field;
					break;
				case kFieldEquipment:
					Equipment = field;
					break;
				case kFieldDistance:
					Distance = stod(field);
					break;
				case kFieldFromCountry:
					FromCountry = field;
					break;
				case kFieldFromContinent:
					FromContinent = field;
					break;
				case kFieldFromRegion:
					FromRegion = field;
					break;
				case kFieldToCountry:
					ToCountry = field;
					break;
				case kFieldToContinent:
					ToContinent = field;
					break;
				case kFieldToRegion:
					ToRegion = field;
					break;
                }

                field_position++;

                field = L"";
            }
			else if (row[t] == L'\"')
            {
                inquotes = !inquotes;
            }
            else
            {
                field += row[t];
			}
		}

		// =====================================================================

		if (Distance < Stats.Shortest) Stats.Shortest = static_cast<int>(Distance);
		if (Distance > Stats.Longest) Stats.Longest = static_cast<int>(Distance);

		for (int t = 0; t < 7; t++)
		{
			if (Location::ContinentShort[t] == FromContinent)
			{
				Stats.Continents[t]++;
				break;
			}
		}

		Stats.Total += Distance;

		// =====================================================================

		Route route(FromIATA, ToIATA, FromICAO, ToICAO,
			Airline,
			Equipment, Distance,
			FromCountry, FromContinent, FromRegion,
			ToCountry, ToContinent, ToRegion);

		Routes.push_back(route);

        return true;
    }

    return false;
}


// the fromcache contains a sorted list of starting airports from all loaded routes
// cached to vastly improved checking if a valid start airport performance
bool RouteHandler::LoadFromCache(const std::wstring file_name)
{
	std::wifstream file(file_name);

	if (file)
	{
		std::wstring s = L"";

		while (std::getline(file, s))
		{
			if (s != L"")
			{
				FromCache.push_back(s);
			}
		}

		if (!Silent)
		{
			std::wcout << "    Loaded " << FromCache.size() << " start airports.\n";
		}

		file.close();
	}
	else
	{
		return false;
	}

	return true;
}


// the tocache contains a sorted list of destination airports from all loaded routes
// cached to vastly improved checking if a valid end airport performance
bool RouteHandler::LoadToCache(const std::wstring file_name)
{
	std::wifstream file(file_name);

	if (file)
	{
		std::wstring s = L"";

		while (std::getline(file, s))
		{
			if (s != L"")
			{
				ToCache.push_back(s);
			}
		}

		if (!Silent)
		{
			std::wcout << "    Loaded " << ToCache.size() << " destination airports.\n";
		}

		file.close();
	}
	else
	{
		return false;
	}

	return true;
}


// used the above cache to determine if this airport can be used to start a route
bool RouteHandler::IsValidFromAirport(const std::wstring icao)
{
	return std::binary_search(FromCache.begin(), FromCache.end(), icao);
}


// used the above cache to determine if this airport can be used to end a route
bool RouteHandler::IsValidToAirport(const std::wstring icao)
{
	return std::binary_search(ToCache.begin(), ToCache.end(), icao);
}