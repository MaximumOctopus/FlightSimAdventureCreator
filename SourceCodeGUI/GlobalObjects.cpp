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

#include "AircraftHandler.h"
#include "AirlineHandler.h"
#include "AirportHandler.h"
#include "Configuration.h"
#include "FlightHandler.h"
#include "GlobalObjects.h"
#include "JobHandler.h"
#include "RouteHandler.h"
#include "RunwayHandler.h"


extern AircraftHandler* GAircraftHandler;
extern AirlineHandler* GAirlineHandler;
extern AirportHandler* GAirportHandler;
extern Configuration* GConfiguration;
extern FlightHandler* GFlightHandler;
extern JobHandler* GJobHandler;
extern RouteHandler* GRouteHandler;
extern RunwayHandler* GRunwayHandler;


namespace GlobalObjects
{
	bool CreateGlobalObjects()
	{
		// config to do, load from ini in root
		GConfiguration = new Configuration();

		GAirlineHandler = new AirlineHandler();

		GAirportHandler = new AirportHandler();

		GAircraftHandler = new AircraftHandler();

		GFlightHandler = new FlightHandler();

		GRouteHandler = new RouteHandler(SystemConstants::RoutesFileName);

		GRunwayHandler = new RunwayHandler(SystemConstants::RunwaysFileName);

		GJobHandler = new JobHandler();

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

		if (GRouteHandler != nullptr)
		{
			delete GRouteHandler;
		}

		if (GFlightHandler != nullptr)
		{
			delete GFlightHandler;
		}

		if (GAirportHandler != nullptr)
		{
			delete GAirportHandler;
		}

		if (GAircraftHandler != nullptr)
		{
			delete GAircraftHandler;
		}

		if (GAirlineHandler != nullptr)
		{
            delete GAirlineHandler;
        }

		if (GConfiguration != nullptr)
		{
			delete GConfiguration;
        }
	}
};