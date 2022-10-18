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

#include "AircraftConstants.h"


class Aircraft
{
public:

	std::wstring Name = L"";
	int CruiseSpeed = 0;			// cruise speed in kts
	int Range = 0;					// max range in nautical miles
	int RunwayLength = 0;			// minimum take-off runway length required (0 = don't care)
	AircraftConstants::MSFSVersion Availability = AircraftConstants::MSFSVersion::All;
	AircraftConstants::AircraftType Type = AircraftConstants::AircraftType::None;
	bool Airliner = false;
	bool Military = false;
	bool Seaplane = false;	

	Aircraft();

	Aircraft(const std::wstring, int, int, int, AircraftConstants::MSFSVersion, AircraftConstants::AircraftType, bool, bool, bool);

	std::wstring Show();
};