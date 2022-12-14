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

#include <algorithm>
#include <fstream>
#include <iostream>
#include <locale>

#include "Aircraft.h"
#include "AircraftHandler.h"
#include "Constants.h"


AircraftHandler* GAircraftHandler;


bool sortByPath(const Aircraft& lhs, const Aircraft& rhs)
{
	std::wstring l = lhs.Name;
	std::wstring r = rhs.Name;

	std::transform(l.begin(), l.end(), l.begin(), ::tolower);
	std::transform(r.begin(), r.end(), r.begin(), ::tolower);

	int c = l.compare(r);

	if (c <= 0)
	{
		return true;
	}

    return false;
}


AircraftHandler::AircraftHandler()
{
	if (!LoadAircraft(SystemConstants::DefaultAircraft))
	{
		LastError = L" Aircraft data file not found \"" + SystemConstants::DefaultAircraft + L"\".";
	}
	else
	{
		Loaded = true;
	}

	if (!LoadAircraft(SystemConstants::CustomAircraft))
	{
	   LastError = L" Aircraft data file not found \"" + SystemConstants::CustomAircraft + L"\".";
	}
	else
	{
		Loaded = true;
	}

	std::sort(AircraftList.begin(), AircraftList.end(), sortByPath);
}


Aircraft AircraftHandler::GetRandomAircraft()
{
	if (AircraftList.size() != 0)
    {
        int a = rand() % AircraftList.size();

		return AircraftList[a];
    }

	return Aircraft();
}


int AircraftHandler::Filter(AircraftLoadFilter alf)
{
	FilteredList.clear();

	for (int t = 0; t < AircraftList.size(); t++)
	{
		bool add = true;

		if (!alf.Types[AircraftList[t].TypeAsInt])
		{
			add = false;
		}

		if (!alf.Airliner && AircraftList[t].Airliner)
		{
			add = false;
		}

		if (!alf.Military && AircraftList[t].Military)
		{
			add = false;
		}

		if (!alf.Seaplane && AircraftList[t].Seaplane)
		{
			add = false;
		}

		if (AircraftList[t].CruiseSpeed > alf.MaxSpeed)
		{
			add = false;
		}

        if (AircraftList[t].CruiseSpeed < alf.MinSpeed)
		{
			add = false;
		}

		if (alf.Version != AircraftConstants::MSFSVersion::All)
		{
			switch (AircraftList[t].Availability)
			{
				case AircraftConstants::MSFSVersion::All:
					break;
				case AircraftConstants::MSFSVersion::DeluxeAbove:
					if (alf.Version == AircraftConstants::MSFSVersion::PremiumAbove)
					{
						add = false;
					}
					break;
				case AircraftConstants::MSFSVersion::PremiumAbove:
					break;
			}
		}

		if (add)
		{
			FilteredList.push_back(AircraftList[t]);
        }
	}

	return FilteredList.size();
}


