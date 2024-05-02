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

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("RouteBrowser.cpp", frmRouteBrowser);
USEFORM("main.cpp", frmMain);
USEFORM("StatsRoutes.cpp", frmStatsRoutes);
USEFORM("StatsAirports.cpp", frmStatsAirports);
USEFORM("StatsAircraft.cpp", frmStatsAircraft);
USEFORM("About.cpp", frmAbout);
USEFORM("AirportSearchDialog.cpp", frmAirportSearchDialog);
USEFORM("Favourites.cpp", frmFavourites);
USEFORM("Distance.cpp", frmDistanceCalc);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TfrmMain), &frmMain);
		Application->CreateForm(__classid(TfrmAirportSearchDialog), &frmAirportSearchDialog);
		Application->CreateForm(__classid(TfrmAbout), &frmAbout);
		Application->CreateForm(__classid(TfrmFavourites), &frmFavourites);
		Application->CreateForm(__classid(TfrmDistanceCalc), &frmDistanceCalc);
		Application->CreateForm(__classid(TfrmRouteBrowser), &frmRouteBrowser);
		Application->CreateForm(__classid(TfrmStatsRoutes), &frmStatsRoutes);
		Application->CreateForm(__classid(TfrmStatsAirports), &frmStatsAirports);
		Application->CreateForm(__classid(TfrmStatsAircraft), &frmStatsAircraft);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
