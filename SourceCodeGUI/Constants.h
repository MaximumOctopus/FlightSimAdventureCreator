//
// FlightSimAdventureCreator 1.0 (GUI Version)
//
// (c) Paul Alan Freshney 2022-2023
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
	static const std::wstring FSACVersion = L"0.5.0 (debug)";
	#else
	static const std::wstring FSACVersion = L"0.5.0";
	#endif

	static const std::wstring FSACDate = L"September 4th 2023";

    static const std::wstring ConfigFileName = L"fsac.data";

	static const std::wstring OurAirportsFileName = L"airports.csv";
	static const std::wstring MSFSCompatSourceFileName = L"LetsFlyDB.csv";

    static const std::wstring AirlineFileName = L"fsacairlines.csv";
	static const std::wstring AirportsFileName = L"fsac.csv";
	static const std::wstring RoutesFileName = L"routes.csv";
	static const std::wstring RoutesFromCacheFileName = L"routes_fromcache.csv";
	static const std::wstring RoutesToCacheFileName = L"routes_tocache.csv";
	static const std::wstring RunwaysFileName = L"runways.csv";

	static const std::wstring POIFileName = L".csv";						// to do
	static const std::wstring NavAidsFileName = L".csv";					// to do

	static const std::wstring DefaultAircraft = L"default_aircraft.txt";
	static const std::wstring CustomAircraft = L"custom_aircraft.txt";

	static const std::wstring FavouritesFileName = L"favourites.txt";
	static const std::wstring JobsFileName = L"jobs.txt";
}