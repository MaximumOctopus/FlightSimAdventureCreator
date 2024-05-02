//
// FlightSimAdventureCreator 1.0 (GUI Version)
//
// (c) Paul Alan Freshney 2022-2024
//
// paul@freshney.org
//
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
//
//

#include "DateUtility.h"
#include "Flight.h"


// create the object in simplfied mode where we don't need to find the airport objects
// and add them to the aircraft vector
Flight::Flight(const std::wstring fromICAO, const std::wstring toICAO, int distance)
{
	Simple = true;
	SimpleFromICAO = fromICAO;
	SimpleToICAO = toICAO;

    Distance = distance;
}


Flight::Flight(const std::wstring name, int distance)
{
	Name = name;
	Distance = distance;
}


std::wstring Flight::GetMSFSFileName()
{
	return Airports.front().Ident + L"_to_" + Airports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".pln";
}


std::wstring Flight::GetTextFileName()
{
	return Airports.front().Ident + L"_to_" + Airports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".txt";
}


std::wstring Flight::ToCSVRow()
{
	std::wstring output(L"");

	for (int t = 0; t < Airports.size(); t++)
	{
		output += Airports[t].Ident + L"," + Airports[t].IATA + L",\"" + Airports[t].Name + L"\"," + std::to_wstring(Airports[t].Elevation) + L"," + Airports[t].Longitude + L"," + Airports[t].Latitude + L",";

		output += Airports[t].Country + L"," + Airports[t].Continent + L"," + Airports[t].Region;

		if (t != Airports.size() - 1)
		{
			output += L",";
        }
	}

    return output;
}
