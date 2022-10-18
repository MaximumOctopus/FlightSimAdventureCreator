//
// FlightSimAdventureCreator 1.0
//
// (c) Paul Alan Freshney 2022
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


struct AircraftLoadFilter {
	int Type = Defaults::DefaultAircraftSelection;	// 0 = prop, 1 = jet, 2 = heli, 3 = glider, 4 = twin prop, 5 = turbo prop, 6 = twin turbo prop, 7 = balloon

	int MaxSpeed = Defaults::DefaultMaxSpeed;		// maximum cruise speed required
	int MinSpeed = 0;								// minimum cruise speed required

	bool Airliner = true;	
	bool Military = true;
	bool Seaplane = false;

	AircraftConstants::SpecialMode Special = AircraftConstants::SpecialMode::None;		
													// this is a setting that encapulates several settings in a single flag
													// GA: prop and twin prop types, no military, no airliners
													// Twins: twin props and twin turbo props, no military
													// Turbos: turbo props and twin turbo props


	AircraftConstants::MSFSVersion Version = AircraftConstants::MSFSVersion::All;
};


class AircraftHandler {

	bool Silent = false;

	AircraftLoadFilter LoadFilter;

	int TypeCount[AircraftConstants::AircraftTypeCount] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	enum class RowType { Unknown = 0, SectionStart = 1, SectionEnd = 2, Name = 3, Cruise = 4, Range = 5, Availability = 6, Type = 7, AirLiner = 8, Military = 9, Seaplane = 10, RunwayLength = 11 };
	enum class ProcessingMode { ReadyForSection = 0, SectionFound = 1 };

	[[nodiscard]] bool LoadAircraft(const std::wstring);

	[[nodiscard]] RowType GetRowType(const std::wstring);

	[[nodiscard]] std::wstring GetStringValueFromRow(const std::wstring);
	[[nodiscard]] int GetIntValueFromRow(const std::wstring);

public:

	bool Loaded = false;

	std::vector<Aircraft> AircraftList;

	AircraftHandler(bool, bool, bool, int, bool, bool, bool, int, int, AircraftConstants::MSFSVersion, AircraftConstants::SpecialMode);

	Aircraft GetRandomAircraft();
};