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

#include "Aircraft.h"
#include "AircraftConstants.h"
#include "AirportConstants.h"
#include "Airport.h"


namespace Utility
{
	[[nodiscard]] bool FileExists(const std::wstring&);

	[[nodiscard]] double AngleBetween(double lat1, double long1, double lat2, double long2);

	[[nodiscard]] std::wstring DegreesToDMS(double, double);

	[[nodiscard]] std::wstring GetContinentFromShortCode(std::wstring);
	[[nodiscard]] std::wstring GetCountryFromShortCode(std::wstring);

	[[nodiscard]] std::wstring GetAircraftType(int);
	[[nodiscard]] std::wstring GetAircraftType(AircraftConstants::AircraftType);

	[[nodiscard]] std::wstring GetAirportType(AirportConstants::AirportType);
	[[nodiscard]] std::wstring GetAirportTypeDisplay(AirportConstants::AirportType);

	[[nodiscard]] std::wstring BoolToYesNo(bool);

	[[nodiscard]] int GetUTCHour();

	[[nodiscard]] std::wstring DateTime(int);

	[[nodiscard]] std::wstring ExtractFileName(std::wstring);
}