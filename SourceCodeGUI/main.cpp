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
#include "Favourites.h"

#include "AircraftConstants.h"
#include "DateUtility.h"
#include "Configuration.h"
#include "Formatting.h"
#include "GlobalObjects.h"
#include "Locations.h"
#include "main.h"
#include "MSFSSystem.h"
#include "RouteHandler.h"
#include "RunwayHandler.h"
#include "Utility.h"
#include "WindowsUtility.h"

#pragma package(smart_init)
#pragma resource "*.dfm"


extern AircraftHandler* GAircraftHandler;
extern AirportHandler* GAirportHandler;
extern Configuration* GConfiguration;
extern RouteHandler* GRouteHandler;
extern RunwayHandler* GRunwayHandler;


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

	lStatsAircraft->Caption = System::Sysutils::IntToStr((int)GAircraftHandler->AircraftList.size());
	lStatsAirport->Caption = System::Sysutils::IntToStr((int)GAirportHandler->Airports.size());
	lStatsRunways->Caption = System::Sysutils::IntToStr((int)GRunwayHandler->Runways.size());

	SetLabelStatus(GAircraftHandler->AircraftList.size(), lStatsAircraft);
	SetLabelStatus(GAirportHandler->Airports.size(), lStatsAirport);
	SetLabelStatus(GRunwayHandler->Runways.size(), lStatsRunways);
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

	if (cbContinentFilter->Checked)
	{
		cbContinentFilterClick(cbContinentFilter);
	}

	if (cbCountryFilter->Checked)
	{
		cbContinentFilterClick(cbCountryFilter);
	}

	if (cbRegionFilter->Checked)
	{
		cbContinentFilterClick(cbRegionFilter);
	}

	if (cbLatLongFilter->Checked)
	{
		cbLatLongFilterClick(cbLatLongFilter);
	}

	if (cbTimeOfDay->Checked)
	{
		cbLatLongFilterClick(cbTimeOfDay);
    }

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

	// ============================================================================================
	// == other ===================================================================================
	// ============================================================================================

	cbKeepTrying->Checked = rf.KeepTrying;
}


void TForm1::InitialGUISetup()
{
	sgRoutes->ColAlignments[4] = taRightJustify;

	sgRoutes->Cells[0][0] = L"Route";
	sgRoutes->Cells[1][0] = L"Cntnt";
	sgRoutes->Cells[2][0] = L"Cntry";
	sgRoutes->Cells[3][0] = L"Rgn";
	sgRoutes->Cells[4][0] = L"Length";

	for (int t = 0; t < 16; t++)
	{
		cbBearing->Items->Add(Constants::CompassBearings[t].c_str());
	}

	cbBearing->ItemIndex = 0;

	ShowHint = GConfiguration->System.ShowToolTips;
	miShowTooltips->Checked = ShowHint;
}


void TForm1::ResetGUI()
{
	AircraftLoadFilter aclf;
	AirportLoadFilter aplf;
	RouteFilter rf;

	BuildGUIFrom(aclf, aplf, rf);
}


void TForm1::SetLabelStatus(int test_value, TLabel *label)
{
	if (test_value == 0)
	{
		TLabel *l = (TLabel*)label;

		l->Font->Color = clRed;
		l->Font->Style = l->Font->Style << fsBold;
    }
}
#pragma end_region


void __fastcall TForm1::bUpdateAircraftClick(TObject *Sender)
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
	}
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
	sbMain->SimpleText = "Updating airport selection...";

	AirportLoadFilter alf = BuildAirportLoadFilterFromUI();

	int count = GAirportHandler->Filter(alf);

	gbAirports->Caption = "Airports (" + System::Sysutils::IntToStr((int)GAirportHandler->FilteredList.size()) + " selected)";

    sbMain->SimpleText = "";
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


