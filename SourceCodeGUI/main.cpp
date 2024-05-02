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
#include <System.SysUtils.hpp>
#pragma hdrstop

#include "About.h"
#include "AirportSearchDialog.h"
#include "Distance.h"
#include "Favourites.h"
#include "RouteBrowser.h"
#include "StatsAircraft.h"
#include "StatsAirports.h"
#include "StatsRoutes.h"

#include "AirlineHandler.h"
#include "AircraftConstants.h"
#include "DateUtility.h"
#include "Configuration.h"
#include "Formatting.h"
#include "GlobalObjects.h"
#include "JobHandler.h"
#include "Locations.h"
#include "main.h"
#include "MSFSSystem.h"
#include "FlightHandler.h"
#include "RouteHandler.h"
#include "RunwayHandler.h"
#include "Utility.h"
#include "WindowsUtility.h"

#pragma package(smart_init)
#pragma resource "*.dfm"


extern AircraftHandler* GAircraftHandler;
extern AirlineHandler* GAirlineHandler;
extern AirportHandler* GAirportHandler;
extern Configuration* GConfiguration;
extern FlightHandler* GFlightHandler;
extern JobHandler* GJobHandler;
extern RouteHandler* GRouteHandler;
extern RunwayHandler* GRunwayHandler;


TfrmMain *frmMain;


__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
	srand((unsigned)time(NULL));

	std::wstring c = L"FSAC " + SystemConstants::FSACVersion + L" / " + SystemConstants::FSACDate;

    Caption = c.c_str();

	if (GlobalObjects::CreateGlobalObjects())
	{
		InitialGUISetup();

		ResetGUI();

		UpdateAircraftList();

		UpdateCountryList();
	}
	else
	{
		std::wstring e = GAirportHandler->GetLastError() + L"..." + GRunwayHandler->GetLastError().c_str();

		sbMain->SimpleText = e.c_str();

		bGenerate->Enabled = false;
	}

	StatsGUI();
}


void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
    GlobalObjects::FreeGlobalObjects();
}


void __fastcall TfrmMain::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == VK_F9)
	{
        bGenerateClick(nullptr);
    }
}


void __fastcall TfrmMain::miResetAircraftClick(TObject *Sender)
{
	AircraftLoadFilter aclf;
	AirportLoadFilter aplf;
	FlightFilter rf;

	aplf.Ignore = true;
	rf.Ignore = true;

	BuildGUIFrom(aclf, aplf, rf);
}


void __fastcall TfrmMain::miResetAirportsClick(TObject *Sender)
{
	AircraftLoadFilter aclf;
	AirportLoadFilter aplf;
	FlightFilter rf;

	aplf.Ignore = true;
	rf.Ignore = true;

	BuildGUIFrom(aclf, aplf, rf);
}


void __fastcall TfrmMain::miResetRouteClick(TObject *Sender)
{
	AircraftLoadFilter aclf;
	AirportLoadFilter aplf;
	FlightFilter rf;

	aclf.Ignore = true;
	aplf.Ignore = true;

	BuildGUIFrom(aclf, aplf, rf);
}


void __fastcall TfrmMain::miRouteBrowserClick(TObject *Sender)
{
	frmRouteBrowser->ShowModal();
}


void __fastcall TfrmMain::Exit1Click(TObject *Sender)
{
	Application->Free();
}


#pragma region GUI_Build_Update
void TfrmMain::BuildGUIFrom(AircraftLoadFilter& aclf, AirportLoadFilter& aplf, FlightFilter& rf)
{
	// ============================================================================================
	// == build aircraft section ==================================================================
	// ============================================================================================

	if (!aclf.Ignore)
	{
		cbAircraftTypeProps->Checked = aclf.Types[AircraftConstants::AircraftTypeProp];
		cbAircraftTypeJet->Checked = aclf.Types[AircraftConstants::AircraftTypeJet];
		cbAircraftTypeHelicopter->Checked = aclf.Types[AircraftConstants::AircraftTypeHeli];
		cbAircraftTypeGlider->Checked = aclf.Types[AircraftConstants::AircraftTypeGlider];
		cbAircraftTypeTwinProps->Checked = aclf.Types[AircraftConstants::AircraftTypeTwinProp];
		cbAircraftTypeTurboProps->Checked = aclf.Types[AircraftConstants::AircraftTypeTurboProp];
		cbAircraftTypeTwinTurboProps->Checked = aclf.Types[AircraftConstants::AircraftTypeTwinTurboProp];
		cbAircraftTypeBalloon->Checked = aclf.Types[AircraftConstants::AircraftTypeBalloon];

		cbAircraftTypeAirliners->Checked = aclf.Airliner;
		cbAircraftTypeMilitary->Checked = aclf.Military;
		cbAircraftTypeSeaplanes->Checked = aclf.Seaplane;

		eMinSpeed->Text = aclf.MinSpeed;
		eMaxSpeed->Text = aclf.MaxSpeed;

		bUpdateAircraftClick(nullptr);
	}

	// ============================================================================================
	// == build airport section ===================================================================
	// ============================================================================================

	if (!aplf.Ignore)
	{
		if (aplf.FilterContinent)
		{
			pcGeography->TabIndex = 1;
		}

		cbContinentAF->Checked = aplf.Continents[0];
		cbContinentAN->Checked = aplf.Continents[1];
		cbContinentAS->Checked = aplf.Continents[2];
		cbContinentEU->Checked = aplf.Continents[3];
		cbContinentNA->Checked = aplf.Continents[4];
		cbContinentOC->Checked = aplf.Continents[5];
		cbContinentSA->Checked = aplf.Continents[6];

		if (aplf.FilterCountry)
		{
			pcGeography->TabIndex = 2;
		}

		cbCountryList->ItemIndex = Utility::GetCountryFromShortCodeAsInt(aplf.Country);

		if (aplf.FilterRegion)
		{
			pcGeography->TabIndex = 3;
        }

		eRegionICO->Text = aplf.Region.c_str();

		if (aplf.FilterLatLong)
		{
			pcGeography->TabIndex = 4;
        }

		eLatFrom->Text = aplf.LatitudeFrom;
		eLatTo->Text = aplf.LatitudeTo;
		eLongFrom->Text = aplf.LongitudeFrom;
		eLongTo->Text = aplf.LongitudeTo;

		cbLargeAirports->Checked = aplf.LargeAirports;
		cbMediumAirports->Checked = aplf.MediumAirports;
		cbSmallAirports->Checked = aplf.SmallAirports;
		cbHeliports->Checked = aplf.Heliports;
		cbSeaplaneBases->Checked = aplf.SeaplaneBases;

		cbTimeOfDay->Checked = aplf.UseTimeOfDay;
		rbDay->Checked = aplf.Day;
		rbNight->Checked = aplf.Night;

		pcGeographyChange(nullptr);

		if (cbTimeOfDay->Checked)
		{
			cbTimeOfDayClick(cbTimeOfDay);
		}

		std::wstring emin = L"(min: " + std::to_wstring(GAirportHandler->Stats.ElevationLowest) + L" ft)";
		std::wstring emax = L"(max: " + std::to_wstring(GAirportHandler->Stats.ElevationHighest) + L" ft)";

		lMinElevationRange->Caption = emin.c_str();
		lMaxElevationRange->Caption = emax.c_str();

		bUpdateAirportsClick(nullptr);
	}

	// ============================================================================================
	// == build route section =====================================================================
	// ============================================================================================

	if (!rf.Ignore)
	{
		pcRoute->TabIndex = rf.GenerateMode;

		eRange->Text = rf.Range;
		eLegs->Text = rf.Legs;
		eCount->Text = rf.Count;

		cbUseDirection->Checked = rf.UseDirection;
		eDirection->Text = rf.Direction;

		eStartAirportICAO->Text = rf.StartAirportICAO.c_str();
		eEndAirportICAO->Text = rf.EndAirportICAO.c_str();

		cbStartFromFavourite->Checked = rf.StartFromFavourite;
		cbEndAtFavourite->Checked = rf.EndAtFavourite;

		cbUseAircraftRange->Checked = rf.UseAircraftRange;
		eAircraftRangeModifier->Text = rf.AircraftRangeModifier;

		cbUseFlightTime->Checked = rf.UseFlightTime;
		eFlightTime->Text = rf.FlightTime;

		if (rf.StartEndUseLegs)
		{
			rbStartEndLegs->Checked = true;
		}
		else
		{
			rbStartEndRange->Checked = true;
		}

		cbUseFlightTimeClick(nullptr);
		cbUseDirectionClick(nullptr);

		// =====================================================================

		eRWRange->Text = rf.RWRange;

		cbRWUseAircraftRange->Checked = rf.RWUseAircraftRange;
		cbRWUseFlightTime->Checked = rf.RWUseFlightTime;
		eRWFlightTime->Text = rf.RWFlightTime;
		cbRWAllowExcessRange->Checked = rf.RWUseExcessRange;

		rbRWFromICAO->Checked = rf.Direction;

		eRWAirport->Text = rf.RWAirport.c_str();
		cbRWRouteType->ItemIndex = rf.RWRouteType;

		cbRWAirline->Checked = rf.RWUseAirline;
		cbRWAirlines->Enabled = rf.RWUseAirline;

		if (!rf.RWAirline.empty())
		{
			cbRWAirlines->Text = rf.RWAirline.c_str();
		}
		else
		{
			cbRWAirlines->ItemIndex = 0;
		}

		eRWRouteCount->Text = rf.RWCount;

		cbRWUseFlightTimeClick(nullptr);
	}

	// ============================================================================================
	// == other ===================================================================================
	// ============================================================================================

    if (!rf.Ignore)
	{
		cbKeepTrying->Checked = rf.KeepTrying;
	}
}


