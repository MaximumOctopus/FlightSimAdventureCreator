//
// FlightSimAdventureCreator 1.0 (GUI Version)
//
// (c) Paul Alan Freshney 2022-2024
//
// paul@freshney.org
//
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
//
//

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "Ini.h"


Ini::Ini(const std::wstring file_name)
{
	Loaded = LoadFile(file_name);
}


bool Ini::LoadFile(const std::wstring file_name)
{
	std::wifstream file(file_name);

	//file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

	if (file)
	{
		Lines.clear();

		std::wstring s;

		while (std::getline(file, s))
		{
			if (s != L"")
			{
				Lines.push_back(s);
			}
		}

		file.close();

		return true;

	}

	return false;
}


int Ini::ReadInteger(const std::wstring section, const std::wstring key, int default_value)
{
	std::wstring::size_type sz;   // alias of size_t

	try
	{
		int i = std::stoi(ReadString(section, key, L"-1"), &sz);

		if (i == -1)
		{
			return default_value;
		}

		return i;
	}
	catch(...)
	{
		return default_value;
	}
}


std::wstring Ini::ReadString(std::wstring section, std::wstring key, const std::wstring default_value)
{
	bool inSection = false;
	std::wstring SectionName = L"";
	int StartIndex = 0;

	key = key + L'=';

	std::transform(key.begin(), key.end(), key.begin(), ::tolower);
	std::transform(section.begin(), section.end(), section.begin(), ::tolower);

	if (LastSection == section)
	{ 
		StartIndex = LastSectionIndex;
	}

	for (int i = StartIndex; i < Lines.size(); i++)
	{
		if (Lines[i][0] == L'[')
		{
			if (inSection)
			{
				// we were in the right section, but now entered a new one.... which means the key we're looking
				// for must be missing, so return the default value

				LastKeyExist = false;

				return default_value;
			}
			else
			{
				std::size_t bo = Lines[i].find(L"[");
				std::size_t bc = Lines[i].find(L"]");

				SectionName = Lines[i].substr(bo + 1, bc - 1);

				std::transform(SectionName.begin(), SectionName.end(), SectionName.begin(), ::tolower);

				if (SectionName == section)
				{
					inSection = true;

					LastSection = section;
					LastSectionIndex = i;
				}
			}
		}
		else
		{
			if (inSection)
			{
				if (Lines[i] != L"")
				{
					if ((Lines[i][0] != L';') && (Lines[i][0] != L'/'))
					{
						std::wstring normalised_line = NormaliseEntry(Lines[i]);

						std::wstring line(normalised_line);
						std::transform(line.begin(), line.end(), line.begin(), ::tolower);

						if (line.find(key) == 0)
						{
							if (normalised_line.length() > key.length())
							{
								LastKeyExist = true;

								return normalised_line.substr(key.length());
							}
							else
							{
								LastKeyExist = false;

								// key is emtpy (key= ) so let's return the default                                

								return default_value;
							}
						}
					}
				}
			}
		}
	}

	return default_value;
}


// this removes white space, quote characters so that our input resembles this:
// key=value
std::wstring Ini::NormaliseEntry(const std::wstring line)
{
	std::wstring output = L"";

	bool inquotes = false;
	bool intovalue = false;

	for (int t = 0; t < line.length(); t++)
	{
		if (line[t] == L'=')
		{
			intovalue = true;

			output += line[t];
		}
		else if (line[t] == L'"')
		{
			inquotes = !inquotes;
		}
		else if (line[t] == L';')
		{
			if (intovalue && !inquotes)
			{
				break;
			}
		}
		else
		{
			if (line[t] == L' ')
			{
				if (inquotes)
				{
					output += L' ';
				}
			}
			else
			{
				output += line[t];
			}
		}
	}

	return output;
}