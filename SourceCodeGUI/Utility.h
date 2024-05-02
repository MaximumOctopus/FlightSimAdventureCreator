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


#include <string>

#include "Aircraft.h"
#include "AircraftConstants.h"
#include "AirportConstants.h"
#include "Airport.h"


namespace Utility
{
	[[nodiscard]] double AngleBetween(double, double, double, double);

	[[nodiscard]] std::wstring DegreesToDMS(double, double);

	[[nodiscard]] std::wstring GetContinentFromShortCode(const std::wstring);
	[[nodiscard]] int GetContinentFromShortCodeAsInt(const std::wstring);

	[[nodiscard]] std::wstring GetCountryFromShortCode(const std::wstring);
	[[nodiscard]] int GetCountryFromShortCodeAsInt(const std::wstring);

	[[nodiscard]] double GetRange(const std::wstring);

	[[nodiscard]] double GetDirectionFromBearing(const std::wstring);

	[[nodiscard]] std::wstring GetAircraftType(int);
	[[nodiscard]] std::wstring GetAircraftType(AircraftConstants::AircraftType);
	[[nodiscard]] AircraftConstants::AircraftType GetAircraftTypeFromInt(int);
	[[nodiscard]] int GetAircraftTypeAsInt(AircraftConstants::AircraftType type);
	[[nodiscard]] int GetAircraftTypeToConfigType(AircraftConstants::AircraftType);

	[[nodiscard]] std::wstring GetAirportType(AirportConstants::AirportType);
	AirportConstants::AirportType GetAirportType(const std::wstring);
	[[nodiscard]] std::wstring GetAirportTypeDisplay(AirportConstants::AirportType);

	[[nodiscard]] std::wstring BoolToYesNo(bool);

	[[nodiscard]] std::wstring ExtractFileName(const std::wstring);

	[[nodiscard]] double AircraftTimeToDistance(int, int, int, AircraftConstants::AircraftType);
	[[nodiscard]] double AircraftDistanceToTime(int, int, int, AircraftConstants::AircraftType);

	double ReverseAngle(double);

	bool IsWithinLongLat(double, double, double);
}