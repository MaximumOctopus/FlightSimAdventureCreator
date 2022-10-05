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

#include <fcntl.h>
#include <format>
#include <io.h>
#include <iostream>
#include <string>

#include "AircraftHandler.h"
#include "AirportHandler.h"
#include "Configuration.h"
#include "Constants.h"
#include "FCASAirportData.h"
#include "GlobalObjects.h"
#include "Help.h"
#include "JobHandler.h"
#include "Utility.h"

#include "MSFSSystem.h"


extern Configuration* GConfiguration;
extern AircraftHandler* GAircraftHandler;
extern AirportHandler* GAirportHandler;
extern JobHandler* GJobHandler;


void GenerateAircraftAndLocation()
{
    if (GAircraftHandler->AircraftList.size() != 0 && GAirportHandler->Airports.size() != 0)
    {
        Aircraft aircraft = GAircraftHandler->GetRandomAircraft();
        Airport airport = GAirportHandler->GetAirport(kRandomAirport);

        // just generate a random aircraft and a start airport

        std::wcout << std::format(L"    {0} ({1}), {2} ({3})", airport.Name, airport.Ident, Utility::GetCountryFromShortCode(airport.Country), airport.Country) << L"\n\n";

        std::wcout << std::format(L"    {0} ({1} kts, {2} nm)", aircraft.Name, aircraft.CruiseSpeed, aircraft.Range) << L"\n\n";

        std::wcout << L"    " << GJobHandler->GetJob(aircraft.Type, aircraft.Airliner, aircraft.Military) << L"\n\n";
    }
    else
    {
        std::wcout << std::format(L"Error, needs >0 aircraft ({0}) and >0 airports ({1}) :(", GAircraftHandler->AircraftList.size(), GAirportHandler->Airports.size()) << L"\n";
    }
}


void RunHelperFunctions()
{
    if (GConfiguration->Helpers.FindNearest)
    {
        std::wstring airport = GConfiguration->Route.FindNearestICAO;

        if (airport == L"")
        {
            airport = GConfiguration->Route.StartAirportICAO;
        }

        GAirportHandler->FindNearest(airport, GConfiguration->Route.Range, true);
    }
}


int wmain(int argc, wchar_t* argv[])
{     
    if (_setmode(_fileno(stdout), _O_U16TEXT) == -1)
    {
        std::wcout << L"Error setting U16 console mode. No idea why.\n";
    }

    // ==========================================================================================

    srand((unsigned)time(NULL));

    // ==========================================================================================
    // ==========================================================================================

    if (argc == 2)
    {
        std::wstring parameter = argv[1];

        #ifdef _DEBUG
        if (parameter == L"/fcasexport")
        {
            FSACAirportData::Export();

            return 0;
        }
        #endif

        if (parameter == L"/help" || parameter == L"/?")
        {
            Help::Commands();

            return 0;
        }

        if (parameter == L"/cat")
        {
            Help::Cat();

            return 0;
        }
    }

    // ==========================================================================================
    // ==========================================================================================

    Help::ConsoleHeader();

    if (GlobalObjects::CreateGlobalObjects(argc, argv))
    {
        std::wcout << "\n";

        RunHelperFunctions();

        if (GConfiguration->Route.AtoB)
        {
            for (int t = 0; t < GConfiguration->Route.Count; t++)
            {
                if (GConfiguration->Route.Count != 1)
                {
                    std::wcout << L"\n== Route #" << t + 1 << " =======================================================\n\n";
                }

                Aircraft aircraft = GAircraftHandler->GetRandomAircraft();

                std::wcout << L"  " << aircraft.Show() << "\n";

                std::wcout << L"    " << GJobHandler->GetJob(aircraft.Type, aircraft.Airliner, aircraft.Military) << L"\n\n";

                double potential_route_length = GConfiguration->Route.Range * (double)GConfiguration->Route.Legs;
                double usable_aircraft_range = ((double)aircraft.Range * (GConfiguration->Route.AircraftRangePercent / 100));
                double range_per_leg = GConfiguration->Route.Range;

                std::wcout << std::format(L"   Potential route length : {0} nm", potential_route_length) << L"\n";
                std::wcout << std::format(L"   Usable aircraft range  : {0} nm (max {1} nm)", usable_aircraft_range, aircraft.Range) << L"\n\n";

                if (GConfiguration->Route.UseAircraftRange)
                {
                    range_per_leg = ((double)aircraft.Range * (GConfiguration->Route.AircraftRangePercent / 100)) / (double)GConfiguration->Route.Legs;
                }
                else
                {
                    if (range_per_leg > usable_aircraft_range)
                    {
                        std::wcout << L" User range (per leg) is greater than aircraft range, using aircraft range!\n";

                        range_per_leg = ((double)aircraft.Range * (GConfiguration->Route.AircraftRangePercent / 100)) / (double)GConfiguration->Route.Legs;
                    }
                    else if (potential_route_length > usable_aircraft_range && !GConfiguration->Aircraft.AllowExcessRange)
                    {
                        std::wcout << L" User range too large for aircraft and leg count, using aircraft range!\n";

                        range_per_leg = ((double)aircraft.Range * (GConfiguration->Route.AircraftRangePercent / 100)) / (double)GConfiguration->Route.Legs;
                    }

                    std::wcout << L"\n";
                }

                std::wcout << std::format(L"Max. Range (per leg): {0} nm; legs: {1}", range_per_leg, GConfiguration->Route.Legs) << L"\n\n";

                GAirportHandler->GetRoute(GConfiguration->Route.StartAirportICAO, range_per_leg, GConfiguration->Route.Direction, GConfiguration->Route.Legs, 
                    GConfiguration->Route.SimpleRouteCount,
                    GConfiguration->Airport.KeepTrying);     // to do add endairport
            }
        }
        else
        {
            GenerateAircraftAndLocation();
        }
    }
    else
    {
        std::wcout << L"\n  Data not available, exiting :( Try unzipping again, or download a new copy.\n\n";
    }

    GlobalObjects::FreeGlobalObjects();
}