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

#pragma once

#include <string>
#include <vector>

#include "Airport.h"


namespace TextItinerary
{
	bool Export(std::vector<Airport>&, const std::wstring);
}