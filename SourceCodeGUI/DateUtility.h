//
// FlightSimAdventureCreator 1.0 (GUI Version)
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

static const int kDisplayModeConsole = 0;
static const int kDisplayModeFile = 1;


namespace DateUtility
{
	// this incredibly well-researched data is used by the routines that generate longitude boundaries for a day or night flight
	// it's likely northern hemisphere-centric (and biased a bit towards a northern European day), but is still good enough for now (is it?!)
	// this represents number of hours around midday + and - that are light (roughly)
	// so in january, rough estimate for light is 0800 to 1600
	static const int HoursOfDayLightModifier[] = { 4, 5, 6, 7, 8, 9, 9, 8, 8, 7, 6, 5 };

	double GetUTCHour();
	int GetMonth();

	std::wstring DateTime(int);
}