AirportLoadFilter TForm1::BuildAirportLoadFilterFromUI()
{
	AirportLoadFilter alf;

	alf.FilterContinent = cbContinentFilter->Checked;

	alf.Continents[0] = cbContinentAF->Checked;
	alf.Continents[1] = cbContinentAN->Checked;
	alf.Continents[2] = cbContinentAS->Checked;
	alf.Continents[3] = cbContinentEU->Checked;
	alf.Continents[4] = cbContinentNA->Checked;
	alf.Continents[5] = cbContinentOC->Checked;
	alf.Continents[6] = cbContinentSA->Checked;

	alf.FilterCountry = cbCountryFilter->Checked;
	if (cbCountryList->ItemIndex != -1)
	{
		alf.Country = Location::ISOCountriesOrdered[cbCountryList->ItemIndex][1];
	}

	alf.FilterRegion = cbRegionFilter->Checked;
	alf.Region = eRegionICO->Text.UpperCase().c_str();

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

	if (rf.FlightTime == 0)
	{
		rf.UseFlightTime = false;
	}

	rf.StartEndUseLegs = rbStartEndLegs->Checked;

	rf.KeepTrying = cbKeepTrying->Checked;

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
	if (!cbContinentFilter->Checked && !cbCountryFilter->Checked && !cbRegionFilter->Checked && !cbLatLongFilter->Checked && !cbTimeOfDay->Checked)
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

			GenerateRoutes();

			if (!UpdateRouteList())
			{
				sbMain->SimpleText = "No routes could be generated with selected locations and route parameters :(";
			}

            bGenerate->Enabled = true;
		}
	}
	else
	{
	    sbMain->SimpleText = "Can't generate route, not enough airports or aircraft!";
    }
}


void TForm1::GenerateRoutes()
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

	int selected_aircraft = cbAircraftList->ItemIndex;

	if (bLockAircraft->Tag == 0)
	{
		selected_aircraft = rand() % cbAircraftList->Items->Count;
		cbAircraftList->ItemIndex = selected_aircraft;
		cbAircraftListChange(nullptr);
	}

	Aircraft aircraft = GAircraftHandler->AircraftList[selected_aircraft];

    // =========================================================================

  //  std::wcout << L"    " << GJobHandler->GetJob(aircraft.Type, aircraft.Airliner, aircraft.Military) << L"\n\n";

	if (cbUseFlightTime->Checked)
	{
		if (eFlightTime->Text.ToIntDef(0) != 0)
		{
			int new_range = GRouteHandler->SetRangeFromTime(eFlightTime->Text.ToIntDef(0), RouteLegs, aircraft.CruiseSpeed, aircraft.Type);

			if (new_range != -1)
			{
				RouteRange = new_range;

				FlightTime = eFlightTime->Text.ToIntDef(0);
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

			range_per_leg = ((double)aircraft.Range * (eAircraftRangeModifier->Text.ToIntDef(DataDefaults::RangeModifier) / 100)) / (double)RouteLegs;
		}
		else if (potential_route_length > usable_aircraft_range && !cbAllowExcessRange->Checked)
		{
			//std::wcout << L" User range too large for aircraft and leg count, using aircraft range!\n";

			range_per_leg = ((double)aircraft.Range * (eAircraftRangeModifier->Text.ToIntDef(DataDefaults::RangeModifier) / 100)) / (double)RouteLegs;
        }
	}

	//std::wcout << std::format(L"  Max. range (per leg): {0:.1f} nm; legs: {1}", range_per_leg, GConfiguration->Route.Legs) << L"\n\n";

	BuildRouteDescription(eStartAirportICAO->Text.c_str(), eEndAirportICAO->Text.c_str(), range_per_leg, RouteDirection, RouteLegs, RouteCount,	FlightTime, cbKeepTrying->Checked);

	GAirportHandler->GetRoute(eStartAirportICAO->Text.c_str(), eEndAirportICAO->Text.c_str(), range_per_leg, RouteDirection, RouteLegs, RouteCount,	cbKeepTrying->Checked);

	sbMain->SimpleText = "Finished generating routes.";
}


bool TForm1::UpdateRouteList()
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

		return true;
	}
	else
	{
		sgRoutes->RowCount = 2;

		sgRoutes->Cells[0][1] = "No routes could be generated :(";

		sgRoutes->Cells[1][1] = "";
		sgRoutes->Cells[2][1] = "";
		sgRoutes->Cells[3][1] = "";

		sgRoutes->Cells[4][1] = "";
    }

    return false;
}


