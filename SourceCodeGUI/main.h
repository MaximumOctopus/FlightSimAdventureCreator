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
#include <Vcl.Graphics.hpp>


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
	TLabel *labellongto;
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
	TMenuItem *N3;
	TMenuItem *miShowTooltips;
	TToolButton *tbCodeTest;
	TEdit *eMagicCode;
	TPopupMenu *puSelectICAO;
	TMenuItem *PopupMenu11;
	TMenuItem *N4;
	TMenuItem *Select1;
	TImage *Image1;
	TLabel *lDistanceStartEnd;
	TMenuItem *N5;
	TMenuItem *miUseHomeAirport;
	TMenuItem *SetasHomeairport1;
	TPopupMenu *puRegionSelect;
	TMenuItem *UnitedKingdom1;
	TMenuItem *England1;
	TMenuItem *England2;
	TMenuItem *NorthernIreland1;
	TMenuItem *NorthernIreland2;
	TMenuItem *Australia1;
	TMenuItem *NewSouthWales1;
	TMenuItem *NewSouthWales2;
	TMenuItem *SouthAustralia1;
	TMenuItem *SouthAustralia2;
	TMenuItem *Vistoria1;
	TMenuItem *Vistoria2;
	TMenuItem *UnitedStatesofAmerica1;
	TMenuItem *Alabama1;
	TMenuItem *Alabama2;
	TMenuItem *Arizona1;
	TMenuItem *Arizona2;
	TMenuItem *California1;
	TMenuItem *California2;
	TMenuItem *Connecticut1;
	TMenuItem *Connecticut2;
	TMenuItem *Florida1;
	TMenuItem *Florida2;
	TMenuItem *Hawaii1;
	TMenuItem *Hawaii2;
	TMenuItem *Illinois1;
	TMenuItem *Illinois2;
	TMenuItem *Iowa1;
	TMenuItem *Iowa2;
	TMenuItem *Kentucky1;
	TMenuItem *Kentucky2;
	TMenuItem *Maine1;
	TMenuItem *Maine2;
	TMenuItem *Massachusetts1;
	TMenuItem *Massachusetts2;
	TMenuItem *Minnesota1;
	TMenuItem *Minnesota2;
	TMenuItem *Missouri1;
	TMenuItem *Missouri2;
	TMenuItem *Nebraska1;
	TMenuItem *Nebraska2;
	TMenuItem *NewJersey1;
	TMenuItem *NewJersey2;
	TMenuItem *NewYork1;
	TMenuItem *NewYork2;
	TMenuItem *NorthDakota1;
	TMenuItem *NorthDakota2;
	TMenuItem *Oklahoma1;
	TMenuItem *Oklahoma2;
	TMenuItem *Pennsylvania1;
	TMenuItem *Pennsylvania2;
	TMenuItem *SouthCarolina1;
	TMenuItem *SouthCarolina2;
	TMenuItem *ennessee1;
	TMenuItem *ennessee2;
	TMenuItem *Utah1;
	TMenuItem *Utah2;
	TMenuItem *Virginia1;
	TMenuItem *Virginia2;
	TMenuItem *WestVirginia1;
	TMenuItem *WestVirginia2;
	TMenuItem *Wyoming1;
	TMenuItem *Wyoming2;
	TMenuItem *DisctrictofColumbia1;
	TMenuItem *Nevada1;
	TMenuItem *Canada1;
	TMenuItem *Alberta1;
	TMenuItem *Alberta2;
	TMenuItem *Manitoba1;
	TMenuItem *Manitoba2;
	TMenuItem *NewfoundlandandLabrador1;
	TMenuItem *NewfoundlandandLabrador2;
	TMenuItem *Ontario1;
	TMenuItem *Ontario2;
	TMenuItem *PrinceEdwardIsland1;
	TMenuItem *Quebec1;
	TMenuItem *Quebec2;
	TMenuItem *NorthwestTerritories1;
	TMenuItem *NorthwestTerritories2;
	TMenuItem *N6;
	TMenuItem *NewZealand1;
	TMenuItem *Auckland1;
	TMenuItem *Auckland2;
	TMenuItem *Canterbury1;
	TMenuItem *Canterbury2;
	TMenuItem *HawkesBay1;
	TMenuItem *HawkesBay2;
	TMenuItem *ManawatuWanganui1;
	TMenuItem *ManawatuWanganui2;
	TMenuItem *Northland1;
	TMenuItem *Northland2;
	TMenuItem *Southland1;
	TMenuItem *Southland2;
	TMenuItem *aranaki1;
	TMenuItem *aranaki2;
	TMenuItem *Wellington1;
	TMenuItem *Wellington2;
	TMenuItem *France1;
	TMenuItem *Ain1;
	TMenuItem *Ain2;
	TMenuItem *Bretagne1;
	TMenuItem *CentreValdeLoire1;
	TMenuItem *Corse1;
	TMenuItem *Corse2;
	TMenuItem *HautsdeFrance1;
	TMenuItem *HautsdeFrance2;
	TMenuItem *Normandie1;
	TMenuItem *Normandie2;
	TMenuItem *Occitanie1;
	TMenuItem *Occitanie2;
	TMenuItem *ProvenceAlpesCtedAzur1;
	TMenuItem *Spain1;
	TMenuItem *Andaluca1;
	TMenuItem *Andaluca2;
	TMenuItem *AsturiasPrincipadode1;
	TMenuItem *AsturiasPrincipadode2;
	TMenuItem *Cantabria1;
	TMenuItem *Cantabria2;
	TMenuItem *CastillaLaMancha1;
	TMenuItem *CatalunyacaCatalua1;
	TMenuItem *CatalunyacaCatalua2;
	TMenuItem *Extremadura1;
	TMenuItem *Extremadura2;
	TMenuItem *llesBalearscaIslasBaleares1;
	TMenuItem *llesBalearscaIslasBaleares2;
	TMenuItem *MadridComunidadde1;
	TMenuItem *MadridComunidadde2;
	TMenuItem *MurciaReginde1;
	TMenuItem *MurciaReginde2;
	TMenuItem *asVasco1;
	TMenuItem *ValencianaComunitat1;
	TMenuItem *N7;
	TMenuItem *N8;
	TPopupMenu *puDirection;
	TMenuItem *SetDirection1;
	TMenuItem *SetDirection2;
	TMenuItem *Frombearing1;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *NE1;
	TMenuItem *NE2;
	TMenuItem *E1;
	TMenuItem *E2;
	TMenuItem *SE1;
	TMenuItem *SE2;
	TMenuItem *S1;
	TMenuItem *S2;
	TMenuItem *SW1;
	TMenuItem *SW2;
	TMenuItem *W1;
	TMenuItem *W2;
	TMenuItem *NW1;
	TMenuItem *NW2;
	TMenuItem *Fromangle1;
	TMenuItem *N01;
	TMenuItem *N02;
	TMenuItem *N901;
	TMenuItem *N902;
	TMenuItem *N1801;
	TMenuItem *N1802;
	TMenuItem *N2701;
	TMenuItem *N2702;
	TLabel *Label32;
	TMenuItem *Gliders1;
	TMenuItem *Helicopters1;
	TMenuItem *AirlinersPropTurbo1;
	TMenuItem *Brazil1;
	TMenuItem *N11;
	TMenuItem *Alagoas1;
	TMenuItem *Alagoas2;
	TMenuItem *Amazonas1;
	TMenuItem *Amazonas2;
	TMenuItem *Cear1;
	TMenuItem *Cear2;
	TMenuItem *Gois1;
	TMenuItem *Maranho1;
	TMenuItem *MatoGrosso1;
	TMenuItem *MatoGrossodoSul1;
	TMenuItem *MinasGerais1;
	TMenuItem *Par1;
	TMenuItem *Paraba1;
	TMenuItem *Paran1;
	TMenuItem *Pernambuco1;
	TMenuItem *Piau1;
	TMenuItem *RiodeJaneiro1;
	TMenuItem *RioGrandedoNorte1;
	TMenuItem *RioGrandedoSul1;
	TMenuItem *Rondnia1;
	TMenuItem *Roraima1;
	TMenuItem *SantaCatarina1;
	TMenuItem *SoPaulo1;
	TMenuItem *Sergipe1;
	TMenuItem *ocantins1;
	TBevel *Bevel14;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall bUpdateAircraftClick(TObject *Sender);
	void __fastcall bUpdateAirportsClick(TObject *Sender);
	void __fastcall bGenerateClick(TObject *Sender);
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
	void __fastcall cbTimeOfDayClick(TObject *Sender);
	void __fastcall tbCodeTestClick(TObject *Sender);
	void __fastcall eDirectionExit(TObject *Sender);
	void __fastcall Select1Click(TObject *Sender);
	void __fastcall eEndAirportICAOExit(TObject *Sender);
	void __fastcall miUseHomeAirportClick(TObject *Sender);
	void __fastcall SetasHomeairport1Click(TObject *Sender);
	void __fastcall puSelectICAOPopup(TObject *Sender);
	void __fastcall England1Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);

private:	// User declarations

	bool AircraftDetailsHaveChanged = false;
	bool AirportDetailsHaveChanged = false;

	void BuildGUIFrom(AircraftLoadFilter&, AirportLoadFilter&, RouteFilter&);
	void InitialGUISetup();
	void ResetGUI();
    void SetLabelStatus(int, TLabel *label);

	void GenerateRoutes();
	bool UpdateRouteList();

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
