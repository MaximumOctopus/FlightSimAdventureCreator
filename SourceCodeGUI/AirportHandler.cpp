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

#include <algorithm>
#include <fstream>
#include <iostream>

#include "Airport.h"
#include "AirportHandler.h"
#include "Configuration.h"
#include "DateUtility.h"
#include "Defaults.h"
#include "Formatting.h"
#include "Locations.h"
#include "MSFSFlightPlan.h"
#include "Flight.h"
#include "FlightHandler.h"
#include "RunwayHandler.h"
#include "TextItinerary.h"
#include "Utility.h"


AirportHandler* GAirportHandler;
extern Configuration* GConfiguration;
extern FlightHandler* GFlightHandler;
extern RunwayHandler* GRunwayHandler;


bool sortBySize(const Airport &lhs, const Airport &rhs) { return lhs.Distance < rhs.Distance; }

bool sortByICAO(const Airport &lhs, const Airport &rhs) { return lhs.Ident < rhs.Ident; }

bool BinaryICAO(Airport lhs, Airport rhs) { return (lhs.Ident < rhs.Ident); }


AirportHandler::AirportHandler()
{
	Airports.reserve(30000);

	Loaded = LoadAirports(SystemConstants::AirportsFileName);

	if (!Loaded)
	{
		LastError = L" Airport data file not found \"" + SystemConstants::AirportsFileName + L"\".";
    }
}


// if airport_index != -1 then returns that object
// else a random airport will be selected
Airport AirportHandler::GetAirport(int airport_index)
{
    if (airport_index != kRandomAirport)
    {
		return FilteredList[airport_index];
    }

	if (FilteredList.size() != 0)
    {
		int a = rand() % FilteredList.size();

		return FilteredList[a];
    }

    return Airport();
}


double AirportHandler::DistanceBetweenTwoAirports(const std::wstring icao_from, const  std::wstring icao_to)
{
	int from_index = GetIndexFromICAO(icao_from);
    int to_index = GetIndexFromICAO(icao_to);

    if (from_index != -1 && to_index != -1)
    {
        return DistanceBetween(Airports[from_index].LatitudeR, Airports[from_index].LongitudeR,
                               Airports[to_index].LatitudeR, Airports[to_index].LongitudeR);
    }

	return -1;
}


// https://www.geeksforgeeks.org/program-distance-two-points-earth/
// long and lat must already be converted to radians
double AirportHandler::DistanceBetween(double lat1, double long1, double lat2, double long2)
{
    long double deltalong = long2 - long1;
    long double deltalat = lat2 - lat1;

	long double distance = std::pow(std::sin(deltalat / 2), 2) + std::cos(lat1) * std::cos(lat2) * std::pow(std::sin(deltalong / 2), 2);

    distance = 2 * std::asin(std::sqrt(distance));

    // Radius of Earth in nautical miles
    static const double R = 3340.1;

    // Calculate the result
    return distance * R;
}


// calculates the distance from each airport to the origin
void AirportHandler::CalculateDistances(double range, double origin_lat, double origin_long)
{
    double range_min = range * 0.9;
    double range_max = range * 1.1;

	FlightCache.clear();

	for (int t = 0; t < FilteredList.size(); t++)
    {
		FilteredList[t].Distance = DistanceBetween(origin_lat, origin_long, FilteredList[t].LatitudeR, FilteredList[t].LongitudeR);

		if (FilteredList[t].Distance < range_max && FilteredList[t].Distance > range_min && FilteredList[t].Distance != 0)
        {
			FlightCache.push_back(FilteredList[t]);
        }
    }
}


