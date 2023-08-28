//
// FlightSimAdventureCreator 1.0
//
// (c) Paul Alan Freshney 2022-2023
//
// paul@freshney.org
// 
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
// 
// 

#include <format>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "Airport.h"
#include "Utility.h"


Airport::Airport()
{

}


Airport::Airport(const std::wstring ident, AirportConstants::AirportType type, const std::wstring name, int elevation, const  std::wstring latitude, const std::wstring longitude, 
	const std::wstring country, const std::wstring continent, const  std::wstring region,
	const std::wstring iata,
	bool msfs_compatible)
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

	IATA = iata;

	LatitudeD = std::stod(latitude);
	LongitudeD = std::stod(longitude);

	LatitudeR = LatitudeD * (3.14159265358979323846 / 180);		// cache for distance calculations
	LongitudeR = LongitudeD * (3.14159265358979323846 / 180);	//

	MSFSCompatible = msfs_compatible;
}


std::wstring Airport::Angle1p()
{
	std::wostringstream sobj;

	sobj << std::fixed;
	sobj << std::setprecision(1);
	sobj << Angle;

	return sobj.str();
}


// if runway is 26L then returns 26
std::wstring Airport::RunwayNumber()
{
	if (Runway.Name != L"")
	{
		if (isalpha(Runway.Name.back()))
		{
			return Runway.Name.substr(0, Runway.Name.length() - 1);
		}
	}

	return L"";
}


// if runway is 26L then returns LEFT
std::wstring Airport::RunwayDesignator()
{
	if (Runway.Name != L"")
	{
		if (Runway.Name.back() == L'L')
		{
			return L"LEFT";
		}
		else if (Runway.Name.back() == L'R')
		{
			return L"RIGHT";
		}
		else if (Runway.Name.back() == L'C')
		{
			return L"CENTER";
		}
	}

	return L"";
}


void Airport::Show()
{
	std::wcout << std::format(L"{0} ({1}), {2}", Name, Ident, Utility::GetAirportType(Type)) << L"\n";
	std::wcout << L"  " << std::format(L"{0} ({1}, {2})", Utility::GetCountryFromShortCode(Country), Country, Region) << L"\n";
	std::wcout << L"  " << std::format(L"{0} ({1})", Utility::GetContinentFromShortCode(Continent), Continent) << L"\n";
	std::wcout << L"  " << std::format(L"Elevation: {0} feet", Elevation) << L"\n";
	std::wcout << L"  " << std::format(L"Long/Lat : {0}, {1}", Latitude, Longitude) << L"\n\n";
}