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


namespace Defaults
{
	static const int DefaultACPC = 75;				// nautical miles
	static const int DefaultRange = 100;			// nautical miles	
	static const int DefaultMaxSpeed = 9999;		// kts

	static const int DefaultAircraftSelection = -1; // internally this just means all, no filter
	static const int DefaultDirection = -1;			// internally this just means don't filter on direction
	static const int DefaultDirectionMargin = 25;   // added to direction values +/- to increase chances of hitting and airport

	static const int DefaultShortRoutesToShow = 5;	// route generation with 1 leg will output a set number of randomised routes. default is here
}


namespace Constants
{
	enum class TimeOfDay { None = 0, Midday = 1, Midnight = 2 };

	static const std::wstring CompassBearings[16] = { L"N", L"NNE", L"NE", L"ENE", L"E", L"ESE", L"SE", L"SSE", L"S", L"SSW", L"SW", L"WSW", L"W", L"WNW", L"NW", L"NNW"};
	static const double CompassDegrees[16] = { 0, 22.5, 45, 67.5, 90, 112.5, 135, 157.5, 180, 202.5, 225, 247.5, 270, 292.5, 315, 337.5 };
}