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

#include "AirportSearchDialog.h"

#include "AirlineHandler.h"
#include "AirportHandler.h"
#include "Configuration.h"
#include "Locations.h"
#include "RouteBrowser.h"
#include "RouteHandler.h"
#include "Utility.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmRouteBrowser *frmRouteBrowser;

extern AirlineHandler* GAirlineHandler;
extern AirportHandler* GAirportHandler;
extern Configuration* GConfiguration;
extern RouteHandler* GRouteHandler;


__fastcall TfrmRouteBrowser::TfrmRouteBrowser(TComponent* Owner)
	: TForm(Owner)
{
	sgRoutes->ColAlignments[4] = taRightJustify;

	sgRoutes->Cells[0][0] = L"Airline";
	sgRoutes->Cells[1][0] = L"Route";
	sgRoutes->Cells[2][0] = L"From";
	sgRoutes->Cells[3][0] = L"To";
	sgRoutes->Cells[4][0] = L"Length";
}


void __fastcall TfrmRouteBrowser::FormCreate(TObject *Sender)
{
	fh = new FlightHandler();

	eMin->Text = MinDistance;
    eMax->Text = MaxDistance;

	UpdateLists();
}


void __fastcall TfrmRouteBrowser::FormDestroy(TObject *Sender)
{
    delete fh;
}


void __fastcall TfrmRouteBrowser::eICAOKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if (Key == 13)
	{
		if (eICAO->Text != L"")
		{
			bSearchFromICAOClick(NULL);
		}
	}
}


void TfrmRouteBrowser::UpdateLists()
{
	cbCountryList->Clear();

	for (int t = 0; t < Location::ISOCountriesCount; t++)
	{
		cbCountryList->Items->Add(Location::ISOCountriesOrdered[t][0].c_str());
	}

	cbCountryList->ItemIndex = 0;

	cbAirlineList->Clear();

	for (int t = 0; t < GAirlineHandler->Airlines.size(); t++)
	{
		cbAirlineList->Items->Add(GAirlineHandler->Airlines[t].Name.c_str());
	}

	cbAirlineList->ItemIndex = 0;
}


void __fastcall TfrmRouteBrowser::bSearchFromICAOClick(TObject *Sender)
{
	if (!GAirportHandler->IsValidAirport(eICAO->Text.c_str()))
	{
		lInvalid->Visible = true;

		return;
	}
	else
	{
		lInvalid->Visible = false;
	}

	fh->Flights.clear();

    ClearRouteList();

	for (int t = 0; t < GRouteHandler->Routes.size(); t++)
	{
		bool found = false;
		bool cancontinue = true;

		if (cbAirlineFilter->Checked)                                           // airline
		{
			if (GRouteHandler->Routes[t].Airline != cbAirlineList->Text.c_str())
			{
				cancontinue = false;
            }
		}

		if  (cbRouteType->ItemIndex == 1)                                       // internal only
		{
			if (GRouteHandler->Routes[t].FromCountry != GRouteHandler->Routes[t].ToCountry)
			{
				cancontinue = false;
			}
		}

		if  (cbRouteType->ItemIndex == 2)                                       // external only
		{
			if (GRouteHandler->Routes[t].FromCountry == GRouteHandler->Routes[t].ToCountry)
			{
				cancontinue = false;
			}
		}

		if (cancontinue)
		{
			if (rbFromICAO->Checked)
			{
				if (GRouteHandler->Routes[t].FromICAO == eICAO->Text.c_str())   // ICAO
				{
					if (GRouteHandler->Routes[t].Distance > MinDistance &&      // distance
						GRouteHandler->Routes[t].Distance < MaxDistance)
					{
						if (cbCountryFilter->Checked)    // country
						{
							if (GRouteHandler->Routes[t].ToCountry == Location::ISOCountriesOrdered[cbCountryList->ItemIndex][1].c_str())
							{
								found = true;
							}
						}
						else
						{
							found = true;
						}
					}
				}
			}
			else
			{
				if (GRouteHandler->Routes[t].ToICAO == eICAO->Text.c_str())     // ICAO
				{
					if (GRouteHandler->Routes[t].Distance > MinDistance &&      // distance
						GRouteHandler->Routes[t].Distance < MaxDistance)
					{
						if (cbCountryFilter->Checked)    						// country
						{
							if (GRouteHandler->Routes[t].FromCountry == Location::ISOCountriesOrdered[cbCountryList->ItemIndex][1].c_str())
							{
								found = true;
							}
						}
						else
						{
							found = true;
						}
					}
				}
			}
		}

		if (found)
		{
			int i = sgRoutes->RowCount - 1;

			std::wstring d = std::to_wstring((int)GRouteHandler->Routes[t].Distance) + L" nm";
			std::wstring r = GRouteHandler->Routes[t].FromICAO + L" -> " + GRouteHandler->Routes[t].ToICAO;

			sgRoutes->Cells[0][i] = GRouteHandler->Routes[t].Airline.c_str();
			sgRoutes->Cells[1][i] = r.c_str();
			sgRoutes->Cells[2][i] = GRouteHandler->Routes[t].FromCountry.c_str();
			sgRoutes->Cells[3][i] = GRouteHandler->Routes[t].ToCountry.c_str();
			sgRoutes->Cells[4][i] = d.c_str();

			sgRoutes->RowCount++;

			Flight f(GRouteHandler->Routes[t].FromICAO, GRouteHandler->Routes[t].ToICAO, GRouteHandler->Routes[t].Distance);

            fh->Flights.push_back(f);
		}

		std::wstring status(L"Found " + std::to_wstring(sgRoutes->RowCount - 2) + L" routes");

		lStatus->Caption = status.c_str();

	}
}


