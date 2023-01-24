//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AirportHandler.h"
#include "Distance.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

extern AirportHandler* GAirportHandler;

TfrmDistanceCalc *frmDistanceCalc;


__fastcall TfrmDistanceCalc::TfrmDistanceCalc(TComponent* Owner)
	: TForm(Owner)
{
	lError->Caption = "";
}

void __fastcall TfrmDistanceCalc::bCalculateClick(TObject *Sender)
{
	double dnm = GAirportHandler->DistanceBetweenTwoAirports(eFromICAO->Text.c_str(), eToICAO->Text.c_str());

	if (dnm >= 0)
	{
		double dkm = dnm * 1.852; // convert to km
		double dmi = dnm * 1.151078; // convert to miles

		lDistanceNM->Caption    = static_cast<int>(dnm);
		lDistanceKM->Caption    = static_cast<int>(dkm);
		lDistanceMiles->Caption = static_cast<int>(dmi);
	}
	else
	{
		lError->Caption = "journey could not be calculated :(";
	}
}

void __fastcall TfrmDistanceCalc::eFromICAOKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key != 13)
	{
		return;
    }

	if (!eFromICAO->Text.IsEmpty() && !eToICAO->Text.IsEmpty())
	{
		bCalculateClick(NULL);
	}
}
