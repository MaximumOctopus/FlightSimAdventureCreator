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

// https://developer.x-plane.com/article/flightplan-files-v11-fms-file-format/
// https://xp-soaring.github.io/tasks/x-plane_fms_format.html

#include <fstream>
#include <iostream>
#include <string>

#include "Formatting.h"
#include "XPlaneFlightPlan.h"


namespace XPlaneFlightPlan
{
	// exports a v11 xplane flight plan file
	bool Export(std::vector<Airport>& airports, const std::wstring file_name)
	{
		std::ofstream ofile(file_name);

		if (ofile)
		{
			std::wcout << L"Saving XPlane v11 Flight Plan: " << file_name << L"\n\n";

			ofile << Formatting::to_utf8(L"I\n");
			ofile << Formatting::to_utf8(L"1100 Version\n");
			ofile << Formatting::to_utf8(L"CYCLE 2210\n");		// this is just YYMM

			ofile << Formatting::to_utf8(L"ADEP " + airports[0].Ident + L"\n");
			ofile << Formatting::to_utf8(L"DEPRWY " + airports[0].Runway.Name + L"\n");

			ofile << Formatting::to_utf8(L"ADES " + airports.back().Ident + L"\n");
			ofile << Formatting::to_utf8(L"DESRWY " + airports.back().Runway.Name + L"\n");

			ofile << Formatting::to_utf8(L"NUMENR " + std::to_wstring(airports.size()) + L"\n");

			ofile << Formatting::to_utf8(L"1 " + airports[0].Ident + L"ADEP 0.000000 " + airports[0].Latitude + L" " + airports[0].Longitude + L"\n");

			if (airports.size() > 2)
			{
				for (int t = 1; t < airports.size() - 1; t++)
				{
					ofile << Formatting::to_utf8(L"1 " + airports[t].Ident + L"DRCT 0.000000 " + airports[t].Latitude + L" " + airports[t].Longitude + L"\n");
				}
			}

			ofile << Formatting::to_utf8(L"1 " + airports.back().Ident + L"ADES 0.000000 " + airports.back().Latitude + L" " + airports.back().Longitude + L"\n");

			return true;
		}

		return false;
	}
}