void TForm1::BuildRouteDescription(const std::wstring start_icao, const std::wstring end_icao, double range, double direction, int legs, int simple_count, int flight_time, bool keep_trying)
{
	std::wstring RouteDescription = L"";

	if (start_icao == L"")
	{
		RouteDescription = L"Random -> ";
	}
	else
	{
		RouteDescription = start_icao + L" -> ";
	}

	if (end_icao == L"")
	{
		RouteDescription += L"Random; ";
	}
	else
	{
		RouteDescription += end_icao + L"; ";
	}

	if (flight_time == 0)
	{
		RouteDescription += std::to_wstring(static_cast<int>(range)) + L" nm; ";
	}
	else
	{
		RouteDescription += std::to_wstring(static_cast<int>(range)) + L" nm (flight time " + std::to_wstring(flight_time) + L" mins); ";
    }

	if (direction != -1)
	{
		RouteDescription += L"@ " + std::to_wstring(direction) + L"°; ";
	}

	RouteDescription += std::to_wstring(legs) + L" leg(s); ";

	if (legs == 1)
	{
		RouteDescription += std::to_wstring(simple_count) + L" routes (max.); ";
	}
	else
	{
		RouteDescription += std::to_wstring(simple_count) + L" routes; ";
	}

	if (keep_trying)
	{
        RouteDescription += L" keep trying (<21 times); ";
    }

	mRouteDebug->Text = RouteDescription.c_str();
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

 	eLatFrom->Enabled = cbLatLongFilter->Checked;
	eLatTo->Enabled = cbLatLongFilter->Checked;
	eLongFrom->Enabled = cbLatLongFilter->Checked;
	eLongTo->Enabled = cbLatLongFilter->Checked;

	rbDay->Enabled = cbTimeOfDay->Checked;
	rbNight->Enabled = cbTimeOfDay->Checked;

    AirportDetailsHaveChanged = true;
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

		cbContinentAF->Enabled = cbContinentFilter->Checked;
		cbContinentAN->Enabled = cbContinentFilter->Checked;
		cbContinentAS->Enabled = cbContinentFilter->Checked;
		cbContinentEU->Enabled = cbContinentFilter->Checked;
		cbContinentNA->Enabled = cbContinentFilter->Checked;
		cbContinentOC->Enabled = cbContinentFilter->Checked;
		cbContinentSA->Enabled = cbContinentFilter->Checked;

		cbCountryList->Enabled = cbCountryFilter->Checked;

		eRegionICO->Enabled = cbRegionFilter->Checked;
	}

    AirportDetailsHaveChanged = true;
}


void __fastcall TForm1::tbResetClick(TObject *Sender)
{
	if (Application->MessageBox(L"This will reset all parameters to their defaults.", L"Reset Parameters?", MB_OKCANCEL) == IDOK)
	{
		ResetGUI();
	}
}


void __fastcall TForm1::tbSaveClick(TObject *Sender)
{
	sdMain->Filter = "FSAC configuration files|*.config";
    sdMain->DefaultExt = ".config";

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
	GRouteHandler->ExportAllToMSFS();
}


void __fastcall TForm1::tbExportItineraryClick(TObject *Sender)
{
	GRouteHandler->ExportAllToItinerary();
}


void __fastcall TForm1::Createcustomaircrafttxt1Click(TObject *Sender)
{
	if (Application->MessageBox(L"This will overwrite the existing file, all edits will be lost.", L"Create new 'custom_aircraft.txt'?", MB_OKCANCEL) == IDOK)
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
	if (sgRoutes->Selection.Top > 0 && GRouteHandler->Routes.size() != 0)
	{
		UpdateRouteDescription(sgRoutes->Selection.Top - 1);
	}
}


