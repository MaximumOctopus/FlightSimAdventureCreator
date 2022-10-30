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

#include <filesystem>
#include <iostream>
#include <ShlObj.h>  
#include <string>
#include <windows.h>

#include "ConfigurationConstants.h"
#include "Constants.h"
#include "Defaults.h"
#include "Locations.h"
#include "Utility.h"


namespace Utility
{
	// https://www.movable-type.co.uk/scripts/latlong.html
	// incoming parameters MUST be in radians
	double AngleBetween(double lat1, double long1, double lat2, double long2)
	{
		double x = std::cos(lat2) * std::sin(long2 - long1);
		double y = std::cos(lat1) * std::sin(lat2) - std::sin(lat1) * std::cos(lat2) * std::cos(long2 - long1);

		double beta = std::atan2(x, y) * (180.0 / 3.14159265358979323846); // radians to degrees

		if (beta < 0) beta += 360;

		return beta;
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

		output += std::to_wstring(std::abs(degree_lat)) + L"° " + std::to_wstring(std::abs(minutes_lat)) + L"' " + std::to_wstring(std::abs(seconds_lat)) + L"\", ";

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


	std::wstring GetContinentFromShortCode(const std::wstring code)
	{
		for (int t = 0; t < Location::ContinentCount; t++)
		{
			if (Location::ContinentShort[t] == code)
			{
				return Location::ContinentNames[t];
			}
		}

		return L"unknown";
	}


	int GetContinentFromShortCodeAsInt(const std::wstring continent)
	{
		for (int t = 0; t < Location::ContinentCount; t++)
		{
			if (Location::ContinentShort[t] == continent)
			{
				return t;
			}
		}

		return 0;       // error to do
    }


	std::wstring GetCountryFromShortCode(const std::wstring iso_code)
	{
		for (int t = 0; t < Location::ISOCountriesCount; t++)
		{
			if (Location::ISOCountriesOrdered[t][1] == iso_code)
			{
				return Location::ISOCountriesOrdered[t][0];
			}
		}

		return L"unknown";
	}


	int GetCountryFromShortCodeAsInt(const std::wstring iso_code)
	{
		for (int t = 0; t < Location::ISOCountriesCount; t++)
		{
			if (Location::ISOCountriesOrdered[t][1] == iso_code)
			{
				return t;
			}
		}

		return -1;
	}


	double GetDirectionFromBearing(const std::wstring input)
	{
		std::wstring bearing(input);
		std::transform(bearing.begin(), bearing.end(), bearing.begin(), ::toupper);

		for (int t = 0; t < 16; t++)
		{
			if (bearing == Constants::CompassBearings[t])
			{
				return Constants::CompassDegrees[t];
			}
		}

		return DataDefaults::Direction;
	}


	// allows for input of 500 (as nm) or 500k (kilometers)
	double GetRange(const std::wstring input)
	{
		bool ConvertFromK = false;
		std::wstring range = input;

		if (range.back() == L'K' || range.back() == L'k')
		{
			ConvertFromK = true;

			range = input.substr(0, input.length() - 1);
		}

		double Range = DataDefaults::Range;

		try
		{
			Range = stod(range);

			if (ConvertFromK)
			{
				// input in kilometers, convert to nm
				Range = Range / 1.852;
			}
		}
		catch (...)
		{		
		}

		return Range;
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
		case 7:
			return L"Balloon";
		case 8:
			return L"Seaplane";
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
		case AircraftConstants::AircraftType::Balloon:
			return L"Balloon";
		}

		return L"unknown!";
	}


	int GetAircraftTypeToConfigType(AircraftConstants::AircraftType type)
	{
		switch (type)
		{
		case AircraftConstants::AircraftType::Prop:
			return AircraftConstants::AircraftTypeProp;
		case AircraftConstants::AircraftType::Jet:
			return AircraftConstants::AircraftTypeJet;
		case AircraftConstants::AircraftType::Helicopter:
			return AircraftConstants::AircraftTypeHeli;
		case AircraftConstants::AircraftType::Glider:
			return AircraftConstants::AircraftTypeGlider;
		case AircraftConstants::AircraftType::TwinProp:
			return AircraftConstants::AircraftTypeTwinProp;
		case AircraftConstants::AircraftType::TurboProp:
			return AircraftConstants::AircraftTypeTurboProp;
		case AircraftConstants::AircraftType::TwinTurboProp:
			return AircraftConstants::AircraftTypeTwinTurboProp;
		case AircraftConstants::AircraftType::Balloon:
			return AircraftConstants::AircraftTypeBalloon;
		}

		return -1;
	}


