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

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "Configuration.h"
#include "Constants.h"
#include "DateUtility.h"
#include "Defaults.h"
#include "Formatting.h"
#include "Locations.h"
#include "Ini.h"
#include "Utility.h"


Configuration* GConfiguration;


Configuration::Configuration()
{
	if (!LoadFavourites())
	{
	}

	if (!LoadSystem())
	{

    }
}

Configuration::~Configuration()
{
	if (ShouldSaveFavourites)
	{
        SaveFavourites();
	}

	SaveSystem();
}


bool Configuration::LoadConfiguration(const std::wstring file_name, AircraftLoadFilter& aircraftlf, AirportLoadFilter& airportlf, RouteFilter& rf)
{
	Ini* config = new Ini(file_name);

	if (config->Loaded)
	{
		int IntegerKey = 0;
		std::wstring StringKey = L"";

		// ============================================================================================
		// == load from aircraft section ==============================================================
		// ============================================================================================

		for (int t = 0; t < 8; t++)
		{
			IntegerKey = config->ReadInteger(L"Aircraft", L"Type" + std::to_wstring(t), 1);
			if (config->LastKeyExist)
			{
				aircraftlf.Types[t] = IntegerKey;
			}
		}

		IntegerKey = config->ReadInteger(L"Aircraft", L"MinSpeed", 1);
		if (config->LastKeyExist)
		{
			aircraftlf.MinSpeed = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Aircraft", L"MaxSpeed", DataDefaults::MaxSpeed);
		if (config->LastKeyExist)
		{
			aircraftlf.MaxSpeed = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Aircraft", L"Airliner", true);
		if (config->LastKeyExist)
		{
			aircraftlf.Airliner = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Aircraft", L"Military", true);
		if (config->LastKeyExist)
		{
			aircraftlf.Military = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Aircraft", L"Seaplane", true);
		if (config->LastKeyExist)
		{
			aircraftlf.Seaplane = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Aircraft", L"Version", 0);
		if (config->LastKeyExist)
		{
			switch (IntegerKey)
			{
			case 0:
				aircraftlf.Version = AircraftConstants::MSFSVersion::All;
				break;
			case 1:
				aircraftlf.Version = AircraftConstants::MSFSVersion::DeluxeAbove;
				break;
			case 2:
				aircraftlf.Version = AircraftConstants::MSFSVersion::PremiumAbove;
				break;
			}
		}

		// ============================================================================================
		// == load from airport section ===============================================================
		// ============================================================================================

		for (int t = 0; t < 7; t++)
		{
			IntegerKey = config->ReadInteger(L"Airport", L"Continent" + std::to_wstring(t), 1);
			if (config->LastKeyExist)
			{
				 airportlf.Continents[t] = IntegerKey;
			}
		}

		IntegerKey = config->ReadInteger(L"Airport", L"Elevation", false);
		if (config->LastKeyExist)
		{
			airportlf.MinimumElevation = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"FilterContinent", false);
		if (config->LastKeyExist)
		{
			airportlf.FilterContinent = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"FilterCountry", false);
		if (config->LastKeyExist)
		{
			airportlf.FilterCountry = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"FilterRegion", false);
		if (config->LastKeyExist)
		{
			airportlf.FilterRegion = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"FilterLatLong", false);
		if (config->LastKeyExist)
		{
			airportlf.FilterLatLong = IntegerKey;
		}

		StringKey = config->ReadString(L"Airport", L"Country", L"");
		if (config->LastKeyExist)
		{
			airportlf.Country = StringKey;
		}

		StringKey = config->ReadString(L"Airport", L"Region", L"");
		if (config->LastKeyExist)
		{
			airportlf.Region = StringKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"LargeAirports", 1);
		if (config->LastKeyExist)
		{
			airportlf.LargeAirports = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"MediumAirports", 1);
		if (config->LastKeyExist)
		{
			airportlf.MediumAirports = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"SmallAirports", 1);
		if (config->LastKeyExist)
		{
			airportlf.SmallAirports = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"Heliports", 1);
		if (config->LastKeyExist)
		{
			airportlf.Heliports = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"SeaplaneBases", 1);
		if (config->LastKeyExist)
		{
			airportlf.SeaplaneBases = IntegerKey;
		}

		StringKey = config->ReadString(L"Airport", L"LatitudeFrom", L"");
		if (config->LastKeyExist)
		{
			airportlf.LatitudeFrom = stod(StringKey);
		}

		StringKey = config->ReadString(L"Airport", L"LatitudeTo", L"");
		if (config->LastKeyExist)
		{
			airportlf.LatitudeTo = stod(StringKey);
		}

		StringKey = config->ReadString(L"Airport", L"LongitudeFrom", L"");
		if (config->LastKeyExist)
		{
			airportlf.LongitudeFrom = stod(StringKey);
		}

		StringKey = config->ReadString(L"Airport", L"LongitudeTo", L"");
		if (config->LastKeyExist)
		{
			airportlf.LongitudeTo = stod(StringKey);
		}

		IntegerKey = config->ReadInteger(L"Airport", L"LongitudeFilter", 1);
		if (config->LastKeyExist)
		{
			airportlf.LongitudeFilter = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"LatitudeFilter", 1);
		if (config->LastKeyExist)
		{
			airportlf.LatitudeFilter = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"UseTimeOfDay", 1);
		if (config->LastKeyExist)
		{
			airportlf.UseTimeOfDay = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"Day", 1);
		if (config->LastKeyExist)
		{
			airportlf.Day = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Airport", L"Night", 1);
		if (config->LastKeyExist)
		{
			airportlf.Night = IntegerKey;
		}

		// ============================================================================================
		// == load from route section =================================================================
		// ============================================================================================

		IntegerKey = config->ReadInteger(L"Route", L"Range", DataDefaults::Range);
		if (config->LastKeyExist)
		{
			rf.Range = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"Legs", 1);
		if (config->LastKeyExist)
		{
			rf.Legs = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"Count", 1);
		if (config->LastKeyExist)
		{
			rf.Count = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"UseDirection", 1);
		if (config->LastKeyExist)
		{
			rf.UseDirection = IntegerKey;
		}

		StringKey = config->ReadString(L"Route", L"Direction", L"");
		if (config->LastKeyExist)
		{
			rf.Direction = stod(StringKey);
		}

		StringKey = config->ReadString(L"Route", L"StartAirportICAO", L"");
		if (config->LastKeyExist)
		{
			rf.StartAirportICAO = StringKey;
		}

		StringKey = config->ReadString(L"Route", L"EndAirportICAO", L"");
		if (config->LastKeyExist)
		{
			rf.EndAirportICAO = StringKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"StartFromFavourite", 0);
		if (config->LastKeyExist)
		{
			rf.StartFromFavourite = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"EndAtFavourite", 0);
		if (config->LastKeyExist)
		{
			rf.EndAtFavourite = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"UseAircraftRange", 1);
		if (config->LastKeyExist)
		{
			rf.UseAircraftRange = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"AircraftRangeModifier", 1);
		if (config->LastKeyExist)
		{
			rf.AircraftRangeModifier = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"UseFlightTime", 1);
		if (config->LastKeyExist)
		{
			rf.UseFlightTime = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"FlightTime", 1);
		if (config->LastKeyExist)
		{
			rf.FlightTime = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"StartEndUseLegs", 1);
		if (config->LastKeyExist)
		{
			rf.StartEndUseLegs = IntegerKey;
        }

		IntegerKey = config->ReadInteger(L"Route", L"SimpleRouteCount", 1);
		if (config->LastKeyExist)
		{
			rf.SimpleRouteCount = IntegerKey;
		}

		IntegerKey = config->ReadInteger(L"Route", L"KeepTrying", 0);
		if (config->LastKeyExist)
		{
			rf.KeepTrying = IntegerKey;
		}

		return true;
	}

	return false; // to do
}


bool Configuration::SaveConfiguration(const std::wstring file_name, AircraftLoadFilter& aircraftlf, AirportLoadFilter& airportlf, RouteFilter& rf)
{
	std::wofstream ofile(file_name);

	if (ofile)
	{
		ofile << L"// ===============================================================================\n";
		ofile << L"// Config created: " + DateUtility::DateTime(kDisplayModeConsole) + L"\n";
		ofile << L"// ===============================================================================\n\n";

		ofile << L"[version]\n";
        ofile << L"Version=1\n";

		ofile << L"[aircraft]\n";
		ofile << L"Type0=" << aircraftlf.Types[0] << "\n";
		ofile << L"Type1=" << aircraftlf.Types[1] << "\n";
		ofile << L"Type2=" << aircraftlf.Types[2] << "\n";
		ofile << L"Type3=" << aircraftlf.Types[3] << "\n";
		ofile << L"Type4=" << aircraftlf.Types[4] << "\n";
		ofile << L"Type5=" << aircraftlf.Types[5] << "\n";
		ofile << L"Type6=" << aircraftlf.Types[6] << "\n";
		ofile << L"Type7=" << aircraftlf.Types[7] << "\n";
		ofile << L"MinSpeed=" << aircraftlf.MinSpeed << "\n";
		ofile << L"MaxSpeed=" << aircraftlf.MaxSpeed << "\n";
		ofile << L"Airliner=" << aircraftlf.Airliner << "\n";
		ofile << L"Military=" << aircraftlf.Military << "\n";
		ofile << L"Seaplane=" << aircraftlf.Seaplane << "\n";

		switch (aircraftlf.Version)
		{
		case AircraftConstants::MSFSVersion::All:
			ofile << L"Version=0\n";
			break;
		case AircraftConstants::MSFSVersion::DeluxeAbove:
			ofile << L"Version=1\n";
			break;
		case AircraftConstants::MSFSVersion::PremiumAbove:
			ofile << L"Version=2\n";
		}

		ofile << L"\n[airport]\n";
		ofile << L"Elevation=" << airportlf.MinimumElevation << "\n";
		ofile << L"Continent0=" << airportlf.Continents[0] << "\n";
		ofile << L"Continent1=" << airportlf.Continents[1] << "\n";
		ofile << L"Continent2=" << airportlf.Continents[2] << "\n";
		ofile << L"Continent3=" << airportlf.Continents[3] << "\n";
		ofile << L"Continent4=" << airportlf.Continents[4] << "\n";
		ofile << L"Continent5=" << airportlf.Continents[5] << "\n";
		ofile << L"Continent6=" << airportlf.Continents[6] << "\n";
		ofile << L"FilterContinent=" << airportlf.FilterContinent << "\n";
		ofile << L"FilterCountry=" << airportlf.FilterCountry << "\n";
		ofile << L"FilterRegion=" << airportlf.FilterRegion << "\n";
		ofile << L"FilterLatLong=" << airportlf.FilterLatLong << "\n";
		ofile << L"Country=" << airportlf.Country << "\n";
		ofile << L"Region=" << airportlf.Region << "\n";
		ofile << L"LargeAirports=" << airportlf.LargeAirports << "\n";
		ofile << L"MediumAirports=" << airportlf.MediumAirports << "\n";
		ofile << L"SmallAirports=" << airportlf.SmallAirports << "\n";
		ofile << L"Heliports=" << airportlf.Heliports << "\n";
		ofile << L"SeaplaneBases=" << airportlf.SeaplaneBases << "\n";
		ofile << L"LatitudeFrom=" << airportlf.LatitudeFrom << "\n";
		ofile << L"LatitudeTo=" << airportlf.LatitudeTo << "\n";
		ofile << L"LongitudeFrom=" << airportlf.LongitudeFrom << "\n";
		ofile << L"LongitudeTo=" << airportlf.LongitudeTo << "\n";
		ofile << L"LongitudeFilter=" << airportlf.LongitudeFilter << "\n";
		ofile << L"LatitudeFilter=" << airportlf.LatitudeFilter << "\n";
		ofile << L"UseTimeOfDay=" << airportlf.UseTimeOfDay << "\n";
		ofile << L"Day=" << airportlf.Day << "\n";
		ofile << L"Night=" << airportlf.Night << "\n";

		ofile << L"\n[route]\n";
		ofile << L"Range=" << rf.Range << "\n";
		ofile << L"Legs=" << rf.Legs << "\n";
		ofile << L"Count=" << rf.Count << "\n";
		ofile << L"UseDirection=" << rf.UseDirection << "\n";
		ofile << L"Direction=" << rf.Direction << "\n";
		ofile << L"StartAirportICAO=" << rf.StartAirportICAO << "\n";
		ofile << L"EndAirportICAO" << rf.EndAirportICAO << "\n";
		ofile << L"StartFromFavourite=" << rf.StartFromFavourite << "\n";
		ofile << L"EndAtFavourite=" << rf.EndAtFavourite << "\n";
		ofile << L"UseAircraftRange=" << rf.UseAircraftRange << "\n";
		ofile << L"AircraftRangeModifier=" << rf.AircraftRangeModifier << "\n";
		ofile << L"UseFlightTime=" << rf.UseFlightTime  << "\n";
		ofile << L"FlightTime=" << rf.FlightTime << "\n";
		ofile << L"StartEndUseLegs=" << rf.StartEndUseLegs << "\n";
		ofile << L"SimpleRouteCount=" << rf.SimpleRouteCount << "\n";

		ofile << L"KeepTrying=" << rf.KeepTrying << "\n";

		ofile << "\n";

		ofile.close();

		return true;
	}

	return false; // to do
}


bool Configuration::LoadSystem()
{
	Ini* config = new Ini(SystemConstants::ConfigFileName);

	if (config->Loaded)
	{
		int IntegerKey = 0;
		std::wstring StringKey = L"";

		IntegerKey = config->ReadInteger(L"System", L"ShowToolTips", 1);
		if (config->LastKeyExist)
		{
			System.ShowToolTips = IntegerKey;
		}

		return true;
	}

	return false;
}


bool Configuration::SaveSystem()
{
	std::wofstream ofile(SystemConstants::ConfigFileName);

	if (ofile)
	{
		ofile << L"// ===============================================================================\n";
		ofile << L"// Config created: " + DateUtility::DateTime(kDisplayModeConsole) + L"\n";
		ofile << L"// ===============================================================================\n\n";

		ofile << L"[System]\n";
		ofile << L"ShowToolTips=" << System.ShowToolTips << "\n";

		ofile << "\n";

		ofile.close();

		return true;
	}

	return false; // to do
}


bool Configuration::LoadFavourites()
{
	std::wifstream file(SystemConstants::FavouritesFileName);

	if (file)
	{
		std::wstring s = L"";

		while (std::getline(file, s))
		{
			if (s != L"")
			{
				if (s[0] == L'/')
				{
					// comment, do nothing
				}
				else
				{
					Favourites.push_back(s);
				}
			}
		}

		file.close();

		return true;
	}
	else
	{
		LastError = L"Couldn't locate \"" + SystemConstants::FavouritesFileName + L"\" :(\n";
	}

	return false;
}


bool Configuration::SaveFavourites()
{
	std::wofstream file(SystemConstants::FavouritesFileName);

	if (file)
	{
		file << L"//  list of your favourite airports, one ICAO airport code per line\n";
		file << L"//  if you edit this file then please keep a backup, future updates will overwrite this file!\n";
		file << L"//\n";

		for (int t = 0; t < Favourites.size(); t++)
		{
			file << Favourites[t] << "\n";
		}

		file.close();

		return true;
	}
	else
	{
		LastError = L"Couldn't locate \"" + SystemConstants::FavouritesFileName + L"\" :(\n";
	}

	return false;
}


std::wstring Configuration::GetRandomFavourite()
{
    if (Favourites.size() != 0)
	{
		return Favourites[rand() % Favourites.size()];
	}

    return L"";
}


std::wstring Configuration::GetLastError()
{
	return LastError;
}


void Configuration::FavouritesHaveChanged()
{
	ShouldSaveFavourites = true;
}
