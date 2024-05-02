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
#include <vector>

#include "Airport.h"


namespace XPlaneFlightPlan
{
	// exports a v11 xplane flight plan file
	bool Export(std::vector<Airport>&, const std::wstring);
}