void TfrmMain::InitialGUISetup()
{
	#ifdef _DEBUG
	tbCodeTest->Visible = true;
	eMagicCode->Visible = true;
    bShowSearchParameters->Visible = true;
	#endif

	pcGeography->TabIndex = 1;
    pcRoute->TabIndex = 0;

	sgRoutes->ColAlignments[9] = taRightJustify;

	sgRoutes->ColWidths[0] = 15;
	sgRoutes->ColWidths[1] = 220;
	sgRoutes->ColWidths[2] = 65;
	sgRoutes->ColWidths[3] = 65;
	sgRoutes->ColWidths[4] = 65;
	sgRoutes->ColWidths[5] = 9;
	sgRoutes->ColWidths[6] = 65;
	sgRoutes->ColWidths[7] = 65;
	sgRoutes->ColWidths[8] = 65;
	sgRoutes->ColWidths[9] = 75;

	sgRoutes->Cells[0][0] = L"";
	sgRoutes->Cells[1][0] = L"Route";
	sgRoutes->Cells[2][0] = L"Continent";
	sgRoutes->Cells[3][0] = L"Country";
	sgRoutes->Cells[4][0] = L"Region";
	sgRoutes->Cells[5][0] = L"";
	sgRoutes->Cells[6][0] = L"Continent";
	sgRoutes->Cells[7][0] = L"Country";
	sgRoutes->Cells[8][0] = L"Region";
	sgRoutes->Cells[9][0] = L"Length";

	ShowHint = GConfiguration->System.ShowToolTips;
	miShowTooltips->Checked = ShowHint;

	if (GAircraftHandler->FilteredList.size() != 0)
	{
		for (int t = 0; t < GAirlineHandler->Airlines.size(); t++)
		{
			cbRWAirlines->Items->Add(GAirlineHandler->Airlines[t].Name.c_str());
		}

       	cbRWAirlines->ItemIndex = 0;
	}
}


void TfrmMain::ResetGUI()
{
	AircraftLoadFilter aclf;
	AirportLoadFilter aplf;
	FlightFilter rf;

	BuildGUIFrom(aclf, aplf, rf);
}


void TfrmMain::SetLabelStatus(int test_value, TLabel *label)
{
	if (test_value == 0)
	{
		TLabel *l = (TLabel*)label;

		l->Font->Color = clRed;
		l->Font->Style = l->Font->Style << fsBold;
    }
}


void TfrmMain::StatsGUI()
{
	if (GAircraftHandler->Loaded)
	{
		lStatsAircraft->Caption = System::Sysutils::IntToStr((int)GAircraftHandler->AircraftList.size());
	}
	else
	{
		Label21->Font->Color = clMaroon;
		lStatsAircraft->Font->Color = clMaroon;
	}

	if (GAirportHandler->Loaded)
	{
		lStatsAirport->Caption = System::Sysutils::IntToStr((int)GAirportHandler->Airports.size());
	}
	else
	{
		Label22->Font->Color = clMaroon;
		lStatsAirport->Font->Color = clMaroon;
	}

	if (GRunwayHandler->Loaded)
	{
		lStatsRunways->Caption = System::Sysutils::IntToStr((int)GRunwayHandler->Runways.size());
	}
	else
	{
		Label30->Font->Color = clMaroon;
		lStatsRunways->Font->Color = clMaroon;
	}


	if (GRouteHandler->Loaded)
	{
		lStatsRoutes->Caption = System::Sysutils::IntToStr((int)GRouteHandler->Routes.size());
	}
	else
	{
		Label36->Font->Color = clMaroon;
		lStatsRoutes->Font->Color = clMaroon;
	}

	SetLabelStatus(GAircraftHandler->AircraftList.size(), lStatsAircraft);
	SetLabelStatus(GAirportHandler->Airports.size(), lStatsAirport);
	SetLabelStatus(GRunwayHandler->Runways.size(), lStatsRunways);
	SetLabelStatus(GRouteHandler->Routes.size(), lStatsRoutes);
}


void TfrmMain::UpdateExcessRange()
{
	if (GAircraftHandler->FilteredList.size() != 0)
	{
		int range = GAircraftHandler->FilteredList[cbAircraftList->ItemIndex].Range;
		int aemodifier = eAircraftRangeModifier->Text.ToIntDef(0);
		int aerange = static_cast<int>((double)range * (1 + ((double)aemodifier / 100)));

		std::wstring newrange(std::to_wstring(aerange) + L" nm");

		lExcessRange->Caption = newrange.c_str();
	}
	else
	{
        lExcessRange->Caption = "";
    }
}
#pragma end_region

void __fastcall TfrmMain::bUpdateAircraftClick(TObject *Sender)
{
	if (bLockAircraft->Tag == 0)
	{
		sbMain->SimpleText = "Updating aircraft selection...";

        AircraftDetailsHaveChanged = false;

		AircraftLoadFilter alf = BuildAircraftLoadFilterFromUI();

		int count = GAircraftHandler->Filter(alf);

		if (count != 0)
		{
			UpdateAircraftList();
		}
		else
		{
			cbAircraftList->Clear();

			lAircraftStats->Caption = "";
		}

		gbAircraft->Caption = "Aircraft (" + System::Sysutils::IntToStr((int)GAircraftHandler->FilteredList.size()) + " selected)";

		sbMain->SimpleText = "";

		UpdateExcessRange();
	}
}


