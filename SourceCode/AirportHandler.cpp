//
// FlightSimAdventureCreator 1.0
//
// (c) Paul Alan Freshney 2022-2023
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
#include "RouteDisplay.h"
#include "RunwayHandler.h"
#include "TextItinerary.h"
#include "Utility.h"


AirportHandler* GAirportHandler;
extern RunwayHandler* GRunwayHandler;


AirportHandler::AirportHandler(const std::wstring file_name)
{
    ExportMSFSPlan = false;

    Filter.Country = L"";
    Filter.Continent = L"";

    Filter.LargeAirports = true;
    Filter.MediumAirports = true;
    Filter.SmallAirports = true;
    Filter.Heliports = true;
    Filter.SeaplaneBases = true;

    Airports.reserve(30000);

    Loaded = LoadAirports(file_name);

    if (!Loaded)
    {
        std::wcout << std::format(L" Airport data file not found \"{0}\"", file_name) << L"\n";
    }

    #ifdef _DEBUG
    ImportedDataCheck();
    #endif
}


AirportHandler::AirportHandler(bool silent, bool export_plan, bool export_text, AirportData airport_filter_data)
{
    Silent = silent;

    ExportMSFSPlan = export_plan;
    ExportTextReport = export_text;

    Filter.Country = airport_filter_data.Country;
    Filter.Continent = airport_filter_data.Continent;
    Filter.Region = airport_filter_data.Region;

    Filter.LongitudeFrom = airport_filter_data.LongitudeFrom;
    Filter.LongitudeTo = airport_filter_data.LongitudeTo;
    Filter.LatitudeFrom = airport_filter_data.LatitudeFrom;
    Filter.LatitudeTo = airport_filter_data.LatitudeTo;
    Filter.LongitudeFilter = airport_filter_data.LongitudeFilter;
    Filter.LatitudeFilter = airport_filter_data.LatitudeFilter;

    Filter.MinimumElevation = airport_filter_data.Elevation;

    Filter.LargeAirports = airport_filter_data.LargeAirports;
    Filter.MediumAirports = airport_filter_data.MediumAirports;
    Filter.SmallAirports = airport_filter_data.SmallAirports;
    Filter.Heliports = airport_filter_data.Heliports;
    Filter.SeaplaneBases = airport_filter_data.SeaplaneBases;

    if (Filter.LongitudeFrom < Filter.LongitudeTo)
    {
        Filter.LongitudeInverse = true;
    }

    if (Filter.LatitudeFrom < Filter.LatitudeTo)
    {
        Filter.LatitudeInverse = true;
    }

    Airports.reserve(30000);

    Loaded = LoadAirports(SystemConstants::AirportsFileName);

    if (!Loaded)
    {
        std::wcout << L" Airport data file not found \"" << SystemConstants::AirportsFileName << L"\".\n";
    }
    else
    {
        if (airport_filter_data.ListAirports)
        {
            ListAirports();
        }

        #ifdef _DEBUG
        ImportedDataCheck();
        #endif
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


double AirportHandler::DistanceBetweenTwoAirports(const std::wstring icao_from, const  std::wstring icao_to)
{
    int from_index = GetIndexFromICAO(icao_from);
    int to_index = GetIndexFromICAO(icao_to);

    if (from_index != -1 && to_index != -1)
    {
        return DistanceBetween(Airports[from_index].LatitudeR, Airports[from_index].LongitudeR,
                               Airports[to_index].LatitudeR, Airports[to_index].LongitudeR);
    }

    return 0;
}


// https://www.geeksforgeeks.org/program-distance-two-points-earth/
// long and lat must already be converted to radians
double AirportHandler::DistanceBetween(double lat1, double long1, double lat2, double long2)
{
    long double deltalong = (long double)long2 - (long double)long1;
    long double deltalat = (long double)lat2 - (long double)lat1;

    long double distance = pow(sin(deltalat / 2), 2) + cos((long double)lat1) * cos(lat2) * pow(sin(deltalong / 2), 2);

    distance = 2 * asin(sqrt(distance));

    // Radius of Earth in nautical miles
    static const double R = 3340.1;

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
void AirportHandler::CalculateDistances(double range, double direction, double direction_modifier, double origin_lat, double origin_long)
{
    double range_min = range * 0.9;
    double range_max = range * 1.1;

    double angle_min = direction - direction_modifier;
    double angle_max = direction + direction_modifier;

    if (angle_min < 0) angle_min += 360;
    if (angle_max > 359) angle_max -= 360;

    RouteCache.clear();

    for (int t = 0; t < Airports.size(); t++)
    {
        bool is_within_angle = false;

        Airports[t].Distance = DistanceBetween(origin_lat, origin_long, Airports[t].LatitudeR, Airports[t].LongitudeR);

        double angle = Utility::AngleBetween(origin_lat, origin_long, Airports[t].LatitudeR, Airports[t].LongitudeR);

        if (angle_max >= angle_min)
        {
            if (angle >= angle_min && angle <= angle_max)
            {
                is_within_angle = true;
            }
        }
        else
        {   
            if (angle >= angle_min || angle <= angle_max)
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


void AirportHandler::GetRoute(const std::wstring start_icao, const std::wstring end_icao, double range, double direction, int legs, int simple_count, bool keep_trying)
{
    RouteCache.clear();

    if (start_icao != L"" && end_icao != L"")
    {
        StartToFinish(start_icao, end_icao, range, legs, keep_trying);

        return;
    }

    std::wstring TargetICAO = L"";
    bool reverse = false;

    // if we have a start we search as normal, if we only have an end then we do the search as though
    // the end was our start location, then reverse the order :)
    if (!start_icao.empty() && end_icao.empty())
    {
        TargetICAO = start_icao;
    }
    else if (start_icao.empty() && !end_icao.empty())
    {
        TargetICAO = end_icao;

        // so we'll do the route in reverse, so we need to reverse the required angle of flight
        if (direction != DataDefaults::Direction)
        {
            direction = Utility::ReverseAngle(direction);
        }

        reverse = true;
    }

    if (legs == 1)
    {
        if (simple_count > 0)
        {
            Generation.ShortRouteCount = simple_count;
        }

        SimpleRoute(TargetICAO, range, direction, keep_trying, reverse);
    }
    else
    {
        MultiLegRoute(TargetICAO, range, direction, legs, keep_trying, reverse);
    }
}


// generates a route from one airport to another, A->B
bool AirportHandler::SimpleRoute(const std::wstring airport_icao, double range, double direction, bool keep_trying, bool reverse)
{
    int MaximumAttempts = Generation.MaximumAttempts;
    int Attempt = 0;
    int TargetAirport = kRandomAirport;
    int Retries = 0;
    double DirectionMarginOfError = DataDefaults::DirectionMargin;

    if (airport_icao != L"")
    {
        TargetAirport = GetIndexFromICAO(airport_icao);

        if (TargetAirport == kRandomAirport)
        {
            std::wcout << L"  Couldn't find start airport L\"" << airport_icao << L"\", using random :(\n";
        }
    }

    while (Attempt < MaximumAttempts)
    {
        Airport origin = GetAirport(TargetAirport);

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
                
                origin.Runway.Name = runway.Name;
                origin.Runway.Length = runway.Length;
                origin.Runway.Surface = runway.SurfaceType;

                int OutputCount = Generation.ShortRouteCount;

                if (RouteCache.size() < Generation.ShortRouteCount)
                {
                    OutputCount = RouteCache.size();
                }

                for (int t = 0; t < OutputCount; t++)
                {
                    SingleLegAirports.clear();

                    Runway runway = GRunwayHandler->GetRandom(RouteCache[t].Ident);

                    RouteCache[t].Runway.Name = runway.Name;
                    RouteCache[t].Runway.Length = runway.Length;
                    RouteCache[t].Runway.Surface = runway.SurfaceType;

                    if (reverse)
                    {
                        SingleLegAirports.push_back(RouteCache[t]);
                        SingleLegAirports.push_back(origin);

                        SingleLegAirports.back().Distance = SingleLegAirports.front().Distance;
                        SingleLegAirports.back().Angle = Utility::ReverseAngle(SingleLegAirports.back().Angle);
                    }
                    else
                    {
                        SingleLegAirports.push_back(origin);
                        SingleLegAirports.push_back(RouteCache[t]);

                        SingleLegAirports.front().Distance = SingleLegAirports.back().Distance;
                    }

                    SingleLegAirports.front().Angle = Utility::AngleBetween(SingleLegAirports.front().LatitudeR, SingleLegAirports.front().LongitudeR,
                    SingleLegAirports.back().LatitudeR, SingleLegAirports.back().LongitudeR);

                    std::wcout << L"   " << std::format(L"{0} --> {1}, {2} ({3:.1f} nm), @ {4:.1f}°\n", SingleLegAirports.front().Ident, SingleLegAirports.back().Ident, SingleLegAirports.back().Country, SingleLegAirports.back().Distance, SingleLegAirports.front().Angle);

                    if (ExportMSFSPlan || ExportTextReport)    
                    {
                        if (ExportMSFSPlan)
                        {
                            if (!MSFSFlightPlan::Export(SingleLegAirports, L"Plans\\" + SingleLegAirports.front().Ident + L"_to_" + SingleLegAirports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".pln"))
                            {
                                std::wcout << L"\n\nError saving plan file :( \n";
                            }
                        }

                        if (ExportTextReport)
                        {
                            if (!TextItinerary::Export(SingleLegAirports, L"Reports\\" + SingleLegAirports.front().Ident + L"_to_" + SingleLegAirports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".txt"))
                            {
                                std::wcout << L"\n\nError saving text file :( \n";
                            }
                        }
                    }
                }

                return true;
            }
        }

        #ifdef _DEBUG
        std::wcout << std::format(L"SR. SLACount {0}; Attempt {1}.", SingleLegAirports.size(), Attempt);
        #endif 

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


// this will accept either a start airport (reverse = false) or destination airport (reverse = true)
bool AirportHandler::MultiLegRoute(std::wstring airport_icao, double range, double direction, int legs, bool keep_trying, bool reverse)
{
    int MaximumAttempts = Generation.MaximumAttempts;
    int Attempt = 0;
    int TargetAirport = kRandomAirport;
    int Retries = 0;
    double DirectionMarginOfError = DataDefaults::DirectionMargin;

    if (airport_icao != L"")
    {
        TargetAirport = GetIndexFromICAO(airport_icao);

        if (TargetAirport == kRandomAirport)
        {
            std::wcout << L"  Couldn't find airport L\"" << airport_icao << L"\" :(\n";
        }
    }

    while (Attempt < MaximumAttempts)
    {
        MultiLegAirports.clear();

        Airport origin = GetAirport(TargetAirport);

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

        #ifdef _DEBUG
        std::wcout << std::format(L"MLR. MLACount {0}; Legs {1}; Attempt {2}.\n", MultiLegAirports.size(), legs, Attempt);
        #endif 

        if (MultiLegAirports.size() == legs + 1) break;

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

    if (MultiLegAirports.size() == legs + 1)
    {
        if (reverse)
        {
            std::reverse(MultiLegAirports.begin(), MultiLegAirports.end());
        }

        FinaliseMultiLegData();

        RouteDisplay::OutputMultiLegRoute(MultiLegAirports);

        HandleMultiLegExport();

        return true;
    }

    std::wcout << std::format(L"Sorry, no routes could be generated with a range of {0} nm after {1} attempts :(", range, MaximumAttempts) << L"\n";
    
    return false;
}


// used when both start airport and end airport have been set
bool AirportHandler::StartToFinish(std::wstring start_icao, std::wstring end_icao, double range, int legs, bool keep_trying)
{
    int MaximumAttempts = Generation.MaximumAttempts;
    int Attempt = 0;

    double DirectionMarginOfError = DataDefaults::DirectionMargin;
    int StartAirport;
    int EndAirport;

    MultiLegAirports.clear();

    StartAirport = GetIndexFromICAO(start_icao);
    Airport origin = GetAirport(StartAirport);

    EndAirport = GetIndexFromICAO(end_icao);
    Airport destination = GetAirport(EndAirport);

    while (Attempt < MaximumAttempts)
    {
        MultiLegAirports.push_back(origin);

        // eg 3 legs = 4 airports, we have 1, so we need 2 more, then we add the end airport after this loop

        while (MultiLegAirports.size() != legs)
        {
            double direction = Utility::AngleBetween(MultiLegAirports.back().LatitudeR, MultiLegAirports.back().LongitudeR,
                destination.LatitudeR, destination.LongitudeR);

            CalculateDistances(range, direction, DirectionMarginOfError, MultiLegAirports.back().LatitudeR, MultiLegAirports.back().LongitudeR);

            if (RouteCache.size() != 0)
            {
                int random_airport = rand() % RouteCache.size();

                MultiLegAirports.push_back(RouteCache[random_airport]);
            }
            else
            {
                // for now... not sure what to do :(
                std::wcout << std::format(L"  Couldn't complete route, trying again... attempt {0} of {1}\n", Attempt + 1, MaximumAttempts);
                break;
            }
        }

        #ifdef _DEBUG
        std::wcout << std::format(L"STF. MLACount {0}; Legs {1}; Attempt {2}.\n", MultiLegAirports.size(), legs, Attempt);
        #endif      

        if (MultiLegAirports.size() == legs) break;

        Attempt++;
    }

    if (MultiLegAirports.size() == legs)
    {

        MultiLegAirports.push_back(destination);

        FinaliseMultiLegData();

        RouteDisplay::OutputMultiLegRoute(MultiLegAirports);

        HandleMultiLegExport();

        return true;
    }

    return false;
}


void AirportHandler::FinaliseMultiLegData()
{
    double TotalDistance = 0;

    Runway runway = GRunwayHandler->GetRandom(MultiLegAirports[0].Ident);

    MultiLegAirports[0].Runway.Name = runway.Name;
    MultiLegAirports[0].Runway.Length = runway.Length;
    MultiLegAirports[0].Runway.Surface = runway.SurfaceType;

    // update distances
    for (int i = 1; i < MultiLegAirports.size(); i++)
    {
        MultiLegAirports[i].Distance = DistanceBetween(MultiLegAirports[i - 1].LatitudeR, MultiLegAirports[i - 1].LongitudeR,
            MultiLegAirports[i].LatitudeR, MultiLegAirports[i].LongitudeR);

        Runway runway = GRunwayHandler->GetRandom(MultiLegAirports[i].Ident);

        MultiLegAirports[i].Runway.Name = runway.Name;
        MultiLegAirports[i].Runway.Length = runway.Length;
        MultiLegAirports[i].Runway.Surface = runway.SurfaceType;

        TotalDistance += MultiLegAirports[i].Distance;

        MultiLegAirports[i].Angle = Utility::AngleBetween(MultiLegAirports[i - 1].LatitudeR, MultiLegAirports[i - 1].LongitudeR,
            MultiLegAirports[i].LatitudeR, MultiLegAirports[i].LongitudeR);
    }

    MultiLegAirports[0].Distance = TotalDistance; // cache total route length in first airport
}


void AirportHandler::HandleMultiLegExport()
{
    if (ExportMSFSPlan)
    {
        if (!MSFSFlightPlan::Export(MultiLegAirports, L"Plans\\" + MultiLegAirports[0].Ident + L"_to_" + MultiLegAirports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".pln"))
        {
            std::wcout << L"\n\nError saving MSFS plan file :( \n";
        }
    }

    if (ExportTextReport)
    {
        if (!TextItinerary::Export(MultiLegAirports, L"Reports\\" + MultiLegAirports[0].Ident + L"_to_" + MultiLegAirports.back().Ident + L"_" + DateUtility::DateTime(kDisplayModeFile) + L".txt"))
        {
            std::wcout << L"\n\nError saving text file :( \n";
        }
    }
}


int AirportHandler::GetIndexFromIATA(const std::wstring iata)
{
    for (int t = 0; t < Airports.size(); t++)
    {
        if (Airports[t].IATA == iata)
        {
            return t;
        }
    }

    return kRandomAirport;
}


int AirportHandler::GetIndexFromICAO(const std::wstring icao)
{
    for (int t = 0; t < Airports.size(); t++)
    {
        if (Airports[t].Ident == icao)
        {
            return t;
        }
    }

    return kRandomAirport;
}


#ifdef _DEBUG
void AirportHandler::ImportedDataCheck()
{
    int NoICAO = 0;
    int NoIATA = 0;
    int NoName = 0;
    int NoType = 0;
    int NoLat = 0;
    int NoLong = 0;
    int NoCountry = 0;
    int NoContinent = 0;
    int NoRegion = 0;

    for (int t = 0; t < Airports.size(); t++)
    {
        if (Airports[t].Ident == L"")
        {
            NoICAO++;
        }
        if (Airports[t].IATA == L"")
        {
            NoIATA++;
        }
        if (Airports[t].Name == L"")
        {
            NoName++;
        }
        if (Airports[t].Type == AirportConstants::AirportType::None)
        {
            NoType++;
        }
        if (Airports[t].Latitude == L"")
        {
            NoLat++;
        }
        if (Airports[t].Longitude == L"")
        {
            NoLong++;
        }
        if (Airports[t].Country == L"")
        {
            NoCountry++;
        }
        if (Airports[t].Continent == L"")
        {
            NoContinent++;
        }
        if (Airports[t].Region == L"")
        {
            NoRegion++;
        }
    }

    std::wcout << std::format(L"    NoICAO : {0}; NoIATA : {1}; NoName: {2}; NoType : {3}\n", NoICAO, NoIATA, NoName, NoType);
    std::wcout << std::format(L"    NoLat : {0}; NoLong : {1}; NoCont : {2}; NoCountry : {3}; NoReg : {4}; Lo : {5} ft; Hi : {6} ft.\n", NoLat, NoLong, NoContinent, NoCountry, NoRegion, Stats.ElevationLowest, Stats.ElevationHighest);
}
#endif


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
        std::wstring IATA = L"";
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
                        #ifdef _DEBUG
                       // std::wcout << field << L"\n";
                        #endif

                        return false;
                    }

                    break;
                }
                case kAFieldName:
                    Name = field;
                    break;
                case kAFieldLatitude:
                    Latitude = field;

                    if (Filter.LatitudeFilter)
                    {
                        double l = 0;

                        try
                        {
                            l = stod(field);
                        }
                        catch (...)
                        {
                            #ifdef _DEBUG       
                            std::wcout << L"lat convert " << field << L"\n";
                            #endif

                            return false;
                        }

                        if (Filter.LatitudeInverse)
                        {
                            if (l > Filter.LatitudeFrom && l < Filter.LatitudeTo)
                            {
#ifdef _DEBUG       
                                std::wcout << L"lat " << field << L"\n";
#endif

                                return false;
                            }
                        }
                        else
                        {
                            if (l > Filter.LatitudeFrom || l < Filter.LatitudeTo)
                            {
                                #ifdef _DEBUG       
                                std::wcout << L"lat from " << field << L"\n";
                                #endif

                                return false;
                            }
                        }
                    }

                    break;
                case kAFieldLongitude:
                    Longitude = field;

                    if (Filter.Day || Filter.Night || Filter.LongitudeFilter)
                    {
                        double l = 0;

                        try
                        {
                            l = stod(field);
                        }
                        catch (...)
                        {
                            #ifdef _DEBUG
                            std::wcout << L" longconvert " << field << L"\n";
                            #endif

                            return false;
                        }

                        if (Filter.LongitudeInverse)
                        {
                            if (l > Filter.LongitudeFrom && l < Filter.LongitudeTo)
                            {
                                #ifdef _DEBUG       
                                std::wcout << L" Long " << field << L"\n";
                                #endif

                                return false;
                            }
                        }
                        else
                        {
                            if (l > Filter.LongitudeFrom || l < Filter.LongitudeTo)
                            {
                                #ifdef _DEBUG       
                                std::wcout << L" long from " << field << L"\n";
                                #endif

                                return false;
                            }
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
                        #ifdef _DEBUG
                        std::wcout << L"ME = " << Filter.MinimumElevation << L"; input = " << field << L"\n";
                        #endif

                        return false;
                    }

                    if (Elevation < Stats.ElevationLowest)
                    {
                        Stats.ElevationLowest = Elevation;
                    }

                    if (Elevation > Stats.ElevationHighest)
                    {
                        Stats.ElevationHighest = Elevation;
                    }

                    break;
                }
                case kAFieldContinent:
                    Continent = field;
                    
                    if (Filter.Continent != L"")
                    {
                        if (Continent != Filter.Continent)
                        {
                            #ifdef _DEBUG       
                            std::wcout << L"continent = " << field << L"\n";
                            #endif

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
                            #ifdef _DEBUG       
                            std::wcout << L" country " << field << L"\n";
                            #endif

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
                            #ifdef _DEBUG       
                            std::wcout << L"region: " << field << L"\n";
                            #endif

                            return false;
                        }
                    }

                    break;
                case kAFieldIATA:
                    IATA = field;
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

        Airport airport(Ident, Type, Name, Elevation, Latitude, Longitude, Country, Continent, Region, IATA, MSFSCompatible);

        Airports.push_back(airport);

        return true;
    }

    return false;
}


AirportConstants::AirportType AirportHandler::GetTypeFrom(const std::wstring row)
{
    switch (Utility::GetAirportType(row))
    {
    case AirportConstants::AirportType::Small:
        if (Filter.SmallAirports) return AirportConstants::AirportType::Small;
        break;
    case AirportConstants::AirportType::Medium:
        if (Filter.MediumAirports) return AirportConstants::AirportType::Medium;
        break;
    case AirportConstants::AirportType::Large:
        if (Filter.LargeAirports) return AirportConstants::AirportType::Large;
        break;
    case AirportConstants::AirportType::Heliport:
        if (Filter.Heliports) return AirportConstants::AirportType::Heliport;
        break;
    case AirportConstants::AirportType::SeaplaneBase:
        if (Filter.SeaplaneBases) return AirportConstants::AirportType::SeaplaneBase;
        break;
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
                    std::wcout << std::format(L"    {0}, {1} ({2}), {3:.1f} nm, {4}\n", RouteCache[t].Ident, RouteCache[t].Country, RouteCache[t].Region, RouteCache[t].Distance, Utility::GetAirportTypeDisplay(RouteCache[t].Type));
                }

                std::wcout << std::format(L"\n  Found {0} airports within range of {1}.\n\n", RouteCache.size(), start_icao);
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
bool AirportHandler::Save(const std::wstring file_name, bool only_msfs_compatible)
{
    std::ofstream ofile(file_name);

    if (ofile)
    {
        if (only_msfs_compatible)
        {
            std::wcout << L"Saving FSAC airport data (MSFS compatible only) to \"" << file_name << L"\"\n\n";
        }
        else
        {
            std::wcout << L"Saving FSAC airport data to \"" << file_name << L"\"\n\n";
        }

        ofile << Formatting::to_utf8(L"//airport_id,ident,type,name,latitude_deg,longitude_deg,elevation_ft,iso_continent,iso_country,iso_region,unused,unused,unused,iata,unused,unused,unused,unused,unused,unused,unused,unused,unused,unused,unused,msfs_compatible,msfs_addon") << "\n";

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
                output += L",,,";
                output += Airports[t].IATA + L",";

                // these are currently not used ;)
                output += L",,,,,,,,,,,";

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
            std::wcout << L"  " << Formatting::AddTrailingSpace(Airports[t].Ident, 4) << L"   " << Airports[t].Continent << L", " << Airports[t].Country << L" (" << Formatting::AddTrailingSpace(Airports[t].Region, 6) << L") " << Formatting::AddLeadingSpace(std::to_wstring(Airports[t].Elevation), 5) << L" ft. " << Airports[t].Name << L"\n";
        }

        std::wcout << L"\n\n";
    }
}