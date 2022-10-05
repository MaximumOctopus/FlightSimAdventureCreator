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

#include <algorithm>
#include <codecvt>
#include <format>
#include <fstream>
#include <iostream>
#include <locale>

#include "Aircraft.h"
#include "AircraftHandler.h"
#include "Constants.h"

#ifdef _DEBUG
#include "Debug.h"
#endif


AircraftHandler* GAircraftHandler;


AircraftHandler::AircraftHandler(bool silent, bool default_aircraft, bool custom_aircraft, int type, bool include_airliners, bool include_military, 
    int max_speed, int min_speed, AircraftConstants::MSFSVersion version, SpecialMode special_mode)
{
    Silent = silent;

    LoadFilter.MaxSpeed = max_speed;
    LoadFilter.MinSpeed = min_speed;

    LoadFilter.Version = version;

    if (special_mode == SpecialMode::None)
    {
        LoadFilter.Type = type;

        LoadFilter.Airliner = include_airliners;
        LoadFilter.Military = include_military;
    }
    else if (special_mode == SpecialMode::JetAirliners)
    {
        LoadFilter.Type = 1;

        LoadFilter.Airliner = true;
        LoadFilter.Military = false;
    }
    else
    {
        LoadFilter.Special = special_mode;
    }

    if (default_aircraft)
    {
        if (!LoadAircraft(L"default_aircraft.txt"))
        {
            std::wcout << L" Aircraft data file not found \"default_aircraft.txt\".\n";
        }
        else
        {
            Loaded = true;
        }
    }

    if (custom_aircraft)
    {
        if (!LoadAircraft(L"custom_aircraft.txt"))
        {
            std::wcout << L" Aircraft data file not found \"custom_aircraft.txt\".\n";
        }
        else
        {
            Loaded = true;
        }
    }

    if (Loaded && !Silent)
    {
        std::wcout << "  Loaded " << AircraftList.size() << " aircraft.\n";
    }
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


bool AircraftHandler::LoadAircraft(const std::wstring file_name)
{
    std::wifstream file(file_name);

    //file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

    if (file)
    {
        ProcessingMode mode = ProcessingMode::ReadyForSection;

        std::wstring Name = L"";
        int CruiseSpeed = 0;
        int Range = 0;
        int RunwayLength = 0;
        AircraftConstants::MSFSVersion Availability = AircraftConstants::MSFSVersion::All;
        AircraftConstants::AircraftType Type = AircraftConstants::AircraftType::None;
        bool Military = false;
        bool Airliner = false;

        std::wstring s;

        bool ShouldAdd = true;

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
                            std::wcout << L"\"{\" identifier found when expecting L\"}\". " << file_name << L" @ line " << line << "\n";
                        }

                        mode = ProcessingMode::SectionFound;
                        break;

                    case RowType::SectionEnd:
                    {
                        if (mode == ProcessingMode::SectionFound)
                        {
                            switch (LoadFilter.Special)
                            {
                            case SpecialMode::GA:
                            {
                                if (Type != AircraftConstants::AircraftType::Prop && Type != AircraftConstants::AircraftType::TwinProp && 
                                    Type != AircraftConstants::AircraftType::TurboProp && Type != AircraftConstants::AircraftType::TwinTurboProp)
                                {
                                    ShouldAdd = false;
                                }

                                if (Military) ShouldAdd = false;
                                if (Airliner) ShouldAdd = false;

                                break;
                            }
                            case SpecialMode::JetAirliners:
                            {
                                if (Type != AircraftConstants::AircraftType::Jet && Airliner != true)
                                {
                                    ShouldAdd = false;
                                }
                                break;
                            }
                            case SpecialMode::Twins:
                                if (Type != AircraftConstants::AircraftType::TwinProp && Type != AircraftConstants::AircraftType::TwinTurboProp)
                                {
                                    ShouldAdd = false;
                                }
                                break;
                            case SpecialMode::Props:
                                if (Type != AircraftConstants::AircraftType::Prop && Type != AircraftConstants::AircraftType::TwinProp)
                                {
                                    ShouldAdd = false;
                                }
                                break;
                            case SpecialMode::TurboProps:
                                if (Type != AircraftConstants::AircraftType::TurboProp && Type != AircraftConstants::AircraftType::TwinTurboProp)
                                {
                                    ShouldAdd = false;
                                }
                                break;
                            }

                            // let's see if this aircraft is valid
                            if (Type == AircraftConstants::AircraftType::None)
                            {
                                std::wcout << std::format(L"    Aircraft error, invalid type specified (None) @ line {0}", line) << "\n";

                                ShouldAdd = false;
                            }

                            if (Range <= 0)
                            {
                                std::wcout << std::format(L"    Aircraft error, invalid range specified {0} @ line {1}", Range, line) << "\n";

                                ShouldAdd = false;
                            }

                            //
                            if (ShouldAdd)
                            {
                                Aircraft aircraft(Name, CruiseSpeed, Range, RunwayLength, Availability, Type, Military, Airliner);

                                AircraftList.push_back(aircraft);
                            }
                            else
                            {
                                #ifdef _DEBUG
                                FSACDebug::Output(L"Rejected " + Name);
                                #endif                      
                            }
                        }
                        else
                        {
                            std::wcout << std::format(L"\"}}\" identifier found when expecting \"{{\". {0} @ line {1}", file_name, line) << "\n";
                        }

                        Name = L"";
                        CruiseSpeed = 0;
                        Range = 0;
                        RunwayLength = 0;
                        Availability = AircraftConstants::MSFSVersion::All;
                        Type = AircraftConstants::AircraftType::None;
                        Military = false;
                        Airliner = false;

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
                            std::wcout << std::format(L"\"name=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
                        }
                        break;

                    case RowType::Cruise:
                        if (mode == ProcessingMode::SectionFound)
                        {
                            int c = GetIntValueFromRow(s);

                            if (c != -1)
                            {
                                if (c < LoadFilter.MaxSpeed && c > LoadFilter.MinSpeed)
                                {
                                    CruiseSpeed = c;
                                }
                                else
                                {
                                    ShouldAdd = false;
                                }
                            }
                        }
                        else
                        {
                            std::wcout << std::format(L"\"cruise=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
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
                            std::wcout << std::format(L"\"range=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
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
                                std::wcout << std::format(L"\"availability=\" identifier invalid (should be {0}-{1}). {2} @ line {3}", AircraftConstants::MSFSVersionMin, AircraftConstants::MSFSVersionMax, file_name, line) << "\n";
                            }
                        }
                        else
                        {
                            std::wcout << std::format(L"\"availability=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
                        }
                        break;

                    case RowType::Type:
                        if (mode == ProcessingMode::SectionFound)
                        {
                            int t = GetIntValueFromRow(s);

                            if (t >= AircraftConstants::AircraftTypeMin && t <= AircraftConstants::AircraftTypeMax)
                            {
                                TypeCount[t]++;

                                if (LoadFilter.Type != -1)
                                {
                                    if (t != LoadFilter.Type)
                                    {
                                        ShouldAdd = false;
                                    }
                                }

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
                                }
                            }
                        }
                        else
                        {
                            std::wcout << std::format(L"\"type=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
                        }
                        break;

                    case RowType::Military:
                        if (mode == ProcessingMode::SectionFound)
                        {
                            Military = GetIntValueFromRow(s);

                            if (!LoadFilter.Military)
                            {
                                if (Military)
                                {
                                    ShouldAdd = false;
                                }
                            }
                        }
                        else
                        {
                            std::wcout << std::format(L"\"military=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
                        }
                        break;

                    case RowType::AirLiner:
                        if (mode == ProcessingMode::SectionFound)
                        {
                            Airliner = GetIntValueFromRow(s);

                            if (!LoadFilter.Airliner)
                            {
                                if (Airliner)
                                {
                                    ShouldAdd = false;
                                }
                            }
                        }
                        else
                        {
                            std::wcout << std::format(L"\"airliner=\" identifier found in invalid location. {0} @ line {1}", file_name, line) << "\n";
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
    else if (row.find(L"military=") != std::wstring::npos)
    {
        return RowType::Military;
    }
    else if (row.find(L"airliner=") != std::wstring::npos)
    {
        return RowType::AirLiner;
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