// this version ensures the selected airports are within the specified range and direction
void AirportHandler::CalculateDistances(double range, double direction, double direction_modifier, double origin_lat, double origin_long)
{
    double range_min = range * 0.9;
    double range_max = range * 1.1;

    double angle_min = direction - direction_modifier;
    double angle_max = direction + direction_modifier;

    if (angle_min < 0) angle_min += 360;
    if (angle_max > 359) angle_max -= 360;

	FlightCache.clear();

	for (int t = 0; t < FilteredList.size(); t++)
    {
        bool is_within_angle = false;

		FilteredList[t].Distance = DistanceBetween(origin_lat, origin_long, FilteredList[t].LatitudeR, FilteredList[t].LongitudeR);

		double angle = Utility::AngleBetween(origin_lat, origin_long, FilteredList[t].LatitudeR, FilteredList[t].LongitudeR);

        if (angle_max >= angle_min)
        {
            if (angle >= angle_min && angle <= angle_max)
            {
                is_within_angle = true;
            }
        }
        else
        {   
            if (angle >= angle_min || angle <= angle_max)
            {
                is_within_angle = true;
            }
        }

		if (FilteredList[t].Distance < range_max && FilteredList[t].Distance > range_min && is_within_angle && FilteredList[t].Distance != 0)
        {
			FilteredList[t].Angle = angle;

			FlightCache.push_back(FilteredList[t]);
        }
    }
}


// calculates the distance from each airport to the origin
void AirportHandler::CalculateDistancesNoMinimum(double range, double origin_lat, double origin_long)
{
	FlightCache.clear();

	for (int t = 0; t < FilteredList.size(); t++)
    {
		FilteredList[t].Distance = DistanceBetween(origin_lat, origin_long, FilteredList[t].LatitudeR, FilteredList[t].LongitudeR);

		if (FilteredList[t].Distance < range && FilteredList[t].Distance != 0)
		{
			FlightCache.push_back(FilteredList[t]);
        }
    }
}


void AirportHandler::GetRoute(const std::wstring start_icao, const std::wstring end_icao, double range, double direction, int legs, int simple_count, bool keep_trying)
{
	FlightCache.clear();

	GFlightHandler->Flights.clear();

	if (start_icao != L"" && end_icao != L"")
	{
		for (int t = 0; t < simple_count; t++)
		{
			StartToFinish(start_icao, end_icao, range, legs, keep_trying);
		}

		return;
	}

	std::wstring TargetICAO = L"";
	bool reverse = false;

	// if we have a start we search as normal, if we only have an end then we do the search as though
    // the end was our start location, then reverse the order :)
	if (!start_icao.empty() && end_icao.empty())
    {
        TargetICAO = start_icao;
    }
	else if (start_icao.empty() && !end_icao.empty())
	{
		TargetICAO = end_icao;

		// so we'll do the route in reverse, so we need to reverse the required angle of flight
		if (direction != DataDefaults::Direction)
		{
			direction = Utility::ReverseAngle(direction);
		}

        reverse = true;
    }

    if (legs == 1)
	{
        if (simple_count > 0)
        {
            Generation.ShortRouteCount = simple_count;
        }

		SimpleRoute(TargetICAO, range, direction, keep_trying, reverse);
    }
    else
	{
		for (int t = 0; t < simple_count; t++)
		{
			MultiLegRoute(TargetICAO, range, direction, legs, keep_trying, reverse);
		}
	}

    GFlightHandler->Sort(0);
}


