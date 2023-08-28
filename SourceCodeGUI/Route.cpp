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

#include "Route.h"


Route::Route(const std::wstring _FromIATA, const std::wstring _ToIATA, const std::wstring _FromICAO, const std::wstring _ToICAO,
	const std::wstring _Airline,
	const std::wstring _Equipment, double _Distance,
	const std::wstring _FromCountry, const std::wstring _FromContinent, const std::wstring _FromRegion,
	const std::wstring _ToCountry, const std::wstring _ToContinent, const std::wstring _ToRegion)
{
	FromIATA = _FromIATA;
	ToIATA = _ToIATA;
	
	FromICAO = _FromICAO;
	ToICAO = _ToICAO;
	
	Airline = _Airline;
	Equipment = _Equipment;
	Distance = _Distance;
	
	FromCountry = _FromCountry;
	FromContinent = _FromContinent;
	FromRegion = _FromRegion;

	ToCountry = _ToCountry;
	ToContinent = _ToContinent;
	ToRegion = _ToRegion;
}