void TfrmMain::UpdateAircraftList()
{
	cbAircraftList->Items->Clear();

	if (GAircraftHandler->FilteredList.size() != 0)
	{
		for (int t = 0; t < GAircraftHandler->FilteredList.size(); t++)
		{
			cbAircraftList->Items->Add(GAircraftHandler->FilteredList[t].Name.c_str());
		}

		cbAircraftList->ItemIndex = 0;

		cbAircraftListChange(nullptr);
	}
}


void __fastcall TfrmMain::bUpdateAirportsClick(TObject *Sender)
{
	sbMain->SimpleText = "Updating airport selection...";

	AirportLoadFilter alf = BuildAirportLoadFilterFromUI();

	int count = GAirportHandler->Filter(alf);

	gbAirports->Caption = "Airports (" + System::Sysutils::IntToStr((int)GAirportHandler->FilteredList.size()) + " selected)";

	sbMain->SimpleText = "";
}


AircraftLoadFilter TfrmMain::BuildAircraftLoadFilterFromUI()
{
	AircraftLoadFilter alf;

	alf.Types[AircraftConstants::AircraftTypeProp] = cbAircraftTypeProps->Checked;
	alf.Types[AircraftConstants::AircraftTypeJet] = cbAircraftTypeJet->Checked;
	alf.Types[AircraftConstants::AircraftTypeHeli] = cbAircraftTypeHelicopter->Checked;
	alf.Types[AircraftConstants::AircraftTypeGlider] = cbAircraftTypeGlider->Checked;
	alf.Types[AircraftConstants::AircraftTypeTwinProp] = cbAircraftTypeTwinProps->Checked;
	alf.Types[AircraftConstants::AircraftTypeTurboProp] = cbAircraftTypeTurboProps->Checked;
	alf.Types[AircraftConstants::AircraftTypeTwinTurboProp] = cbAircraftTypeTwinTurboProps->Checked;
	alf.Types[AircraftConstants::AircraftTypeBalloon] = cbAircraftTypeBalloon->Checked;

	alf.Airliner = cbAircraftTypeAirliners->Checked;
	alf.Military = cbAircraftTypeMilitary->Checked;
	alf.Seaplane = cbAircraftTypeSeaplanes->Checked;

	alf.MinSpeed = eMinSpeed->Text.ToIntDef(0);
	alf.MaxSpeed = eMaxSpeed->Text.ToIntDef(0);

	switch (cbMSFSVersion->ItemIndex)
	{
	case 0:
		alf.Version = AircraftConstants::MSFSVersion::All;
		break;
	case 1:
		alf.Version = AircraftConstants::MSFSVersion::DeluxeAbove;
		break;
	case 2:
		alf.Version = AircraftConstants::MSFSVersion::PremiumAbove;
        break;
	}

	return alf;
}


AirportLoadFilter TfrmMain::BuildAirportLoadFilterFromUI()
{
	AirportLoadFilter alf;

	alf.FilterContinent = (pcGeography->TabIndex == 1);

	alf.Continents[0] = cbContinentAF->Checked;
	alf.Continents[1] = cbContinentAN->Checked;
	alf.Continents[2] = cbContinentAS->Checked;
	alf.Continents[3] = cbContinentEU->Checked;
	alf.Continents[4] = cbContinentNA->Checked;
	alf.Continents[5] = cbContinentOC->Checked;
	alf.Continents[6] = cbContinentSA->Checked;

	alf.FilterCountry = (pcGeography->TabIndex == 2);
	if (cbCountryList->ItemIndex != -1)
	{
		alf.Country = Location::ISOCountriesOrdered[cbCountryList->ItemIndex][1];
	}

	alf.FilterRegion = (pcGeography->TabIndex == 3);
	alf.Region = eRegionICO->Text.UpperCase().c_str();

	alf.FilterLatLong = (pcGeography->TabIndex == 4);

	alf.LatitudeFrom = eLatFrom->Text.ToDouble();
	alf.LatitudeTo = eLatTo->Text.ToDouble();
	alf.LongitudeFrom = eLongFrom->Text.ToDouble();
	alf.LongitudeTo = eLongTo->Text.ToDouble();

	if (alf.LatitudeFrom != 0 && alf.LatitudeTo != 0)
	{
		alf.LatitudeFilter = true;
	}

	if (alf.LongitudeFrom != 0 && alf.LongitudeTo != 0)
	{
		alf.LongitudeFilter = true;
	}

	if (alf.LatitudeFrom < alf.LatitudeTo)
	{
		alf.LatitudeInverse = true;
	}

	if (alf.LongitudeFrom < alf.LongitudeTo)
	{
		alf.LongitudeInverse = true;
	}

	alf.MinimumElevation = eMinElevation->Text.ToIntDef(DataDefaults::LowestElevation);
	alf.MaximumElevation = eMaxElevation->Text.ToIntDef(DataDefaults::HighestElevation);

	alf.LargeAirports = cbLargeAirports->Checked;
	alf.MediumAirports = cbMediumAirports->Checked;
	alf.SmallAirports = cbSmallAirports->Checked;
	alf.Heliports = cbHeliports->Checked;
	alf.SeaplaneBases = cbSeaplaneBases->Checked;

	alf.UseTimeOfDay = cbTimeOfDay->Checked;

	if (alf.Day)
	{
		alf.SetLongitude(TimeOfDay::Midday, DateUtility::GetMonth());
	}
	else
	{
		alf.SetLongitude(TimeOfDay::Midnight, DateUtility::GetMonth());
    }

	alf.Day = rbDay->Checked;
	alf.Night = rbNight->Checked;

	return alf;
}


FlightFilter TfrmMain::BuildRouteLoadFilterFromUI()
{
	FlightFilter rf;

	rf.GenerateMode = pcRoute->TabIndex;

	rf.Range = eRange->Text.ToDouble();
	rf.Legs = eLegs->Text.ToIntDef(1);
	rf.Count = eCount->Text.ToIntDef(1);

	rf.UseDirection = cbUseDirection->Checked;
	rf.Direction = eDirection->Text.ToDouble();

	rf.StartAirportICAO = eStartAirportICAO->Text.c_str();
	rf.EndAirportICAO = eEndAirportICAO->Text.c_str();

	rf.StartFromFavourite = cbStartFromFavourite->Checked;

	rf.UseAircraftRange = cbUseAircraftRange->Checked;
	rf.AircraftRangeModifier = eAircraftRangeModifier->Text.ToDouble();

	rf.UseFlightTime = cbUseFlightTime->Checked;
	rf.FlightTime = eFlightTime->Text.ToIntDef(0);

	if (rf.FlightTime < 1)
	{
		rf.UseFlightTime = false;
	}

	rf.StartEndUseLegs = rbStartEndLegs->Checked;

	rf.KeepTrying = cbKeepTrying->Checked;

	// =========================================================================

	rf.RWRange = eRWRange->Text.ToIntDef(0);

	rf.RWUseAircraftRange = cbRWUseAircraftRange->Checked;
	rf.RWUseFlightTime = cbRWUseFlightTime->Checked;
	rf.RWFlightTime = eRWFlightTime->Text.ToIntDef(0);
	rf.RWUseExcessRange = cbRWAllowExcessRange->Checked;

	rf.Direction = rbRWFromICAO->Checked;

	rf.RWAirport = eRWAirport->Text.c_str();
	rf.RWRouteType = cbRWRouteType->ItemIndex;

	rf.RWUseAirline = cbRWAirline->Checked;
	rf.RWAirline = cbRWAirlines->Text.c_str();

	rf.RWCount = eRWRouteCount->Text.ToIntDef(0);

	// =========================================================================

	return rf;
}


