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

#ifndef StatsRoutesH
#define StatsRoutesH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "pies.h"
#include <Vcl.Samples.Gauges.hpp>
#include <Vcl.ExtCtrls.hpp>

class TfrmStatsRoutes : public TForm
{
__published:	// IDE-managed Components
	TLabel *lCount;
	TLabel *Label2;
	TLabel *lLongest;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TButton *Button1;
	TGauge *g1;
	TGauge *g2;
	TGauge *g3;
	TGauge *g4;
	TGauge *g5;
	TGauge *g6;
	TGauge *g7;
	TLabel *Label10;
	TLabel *lTotal;
	TLabel *Label12;
	TLabel *lAverage;
	TLabel *Label11;
	TLabel *lShortest;
	TBevel *Bevel2;
	TLabel *lc1;
	TLabel *lc2;
	TLabel *lc3;
	TLabel *lc4;
	TLabel *lc5;
	TLabel *lc6;
	TLabel *lc7;
	TLabel *Label1;
	TLabel *lFrom;
	TLabel *Label14;
	TLabel *lTo;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmStatsRoutes(TComponent* Owner);
};

extern PACKAGE TfrmStatsRoutes *frmStatsRoutes;

#endif
