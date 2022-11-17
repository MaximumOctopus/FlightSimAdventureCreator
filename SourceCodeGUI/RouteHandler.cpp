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

#pragma hdrstop

#include "DateUtility.h"
#include "TextItinerary.h"
#include "MSFSFlightPlan.h"
#include "RouteHandler.h"
#include "Utility.h"

#pragma package(smart_init)


RouteHandler* GRouteHandler;


RouteHandler::RouteHandler()
{

}


bool RouteHandler::ExportToMSFS(const std::wstring file_name, int route_id)
{
	return MSFSFlightPlan::Export(Routes[route_id].Airports, file_name);
}


bool RouteHandler::ExportToItinerary(const std::wstring file_name, int route_id)
{
	return TextItinerary::Export(Routes[route_id].Airports, file_name);
}


bool RouteHandler::ExportAllToMSFS()
{
	if (Routes.size() != 0)
	{
		for (int t = 0; t < Routes.size(); t++)
		{
			MSFSFlightPlan::Export(Routes[t].Airports, L"Plans\\" + Routes[t].Airports.front().Ident + L"_to_" + Routes[t].Airports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".pln");
		}

		return true;
	}

	return false;
}


bool RouteHandler::ExportAllToItinerary()
{
	if (Routes.size() != 0)
	{
		for (int t = 0; t < Routes.size(); t++)
		{
			TextItinerary::Export(Routes[t].Airports, L"Reports\\" + Routes[t].Airports.front().Ident + L"_to_" + Routes[t].Airports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".txt");
		}

		return true;
	}

	return false;
}


void RouteHandler::Add(Route route)
{
    Routes.push_back(route);
}


// the range can't be set from time until we have an aircraft, so this
// function must be called once an aircraft has been generated
int RouteHandler::SetRangeFromTime(int flight_time, int legs, int speed, AircraftConstants::AircraftType type)
{
	if (speed > 0)
	{
		double range = Utility::AircraftTimeToDistance(flight_time, speed, legs, type);

		if (range > 0)
		{
			return range;
		}
	}

	return -1;
}


std::wstring RouteHandler::BuildRouteDescription(const std::wstring start_icao, const std::wstring end_icao, bool start_favourite, bool end_favourite, double range, double direction, int legs, int simple_count, int flight_time, bool keep_trying,
	bool use_aircraft_range, int aircraft_range, int aircraft_range_modifier)
{
	std::wstring RouteDescription = L"";

	if (start_favourite)
	{
		RouteDescription = L"Favourite -> ";
	}
	else if (start_icao == L"")
	{
		RouteDescription = L"Random -> ";
	}
	else
	{
		RouteDescription = start_icao + L" -> ";
	}

	if (end_favourite)
	{
		RouteDescription = L"Favourite; ";
	}
	else if (end_icao == L"")
	{
		RouteDescription += L"Random; ";
	}
	else
	{
		RouteDescription += end_icao + L"; ";
	}

	if (flight_time == 0)
	{
		RouteDescription += std::to_wstring(static_cast<int>(range)) + L" nm";

		if (use_aircraft_range)
		{
			 RouteDescription += L" (based on aircraft range, " + std::to_wstring(aircraft_range) + L" nm @ " + std::to_wstring(aircraft_range_modifier) + L"%)";
		}

		RouteDescription += L";";
	}
	else
	{
		RouteDescription += std::to_wstring(static_cast<int>(range)) + L" nm (flight time " + std::to_wstring(flight_time) + L" mins); ";
    }

	if (direction != -1)
	{
		RouteDescription += L"@ " + std::to_wstring(direction) + L"°; ";
	}

	RouteDescription += std::to_wstring(legs) + L" leg(s); ";

	if (legs == 1)
	{
		RouteDescription += std::to_wstring(simple_count) + L" routes (max.); ";
	}
	else
	{
		RouteDescription += std::to_wstring(simple_count) + L" routes; ";
	}

	if (keep_trying)
	{
        RouteDescription += L" keep trying (<21 times); ";
    }

	return RouteDescription;
}
