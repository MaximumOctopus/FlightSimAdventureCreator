//
// FlightSimAdventureCreator 1.0 (GUI Version)
//
// (c) Paul Alan Freshney 2022-2023
//
// paul@freshney.org
//
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
//
//

#pragma once

#include <algorithm>
#include <fstream>

#include "AirlineHandler.h"
#include "Constants.h"


AirlineHandler* GAirlineHandler;


AirlineHandler::AirlineHandler()
{
	Loaded = LoadAirlines(SystemConstants::AirlineFileName);
}


bool AirlineHandler::LoadAirlines(const std::wstring file_name)
{
	std::wifstream file(file_name);

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
		std::wstring IATA = L"";

		std::wstring field = L"";
		int field_position = 0;

		for (int t = 0; t < row.length(); t++)
		{
			if (row[t] == L',')
			{
				switch (field_position)
				{
				case kFFieldName:
					Name = field;
					break;
				case kFFieldIATA:
					IATA = field;
					break;
				}
			}
			else
            {
                field += row[t];
			}
        }

		Airline airline(Name, IATA, L"", L"");

		Airlines.push_back(airline);

        return true;
    }

    return false;
}
