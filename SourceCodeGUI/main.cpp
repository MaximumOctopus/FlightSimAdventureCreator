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
#include <System.SysUtils.hpp>
#pragma hdrstop

#include "About.h"
#include "AirportSearchDialog.h"

#include "AircraftConstants.h"
#include "DateUtility.h"
#include "Configuration.h"
#include "Formatting.h"
#include "GlobalObjects.h"
#include "Locations.h"
#include "main.h"
#include "MSFSSystem.h"
#include "RouteHandler.h"
#include "Utility.h"

#pragma package(smart_init)
#pragma resource "*.dfm"


extern AircraftHandler* GAircraftHandler;
extern AirportHandler* GAirportHandler;
extern Configuration* GConfiguration;
extern RouteHandler* GRouteHandler;


TForm1 *Form1;


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TForm1::FormCreate(TObject *Sender)
{
	srand((unsigned)time(NULL));

	std::wstring c = L"FSAC " + SystemConstants::FSACVersion + L" / " + SystemConstants::FSACDate;

    Caption = c.c_str();

	if (GlobalObjects::CreateGlobalObjects())
	{
		sgRoutes->ColAlignments[4] = taRightJustify;

		sgRoutes->Cells[0][0] = L"Route";
		sgRoutes->Cells[1][0] = L"Cntnt";
		sgRoutes->Cells[2][0] = L"Cntry";
		sgRoutes->Cells[3][0] = L"Rgn";
		sgRoutes->Cells[4][0] = L"Length";

		ResetGUI();

		UpdateAircraftList();

		UpdateCountryList();
	}

	lStatsAircraft->Caption = System::Sysutils::IntToStr((int)GAircraftHandler->AircraftList.size());
	lStatsAirport->Caption = System::Sysutils::IntToStr((int)GAirportHandler->Airports.size());
}


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    GlobalObjects::FreeGlobalObjects();
}


#pragma region GUI_Build_Update
void TForm1::BuildGUIFrom(AircraftLoadFilter& aclf, AirportLoadFilter& aplf, RouteFilter& rf)
{
	// ============================================================================================
	// == build aircraft section ==================================================================
	// ============================================================================================

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

	// ============================================================================================
	// == build airport section ===================================================================
	// ============================================================================================

	cbContinentFilter->Checked = aplf.FilterContinent;

	cbContinentAF->Checked = aplf.Continents[0];
	cbContinentAN->Checked = aplf.Continents[1];
	cbContinentAS->Checked = aplf.Continents[2];
	cbContinentEU->Checked = aplf.Continents[3];
	cbContinentNA->Checked = aplf.Continents[4];
	cbContinentOC->Checked = aplf.Continents[5];
	cbContinentSA->Checked = aplf.Continents[6];

	cbCountryFilter->Checked = aplf.FilterCountry;
	cbCountryList->ItemIndex = Utility::GetCountryFromShortCodeAsInt(aplf.Country);

	cbRegionFilter->Checked = aplf.FilterRegion;

	eRegionICO->Text = aplf.Region.c_str();

	cbLatLongFilter->Checked = aplf.FilterLatLong;

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

    bUpdateAirportsClick(nullptr);

	// ============================================================================================
	// == build route section =====================================================================
	// ============================================================================================

	eRange->Text = rf.Range;
	eLegs->Text = rf.Legs;
	eCount->Text = rf.Count;

	cbUseDirection->Checked = rf.UseDirection;
	eDirection->Text = rf.Direction;

	eStartAirportICAO->Text = rf.StartAirportICAO.c_str();
	eEndAirportICAO->Text = rf.EndAirportICAO.c_str();

	cbStartFromFavourite->Checked = rf.StartFromFavourite;

	cbUseAircraftRange->Checked = rf.UseAircraftRange;
	eAircraftRangeModifier->Text = rf.AircraftRangeModifier;

	cbUseFlightTime->Checked = rf.UseFlightTime;
	eFlightTime->Text = rf.FlightTime;
}


void TForm1::UpdateGUI()
{
	for (int t = 0; t < 16; t++)
	{
		cbBearing->Items->Add(Constants::CompassBearings[t].c_str());
	}

	cbBearing->ItemIndex = 0;
}


void TForm1::ResetGUI()
{
	AircraftLoadFilter aclf;
	AirportLoadFilter aplf;
	RouteFilter rf;

	BuildGUIFrom(aclf, aplf, rf);
}
#pragma end_region


void __fastcall TForm1::bUpdateAircraftClick(TObject *Sender)
{
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
}


