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

#pragma once


#include <string>


namespace Formatting
{
	[[nodiscard]] std::wstring AddLeadingSpace(std::wstring, int);
    [[nodiscard]] std::wstring AddTrailingSpace(std::wstring, int);

    std::string to_utf8(const std::wstring& str);
    std::string to_utf8(const wchar_t* buffer, int len);
}