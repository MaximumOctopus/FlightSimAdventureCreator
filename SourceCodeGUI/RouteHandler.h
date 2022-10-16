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

#pragma once


#include <vector>

#include "AircraftConstants.h"
#include "Defaults.h"
#include "Route.h"


struct RouteFilter
{
	double Range = DataDefaults::Range;          // nautical miles
	int Legs = 1;
	int Count = 5;

	bool UseDirection = false;
	double Direction = DataDefaults::Direction;  // travel direction in degrees

	std::wstring StartAirportICAO = L"";
	std::wstring EndAirportICAO = L"";

	bool StartFromFavourite = false;

	bool UseAircraftRange = false;
	double AircraftRangeModifier = DataDefaults::ACPC;

	bool UseFlightTime = false;
	int FlightTime = DataDefaults::FlightTime;

    int SimpleRouteCount = 5;
};


class RouteHandler
{

public:

	std::vector<Route> Routes;

	RouteHandler();

	bool ExportToMSFS();
	bool ExportToItinerary();

	int SetRangeFromTime(int, int, int, AircraftConstants::AircraftType);

	void Add(Route);
};