void TfrmMain::UpdateCountryList()
{
	cbCountryList->Clear();

	for (int t = 0; t < Location::ISOCountriesCount; t++)
	{
		cbCountryList->Items->Add(Location::ISOCountriesOrdered[t][0].c_str());
	}

	cbCountryList->ItemIndex = 0;
}


void __fastcall TfrmMain::bRandomJobClick(TObject *Sender)
{
	FillJob();
}


void __fastcall TfrmMain::bGenerateClick(TObject *Sender)
{
	if (pcRoute->TabIndex == 0)
	{
		RandomPreCheck();
	}
	else
	{
		RoutePreCheck();
	}

	FillJob();

	std::wstring gr(L"Generated Routes (" + std::to_wstring(GFlightHandler->Flights.size()) + L")");

	gbGeneratedRoutes->Caption = gr.c_str();
}


void TfrmMain::RandomPreCheck()
{
	if (pcGeography->TabIndex == 0 && !cbTimeOfDay->Checked)
	{
		Application->MessageBox(L"At least one airport location or area must be selected!", L"Route Generation", MB_OK);

		return;
	}

	if (!cbLargeAirports->Checked && !cbMediumAirports->Checked && !cbSmallAirports->Checked && !cbHeliports->Checked && !cbSeaplaneBases->Checked)
	{
		Application->MessageBox(L"At least one airport type must be selected!", L"Route Generation", MB_OK);

		return;
	}

	// =========================================================================

	if (GAircraftHandler->FilteredList.size() != 0 && GAirportHandler->FilteredList.size() != 0)
	{
		bool can_continue = true;

		if (!eStartAirportICAO->Text.IsEmpty)
		{
			if (!GAirportHandler->IsValidAirport(eStartAirportICAO->Text.c_str()))
			{
				Application->MessageBox(L"Start airport ICAO is invalid.", L"Route Generation", MB_OK);

				can_continue = false;
			}
		}

		if (!eStartAirportICAO->Text.IsEmpty)
		{
			if (!GAirportHandler->IsValidAirport(eStartAirportICAO->Text.c_str()))
			{
				Application->MessageBox(L"End airport ICAO is invalid.", L"Route Generation", MB_OK);

				can_continue = false;
			}
		}

		if (can_continue)
		{
			bGenerate->Enabled = false;

			if (AirportDetailsHaveChanged)
			{
				bUpdateAirportsClick(nullptr);
			}

			if (AircraftDetailsHaveChanged)
			{
				bUpdateAircraftClick(nullptr);
			}

			GenerateRandomRoutes();

			sgRoutesClick(nullptr);

			if (!UpdateRouteList())
			{
				sbMain->SimpleText = "No routes could be generated with selected locations and route parameters :(";
			}

			GConfiguration->System.RoutesGenerated += GFlightHandler->Flights.size();

            bGenerate->Enabled = true;
		}
	}
	else
	{
	    sbMain->SimpleText = "Can't generate route, not enough airports or aircraft!";
	}
}


void TfrmMain::RoutePreCheck()
{
	if (pcGeography->TabIndex == 0 && !cbTimeOfDay->Checked)
	{
		Application->MessageBox(L"At least one airport location or area must be selected!", L"Route Generation", MB_OK);

		return;
	}

	if (!cbLargeAirports->Checked && !cbMediumAirports->Checked && !cbSmallAirports->Checked && !cbHeliports->Checked && !cbSeaplaneBases->Checked)
	{
		Application->MessageBox(L"At least one airport type must be selected!", L"Route Generation", MB_OK);

		return;
	}

	// =========================================================================

	if (GAircraftHandler->FilteredList.size() != 0 && GAirportHandler->FilteredList.size() != 0)
	{
		bool can_continue = true;

		if (!eRWAirport->Text.IsEmpty)
		{
			if (!GAirportHandler->IsValidAirport(eRWAirport->Text.c_str()))
			{
				Application->MessageBox(L"Aairport ICAO is invalid.", L"Route Generation", MB_OK);

				can_continue = false;
			}
		}

		if (can_continue)
		{
			bGenerate->Enabled = false;

			if (AirportDetailsHaveChanged)
			{
				bUpdateAirportsClick(nullptr);
			}

			if (AircraftDetailsHaveChanged)
			{
				bUpdateAircraftClick(nullptr);
			}

			GenerateRealWorldRoutes();

			sgRoutesClick(nullptr);

			if (!UpdateRouteList())
			{
				sbMain->SimpleText = "No routes could be generated with selected locations and route parameters :(";
			}

			GConfiguration->System.RoutesGenerated += GFlightHandler->Flights.size();

            bGenerate->Enabled = true;
		}
	}
	else
	{
	    sbMain->SimpleText = "Can't generate route, not enough airports or aircraft!";
	}
}


void TfrmMain::FillJob()
{
	Aircraft aircraft = GetAircraftFromSelection();

	std::wstring job = GJobHandler->FindJob(aircraft.Type, aircraft.Airliner, aircraft.Military);

	mJob->Text = job.c_str();
}


