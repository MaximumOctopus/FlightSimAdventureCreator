//
// FlightSimAdventureCreator 1.0
//
// (c) Paul Alan Freshney 2023-2024
//
// paul@freshney.org
// 
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
// 
// 

#include "Job.h"


Job::Job(JobAircraft type, JobCargo cargo, const std::wstring text)
{
	Type = type;
	Text = text;
	Cargo = cargo;
}