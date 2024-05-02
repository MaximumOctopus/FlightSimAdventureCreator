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


#include <source_location>
#include <string>


namespace FSACDebug
{
	void Output(const std::wstring, const std::source_location& = std::source_location::current());
}