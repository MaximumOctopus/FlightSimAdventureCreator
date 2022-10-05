////
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
#include <fstream>
#include <iostream>

#include "RunwayHandler.h"


RunwayHandler* GRunwayHandler;


RunwayHandler::RunwayHandler(bool silent)
{
    Silent = silent;

    Runways.reserve(40000);

    Loaded = LoadRunways(L"runways.csv");

    if (!Loaded)
    {
        std::wcout << L" Runway data file not found \"runways.csv\".\n";
        std::wcout << L" The latest airports data file can be found here: https://ourairports.com/data/\n\n";
    }
}


Runway RunwayHandler::GetRandom(std::wstring icao)
{
    // ordered alphabetically in the runways file
    // once found, we know the last one is the end in the file
    bool foundicao = false;

    std::vector<int> Available;

    for (int t = 0; t < Runways.size(); t++)
    {
        if (Runways[t].Ident == icao)
        {
            foundicao = true;

            Available.push_back(t);
        }

        if (foundicao)
        {
            if (Runways[t].Ident != icao)
            {
                break;
            }
        }
    }

    if (Available.size() != 0)
    {
        return Runways[Available[rand() % Available.size()]];
    }

    std::wcout << L" Couldn't get a runway for airport \"" << icao << L"\" (exported files may not work correctly)\n";

    return Runway();
}


bool RunwayHandler::LoadRunways(std::wstring file_name)
{
    std::wifstream file(file_name);

    if (file)
    {
        std::wstring s = L"";

        int count = 0;

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
                }
            }
        }

        file.close();

        if (!Silent)
        {
            std::wcout << "  Loaded " << count << " runways.\n";
        }
    }
    else
    {
        return false;
    }

    return true;
}


bool RunwayHandler::ImportFromRow(const std::wstring row)
{
    if (row.length() != 0)
    {
        std::wstring Ident = L"";
        std::wstring SurfaceType = L"";
        std::wstring Name = L"";
        int Length = 0;

        std::wstring field = L"";
        int field_position = 0;

        bool inquotes = false;

        for (int t = 0; t < row.length(); t++)
        {
            if (row[t] == L',' && !inquotes)
            {
                if (field_position == kRFieldIdent)
                {
                    Ident = field;
                }
                else if (field_position == kRFieldLength)
                {
                    try
                    {
                        Length = stoi(field);
                    }
                    catch (...)
                    {
                        Length = 0;
                    }                    
                }
                else if (field_position == kRFieldSurfaceType)
                {
                    SurfaceType = field;
                }
                else if (field_position == kRFieldName)
                {
                    Name = field;

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

        Runway runway(Ident, Name, SurfaceType, Length);

        Runways.push_back(runway);

        return true;
    }

    return false;
}