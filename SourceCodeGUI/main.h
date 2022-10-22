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

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ToolWin.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>

#include "AircraftHandler.h"
#include "AirportHandler.h"
#include "RouteHandler.h"
#include <Vcl.Dialogs.hpp>
#include <Vcl.Grids.hpp>


class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox3;
	TToolBar *ToolBar1;
	TToolButton *tbSave;
	TToolButton *tbOpen;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *File2;
	TMenuItem *Exit1;
	TMenuItem *Exit2;
	TStatusBar *sbMain;
	TImageList *ImageList1;
	TToolButton *ToolButton3;
	TLabel *Label4;
	TEdit *eLegs;
	TLabel *Label9;
	TEdit *eRange;
	TLabel *Label10;
	TLabel *Label11;
	TEdit *eStartAirportICAO;
	TLabel *Label12;
	TEdit *eEndAirportICAO;
	TLabel *Label13;
	TLabel *Label14;
	TCheckBox *cbUseAircraftRange;
	TCheckBox *cbStartFromFavourite;
	TCheckBox *cbUseDirection;
	TEdit *eDirection;
	TLabel *Label15;
	TComboBox *cbBearing;
	TButton *bSetFromBearing;
	TToolButton *tbReset;
	TBevel *Bevel7;
	TCheckBox *cbAllowExcessRange;
	TToolButton *ToolButton1;
	TEdit *eCount;
	TEdit *eFlightTime;
	TLabel *Label16;
	TCheckBox *cbUseFlightTime;
	TSaveDialog *sdMain;
	TOpenDialog *odMain;
	TBevel *Bevel9;
	TBevel *Bevel10;
	TLabel *Label17;
	TBevel *Bevel11;
	TStringGrid *sgRoutes;
	TToolButton *tbExport;
	TToolButton *tbExportItinerary;
	TMenuItem *ools1;
	TMenuItem *Createcustomaircrafttxt1;
	TMenuItem *Help1;
	TMenuItem *About1;
	TLabel *Label19;
	TMemo *mMain;
	TToolButton *ToolButton2;
	TGroupBox *GroupBox1;
	TButton *bGenerate;
	TCheckBox *cbKeepTrying;
	TGroupBox *GroupBox4;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *lStatsAircraft;
	TLabel *lStatsAirport;
	TLabel *Label23;
	TMenuItem *Ai1;
	TMenuItem *Set1;
	TMenuItem *miSetGA;
	TMenuItem *GA2;
	TMenuItem *wins1;
	TMenuItem *Props1;
	TMenuItem *urbos1;
	TMenuItem *Seaplanes1;
	TMenuItem *Searcg1;
	TMenuItem *Airports1;
	TCheckBox *cbEndAtFavourite;
	TGroupBox *gbAirports;
	TBevel *Bevel5;
	TBevel *Bevel4;
	TBevel *Bevel1;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TBevel *Bevel6;
	TLabel *Label24;
	TButton *bUpdateAirports;
	TCheckBox *cbContinentAF;
	TCheckBox *cbContinentAN;
	TCheckBox *cbContinentAS;
	TCheckBox *cbContinentEU;
	TCheckBox *cbContinentNA;
	TCheckBox *cbContinentOC;
	TCheckBox *cbContinentSA;
	TCheckBox *cbCountryFilter;
	TEdit *eLatFrom;
	TCheckBox *cbLatLongFilter;
	TEdit *eLatTo;
	TComboBox *cbCountryList;
	TEdit *eLongFrom;
	TEdit *eLongTo;
	TCheckBox *cbLargeAirports;
	TCheckBox *cbMediumAirports;
	TCheckBox *cbSmallAirports;
	TCheckBox *cbHeliports;
	TCheckBox *cbSeaplaneBases;
	TCheckBox *cbContinentFilter;
	TCheckBox *cbRegionFilter;
	TEdit *eRegionICO;
	TCheckBox *cbTimeOfDay;
	TRadioButton *rbDay;
	TRadioButton *rbNight;
	TButton *bExportSelected;
	TImageList *il16x16;
	TButton *bExportSelectedText;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *lStatsRunways;
	TLabel *Label30;
	TMenuItem *N1;
	TMenuItem *Favourites1;
	TMemo *mRouteDebug;
	TBevel *Bevel13;
	TLabel *Label18;
	TEdit *eElevation;
	TLabel *Label20;
	TRadioButton *rbStartEndLegs;
	TRadioButton *rbStartEndRange;
	TGroupBox *gbAircraft;
	TBevel *Bevel12;
	TLabel *lMinSpeed;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TBevel *Bevel8;
	TLabel *lAircraftStats;
	TLabel *Label26;
	TLabel *Label25;
	TEdit *eMinSpeed;
	TCheckBox *cbAircraftTypeProps;
	TCheckBox *cbAircraftTypeTwinProps;
	TCheckBox *cbAircraftTypeTurboProps;
	TCheckBox *cbAircraftTypeHelicopter;
	TCheckBox *cbAircraftTypeGlider;
	TCheckBox *cbAircraftTypeAirliners;
	TCheckBox *cbAircraftTypeMilitary;
	TCheckBox *cbAircraftTypeTwinTurboProps;
	TCheckBox *cbAircraftTypeJet;
	TCheckBox *cbAircraftTypeBalloon;
	TComboBox *cbAircraftList;
	TButton *bUpdateAircraft;
	TCheckBox *cbAircraftTypeSeaplanes;
	TEdit *eMaxSpeed;
	TComboBox *cbMSFSVersion;
	TEdit *eAircraftRangeModifier;
	TButton *bRandomAircraft;
	TButton *bLockAircraft;
	TLabel *Label29;
	TMenuItem *N2;
	TMenuItem *Militaryjets1;
	TMenuItem *Militarypropsturbo1;
	TLabel *Label31;
	TButton *bOpenStartMap;
	TButton *bOpenEndMap;
	TLabel *Label32;
	TMenuItem *N3;
	TMenuItem *miShowTooltips;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall bUpdateAircraftClick(TObject *Sender);
	void __fastcall bUpdateAirportsClick(TObject *Sender);
	void __fastcall bSetFromBearingClick(TObject *Sender);
	void __fastcall bGenerateClick(TObject *Sender);
	void __fastcall cbLatLongFilterClick(TObject *Sender);
	void __fastcall cbContinentFilterClick(TObject *Sender);
	void __fastcall tbResetClick(TObject *Sender);
	void __fastcall tbSaveClick(TObject *Sender);
	void __fastcall tbOpenClick(TObject *Sender);
	void __fastcall tbExportClick(TObject *Sender);
	void __fastcall tbExportItineraryClick(TObject *Sender);
	void __fastcall Createcustomaircrafttxt1Click(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);
	void __fastcall sgRoutesClick(TObject *Sender);
	void __fastcall cbAircraftListChange(TObject *Sender);
	void __fastcall miSetGAClick(TObject *Sender);
	void __fastcall Airports1Click(TObject *Sender);
	void __fastcall bExportSelectedClick(TObject *Sender);
	void __fastcall bExportSelectedTextClick(TObject *Sender);
	void __fastcall Favourites1Click(TObject *Sender);
	void __fastcall bLockAircraftClick(TObject *Sender);
	void __fastcall bRandomAircraftClick(TObject *Sender);
	void __fastcall cbAircraftTypePropsClick(TObject *Sender);
	void __fastcall cbContinentAFClick(TObject *Sender);
	void __fastcall cbUseFlightTimeClick(TObject *Sender);
	void __fastcall cbUseDirectionClick(TObject *Sender);
	void __fastcall eLegsExit(TObject *Sender);
	void __fastcall eElevationExit(TObject *Sender);
	void __fastcall eAircraftRangeModifierExit(TObject *Sender);
	void __fastcall Label31Click(TObject *Sender);
	void __fastcall bOpenStartMapClick(TObject *Sender);
	void __fastcall bOpenEndMapClick(TObject *Sender);
	void __fastcall miShowTooltipsClick(TObject *Sender);

private:	// User declarations

	bool AircraftDetailsHaveChanged = false;
	bool AirportDetailsHaveChanged = false;

	void BuildGUIFrom(AircraftLoadFilter&, AirportLoadFilter&, RouteFilter&);
	void InitialGUISetup();
	void ResetGUI();
    void SetLabelStatus(int, TLabel *label);

	void GenerateRoutes();
	bool UpdateRouteList();

	void BuildRouteDescription(const std::wstring, const std::wstring, double, double, int, int, int, bool);

	void UpdateAircraftList();

	AircraftLoadFilter BuildAircraftLoadFilterFromUI();
	AirportLoadFilter BuildAirportLoadFilterFromUI();
	RouteFilter BuildRouteLoadFilterFromUI();

	void UpdateCountryList();
    void UpdateRouteDescription(int);

	void SetAircraftSelections(bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool);

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;

#endif