// generates a route from one airport to another, A->B
bool AirportHandler::SimpleRoute(const std::wstring airport_icao, double range, double direction, bool keep_trying, bool reverse)
{
    int MaximumAttempts = Generation.MaximumAttempts;
	int Attempt = 0;
    int TargetAirport = kRandomAirport;
    int Retries = 0;
	double DirectionMarginOfError = DataDefaults::DirectionMargin;

    if (airport_icao != L"")
    {
		TargetAirport = GetIndexFromICAO(airport_icao);

        if (TargetAirport == kRandomAirport)
        {
			LastError = L"  Couldn't find start airport L\"" + airport_icao + L"\", using random :(";
        }
	}

	while (Attempt < MaximumAttempts)
    {
        Airport origin = GetAirport(TargetAirport);

        if (origin.Type != AirportConstants::AirportType::None)
        {
            if (direction != -1)
			{
                CalculateDistances(range, direction, DirectionMarginOfError, origin.LatitudeR, origin.LongitudeR);
            }
            else
            {
                CalculateDistances(range, origin.LatitudeR, origin.LongitudeR);
            }

			if (FlightCache.size() != 0)
            {
                Runway runway = GRunwayHandler->GetRandom(origin.Ident);
                
                origin.Runway.Name = runway.Name;
                origin.Runway.Length = runway.Length;
                origin.Runway.Surface = runway.SurfaceType;

                int OutputCount = Generation.ShortRouteCount;

				if (FlightCache.size() < Generation.ShortRouteCount)
                {
					OutputCount = FlightCache.size();
                }

                for (int t = 0; t < OutputCount; t++)
                {
                    SingleLegAirports.clear();

					Runway runway = GRunwayHandler->GetRandom(FlightCache[t].Ident);

					FlightCache[t].Runway.Name = runway.Name;
					FlightCache[t].Runway.Length = runway.Length;
					FlightCache[t].Runway.Surface = runway.SurfaceType;

                    if (reverse)
                    {
						SingleLegAirports.push_back(FlightCache[t]);
                        SingleLegAirports.push_back(origin);

                        SingleLegAirports.back().Distance = SingleLegAirports.front().Distance;
                        SingleLegAirports.back().Angle = Utility::ReverseAngle(SingleLegAirports.back().Angle);
					}
					else
                    {
                        SingleLegAirports.push_back(origin);
						SingleLegAirports.push_back(FlightCache[t]);

						SingleLegAirports.front().Distance = SingleLegAirports.back().Distance;
                    }

                    SingleLegAirports.front().Angle = Utility::AngleBetween(SingleLegAirports.front().LatitudeR, SingleLegAirports.front().LongitudeR,
					SingleLegAirports.back().LatitudeR, SingleLegAirports.back().LongitudeR);

                    SingleLegAirports.back().Angle = SingleLegAirports.front().Angle;

					// == add route to list =========================================================================

					Flight flight(SingleLegAirports.front().Ident + L" to " + SingleLegAirports.back().Ident, SingleLegAirports.front().Distance);

					flight.Airports.push_back(SingleLegAirports.front());
					flight.Airports.push_back(SingleLegAirports.back());

					flight.FromContinent = SingleLegAirports.front().Continent;
					flight.FromCountry = SingleLegAirports.front().Country;
					flight.FromRegion = SingleLegAirports.front().Region;

					flight.ToContinent = SingleLegAirports.back().Continent;
					flight.ToCountry = SingleLegAirports.back().Country;
					flight.ToRegion = SingleLegAirports.back().Region;

					flight.Favourite = GConfiguration->IsAirportInFavourites(SingleLegAirports.front().Ident) ||
									   GConfiguration->IsAirportInFavourites(SingleLegAirports.back().Ident);

					GFlightHandler->Add(flight);

					// ==============================================================================================

                    if (ExportMSFSPlan || ExportTextReport)    
                    {
                        if (ExportMSFSPlan)
                        {
                            if (!MSFSFlightPlan::Export(SingleLegAirports, L"Plans\\" + SingleLegAirports.front().Ident + L"_to_" + SingleLegAirports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".pln"))
                            {
								LastError = L"\n\nError saving plan file :(";
							}
						}

						if (ExportTextReport)
						{
							if (!TextItinerary::Export(SingleLegAirports, L"Reports\\" + SingleLegAirports.front().Ident + L"_to_" + SingleLegAirports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".txt"))
							{
								LastError =  L"\n\nError saving text file :(";
							}
						}
                    }
                }

                return true;
            }
        }

		Attempt++;

		if (Attempt == MaximumAttempts && keep_trying)
        {
            Retries++;

            // if someone is stupid enough to have a range of 1 nm and "keeptrying" then we have to shut it down eventually...
            // 21 retries from 1 nautical mile gives us just over 100 nm - that should be enough...
            if (Retries < 22)
			{
                Attempt = 0;

                range *= 1.25;

                DirectionMarginOfError += 5;

//                std::wcout << L"  No airports in range, using 1.25x (" << range << L") and retrying (" << Retries << L")...\n";
			}
		}
	}

	LastError = L"Sorry, no routes could be generated with a range of " + std::to_wstring(range) + L" nm after " + std::to_wstring(MaximumAttempts) + L" attempts :(";

    return false;
}


