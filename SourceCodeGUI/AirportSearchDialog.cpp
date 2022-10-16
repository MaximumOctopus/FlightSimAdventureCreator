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

#include <vcl.h>
#pragma hdrstop

#include "AirportSearchDialog.h"
#include "Locations.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAirportSearchDialog *frmAirportSearchDialog;

__fastcall TfrmAirportSearchDialog::TfrmAirportSearchDialog(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TfrmAirportSearchDialog::FormCreate(TObject *Sender)
{
	cbContinent->Items->Add(L"All");

	for (int t = 0; t < Location::ContinentCount; t++)
	{
		cbContinent->Items->Add(Location::ContinentNames[t].c_str());
	}

	cbContinent->ItemIndex = 0;

	cbCountry->Items->Add(L"All");

	for (int t = 0; t < Location::ISOCountriesCount; t++)
	{
		cbCountry->Items->Add(Location::ISOCountries[t][1].c_str());
	}

	cbCountry->ItemIndex = 0;
}


void __fastcall TfrmAirportSearchDialog::bSearchClick(TObject *Sender)
{
    // to do
}
