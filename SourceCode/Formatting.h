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

#pragma once


#include <string>

#include "Formatting.h"


namespace Formatting
{
	[[nodiscard]] std::wstring AddLeadingSpace(std::wstring, int);

    std::string to_utf8(const std::wstring& str);
    std::string to_utf8(const wchar_t* buffer, int len);
}