// this will accept either a start airport (reverse = false) or destination airport (reverse = true)
bool AirportHandler::MultiLegRoute(std::wstring airport_icao, double range, double direction, int legs, bool keep_trying, bool reverse)
{
    int MaximumAttempts = Generation.MaximumAttempts;
    int Attempt = 0;
    int TargetAirport = kRandomAirport;
	int Retries = 0;
	double DirectionMarginOfError = DataDefaults::DirectionMargin;

    if (airport_icao != L"")
    {
        TargetAirport = GetIndexFromICAO(airport_icao);

        if (TargetAirport == kRandomAirport)
		{
			LastError = L"  Couldn't find airport L\"" + airport_icao + L"\" :(";
        }
    }

    while (Attempt < MaximumAttempts)
    {
        MultiLegAirports.clear();

        Airport origin = GetAirport(TargetAirport);

        double FromLatitude = origin.LatitudeR;
        double FromLongitude = origin.LongitudeR;

		MultiLegAirports.push_back(origin);

        for (int leg = 0; leg < legs; leg++)
        {
            if (origin.Type != AirportConstants::AirportType::None)
            {
                if (direction != -1)
                {
                    CalculateDistances(range, direction, DirectionMarginOfError, FromLatitude, FromLongitude);
                }
                else
                {
                    CalculateDistances(range, FromLatitude, FromLongitude);
                }

				if (FlightCache.size() != 0)
                {
					int random_airport = rand() % FlightCache.size();

					MultiLegAirports.push_back(FlightCache[random_airport]);

					FromLatitude = FlightCache[random_airport].LatitudeR;
					FromLongitude = FlightCache[random_airport].LongitudeR;
                }
                else
                {
                    break;
				}
            }
        }

        if (MultiLegAirports.size() == legs + 1) break;

        Attempt++;

        if (Attempt == MaximumAttempts && keep_trying)
        {
            Retries++;

            // if someone is stupid enough to have a range of 1 nm and "keeptrying" then we have to shut it down eventually...
            // 21 retries from 1 nautical mile gives us just over 100 nm - that should be enough...
            if (Retries < 22)
            {
                Attempt = 0;

                range *= 1.25;
                DirectionMarginOfError += 5;

				// std::wcout << L"  No airports in range, using 1.25x (" << range << L") and retrying (" << Retries << L")...\n";
			}
        }
    }

    if (MultiLegAirports.size() == legs + 1)
    {
        if (reverse)
        {
			std::reverse(MultiLegAirports.begin(), MultiLegAirports.end());
        }

        FinaliseMultiLegData();

		Flight flight(MultiLegAirports.front().Ident + L" to " + MultiLegAirports.back().Ident, MultiLegAirports.front().Distance);

		for (int t = 0; t < MultiLegAirports.size(); t++)
		{
			flight.Airports.push_back(MultiLegAirports[t]);
		}

		flight.FromContinent = MultiLegAirports.front().Continent;
		flight.FromCountry = MultiLegAirports.front().Country;
		flight.FromRegion = MultiLegAirports.front().Region;

		flight.ToContinent = MultiLegAirports.back().Continent;
		flight.ToCountry = MultiLegAirports.back().Country;
		flight.ToRegion = MultiLegAirports.back().Region;

		flight.Favourite = GConfiguration->IsAirportInFavourites(MultiLegAirports.front().Ident) ||
						   GConfiguration->IsAirportInFavourites(MultiLegAirports.back().Ident);

		GFlightHandler->Add(flight);

		HandleMultiLegExport();

        return true;
    }

	LastError = L"Sorry, no routes could be generated with a range of " + std::to_wstring(range) + L" nm after " + std::to_wstring(MaximumAttempts) + L" attempts :(";

    return false;
}