void TfrmMain::GenerateRandomRoutes()
{
	sbMain->SimpleText = "Generating random routes...";

	double RouteDirection = DataDefaults::Direction; // to do; all these need setting if UI says so / not default value
	double RouteRange = eRange->Text.ToDouble();
	int RouteLegs = eLegs->Text.ToInt();
	int RouteCount = eCount->Text.ToIntDef(1);
	int FlightTime = 0;

	if (cbUseDirection->Checked)
	{
		RouteDirection = eDirection->Text.ToDouble();
	}

	// populate start/end from favourites if requested

	if (cbStartFromFavourite->Checked)
	{
		eStartAirportICAO->Text = GConfiguration->GetRandomFavourite().c_str();
	}

	if (cbEndAtFavourite->Checked)
	{
		eEndAirportICAO->Text = GConfiguration->GetRandomFavourite().c_str();
	}

	// =========================================================================

	if (eStartAirportICAO->Text != "" && eEndAirportICAO->Text != "")
	{
		double d = GAirportHandler->DistanceBetweenTwoAirports(eStartAirportICAO->Text.c_str(), eEndAirportICAO->Text.c_str());

		if (rbStartEndRange->Checked)
		{
			RouteLegs = (d / RouteRange) + 1;
		}
		else
        {
			RouteRange = d / RouteLegs;
		}
	}

	// =========================================================================

	Aircraft aircraft = GetAircraftFromSelection();

	// =========================================================================

	if (cbUseFlightTime->Checked)
	{
		if (eFlightTime->Text.ToIntDef(0) != 0)
		{
			int new_range = GFlightHandler->SetRangeFromTime(eFlightTime->Text.ToIntDef(0), RouteLegs, aircraft.CruiseSpeed, aircraft.Type);

			if (new_range != -1)
			{
				RouteRange = new_range;

				FlightTime = eFlightTime->Text.ToIntDef(0);
			}
		}
	}

	double potential_route_length = RouteRange * (double)RouteLegs;
	double usable_aircraft_range = (double)aircraft.Range * (1 + ((double)eAircraftRangeModifier->Text.ToIntDef(DataDefaults::AircraftRangePC) / 100));
	double range_per_leg = RouteRange;

	if (cbUseAircraftRange->Checked)
	{
		range_per_leg = ((double)aircraft.Range * (1 + ((double)eAircraftRangeModifier->Text.ToIntDef(DataDefaults::AircraftRangePC) / 100))) / (double)RouteLegs;
	}
	else
	{
		if (range_per_leg > usable_aircraft_range)
		{
			range_per_leg = ((double)aircraft.Range * (1 + ((double)eAircraftRangeModifier->Text.ToIntDef(DataDefaults::AircraftRangePC) / 100))) / (double)RouteLegs;
		}
		else if (potential_route_length > usable_aircraft_range && !cbAllowExcessRange->Checked)
		{
			range_per_leg = ((double)aircraft.Range * (1 + ((double)eAircraftRangeModifier->Text.ToIntDef(DataDefaults::AircraftRangePC) / 100))) / (double)RouteLegs;
		}
	}

	mRouteDebug->Text = GFlightHandler->BuildRouteDescription(eStartAirportICAO->Text.c_str(), eEndAirportICAO->Text.c_str(), cbStartFromFavourite->Checked, cbEndAtFavourite->Checked,
		range_per_leg, RouteDirection, RouteLegs, RouteCount, FlightTime, cbKeepTrying->Checked,
		cbUseAircraftRange->Checked, aircraft.Range, eAircraftRangeModifier->Text.ToIntDef(DataDefaults::AircraftRangePC)).c_str();

	GAirportHandler->GetRoute(eStartAirportICAO->Text.c_str(), eEndAirportICAO->Text.c_str(), range_per_leg, RouteDirection, RouteLegs, RouteCount,	cbKeepTrying->Checked, cbMoreRandom->Checked);

	sbMain->SimpleText = "Finished generating routes.";
}


void TfrmMain::GenerateRealWorldRoutes()
{
	sbMain->SimpleText = "Generating random routes...";

	// =========================================================================
	Aircraft aircraft = GetAircraftFromSelection();
	// =========================================================================

	RouteFilter rf;

	double range = eRWRange->Text.ToDouble();

	if (cbRWUseFlightTime->Checked)
	{
		if (eRWFlightTime->Text.ToIntDef(0) != 0)
		{
			int new_range = GFlightHandler->SetRangeFromTime(eRWFlightTime->Text.ToIntDef(0), 1, aircraft.CruiseSpeed, aircraft.Type);

			if (new_range != -1)
			{
				range = new_range;
			}
		}
	}
	else if (cbRWUseAircraftRange->Checked)
	{
		range = (double)aircraft.Range * (1 + ((double)eAircraftRangeModifier->Text.ToIntDef(DataDefaults::AircraftRangePC) / 100));

		Caption = aircraft.Range;
	}

	rf.Distance = range;
	rf.DistanceMin = range * 0.90;
	rf.DistanceMax = range * 1.10;

	rf.DirectionFrom = rbRWFromICAO->Checked;				                    // true: ICAO is start, false: ICAO is end

	rf.ICAO = eRWAirport->Text.c_str();
	rf.SpecificAirline = cbRWAirline->Checked;
	rf.Airline = cbRWAirlines->Text.c_str();

	rf.RouteCount = eRWRouteCount->Text.ToInt();

	rf.KeepTrying = cbKeepTrying->Checked;
	rf.InternalOnly = cbRWRouteType->ItemIndex == 1;
	rf.ExternalOnly = cbRWRouteType->ItemIndex == 2;

	GRouteHandler->GenerateRoutes(rf);

//	std::wstring s = std::to_wstring(rf.Distance) + L" " + std::to_wstring(rf.DistanceMin) + L" " + std::to_wstring(rf.DistanceMax);
//    Caption = s.c_str();

	sbMain->SimpleText = "Finished generating routes.";
}


Aircraft TfrmMain::GetAircraftFromSelection()
{
	int selected_aircraft = cbAircraftList->ItemIndex;

	if (bLockAircraft->Tag == 0)
	{
		selected_aircraft = rand() % cbAircraftList->Items->Count;
		cbAircraftList->ItemIndex = selected_aircraft;
		cbAircraftListChange(nullptr);
	}

	return GAircraftHandler->FilteredList[selected_aircraft];
}


bool TfrmMain::UpdateRouteList()
{
	if (GFlightHandler->Flights.size() != 0)
	{
		sgRoutes->RowCount = GFlightHandler->Flights.size() + 1;

		for (int t = 0; t < GFlightHandler->Flights.size(); t++)
		{
			std::wstring d = std::to_wstring(GFlightHandler->Flights[t].Distance) + L" nm";

			if (GFlightHandler->Flights[t].Favourite)
			{
				sgRoutes->Cells[0][t + 1] = "*";
			}
			else
			{
				sgRoutes->Cells[0][t + 1] = "";
            }

			sgRoutes->Cells[1][t + 1] = GFlightHandler->Flights[t].Name.c_str();

			sgRoutes->Cells[2][t + 1] = GFlightHandler->Flights[t].FromContinent.c_str();
			sgRoutes->Cells[3][t + 1] = GFlightHandler->Flights[t].FromCountry.c_str();
			sgRoutes->Cells[4][t + 1] = GFlightHandler->Flights[t].FromRegion.c_str();

			sgRoutes->Cells[6][t + 1] = GFlightHandler->Flights[t].ToContinent.c_str();
			sgRoutes->Cells[7][t + 1] = GFlightHandler->Flights[t].ToCountry.c_str();
			sgRoutes->Cells[8][t + 1] = GFlightHandler->Flights[t].ToRegion.c_str();

			sgRoutes->Cells[9][t + 1] = d.c_str();
		}

		return true;
	}
	else
	{
		sgRoutes->RowCount = 2;

		sgRoutes->Cells[0][1] = "";
		sgRoutes->Cells[1][1] = "No routes could be generated :(";

		sgRoutes->Cells[2][1] = "";
		sgRoutes->Cells[3][1] = "";
		sgRoutes->Cells[4][1] = "";

		sgRoutes->Cells[6][1] = "";
		sgRoutes->Cells[7][1] = "";
		sgRoutes->Cells[8][1] = "";

		sgRoutes->Cells[9][1] = "";
    }

	return false;
}
void __fastcall TfrmMain::tbNewClick(TObject *Sender)
{
	if (Application->MessageBox(L"This will reset all parameters to their defaults.", L"Reset Parameters?", MB_OKCANCEL) == IDOK)
	{
		ResetGUI();
	}
}


void __fastcall TfrmMain::tbSaveClick(TObject *Sender)
{
	sdMain->Filter = "FSAC configuration files|*.config";
	sdMain->DefaultExt = ".config";

	AircraftLoadFilter aircraft_lf = BuildAircraftLoadFilterFromUI();
	AirportLoadFilter airport_lf = BuildAirportLoadFilterFromUI();
	FlightFilter rf = BuildRouteLoadFilterFromUI();

	if (sdMain->Execute())
	{
		std::wstring file_name = sdMain->FileName.c_str();

		if (GConfiguration->SaveConfiguration(file_name, aircraft_lf, airport_lf, rf))
		{
            sbMain->SimpleText = "Configuation saved successfully!";
        }
	}
}