void __fastcall TfrmRouteBrowser::tbMinChange(TObject *Sender)
{
	eMin->Text = tbMin->Position * 100;

	MinDistance = tbMin->Position * 100;
}


void __fastcall TfrmRouteBrowser::tbMaxChange(TObject *Sender)
{
	eMax->Text = tbMax->Position * 100;

	MaxDistance = tbMax->Position * 100;
}


void TfrmRouteBrowser::ClearRouteList()
{
	sgRoutes->RowCount = 2;

	sgRoutes->Cells[0][1] = L"";
	sgRoutes->Cells[1][1] = L"";
	sgRoutes->Cells[2][1] = L"";
	sgRoutes->Cells[3][1] = L"";
	sgRoutes->Cells[4][1] = L"";
}


void __fastcall TfrmRouteBrowser::rbFromICAOClick(TObject *Sender)
{
	lDestinationCountry->Caption = L"Destination county";
}


void __fastcall TfrmRouteBrowser::rbToICAOClick(TObject *Sender)
{
	lDestinationCountry->Caption = L"Source county";
}


void __fastcall TfrmRouteBrowser::cbCountryFilterClick(TObject *Sender)
{
	cbCountryList->Enabled = cbCountryFilter->Checked;

	if (cbCountryFilter->Checked && cbRouteType->ItemIndex != 0)
	{
		cbRouteType->ItemIndex = 0;
	}
}


void __fastcall TfrmRouteBrowser::cbAirlineFilterClick(TObject *Sender)
{
	cbAirlineList->Enabled = cbAirlineFilter->Checked;
}


void __fastcall TfrmRouteBrowser::eICAOExit(TObject *Sender)
{
	if (eICAO->Text != "")
	{
		if (rbFromICAO->Checked)
		{
			if (!GRouteHandler->IsValidFromAirport(eICAO->Text.c_str()))
			{
				eICAO->Text = "";

				lInvalid->Visible = true;
			}
			else
			{
				lInvalid->Visible = false;
            }
		}
		else
		{
			if (!GRouteHandler->IsValidToAirport(eICAO->Text.c_str()))
			{
				eICAO->Text = "";

				lInvalid->Visible = true;
			}
			else
			{
				lInvalid->Visible = false;
			}
		}
	}
}


void __fastcall TfrmRouteBrowser::cbRouteTypeChange(TObject *Sender)
{
	if (cbRouteType->ItemIndex != 0)
	{
		cbCountryFilter->Checked = false;

		cbCountryFilterClick(nullptr);
	}
}


void __fastcall TfrmRouteBrowser::Select1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;
	TPopupMenu *pm = (TPopupMenu*)mi->GetParentMenu();
	TEdit *edit = (TEdit*)pm->PopupComponent;

	frmAirportSearchDialog->SetSelectionMode(true);

	if (frmAirportSearchDialog->ShowModal() == mrOk)
	{
		edit->Text = frmAirportSearchDialog->SelectedICAO.c_str();

		eICAOExit(nullptr);
	}
}


void __fastcall TfrmRouteBrowser::miUseHomeAirportClick(TObject *Sender)
{
	if (GConfiguration->System.HomeAirport != L"")
	{
		TMenuItem *mi = (TMenuItem*)Sender;
		TPopupMenu *pm = (TPopupMenu*)mi->GetParentMenu();
		TEdit *edit = (TEdit*)pm->PopupComponent;

		edit->Text = GConfiguration->System.HomeAirport.c_str();
	}
}


void __fastcall TfrmRouteBrowser::SetasHomeairport1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;
	TPopupMenu *pm = (TPopupMenu*)mi->GetParentMenu();
	TEdit *edit = (TEdit*)pm->PopupComponent;

	if (!edit->Text.IsEmpty())
	{
		GConfiguration->System.HomeAirport = edit->Text.c_str();
	}
}


void __fastcall TfrmRouteBrowser::BarraAirport1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;
	TPopupMenu *pm = (TPopupMenu*)mi->GetParentMenu();
	TEdit *edit = (TEdit*)pm->PopupComponent;

	if (mi->Tag < Location::HandCraftedICAOCount)
	{
     	edit->Text = Location::HandCraftedICAO[mi->Tag].c_str();

		if (!edit->Text.IsEmpty())
		{
			eICAOExit(nullptr);
		}
	}
}


void __fastcall TfrmRouteBrowser::bExportSelectedClick(TObject *Sender)
{
	if (sgRoutes->Selection.Top > 0 && fh->Flights.size() != 0)
	{
		sdMain->Filter = "MSFS 2020 plan files|*.pln";
		sdMain->DefaultExt = ".pln";
		sdMain->FileName = fh->Flights[sgRoutes->Selection.Top - 1].GetMSFSFileName().c_str();

		if (sdMain->Execute())
		{
			std::wstring file_name = sdMain->FileName.c_str();

			fh->ExportToMSFS(file_name, sgRoutes->Selection.Top);
		}
	}
}


void __fastcall TfrmRouteBrowser::bExportSelectedTextClick(TObject *Sender)
{
	if (sgRoutes->Selection.Top > 0 && fh->Flights.size() != 0)
	{
		sdMain->Filter = "Itinerary text files|*.txt";
		sdMain->DefaultExt = ".txt";
		sdMain->FileName = fh->Flights[sgRoutes->Selection.Top - 1].GetTextFileName().c_str();

		if (sdMain->Execute())
		{
			std::wstring file_name = sdMain->FileName.c_str();

			fh->ExportToItinerary(file_name, sgRoutes->Selection.Top);
		}
	}
}
