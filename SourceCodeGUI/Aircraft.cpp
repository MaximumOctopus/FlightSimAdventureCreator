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
    TypeAsInt = Utility::GetAircraftTypeAsInt(type);

	Airliner = airliner;
	Military = military;
	Seaplane = seaplane;
}


std::wstring Aircraft::ShowStats()
{
	return Utility::GetAircraftType(Type) + L", " + std::to_wstring(CruiseSpeed) + L" kts, " + std::to_wstring(Range) + L" nm";
}