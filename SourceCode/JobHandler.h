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
#include <vector>

#include "AircraftConstants.h"
#include "Job.h"


static const int kJobAircraftTypes = 5;
static const int kAddToAll = 99;


class JobHandler
{
	bool Loaded = false;
	bool Silent = false;

	[[nodiscard]] bool LoadJobs(const std::wstring);

	[[nodiscard]] int JobAircraftTypeToIndex(JobAircraft);

	void AddTo(JobAircraft, JobCargo, std::wstring);

public:

	std::vector<Job> Jobs[kJobAircraftTypes];
	std::vector<std::wstring> ObjectsUnusual;
	std::vector<std::wstring> ObjectsSmall;
	std::vector<std::wstring> ObjectsLarge;
	std::vector<std::wstring> SLF;

	JobHandler(bool);

	std::wstring GetJob(AircraftConstants::AircraftType, bool, bool);
};