void TForm1::UpdateAircraftList()
{
	cbAircraftList->Items->Clear();

	for (int t = 0; t < GAircraftHandler->FilteredList.size(); t++)
	{
		cbAircraftList->Items->Add(GAircraftHandler->FilteredList[t].Name.c_str());
	}

	cbAircraftList->ItemIndex = 0;

    cbAircraftListChange(nullptr);
}


void __fastcall TForm1::bUpdateAirportsClick(TObject *Sender)
{
	AirportLoadFilter alf = BuildAirportLoadFilterFromUI();

	int count = GAirportHandler->Filter(alf);

	gbAirports->Caption = "Airports (" + System::Sysutils::IntToStr((int)GAirportHandler->FilteredList.size()) + " selected)";
}


AircraftLoadFilter TForm1::BuildAircraftLoadFilterFromUI()
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

	return alf;
}


AirportLoadFilter TForm1::BuildAirportLoadFilterFromUI()
{
	AirportLoadFilter alf;

	alf.FilterContinent = cbContinentFilter->Checked;

	if (cbContinentAF->Checked) alf.Continents[0] = true;
	if (cbContinentAN->Checked) alf.Continents[1] = true;
	if (cbContinentAS->Checked) alf.Continents[2] = true;
	if (cbContinentEU->Checked) alf.Continents[3] = true;
	if (cbContinentNA->Checked) alf.Continents[4] = true;
	if (cbContinentOC->Checked) alf.Continents[5] = true;
	if (cbContinentSA->Checked) alf.Continents[6] = true;

	alf.FilterCountry = cbCountryFilter->Checked;
	if (cbCountryList->ItemIndex != -1)
	{
		alf.Country = Location::ISOCountriesOrdered[cbCountryList->ItemIndex][1];
	}

	alf.FilterRegion = cbRegionFilter->Checked;
	alf.Region = eRegionICO->Text.c_str();

	alf.FilterLatLong = cbLatLongFilter->Checked;

	alf.LatitudeFrom = eLatFrom->Text.ToDouble();
	alf.LatitudeTo = eLatTo->Text.ToDouble();
	alf.LongitudeFrom = eLongFrom->Text.ToDouble();
	alf.LongitudeTo = eLongTo->Text.ToDouble();

	if (alf.LatitudeFrom < alf.LatitudeTo)
	{
		alf.LatitudeInverse = true;
	}

	if (alf.LongitudeFrom < alf.LongitudeTo)
	{
		alf.LongitudeInverse = true;
	}

	alf.MinimumElevation = eElevation->Text.ToIntDef(DataDefaults::LowestElevation);

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


RouteFilter TForm1::BuildRouteLoadFilterFromUI()
{
	RouteFilter rf;

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

	return rf;
}


void TForm1::UpdateCountryList()
{
	cbCountryList->Clear();

	for (int t = 0; t < Location::ISOCountriesCount; t++)
	{
		cbCountryList->Items->Add(Location::ISOCountriesOrdered[t][0].c_str());
	}

    cbCountryList->ItemIndex = 0;
}


void __fastcall TForm1::bSetFromBearingClick(TObject *Sender)
{
	eDirection->Text = Constants::CompassDegrees[cbBearing->ItemIndex];
}


void __fastcall TForm1::bGenerateClick(TObject *Sender)
{
	if (GAircraftHandler->FilteredList.size() != 0 && GAirportHandler->FilteredList.size() != 0)
	{
		GenerateRoutes();

		UpdateRouteList();
	}
}


void TForm1::GenerateRoutes()
{
    double RouteDirection = DataDefaults::Direction; // to do; all these need setting if UI says so / not default value
	double RouteRange = eRange->Text.ToDouble();
	int RouteLegs = eLegs->Text.ToInt();
	int RouteCount = eCount->Text.ToIntDef(1);

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

		if (RouteLegs != 1 && RouteRange != DataDefaults::Range)
		{
			//std::wcout << L"  Setting start and end aiports is not compatible with setting legs and range (can't have both!). Using range.\n\n";
		}

		if (RouteRange != DataDefaults::Range)
		{
			RouteLegs = (d / RouteRange) + 1;
		}
		else
        {
			RouteRange = d / RouteLegs;
		}

		//std::wcout << std::format(L"  Set range/legs based on distance {0:.1f} from {1} to {2}. Range {3} nm; Legs {4}.\n\n", d, GConfiguration->Route.StartAirportICAO, GConfiguration->Route.EndAirportICAO, GConfiguration->Route.Range, GConfiguration->Route.Legs);
	}

	int random_aircraft = rand() % cbAircraftList->Items->Count;
	cbAircraftList->ItemIndex = random_aircraft;
    cbAircraftListChange(nullptr);

	Aircraft aircraft = GAircraftHandler->AircraftList[random_aircraft];

  //  std::wcout << L"    " << GJobHandler->GetJob(aircraft.Type, aircraft.Airliner, aircraft.Military) << L"\n\n";

	if (cbUseFlightTime->Checked)
	{
		if (eFlightTime->Text.ToIntDef(0) != 0)
		{
			int new_range = GRouteHandler->SetRangeFromTime(eFlightTime->Text.ToIntDef(0), RouteLegs, aircraft.CruiseSpeed, aircraft.Type);

			if (new_range != -1)
			{
				RouteRange = new_range;
			}

			//std::wcout << std::format(L"  Set range to {0} nm, based on {1} min flight time.\n", GConfiguration->Route.Range, GConfiguration->Route.RequestedFlightTime);
		}
	}

	double potential_route_length = RouteRange * (double)RouteLegs;
	double usable_aircraft_range = ((double)aircraft.Range * (eAircraftRangeModifier->Text.ToIntDef(DataDefaults::RangeModifier) / 100));
	double range_per_leg = RouteRange;

	//std::wcout << std::format(L"   Potential route length : {0:.1f} nm", potential_route_length) << L"\n";
	//std::wcout << std::format(L"   Usable aircraft range  : {0:.1f} nm ({1}% of max. {2} nm)", usable_aircraft_range, GConfiguration->Route.AircraftRangePercent, aircraft.Range) << L"\n\n";

	if (cbUseAircraftRange->Checked)
	{
		range_per_leg = ((double)aircraft.Range * (eAircraftRangeModifier->Text.ToIntDef(DataDefaults::RangeModifier) / 100)) / (double)RouteLegs;
	}
    else
    {
        if (range_per_leg > usable_aircraft_range)
		{
			//std::wcout << L" User range (per leg) is greater than aircraft range, using aircraft range!\n";

		   //	range_per_leg = ((double)aircraft.Range * (eAircraftRangeModifier->Text.ToIntDef(DataDefaults::RangeModifier) / 100)) / (double)RouteLegs;
		}
		else if (potential_route_length > usable_aircraft_range && !cbAllowExcessRange->Checked)
		{
			//std::wcout << L" User range too large for aircraft and leg count, using aircraft range!\n";

		   //	range_per_leg = ((double)aircraft.Range * (eAircraftRangeModifier->Text.ToIntDef(DataDefaults::RangeModifier) / 100)) / (double)RouteLegs;
        }
	}

	//std::wcout << std::format(L"  Max. range (per leg): {0:.1f} nm; legs: {1}", range_per_leg, GConfiguration->Route.Legs) << L"\n\n";

	GAirportHandler->GetRoute(eStartAirportICAO->Text.c_str(), eEndAirportICAO->Text.c_str(), range_per_leg, RouteDirection, RouteLegs, RouteCount,	cbKeepTrying->Checked);
}


