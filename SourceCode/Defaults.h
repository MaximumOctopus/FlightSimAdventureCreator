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


namespace Defaults
{
	static const int DefaultACPC = 75;					// nautical miles
	static const int DefaultRange = 100;				// nautical miles	
	static const int DefaultMaxSpeed = 9999;			// kts

	static const int DefaultRangeModifier = 10;         // percent + / -

	static const int DefaultAircraftSelection = -1;		// internally this just means all, no filter
	static const double DefaultDirection = -1;			// internally this just means don't filter on direction
	static const double DefaultDirectionMargin = 25;	// added to direction values +/- to increase chances of hitting and airport

	static const int DefaultShortRoutesToShow = 5;		// route generation with 1 leg will output a set number of randomised routes. default is here

	static const int DefaultMaximumAttempts = 5;
}