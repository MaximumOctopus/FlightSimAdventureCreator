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

#include "Runway.h"


Runway::Runway()
{

}


Runway::Runway(const std::wstring ident, const std::wstring name, const std::wstring type, int length)
{
	Ident = ident;
	Name = name;
	SurfaceType = type;
	Length = length;
}