void TForm1::UpdateRouteList()
{
	if (GRouteHandler->Routes.size() != 0)
	{
		sgRoutes->RowCount = GRouteHandler->Routes.size() + 1;

		for (int t = 0; t < GRouteHandler->Routes.size(); t++)
		{
			std::wstring d = std::to_wstring(GRouteHandler->Routes[t].Distance) + L" nm";

			sgRoutes->Cells[0][t + 1] = GRouteHandler->Routes[t].Name.c_str();

			sgRoutes->Cells[1][t + 1] = GRouteHandler->Routes[t].Continent.c_str();
			sgRoutes->Cells[2][t + 1] = GRouteHandler->Routes[t].Country.c_str();
			sgRoutes->Cells[3][t + 1] = GRouteHandler->Routes[t].Region.c_str();

			sgRoutes->Cells[4][t + 1] = d.c_str();
		}
	}
}


void __fastcall TForm1::cbLatLongFilterClick(TObject *Sender)
{
	if (cbLatLongFilter->Checked && cbTimeOfDay->Checked)
	{
		TCheckBox *cb = (TCheckBox*)Sender;

		if (cb->Tag == 0)
		{
			cbTimeOfDay->Checked = false;
		}
		else
		{
			cbLatLongFilter->Checked = false;
		}
	}
}


