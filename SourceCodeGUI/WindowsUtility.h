//
// FlightSimAdventureCreator 1.0 (GUI Version)
//
// (c) Paul Alan Freshney 2022
//
// paul@freshney.org
//
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
//
//

#pragma once


namespace WindowsUtility
{
	[[nodiscard]] bool FileExists(const std::wstring&);

	[[nodiscard]] bool DirectoryExistsWString(const std::wstring&);

    void OpenWebsite(const std::wstring);
}
