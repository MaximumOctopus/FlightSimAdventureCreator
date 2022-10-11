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
#include <format>
#include <fstream>
#include <iostream>

#include "Constants.h"
#include "Formatting.h"
#include "RunwayHandler.h"


RunwayHandler* GRunwayHandler;


RunwayHandler::RunwayHandler(const std::wstring file_name)
{
    Runways.reserve(40000);

    Loaded = LoadRunways(file_name);

    if (!Loaded)
    {
        std::wcout << L" Runway data file not found \"" << SystemConstants::RunwaysFileName << L"\".\n";
        std::wcout << L" The latest airports data file can be found here: https://ourairports.com/data/\n\n";
    }

    #ifdef _DEBUG
    ImportedDataCheck();
    #endif
}


RunwayHandler::RunwayHandler(bool silent, const std::wstring file_name)
{
    Silent = silent;

    Runways.reserve(26000);

    Loaded = LoadRunways(file_name);

    if (!Loaded)
    {
        std::wcout << L" Runway data file not found \"" << SystemConstants::RunwaysFileName << L"\".\n";
        std::wcout << L" The latest airports data file can be found here: https://ourairports.com/data/\n\n";
    }

    #ifdef _DEBUG
    ImportedDataCheck();
    #endif
}


Runway RunwayHandler::GetRandom(const std::wstring icao)
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


#ifdef _DEBUG
void RunwayHandler::ImportedDataCheck()
{
    int NoICAO = 0;
    int NoName = 0;
    int LengthZero = 0;
    int NoSurface = 0;

    for (int t = 0; t < Runways.size(); t++)
    {
        if (Runways[t].Ident == L"")
        {
            NoICAO++;
        }
        if (Runways[t].Name == L"")
        {
            NoName++;
        }
        if (Runways[t].Length == 0)
        {
            LengthZero++;
        }
        if (Runways[t].SurfaceType == L"")
        {
            NoSurface++;
        }
    }

    std::wcout << std::format(L"    NoICAO: {0}; NoName: {1}; NoSurface: {2}; LengthZero: {3}.\n", NoICAO, NoName, NoSurface, LengthZero);
}
#endif


bool RunwayHandler::LoadRunways(const std::wstring file_name)
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


int RunwayHandler::FindAndSet(const std::wstring icao)
{
    int count = 0;

    for (int t = 0; t < Runways.size(); t++)
    {
        if (Runways[t].Ident == icao)
        {
            Runways[t].MSFSCompatible = true;

            count++;
        }
    }

    return count;
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
                switch (field_position)
                {
                case kRFieldIdent:
                    Ident = field;
                    break;
                case kRFieldLength:
                    try
                    {
                        Length = stoi(field);
                    }
                    catch (...)
                    {
                        Length = 0;
                    }
                    break;
                case kRFieldSurfaceType:
                    SurfaceType = field;
                    break;
                case kRFieldName:
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


bool RunwayHandler::Save(const std::wstring file_name, bool only_msfs_compatible)
{
    std::ofstream ofile(file_name);

    if (ofile)
    {
        if (only_msfs_compatible)
        {
            std::wcout << L"Saving runway data (MSFS compatible only) to \"" << file_name << L"\"\n\n";
        }
        else
        {
            std::wcout << L"Saving runway data to \"" << file_name << L"\"\n\n";
        }

        ofile << Formatting::to_utf8(L"//id,airport_ref,airport_ident,length_ft,width_ft,surface,lighted,closed,le_ident\n");

        for (int t = 0; t < Runways.size(); t++)
        {
            if (!(only_msfs_compatible && Runways[t].MSFSCompatible == false))
            {
                std::wstring output = std::to_wstring(t) + L",0,";          // 0 is the airport ref which we don't have / use

                output += Runways[t].Ident + L",";
                output += std::to_wstring(Runways[t].Length) + L",";
                output += L"0,";                                            // width, not stored or used
                output += Runways[t].SurfaceType + L",";
                output += L",,";                                            // lighted and closed not used (we don't import closed airports!)
                output += Runways[t].Name + L",";

                ofile << Formatting::to_utf8(output) << "\n";
            }
        }

        ofile.close();

        return true;
    }

    return false;
}