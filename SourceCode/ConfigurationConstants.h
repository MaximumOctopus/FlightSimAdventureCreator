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


namespace Constants
{
	enum class TimeOfDay { None = 0, Midday = 1, Midnight = 2 };

	static const std::wstring CompassBearings[16] = { L"N", L"NNE", L"NE", L"ENE", L"E", L"ESE", L"SE", L"SSE", L"S", L"SSW", L"SW", L"WSW", L"W", L"WNW", L"NW", L"NNW"};
	static const double CompassDegrees[16] = { 0, 22.5, 45, 67.5, 90, 112.5, 135, 157.5, 180, 202.5, 225, 247.5, 270, 292.5, 315, 337.5 };

	enum class LatLongSelection { None = 0, LatitudeFrom = 1, LatitudeTo = 2, LongitudeFrom = 3, LongitudeTo = 4 };
}