// used when both start airport and end airport have been set
bool AirportHandler::StartToFinish(std::wstring start_icao, std::wstring end_icao, double range, int legs, bool keep_trying)
{
    int MaximumAttempts = Generation.MaximumAttempts;
    int Attempt = 0;

	double DirectionMarginOfError = DataDefaults::DirectionMargin;
    int StartAirport;
    int EndAirport;

    MultiLegAirports.clear();

    StartAirport = GetIndexFromICAO(start_icao);
    Airport origin = GetAirport(StartAirport);

    EndAirport = GetIndexFromICAO(end_icao);
    Airport destination = GetAirport(EndAirport);

    while (Attempt < MaximumAttempts)
    {
		MultiLegAirports.push_back(origin);

        // eg 3 legs = 4 airports, we have 1, so we need 2 more, then we add the end airport after this loop

        while (MultiLegAirports.size() != legs)
        {
            double direction = Utility::AngleBetween(MultiLegAirports.back().LatitudeR, MultiLegAirports.back().LongitudeR,
                destination.LatitudeR, destination.LongitudeR);

            CalculateDistances(range, direction, DirectionMarginOfError, MultiLegAirports.back().LatitudeR, MultiLegAirports.back().LongitudeR);

			if (FlightCache.size() != 0)
            {
				int random_airport = rand() % FlightCache.size();

				MultiLegAirports.push_back(FlightCache[random_airport]);
            }
            else
            {
                // for now... not sure what to do :(
//                std::wcout << std::format(L"  Couldn't complete route, trying again... attempt {0} of {1}\n", Attempt + 1, MaximumAttempts);
				break;
			}
		}

		if (MultiLegAirports.size() == legs) break;

        Attempt++;
    }

    if (MultiLegAirports.size() == legs)
    {
		MultiLegAirports.push_back(destination);

		FinaliseMultiLegData();

		// == add route to list =========================================================================

		Flight flight(MultiLegAirports.front().Ident + L" to " + MultiLegAirports.back().Ident, MultiLegAirports.front().Distance);

		for (int t = 0; t < MultiLegAirports.size(); t++)
		{
			flight.Airports.push_back(MultiLegAirports[t]);
		}

		flight.FromContinent = MultiLegAirports.front().Continent;
		flight.FromCountry = MultiLegAirports.front().Country;
		flight.FromRegion = MultiLegAirports.front().Region;

		flight.ToContinent = MultiLegAirports.back().Continent;
		flight.ToCountry = MultiLegAirports.back().Country;
		flight.ToRegion = MultiLegAirports.back().Region;

		flight.Favourite = GConfiguration->IsAirportInFavourites(MultiLegAirports.front().Ident) ||
						   GConfiguration->IsAirportInFavourites(MultiLegAirports.back().Ident);

		GFlightHandler->Add(flight);

		// ==============================================================================================

        HandleMultiLegExport();

        return true;
    }

    return false;
}


void AirportHandler::FinaliseMultiLegData()
{
    double TotalDistance = 0;

    Runway runway = GRunwayHandler->GetRandom(MultiLegAirports[0].Ident);

    MultiLegAirports[0].Runway.Name = runway.Name;
    MultiLegAirports[0].Runway.Length = runway.Length;
    MultiLegAirports[0].Runway.Surface = runway.SurfaceType;

    // update distances
    for (int i = 1; i < MultiLegAirports.size(); i++)
    {
        MultiLegAirports[i].Distance = DistanceBetween(MultiLegAirports[i - 1].LatitudeR, MultiLegAirports[i - 1].LongitudeR,
            MultiLegAirports[i].LatitudeR, MultiLegAirports[i].LongitudeR);

        Runway runway = GRunwayHandler->GetRandom(MultiLegAirports[i].Ident);

        MultiLegAirports[i].Runway.Name = runway.Name;
        MultiLegAirports[i].Runway.Length = runway.Length;
        MultiLegAirports[i].Runway.Surface = runway.SurfaceType;

        TotalDistance += MultiLegAirports[i].Distance;

        MultiLegAirports[i].Angle = Utility::AngleBetween(MultiLegAirports[i - 1].LatitudeR, MultiLegAirports[i - 1].LongitudeR,
            MultiLegAirports[i].LatitudeR, MultiLegAirports[i].LongitudeR);
    }

    MultiLegAirports[0].Distance = TotalDistance; // cache total route length in first airport
}


void AirportHandler::HandleMultiLegExport()
{
    if (ExportMSFSPlan)
    {
        if (!MSFSFlightPlan::Export(MultiLegAirports, L"Plans\\" + MultiLegAirports[0].Ident + L"_to_" + MultiLegAirports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".pln"))
        {
			LastError = L"\n\nError saving MSFS plan file :(";
		}
	}

	if (ExportTextReport)
	{
		if (!TextItinerary::Export(MultiLegAirports, L"Reports\\" + MultiLegAirports[0].Ident + L"_to_" + MultiLegAirports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".txt"))
		{
			LastError = L"\n\nError saving text file :(";
        }
    }
}


int AirportHandler::GetIndexFromIATA(const std::wstring iata)
{
    for (int t = 0; t < Airports.size(); t++)
    {
        if (Airports[t].IATA == iata)
        {
            return t;
        }
    }

    return kRandomAirport;
}


