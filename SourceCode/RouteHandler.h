//
// FlightSimAdventureCreator 1.0
//
// (c) Paul Alan Freshney 2022-2023
//
// paul@freshney.org
// 
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
// 
// 

#pragma once

#include <vector>

#include "Route.h"


struct RouteStats
{
	int Shortest = 99999;
	int Longest = 0;
	int Total = 0;
    int Average = 0;

	int Continents[7] = { 0, 0, 0, 0, 0, 0, 0 };
};


struct RouteFilter
{
	double Distance = 0;                // original distance, usedd to generate new values when "keep trying"

	double DistanceMin = 0;
	double DistanceMax = 0;

	bool DirectionFrom = true;			// true: ICAO is start, false: ICAO is end

	std::wstring ICAO = L"";

    bool SpecificAirline = false;
	std::wstring Airline = L"";

    bool KeepTrying = false;

	bool InternalOnly = false;
    bool ExternalOnly = false;

	int RouteCount = 0;

	void Next(int attempt)
	{
		Distance *= 1.0 + (((double)attempt + 1) * 0.05);

		DistanceMin = (0.9 - (((double)attempt + 1) * 0.01)) * Distance;
		DistanceMax = (1.1 + (((double)attempt + 1) * 0.01)) * Distance;
	}
};


class RouteHandler
{
	static const int kFieldAirline = 0;
	static const int kFieldFromIATA = 1;
	static const int kFieldFromICAO = 2;
	static const int kFieldToIATA = 3;
	static const int kFieldToICAO = 4;
	static const int kFieldEquipment = 5;
	static const int kFieldDistance = 6;
	static const int kFieldFromCountry = 7;
	static const int kFieldFromContinent = 8;
	static const int kFieldFromRegion = 9;
	static const int kFieldToCountry = 10;
	static const int kFieldToContinent = 11;
	static const int kFieldToRegion = 12;

	std::vector<Airport> Airports;

	bool Silent = false;
	bool ExtraDetail = false;

	bool ExportMSFSPlan = false;
	bool ExportTextReport = false;

	int TryGenerateRoutes(RouteFilter&);
	int TryGenerateRoutesNoAirport(RouteFilter&);

	void RouteFound(int, int, int, int);

	[[nodiscard]] bool LoadRoutes(const std::wstring);
	[[nodiscard]] bool LoadFromCache(const std::wstring);
	[[nodiscard]] bool LoadToCache(const std::wstring);

    bool ImportFromRow(const std::wstring);

public:

	bool Loaded = false;

    RouteStats Stats;

	std::vector<Route> Routes;
	std::vector<std::wstring> FromCache;
	std::vector<std::wstring> ToCache;
    std::vector<std::wstring> Airlines;

	RouteHandler(const std::wstring, bool,  bool, bool, bool);

	int GenerateRoutes(RouteFilter&);

	bool IsValidFromAirport(const std::wstring);
	bool IsValidToAirport(const std::wstring);
};
