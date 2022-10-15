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


bool RouteHandler::ExportToMSFS()
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


bool RouteHandler::ExportToItinerary()
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
