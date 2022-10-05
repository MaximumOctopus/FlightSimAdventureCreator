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

#pragma once


#include <string>


enum class JobAircraft { None = 0, All = 1, AllPropsTwins = 2, Airliners = 3, Jets = 4, Military = 5, Helicopters = 6 };
enum class JobCargo { None = 0, Object = 1, ObjectUnusual = 2, SLF = 3 };


class Job
{
public:

	JobAircraft Type = JobAircraft::All;				// aircraft types that it's compatible with
	std::wstring Text = L"";

	JobCargo Cargo = JobCargo::None;

	Job(JobAircraft, JobCargo, std::wstring);
};