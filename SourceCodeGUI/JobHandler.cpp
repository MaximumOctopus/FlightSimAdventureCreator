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

#include <fstream>
#include <iostream>

#include "Constants.h"
#include "Job.h"
#include "JobHandler.h"


JobHandler* GJobHandler;


JobHandler::JobHandler()
{
	Loaded = LoadJobs(SystemConstants::JobsFileName);

	int JobCount = 0;

	for (int t = 0; t < kJobAircraftTypes; t++)
	{
	   JobCount += Jobs[t].size();
	}


		// to do std::wcout << std::format(L"  Loaded {0} Jobs, {1} Objects, and {2} SLF.", JobCount, ObjectsUnusual.size() + ObjectsSmall.size() + ObjectsLarge.size(), SLF.size()) << L"\n";
}


std::wstring JobHandler::FindJob(AircraftConstants::AircraftType aircraft_type, bool is_airliner, bool is_military)
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
		case AircraftConstants::AircraftType::Glider:
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
        case AircraftConstants::AircraftType::Balloon:
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
			case JobCargo::None:
				break;
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

			return Format(job.Text, item);
        }
    }

	return L"Unsupported aircraft!";
}


// converts a JobAircraft type to an index to the Jobs vector list
int JobHandler::JobAircraftTypeToIndex(JobAircraft job_aircraft)
{
	switch (job_aircraft)
	{
	case JobAircraft::None:
		break;
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
									// to do std::wcout << std::format(L"Unknown aircraft job type \"{0}\" @ line {1} in {2}\n", s, Line, SystemConstants::JobsFileName);
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
							// to do std::wcout << std::format(L"Invalid job list identifier \"{0}\" @ line {1} in {2}\n", s, Line, SystemConstants::JobsFileName);
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
							// to do std::wcout << std::format(L"Unknown aircraft job type \"{0}\" @ line {1} in {2}\n", s, Line, SystemConstants::JobsFileName);
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
							// to do std::wcout << std::format(L"Invalid object list identifier \"{0}\" @ line {1} in {2}\n", s, Line, SystemConstants::JobsFileName);
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
							// to do std::wcout << std::format(L"Invalid object list identifier \"{0}\" @ line {1} in {2}\n", s, Line, SystemConstants::JobsFileName);
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
                            // to do std::wcout << std::format(L"Invalid object list identifier \"{0}\" @ line {1} in {2}\n", s, Line, SystemConstants::JobsFileName);
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


void JobHandler::AddTo(JobAircraft job_aircraft_type, JobCargo job_cargo, const std::wstring item)
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


std::wstring JobHandler::Format(const std::wstring job, const std::wstring value)
{
	std::wstring output(job);

	auto pos = output.find(L"{0}");

	if (pos != std::wstring::npos)
	{
		output.replace(pos, 3, value);
	}

	return output;
}
