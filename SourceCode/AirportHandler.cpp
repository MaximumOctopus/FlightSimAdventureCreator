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

#include <algorithm>
#include <format>
#include <fstream>
#include <iostream>

#include "Airport.h"
#include "AirportHandler.h"
#include "DateUtility.h"
#include "Formatting.h"
#include "MSFSFlightPlan.h"
#include "RouteHandler.h"
#include "RunwayHandler.h"
#include "Utility.h"


AirportHandler* GAirportHandler;
extern RunwayHandler* GRunwayHandler;


AirportHandler::AirportHandler(std::wstring file_name)
{
    ExportMSFSPlan = false;

    Filter.Country = L"";
    Filter.Continent = L"";
    Filter.MinimumElevation = 0;

    Filter.LargeAirports = true;
    Filter.MediumAirports = true;
    Filter.SmallAirports = true;
    Filter.Heliports = true;

    Airports.reserve(30000);

    Loaded = LoadAirports(file_name);

    if (!Loaded)
    {
        std::wcout << std::format(L" Airport data file not found \"{0}\"", file_name) << L"\n";
    }
}


AirportHandler::AirportHandler(bool silent, bool export_plan, AirportData airport_filter_data)
{
    Silent = silent;

    ExportMSFSPlan = export_plan;

    Filter.Country = airport_filter_data.Country;
    Filter.Continent = airport_filter_data.Continent;
    Filter.Region = airport_filter_data.Region;

    Filter.MinimumElevation = airport_filter_data.Elevation;

    Filter.LargeAirports = airport_filter_data.LargeAirports;
    Filter.MediumAirports = airport_filter_data.MediumAirports;
    Filter.SmallAirports = airport_filter_data.SmallAirports;
    Filter.Heliports = airport_filter_data.Heliports;

    Airports.reserve(30000);

    Loaded = LoadAirports(L"fcas.csv");

    if (!Loaded)
    {
        std::wcout << L" Airport data file not found \"fcas.csv\".\n";
    }
    else
    {
        if (airport_filter_data.ListAirports)
        {
            ListAirports();
        }
    }
}


// if airport_index != -1 then returns that object
// else a random airport will be selected
Airport AirportHandler::GetAirport(int airport_index)
{
    if (airport_index != kRandomAirport)
    {
        return Airports[airport_index];
    }

    if (Airports.size() != 0)
    {
        int a = rand() % Airports.size();

        return Airports[a];
    }

    return Airport();
}