int AirportHandler::GetIndexFromICAO(const std::wstring icao)
{
	for (int t = 0; t < FilteredList.size(); t++)
	{
		if (FilteredList[t].Ident == icao)
		{
			return t;
		}
	}

	return kRandomAirport;
}


int AirportHandler::GetIndexFromICAOFullList(const std::wstring icao)
{
	for (int t = 0; t < Airports.size(); t++)
	{
		if (Airports[t].Ident == icao)
		{
			return t;
		}
	}

	return kRandomAirport;
}


bool AirportHandler::IsAirportInFilteredList(const std::wstring icao)
{
	for (int t = 0; t < FilteredList.size(); t++)
	{
		if (FilteredList[t].Ident == icao)
		{
			return true;
		}
	}

	return false;

	//Airport a(icao);

	//return std::binary_search(FilteredList.begin(), FilteredList.end(), a, BinaryICAO);
}


// binary search requires data be sorted, airports are already sorted by ICAO (Ident) in fsac.csv
bool AirportHandler::IsValidAirport(const std::wstring icao)
{
	Airport a(icao);

	return std::binary_search(Airports.begin(), Airports.end(), a, BinaryICAO);
}


// airport parameter must already be checked as valid
int AirportHandler::Search(AirportSearchFilter asf)
{
	double longitude = 0;
	double latitude = 0;
	int distance = 0;

	if (asf.WithinRange)
	{
		Airport a = Airports[GetIndexFromICAOFullList(asf.Airport)];

		longitude = a.LongitudeR;
		latitude = a.LatitudeR;
	}

	SearchResults.clear();

	for (int t = 0; t < Airports.size(); t++)
	{
		bool add = true;

		if (asf.Continent != L"")
		{
			if (asf.Continent != Airports[t].Continent)
			{
				add = false;
			}
		}

		if (add && asf.Country != L"")
		{
			if (asf.Country != Airports[t].Country)
			{
				add = false;
			}
		}

		if (add && asf.SearchText != L"")
		{
			std::wstring name = Airports[t].Name;
			std::transform(name.begin(), name.end(), name.begin(), ::tolower);

			if (name.find(asf.SearchText) == std::wstring::npos)
			{
				add = false;
			}
		}

		switch (Airports[t].Type)
		{
		case AirportConstants::AirportType::None:
			break;
		case AirportConstants::AirportType::Small:
			if (!asf.SmallAirports)
			{
				add = false;
			}
			break;
		case AirportConstants::AirportType::Medium:
			if (!asf.MediumAirports)
			{
				add = false;
			}
			break;
		case AirportConstants::AirportType::Large:
			if (!asf.LargeAirports)
			{
				add = false;
			}
			break;
		case AirportConstants::AirportType::Heliport:
			if (!asf.Heliports)
			{
				add = false;
			}
			break;
		case AirportConstants::AirportType::SeaplaneBase:
			if (!asf.SeaplaneBases)
			{
				add = false;
			}
			break;
		}

		if (add && asf.WithinRange)
		{
			distance = DistanceBetween(latitude, longitude, Airports[t].LatitudeR, Airports[t].LongitudeR);

			if (distance > asf.Range)
			{
				add = false;
			}
		}

		if (add)
		{
			SearchResults.push_back(Airports[t]);

			if (asf.WithinRange)
			{
                SearchResults.back().Distance = distance;
            }

			if (SearchResults.size() == 500)
			{
				break;
            }
		}
	}

	if (asf.WithinRange && SearchResults.size() != 0)
	{
		std::sort(SearchResults.begin(), SearchResults.end(), sortBySize);
    }

	return SearchResults.size();
}


