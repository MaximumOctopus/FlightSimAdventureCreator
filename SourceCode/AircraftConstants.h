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


namespace AircraftConstants
{
	enum class MSFSVersion { All = 0, DeluxeAbove = 1, PremiumAbove = 2 };
	enum class AircraftType { None = 0, Prop = 1, Jet = 2, Helicopter = 3, Glider = 4, TwinProp = 5, TurboProp = 6, TwinTurboProp = 7 };

	static const int AircraftTypeProp = 0;
	static const int AircraftTypeJet = 1;
	static const int AircraftTypeHeli = 2;
	static const int AircraftTypeGlider = 3;
	static const int AircraftTypeTwinProp = 4;
	static const int AircraftTypeTurboProp = 5;
	static const int AircraftTypeTwinTurboProp = 6;

	static const int AircraftTypeCount = 7;
	static const int AircraftTypeMin = 0;
	static const int AircraftTypeMax = 6;

	static const int MSFSVersionMin = 0;
	static const int MSFSVersionMax = 2;
}