void __fastcall TfrmMain::tbOpenClick(TObject *Sender)
{
	AircraftLoadFilter aclf;
	AirportLoadFilter aplf;
	FlightFilter rf;

	if (odMain->Execute())
	{
		std::wstring file_name = odMain->FileName.c_str();

		if (GConfiguration->LoadConfiguration(file_name, aclf, aplf, rf))
		{
			BuildGUIFrom(aclf, aplf, rf);
        }
    }
}


void __fastcall TfrmMain::tbExportClick(TObject *Sender)
{
	GFlightHandler->ExportAllToMSFS();
}


void __fastcall TfrmMain::tbExportItineraryClick(TObject *Sender)
{
	GFlightHandler->ExportAllToItinerary();
}


void __fastcall TfrmMain::Createcustomaircrafttxt1Click(TObject *Sender)
{
	if (Application->MessageBox(L"This will overwrite the existing file, all edits will be lost.", L"Create new 'custom_aircraft.txt'?", MB_OKCANCEL) == IDOK)
	{
		int aircraft_count = MSFSSystem::CreateAircraftList(true);

		if (aircraft_count != 0)
		{
			std::wstring message = L"'custom_aircraft.txt' file created successfully (found " + std::to_wstring(aircraft_count) + L" aircraft).";

			sbMain->SimpleText = message.c_str();
		}
		else
		{
			sbMain->SimpleText = "Error creating 'custom_aircraft.txt' file.";
        }
    }
}


void __fastcall TfrmMain::About1Click(TObject *Sender)
{
	frmAbout->ShowModal();
}


void __fastcall TfrmMain::lStatsRoutesClick(TObject *Sender)
{
	frmStatsRoutes->ShowModal();
}


void __fastcall TfrmMain::lStatsAirportClick(TObject *Sender)
{
	frmStatsAirports->ShowModal();
}

void __fastcall TfrmMain::lStatsAircraftClick(TObject *Sender)
{
	frmStatsAircraft->ShowModal();
}


void __fastcall TfrmMain::sgRoutesClick(TObject *Sender)
{
	if (sgRoutes->Selection.Top > 0 && GFlightHandler->Flights.size() != 0)
	{
		UpdateRouteDescription(sgRoutes->Selection.Top - 1);
	}
	else
	{
		mMain->Clear();
    }
}


void TfrmMain::UpdateRouteDescription(int route_id)
{
	mMain->Clear();

	Flight& f = GFlightHandler->Flights[route_id];

	// when creating a lot of routes we can speed things up a bit by not populating the airports list in the flight object
	// however, we need them for this bit, so only do the work if necessary
	if (GFlightHandler->Flights[route_id].Simple)
	{
		GAirportHandler->Populate(route_id);
	}

	std::wstring output = L" Starting at: " + f.Airports[0].Ident + L" (" + f.Airports[0].Country + L", " + f.Airports[1].Angle1p() + L"°)";

	mMain->Lines->Add(output.c_str());

	// airport iternary

	for (int t = 1; t < f.Airports.size(); t++)
	{
		if (t == f.Airports.size() - 1)
		{
			output = Formatting::AddLeadingSpace(std::to_wstring((int)f.Airports[t].Distance), 7) + L"nm --> " + f.Airports[t].Ident + L" (" + f.Airports[t].Country + L")";
		}
		else
		{
			output = Formatting::AddLeadingSpace(std::to_wstring((int)f.Airports[t].Distance), 7) + L"nm --> " + f.Airports[t].Ident + L" (" + f.Airports[t].Country + L", " + f.Airports[t + 1].Angle1p() + L"°)";
		}

		mMain->Lines->Add(output.c_str());
	}

	mMain->Lines->Add(L"");

	// airport, detailed view

	for (int t = 0; t < f.Airports.size(); t++)
	{
		output = std::to_wstring(t + 1) + L") " + f.Airports[t].Name;
		mMain->Lines->Add(output.c_str());
		output = L"   " + Utility::GetCountryFromShortCode(f.Airports[t].Country);
		mMain->Lines->Add(output.c_str());
	}

	// add airline, if relevant

	if (f.Airline != L"")
	{
		mMain->Lines->Add(L"");

		std::wstring airline(L"Airline: " + f.Airline);

		mMain->Lines->Add(L"");
		mMain->Lines->Add(airline.c_str());
	}

    // ensure the top line of the memo is visible

	mMain->SelStart = 0;
	mMain->SelLength  = 1;
}


void __fastcall TfrmMain::cbAircraftListChange(TObject *Sender)
{
	if (cbAircraftList->ItemIndex != -1)
	{
		lAircraftStats->Caption = GAircraftHandler->FilteredList[cbAircraftList->ItemIndex].ShowStats().c_str();

        UpdateExcessRange();
    }
}


void __fastcall TfrmMain::miSetGAClick(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;

	switch (mi->Tag)
	{
		case 0:
			SetAircraftSelections(true, false, false, false, true, true, true, false, false, false, false);
			break;
		case 1:
			SetAircraftSelections(false, true, false, false, false, false, false, false, true, false, false);
			break;
		case 2:
			SetAircraftSelections(true, false, false, false, true, false, false, false, true, true, false);
			break;
		case 3:
			SetAircraftSelections(false, false, false, false, false, true, true, false, true, true, false);
			break;
		case 4:
			SetAircraftSelections(false, false, false, false, true, false, true, false, true, true, false);
			break;
		case 5:
			SetAircraftSelections(false, false, false, false, false, false, false, false, true, false, true);
			break;
		case 6:
			SetAircraftSelections(false, true, false, false, false, false, false, false, false, true, false);
			break;
		case 7:
			SetAircraftSelections(true, false, false, false, true, true, true, false, false, true, false);
			break;
		case 8:
			SetAircraftSelections(false, false, false, true, false, false, false, false, false, false, false);
			break;
		case 9:
			SetAircraftSelections(false, false, true, false, false, false, false, false, false, true, false);
			break;
		case 10:
			SetAircraftSelections(true, false, false, false, true, true, true, false, true, false, false);
			break;
	}

    bUpdateAircraftClick(nullptr);
}


void TfrmMain::SetAircraftSelections(bool prop, bool jet, bool heli, bool glider, bool twinprop, bool turboprop, bool ttp, bool balloon, bool airliner, bool military, bool seaplane)
{
	cbAircraftTypeProps->Checked = prop;
	cbAircraftTypeJet->Checked = jet;
	cbAircraftTypeHelicopter->Checked = heli;
	cbAircraftTypeGlider->Checked = glider;
	cbAircraftTypeTwinProps->Checked = twinprop;
	cbAircraftTypeTurboProps->Checked = turboprop;
	cbAircraftTypeTwinTurboProps->Checked = ttp;
	cbAircraftTypeBalloon->Checked = balloon;

	cbAircraftTypeAirliners->Checked = airliner;
	cbAircraftTypeMilitary->Checked = military;
	cbAircraftTypeSeaplanes->Checked = seaplane;
}


void __fastcall TfrmMain::Airports1Click(TObject *Sender)
{
	frmAirportSearchDialog->SetSelectionMode(false);

	frmAirportSearchDialog->ShowModal();
}