// https://www.geeksforgeeks.org/program-distance-two-points-earth/
// long and lat must already be converted to radians
double AirportHandler::DistanceBetween(double lat1, double long1, double lat2, double long2)
{
    double deltalong = long2 - long1;
    double deltalat = lat2 - lat1;

    double distance = pow(sin(deltalat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(deltalong / 2), 2);

    distance = 2 * asin(sqrt(distance));

    // Radius of Earth in nautical miles
    double R = 3340.1;

    // Calculate the result
    return distance * R;
}


// calculates the distance from each airport to the origin
void AirportHandler::CalculateDistances(double range, double origin_lat, double origin_long)
{
    double range_min = range * 0.9;
    double range_max = range * 1.1;

    RouteCache.clear();

    for (int t = 0; t < Airports.size(); t++)
    {
        Airports[t].Distance = DistanceBetween(origin_lat, origin_long, Airports[t].LatitudeR, Airports[t].LongitudeR);

        if (Airports[t].Distance < range_max && Airports[t].Distance > range_min && Airports[t].Distance != 0)
        {
            RouteCache.push_back(Airports[t]);
        }
    }
}


// this version ensures the selected airports are within the specified range and direction
void AirportHandler::CalculateDistances(double range, double direction, int direction_modifier, double origin_lat, double origin_long)
{
    double range_min = range * 0.9;
    double range_max = range * 1.1;

    double angle_min = direction - direction_modifier;
    double angle_max = direction + direction_modifier;

    if (angle_min < 0) angle_min += 360;
    if (angle_max > 359) angle_min -= 360;

    RouteCache.clear();

    for (int t = 0; t < Airports.size(); t++)
    {
        bool is_within_angle = false;

        Airports[t].Distance = DistanceBetween(origin_lat, origin_long, Airports[t].LatitudeR, Airports[t].LongitudeR);

        double angle = Utility::AngleBetween(origin_lat, origin_long, Airports[t].LatitudeR, Airports[t].LongitudeR);

        if (angle_max >= angle_min)
        {
            if (angle > angle_min && angle < angle_max)
            {
                is_within_angle = true;
            }
        }
        else
        {   
            if (angle_max > angle || angle_min < angle)
            {
                is_within_angle = true;
            }
        }

        if (Airports[t].Distance < range_max && Airports[t].Distance > range_min && is_within_angle && Airports[t].Distance != 0)
        {
            #ifdef _DEBUG
            std::wcout << L"Rmin " << range_min << L", Rmax " << range_max << L" Amin " << angle_min << L", Amax " << angle_max << L", A " << angle << L", D " << Airports[t].Distance << L"\n";
            #endif          

            Airports[t].Angle = angle;

            RouteCache.push_back(Airports[t]);
        }
    }
}


// calculates the distance from each airport to the origin
void AirportHandler::CalculateDistancesNoMinimum(double range, double origin_lat, double origin_long)
{
    RouteCache.clear();

    for (int t = 0; t < Airports.size(); t++)
    {
        Airports[t].Distance = DistanceBetween(origin_lat, origin_long, Airports[t].LatitudeR, Airports[t].LongitudeR);

        if (Airports[t].Distance < range && Airports[t].Distance != 0)
        {
            RouteCache.push_back(Airports[t]);
        }
    }
}


void AirportHandler::GetRoute(std::wstring start_icao, double range, double direction, int legs, int simple_count, bool keep_trying)
{
    RouteCache.clear();

    if (legs == 1)
    {
        if (simple_count > 0)
        {
            Generation.ShortRouteCount = simple_count;
        }

        SimpleRoute(start_icao, range, direction, keep_trying);
    }
    else
    {
        MultiLegRoute(start_icao, range, direction, legs, keep_trying);
    }
}


// generates a route from one airport to another, A->B
bool AirportHandler::SimpleRoute(std::wstring start_icao, double range, double direction, bool keep_trying)
{
    int MaximumAttempts = 5;
    int Attempt = 0;
    int StartAirport = kRandomAirport;
    int Retries = 0;
    int DirectionMarginOfError = Defaults::DefaultDirectionMargin;

    if (start_icao != L"")
    {
        StartAirport = GetIndexFromICAO(start_icao);
    }

    while (Attempt < MaximumAttempts)
    {
        Airport origin = GetAirport(StartAirport);

        if (origin.Type != AirportConstants::AirportType::None)
        {
            if (direction != -1)
            {
                CalculateDistances(range, direction, DirectionMarginOfError, origin.LatitudeR, origin.LongitudeR);
            }
            else
            {
                CalculateDistances(range, origin.LatitudeR, origin.LongitudeR);
            }

            if (RouteCache.size() != 0)
            {
                Runway runway = GRunwayHandler->GetRandom(origin.Ident);
                
                origin.Runway = runway.Name;
                origin.RunwayLength = runway.Length;

                int OutputCount = Generation.ShortRouteCount;

                if (RouteCache.size() < Generation.ShortRouteCount)
                {
                    OutputCount = RouteCache.size();
                }

                for (int t = 0; t < OutputCount; t++)
                {
                    Runway runway = GRunwayHandler->GetRandom(RouteCache[t].Ident);

                    RouteCache[t].Runway = runway.Name;
                    RouteCache[t].RunwayLength = runway.Length;

                    if (direction != -1)
                    {
                        std::wcout << L"   " << origin.Ident << L" --> " << RouteCache[t].Ident << L", " << RouteCache[t].Country << L" (" << RouteCache[t].Distance << L" nm), @ " << RouteCache[t].Angle << L"°\n";
                    }
                    else
                    {
                        std::wcout << L"   " << origin.Ident << L" --> " << RouteCache[t].Ident << L", " << RouteCache[t].Country << L" (" << RouteCache[t].Distance << L" nm)\n";
                    }

                    if (ExportMSFSPlan)
                    {
                        std::vector<Airport> ForExport;

                        ForExport.push_back(origin);
                        ForExport.push_back(RouteCache[t]);

                        if (!MSFSFlightPlan::Export(ForExport, L"plans\\" + origin.Ident + L"_to_" + RouteCache[t].Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".pln"))
                        {
                            std::wcout << L"\n\nerror saving plan file :( \n";
                        }
                    }
                }

                return true;
            }
        }

        Attempt++;

        if (Attempt == MaximumAttempts && keep_trying)
        {
            Retries++;

            // if someone is stupid enough to have a range of 1 nm and "keeptrying" then we have to shut it down eventually...
            // 21 retries from 1 nautical mile gives us just over 100 nm - that should be enough...
            if (Retries < 22)
            {
                Attempt = 0;

                range *= 1.25;

                DirectionMarginOfError += 5;

                std::wcout << L"  No airports in range, using 1.25x (" << range << L") and retrying (" << Retries << L")...\n";
            }
        }
    }
 
    std::wcout << std::format(L"Sorry, no routes could be generated with a range of {0} nm after {1} attempts :(", range, MaximumAttempts) << L"\n";
          
    return false;
}


bool AirportHandler::MultiLegRoute(std::wstring start_icao, double range, double direction, int legs, bool keep_trying)
{
    int MaximumAttempts = 5;
    int Attempt = 0;
    int StartAirport = kRandomAirport;
    int Retries = 0;
    int DirectionMarginOfError = Defaults::DefaultDirectionMargin;

    if (start_icao != L"")
    {
        StartAirport = GetIndexFromICAO(start_icao);
    }

    while (Attempt < MaximumAttempts)
    {
        MultiLegAirports.clear();

        Airport origin = GetAirport(StartAirport);

        double FromLatitude = origin.LatitudeR;
        double FromLongitude = origin.LongitudeR;

        MultiLegAirports.push_back(origin);

        for (int leg = 0; leg < legs; leg++)
        {
            if (origin.Type != AirportConstants::AirportType::None)
            {
                if (direction != -1)
                {
                    CalculateDistances(range, direction, DirectionMarginOfError, FromLatitude, FromLongitude);
                }
                else
                {
                    CalculateDistances(range, FromLatitude, FromLongitude);
                }

                if (RouteCache.size() != 0)
                {
                    int random_airport = rand() % RouteCache.size();

                    MultiLegAirports.push_back(RouteCache[random_airport]);

                    FromLatitude = RouteCache[random_airport].LatitudeR;
                    FromLongitude = RouteCache[random_airport].LongitudeR;
                }
                else
                {
                    break;
                }
            }
        }

        Attempt++;

        if (Attempt == MaximumAttempts && keep_trying)
        {
            Retries++;

            // if someone is stupid enough to have a range of 1 nm and "keeptrying" then we have to shut it down eventually...
            // 21 retries from 1 nautical mile gives us just over 100 nm - that should be enough...
            if (Retries < 22)
            {
                Attempt = 0;

                range *= 1.25;
                DirectionMarginOfError += 5;

                std::wcout << L"  No airports in range, using 1.5x (" << range << L") and retrying (" << Retries << L")...\n";
            }
        }
    }

    if (MultiLegAirports.size() != legs)
    {
        double TotalDistance = 0;

        Runway runway = GRunwayHandler->GetRandom(MultiLegAirports[0].Ident);

        MultiLegAirports[0].Runway = runway.Name;
        MultiLegAirports[0].RunwayLength = runway.Length;

        // update distances
        for (int i = 1; i < MultiLegAirports.size(); i++)
        {
             MultiLegAirports[i].Distance = DistanceBetween(MultiLegAirports[i - 1].LatitudeR, MultiLegAirports[i - 1].LongitudeR,
                                                           MultiLegAirports[i].LatitudeR, MultiLegAirports[i].LongitudeR);

             Runway runway = GRunwayHandler->GetRandom(MultiLegAirports[i].Ident);

             MultiLegAirports[i].Runway = runway.Name;
             MultiLegAirports[i].RunwayLength = runway.Length;

             TotalDistance += MultiLegAirports[i].Distance;
        }

        MultiLegAirports[0].Distance = TotalDistance; // cache total route length in first airport

        RouteHandler::OutputMultiLegRoute(MultiLegAirports);

        if (ExportMSFSPlan)
        {
            if (!MSFSFlightPlan::Export(MultiLegAirports, L"Plans\\" + MultiLegAirports[0].Ident + L"_to_" + MultiLegAirports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".pln"))
            {
                std::wcout << L"\n\nerror saving plan file :( \n";
            }
        }

        return true;
    }

    std::wcout << std::format(L"Sorry, no routes could be generated with a range of {0} nm after {1} attempts :(", range, MaximumAttempts) << L"\n";
    
    return false;
}


int AirportHandler::GetIndexFromICAO(std::wstring icao)
{
    for (int t = 0; t < Airports.size(); t++)
    {
        if (Airports[t].Ident == icao)
        {
            return t;
        }
    }

    return -1;
}


bool AirportHandler::LoadAirports(const std::wstring file_name)
{
    std::wifstream file(file_name);

    //file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

    if (file)
    {
        std::wstring s = L"";

        int count = 0;
        int ignored = 0;

        while (std::getline(file, s))
        {
            if (s != L"")
            {
                if (s[0] == L'\"' || s[0] == L'/')
                {
                    // comment or first row of csv, do nothing
                }
                else
                {                  
                    if (ImportFromRow(s))
                    {
                        count++;
                    }
                    else
                    {
                        ignored++;
                    }
                }
            }
        }

        file.close();

        if (!Silent)
        {
            std::wcout << std::format(L"  Loaded {0} airports, rejected {1} airports.", count, ignored) << L"\n";
        }
    }
    else
    {
        return false;
    }

    return true;
}


bool AirportHandler::ImportFromRow(const std::wstring row)
{
    if (row.length() != 0)
    {
        std::wstring Ident = L"";
        AirportConstants::AirportType Type = AirportConstants::AirportType::None;
        std::wstring tfield = L"";
        std::wstring Name = L"";
        int Elevation = 0;
        std::wstring Latitude = L"";
        std::wstring Longitude = L"";
        std::wstring Country = L"";
        std::wstring Continent = L"";
        std::wstring Region = L"";
        bool MSFSCompatible = false;

        std::wstring field = L"";
        int field_position = 0;

        bool inquotes = false;

        for (int t = 0; t < row.length(); t++)
        {
            if (row[t] == L',' && !inquotes)
            {
                switch (field_position)
                {
                case kAFieldIdent:
                    Ident = field;
                    break;
                case kAFieldType:
                {
                    Type = GetTypeFrom(field);

                    if (Type == AirportConstants::AirportType::None)
                    {
                        return false;
                    }

                    break;
                }
                case kAFieldName:
                    Name = field;
                    break;
                case kAFieldLatitude:
                    Latitude = field;
                    break;
                case kAFieldLongitude:
                    Longitude = field;

                    if (Filter.Day || Filter.Night)
                    {
                        double l = 0;

                        try
                        {
                            l = stod(field);
                        }
                        catch (...)
                        {
                            return false;
                        }

                        if (l > Filter.LongitudeFrom || l < Filter.LongitudeTo)
                        {
                            return false;
                        }
                    }

                    break;
                case kAFieldElevation:
                {
                    try
                    {
                        Elevation = stoi(field);
                    }
                    catch(...)
                    {
                        Elevation = 0;
                    }

                    if (Elevation < Filter.MinimumElevation)
                    {
                        return false;
                    }

                    break;
                }
                case kAFieldContinent:
                    Continent = field;
                    
                    if (Filter.Continent != L"")
                    {
                        if (Continent != Filter.Continent)
                        {
                            return false;
                        }
                    }

                    break;
                case kAFieldCountry:
                    Country = field;

                    if (Filter.Country != L"")
                    {
                        if (Country != Filter.Country)
                        {
                            return false;
                        }
                    }

                    break;
                case kAFieldRegion:
                    Region = field;

                    if (Filter.Region != L"")
                    {
                        if (Region != Filter.Region)
                        {
                            return false;
                        }
                    }

                    break;
                case kAFieldMSFSCompatible:
                    if (field == L"1")
                    {
                        MSFSCompatible = true;
                    }
                    break;
                }

                if (field_position == kAFieldMSFSCompatible)
                {
                    break;
                }

                field_position++;

                field = L"";
            }
            else if (row[t] == L'\"')
            {
                inquotes = !inquotes;
            }
            else
            {
                field += row[t];
            }
        }

        switch (Type)
        {
        case AirportConstants::AirportType::Small:
            TypeCount[AirportConstants::AirportTypeSmall]++;
            break;
        case AirportConstants::AirportType::Medium:
            TypeCount[AirportConstants::AirportTypeMedium]++;
            break;
        case AirportConstants::AirportType::Large:
            TypeCount[AirportConstants::AirportTypeLarge]++;
            break;
        case AirportConstants::AirportType::Heliport:
            TypeCount[AirportConstants::AirportTypeHeliport]++;
            break;
        case AirportConstants::AirportType::SeaplaneBase:
            TypeCount[AirportConstants::AirportTypeSeaplaneBase]++;
            break;
        }

        Airport airport(Ident, Type, Name, Elevation, Latitude, Longitude, Country, Continent, Region, MSFSCompatible);

        Airports.push_back(airport);

        return true;
    }

    return false;
}


AirportConstants::AirportType AirportHandler::GetTypeFrom(std::wstring row)
{
    if (row == L"small_airport")
    {
        if (Filter.SmallAirports) return AirportConstants::AirportType::Small;
    }
    else if (row == L"medium_airport")
    {
        if (Filter.MediumAirports) return AirportConstants::AirportType::Medium;
    }
    else if (row == L"large_airport")
    {
        if (Filter.LargeAirports) return AirportConstants::AirportType::Large;
    }
    else if (row == L"heliport")
    {
       if (Filter.Heliports) return AirportConstants::AirportType::Heliport;
    }

    return AirportConstants::AirportType::None;
}


int AirportHandler::FindNearest(const std::wstring start_icao, double range, bool output)
{
    int StartAirport = kRandomAirport;

    if (start_icao != L"")
    {
        StartAirport = GetIndexFromICAO(start_icao);
    }
    else
    {
        return 0;
    }

    Airport origin = GetAirport(StartAirport);

    if (origin.Type != AirportConstants::AirportType::None)
    {
        CalculateDistancesNoMinimum(range, origin.LatitudeR, origin.LongitudeR);

        if (output)
        {
            if (RouteCache.size() != 0)
            {
                std::ranges::sort(RouteCache, {}, &Airport::Distance);

                std::wcout << L"  All airports wthin " << range << L" nm of " << start_icao << "\n\n";

                for (int t = 0; t < RouteCache.size(); t++)
                {
                    std::wcout << L"    " << RouteCache[t].Ident << L", " << RouteCache[t].Country << L" (" << RouteCache[t].Distance << L" nm), " << Utility::GetAirportTypeDisplay(RouteCache[t].Type) << L"\n";
                }

                std::wcout << L"\n\n";
            }
            else
            {
                std::wcout << L"Sorry, no airports could be found within " << range << L" nm of " << start_icao << L" :(\n\n";
            }
        }
    }
        
    return static_cast<int>(RouteCache.size());
}


// saves to the ourairport.com/data airport.csv format
//
bool AirportHandler::Save(std::wstring file_name, bool only_msfs_compatible)
{
    std::ofstream ofile(file_name);

    if (ofile)
    {
        if (only_msfs_compatible)
        {
            std::wcout << L"Saving FCAS airport data (MSFS compatible only) to \"" << file_name << L"\"\n\n";
        }
        else
        {
            std::wcout << L"Saving FCAS airport data to \"" << file_name << L"\"\n\n";
        }

        ofile << Formatting::to_utf8(L"//airport_id,ident,type,name,latitude_deg,longitude_deg,elevation_ft,iso_continent,iso_country,iso_region,municipality,continent,country,region,longest_runway_length,avgas_avail,jetfuel_avail,airport_use,runway_hard,runway_soft,runway_water,helipad,approach_VASI,approach_ALS,approach_ILS,msfs_compatible,msfs_addon") << "\n";

        for (int t = 0; t < Airports.size(); t++)
        {
            if (!(only_msfs_compatible && Airports[t].MSFSCompatible == false))
            { 
                std::wstring output = std::to_wstring(t) + L',';

                output += Airports[t].Ident + L",";
                output += L"\"" + Utility::GetAirportType(Airports[t].Type) + L"\",";
                output += L"\"" + Airports[t].Name + L"\",";
                output += Airports[t].Latitude + L",";
                output += Airports[t].Longitude + L",";
                output += std::to_wstring(Airports[t].Elevation) + L",";
                output += Airports[t].Continent + L",";
                output += Airports[t].Country + L",";
                output += Airports[t].Region + L",";

                // these are currently not used ;)
                output += L",,,,,,,,,,,,,,,";

                output += std::to_wstring(Airports[t].MSFSCompatible);

                ofile << Formatting::to_utf8(output) << "\n";
            }
        }

        ofile.close();

        return true;
    }
    
    return false;
}


void AirportHandler::ListAirports()
{
    if (Airports.size() != 0)
    {
        std::wcout << L"\n== Airport List ====================================================\n\n";

        for (int t = 0; t < Airports.size(); t++)
        {
            std::wcout << L"  " << Airports[t].Ident << L", " << Airports[t].Continent << L", " << Airports[t].Country << L", " << Airports[t].Region << L". " << Formatting::AddLeadingSpace(std::to_wstring(Airports[t].Elevation), 5) << L" ft. " << Airports[t].Name << L"\n";
        }

        std::wcout << L"\n\n";
    }
}