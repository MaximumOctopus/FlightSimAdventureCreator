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

#include "AirportHandler.h"
#include "StatsAirports.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmStatsAirports *frmStatsAirports;


extern AirportHandler* GAirportHandler;


__fastcall TfrmStatsAirports::TfrmStatsAirports(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TfrmStatsAirports::FormCreate(TObject *Sender)
{
	std::wstring l = std::to_wstring(GAirportHandler->Stats.ElevationLowest) + L" ft";
	std::wstring h = std::to_wstring(GAirportHandler->Stats.ElevationHighest) + L" ft";
	std::wstring c = std::to_wstring(GAirportHandler->Airports.size()) + L" airports";

	lLowest->Caption = l.c_str();
	lHighest->Caption = h.c_str();
    lCount->Caption = c.c_str();

	if (GAirportHandler->Airports.size() != 0)
	{
		gc1->Progress = ((double)GAirportHandler->Stats.Continents[0] / (double)GAirportHandler->Airports.size()) * (double)100;
		gc2->Progress = ((double)GAirportHandler->Stats.Continents[1] / (double)GAirportHandler->Airports.size()) * (double)100;
		gc3->Progress = ((double)GAirportHandler->Stats.Continents[2] / (double)GAirportHandler->Airports.size()) * (double)100;
		gc4->Progress = ((double)GAirportHandler->Stats.Continents[3] / (double)GAirportHandler->Airports.size()) * (double)100;
		gc5->Progress = ((double)GAirportHandler->Stats.Continents[4] / (double)GAirportHandler->Airports.size()) * (double)100;
		gc6->Progress = ((double)GAirportHandler->Stats.Continents[5] / (double)GAirportHandler->Airports.size()) * (double)100;
		gc7->Progress = ((double)GAirportHandler->Stats.Continents[6] / (double)GAirportHandler->Airports.size()) * (double)100;

		gt1->Progress = ((double)GAirportHandler->Stats.TypeCount[0] / (double)GAirportHandler->Airports.size()) * (double)100;
		gt2->Progress = ((double)GAirportHandler->Stats.TypeCount[1] / (double)GAirportHandler->Airports.size()) * (double)100;
		gt3->Progress = ((double)GAirportHandler->Stats.TypeCount[2] / (double)GAirportHandler->Airports.size()) * (double)100;
		gt4->Progress = ((double)GAirportHandler->Stats.TypeCount[3] / (double)GAirportHandler->Airports.size()) * (double)100;
		gt5->Progress = ((double)GAirportHandler->Stats.TypeCount[4] / (double)GAirportHandler->Airports.size()) * (double)100;
	}

	lc1->Caption = GAirportHandler->Stats.Continents[0];
	lc2->Caption = GAirportHandler->Stats.Continents[1];
	lc3->Caption = GAirportHandler->Stats.Continents[2];
	lc4->Caption = GAirportHandler->Stats.Continents[3];
	lc5->Caption = GAirportHandler->Stats.Continents[4];
	lc6->Caption = GAirportHandler->Stats.Continents[5];
	lc7->Caption = GAirportHandler->Stats.Continents[6];

	lt1->Caption = GAirportHandler->Stats.TypeCount[0];
	lt2->Caption = GAirportHandler->Stats.TypeCount[1];
	lt3->Caption = GAirportHandler->Stats.TypeCount[2];
	lt4->Caption = GAirportHandler->Stats.TypeCount[3];
	lt5->Caption = GAirportHandler->Stats.TypeCount[4];
}
