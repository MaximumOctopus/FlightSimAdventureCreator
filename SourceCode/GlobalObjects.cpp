//
// FlightSimAdventureCreator 1.0
//
// (c) Paul Alan Freshney 2022-2023
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
#include "RouteHandler.h"
#include "RunwayHandler.h"


extern AircraftHandler* GAircraftHandler;
extern AirportHandler* GAirportHandler;
extern Configuration* GConfiguration;
extern JobHandler* GJobHandler;
extern RouteHandler* GRouteHandler;
extern RunwayHandler* GRunwayHandler;


namespace GlobalObjects
{
	bool CreateGlobalObjects(int argc, wchar_t* argv[])
	{
		GConfiguration = new Configuration(argc, argv);

		GAirportHandler = new AirportHandler(GConfiguration->Meta.Silent, GConfiguration->Export.MSFS, GConfiguration->Export.Text, GConfiguration->Airport);

		if (!GConfiguration->Meta.OnlyNeedAirports)
		{
			GAircraftHandler = new AircraftHandler(GConfiguration->Meta.Silent,
				GConfiguration->Aircraft.Default, GConfiguration->Aircraft.Custom,
				GConfiguration->Aircraft.Type, GConfiguration->Aircraft.Airliner, GConfiguration->Aircraft.Military, GConfiguration->Aircraft.Seaplane,
				GConfiguration->Aircraft.MaxSpeed, GConfiguration->Aircraft.MinSpeed,
				GConfiguration->Aircraft.Version, GConfiguration->Aircraft.Special);

			GRunwayHandler = new RunwayHandler(GConfiguration->Meta.Silent, SystemConstants::RunwaysFileName);

			GJobHandler = new JobHandler(GConfiguration->Meta.Silent);

			if (GConfiguration->Route.RealWorld)
			{
				GRouteHandler = new RouteHandler(SystemConstants::RoutesFileName, 
					GConfiguration->Meta.Silent, GConfiguration->Meta.ExtraDetail,
					GConfiguration->Export.MSFS, GConfiguration->Export.Text);
			}

			return GAirportHandler->Loaded && GRunwayHandler->Loaded;
		}

		return GAirportHandler->Loaded;
	}


	void FreeGlobalObjects()
	{
		if (GRouteHandler != nullptr)
		{
			delete GRouteHandler;
		}

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