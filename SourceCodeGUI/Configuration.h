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
#include <vector>

#include "AircraftHandler.h"
#include "AirportHandler.h"
#include "Defaults.h"
#include "RouteHandler.h"


struct SystemSettings
{
	bool ShowToolTips = true;
	int RoutesGenerated = 0;

    std::wstring HomeAirport = L"";
};


class Configuration
{
	bool ShouldSaveFavourites = false;
	std::wstring LastError = L"";

	bool LoadFavourites();
	bool SaveFavourites();

	[[nodiscard]] bool LoadSystem();
	bool SaveSystem();

public:

	SystemSettings System;

	std::vector<std::wstring> Favourites;

	Configuration();
	~Configuration();

	std::wstring GetLastError();

	[[nodiscard]] bool LoadConfiguration(const std::wstring, AircraftLoadFilter&, AirportLoadFilter&, RouteFilter&);
	[[nodiscard]] bool SaveConfiguration(const std::wstring, AircraftLoadFilter&, AirportLoadFilter&, RouteFilter&);

	[[nodiscard]] std::wstring GenerateConfigCode(AircraftLoadFilter&, AirportLoadFilter&, RouteFilter&);
	[[nodiscard]] std::wstring DecodeConfigCode(std::wstring, AircraftLoadFilter&, AirportLoadFilter&, RouteFilter&);

	std::wstring GetRandomFavourite();

	void FavouritesHaveChanged();
};