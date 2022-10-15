//
// FlightSimAdventureCreator 1.0 (GUI Version)
//
// (c) Paul Alan Freshney 2022
//
// paul@freshney.org
//
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
//
//

#include "AircraftHandler.h"
#include "AirportHandler.h"
#include "Configuration.h"
#include "GlobalObjects.h"
//#include "JobHandler.h"
#include "RouteHandler.h"
#include "RunwayHandler.h"


extern AircraftHandler* GAircraftHandler;
extern AirportHandler* GAirportHandler;
extern Configuration* GConfiguration;
extern RouteHandler* GRouteHandler;
extern RunwayHandler* GRunwayHandler;
//extern JobHandler* GJobHandler;


namespace GlobalObjects
{
	bool CreateGlobalObjects()
	{
		// config to do, load from ini in root
		GConfiguration = new Configuration();

		GAirportHandler = new AirportHandler();

		GAircraftHandler = new AircraftHandler();

		GRouteHandler = new RouteHandler();

		GRunwayHandler = new RunwayHandler(SystemConstants::RunwaysFileName);

		   //	GJobHandler = new JobHandler(GConfiguration->Meta.Silent);

		  //	return GAirportHandler->Loaded && GRunwayHandler->Loaded;
	   //	}

		return true;
	}


	void FreeGlobalObjects()
	{
	  /*	if (GJobHandler != nullptr)
		{
			delete GJobHandler;
		}              */

		if (GRunwayHandler != nullptr)
		{
			delete GRunwayHandler;
		}

		if (GRouteHandler != nullptr)
		{
			delete GRouteHandler;
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