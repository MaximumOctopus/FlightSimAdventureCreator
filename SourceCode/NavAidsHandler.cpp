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

#include "NavAidsHandler.h"


NavAidsHandler::NavAidsHandler()
{
	Loaded = LoadNavAids(L"");

	if (!Loaded)
	{

	}
}


bool NavAidsHandler::LoadNavAids(const std::wstring file_name)
{
	return false;
}