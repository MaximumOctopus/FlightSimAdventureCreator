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


class Airline
{
public:

	std::wstring Name = L"";
	std::wstring IATA = L"";
	std::wstring Callsign = L"";
	std::wstring Country = L"";

	Airline(const std::wstring, const std::wstring, const std::wstring, const std::wstring);
};
