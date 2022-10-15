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


namespace DataDefaults
{
	static const int ACPC = 75;					// % modifier of aircraft range to get leg range
	static const int Range = 100;				// nautical miles
	static const int MaxSpeed = 9999;			// kts

    static const int LowestElevation = -2000;

	static const int RangeModifier = 10;         // percent + / -

	static const int AircraftSelection = -1;		// internally this just means all, no filter
	static const double Direction = -1;			// internally this just means don't filter on direction
	static const double DirectionMargin = 25;	// added to direction values +/- to increase chances of hitting and airport

	static const int ShortRoutesToShow = 5;		// route generation with 1 leg will output a set number of randomised routes. default is here

	static const int MaximumAttempts = 5;

    static const int FlightTime = 60;           // minutes
}