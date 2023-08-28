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

#include <vector>

#include "Airline.h"

static const int kFFieldName = 0;
static const int kFFieldIATA = 1;


class AirlineHandler
{

	[[nodiscard]] bool LoadAirlines(const std::wstring);
	[[nodiscard]] bool ImportFromRow(const std::wstring);

public:

    bool Loaded = false;

	std::vector<Airline> Airlines;

	AirlineHandler();
};
