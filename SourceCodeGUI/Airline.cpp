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

#include "Airline.h"


Airline::Airline(const std::wstring name, const std::wstring iata, const std::wstring callsign, const std::wstring country)
{
	Name = name;
	IATA = iata;
	Callsign = callsign;
	Country = country;
}
