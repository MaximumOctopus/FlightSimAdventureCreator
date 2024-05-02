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

#pragma once


#include <vector>

#include "AircraftConstants.h"
#include "Defaults.h"
#include "Flight.h"


struct FlightFilter
{
	bool Ignore = false;

	// =========================================================================

	int GenerateMode = 0;                       // 0 = random, 1 = realworld

	// =========================================================================

	double RWRange = DataDefaults::Range;

	bool RWUseAircraftRange = false;
	bool RWUseFlightTime = false;
	int RWFlightTime = DataDefaults::FlightTime;
	bool RWUseExcessRange = false;

	bool RWFromAirport = true;
	std::wstring RWAirport = L"";
	int RWRouteType = 0;

	bool RWUseAirline = false;
    std::wstring RWAirline = L"";

	int RWCount = DataDefaults::Routes;

	// =========================================================================

	double Range = DataDefaults::Range;          // nautical miles
	int Legs = 1;
	int Count = 10;

	bool UseDirection = false;
	double Direction = DataDefaults::Direction;  // travel direction in degrees

	std::wstring StartAirportICAO = L"";
	std::wstring EndAirportICAO = L"";

	bool StartFromFavourite = false;
	bool EndAtFavourite = false;

	bool UseAircraftRange = false;
	double AircraftRangeModifier = DataDefaults::AircraftRangePC;

	bool UseFlightTime = false;
	int FlightTime = DataDefaults::FlightTime;
	bool UseExcessRange = false;

	bool StartEndUseLegs = true;

	int SimpleRouteCount = DataDefaults::Routes;

	// =========================================================================

	bool KeepTrying = false;
};


class FlightHandler
{

public:

	std::vector<Flight> Flights;

	FlightHandler();

	bool ExportAllToMSFS();
	bool ExportAllToItinerary();

	bool ExportToItinerary(const std::wstring, int);
	bool ExportToMSFS(const std::wstring, int);
	bool ExportToXPlane11(const std::wstring, int);

	int SetRangeFromTime(int, int, int, AircraftConstants::AircraftType);

	void Add(Flight);

	std::wstring BuildRouteDescription(const std::wstring, const std::wstring, bool, bool, double, double, int, int, int, bool,
										bool, int, int);

    void Sort(int);

	void SaveToCSV(std::wstring);
};
