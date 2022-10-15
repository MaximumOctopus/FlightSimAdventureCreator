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

#include <ShlObj.h>  
#include <string>
#include <windows.h>

#include "WindowsUtility.h"


namespace WindowsUtility
{
	bool FileExists(const std::wstring& file_name)
	{
		FILE* wstream = NULL;

		if (_wfopen_s(&wstream, file_name.c_str(), L"r") == 0)
		{
			if (wstream)
			{
				fclose(wstream);
			}

			return true;
		}
		else
		{
			return false;
		}
	}

	bool DirectoryExistsWString(const std::wstring& dirName_in)
	{
		std::wstring directory;

		if (dirName_in[dirName_in.length() - 1] == L'\"')
		{
			directory = dirName_in.substr(0, dirName_in.length() - 1);
		}
		else
		{
			directory = dirName_in;
		}

		DWORD fileAttr = GetFileAttributes(directory.c_str());

		return (fileAttr != INVALID_FILE_ATTRIBUTES && (fileAttr & FILE_ATTRIBUTE_DIRECTORY));
	}
}