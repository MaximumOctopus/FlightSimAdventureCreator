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

#include "DateUtility.h"
#include "Route.h"


Route::Route(std::wstring name, int distance)
{
	Name = name;
	Distance = distance;
}


std::wstring Route::GetMSFSFileName()
{
	return Airports.front().Ident + L"_to_" + Airports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".pln";
}


std::wstring Route::GetTextFileName()
{
	return Airports.front().Ident + L"_to_" + Airports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".txt";
}