	AircraftConstants::AircraftType GetAircraftTypeFromInt(int type)
	{
		switch (type)
		{
		case 0:
			return AircraftConstants::AircraftType::Prop;
		case 1:
			return AircraftConstants::AircraftType::Jet;
		case 2:
			return AircraftConstants::AircraftType::Helicopter;
		case 3:
			return AircraftConstants::AircraftType::Glider;
		case 4:
			return AircraftConstants::AircraftType::TwinProp;
		case 5:
			return AircraftConstants::AircraftType::TurboProp;
		case 6:
			return AircraftConstants::AircraftType::TwinTurboProp;
		case 7:
			return AircraftConstants::AircraftType::Balloon;
		}

		return AircraftConstants::AircraftType::None;
	}


	int GetAircraftTypeAsInt(AircraftConstants::AircraftType type)
	{
		switch (type)
		{
		case AircraftConstants::AircraftType::Prop:
			return 0;
		case AircraftConstants::AircraftType::Jet:
			return 1;
		case AircraftConstants::AircraftType::Helicopter:
			return 2;
		case AircraftConstants::AircraftType::Glider:
			return 3;
		case AircraftConstants::AircraftType::TwinProp:
			return 4;
		case AircraftConstants::AircraftType::TurboProp:
			return 5;
		case AircraftConstants::AircraftType::TwinTurboProp:
			return 6;
		case AircraftConstants::AircraftType::Balloon:
			return 7;
		}

		return -1;
    }


	std::wstring GetAirportType(AirportConstants::AirportType type)
	{
		switch (type)
		{
		case AirportConstants::AirportType::None:
			return L"none";
		case AirportConstants::AirportType::Small:
			return AirportConstants::SmallAirport;
		case AirportConstants::AirportType::Medium:
			return AirportConstants::MediumAirport;
		case AirportConstants::AirportType::Large:
			return AirportConstants::LargeAirport;
		case AirportConstants::AirportType::Heliport:
			return AirportConstants::Heliport;
		case AirportConstants::AirportType::SeaplaneBase:
			return AirportConstants::SeaplaneBase;
		}

		return L"!unknown!";
	}


	AirportConstants::AirportType GetAirportType(const std::wstring name)
	{
		if (name == AirportConstants::SmallAirport)
		{
			return AirportConstants::AirportType::Small;
		}
		else if (name == AirportConstants::MediumAirport)
		{
			return AirportConstants::AirportType::Medium;
		}
		else if (name == AirportConstants::LargeAirport)
		{
			return AirportConstants::AirportType::Large;
		}
		else if (name == AirportConstants::Heliport)
		{
			return AirportConstants::AirportType::Heliport;
		}
		else if (name == AirportConstants::SeaplaneBase)
		{
			return AirportConstants::AirportType::SeaplaneBase;
		}

		return AirportConstants::AirportType::None;
	}


	std::wstring GetAirportTypeDisplay(AirportConstants::AirportType type)
	{
		switch (type)
		{
		case AirportConstants::AirportType::None:
			return L"Unknown";
		case AirportConstants::AirportType::Small:
			return L"Small";
		case AirportConstants::AirportType::Medium:
			return L"Medium";
		case AirportConstants::AirportType::Large:
			return L"Large";
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


	std::wstring ExtractFileName(const std::wstring input)
	{
		auto i = input.rfind(L"\\");

		if (i != std::wstring::npos)
		{
			return input.substr(i + 1);
		}

		return input;
	}


	// takes a time (minutes), cruise speed, and aircraft type, and returns
	// a distance to be travelled in specified time 
	double AircraftTimeToDistance(int minutes, int speed, int legs, AircraftConstants::AircraftType type)
	{
		double time_reduced = 0;
		double time_cruise = 0;
		double time_reduced_speed_modifier = 0;

		switch (type)
		{
		case AircraftConstants::AircraftType::Prop:
		case AircraftConstants::AircraftType::TwinProp:
			time_reduced = (2 * legs * 6);
			time_reduced_speed_modifier = 40;
			break;
		case AircraftConstants::AircraftType::TwinTurboProp:
		case AircraftConstants::AircraftType::TurboProp:		
			time_reduced = (2 * legs * 6);	
			time_reduced_speed_modifier = 50;
			break;
		case AircraftConstants::AircraftType::Jet:
			time_reduced = (2 * legs * 5);
			time_reduced_speed_modifier = 40;
			break;
		case AircraftConstants::AircraftType::Helicopter:
		case AircraftConstants::AircraftType::Balloon:
			time_reduced = (2 * legs * 4);
			time_reduced_speed_modifier = 60;
			break;
		case AircraftConstants::AircraftType::Glider:
			time_reduced = (2 * legs * 6);
			time_reduced_speed_modifier = 60;
			break;
		}

		time_cruise = minutes - time_reduced;

		return ((time_reduced / 60) * ((time_reduced_speed_modifier / 100) * speed)) + ((time_cruise / 60) * speed);
	}


	double AircraftDistanceToTime(int distance, int speed, int legs, AircraftConstants::AircraftType type)
	{
		return 0;
	}


	double ReverseAngle(double angle)
	{
		angle += 180;

		if (angle > 359)
		{
			angle = angle - 360;
		}

		return angle;
	}
}
