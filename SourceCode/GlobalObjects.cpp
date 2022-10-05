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

#include "Configuration.h"
#include "AircraftHandler.h"
#include "AirportHandler.h"
#include "GlobalObjects.h"
#include "JobHandler.h"
#include "RunwayHandler.h"


extern Configuration* GConfiguration;
extern AircraftHandler* GAircraftHandler;
extern AirportHandler* GAirportHandler;
extern RunwayHandler* GRunwayHandler;
extern JobHandler* GJobHandler;

namespace GlobalObjects
{
	bool CreateGlobalObjects(int argc, wchar_t* argv[])
	{
		GConfiguration = new Configuration(argc, argv);

		GAircraftHandler = new AircraftHandler(GConfiguration->Meta.Silent,
			                                   GConfiguration->Aircraft.Default, GConfiguration->Aircraft.Custom,
											   GConfiguration->Aircraft.Type, GConfiguration->Aircraft.Airliner, GConfiguration->Aircraft.Military,
											   GConfiguration->Aircraft.MaxSpeed, GConfiguration->Aircraft.MinSpeed,
											   GConfiguration->Aircraft.Version, GConfiguration->Aircraft.Special);

		GAirportHandler = new AirportHandler(GConfiguration->Meta.Silent, GConfiguration->Export.MSFS, GConfiguration->Airport);

		GRunwayHandler = new RunwayHandler(GConfiguration->Meta.Silent);

		GJobHandler = new JobHandler(GConfiguration->Meta.Silent);

		return GAirportHandler->Loaded && GRunwayHandler->Loaded;
	}


	void FreeGlobalObjects()
	{
		if (GJobHandler != nullptr)
		{
			delete GJobHandler;
		}

		if (GRunwayHandler != nullptr)
		{
			delete GRunwayHandler;
		}

		if (GAirportHandler != nullptr)
		{
			delete GAirportHandler;
		}

		if (GAircraftHandler != nullptr)
		{
			delete GAircraftHandler;
		}

		if (GConfiguration != nullptr)
		{
			delete GConfiguration;
		}
	}
};