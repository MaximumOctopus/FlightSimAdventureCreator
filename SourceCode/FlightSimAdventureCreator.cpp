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
#include "MSFSSystem.h"
#include "Utility.h"
#include "VersionCheck.h"


extern Configuration* GConfiguration;
extern AircraftHandler* GAircraftHandler;
extern AirportHandler* GAirportHandler;
extern JobHandler* GJobHandler;


bool RunHelperFunctions()
{
    if (GConfiguration->Helpers.FindNearest)
    {
        std::wstring airport = GConfiguration->Route.FindNearestICAO;

        if (airport == L"")
        {
            airport = GConfiguration->Route.StartAirportICAO;
        }

        GAirportHandler->FindNearest(airport, GConfiguration->Route.Range, true);

        return true;
    }

    return false;
}


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
        std::wcout << std::format(L"Error, needs >0 aircraft ({0}) and >0 airports ({1}) :(\n", GAircraftHandler->AircraftList.size(), GAirportHandler->Airports.size());
    }
}


// this is a bit messy and needs refactoring to do
void GenerateUserRoutes(int route)
{
    if (GConfiguration->Route.Count != 1)
    {
        std::wcout << L"\n == Route #" << route + 1 << " =======================================================\n\n";
    }

    if (GConfiguration->Route.StartAirportICAO != L"" && GConfiguration->Route.EndAirportICAO != L"")
    {
        double d = GAirportHandler->DistanceBetweenTwoAirports(GConfiguration->Route.StartAirportICAO, GConfiguration->Route.EndAirportICAO);

        if (GConfiguration->Route.Legs != 1 && GConfiguration->Route.Range != Defaults::DefaultRange)
        {
            std::wcout << L"  Setting start and end aiports is not compatible with setting legs and range (can't have both!). Using range.\n\n";
        }

        if (GConfiguration->Route.Range != Defaults::DefaultRange)
        {
            GConfiguration->Route.Legs = (d / GConfiguration->Route.Range) + 1;
        }
        else
        {
            GConfiguration->Route.Range = d / GConfiguration->Route.Legs;
        }

        std::wcout << std::format(L"  Set range/legs based on distance {0:.1f} from {1} to {2}. Range {3} nm; Legs {4}.\n\n", d, GConfiguration->Route.StartAirportICAO, GConfiguration->Route.EndAirportICAO, GConfiguration->Route.Range, GConfiguration->Route.Legs);
    }

    Aircraft aircraft = GAircraftHandler->GetRandomAircraft();

    std::wcout << L"  " << aircraft.Show() << "\n";
    std::wcout << L"    " << GJobHandler->GetJob(aircraft.Type, aircraft.Airliner, aircraft.Military) << L"\n\n";

    if (GConfiguration->Route.RequestedFlightTime != 0)
    {
        if (GConfiguration->SetRangeFromTime(aircraft.CruiseSpeed, aircraft.Type))
        {
            std::wcout << std::format(L"  Set range to {0} nm, based on {1} min flight time.\n", GConfiguration->Route.Range, GConfiguration->Route.RequestedFlightTime);
        }
    }

    double potential_route_length = GConfiguration->Route.Range * (double)GConfiguration->Route.Legs;
    double usable_aircraft_range = ((double)aircraft.Range * (GConfiguration->Route.AircraftRangePercent / 100));
    double range_per_leg = GConfiguration->Route.Range;

    std::wcout << std::format(L"   Potential route length : {0:.1f} nm", potential_route_length) << L"\n";
    std::wcout << std::format(L"   Usable aircraft range  : {0:.1f} nm ({1}% of max. {2} nm)", usable_aircraft_range, GConfiguration->Route.AircraftRangePercent, aircraft.Range) << L"\n\n";

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

    std::wcout << std::format(L"  Max. range (per leg): {0:.1f} nm; legs: {1}", range_per_leg, GConfiguration->Route.Legs) << L"\n\n";

    GAirportHandler->GetRoute(GConfiguration->Route.StartAirportICAO, GConfiguration->Route.EndAirportICAO, range_per_leg, GConfiguration->Route.Direction, GConfiguration->Route.Legs,
        GConfiguration->Route.SimpleRouteCount,
        GConfiguration->Airport.KeepTrying);   
}


int SpecialOptions(std::wstring first_argument)
{
    std::wstring parameter = first_argument;

    #ifdef _DEBUG
    if (parameter == kFSACXAirports)
    {
        FSACAirportData::ExportAirports();

        return 0;
    }
    if (parameter == kFSACXRunways)
    {
        FSACAirportData::ExportRunways();

        return 0;
    }
    #endif

    if (parameter == kGetVersion)
    {
        VersionCheck::IsNewVersion();

        return 0;
    }
    else if (parameter == kCustomAircraftFile)
    {
        if (!MSFSSystem::CreateAircraftList(true))
        {
            std::wcout << L" Unable to create \"custom_aircraft.txt\" from community folder.\n";
        }

        return 0;
    }
    else if (parameter == kHelp || parameter == kHelpLazy)
    {
        Help::Commands();

        return 0;
    }
    else if (parameter == kCats)
    {
        Help::Cat();

        return 0;
    }

    return -1;
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
        if (SpecialOptions(argv[1]) == 0)
        {
            return 0;
        }
    }

    // ==========================================================================================
    // ==========================================================================================

    Help::ConsoleHeader();

    if (GlobalObjects::CreateGlobalObjects(argc, argv))
    {
        std::wcout << "\n";

        bool user_just_wanted_analysis = RunHelperFunctions();

        if (!user_just_wanted_analysis)
        {
            if (GConfiguration->Route.AtoB)
            {
                for (int t = 0; t < GConfiguration->Route.Count; t++)
                {
                    GenerateUserRoutes(t);
                }
            }
            else
            {
                GenerateAircraftAndLocation();
            }
        }
    }
    else
    {
        std::wcout << L"\n  Data not available, exiting :( Try unzipping again, or download a new copy.\n\n";
    }

    GlobalObjects::FreeGlobalObjects();
}