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


class NavAid
{
public:

	std::wstring Name = L"";
	std::wstring Ident = L"";
	std::wstring Type = L"";
	std::wstring Freq = L"";				// kHz
	std::wstring Country = L"";				// ICO code

	int Elevation = 0;

	double LatitudeD = 0;					// value cached as double for quicker calcs
	double LongitudeD = 0;					//

	double LatitudeR = 0;					// value cached in radians for quicker distance calc
	double LongitudeR = 0;					//

	NavAid(const std::wstring, const std::wstring, const std::wstring);
};