bool AircraftHandler::LoadAircraft(const std::wstring file_name)
{
    std::wifstream file(file_name);

	if (file)
    {
		ProcessingMode mode = ProcessingMode::ReadyForSection;

		std::wstring Name = L"";
        int CruiseSpeed = 0;
        int Range = 0;
		int RunwayLength = 0;
		AircraftConstants::MSFSVersion Availability = AircraftConstants::MSFSVersion::All;
		AircraftConstants::AircraftType Type = AircraftConstants::AircraftType::None;
		bool Airliner = false;
		bool Military = false;
		bool Seaplane = false;

		bool ShouldAdd = true;

		std::wstring s;

		int line = 1;

		while (std::getline(file, s))
		{
			if (s != L"")
			{
                if (s[0] == L'/' || s[1] == L';')
				{
                    // comment, do nothing
				}
                else
				{
                    RowType current = GetRowType(s);

                    switch (current)
					{
                    case RowType::Unknown:
						break;

					case RowType::SectionStart:

						if (mode == ProcessingMode::SectionFound)
                        {
						 //   std::wcout << L"\"{\" identifier found when expecting L\"}\". " << file_name << L" @ line " << line << "\n";
                        }

                        mode = ProcessingMode::SectionFound;
						break;

					case RowType::SectionEnd:
                    {
						if (mode == ProcessingMode::SectionFound)
						{
							if (Range <= 0)
							{
							  //  std::wcout << std::format(L"    Aircraft error, invalid range specified {0} @ line {1}", Range, line) << "\n";

								ShouldAdd = false;
							}

							//
							if (ShouldAdd)
							{
								Aircraft aircraft(Name, CruiseSpeed, Range, RunwayLength, Availability, Type, Airliner, Military, Seaplane);

								AircraftList.push_back(aircraft);
							}
							else
							{
  //								FSACDebug::Output(L"Rejected " + Name);
							}
						}
						else
						{
						  //  std::wcout << std::format(L"\"}}\" identifier found when expecting \"{{\". {0} @ line {1}", file_name, line) << "\n";
						}

						Name = L"";
						CruiseSpeed = 0;
						Range = 0;
						RunwayLength = 0;
						Availability = AircraftConstants::MSFSVersion::All;
						Type = AircraftConstants::AircraftType::None;
						Airliner = false;
						Seaplane = false;
						Military = false;

						mode = ProcessingMode::ReadyForSection;

						ShouldAdd = true;

                        break;
                    }
					case RowType::Name:
                        if (mode == ProcessingMode::SectionFound)
                        {
							Name = GetStringValueFromRow(s);
                        }
                        else
                        {
						   // std::wcout << std::format(L"\"name=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
                        }
                        break;

                    case RowType::Cruise:
                        if (mode == ProcessingMode::SectionFound)
                        {
                            int c = GetIntValueFromRow(s);

                            if (c != -1)
                            {
								CruiseSpeed = c;
                            }
                        }
                        else
                        {
						   // std::wcout << std::format(L"\"cruise=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
                        }
                        break;

                    case RowType::Range:
                        if (mode == ProcessingMode::SectionFound)
                        {
							int r = GetIntValueFromRow(s);

                            if (r > 0)
                            {
                                Range = r;
                            }
                        }
                        else
                        {
							//std::wcout << std::format(L"\"range=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
                        }
                        break;

                    case RowType::Availability:
                        if (mode == ProcessingMode::SectionFound)
                        {
                            int t = GetIntValueFromRow(s);

                            if ((t >= AircraftConstants::MSFSVersionMin && t <= AircraftConstants::MSFSVersionMax) || t == 99)
                            {
                                switch (t)
                                {
                                case 0:
                                case 99:
                                    Availability = AircraftConstants::MSFSVersion::All;
                                    break;
                                case 1:
                                    Availability = AircraftConstants::MSFSVersion::DeluxeAbove;

                                    if (LoadFilter.Version == AircraftConstants::MSFSVersion::PremiumAbove)
                                    {
                                        ShouldAdd = false;
                                    }

                                    break;
                                case 2:
                                    Availability = AircraftConstants::MSFSVersion::PremiumAbove;

                                    if (LoadFilter.Version != AircraftConstants::MSFSVersion::All)
                                    {
                                        ShouldAdd = false;
                                    }

                                    break;
                                }
                            }
                            else
                            {
							   // std::wcout << std::format(L"\"availability=\" identifier invalid (should be {0}-{1}). {2} @ line {3}", AircraftConstants::MSFSVersionMin, AircraftConstants::MSFSVersionMax, file_name, line) << "\n";
                            }
                        }
                        else
                        {
						  //  std::wcout << std::format(L"\"availability=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
                        }
                        break;

                    case RowType::Type:
                        if (mode == ProcessingMode::SectionFound)
                        {
                            int t = GetIntValueFromRow(s);

                            if (t >= AircraftConstants::AircraftTypeMin && t <= AircraftConstants::AircraftTypeMax)
                            {
								TypeCount[t]++;

								switch (t)
                                {
                                case 0:
                                    Type = AircraftConstants::AircraftType::Prop;
                                    TypeCount[AircraftConstants::AircraftTypeProp]++;
                                    break;
                                case 1:
                                    Type = AircraftConstants::AircraftType::Jet;
                                    TypeCount[AircraftConstants::AircraftTypeJet]++;
                                    break;
                                case 2:
                                    Type = AircraftConstants::AircraftType::Helicopter;
                                    TypeCount[AircraftConstants::AircraftTypeHeli]++;
                                    break;
                                case 3:
                                    Type = AircraftConstants::AircraftType::Glider;
                                    TypeCount[AircraftConstants::AircraftTypeGlider]++;
                                    break;
                                case 4:
                                    Type = AircraftConstants::AircraftType::TwinProp;
                                    TypeCount[AircraftConstants::AircraftTypeTwinProp]++;
                                    break;
                                case 5:
                                    Type = AircraftConstants::AircraftType::TurboProp;
                                    TypeCount[AircraftConstants::AircraftTypeTurboProp]++;
                                    break;
                                case 6:
                                    Type = AircraftConstants::AircraftType::TwinTurboProp;
                                    TypeCount[AircraftConstants::AircraftTypeTwinTurboProp]++;
                                    break;
                                case 7:
                                    Type = AircraftConstants::AircraftType::Balloon;
                                    TypeCount[AircraftConstants::AircraftTypeBalloon]++;
                                    break;
                                }
                            }
                        }
                        else
                        {
						   // std::wcout << std::format(L"\"type=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
                        }
                        break;
                    case RowType::AirLiner:
                        if (mode == ProcessingMode::SectionFound)
                        {
                            Airliner = GetIntValueFromRow(s);
						}
                        else
                        {
						   // std::wcout << std::format(L"\"airliner=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
                        }
                        break;
                    case RowType::Military:
                        if (mode == ProcessingMode::SectionFound)
                        {
							Military = GetIntValueFromRow(s);
						}
                        else
                        {
						   // std::wcout << std::format(L"\"military=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
                        }
                        break;
                    case RowType::Seaplane:
                        if (mode == ProcessingMode::SectionFound)
                        {
							Seaplane = GetIntValueFromRow(s);
                        }
                        else
                        {
						   // std::wcout << std::format(L"\"military=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
                        }
                        break;
                    case RowType::RunwayLength:
                    {
                        int r = GetIntValueFromRow(s);

                        if (r >= 0)
						{
                            RunwayLength = r;
                        }

                        break;
                    }
                    }
                }
            }

            line++;
        }

        file.close();
    }
    else
    {
        return false;
    }

    return true;
}


