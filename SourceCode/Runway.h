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


class Runway
{
public:

	std::wstring Ident = L"";
	std::wstring Name = L"";
	std::wstring SurfaceType = L"";	
	int Length = 0;

	Runway();

	Runway(std::wstring, std::wstring, std::wstring, int);
};