void TForm1::UpdateRouteDescription(int route_id)
{
	mMain->Clear();

	Route r = GRouteHandler->Routes[route_id];

	std::wstring output = L" Starting at: " + r.Airports[0].Ident + L" (" + r.Airports[0].Country + L", " + std::to_wstring(r.Airports[1].Angle) + L"°)";

	mMain->Lines->Add(output.c_str());

	for (int t = 1; t < r.Airports.size(); t++)
	{
		if (t == r.Airports.size() - 1)
		{
			output = Formatting::AddLeadingSpace(std::to_wstring((int)r.Airports[t].Distance), 7) + L"nm --> " + r.Airports[t].Ident + L" (" + r.Airports[t].Country + L")";
		}
		else
		{
			output = Formatting::AddLeadingSpace(std::to_wstring((int)r.Airports[t].Distance), 7) + L"nm --> " + r.Airports[t].Ident + L" (" + r.Airports[t].Country + L", " + std::to_wstring(r.Airports[t + 1].Angle) + L"°)";
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
		case 6:
			SetAircraftSelections(false, true, false, false, false, false, false, false, false, true, false);
			break;
		case 7:
			SetAircraftSelections(true, false, false, false, true, true, true, false, false, true, false);
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


void __fastcall TForm1::bExportSelectedClick(TObject *Sender)
{
	if (sgRoutes->Selection.Top > 0 && GRouteHandler->Routes.size() != 0)
	{
		sdMain->Filter = "MSFS 2020 plan files|*.pln";
		sdMain->DefaultExt = ".pln";
		sdMain->FileName = GRouteHandler->Routes[sgRoutes->Selection.Top].GetMSFSFileName().c_str();

		if (sdMain->Execute())
		{
			std::wstring file_name = sdMain->FileName.c_str();

			GRouteHandler->ExportToMSFS(file_name, sgRoutes->Selection.Top);
		}
	}
}


void __fastcall TForm1::bExportSelectedTextClick(TObject *Sender)
{
	if (sgRoutes->Selection.Top > 0 && GRouteHandler->Routes.size() != 0)
	{
		sdMain->Filter = "Itinerary text files|*.txt";
		sdMain->DefaultExt = ".txt";
		sdMain->FileName = GRouteHandler->Routes[sgRoutes->Selection.Top].GetTextFileName().c_str();

		if (sdMain->Execute())
		{
			std::wstring file_name = sdMain->FileName.c_str();

			GRouteHandler->ExportToItinerary(file_name, sgRoutes->Selection.Top);
		}
	}
}


void __fastcall TForm1::Favourites1Click(TObject *Sender)
{
	frmFavourites->ShowModal();
}


void __fastcall TForm1::bLockAircraftClick(TObject *Sender)
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


void __fastcall TForm1::bRandomAircraftClick(TObject *Sender)
{
	if (cbAircraftList->Items->Count != 0 && bLockAircraft->Tag == 0)
	{
		cbAircraftList->ItemIndex = rand() % cbAircraftList->Items->Count;
		cbAircraftListChange(nullptr);
    }
}


void __fastcall TForm1::cbAircraftTypePropsClick(TObject *Sender)
{
	AircraftDetailsHaveChanged = true;
}


void __fastcall TForm1::cbContinentAFClick(TObject *Sender)
{
	AirportDetailsHaveChanged = true;
}


void __fastcall TForm1::cbUseFlightTimeClick(TObject *Sender)
{
	eFlightTime->Enabled = cbUseFlightTime->Checked;
	eRange->Enabled = !cbUseFlightTime->Checked;
}


void __fastcall TForm1::cbUseDirectionClick(TObject *Sender)
{
	eDirection->Enabled = cbUseDirection->Checked;
	cbBearing->Enabled = cbUseDirection->Checked;
	bSetFromBearing->Enabled = cbUseDirection->Checked;
}


// used by MinSpeed, Range, FlightTime, Legs, and RouteCount
void __fastcall TForm1::eLegsExit(TObject *Sender)
{
	TEdit *edit = (TEdit*)Sender;

	int i = edit->Text.ToIntDef(0);

	if (i < 1)
	{
		edit->Text = "1";
	}
}


// ensures user sets elevation to a sensible value
void __fastcall TForm1::eElevationExit(TObject *Sender)
{
	TEdit *edit = (TEdit*)Sender;

	int i = edit->Text.ToIntDef(-3000);

	if (i < -2000)
	{
		edit->Text = "-2000";
	}
}


// handles edit boxes that require percent values 0-100
void __fastcall TForm1::eAircraftRangeModifierExit(TObject *Sender)
{
	TEdit *edit = (TEdit*)Sender;

	int i = edit->Text.ToIntDef(-1);

	if (i < 0)
	{
		edit->Text = "0";
	}

	if (i > 100)
	{
		edit->Text = "100";
	}
}


void __fastcall TForm1::Label31Click(TObject *Sender)
{
	WindowsUtility::OpenWebsite(L"https://en.wikipedia.org/wiki/ISO_3166-2");
}


void __fastcall TForm1::bOpenStartMapClick(TObject *Sender)
{
	if (sgRoutes->Selection.Top > 0 && GRouteHandler->Routes.size() != 0)
	{
		Airport start = GRouteHandler->Routes[sgRoutes->Selection.Top - 1].Airports.front();

		WindowsUtility::OpenWebsite(L"https://maps.google.com/?q=" + start.Latitude + L"," + start.Longitude);
	}
}


void __fastcall TForm1::bOpenEndMapClick(TObject *Sender)
{
	if (sgRoutes->Selection.Top > 0 && GRouteHandler->Routes.size() != 0)
	{
		Airport end = GRouteHandler->Routes[sgRoutes->Selection.Top - 1].Airports.back();

		WindowsUtility::OpenWebsite(L"https://maps.google.com/?q=" + end.Latitude + L"," + end.Longitude);
	}
}


void __fastcall TForm1::miShowTooltipsClick(TObject *Sender)
{
	ShowHint = miShowTooltips->Checked;

	GConfiguration->System.ShowToolTips = miShowTooltips->Checked;
}
