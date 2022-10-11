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

#pragma once

// this takes a vanilla airports.csv (get it from outairports.com/data) and another CSV that contains an msfs_compatible field and combines them
// (note that both files must be in the EXACT SAME FORMAT with the msfs_compatible field as the 26th (Z in Excel))
// a 1 in this field indicates that the airport is valid in MSFS (only these will be transferred to the fsac.csv file)
// it then saves the new file to fsac.csv
// it's not optimised, it's a bit rough, but it works!

namespace FSACAirportData
{
	void ExportAirports();

	void ExportRunways();
}