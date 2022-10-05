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

#include <format>
#include <iostream>

#include "Airport.h"
#include "Utility.h"


Airport::Airport()
{

}


Airport::Airport(std::wstring ident, AirportConstants::AirportType type, std::wstring name, int elevation, std::wstring latitude, std::wstring longitude, std::wstring country, std::wstring continent, std::wstring region, bool msfs_compatible)
{
	Ident = ident;
	Type = type;
	Name = name;

	Elevation = elevation;
	Latitude = latitude;
	Longitude = longitude;

	Country = country;
	Continent = continent;
	Region = region;

	LatitudeD = std::stod(latitude);
	LongitudeD = std::stod(longitude);

	LatitudeR = LatitudeD * (3.14159265358979323846 / 180);		// cache for distance calculations
	LongitudeR = LongitudeD * (3.14159265358979323846 / 180);	//

	MSFSCompatible = msfs_compatible;
}


// if runway is 26L then returns 26
std::wstring Airport::RunwayNumber()
{
	if (Runway != L"")
	{
		if (isalpha(Runway.back()))
		{
			return Runway.substr(0, Runway.length() - 1);
		}
	}

	return L"";
}


// if runway is 26L then returns LEFT
std::wstring Airport::RunwayDesignator()
{
	if (Runway != L"")
	{
		if (Runway.back() == L'L')
		{
			return L"LEFT";
		}
		else if (Runway.back() == L'R')
		{
			return L"RIGHT";
		}
		else if (Runway.back() == L'C')
		{
			return L"CENTER";
		}
	}

	return L"";
}


void Airport::Show()
{
	std::wcout << std::format(L"{0} ({1}), {2})", Name, Ident, Utility::GetAirportType(Type)) << L"\n";
	std::wcout << L"  " << std::format(L"{0} ({1}, {2})", Utility::GetCountryFromShortCode(Country), Country, Region) << L"\n";
	std::wcout << L"  " << std::format(L"{0} ({1}", Utility::GetContinentFromShortCode(Continent), Continent) << L"\n";
	std::wcout << L"  " << std::format(L"Elevation: {0} feet", Elevation) << L"\n";
	std::wcout << L"  " << std::format(L"{0}, {1}", Latitude, Longitude) << L"\n\n";
}