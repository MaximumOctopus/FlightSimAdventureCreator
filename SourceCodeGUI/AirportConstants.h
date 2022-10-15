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


namespace AirportConstants
{
	enum class AirportType { None = 0, Small = 1, Medium = 2, Large = 3, Heliport = 4, SeaplaneBase = 5 };

	static const std::wstring SmallAirport = L"small_airport";		// as specified in the source airports.csv file from ourairports.com
	static const std::wstring MediumAirport = L"medium_airport";	//
	static const std::wstring LargeAirport = L"large_airport";		//
	static const std::wstring Heliport = L"heliport";				//
	static const std::wstring SeaplaneBase = L"seaplane_base";		//

	static const int AirportTypeCount = 5;

	static const int AirportTypeSmall = 0;
	static const int AirportTypeMedium = 1;
	static const int AirportTypeLarge = 2;
	static const int AirportTypeHeliport = 3;
	static const int AirportTypeSeaplaneBase = 4;
}