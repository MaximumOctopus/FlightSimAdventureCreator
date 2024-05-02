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


class Route
{
public:

	std::wstring FromIATA = L"";
	std::wstring ToIATA = L"";
	std::wstring FromICAO = L"";
	std::wstring ToICAO = L"";
	std::wstring Airline = L"";
	std::wstring Equipment = L"";
	double Distance = 0;
	std::wstring FromCountry = L"";
	std::wstring FromContinent = L"";
	std::wstring FromRegion = L"";
	std::wstring ToCountry = L"";
	std::wstring ToContinent = L"";
	std::wstring ToRegion = L"";

	Route(const std::wstring, const std::wstring, const std::wstring, const std::wstring, 
		const std::wstring, 
		const std::wstring,	double,
		const std::wstring, const std::wstring, const std::wstring, 
		const std::wstring, const std::wstring, const std::wstring);
};