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

#include <string>
#include <vector>

#include "Aircraft.h"
#include "AircraftConstants.h"
#include "Constants.h"
#include "ConfigurationConstants.h"
#include "Defaults.h"


struct AircraftStats
{
	int LowestCruise = 99999;
	int HighestCruise = 0;

	int LowestRange = 99999;
	int HighestRange = 0;

   	int TypeCount[AircraftConstants::AircraftTypeCount] = { 0, 0, 0, 0, 0, 0, 0, 0 };
};


struct AircraftLoadFilter
{
	bool Ignore = false;

	bool Types[8] = { true, true, true, true, true, true, true, true };

	int MaxSpeed = DataDefaults::MaxSpeed;		// maximum cruise speed required
	int MinSpeed = 1;							// minimum cruise speed required

	bool Airliner = true;
	bool Military = true;
	bool Seaplane = false;

	AircraftConstants::MSFSVersion Version = AircraftConstants::MSFSVersion::All;
};


class AircraftHandler
{
	std::wstring LastError = L"";

	AircraftLoadFilter LoadFilter;

	enum class RowType { Unknown = 0, SectionStart = 1, SectionEnd = 2, Name = 3, Cruise = 4, Range = 5, Availability = 6, Type = 7, AirLiner = 8, Military = 9, Seaplane = 10, RunwayLength = 11 };
	enum class ProcessingMode { ReadyForSection = 0, SectionFound = 1 };

	[[nodiscard]] bool LoadAircraft(const std::wstring);

	[[nodiscard]] RowType GetRowType(const std::wstring);

	[[nodiscard]] std::wstring GetStringValueFromRow(const std::wstring);
	[[nodiscard]] int GetIntValueFromRow(const std::wstring);

public:

	bool Loaded = false;

    AircraftStats Stats;

	std::vector<Aircraft> AircraftList;
	std::vector<Aircraft> FilteredList;

	AircraftHandler();

	Aircraft GetRandomAircraft();

	int Filter(AircraftLoadFilter);

    std::wstring GetLastError();
};