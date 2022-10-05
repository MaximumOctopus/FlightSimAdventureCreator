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


#include <vector>

#include "Airport.h"
#include "AirportConstants.h"
#include "Configuration.h"


static const int kRandomAirport = -1;

static const int kAFieldIdent = 1;
static const int kAFieldType = 2;
static const int kAFieldName = 3;
static const int kAFieldLatitude = 4;
static const int kAFieldLongitude = 5;
static const int kAFieldElevation = 6;
static const int kAFieldContinent = 7;
static const int kAFieldCountry = 8;
static const int kAFieldRegion = 9;
static const int kAFieldMSFSCompatible = 25;


struct AirportLoadFilter {
	int MinimumElevation = 0;		// in feet

	std::wstring Country = L"";		// ISO code https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2
	std::wstring Continent = L"";	// ISO code
	std::wstring Region = L"";		// ISO region codes https://en.wikipedia.org/wiki/ISO_3166-2 (has links for each country to available codes)

	bool LargeAirports = false;		// "large_airport" in fcas.csv
	bool MediumAirports = false;	// "medium_airport" in fcas.csv
	bool SmallAirports = false;		// "small_airport" in fcas.csv
	bool Heliports = false;			// "heliport" in fcas.csv

	bool Day = false;				// airports in daylight
	bool Night = false;				// airports at night

	double LongitudeFrom = 0;		// longitude range
	double LongitudeTo = 0;			//
};


struct AirportRouteGeneration
{
	int ShortRouteCount = Defaults::DefaultShortRoutesToShow;	// how many of the short, A->B, routes to display (it could create hundreds!)
};


class AirportHandler
{
	int TypeCount[AirportConstants::AirportTypeCount] = { 0, 0, 0, 0, 0 };

	bool Silent = false;

	std::vector<Airport> MultiLegAirports;
	std::vector<Airport> RouteCache;

	bool ExportMSFSPlan = false;

	AirportLoadFilter Filter;
	AirportRouteGeneration Generation;

	[[nodiscard]] bool LoadAirports(const std::wstring);
	bool ImportFromRow(const std::wstring);

	[[nodiscard]] AirportConstants::AirportType GetTypeFrom(std::wstring);

	[[nodiscard]] double DistanceBetween(double, double, double, double);

	void CalculateDistances(double, double, double);
	void CalculateDistances(double, double, int, double, double);					// when we also need distance
	void CalculateDistancesNoMinimum(double, double, double);				// unlike the above two, this is strictly if airport range <= range

	bool SimpleRoute(std::wstring, double, double, bool);
	bool MultiLegRoute(std::wstring, double, double, int, bool);

	void ListAirports();

public:

	bool Loaded = false;

	std::vector<Airport> Airports;

	AirportHandler(std::wstring);

	AirportHandler(bool, bool, AirportData);

	Airport GetAirport(int);

	int GetIndexFromICAO(std::wstring);

	void GetRoute(std::wstring, double, double, int, int, bool);

	int FindNearest(const std::wstring, double, bool);

	[[nodiscard]] bool Save(std::wstring, bool);
};