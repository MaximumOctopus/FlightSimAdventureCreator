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

#include <vector>

#include "Airline.h"


class AirlineHandler
{
	static const int kAFieldName = 1;
	static const int kAFieldCode = 3;

	[[nodiscard]] bool LoadAirlines(const std::wstring);

	bool ImportFromRow(const std::wstring);

public:

	bool Loaded = false;

	std::vector<Airline> Airlines;

	AirlineHandler(const std::wstring);

	std::wstring FindWithCode(const std::wstring);
};