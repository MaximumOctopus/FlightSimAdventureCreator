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

#include <filesystem>
#include <string>

#include "FileUtility.h"


namespace FileUtility
{
	bool FileExists(const std::wstring file_name)
	{
		return std::filesystem::exists(file_name);
	}


	bool DirectoryExists(const std::wstring folder_name)
	{
		return std::filesystem::exists(folder_name);
	}
}