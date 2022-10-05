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

#include <filesystem>
#include <iostream>
#include <string>

#include "Constants.h"
#include "Utility.h"


namespace Utility
{
	bool FileExists(const std::wstring& file_name)
	{
		FILE* wstream = NULL;

		if (_wfopen_s(&wstream, file_name.c_str(), L"r") == 0)
		{
			if (wstream)
			{
				fclose(wstream);
			}

			return true;
		}
		else
		{
			return false;
		}
	}

	// https://www.igismap.com/formula-to-find-bearing-or-heading-angle-between-two-points-latitude-longitude
	// incoming parameters MUST be in radians
	double AngleBetween(double lat1, double long1, double lat2, double long2)
	{
		double x = cos(lat2) * sin(abs(long1 - long2));
		double y = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(abs(long1 - long2));
			
		double beta = atan2(x, y); // value in radians

		return beta * (180.0 / 3.14159265358979323846);
	}


	// converts x, y to d° m' s"
	std::wstring DegreesToDMS(double latitude, double longitude)
	{
		std::wstring output = L"";

		int degree_lon = (int)longitude;
		int minutes_lon = (int)(((double)longitude - (double)degree_lon) * 60.0);
		double seconds_lon = (double)(longitude - (double)degree_lon - (double)minutes_lon / 60.0) * 60.0 * 60.0;

		int degree_lat = (int)latitude;
		int minutes_lat = (int)(((double)latitude - (double)degree_lat) * 60.0);
		double seconds_lat = (double)(latitude - (double)degree_lat - (double)minutes_lat / 60.0) * 60.0 * 60.0;

		if (degree_lat >= 0)
		{
			output += L"N";
		}
		else
		{
			output += L"S";
		}

		output += std::to_wstring(abs(degree_lat)) + L"° " + std::to_wstring(abs(minutes_lat)) + L"' " + std::to_wstring(abs(seconds_lat)) + L"\", ";

		if (degree_lon >= 0)
		{
			output += L"E";
		}
		else
		{
			output += L"W";
		}

		output += std::to_wstring(abs(degree_lon)) + L"° " + std::to_wstring(abs(minutes_lon)) + L"' " + std::to_wstring(abs(seconds_lon)) + L"\"";

		return output;
	}


	std::wstring GetContinentFromShortCode(std::wstring code)
	{
		for (int t = 0; t < kContinentCount; t++)
		{
			if (ContinentShort[t] == code)
			{
				return ContinentNames[t];
			}
		}

		return L"unknown";
	}


	std::wstring GetCountryFromShortCode(std::wstring iso_code)
	{
		for (int t = 0; t < kISOCountries; t++)
		{
			if (ISOCountries[t][0] == iso_code)
			{
				return ISOCountries[t][1];
			}
		}

		return L"unknown";
	}


	std::wstring GetAircraftType(int type)
	{
		switch (type)
		{
		case 0:
			return L"Propeller";
		case 1:
			return L"Jet";
		case 2:
			return L"Helicopter";
		case 3:
			return L"Glider";
		case 4:
			return L"Twin propeller";
		case 5:
			return L"Twin prop";
		case 6:
			return L"Twin turbo prop";
		}

		return L"unknown!";
	}


	std::wstring GetAircraftType(AircraftConstants::AircraftType type)
	{
		switch (type)
		{
		case AircraftConstants::AircraftType::None:
			return L"None!";
		case AircraftConstants::AircraftType::Prop:
			return L"Propeller";
		case AircraftConstants::AircraftType::Jet:
			return L"Jet";
		case AircraftConstants::AircraftType::Helicopter:
			return L"Helicopter";
		case AircraftConstants::AircraftType::Glider:
			return L"Glider";
		case AircraftConstants::AircraftType::TwinProp:
			return L"Twin propeller";
		case AircraftConstants::AircraftType::TurboProp:
			return L"Turbo prop";
		case AircraftConstants::AircraftType::TwinTurboProp:
			return L"Twin turbo prop";
		}

		return L"unknown!";
	}


	std::wstring GetAirportType(AirportConstants::AirportType type)
	{
		switch (type)
		{
		case AirportConstants::AirportType::None:
			return L"none";
		case AirportConstants::AirportType::Small:
			return L"small_airport";
		case AirportConstants::AirportType::Medium:
			return L"medium_airport";
		case AirportConstants::AirportType::Large:
			return L"large_airport";
		case AirportConstants::AirportType::Heliport:
			return L"heliport";
		case AirportConstants::AirportType::SeaplaneBase:
			return L"seaplane_base";
		}

		return L"!unknown!";
	}

	std::wstring GetAirportTypeDisplay(AirportConstants::AirportType type)
	{
		switch (type)
		{
		case AirportConstants::AirportType::None:
			return L"none";
		case AirportConstants::AirportType::Small:
			return L"Small";
		case AirportConstants::AirportType::Medium:
			return L"Medium";
		case AirportConstants::AirportType::Large:
			return L"large";
		case AirportConstants::AirportType::Heliport:
			return L"Heliport";
		case AirportConstants::AirportType::SeaplaneBase:
			return L"Seaplane base";
		}

		return L"!unknown!";
	}


	std::wstring BoolToYesNo(bool input)
	{
		if (input)
		{
			return L"Yes";
		}

		return L"No";
	}


	std::wstring ExtractFileName(std::wstring input)
	{
		auto i = input.rfind(L"\\");

		if (i != std::wstring::npos)
		{
			return input.substr(i + 1);
		}

		return input;
	}
}