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

#include "POI.h"


POI::POI(std::wstring name, std::wstring description, std::wstring latitude, std::wstring longitude)
{
	Name = name;
	Description = description;

	double LatitudeD = std::stod(latitude);
	double LongitudeD = std::stod(longitude);

	LatitudeR = LatitudeD * (3.14159265358979323846 / 180);		// cache for distance calculations
	LongitudeR = LongitudeD * (3.14159265358979323846 / 180);	//
}