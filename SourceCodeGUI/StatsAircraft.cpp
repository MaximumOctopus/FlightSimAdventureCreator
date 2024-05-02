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

#include "AircraftHandler.h"
#include "StatsAircraft.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmStatsAircraft *frmStatsAircraft;


extern AircraftHandler* GAircraftHandler;


__fastcall TfrmStatsAircraft::TfrmStatsAircraft(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TfrmStatsAircraft::FormCreate(TObject *Sender)
{
	std::wstring ac = std::to_wstring(GAircraftHandler->AircraftList.size()) + L" aircraft";
	std::wstring lc = std::to_wstring(GAircraftHandler->Stats.LowestCruise) + L" kts";
	std::wstring hc = std::to_wstring(GAircraftHandler->Stats.HighestCruise) + L" kts";
	std::wstring lr = std::to_wstring(GAircraftHandler->Stats.LowestRange) + L" nm";
	std::wstring hr = std::to_wstring(GAircraftHandler->Stats.HighestRange) + L" nm";

	lLowestCruise->Caption = lc.c_str();
	lHighestCruise->Caption = hc.c_str();
	lLowestRange->Caption = lr.c_str();
	lHighestRange->Caption = hr.c_str();

	lCount->Caption = ac.c_str();

	if (GAircraftHandler->AircraftList.size() != 0)
	{
		g1->Progress = ((double)GAircraftHandler->Stats.TypeCount[0] / (double)GAircraftHandler->AircraftList.size()) * (double)100;
		g2->Progress = ((double)GAircraftHandler->Stats.TypeCount[1] / (double)GAircraftHandler->AircraftList.size()) * (double)100;
		g3->Progress = ((double)GAircraftHandler->Stats.TypeCount[2] / (double)GAircraftHandler->AircraftList.size()) * (double)100;
		g4->Progress = ((double)GAircraftHandler->Stats.TypeCount[3] / (double)GAircraftHandler->AircraftList.size()) * (double)100;
		g5->Progress = ((double)GAircraftHandler->Stats.TypeCount[4] / (double)GAircraftHandler->AircraftList.size()) * (double)100;
		g6->Progress = ((double)GAircraftHandler->Stats.TypeCount[5] / (double)GAircraftHandler->AircraftList.size()) * (double)100;
		g7->Progress = ((double)GAircraftHandler->Stats.TypeCount[6] / (double)GAircraftHandler->AircraftList.size()) * (double)100;
		g8->Progress = ((double)GAircraftHandler->Stats.TypeCount[7] / (double)GAircraftHandler->AircraftList.size()) * (double)100;
	}

	lt1->Caption = GAircraftHandler->Stats.TypeCount[0];
	lt2->Caption = GAircraftHandler->Stats.TypeCount[1];
	lt3->Caption = GAircraftHandler->Stats.TypeCount[2];
	lt4->Caption = GAircraftHandler->Stats.TypeCount[3];
	lt5->Caption = GAircraftHandler->Stats.TypeCount[4];
	lt6->Caption = GAircraftHandler->Stats.TypeCount[5];
	lt7->Caption = GAircraftHandler->Stats.TypeCount[6];
	lt8->Caption = GAircraftHandler->Stats.TypeCount[7];
}
