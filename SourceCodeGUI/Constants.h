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


namespace SystemConstants
{
	#ifdef _DEBUG
	static const std::wstring FSACVersion = L"0.2.4 (debug)";
	#else
	static const std::wstring FSACVersion = L"0.2.4";
	#endif

	static const std::wstring FSACDate = L"November 17th 2022";

    static const std::wstring ConfigFileName = L"fsac.data";

	static const std::wstring OurAirportsFileName = L"airports.csv";
	static const std::wstring MSFSCompatSourceFileName = L"LetsFlyDB.csv";

	static const std::wstring AirportsFileName = L"fsac.csv";
	static const std::wstring RunwaysFileName = L"runways.csv";
	static const std::wstring POIFileName = L".csv";						// to do
	static const std::wstring NavAidsFileName = L".csv";					// to do

	static const std::wstring DefaultAircraft = L"default_aircraft.txt";
	static const std::wstring CustomAircraft = L"custom_aircraft.txt";

	static const std::wstring FavouritesFileName = L"favourites.txt";
	static const std::wstring JobsFileName = L"jobs.txt";
}