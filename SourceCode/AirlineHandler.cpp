//
// FlightSimAdventureCreator 1.0
//
// (c) Paul Alan Freshney 2023-2024
//
// paul@freshney.org
// 
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
// 
// 

// only used to populate route files

#pragma once

#include <format>
#include <fstream>
#include <iostream>
#include <vector>

#include "AirlineHandler.h"
#include "Constants.h"


AirlineHandler::AirlineHandler(const std::wstring file_name)
{
	Loaded = LoadAirlines(file_name);

    if (!Loaded)
    {
        std::wcout << L" Airline data file not found \"" << SystemConstants::AirlineFileName << L"\".\n";
    }
}


std::wstring AirlineHandler::FindWithCode(const std::wstring code)
{
    for (int t = 0; t < Airlines.size(); t++)
    {
        if (Airlines[t].Code == code)
        {
            return Airlines[t].Name;
        }
    }

    return L"";
}


bool AirlineHandler::LoadAirlines(const std::wstring file_name)
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

        std::wcout << std::format(L"  Loaded {0} airlines, rejected {1} airlines.", count, ignored) << L"\n";
    }
    else
    {
        return false;
    }

    return true;
}


bool AirlineHandler::ImportFromRow(const std::wstring row)
{
    if (row.length() != 0)
    {
        std::wstring Name = L"";
        std::wstring Code = L"";

        std::wstring field = L"";

        int field_position = 0;

        bool inquotes = false;

        for (int t = 0; t < row.length(); t++)
        {
            if (row[t] == L',' && !inquotes)
            {
                switch (field_position)
                {
                case kAFieldName:
                    Name = field;
                    break;
                case kAFieldCode:
                    Code = field;
                    break;
                }

                if (field_position > kAFieldCode)
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

        Airline airline(Name, Code);

        Airlines.push_back(airline);

        return true;
    }

    return false;
}