//
// FlightSimAdventureCreator 1.0 (GUI Version)
//
// (c) Paul Alan Freshney 2022-2024
//
// paul@freshney.org
//
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
//
//

#include <fstream>
#include <string>

#include "AirportHandler.h"
#include "Configuration.h"
#include "Constants.h"
#include "FlightHandler.h"
#include "Locations.h"
#include "RouteHandler.h"


RouteHandler* GRouteHandler;

extern AirportHandler* GAirportHandler;
extern Configuration* GConfiguration;
extern FlightHandler* GFlightHandler;


RouteHandler::RouteHandler(const std::wstring file_name)
{
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
	GFlightHandler->Flights.clear();

	int attempts = 0;

	do
	{
		if (rf.ICAO.empty())
		{
			if (TryGenerateRoutesNoAirport(rf) == 0)
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
			if (TryGenerateRoutes(rf) == 0)
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
	while (GFlightHandler->Flights.size() == 0 && attempts < DataDefaults::MaximumAttempts);

	GFlightHandler->Sort(0);

	return attempts;
}


// generate random routes with either a start or end airport
int RouteHandler::TryGenerateRoutes(RouteFilter& rf)
{
	int GeneratedRoutes = 0;
	int RoutesChecked = 0;

	while (GeneratedRoutes < rf.RouteCount && RoutesChecked < 15001)
	{
		bool found = false;
		bool cancontinue = true;

		int Route = rand() % Routes.size();

		if (rf.SpecificAirline)                                           		// airline
		{
			if (Routes[Route].Airline != rf.Airline)
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
				if (Routes[Route].FromICAO == rf.ICAO)   			// ICAO
				{
					if (Routes[Route].Distance > rf.DistanceMin &&   // distance
						Routes[Route].Distance < rf.DistanceMax)
					{
						if (GAirportHandler->IsAirportInFilteredList(Routes[Route].ToICAO))
						{
							found = true;
						}
					}
				}
			}
			else
			{
				if (Routes[Route].ToICAO == rf.ICAO)     			// ICAO
				{
					if (Routes[Route].Distance > rf.DistanceMin &&   // distance
						Routes[Route].Distance < rf.DistanceMax)
					{
						if (GAirportHandler->IsAirportInFilteredList(Routes[Route].FromICAO))
						{
							found = true;
						}
					}
				}
			}
		}

		if (found)
		{
			Flight f(Routes[Route].FromICAO, Routes[Route].ToICAO, Routes[Route].Distance);

			f.Name = Routes[Route].FromICAO + L" to " + Routes[Route].ToICAO;
			f.Airline = Routes[Route].Airline;

			f.FromContinent = Routes[Route].FromContinent;
			f.FromCountry = Routes[Route].FromCountry;
			f.FromRegion = Routes[Route].FromRegion;

			f.ToContinent = Routes[Route].ToContinent;
			f.ToCountry = Routes[Route].ToCountry;
			f.ToRegion = Routes[Route].ToRegion;

			f.Favourite = GConfiguration->IsAirportInFavourites(Routes[Route].FromICAO) ||
						  GConfiguration->IsAirportInFavourites(Routes[Route].ToICAO);

			GFlightHandler->Flights.push_back(f);

			GeneratedRoutes++;

			if (GeneratedRoutes == rf.RouteCount)
			{
				return GFlightHandler->Flights.size();
			}
		}

        RoutesChecked++;
	}

	return GFlightHandler->Flights.size();
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

		if (rf.SpecificAirline)                                           		// airline
		{
			if (Routes[Route].Airline != rf.Airline)
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
				if (GAirportHandler->IsAirportInFilteredList(Routes[Route].FromICAO) &&
				    GAirportHandler->IsAirportInFilteredList(Routes[Route].ToICAO))
				{
					found = true;
				}
			}
		}

		if (found)
		{
			Flight f(Routes[Route].FromICAO, Routes[Route].ToICAO, Routes[Route].Distance);

			f.Name = Routes[Route].FromICAO + L" to " + Routes[Route].ToICAO;
			f.Airline = Routes[Route].Airline;

			f.FromContinent = Routes[Route].FromContinent;
			f.FromCountry = Routes[Route].FromCountry;
			f.FromRegion = Routes[Route].FromRegion;

			f.ToContinent = Routes[Route].ToContinent;
			f.ToCountry = Routes[Route].ToCountry;
			f.ToRegion = Routes[Route].ToRegion;

			f.Favourite = GConfiguration->IsAirportInFavourites(Routes[Route].FromICAO) ||
						  GConfiguration->IsAirportInFavourites(Routes[Route].ToICAO);

			GFlightHandler->Flights.push_back(f);

			GeneratedRoutes++;

			if (GeneratedRoutes == rf.RouteCount)
			{
				return GFlightHandler->Flights.size();
			}
		}

		RoutesChecked++;
	}

	return GFlightHandler->Flights.size();
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

		if (Routes.size() != 0)
		{
			Stats.Average = static_cast<int>((double)Stats.Total / (double)Routes.size());
        }

		file.close();

		return true;
	}

	return false;
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
			if ((row[t] == L',' && !inquotes) || t == row.length() - 1)
			{
                if (t == row.length() - 1) field += row[t];

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