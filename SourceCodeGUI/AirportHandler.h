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


#include <vector>

#include "Airport.h"
#include "AirportConstants.h"
#include "Constants.h"
#include "DateUtility.h"
#include "Defaults.h"


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
static const int kAFieldIATA = 13;
static const int kAFieldMSFSCompatible = 25;

enum class TimeOfDay { None = 0, Midday = 1, Midnight = 2 };


struct AirportStats
{
	int ElevationLowest = 99999;
	int ElevationHighest = -99999;

	int Continents[7] = { 0, 0, 0, 0, 0, 0, 0 };

   	int TypeCount[AirportConstants::AirportTypeCount] = { 0, 0, 0, 0, 0 };
};


struct AirportLoadFilter
{
    bool Ignore = false;

	int MinimumElevation = -2000;	// in feet (LLMZ is the lowest airport in the world at -1266 feet)
	int MaximumElevation = 15000;	// in feet (ZUDC is the lowest airport in the world at 14472 feet)

	int Continents[7] = { true, true, true, true, true, true, true };

	bool FilterContinent = true;
	bool FilterCountry = false;
	bool FilterRegion = false;
	bool FilterLatLong = false;

	std::wstring Country = L"";		// ISO code https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2
///	std::wstring Continent = L"";	// ISO code
	std::wstring Region = L"";		// ISO region codes https://en.wikipedia.org/wiki/ISO_3166-2 (has links for each country to available codes)

	bool LargeAirports = true;		// "large_airport" in fcas.csv
	bool MediumAirports = true;		// "medium_airport" in fcas.csv
	bool SmallAirports = true;		// "small_airport" in fcas.csv
	bool Heliports = true;			// "heliport" in fcas.csv
	bool SeaplaneBases = true;		// "seaplane_base" in fcas.csv

	double LongitudeFrom = 0;		// limit airports to a range of longitudes
	double LongitudeTo = 0;			//
	double LatitudeFrom = 0;		// limit airports to a range of latitudes
	double LatitudeTo = 0;			//

	bool LongitudeFilter = false;
	bool LatitudeFilter = false;

	bool LongitudeInverse = false;	// if from < to, then this means we have to alter the conditions of discovery
	bool LatitudeInverse = false;	//

	bool UseTimeOfDay = false;
	bool Day = true;				// airports in daylight
	bool Night = false;				// airports at night

	// this is very rough, I'll improve it over time...
	// let's find midday on Earth (a good aproximation for the lightest part of the day)
	// now let's extend out a number of degreess each side of this, based on the month
	void SetLongitude(TimeOfDay tod, int month)
	{
		static const double DegreesPerHour = 15.0;	// assuming 24 hour earth rotation, 15' per hour

		double time = 0; // hours in 24-hour clock
		double HoursOfInterest = 0;

		if (tod == TimeOfDay::Midnight)
		{
			time = 0;
			HoursOfInterest = (double)(12 - DateUtility::HoursOfDayLightModifier[month]);
		}
		else
		{
			time = 12;
			HoursOfInterest = (double)(DateUtility::HoursOfDayLightModifier[month]);
		}

		double UTCHours = DateUtility::GetUTCHour();

		double deltaH = UTCHours - time;

		double MiddayLong = -deltaH * DegreesPerHour;

		LongitudeFrom = MiddayLong + (HoursOfInterest * DegreesPerHour);
		LongitudeTo = MiddayLong - (HoursOfInterest * DegreesPerHour);

		if (LongitudeFrom > 180)
		{
			LongitudeFrom = (double)-180 + (LongitudeFrom - (double)180);
		}

		if (LongitudeTo > 180)
		{
			LongitudeTo = (double)-180 + (LongitudeTo - (double)180);
		}

		if (LongitudeFrom < -180)
		{
			LongitudeFrom = (double)180 + (LongitudeFrom + (double)180);
		}

		if (LongitudeTo < -180)
		{
			LongitudeTo = (double)180 + (LongitudeTo + (double)180);
		}
	}
};


struct AirportSearchFilter
{
	std::wstring SearchText = L"";

	std::wstring Continent = L"";  		 // ico code
	std::wstring Country = L"";   		// ico code

	bool LargeAirports = false;		// "large_airport" in fcas.csv
	bool MediumAirports = false;		// "medium_airport" in fcas.csv
	bool SmallAirports = false;		// "small_airport" in fcas.csv
	bool Heliports = false;			// "heliport" in fcas.csv
	bool SeaplaneBases = false;		// "seaplane_base" in fcas.csv

	bool WithinRange = false;
	int Range = 100;
	std::wstring Airport = L"";     // icao
};


struct AirportRouteGeneration
{
	int ShortRouteCount = DataDefaults::ShortRoutesToShow;	// how many of the short, A->B, routes to display (it could create hundreds!)
	int MaximumAttempts = DataDefaults::MaximumAttempts;
};


class AirportHandler
{
	std::wstring LastError = L"";

	std::vector<Airport> SingleLegAirports;
	std::vector<Airport> MultiLegAirports;
	std::vector<Airport> FlightCache;

	bool ExportMSFSPlan = false;
	bool ExportTextReport = false;

	AirportRouteGeneration Generation;

	[[nodiscard]] bool LoadAirports(const std::wstring);
	bool ImportFromRow(const std::wstring);

	[[nodiscard]] AirportConstants::AirportType GetTypeFrom(const std::wstring);

	[[nodiscard]] double DistanceBetween(double, double, double, double);

	void CalculateDistances(double, double, double);
	void CalculateDistances(double, double, double, double, double);					// when we also need distance
	void CalculateDistancesNoMinimum(double, double, double);							// unlike the above two, this is strictly if airport range <= range

	bool SimpleRoute(const std::wstring, double, double, bool, bool);
	bool MultiLegRoute(const std::wstring, double, double, int, bool, bool);
	bool StartToFinish(const std::wstring, const std::wstring, double, int, bool);

	void FinaliseMultiLegData();
	void HandleMultiLegExport();

public:

	bool Loaded = false;

	std::vector<Airport> Airports;
	std::vector<Airport> FilteredList;
	std::vector<Airport> SearchResults;

	AirportStats Stats;

	AirportHandler();

	int Filter(AirportLoadFilter);
	int Search(AirportSearchFilter);

	Airport GetAirport(int);

    int GetIndexFromIATA(const std::wstring);
	int GetIndexFromICAO(const std::wstring);
	int GetIndexFromICAOFullList(const std::wstring);
	bool IsValidAirport(const std::wstring);

	bool IsAirportInFilteredList(const std::wstring);

	void GetRoute(const std::wstring, const std::wstring, double, double, int, int, bool);

	int FindNearest(const std::wstring, double, bool);

	[[nodiscard]] double DistanceBetweenTwoAirports(const std::wstring, const std::wstring);

   	void Populate(int);

	std::wstring GetLastError();
};
