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

// https://docs.flightsimulator.com/html/Content_Configuration/SimObjects/Aircraft_SimO/aircraft_cfg.htm
// https://docs.flightsimulator.com/html/Content_Configuration/SimObjects/Aircraft_SimO/flight_model_cfg.htm

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

#include "MSFSSystem.h"


namespace MSFSSystem
{
	// this generates the custom_aircraft.txt file automatically from the Community folder
	// or at least it will do, in the next week or so...
	bool CreateAircraftList()
	{
		std::vector<std::wstring> msfsfolders;

		FindFolder(msfsfolders, L"");

		if (msfsfolders.size() != 0)
		{
			for (int t = 0; t < msfsfolders.size(); t++)
			{
				ProcessFolder(msfsfolders[t]);
			}
		}

		return false;
	}


	bool ProcessFolder(const std::wstring folder)
	{
		return false;
	}


	void FindFolder(std::vector<std::wstring>& folders, const std::wstring& location)
	{
		std::wstring tmp = location + L"*";

		WIN32_FIND_DATAW file;

		HANDLE search_handle = FindFirstFileW(tmp.c_str(), &file);

		if (search_handle != INVALID_HANDLE_VALUE)
		{
			do
			{
				if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if ((!lstrcmpW(file.cFileName, L".")) || (!lstrcmpW(file.cFileName, L"..")))
						continue;

					folders.push_back(file.cFileName);
				}

			} while (FindNextFileW(search_handle, &file));

			FindClose(search_handle);
		}
	}
}