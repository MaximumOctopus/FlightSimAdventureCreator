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

#include "Runway.h"


Runway::Runway()
{

}


Runway::Runway(std::wstring ident, std::wstring name, std::wstring type, int length)
{
	Ident = ident;
	Name = name;
	SurfaceType = type;
	Length = length;
}