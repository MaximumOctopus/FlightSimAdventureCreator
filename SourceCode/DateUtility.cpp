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

#include <ctime>
#include <string>

#include "DateUtility.h"


namespace DateUtility
{
	double GetUTCHour()
	{
		struct tm newtime;
		struct tm gmtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);

		gmtime_s(&gmtime, &now);

		return (double)gmtime.tm_hour + ((double)gmtime.tm_min / 60);
	}


	int GetMonth()
	{
		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);

		return newtime.tm_mon + 1;
	}


	std::wstring DateTime(int mode)
	{
		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);

		std::wstring year = std::to_wstring(newtime.tm_year + 1900);
		std::wstring month = std::to_wstring(newtime.tm_mon + 1);
		std::wstring day = std::to_wstring(newtime.tm_mday);
		std::wstring hour = std::to_wstring(newtime.tm_hour);
		std::wstring min = std::to_wstring(newtime.tm_min);
		std::wstring sec = std::to_wstring(newtime.tm_sec);

		if (newtime.tm_mon + 1 < 10)
		{
			month = L"0" + month;
		}

		if (newtime.tm_mday < 10)
		{
			day = L"0" + day;
		}

		if (newtime.tm_hour < 10)
		{
			hour = L"0" + hour;
		}

		if (newtime.tm_min < 10)
		{
			min = L"0" + min;
		}

		if (newtime.tm_sec < 10)
		{
			sec = L"0" + sec;
		}

		if (mode == kDisplayModeConsole)
		{
			return year + L"/" + month + L"/" + day + L" " + hour + L":" + min + L":" + sec;
		}
		else if (mode == kDisplayModeFile)
		{
			return year + month + day + L"_" + hour + min + sec;
		}
		else
		{
			return L"unknown datetime mode!";
		}
	}
}