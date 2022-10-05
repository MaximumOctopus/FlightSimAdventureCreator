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

#include "Job.h"


Job::Job(JobAircraft type, JobCargo cargo, std::wstring text)
{
	Type = type;
	Text = text;
	Cargo = cargo;
}