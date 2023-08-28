//
// FlightSimAdventureCreator 1.0 (GUI Version)
//
// (c) Paul Alan Freshney 2022-2023
//
// paul@freshney.org
//
// https://github.com/MaximumOctopus/FlightSimAdventureCreator
//
//

#ifndef RouteBrowserH
#define RouteBrowserH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>

#include "FlightHandler.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Dialogs.hpp>

class TfrmRouteBrowser : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *sgRoutes;
	TGroupBox *GroupBox1;
	TEdit *eICAO;
	TRadioButton *rbFromICAO;
	TRadioButton *rbToICAO;
	TTrackBar *tbMin;
	TTrackBar *tbMax;
	TEdit *eMin;
	TEdit *eMax;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Min;
	TLabel *Label5;
	TButton *bSearchFromICAO;
	TBevel *Bevel2;
	TComboBox *cbCountryList;
	TBevel *Bevel1;
	TLabel *lDestinationCountry;
	TBevel *Bevel3;
	TButton *Button1;
	TBevel *Bevel4;
	TLabel *Label6;
	TComboBox *cbAirlineList;
	TCheckBox *cbAirlineFilter;
	TBevel *Bevel5;
	TLabel *lInvalid;
	TCheckBox *cbCountryFilter;
	TLabel *lStatus;
	TComboBox *cbRouteType;
	TPopupMenu *puSelectICAO;
	TMenuItem *PopupMenu11;
	TMenuItem *N4;
	TMenuItem *Select1;
	TMenuItem *N5;
	TMenuItem *miUseHomeAirport;
	TMenuItem *SetasHomeairport1;
	TMenuItem *N7;
	TMenuItem *N14;
	TMenuItem *Africa1;
	TMenuItem *PrincessJulianaInternationalAirport2;
	TMenuItem *CapeTownInternationalAirport1;
	TMenuItem *Uganda1;
	TMenuItem *EntebbeInternationalAirport1;
	TMenuItem *MariscalSucreInternationalAirport2;
	TMenuItem *CairoInternationalAirport1;
	TMenuItem *Asia1;
	TMenuItem *Bhutan1;
	TMenuItem *ParoInternationalAirport1;
	TMenuItem *GibraltarInternationalAirport2;
	TMenuItem *KaiTakInternationalAirport1;
	TMenuItem *Indonesia1;
	TMenuItem *AdisumarmoInternationalAirport1;
	TMenuItem *BugalagaAirstrip1;
	TMenuItem *Japan1;
	TMenuItem *HachijojimaAirport1;
	TMenuItem *HachijojimaAirport2;
	TMenuItem *KeramaAirport1;
	TMenuItem *KeramaAirport2;
	TMenuItem *NagasakiAirport1;
	TMenuItem *NagasakiAirport2;
	TMenuItem *SuwanosejimaAirport1;
	TMenuItem *RotterdamTheHagueAirport2;
	TMenuItem *enzingHillaryAirport1;
	TMenuItem *Australasia1;
	TMenuItem *Australia2;
	TMenuItem *CambridgeBayAirport1;
	TMenuItem *CambridgeBayAirport2;
	TMenuItem *ParaburdooAirport1;
	TMenuItem *ShellharbourAirport1;
	TMenuItem *SydneyKingsfordSmithAirport1;
	TMenuItem *enzingHillaryAirport2;
	TMenuItem *GorgeRiverAirstrip1;
	TMenuItem *GisborneAirport1;
	TMenuItem *LakeTekapoAirport1;
	TMenuItem *MartinsBayAerodrome1;
	TMenuItem *MilfordSoundAirport1;
	TMenuItem *RotoruaAirport1;
	TMenuItem *QueenstownAirport1;
	TMenuItem *QuintinLodgeAirstrip1;
	TMenuItem *WestportAirport1;
	TMenuItem *WhangareiAirport1;
	TMenuItem *Europe1;
	TMenuItem *UAE2;
	TMenuItem *InnsbruckAirport1;
	TMenuItem *InnsbruckAirport2;
	TMenuItem *SydneyKingsfordSmithAirport2;
	TMenuItem *GustafIIIAirport1;
	TMenuItem *SirenaAerodrome2;
	TMenuItem *BornholmAirport1;
	TMenuItem *VaasaAirport2;
	TMenuItem *CharlesdeGaulleAirport1;
	TMenuItem *CharlesdeGaulleAirport2;
	TMenuItem *MegveAltiport1;
	TMenuItem *MegveAltiport2;
	TMenuItem *CairoInternationalAirport2;
	TMenuItem *VaasaAirport1;
	TMenuItem *Germany1;
	TMenuItem *FrankfurtAirport1;
	TMenuItem *FrankfurtAirport2;
	TMenuItem *LeipzigHalleAirport1;
	TMenuItem *LeipzigHalleAirport2;
	TMenuItem *MemmingenAirport1;
	TMenuItem *MemmingenAirport2;
	TMenuItem *Gibraltar1;
	TMenuItem *GibraltarInternationalAirport1;
	TMenuItem *GreatBritain1;
	TMenuItem *BarraAirport1;
	TMenuItem *BarraAirport2;
	TMenuItem *LandsEndAirport1;
	TMenuItem *LandsEndAirport2;
	TMenuItem *ManchesterCityAirportHeliport1;
	TMenuItem *ManchesterCityAirportHeliport2;
	TMenuItem *DonegalAirport2;
	TMenuItem *safjrurAirport1;
	TMenuItem *Ireland1;
	TMenuItem *DonegalAirport1;
	TMenuItem *Italy1;
	TMenuItem *BolzanoAirport1;
	TMenuItem *BolzanoAirport2;
	TMenuItem *IloiloInternationalAirport1;
	TMenuItem *IloiloInternationalAirport2;
	TMenuItem *Netherlads1;
	TMenuItem *AmsterdamAirportSchiphol1;
	TMenuItem *AmsterdamAirportSchiphol2;
	TMenuItem *RotterdamTheHagueAirport1;
	TMenuItem *BugalagaAirstrip2;
	TMenuItem *CristianoRonaldoMadeiraInternationalAirport1;
	TMenuItem *CristianoRonaldoMadeiraInternationalAirport2;
	TMenuItem *PicoAirport1;
	TMenuItem *CapeTownInternationalAirport2;
	TMenuItem *ACoruaAirport1;
	TMenuItem *ACoruaAirport2;
	TMenuItem *AndorraLaSeudUrgellAirport1;
	TMenuItem *AndorraLaSeudUrgellAirport2;
	TMenuItem *SvalbardAirport1;
	TMenuItem *SvalbardAirport2;
	TMenuItem *StockholmArlandaAirport1;
	TMenuItem *StockholmArlandaAirport2;
	TMenuItem *LuganoAirport1;
	TMenuItem *LuganoAirport2;
	TMenuItem *StGallenAltenrheinAirport1;
	TMenuItem *ZurichAirport1;
	TMenuItem *MiddleEast1;
	TMenuItem *UAE1;
	TMenuItem *DubaiInternationalAirport1;
	TMenuItem *Pacific1;
	TMenuItem *BoraBoraAirport1;
	TMenuItem *CookIslandsAitutakiAirport1;
	TMenuItem *EasterIsland1;
	TMenuItem *Hawaii3;
	TMenuItem *IslandofMoorea1;
	TMenuItem *PohnpeiIsland1;
	TMenuItem *SolomanIslandsNusatupeAirport1;
	TMenuItem *NorthAmerica1;
	TMenuItem *Canada2;
	TMenuItem *BellaCoolaAirport1;
	TMenuItem *BillyBishopTorontoCityAirport1;
	TMenuItem *BillyBishopTorontoCityAirport2;
	TMenuItem *DawsonCityAirport1;
	TMenuItem *DawsonCityAirport2;
	TMenuItem *IqaluitInternationalAirport1;
	TMenuItem *StewartAerodrome1;
	TMenuItem *USA1;
	TMenuItem *AspenPitkinCountyAirport1;
	TMenuItem *AspenPitkinCountyAirport2;
	TMenuItem *CatalinaAirport1;
	TMenuItem *CatalinaAirport2;
	TMenuItem *DenverInternationalAirport1;
	TMenuItem *FirstFlightAirportKittyHawk1;
	TMenuItem *FirstFlightAirportKittyHawk2;
	TMenuItem *HartsfieldJacksonAtlantaInternationalAirport1;
	TMenuItem *HartsfieldJacksonAtlantaInternationalAirport2;
	TMenuItem *LakeTahoeAirport1;
	TMenuItem *LakeTahoeAirport2;
	TMenuItem *MarineCorpsAirStationMiramar1;
	TMenuItem *MarineCorpsAirStationMiramar2;
	TMenuItem *OHareInternationalAirport1;
	TMenuItem *OHareInternationalAirport2;
	TMenuItem *PatrickSpaceForceBase1;
	TMenuItem *PatrickSpaceForceBase2;
	TMenuItem *SeattleTacomaInternationalAirport1;
	TMenuItem *SeattleTacomaInternationalAirport2;
	TMenuItem *StewartInternationalAirport1;
	TMenuItem *StewartInternationalAirport2;
	TMenuItem *ValdezAirport1;
	TMenuItem *SouthAmerica1;
	TMenuItem *GustafIIIAirport2;
	TMenuItem *RiodeJaneiroGaleoInternationalAirport1;
	TMenuItem *CostaRica1;
	TMenuItem *SirenaAerodrome1;
	TMenuItem *BornholmAirport2;
	TMenuItem *MariscalSucreInternationalAirport1;
	TMenuItem *Honduras1;
	TMenuItem *oncontinInternationalAirport1;
	TMenuItem *QueenstownAirport2;
	TMenuItem *hagualAirport1;
	TMenuItem *PicoAirport2;
	TMenuItem *PrincessJulianaInternationalAirport1;
	TButton *bExportSelected;
	TButton *bExportSelectedText;
	TImageList *il16x16;
	TSaveDialog *sdMain;
	void __fastcall bSearchFromICAOClick(TObject *Sender);
	void __fastcall tbMinChange(TObject *Sender);
	void __fastcall tbMaxChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall eICAOKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall rbFromICAOClick(TObject *Sender);
	void __fastcall rbToICAOClick(TObject *Sender);
	void __fastcall cbCountryFilterClick(TObject *Sender);
	void __fastcall cbAirlineFilterClick(TObject *Sender);
	void __fastcall eICAOExit(TObject *Sender);
	void __fastcall cbRouteTypeChange(TObject *Sender);
	void __fastcall Select1Click(TObject *Sender);
	void __fastcall miUseHomeAirportClick(TObject *Sender);
	void __fastcall SetasHomeairport1Click(TObject *Sender);
	void __fastcall BarraAirport1Click(TObject *Sender);
	void __fastcall bExportSelectedClick(TObject *Sender);
	void __fastcall bExportSelectedTextClick(TObject *Sender);
private:	// User declarations
    FlightHandler* fh;

	double MinDistance = 0;
	double MaxDistance = 1000;

	void UpdateLists();
	void ClearRouteList();

public:		// User declarations
	__fastcall TfrmRouteBrowser(TComponent* Owner);
};

extern PACKAGE TfrmRouteBrowser *frmRouteBrowser;

#endif
