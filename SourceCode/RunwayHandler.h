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

	[[nodiscard]] bool LoadRunways(const std::wstring);

	[[nodiscard]] bool ImportFromRow(const std::wstring);

	#ifdef _DEBUG
	void ImportedDataCheck();
	#endif

public:

	bool Loaded = false;

	std::vector<Runway> Runways;

	RunwayHandler(const std::wstring);

	RunwayHandler(bool, const std::wstring);

	Runway GetRandom(std::wstring);

	int FindAndSet(const std::wstring);

	bool Save(const std::wstring, bool);
};