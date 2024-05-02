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

#include <iostream>
#include <format>
#include <fstream>
#include <string>

#include "Formatting.h"
#include "TextItinerary.h"
#include "Utility.h"


namespace TextItinerary
{
	bool Export(std::vector<Airport>& airports, const std::wstring file_name)
	{
        std::ofstream ofile(file_name);

        if (ofile)
        {
            std::wcout << L"Saving Text Flight Plan: " << file_name << L"\n\n";

            ofile << Formatting::to_utf8(L"===============================================================================\n");
            ofile << Formatting::to_utf8(L"===============================================================================\n");
            ofile << Formatting::to_utf8(std::format(L"  {0} to {1} ({2:.1f} nm)\n", airports[0].Ident, airports.back().Ident, airports[0].Distance));

            for (int t = 0; t < airports.size(); t++)
            {
                ofile << Formatting::to_utf8(L"  --------------------------------------------------------------------------- \n");
                
                if (t == 0)
                {
                    ofile << Formatting::to_utf8(L"  Departure\n\n");
                }
                else if (t == airports.size() - 1)
                {
                    ofile << Formatting::to_utf8(L"  Arrival\n\n");
                }
                else
                {
                    ofile << Formatting::to_utf8(L"  Leg " + std::to_wstring(t) + L"\n\n");
                }                

                ofile << Formatting::to_utf8(L"    " + airports[t].Ident + L"  " + airports[t].Name + L" (elev.: " + std::to_wstring(airports[t].Elevation) + L" ft)\n");
                ofile << Formatting::to_utf8(L"    Location : " + Utility::GetContinentFromShortCode(airports[t].Continent) + L", " + Utility::GetCountryFromShortCode(airports[t].Country) + L" (" + airports[t].Region + L")\n");

                if (t != 0)
                {
                    ofile << Formatting::to_utf8(std::format(L"    Distance : {0:.1f} nm\n", airports[t].Distance));
                }
                else
                {
                    ofile << Formatting::to_utf8(L"\n");
                }
                
                ofile << Formatting::to_utf8(L"    Lat/Long : " + airports[t].Latitude + L", " + airports[t].Longitude + L"\n");
                ofile << Formatting::to_utf8(L"    Runway   : " + airports[t].Runway.Name + L", " + std::to_wstring(airports[t].Runway.Length) + L" ft., " + airports[t].Runway.Surface + L"\n\n");
            }

            ofile << Formatting::to_utf8(L"\n===============================================================================\n");
            ofile << Formatting::to_utf8(L"===============================================================================\n");
            ofile << Formatting::to_utf8(L" created with FSAC https://github.com/MaximumOctopus/FlightSimAdventureCreator\n\n");

            return true;
        }
        else
        {
            // error
        }

        return false;
	}
}