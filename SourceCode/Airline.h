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


class Airline
{
public:

	std::wstring Name = L"";
	std::wstring Code = L"";

	Airline(const std::wstring, const std::wstring);
};