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


#include <string>
#include <vector>

#include "Runway.h"


static const int kRFieldIdent = 2;
static const int kRFieldLength = 3;
static const int kRFieldSurfaceType = 5;
static const int kRFieldName = 8;


class RunwayHandler
{
	bool Silent = false;

	[[nodiscard]] bool LoadRunways(std::wstring);

	[[nodiscard]] bool ImportFromRow(const std::wstring);

public:

	bool Loaded = false;

	std::vector<Runway> Runways;

	RunwayHandler(bool);

	Runway GetRandom(std::wstring);
};