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


class NavAidsHandler
{
	[[nodiscard]] bool LoadNavAids(const std::wstring);

public:

	bool Loaded = false;

	NavAidsHandler();
};