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


#include <string>
#include <vector>

#include "Airport.h"


class Route
{

public:

	std::vector<Airport> Airports;      // in order of visit

	std::wstring Name = L"";
	int Distance = 0;

	std::wstring Continent = L"";
	std::wstring Country = L"";
	std::wstring Region = L"";

	Route(std::wstring, int);
};