int AirportHandler::Filter(AirportLoadFilter alf)
{
	FilteredList.clear();

	for (int t = 0; t < Airports.size(); t++)
	{
		bool add = true;

		if (alf.FilterContinent)
		{
			if (!alf.Continents[Airports[t].ContinentAsInt])
			{
				add = false;
			}
		}

		if (alf.FilterCountry)
		{
			if (alf.Country != L"")
			{
				if (Airports[t].Country != alf.Country)
				{
					add = false;
				}
			}
		}

		if (alf.FilterRegion)
		{
			if (alf.Region != L"")
			{
				if (Airports[t].Region != alf.Region)
				{
					add = false;
				}
			}
		}

		if (alf.LatitudeFilter)
		{
			if (alf.LatitudeInverse)
			{
				if (Airports[t].LatitudeD > alf.LatitudeFrom && Airports[t].LatitudeD < alf.LatitudeTo)
				{
					add = false;
				}
			}
			else
			{
				if (Airports[t].LatitudeD > alf.LatitudeFrom || Airports[t].LatitudeD < alf.LatitudeTo)
				{
					add = false;
				}
			}
		}

		if (alf.UseTimeOfDay || alf.LongitudeFilter)
		{
			if (alf.LongitudeInverse)
			{
				if (Airports[t].LongitudeD > alf.LongitudeFrom && Airports[t].LongitudeD < alf.LongitudeTo)
				{
					add = false;
				}
			}
			else
			{
				if (Airports[t].LongitudeD > alf.LongitudeFrom || Airports[t].LongitudeD < alf.LongitudeTo)
				{
					add = false;
				}
			}
		}

		if (Airports[t].Elevation < alf.MinimumElevation || Airports[t].Elevation > alf.MaximumElevation)
		{
			add = false;
		}

		switch (Airports[t].Type)
		{
		case AirportConstants::AirportType::None:
			break;
		case AirportConstants::AirportType::Small:
			if (!alf.SmallAirports)
			{
				add = false;
			}
			break;
		case AirportConstants::AirportType::Medium:
			if (!alf.MediumAirports)
			{
				add = false;
			}
			break;
		case AirportConstants::AirportType::Large:
			if (!alf.LargeAirports)
			{
				add = false;
			}
			break;
		case AirportConstants::AirportType::Heliport:
			if (!alf.Heliports)
			{
				add = false;
			}
			break;
		case AirportConstants::AirportType::SeaplaneBase:
			if (!alf.SeaplaneBases)
			{
				add = false;
			}
			break;
		}

		if (add)
		{
			FilteredList.push_back(Airports[t]);
		}
	}

	return FilteredList.size();
}


bool AirportHandler::LoadAirports(const std::wstring file_name)
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

		file.close();
    }
    else
    {
		return false;
    }

    return true;
}