void __fastcall TForm1::cbContinentFilterClick(TObject *Sender)
{
	TCheckBox *cb = (TCheckBox*)Sender;

	if (cb->Checked)
	{
        switch (cb->Tag)
		{
		case 0:
			cbCountryFilter->Checked = false;
			cbRegionFilter->Checked = false;
			break;
		case 1:
			cbContinentFilter->Checked = false;
			cbRegionFilter->Checked = false;
			break;
		case 2:
			cbContinentFilter->Checked = false;
			cbCountryFilter->Checked = false;
			break;
		}
	}
}


void __fastcall TForm1::tbResetClick(TObject *Sender)
{
	if (Application->MessageBox(L"hello", L"Are you sure?", MB_OKCANCEL) == IDOK)
	{
		ResetGUI();
	}
}


void __fastcall TForm1::tbSaveClick(TObject *Sender)
{
	AircraftLoadFilter aircraft_lf = BuildAircraftLoadFilterFromUI();
	AirportLoadFilter airport_lf = BuildAirportLoadFilterFromUI();
	RouteFilter rf = BuildRouteLoadFilterFromUI();

	if (sdMain->Execute())
	{
		std::wstring file_name = sdMain->FileName.c_str();

		if (GConfiguration->SaveConfiguration(file_name, aircraft_lf, airport_lf, rf))
		{

        }
	}
}


void __fastcall TForm1::tbOpenClick(TObject *Sender)
{
	AircraftLoadFilter aclf;
	AirportLoadFilter aplf;
	RouteFilter rf;

	if (odMain->Execute())
	{
		std::wstring file_name = odMain->FileName.c_str();

		if (GConfiguration->LoadConfiguration(file_name, aclf, aplf, rf))
		{
            BuildGUIFrom(aclf, aplf, rf);
        }
    }
}


void __fastcall TForm1::tbExportClick(TObject *Sender)
{
	GRouteHandler->ExportToMSFS();
}


void __fastcall TForm1::tbExportItineraryClick(TObject *Sender)
{
    GRouteHandler->ExportToItinerary();
}


void __fastcall TForm1::Createcustomaircrafttxt1Click(TObject *Sender)
{
	if (Application->MessageBox(L"hello", L"Are you sure?", MB_OKCANCEL) == IDOK)
	{
		if (MSFSSystem::CreateAircraftList(true))
		{
			sbMain->SimpleText = "'custom_aircraft.txt' file created successfully.";
		}
		else
		{
			sbMain->SimpleText = "Error creating 'custom_aircraft.txt' file.";
        }
    }
}


void __fastcall TForm1::About1Click(TObject *Sender)
{
    frmAbout->ShowModal();
}


void __fastcall TForm1::sgRoutesClick(TObject *Sender)
{
	if (sgRoutes->Selection.Top > 0)
	{
		UpdateRouteDescription(sgRoutes->Selection.Top - 1);
	}
}


void TForm1::UpdateRouteDescription(int route_id)
{
	mMain->Clear();

	Route r = GRouteHandler->Routes[route_id];

	std::wstring output = L" Starting at: " + r.Airports[0].Ident + L" (" + r.Airports[0].Country + L", " + std::to_wstring(r.Airports[0].Angle) + L"°)";

	mMain->Lines->Add(output.c_str());

	for (int t = 1; t < r.Airports.size(); t++)
	{
		if (t == r.Airports.size() - 1)
		{
			output = Formatting::AddLeadingSpace(std::to_wstring((int)r.Airports[t].Distance), 7) + L"nm --> " + r.Airports[t].Ident + L" (" + r.Airports[t].Country + L")";
		}
		else
		{
			output = Formatting::AddLeadingSpace(std::to_wstring((int)r.Airports[t].Distance), 7) + L"nm --> " + r.Airports[t].Ident + L" (" + r.Airports[t].Country + L", " + std::to_wstring(r.Airports[t].Angle) + L"°)";
		}

		mMain->Lines->Add(output.c_str());
	}
}


void __fastcall TForm1::cbAircraftListChange(TObject *Sender)
{
	if (cbAircraftList->ItemIndex != -1)
	{
		lAircraftStats->Caption = GAircraftHandler->FilteredList[cbAircraftList->ItemIndex].ShowStats().c_str();
    }
}


void __fastcall TForm1::miSetGAClick(TObject *Sender)
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
	}

    bUpdateAircraftClick(nullptr);
}


void TForm1::SetAircraftSelections(bool prop, bool jet, bool heli, bool glider, bool twinprop, bool turboprop, bool ttp, bool balloon, bool airliner, bool military, bool seaplane)
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


void __fastcall TForm1::Airports1Click(TObject *Sender)
{
	frmAirportSearchDialog->ShowModal();
}
