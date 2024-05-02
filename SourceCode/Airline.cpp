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

#include <format>

#include "Airline.h"


Airline::Airline(const std::wstring name, const std::wstring code)
{
	Name = name;
	Code = code;
}