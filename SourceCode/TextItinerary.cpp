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

#include <iostream>
#include <fstream>
#include <string>

#include "Formatting.h"
#include "TextItinerary.h"


namespace TextItinerary
{
	bool Export(std::vector<Airport>& airports, std::wstring file_name)
	{
        std::ofstream ofile(file_name);

        if (ofile)
        {
            std::wcout << L"Saving Text Flight Plan: " << file_name << L"\n\n";

            for (int t = 0; t < airports.size(); t++)
            {
                ofile << Formatting::to_utf8(L"===============================================================================\n");
                ofile << Formatting::to_utf8(L"   " + std::to_wstring(t + 1) + L"\n\n");

                ofile << Formatting::to_utf8(L"    " + airports[t].Ident + L"  " + airports[t].Name + L" (" + std::to_wstring(airports[t].Elevation) + L")\n");
                ofile << Formatting::to_utf8(L"    Location: " + airports[t].Continent + L", " + airports[t].Country + L", " + airports[t].Region + L"\n");
                ofile << Formatting::to_utf8(L"    Lat/Long: " + airports[t].Latitude + L", " + airports[t].Longitude + L"\n\n");
            }

            return true;
        }
        else
        {
            // error
        }

        return false;
	}
}