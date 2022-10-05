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

#include <format>
#include <fstream>
#include <iostream>

#include "Job.h"
#include "JobHandler.h"


JobHandler* GJobHandler;


JobHandler::JobHandler(bool silent)
{
	Loaded = LoadJobs(L"Jobs.txt");

    if (!Silent)
    {
        int JobCount = 0;

        for (int t = 0; t < kJobAircraftTypes; t++)
        {
            JobCount += Jobs[t].size();
        }

        std::wcout << std::format(L"  Loaded {0} Jobs, {1} Objects, and {2} SLF.", JobCount, ObjectsUnusual.size() + ObjectsSmall.size() + ObjectsLarge.size(), SLF.size()) << L"\n";
    }
}


std::wstring JobHandler::GetJob(AircraftConstants::AircraftType aircraft_type, bool is_airliner, bool is_military)
{
    JobAircraft jt = JobAircraft::None;
                        
    if (is_military)
    {
        jt = JobAircraft::Military;
    }
    else if (is_airliner)
    {
        jt = JobAircraft::Airliners;
    }
    else
    {
        switch (aircraft_type)
        {
        case AircraftConstants::AircraftType::None:
            break;

        case AircraftConstants::AircraftType::Prop:
        case AircraftConstants::AircraftType::TurboProp:
        case AircraftConstants::AircraftType::TwinProp:
        case AircraftConstants::AircraftType::TwinTurboProp:
            jt = JobAircraft::AllPropsTwins;
            break;

        case AircraftConstants::AircraftType::Jet:
            jt = JobAircraft::Jets;
            break;

        case AircraftConstants::AircraftType::Helicopter:
            jt = JobAircraft::Helicopters;
            break;        
        }
    }

    if (jt != JobAircraft::None)
    {
        int index = JobAircraftTypeToIndex(jt);

        if (Jobs[index].size() != 0)
        {
            std::wstring item = L"";

            Job job = Jobs[index][rand() % Jobs[index].size()];

            switch (job.Cargo)
            {
            case JobCargo::Object:
                if (jt == JobAircraft::Airliners)
                {
                    item = ObjectsLarge[rand() % ObjectsLarge.size()];
                }
                else
                {
                    item = ObjectsSmall[rand() % ObjectsSmall.size()];
                }
                break;
            case JobCargo::ObjectUnusual:
                item = ObjectsUnusual[rand() % ObjectsUnusual.size()];
                break;
            case JobCargo::SLF:
                item = SLF[rand() % SLF.size()];
                break;
            }

            return std::vformat(job.Text, std::make_wformat_args(item));
        }
    }

    return L"";
}


// converts a JobAircraft type to an index to the Jobs vector list
int JobHandler::JobAircraftTypeToIndex(JobAircraft job_aircraft)
{
    switch (job_aircraft)
    {
    case JobAircraft::All:
        return kAddToAll;
    case JobAircraft::AllPropsTwins:
        return 0;
    case JobAircraft::Airliners:
        return 1;
    case JobAircraft::Jets:
        return 2;
    case JobAircraft::Military:
        return 3;
    case JobAircraft::Helicopters:
        return 4;
    }

    return -1;
}


