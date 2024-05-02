//
// FlightSimAdventureCreator 1.0
//
// (c) Paul Alan Freshney 2023-2024
//
// paul@freshney.org
// 
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
// 
//

#pragma once


#include <string>
#include <vector>

#include "POI.h"


static const int kPFieldName = 1;
static const int kPFieldLatitude = 3;
static const int kPFieldLongitude = 4;
static const int kPFieldDescription = 8;


class POIHandler
{
	[[nodiscard]] bool LoadPOIs(const std::wstring);

	[[nodiscard]] bool ImportFromRow(const std::wstring);

public:

	bool Loaded = false;

	std::vector<POI> POIs;

	POIHandler();
};