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
	TGroupBox *gbAircraft;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox3;
	TToolBar *ToolBar1;
	TToolButton *tbSave;
	TToolButton *tbOpen;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *File2;
	TMenuItem *Exit1;
	TMenuItem *Exit2;
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
	TButton *bUpdateAirports;
	TCheckBox *cbAircraftTypeSeaplanes;
	TStatusBar *sbMain;
	TEdit *eMinSpeed;
	TEdit *eMaxSpeed;
	TLabel *lMinSpeed;
	TLabel *Label1;
	TCheckBox *cbContinentAF;
	TCheckBox *cbContinentAN;
	TCheckBox *cbContinentAS;
	TCheckBox *cbContinentEU;
	TCheckBox *cbContinentNA;
	TCheckBox *cbContinentOC;
	TCheckBox *cbContinentSA;
	TLabel *Label2;
	TLabel *Label3;
	TCheckBox *cbCountryFilter;
	TLabel *lFoundAirports;
	TLabel *Label5;
	TEdit *eLatFrom;
	TCheckBox *cbLatLongFilter;
	TEdit *eLatTo;
	TLabel *Label6;
	TComboBox *cbCountryList;
	TLabel *Label7;
	TEdit *eLongFrom;
	TLabel *Label8;
	TEdit *eLongTo;
	TCheckBox *cbLargeAirports;
	TCheckBox *cbMediumAirports;
	TCheckBox *cbSmallAirports;
	TCheckBox *cbHeliports;
	TCheckBox *cbSeaplaneBases;
	TBevel *Bevel1;
	TCheckBox *cbContinentFilter;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TCheckBox *cbRegionFilter;
	TEdit *eRegionICO;
	TBevel *Bevel4;
	TBevel *Bevel5;
	TImageList *ImageList1;
	TToolButton *ToolButton3;
	TBevel *Bevel6;
	TCheckBox *cbTimeOfDay;
	TRadioButton *rbDay;
	TRadioButton *rbNight;
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
	TBevel *Bevel8;
	TEdit *eAircraftRangeModifier;
	TCheckBox *cbAllowExcessRange;
	TToolButton *ToolButton1;
	TEdit *eCount;
	TEdit *eFlightTime;
	TLabel *Label16;
	TCheckBox *cbUseFlightTime;
	TSaveDialog *sdMain;
	TLabel *lFoundAircraft;
	TOpenDialog *odMain;
	TBevel *Bevel9;
	TBevel *Bevel10;
	TLabel *Label17;
	TBevel *Bevel11;
	TStringGrid *sgRoutes;
	TToolButton *tbExport;
	TEdit *eElevation;
	TLabel *Label18;
	TToolButton *tbExportItinerary;
	TMenuItem *ools1;
	TMenuItem *Createcustomaircrafttxt1;
	TMenuItem *Help1;
	TMenuItem *About1;
	TLabel *Label19;
	TMemo *mMain;
	TLabel *Label20;
	TToolButton *ToolButton2;
	TLabel *lAircraftStats;
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

private:	// User declarations

	void BuildGUIFrom(AircraftLoadFilter&, AirportLoadFilter&, RouteFilter&);
	void UpdateGUI();
	void ResetGUI();

	void GenerateRoutes();
	void UpdateRouteList();

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