bool JobHandler::LoadJobs(const std::wstring file_name)
{
    std::wifstream file(file_name);

    //file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

    if (file)
    {
        std::wstring s = L"";

        int Line = 1;

        int Category = -1;
        JobAircraft JobAircraftType = JobAircraft::None;
        JobCargo Cargo = JobCargo::None;

        std::wstring Item = L"";

        while (std::getline(file, s))
        {
            if (s != L"")
            {
                if (s[0] == L'\"' || s[0] == L'/')
                {
                    // comment, do nothing
                }
                else
                {
                    switch (s[0])
                    {
                    case L'{':
                        if (s.length() == 3)
                        {
                            switch (s[1])
                            {
                            case L'j':
                            {
                                Category = 0;

                                int at = stoi(s.substr(2));

                                switch (at)
                                {
                                case 0:
                                    JobAircraftType = JobAircraft::All;
                                    break;
                                case 1:
                                    JobAircraftType = JobAircraft::AllPropsTwins;
                                    break;
                                case 2:
                                    JobAircraftType = JobAircraft::Airliners;
                                    break;
                                case 3:
                                    JobAircraftType = JobAircraft::Jets;
                                    break;
                                case 4:
                                    JobAircraftType = JobAircraft::Military;
                                    break;
                                case 5:
                                    JobAircraftType = JobAircraft::Helicopters;
                                    break;

                                default:
                                    std::wcout << std::format(L"Unknown aircraft job type \"{0}\" @ line {1} in Jobs.txt\n", s, Line);
                                    break;
                                }
                                break;
                            }
                            case L'o':
                            {
                                int oc = stoi(s.substr(2));

                                switch (oc)
                                {
                                case 0:
                                    Category = 1;
                                    break;
                                case 1:
                                    Category = 2;
                                    break;
                                case 2:
                                    Category = 4;
                                }
                                break;
                            }
                            case L'p':
                                Category = 3;
                                break;
                            }
                        }
                        else
                        {
                            std::wcout << std::format(L"Invalid job list identifier \"{0}\" @ line {1} in Jobs.txt\n", s, Line);
                        }
                        break;
                    case L'}':
                        Category = -1;
                        break;
                    case L'i':
                        if (s.length() > 2)
                        {
                            Item = s.substr(2);

                            switch (Category)
                            {
                            case 1:
                                ObjectsSmall.push_back(Item);
                                break;
                            case 2:
                                ObjectsLarge.push_back(Item);
                                break;
                            case 3:
                                SLF.push_back(Item);
                                break;
                            case 4:
                                ObjectsUnusual.push_back(Item);
                                break;
                            }
                        }
                        else
                        {
                            std::wcout << std::format(L"Unknown aircraft job type \"{0}\" @ line {1} in Jobs.txt\n", s, Line);
                        }
                        break;
                    case L'o':
                        if (s.length() > 2)
                        {
                            Item = s.substr(2);

                            Cargo = JobCargo::Object;

                            AddTo(JobAircraftType, Cargo, Item);

                            Cargo = JobCargo::None;
                            Item = L"";
                        }
                        else
                        {
                                std::wcout << std::format(L"Invalid object list identifier \"{0}\" @ line {1} in Jobs.txt\n", s, Line);
                        }
                        break;
                    case L's':
                        if (s.length() > 2)
                        {
                            Item = s.substr(2);

                            Cargo = JobCargo::SLF;

                            AddTo(JobAircraftType, Cargo, Item);

                            Cargo = JobCargo::None;
                            Item = L"";
                        }
                        else
                        {
                            std::wcout << std::format(L"Invalid object list identifier \"{0}\" @ line {1} in Jobs.txt\n", s, Line);
                        }
                        break;
                    case L'x':
                        if (s.length() > 2)
                        {
                            Item = s.substr(2);

                            Cargo = JobCargo::ObjectUnusual;

                            AddTo(JobAircraftType, Cargo, Item);                            

                            Cargo = JobCargo::None;
                            Item = L"";
                        }
                        else
                        {
                            std::wcout << std::format(L"Invalid object list identifier \"{0}\" @ line {1} in Jobs.txt\n", s, Line);
                        }
                        break;
                    }
                }
            }

            Line++;
        }
    }

	return false;
}


void JobHandler::AddTo(JobAircraft job_aircraft_type, JobCargo job_cargo, std::wstring item)
{
    Job job(job_aircraft_type, job_cargo, item);

    int index = JobAircraftTypeToIndex(job_aircraft_type);

    if (index != kAddToAll)
    {
        Jobs[index].push_back(job);
    }
    else
    {
        for (int t = 0; t < kJobAircraftTypes; t++)
        {
            Jobs[t].push_back(job);
        }
    }
}