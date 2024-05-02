//
// FlightSimAdventureCreator 1.0
//
// (c) Paul Alan Freshney 2023-2024
//
// paul@freshney.org
// 
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
// 
// 

#pragma once


#include <string>

#include "AirportConstants.h"


struct RunwayData
{
	std::wstring Name = L"";		// eg 26L
	int Length = 0;					// in feet
	std::wstring Surface = L"";
};


class Airport
{

public:

	RunwayData Runway;

	std::wstring Ident = L"";				// ICAO code
	std::wstring IATA = L"";				// IATA code
	AirportConstants::AirportType Type = AirportConstants::AirportType::None;
	std::wstring Name = L"";
	int Elevation = 0;						// in feet
	std::wstring Latitude = L"";
	std::wstring Longitude = L"";
	std::wstring Country = L"";				// ICO code https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2
	std::wstring Continent = L"";			// ICO code
	std::wstring Region = L"";				// ISO region codes https://en.wikipedia.org/wiki/ISO_3166-2 (has links to available codes for each country)
	bool MSFSCompatible = false;

	double LatitudeD = 0;					// value cached as double for quicker calcs
	double LongitudeD = 0;					//

	double LatitudeR = 0;					// value cached in radians for quicker distance calc
	double LongitudeR = 0;					//

	double Distance = 0;					// stored after route generation
	double Angle = 0;						// stored after route generation 

	Airport();

	Airport(const std::wstring, AirportConstants::AirportType, const std::wstring, int, const std::wstring, const std::wstring, 
		const std::wstring, const  std::wstring, const std::wstring, 
		const std::wstring,
		bool);

	std::wstring Angle1p();

	// if runway is 26L then returns 26
	std::wstring RunwayNumber();

	// if runway is 26L then returns LEFT
	std::wstring RunwayDesignator();

	void Show();
};