void __fastcall TfrmMain::bExportSelectedClick(TObject *Sender)
{
	if (sgRoutes->Selection.Top > 0 && GFlightHandler->Flights.size() != 0)
	{
		sdMain->Filter = "MSFS 2020 plan files|*.pln";
		sdMain->DefaultExt = ".pln";
		sdMain->FileName = GFlightHandler->Flights[sgRoutes->Selection.Top - 1].GetMSFSFileName().c_str();

		if (sdMain->Execute())
		{
			std::wstring file_name = sdMain->FileName.c_str();

			GFlightHandler->ExportToMSFS(file_name, sgRoutes->Selection.Top);
		}
	}
}


void __fastcall TfrmMain::bExportSelectedTextClick(TObject *Sender)
{
	if (sgRoutes->Selection.Top > 0 && GFlightHandler->Flights.size() != 0)
	{
		sdMain->Filter = "Itinerary text files|*.txt";
		sdMain->DefaultExt = ".txt";
		sdMain->FileName = GFlightHandler->Flights[sgRoutes->Selection.Top - 1].GetTextFileName().c_str();

		if (sdMain->Execute())
		{
			std::wstring file_name = sdMain->FileName.c_str();

			GFlightHandler->ExportToItinerary(file_name, sgRoutes->Selection.Top);
		}
	}
}


void __fastcall TfrmMain::bExportSelectedXPlaneClick(TObject *Sender)
{
	if (sgRoutes->Selection.Top > 0 && GFlightHandler->Flights.size() != 0)
	{
		sdMain->Filter = "X-Plane 11 flight plans|*.fms";
		sdMain->DefaultExt = ".fms";
		sdMain->FileName = GFlightHandler->Flights[sgRoutes->Selection.Top - 1].GetTextFileName().c_str();

		if (sdMain->Execute())
		{
			std::wstring file_name = sdMain->FileName.c_str();

			GFlightHandler->ExportToXPlane11(file_name, sgRoutes->Selection.Top);
		}
	}
}



void __fastcall TfrmMain::Favourites1Click(TObject *Sender)
{
	frmFavourites->ShowModal();
}


void __fastcall TfrmMain::bLockAircraftClick(TObject *Sender)
{
	TButton *button = (TButton*)Sender;

	if (button->Tag == 0)
	{
		button->Tag = 1;
		button->ImageIndex = 3;
	}
	else
	{
		button->Tag = 0;
		button->ImageIndex = 2;
    }
}


void __fastcall TfrmMain::bRandomAircraftClick(TObject *Sender)
{
	if (cbAircraftList->Items->Count != 0 && bLockAircraft->Tag == 0)
	{
		if (AircraftDetailsHaveChanged)
		{
            bUpdateAircraftClick(nullptr);
        }

		cbAircraftList->ItemIndex = rand() % cbAircraftList->Items->Count;
		cbAircraftListChange(nullptr);
    }
}


void __fastcall TfrmMain::cbAircraftTypePropsClick(TObject *Sender)
{
	AircraftDetailsHaveChanged = true;

	if (cbAirportTypeAutomatic->Checked)
	{
		cbHeliports->Checked = cbAircraftTypeHelicopter->Checked;

		cbSeaplaneBases->Checked = cbAircraftTypeSeaplanes->Checked;

        cbSmallAirports->Checked = !cbAircraftTypeAirliners->Checked;
	}

	UpdateExcessRange();
}


void __fastcall TfrmMain::cbContinentAFClick(TObject *Sender)
{
	AirportDetailsHaveChanged = true;
}


void __fastcall TfrmMain::cbAirportTypeAutomaticClick(TObject *Sender)
{
	cbAircraftTypePropsClick(nullptr);

    cbContinentAFClick(nullptr);
}


void __fastcall TfrmMain::cbUseFlightTimeClick(TObject *Sender)
{
	eFlightTime->Enabled = cbUseFlightTime->Checked;

	if (cbUseAircraftRange->Checked)
	{
		eRange->Enabled = false;
	}
	else
	{
		eRange->Enabled = !cbUseFlightTime->Checked;
    }
}


void __fastcall TfrmMain::cbUseDirectionClick(TObject *Sender)
{
	eDirection->Enabled = cbUseDirection->Checked;
}


// used by MinSpeed, Range, FlightTime, Legs, and RouteCount
void __fastcall TfrmMain::eLegsExit(TObject *Sender)
{
	TEdit *edit = (TEdit*)Sender;

	int i = edit->Text.ToIntDef(0);

	if (i < 1)
	{
		edit->Text = "1";
	}
}


void __fastcall TfrmMain::eDirectionExit(TObject *Sender)
{
	TEdit *edit = (TEdit*)Sender;

	int i = edit->Text.ToIntDef(-1);

	if (i < 1)
	{
		edit->Text = "1";
	}
	else if (i > 359)
	{
        edit->Text = "359";
    }
}


// ensures user sets elevation to a sensible value
void __fastcall TfrmMain::eMinElevationExit(TObject *Sender)
{
	TEdit *edit = (TEdit*)Sender;

	int i = edit->Text.ToIntDef(-3000);

	if (i < -2000)
	{
		edit->Text = "-2000";
	}
}


void __fastcall TfrmMain::eMaxElevationExit(TObject *Sender)
{
	TEdit *edit = (TEdit*)Sender;

	int i = edit->Text.ToIntDef(0);

	if (i == 0 || i > 15000)
	{
		edit->Text = "15000";
	}
}


// handles edit boxes that require percent values 0-100
void __fastcall TfrmMain::eAircraftRangeModifierExit(TObject *Sender)
{
	TEdit *edit = (TEdit*)Sender;

	int i = edit->Text.ToIntDef(-1);

	if (i < 0)
	{
		edit->Text = "0";
	}

	if (i > 500)
	{
		edit->Text = "500";
	}
}


void __fastcall TfrmMain::Label31Click(TObject *Sender)
{
	WindowsUtility::OpenWebsite(L"https://en.wikipedia.org/wiki/ISO_3166-2");
}


void __fastcall TfrmMain::bOpenStartMapClick(TObject *Sender)
{
	if (sgRoutes->Selection.Top > 0 && GFlightHandler->Flights.size() != 0)
	{
		Airport start = GFlightHandler->Flights[sgRoutes->Selection.Top - 1].Airports.front();

		WindowsUtility::OpenWebsite(L"https://maps.google.com/?q=" + start.Latitude + L"," + start.Longitude);
	}
}


void __fastcall TfrmMain::bOpenEndMapClick(TObject *Sender)
{
	if (sgRoutes->Selection.Top > 0 && GFlightHandler->Flights.size() != 0)
	{
		Airport end = GFlightHandler->Flights[sgRoutes->Selection.Top - 1].Airports.back();

		WindowsUtility::OpenWebsite(L"https://maps.google.com/?q=" + end.Latitude + L"," + end.Longitude);
	}
}


void __fastcall TfrmMain::miShowTooltipsClick(TObject *Sender)
{
	ShowHint = miShowTooltips->Checked;

	GConfiguration->System.ShowToolTips = miShowTooltips->Checked;
}


void __fastcall TfrmMain::cbTimeOfDayClick(TObject *Sender)
{
	rbDay->Enabled = cbTimeOfDay->Checked;
	rbNight->Enabled = cbTimeOfDay->Checked;

	AirportDetailsHaveChanged = true;
}