AircraftHandler::RowType AircraftHandler::GetRowType(const std::wstring row)
{
    if (row[0] == L'{')
    {
        return RowType::SectionStart;
    }
    else if (row[0] == L'}')
    {
        return RowType::SectionEnd;
    }
    else if (row.find(L"name=") != std::wstring::npos)
    {
        return RowType::Name;
    }
    else if (row.find(L"cruise=") != std::wstring::npos)
    {
        return RowType::Cruise;
    }
    else if (row.find(L"range=") != std::wstring::npos)
    {
        return RowType::Range;
    }
    else if (row.find(L"availability=") != std::wstring::npos)
    {
        return RowType::Availability;
    }
    else if (row.find(L"type=") != std::wstring::npos)
    {
        return RowType::Type;
	}
    else if (row.find(L"airliner=") != std::wstring::npos)
    {
        return RowType::AirLiner;
	}
	else if (row.find(L"military=") != std::wstring::npos)
	{
		return RowType::Military;
	}
    else if (row.find(L"seaplane=") != std::wstring::npos)
	{
		return RowType::Seaplane;
	}
    else if (row.find(L"minrunway=") != std::wstring::npos)
    {
        return RowType::RunwayLength;
    }

    return RowType::Unknown;
}


std::wstring AircraftHandler::GetStringValueFromRow(const std::wstring row)
{
    auto pos = row.find(L"=");

    if (pos != std::wstring::npos)
    {
		return row.substr(pos + 1);
    }

    return L"unknown";
}


int AircraftHandler::GetIntValueFromRow(const std::wstring row)
{
    auto pos = row.find(L"=");

    if (pos != std::wstring::npos)
    {
        try
        {
            int value = stoi(row.substr(pos + 1));

            return value;
        }
        catch (...)
        {

        }
    }

    return -1;
}


std::wstring AircraftHandler::GetLastError()
{
    return LastError;
}
