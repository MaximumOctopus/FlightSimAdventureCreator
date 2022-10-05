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

#include "Formatting.h"
#include "RouteHandler.h"


namespace RouteHandler
{
	void OutputMultiLegRoute(std::vector<Airport>& airports)
	{
		double distance = 0;

		std::wcout << std::format(L"    Starting airport: {0} ({1}), elevation {2} ft", airports[0].Ident, airports[0].Country, airports[0].Elevation) << L"\n";

		for (int i = 1; i < airports.size(); i++)
		{
			int d = static_cast<int>(airports[i].Distance);

			std::wcout << Formatting::AddLeadingSpace(std::to_wstring(d), 13) << std::format(L" nm -->  {0} ({1}), elevation {2} ft", airports[i].Ident, airports[i].Country, airports[i].Elevation) << L"\n";

			distance += airports[i].Distance;
		}

		std::wcout << L"\n    Total distance: " << distance << L" nm\n\n";
	}
}