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

#include <iostream>

#include "Debug.h"


namespace FSACDebug
{
	void Output(const std::wstring output, const std::source_location& location)
	{
		std::wcout << L" (debug) " << location.function_name() << "() @ " << location.line() << L" " << output << "\n";
	}
}