void __fastcall TfrmMain::tbCodeTestClick(TObject *Sender)
{
	#ifdef _DEBUG
	AircraftLoadFilter aircraft_lf = BuildAircraftLoadFilterFromUI();
	AirportLoadFilter airport_lf = BuildAirportLoadFilterFromUI();
	FlightFilter rf = BuildRouteLoadFilterFromUI();

	std::wstring code = GConfiguration->GenerateConfigCode(aircraft_lf, airport_lf, rf);

	eMagicCode->Text = code.c_str();
    #endif
}


void __fastcall TfrmMain::Select1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;
	TPopupMenu *pm = (TPopupMenu*)mi->GetParentMenu();
	TEdit *edit = (TEdit*)pm->PopupComponent;

	frmAirportSearchDialog->SetSelectionMode(true);

	if (frmAirportSearchDialog->ShowModal() == mrOk)
	{
		edit->Text = frmAirportSearchDialog->SelectedICAO.c_str();

		eEndAirportICAOExit(nullptr);
	}
}


void __fastcall TfrmMain::eEndAirportICAOExit(TObject *Sender)
{
	if (eStartAirportICAO->Text != "" && eEndAirportICAO->Text != "")
	{
		double d = GAirportHandler->DistanceBetweenTwoAirports(eStartAirportICAO->Text.c_str(), eEndAirportICAO->Text.c_str());

		if (d >= 0)
		{
			std::wstring distance = L"(distance is " + std::to_wstring(static_cast<int>(d)) + L" nm from " + eStartAirportICAO->Text.c_str() + L" to " + eEndAirportICAO->Text.c_str() + L" )";

			lDistanceStartEnd->Caption = distance.c_str();
		}
		else
		{
			lDistanceStartEnd->Caption = "(journey not possible with current airport settings)";
		}
	}
	else
	{
		lDistanceStartEnd->Caption = "...";
    }
}


void __fastcall TfrmMain::miUseHomeAirportClick(TObject *Sender)
{
	if (GConfiguration->System.HomeAirport != L"")
	{
		TMenuItem *mi = (TMenuItem*)Sender;
		TPopupMenu *pm = (TPopupMenu*)mi->GetParentMenu();
		TEdit *edit = (TEdit*)pm->PopupComponent;

		edit->Text = GConfiguration->System.HomeAirport.c_str();
	}
}


void __fastcall TfrmMain::SetasHomeairport1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;
	TPopupMenu *pm = (TPopupMenu*)mi->GetParentMenu();
	TEdit *edit = (TEdit*)pm->PopupComponent;

	if (!edit->Text.IsEmpty())
	{
		GConfiguration->System.HomeAirport = edit->Text.c_str();
	}
}


void __fastcall TfrmMain::puSelectICAOPopup(TObject *Sender)
{
	miUseHomeAirport->Enabled = !(GConfiguration->System.HomeAirport == L"");
}


void __fastcall TfrmMain::England1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;

	eRegionICO->Text = Location::ISORegions[mi->Tag].c_str();
}


void __fastcall TfrmMain::N8Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;
	TPopupMenu *pm = (TPopupMenu*)mi->GetParentMenu();
	TEdit *edit = (TEdit*)pm->PopupComponent;

	edit->Text = "";
}


void __fastcall TfrmMain::N9Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;

	eDirection->Text = Constants::CompassDegrees[mi->Tag];
}

void __fastcall TfrmMain::DistancefromAtoB1Click(TObject *Sender)
{
	frmDistanceCalc->ShowModal();
}

void __fastcall TfrmMain::BarraAirport1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;
	TPopupMenu *pm = (TPopupMenu*)mi->GetParentMenu();
	TEdit *edit = (TEdit*)pm->PopupComponent;

	if (mi->Tag < Location::HandCraftedICAOCount)
	{
     	edit->Text = Location::HandCraftedICAO[mi->Tag].c_str();

		if (!edit->Text.IsEmpty())
		{
			eEndAirportICAOExit(nullptr);
		}
	}
}


void __fastcall TfrmMain::cbRWAirlineClick(TObject *Sender)
{
	cbRWAirlines->Enabled = cbRWAirline->Checked;
}


void __fastcall TfrmMain::cbRWUseFlightTimeClick(TObject *Sender)
{
	eRWFlightTime->Enabled = cbRWUseFlightTime->Checked;

	if (cbRWUseAircraftRange->Checked)
	{
		eRWRange->Enabled = false;
	}
	else
	{
		eRWRange->Enabled = !cbRWUseFlightTime->Checked;
	}
}


void __fastcall TfrmMain::pcRouteChange(TObject *Sender)
{
	switch (pcRoute->TabIndex)
	{
	case 0:
		gbGo->Caption = "Random Route Generation";
		break;
	case 1:
		gbGo->Caption = "Random Real-World Route Finder";
		break;
    }
}


void __fastcall TfrmMain::eRWAirportExit(TObject *Sender)
{
	if (eRWAirport->Text != "")
	{
		if (rbRWFromICAO->Checked)
		{
			if (!GRouteHandler->IsValidFromAirport(eRWAirport->Text.c_str()))
			{
				eRWAirport->Text = "";

				sbMain->SimpleText = "Invalid airport for route start.";
			}
		}
		else
		{
			if (!GRouteHandler->IsValidToAirport(eRWAirport->Text.c_str()))
			{
				eRWAirport->Text = "";

                sbMain->SimpleText = "Invalid airport for route desination.";
			}
		}
	}
}


void __fastcall TfrmMain::miRange1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;
	TPopupMenu *pm = (TPopupMenu*)mi->GetParentMenu();
	TEdit *edit = (TEdit*)pm->PopupComponent;

	edit->Text = mi->Tag;
}


void __fastcall TfrmMain::AustraliaCanberra1Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;
	TPopupMenu *pm = (TPopupMenu*)mi->GetParentMenu();
	TEdit *edit = (TEdit*)pm->PopupComponent;

	edit->Text = Location::CityLongitude[mi->Tag];
}


void __fastcall TfrmMain::asmaniaHobart2Click(TObject *Sender)
{
	TMenuItem *mi = (TMenuItem*)Sender;
	TPopupMenu *pm = (TPopupMenu*)mi->GetParentMenu();
	TEdit *edit = (TEdit*)pm->PopupComponent;

	edit->Text = Location::CityLatitude[mi->Tag];
}


void __fastcall TfrmMain::bSaveRoutesClick(TObject *Sender)
{
	sdMain->Filter = "CSV files|*.csv";
	sdMain->DefaultExt = ".csv";

	if (sdMain->Execute())
	{
		for (int t = 0; t < GFlightHandler->Flights.size(); t++)
		{
			if (GFlightHandler->Flights[t].Simple)
			{
				GAirportHandler->Populate(t);
			}
		}

		GFlightHandler->SaveToCSV(sdMain->FileName.c_str());
	}
}


void __fastcall TfrmMain::miOpenRouteFolderClick(TObject *Sender)
{
	WindowsUtility::OpenWebsite(L"Reports\\");
}


void __fastcall TfrmMain::pcGeographyChange(TObject *Sender)
{
	AirportDetailsHaveChanged = true;
}


void __fastcall TfrmMain::bShowSearchParametersClick(TObject *Sender)
{
	mRouteDebug->Visible  = !mRouteDebug->Visible;
}


