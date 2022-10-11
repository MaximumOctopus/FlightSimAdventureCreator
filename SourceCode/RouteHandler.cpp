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

		std::wcout << std::format(L"    Starting airport: {0} ({1}), @ {2:5.1f}° (elevation {3} ft)\n", airports[0].Ident, airports[0].Country, airports[1].Angle, airports[0].Elevation);

		for (int i = 1; i < airports.size(); i++)
		{
			if (i != airports.size() - 1)
			{
				std::wcout << std::format(L"{0:13.1f} nm -->  {1} ({2}), @ {3:5.1f}° (elevation {4} ft)\n", airports[i].Distance, airports[i].Ident, airports[i].Country, airports[i + 1].Angle, airports[i].Elevation);
			}
			else
			{
				std::wcout << std::format(L"{0:13.1f} nm -->  {1} ({2}),          (elevation {3} ft)\n", airports[i].Distance, airports[i].Ident, airports[i].Country, airports[i].Elevation);
			}

			distance += airports[i].Distance;
		}

		std::wcout << std::format(L"\n    Total distance: {0:.1f} nm\n\n", distance);
	}
}