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

#include <algorithm>
#include <vcl.h>
#pragma hdrstop

#include "AirportHandler.h"
#include "Configuration.h"
#include "Favourites.h"
#include "Utility.h"
#include "WindowsUtility.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmFavourites *frmFavourites;

extern AirportHandler* GAirportHandler;
extern Configuration* GConfiguration;


__fastcall TfrmFavourites::TfrmFavourites(TComponent* Owner)
	: TForm(Owner)
{
	for (int t = 0; t < GConfiguration->Favourites.size(); t++)
	{
		lbFavourites->Items->Add(GConfiguration->Favourites[t].c_str());
    }
}


void __fastcall TfrmFavourites::bAddClick(TObject *Sender)
{
	bool found = false;
	std::wstring new_airport = eICAO->Text.c_str();

	std::transform(new_airport.begin(), new_airport.end(), new_airport.begin(), ::toupper);

	for (int t = 0; t < lbFavourites->Items->Count; t++)
	{
		if (new_airport == lbFavourites->Items->Strings[t].c_str())
		{
			found = true;
			break;
		}
	}

	if (!found)
	{
		lbFavourites->Items->Add(new_airport.c_str());

		ModifiedFavourites = true;
	}
	else
	{
		Application->MessageBox(L"Specified airport ICAO is already in favourites!", L"Favourites", MB_OK);
	}
}


void __fastcall TfrmFavourites::bDeleteClick(TObject *Sender)
{
	if (lbFavourites->ItemIndex != -1)
	{
		lbFavourites->Items->Delete(lbFavourites->ItemIndex);

		ModifiedFavourites = true;
    }
}


void __fastcall TfrmFavourites::bOKClick(TObject *Sender)
{
	if (ModifiedFavourites)
	{
		Caption = "a";

		GConfiguration->Favourites.clear();

		Caption = "b";


		for (int t = 0; t < lbFavourites->Items->Count; t++)
		{
			Caption = t;

			GConfiguration->Favourites.push_back(lbFavourites->Items->Strings[t].c_str());
		}

        GConfiguration->FavouritesHaveChanged();
	}
}


void __fastcall TfrmFavourites::lbFavouritesClick(TObject *Sender)
{
	PopulateFromSelected();
}


void TfrmFavourites::PopulateFromSelected()
{
	if (lbFavourites->Items->Count != 0)
	{
		int i = GAirportHandler->GetIndexFromICAOFullList(lbFavourites->Items->Strings[lbFavourites->ItemIndex].c_str());

		if (i != -1)
		{
			std::wstring country(Utility::GetCountryFromShortCode(GAirportHandler->Airports[i].Country) + L" (" + GAirportHandler->Airports[i].Country + L")");
			std::wstring continent(Utility::GetContinentFromShortCode(GAirportHandler->Airports[i].Continent) + L" (" + GAirportHandler->Airports[i].Continent + L")");

			lName->Caption = GAirportHandler->Airports[i].Name.c_str();
			lContinent->Caption = continent.c_str();
			lCountry->Caption = country.c_str();
			lRegion->Caption = GAirportHandler->Airports[i].Region.c_str();

			_latitude = GAirportHandler->Airports[i].Latitude;
			_longitude = GAirportHandler->Airports[i].Longitude;

			return;
		}
	}

	lName->Caption = "";
	lContinent->Caption = "";
	lCountry->Caption = "";
	lRegion->Caption = "";

	_latitude = L"";
	_longitude = L"";
}


void __fastcall TfrmFavourites::Button1Click(TObject *Sender)
{
	if (!_latitude.empty() && !_longitude.empty())
	{
		WindowsUtility::OpenWebsite(L"https://maps.google.com/?q=" + _latitude + L"," + _longitude);
    }
}
