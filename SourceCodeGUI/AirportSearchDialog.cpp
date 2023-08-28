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
#include <fstream>
#include <iostream>
#include <vcl.h>
#pragma hdrstop

#include "AirportHandler.h"
#include "AirportSearchDialog.h"
#include "Formatting.h"
#include "Locations.h"
#include "Utility.h"
#include "WindowsUtility.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAirportSearchDialog *frmAirportSearchDialog;


extern AirportHandler* GAirportHandler;


__fastcall TfrmAirportSearchDialog::TfrmAirportSearchDialog(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TfrmAirportSearchDialog::FormCreate(TObject *Sender)
{
	sgResults->Cells[0][0] = L"id";
	sgResults->Cells[1][0] = L"Ident";
	sgResults->Cells[2][0] = L"Name";
	sgResults->Cells[3][0] = L"Cntnt";
	sgResults->Cells[4][0] = L"Cntry";
	sgResults->Cells[5][0] = L"Region";
	sgResults->Cells[6][0] = L"Lat";
	sgResults->Cells[7][0] = L"Long";
	sgResults->Cells[8][0] = L"Type";
	sgResults->Cells[9][0] = L"";

	sgResults->ColAlignments[9] = taRightJustify;

	cbContinent->Items->Add(L"All");

	for (int t = 0; t < Location::ContinentCount; t++)
	{
		cbContinent->Items->Add(Location::ContinentNames[t].c_str());
	}

	cbContinent->ItemIndex = 0;

	cbCountry->Items->Add(L"All");

	for (int t = 0; t < Location::ISOCountriesCount; t++)
	{
		cbCountry->Items->Add(Location::ISOCountriesOrdered[t][0].c_str());
	}

	cbCountry->ItemIndex = 0;
}


void __fastcall TfrmAirportSearchDialog::FormShow(TObject *Sender)
{
	SelectedICAO = L"";
}


void __fastcall TfrmAirportSearchDialog::bSearchClick(TObject *Sender)
{
	AirportSearchFilter asf;

	if (eSearch->Text != "")
	{
		asf.SearchText = eSearch->Text.c_str();

		std::transform(asf.SearchText.begin(), asf.SearchText.end(), asf.SearchText.begin(), ::tolower);
	}

	if (cbContinent->ItemIndex > 0)
	{
		asf.Continent = Location::ContinentShort[cbContinent->ItemIndex - 1];
	}

	if (cbCountry->ItemIndex > 0)
	{
		asf.Country = Location::ISOCountriesOrdered[cbCountry->ItemIndex - 1][1];
	}

	asf.SmallAirports = cbSmallAirports->Checked;
	asf.MediumAirports = cbMediumAirports->Checked;
	asf.LargeAirports = cbLargeAirports->Checked;
	asf.Heliports = cbHeliports->Checked;
	asf.SeaplaneBases = cbSeaplaneBases->Checked;

	asf.WithinRange = cbWithinRange->Checked;

	if (asf.WithinRange)
	{
		asf.Range = eRange->Text.ToIntDef(100);
		asf.Airport = eICAO->Text.c_str();

		asf.WithinRange = GAirportHandler->IsValidAirport(asf.Airport);

		if (asf.WithinRange)
		{
			sgResults->Cells[9][0] = "nm";
		}
		else
		{
            sgResults->Cells[9][0] = "";
		}

		cbWithinRange->Checked = asf.WithinRange;
    }

	int count = GAirportHandler->Search(asf);

	if (count != 0)
	{
		sgResults->RowCount = count + 1;

		for (int t = 0; t < count; t++)
		{
			sgResults->Cells[0][t + 1] = t;
			sgResults->Cells[1][t + 1] = GAirportHandler->SearchResults[t].Ident.c_str();
			sgResults->Cells[2][t + 1] = GAirportHandler->SearchResults[t].Name.c_str();
			sgResults->Cells[3][t + 1] = GAirportHandler->SearchResults[t].Continent.c_str();
			sgResults->Cells[4][t + 1] = GAirportHandler->SearchResults[t].Country.c_str();
			sgResults->Cells[5][t + 1] = GAirportHandler->SearchResults[t].Region.c_str();
			sgResults->Cells[6][t + 1] = GAirportHandler->SearchResults[t].Latitude.c_str();
			sgResults->Cells[7][t + 1] = GAirportHandler->SearchResults[t].Longitude.c_str();
			sgResults->Cells[8][t + 1] = Utility::GetAirportTypeDisplay(GAirportHandler->SearchResults[t].Type).c_str();

			if (asf.WithinRange)
			{
				sgResults->Cells[9][t + 1] = GAirportHandler->SearchResults[t].Distance;
			}
        }
	}
	else
	{
		sgResults->RowCount = 2;

		sgResults->Cells[0][1] = "";
		sgResults->Cells[1][1] = "";
		sgResults->Cells[2][1] = "No airports found :(";
		sgResults->Cells[3][1] = "";
		sgResults->Cells[4][1] = "";
		sgResults->Cells[5][1] = "";
		sgResults->Cells[6][1] = "";
		sgResults->Cells[7][1] = "";
		sgResults->Cells[8][1] = "";
		sgResults->Cells[9][1] = "";
	}

	std::wstring status = L"Found " + std::to_wstring(count) + L" matching airports.";

    sbSearch->SimpleText = status.c_str();
}


void __fastcall TfrmAirportSearchDialog::eSearchKeyPress(TObject *Sender, System::WideChar &Key)

{
	if (Key == VK_RETURN)
	{
        bSearchClick(nullptr);
	}
}


void __fastcall TfrmAirportSearchDialog::sgResultsDblClick(TObject *Sender)
{
	if (sgResults->Selection.Top > 0 && GAirportHandler->SearchResults.size() != 0)
	{
		Airport start = GAirportHandler->SearchResults[sgResults->Selection.Top - 1];

		WindowsUtility::OpenWebsite(L"https://maps.google.com/?q=" + start.Latitude + L"," + start.Longitude);
	}
}


void __fastcall TfrmAirportSearchDialog::bSelectClick(TObject *Sender)
{
	if (sgResults->Selection.Top > 0 && GAirportHandler->SearchResults.size() != 0)
	{
		SelectedICAO = GAirportHandler->SearchResults[sgResults->Selection.Top - 1].Ident;

		ModalResult = mrOk;
	}
}


void TfrmAirportSearchDialog::SetSelectionMode(bool mode)
{
	bSelect->Visible = mode;
}


void __fastcall TfrmAirportSearchDialog::bSaveClick(TObject *Sender)
{
	sdSearch->Filter = "Search Results|*.csv";
	sdSearch->DefaultExt = ".csv";

	if (sdSearch->Execute())
	{
		std::wstring file_name = sdSearch->FileName.c_str();

		std::ofstream ofile(file_name);

		if (ofile)
		{
			ofile << Formatting::to_utf8(L"//icao,name,continent,country,region,latitude,longitude,type\n");

			for (int t = 0; t < GAirportHandler->SearchResults.size(); t++)
			{
				std::wstring line(GAirportHandler->SearchResults[t].Ident + L',' +
					GAirportHandler->SearchResults[t].Name + L',' +
					GAirportHandler->SearchResults[t].Continent + L',' +
					GAirportHandler->SearchResults[t].Country + L',' +
					GAirportHandler->SearchResults[t].Region + L',' +
					GAirportHandler->SearchResults[t].Latitude + L',' +
					GAirportHandler->SearchResults[t].Longitude + L',' +
					Utility::GetAirportTypeDisplay(GAirportHandler->SearchResults[t].Type));

				ofile << Formatting::to_utf8(line + L'\n');
			}

			ofile.close();
		}
	}
}
