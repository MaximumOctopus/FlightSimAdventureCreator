//
// FlightSimAdventureCreator 1.0 (GUI Version)
//
// (c) Paul Alan Freshney 2022-2024
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
	std::wstring LastError = L"";

	[[nodiscard]] bool LoadRunways(const std::wstring);

	[[nodiscard]] bool ImportFromRow(const std::wstring);

public:

	bool Loaded = false;

	std::vector<Runway> Runways;

	RunwayHandler(const std::wstring);

	Runway GetRandom(std::wstring);

	int FindAndSet(const std::wstring);

    std::wstring GetLastError();
};
