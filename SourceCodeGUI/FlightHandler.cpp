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

#pragma hdrstop

#include <fstream>

#include "DateUtility.h"
#include "Formatting.h"
#include "TextItinerary.h"
#include "MSFSFlightPlan.h"
#include "FlightHandler.h"
#include "Utility.h"
#include "XPlaneFlightPlan.h"

#pragma package(smart_init)


FlightHandler* GFlightHandler;


bool sortBySize(const Flight &lhs, const Flight &rhs) { return lhs.Distance < rhs.Distance; }


FlightHandler::FlightHandler()
{

}


bool FlightHandler::ExportToMSFS(const std::wstring file_name, int route_id)
{
	return MSFSFlightPlan::Export(Flights[route_id].Airports, file_name);
}


bool FlightHandler::ExportToItinerary(const std::wstring file_name, int route_id)
{
	return TextItinerary::Export(Flights[route_id].Airports, file_name);
}


bool FlightHandler::ExportToXPlane11(const std::wstring file_name, int route_id)
{
	return XPlaneFlightPlan::Export(Flights[route_id].Airports, file_name);
}


bool FlightHandler::ExportAllToMSFS()
{
	if (Flights.size() != 0)
	{
		for (int t = 0; t < Flights.size(); t++)
		{
			MSFSFlightPlan::Export(Flights[t].Airports, L"Plans\\" + Flights[t].Airports.front().Ident + L"_to_" + Flights[t].Airports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".pln");
		}

		return true;
	}

	return false;
}


bool FlightHandler::ExportAllToItinerary()
{
	if (Flights.size() != 0)
	{
		for (int t = 0; t < Flights.size(); t++)
		{
			TextItinerary::Export(Flights[t].Airports, L"Reports\\" + Flights[t].Airports.front().Ident + L"_to_" + Flights[t].Airports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".txt");
		}

		return true;
	}

	return false;
}


void FlightHandler::Add(Flight flight)
{
	Flights.push_back(flight);
}


// the range can't be set from time until we have an aircraft, so this
// function must be called once an aircraft has been generated
int FlightHandler::SetRangeFromTime(int flight_time, int legs, int speed, AircraftConstants::AircraftType type)
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


std::wstring FlightHandler::BuildRouteDescription(const std::wstring start_icao, const std::wstring end_icao, bool start_favourite, bool end_favourite, double range, double direction, int legs, int simple_count, int flight_time, bool keep_trying,
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


void FlightHandler::Sort(int mode)
{
	std::sort(Flights.begin(), Flights.end(), sortBySize);
}


void FlightHandler::SaveToCSV(std::wstring file_name)
{
	std::ofstream ofile(file_name);

	if (ofile)
	{
		ofile << Formatting::to_utf8(L"// 1 route per line, per airport {ICAO,IATA,Name,Elevation,Longitude,Latutude,Country,Continent,Region} \n");

		for (int t = 0; t < Flights.size(); t++)
		{
			std::wstring row(Flights[t].ToCSVRow());

			ofile << Formatting::to_utf8(row + L"\n");
		}

        ofile.close();
	}
}
