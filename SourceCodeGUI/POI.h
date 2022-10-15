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


class POI
{

public:

	std::wstring Name = L"";
	std::wstring Description = L"";

	std::wstring Latitude = L"";
	std::wstring Longitude = L"";

	double LatitudeD = 0;					// value cached as double for quicker calcs
	double LongitudeD = 0;					//

	double LatitudeR = 0;					// value cached in radians for quicker distance calc
	double LongitudeR = 0;					//

	POI(const std::wstring name, const std::wstring description, const std::wstring latitude, const std::wstring longitude);
};