bool AirportHandler::ImportFromRow(const std::wstring row)
{
	if (row.length() != 0)
    {
		std::wstring Ident = L"";
		std::wstring IATA = L"";
        AirportConstants::AirportType Type = AirportConstants::AirportType::None;
        std::wstring tfield = L"";
        std::wstring Name = L"";
        int Elevation = 0;
        std::wstring Latitude = L"";
        std::wstring Longitude = L"";
        std::wstring Country = L"";
        std::wstring Continent = L"";
        std::wstring Region = L"";
        bool MSFSCompatible = false;

        std::wstring field = L"";
        int field_position = 0;

        bool inquotes = false;

        for (int t = 0; t < row.length(); t++)
        {
            if (row[t] == L',' && !inquotes)
            {
                switch (field_position)
                {
                case kAFieldIdent:
                    Ident = field;
                    break;
                case kAFieldType:
                {
                    Type = GetTypeFrom(field);

					if (Type == AirportConstants::AirportType::None)
                    {
                        return false;
                    }

                    break;
                }
                case kAFieldName:
                    Name = field;
                    break;
				case kAFieldLatitude:
					Latitude = field;
					break;
				case kAFieldLongitude:
					Longitude = field;
					break;
				case kAFieldElevation:
				{
					try
					{
						Elevation = stoi(field);
					}
					catch(...)
					{
						Elevation = 0;
					}

					if (Elevation < DataDefaults::LowestElevation)
					{
						return false;
					}

					if (Elevation < Stats.ElevationLowest)
					{
                        Stats.ElevationLowest = Elevation;
                    }

                    if (Elevation > Stats.ElevationHighest)
                    {
                        Stats.ElevationHighest = Elevation;
                    }

                    break;
                }
                case kAFieldContinent:
                    Continent = field;
					break;
				case kAFieldCountry:
					Country = field;
					break;
				case kAFieldRegion:
					Region = field;
					break;
				case kAFieldIATA:
					IATA = field;
					break;
				case kAFieldMSFSCompatible:
					if (field == L"1")
                    {
                        MSFSCompatible = true;
                    }
                    break;
                }

                if (field_position == kAFieldMSFSCompatible)
                {
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

		switch (Type)
		{
		case AirportConstants::AirportType::None:
			break;
        case AirportConstants::AirportType::Small:
			Stats.TypeCount[AirportConstants::AirportTypeSmall]++;
            break;
        case AirportConstants::AirportType::Medium:
			Stats.TypeCount[AirportConstants::AirportTypeMedium]++;
            break;
        case AirportConstants::AirportType::Large:
			Stats.TypeCount[AirportConstants::AirportTypeLarge]++;
            break;
        case AirportConstants::AirportType::Heliport:
			Stats.TypeCount[AirportConstants::AirportTypeHeliport]++;
            break;
        case AirportConstants::AirportType::SeaplaneBase:
            Stats.TypeCount[AirportConstants::AirportTypeSeaplaneBase]++;
            break;
		}

		// =====================================================================

		for (int t = 0; t < 7; t++)
		{
			if (Location::ContinentShort[t] == Continent)
			{
				Stats.Continents[t]++;
				break;
			}
		}

		// =====================================================================

		Airport airport(Ident, Type, Name, Elevation, Latitude, Longitude, Country, Continent, Region, IATA, MSFSCompatible);

        Airports.push_back(airport);

        return true;
    }

    return false;
}


AirportConstants::AirportType AirportHandler::GetTypeFrom(const std::wstring row)
{
	switch (Utility::GetAirportType(row))
	{
	case AirportConstants::AirportType::None:
		return AirportConstants::AirportType::None;
    case AirportConstants::AirportType::Small:
		return AirportConstants::AirportType::Small;
	case AirportConstants::AirportType::Medium:
		return AirportConstants::AirportType::Medium;
	case AirportConstants::AirportType::Large:
		return AirportConstants::AirportType::Large;
	case AirportConstants::AirportType::Heliport:
		return AirportConstants::AirportType::Heliport;
	case AirportConstants::AirportType::SeaplaneBase:
		return AirportConstants::AirportType::SeaplaneBase;
	}

	return AirportConstants::AirportType::None;
}


int AirportHandler::FindNearest(const std::wstring start_icao, double range, bool output)
{
    int StartAirport = kRandomAirport;

    if (start_icao != L"")
    {
        StartAirport = GetIndexFromICAO(start_icao);
    }
    else
    {
        return 0;
    }

    Airport origin = GetAirport(StartAirport);

    if (origin.Type != AirportConstants::AirportType::None)
    {
        CalculateDistancesNoMinimum(range, origin.LatitudeR, origin.LongitudeR);

        if (output)
		{
			if (FlightCache.size() != 0)
			{
				// TO DO std::ranges::sort(RouteCache, {}, &Airport::Distance);

//                std::wcout << L"  All airports wthin " << range << L" nm of " << start_icao << "\n\n";

				for (int t = 0; t < FlightCache.size(); t++)
				{
  //                  std::wcout << std::format(L"    {0}, {1} ({2}), {3:.1f} nm, {4}\n", RouteCache[t].Ident, RouteCache[t].Country, RouteCache[t].Region, RouteCache[t].Distance, Utility::GetAirportTypeDisplay(RouteCache[t].Type));
				}

	//            std::wcout << std::format(L"\n  Found {0} airports within range of {1}.\n\n", RouteCache.size(), start_icao);
			}
			else
			{
	  //          std::wcout << L"Sorry, no airports could be found within " << range << L" nm of " << start_icao << L" :(\n\n";
			}
		}
	}

	return static_cast<int>(FlightCache.size());
}


std::wstring AirportHandler::GetLastError()
{
    return LastError;
}


void AirportHandler::Populate(int id)
{
	Flight& f = GFlightHandler->Flights[id];

	int afrom = GetIndexFromICAO(f.SimpleFromICAO);
	f.Airports.push_back(GAirportHandler->GetAirport(afrom));

	int ato = GetIndexFromICAO(f.SimpleToICAO);
	f.Airports.push_back(GetAirport(ato));

	f.Airports.back().Distance = f.Distance;

	f.Airports.back().Angle = Utility::AngleBetween(f.Airports.front().LatitudeR, f.Airports.front().LongitudeR,
													f.Airports.back().LatitudeR, f.Airports.back().LongitudeR);

	f.Simple = false;
}
