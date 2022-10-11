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
#include "Constants.h"
#include "FCASAirportData.h"
#include "RunwayHandler.h"


namespace FSACAirportData
{
	// this takes a vanilla airports.csv (get it from outairports.com/data) and another CSV that contains an msfs_compatible field and combines them
	// (note that both files must be in the EXACT SAME FORMAT with the msfs_compatible field as the 26th (Z in Excel))
	// once it's correctly tagged airports from airports.csv it saves the new file to fcas.csv
	// it's not optimised, it's a bit rough, but it works!
	void ExportAirports()
	{
		std::wcout << L"\n";

		AirportHandler airporthandler(SystemConstants::OurAirportsFileName);

		AirportHandler airporthandlermsfs(SystemConstants::MSFSCompatSourceFileName);	// this will need tweaking before use, airport type is in the wrong position! and airport type values are different to airports.csv

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

						count++;
					}
				}
			}

			if (count != 0)
			{
				std::wcout << std::format(L"\n  Found {0} MSFS compatible airports :)", count) << L"\n\n";

				if (airporthandler.Save(SystemConstants::AirportsFileName, true))
				{
					std::wcout << L"  Saved successfully.\n\n";
				}
			}

			return;
		}

		std::wcout << L"Couldn't load both files, exiting :(\n\n";
	}


	// this takes a list of airports and removes runways belonging to airports not in the list
	// outputs a new runways file containing only runways belonging to the airports we have in the master list
	// it's rough, but it works!
	void ExportRunways()
	{
		std::wcout << L"\n";

		AirportHandler airporthandler(SystemConstants::AirportsFileName);

		RunwayHandler runwayhandler(SystemConstants::RunwaysFileName);

		if (airporthandler.Loaded && runwayhandler.Loaded)
		{
			int count = 0;
			int runways_found = 0;

			for (int t = 0; t < airporthandler.Airports.size(); t++)
			{
				int rwf = runwayhandler.FindAndSet(airporthandler.Airports[t].Ident);

				if (rwf != 0)
				{
					count++;

					runways_found += rwf;
				}
			}

			if (count != 0)
			{
				std::wcout << std::format(L"\n  Found {0} airports with {1} runways :)", count, runways_found) << L"\n\n";

				if (runwayhandler.Save(L"__" + SystemConstants::RunwaysFileName, true))
				{
					std::wcout << L"  Saved successfully.\n\n";
				}
			}

			return;
		}

		std::wcout << std::format(L"Couldn't load data files (\"{0}\" and \"{1}\"), exiting :(\n\n", SystemConstants::AirportsFileName, SystemConstants::RunwaysFileName);
	}
}