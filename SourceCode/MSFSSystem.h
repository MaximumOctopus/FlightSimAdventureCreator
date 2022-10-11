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

// a place for functions that interrogate the MSFS system directly

#pragma once


namespace MSFSSystem
{
	[[nodiscard]] bool CreateAircraftList(const std::wstring);

	bool ProcessContentsFolder(std::vector<Aircraft>&, const std::wstring);

	std::wstring GetNameFromUSLocalisation(const std::wstring);
	std::wstring StripFromJSON(const std::wstring);

	bool SaveCustomAircraftFile(std::vector<Aircraft>&, const std::wstring);

	std::wstring GetFirstFolder(const std::wstring&);

	void FindFolder(std::vector<std::wstring>&, const std::wstring&);
}