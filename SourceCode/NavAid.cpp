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

#include "NavAid.h"


NavAid::NavAid(const std::wstring name, const std::wstring latitude, const std::wstring longitude)
{
	Name = name;

	double LatitudeD = std::stod(latitude);
	double LongitudeD = std::stod(longitude);

	LatitudeR = LatitudeD * (3.14159265358979323846 / 180);		// cache for distance calculations
	LongitudeR = LongitudeD * (3.14159265358979323846 / 180);	//
}