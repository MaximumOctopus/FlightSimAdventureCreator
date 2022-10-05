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
 

namespace GlobalObjects
{
    [[nodiscard]] bool CreateGlobalObjects(int, wchar_t* argv[]);

    void FreeGlobalObjects();
}