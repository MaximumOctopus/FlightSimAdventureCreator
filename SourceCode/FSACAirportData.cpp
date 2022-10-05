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

#include "AirportHandler.h"
#include "FCASAirportData.h"


// this takes a vanilla airports.csv (get it from outairports.com/data) and another CSV that contains an msfs_compatible field and combines them
// (note that both files must be in the EXACT SAME FORMAT with the msfs_compatible field as the 26th (Z in Excel))
// once it's correctly tagged airports from airports.csv it saves the new file to fcas.csv
// it's not optimised, it's a bit rough, but it works!

namespace FSACAirportData
{
	void Export()
	{
		AirportHandler airporthandler(L"airports.csv");

		AirportHandler airporthandlermsfs(L"LetsFlyDB.csv");	// this will need tweaking before use, airport type is in the wrong position! and airport type values are different to airports.csv

		if (airporthandler.Loaded && airporthandlermsfs.Loaded)
		{
			int count = 0;

			for (int t = 0; t < airporthandlermsfs.Airports.size(); t++)
			{
				if (airporthandlermsfs.Airports[t].MSFSCompatible)
				{
					int index = airporthandler.GetIndexFromICAO(airporthandlermsfs.Airports[t].Ident);

					if (index != -1)
					{
						airporthandler.Airports[index].MSFSCompatible = true;
					}

					count++;
				}
			}

			if (count != 0)
			{
				std::wcout << std::format(L"\n  Found {0} MSFS compatible airports :)", count) << L"\n\n";

				if (airporthandler.Save(L"fcas.csv", true))
				{
					std::wcout << L"Saved successfully.\n\n";
				}
			}

			return;
		}

		std::wcout << L"Coun't load both files, exiting :(\n\n";
	}
}