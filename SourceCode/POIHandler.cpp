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
#include <fstream>
#include <iostream>

#include "POIHandler.h"


POIHandler::POIHandler()
{
    Loaded = LoadPOIs(L"");

    if (!Loaded)
    {
        std::wcout << L" Runway data file not found \"runways.csv\".\n";
        std::wcout << L" The latest airports data file can be found here: https://ourairports.com/data/\n\n";
    }
}


bool POIHandler::LoadPOIs(std::wstring file_name)
{
    std::wifstream file(file_name);

    //file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

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

        std::wcout << std::format(L"  Loaded {0} points of interest.", count) << L"\n";
    }
    else
    {
        std::wcout << std::format(L"  POI data file not found \"{0}\"", file_name) << L"\n";

        return false;
    }

    return true;
}


bool POIHandler::ImportFromRow(const std::wstring row)
{
    if (row.length() != 0)
    {
        std::wstring Name = L"";
        std::wstring Description = L"";
        std::wstring Latitude = L"";
        std::wstring Longitude = L"";

        std::wstring field = L"";
        int field_position = 0;

        bool inquotes = false;

        for (int t = 0; t < row.length(); t++)
        {
            if (row[t] == L',' && !inquotes)
            {
                switch (field_position)
                {
                case kPFieldName:
                    Name = field;
                    break;
                case kPFieldLatitude:
                    Latitude = field;
                    break;
                case kPFieldLongitude:
                    Longitude = field;
                    break;
                case kPFieldDescription:
                    Description = field;
                    break;
                }

                if (field_position == kPFieldDescription)
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

        POI poi(Name, Description, Latitude, Longitude);

        POIs.push_back(poi);

        return true;
    }

    return false;
}