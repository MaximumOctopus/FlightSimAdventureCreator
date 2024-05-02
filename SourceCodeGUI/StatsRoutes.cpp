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

#include "RouteHandler.h"
#include "StatsRoutes.h"

#pragma package(smart_init)
#pragma link "pies"
#pragma resource "*.dfm"

TfrmStatsRoutes *frmStatsRoutes;


extern RouteHandler* GRouteHandler;


__fastcall TfrmStatsRoutes::TfrmStatsRoutes(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TfrmStatsRoutes::FormCreate(TObject *Sender)
{
	std::wstring c = std::to_wstring(GRouteHandler->Routes.size()) + L" routes";
	std::wstring s = std::to_wstring(GRouteHandler->Stats.Shortest) + L" nm";
	std::wstring l = std::to_wstring(GRouteHandler->Stats.Longest) + L" nm";

	std::wstring t = std::to_wstring(GRouteHandler->Stats.Total) + L" nm";
	std::wstring a = std::to_wstring(GRouteHandler->Stats.Average) + L" nm";

	lCount->Caption = c.c_str();
	lShortest->Caption = s.c_str();
	lLongest->Caption = l.c_str();

	lTotal->Caption = t.c_str();
	lAverage->Caption = a.c_str();

	lFrom->Caption = GRouteHandler->FromCache.size();
	lTo->Caption = GRouteHandler->ToCache.size();

	if (GRouteHandler->Routes.size() != 0)
	{
		g1->Progress = ((double)GRouteHandler->Stats.Continents[0] / (double)GRouteHandler->Routes.size()) * (double)100;
		g2->Progress = ((double)GRouteHandler->Stats.Continents[1] / (double)GRouteHandler->Routes.size()) * (double)100;
		g3->Progress = ((double)GRouteHandler->Stats.Continents[2] / (double)GRouteHandler->Routes.size()) * (double)100;
		g4->Progress = ((double)GRouteHandler->Stats.Continents[3] / (double)GRouteHandler->Routes.size()) * (double)100;
		g5->Progress = ((double)GRouteHandler->Stats.Continents[4] / (double)GRouteHandler->Routes.size()) * (double)100;
		g6->Progress = ((double)GRouteHandler->Stats.Continents[5] / (double)GRouteHandler->Routes.size()) * (double)100;
		g7->Progress = ((double)GRouteHandler->Stats.Continents[6] / (double)GRouteHandler->Routes.size()) * (double)100;
	}

	lc1->Caption = GRouteHandler->Stats.Continents[0];
	lc2->Caption = GRouteHandler->Stats.Continents[1];
	lc3->Caption = GRouteHandler->Stats.Continents[2];
	lc4->Caption = GRouteHandler->Stats.Continents[3];
	lc5->Caption = GRouteHandler->Stats.Continents[4];
	lc6->Caption = GRouteHandler->Stats.Continents[5];
	lc7->Caption = GRouteHandler->Stats.Continents[6];
}

