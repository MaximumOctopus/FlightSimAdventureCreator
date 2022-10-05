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

#include "AirportConstants.h"


class Airport
{

public:

	std::wstring Ident = L"";				// ICAO code
	AirportConstants::AirportType Type = AirportConstants::AirportType::None;
	std::wstring Name = L"";
	int Elevation = 0;						// in feet
	std::wstring Latitude = L"";
	std::wstring Longitude = L"";
	std::wstring Country = L"";				// ICO code https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2
	std::wstring Continent = L"";			// ICO code
	std::wstring Region = L"";				// ISO region codes https://en.wikipedia.org/wiki/ISO_3166-2 (has links to available codes for each country)
	bool MSFSCompatible = false;

	std::wstring Runway = L"";				// generated randomly for a route
	int RunwayLength = 0;

	double LatitudeD = 0;					// value cached as double for quicker calcs
	double LongitudeD = 0;					//

	double LatitudeR = 0;					// value cached in radians for quicker distance calc
	double LongitudeR = 0;					//

	double Distance = 0;
	double Angle = 0;

	Airport();

	Airport(std::wstring, AirportConstants::AirportType, std::wstring, int, std::wstring, std::wstring, std::wstring, std::wstring, std::wstring, bool);

	// if runway is 26L then returns 26
	std::wstring RunwayNumber();

	// if runway is 26L then returns LEFT
	std::wstring RunwayDesignator();

	void Show();
};