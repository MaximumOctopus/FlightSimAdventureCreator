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

#include "Airport.h"


class Flight
{

public:

	std::vector<Airport> Airports;      // in order of visit

	std::wstring Name = L"";
	std::wstring Airline = L"";
	int Distance = 0;

	std::wstring Continent = L"";
	std::wstring Country = L"";
	std::wstring Region = L"";

	bool Simple = false;                // if generating a large number of results we simply store the from and to ICAO values
	std::wstring SimpleFromICAO = L"";  // if and when the airport object is required we can capture it ad-hoc to increase search
	std::wstring SimpleToICAO = L"";    // peformance

	Flight(const std::wstring, const std::wstring, int);

	Flight(const std::wstring, int);

	std::wstring GetMSFSFileName();
	std::wstring GetTextFileName();

	std::wstring ToCSVRow();
};
