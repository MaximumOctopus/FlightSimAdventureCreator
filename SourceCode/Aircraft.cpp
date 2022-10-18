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

#include "Aircraft.h"
#include "Utility.h"


Aircraft::Aircraft()
{

}


Aircraft::Aircraft(const std::wstring name, int speed, int range, int runway_length, AircraftConstants::MSFSVersion availability, AircraftConstants::AircraftType type, bool airliner, bool military, bool seaplane)
{
	Name = name;
	CruiseSpeed = speed;
	Range = range;
	RunwayLength = runway_length;

	Availability = availability;

	Type = type;

	Airliner = airliner;
	Military = military;
	Seaplane = seaplane;
}


std::wstring Aircraft::Show()
{
	return std::format(L"{0} ({1}, {2} kts, {3} nm)", Name, Utility::GetAircraftType(Type), std::to_wstring(CruiseSpeed), std::to_wstring(Range));
}