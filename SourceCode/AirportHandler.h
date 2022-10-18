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


struct AirportStats
{
	int ElevationLowest = 99999;
	int ElevationHighest = -99999;
};


struct AirportLoadFilter {
	int MinimumElevation = -2000;	// in feet (LLMZ is the lowest airport in the world at -1266 feet)

	std::wstring Country = L"";		// ISO code https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2
	std::wstring Continent = L"";	// ISO code
	std::wstring Region = L"";		// ISO region codes https://en.wikipedia.org/wiki/ISO_3166-2 (has links for each country to available codes)

	bool LargeAirports = false;		// "large_airport" in fcas.csv
	bool MediumAirports = false;	// "medium_airport" in fcas.csv
	bool SmallAirports = false;		// "small_airport" in fcas.csv
	bool Heliports = false;			// "heliport" in fcas.csv
	bool SeaplaneBase = false;		// "seaplane_base" in fcas.csv

	double LongitudeFrom = 0;		// limit airports to a range of longitudes
	double LongitudeTo = 0;			//
	double LatitudeFrom = 0;		// limit airports to a range of latitudes
	double LatitudeTo = 0;			//

	bool LongitudeFilter = false;
	bool LatitudeFilter = false;

	bool LongitudeInverse = false;	// if from < to, then this means we have to alter the conditions of discovery
	bool LatitudeInverse = false;	//

	bool Day = false;				// airports in daylight
	bool Night = false;				// airports at night
};


struct AirportRouteGeneration
{
	int ShortRouteCount = Defaults::DefaultShortRoutesToShow;	// how many of the short, A->B, routes to display (it could create hundreds!)
	int MaximumAttempts = Defaults::DefaultMaximumAttempts;
};


class AirportHandler
{
	int TypeCount[AirportConstants::AirportTypeCount] = { 0, 0, 0, 0, 0 };

	bool Silent = false;

	std::vector<Airport> SingleLegAirports;
	std::vector<Airport> MultiLegAirports;
	std::vector<Airport> RouteCache;

	bool ExportMSFSPlan = false;
	bool ExportTextReport = false;

	AirportLoadFilter Filter;
	AirportRouteGeneration Generation;
	AirportStats Stats;

	[[nodiscard]] bool LoadAirports(const std::wstring);
	bool ImportFromRow(const std::wstring);

	[[nodiscard]] AirportConstants::AirportType GetTypeFrom(const std::wstring);

	[[nodiscard]] double DistanceBetween(double, double, double, double);

	void CalculateDistances(double, double, double);
	void CalculateDistances(double, double, double, double, double);					// when we also need distance
	void CalculateDistancesNoMinimum(double, double, double);				// unlike the above two, this is strictly if airport range <= range

	bool SimpleRoute(const std::wstring, double, double, bool, bool);
	bool MultiLegRoute(const std::wstring, double, double, int, bool, bool);
	bool StartToFinish(const std::wstring, const std::wstring, double, int, bool);

	void FinaliseMultiLegData();
	void HandleMultiLegExport();

	void ListAirports();

	#ifdef _DEBUG
	void ImportedDataCheck();
	#endif

public:

	bool Loaded = false;

	std::vector<Airport> Airports;

	AirportHandler(const std::wstring);

	AirportHandler(bool, bool, bool, AirportData);

	Airport GetAirport(int);

	int GetIndexFromICAO(const std::wstring);

	void GetRoute(const std::wstring, const std::wstring, double, double, int, int, bool);

	int FindNearest(const std::wstring, double, bool);

	[[nodiscard]] double DistanceBetweenTwoAirports(const std::wstring, const std::wstring);

	[[nodiscard]] bool Save(const std::wstring, bool);
};