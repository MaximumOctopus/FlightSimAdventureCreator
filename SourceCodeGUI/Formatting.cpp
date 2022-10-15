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

#include <string>
#include <windows.h>

#include "Formatting.h"


namespace Formatting
{
	std::wstring AddLeadingSpace(std::wstring input, int length)
	{
		if (input.length() == length)
		{
			return input;
		}
		else if (input.length() < length)
		{
			for (auto t = input.length(); t < length; t++)
			{
				input.insert(input.begin(), L' ');
			}

			return input;
		}

		return input;
	}


	std::wstring AddTrailingSpace(std::wstring input, int length)
	{
		if (input.length() == length)
		{
			return input;
		}
		else if (input.length() < length)
		{
			for (auto t = input.length(); t < length; t++)
			{
				input += L' ';
			}

			return input;
		}

		return input;
	}


    // utf8 output magic
    std::string to_utf8(const std::wstring& str)
    {
        return to_utf8(str.c_str(), (int)str.size());
    }


    std::string to_utf8(const wchar_t* buffer, int len)
    {
        int nChars = ::WideCharToMultiByte(
            CP_UTF8,
            0,
            buffer,
            len,
            NULL,
            0,
            NULL,
            NULL);
        if (nChars == 0) return "";

        std::string newbuffer;

        newbuffer.resize(nChars);
        ::WideCharToMultiByte(
            CP_UTF8,
            0,
            buffer,
            len,
            const_cast<char*>(newbuffer.c_str()),
            nChars,
            NULL,
            NULL);

        return newbuffer;
    }
}