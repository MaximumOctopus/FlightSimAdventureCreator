//---------------------------------------------------------------------------

#ifndef StatsAirportsH
#define StatsAirportsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Samples.Gauges.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmStatsAirports : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *lLowest;
	TLabel *lHighest;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TGauge *gc1;
	TGauge *gc2;
	TGauge *gc3;
	TGauge *gc4;
	TGauge *gc5;
	TGauge *gc6;
	TGauge *gc7;
	TButton *Button1;
	TLabel *lCount;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TGauge *gt1;
	TGauge *gt2;
	TGauge *gt3;
	TGauge *gt4;
	TGauge *gt5;
	TLabel *lc1;
	TLabel *lc2;
	TLabel *lc3;
	TLabel *lc4;
	TLabel *lc5;
	TLabel *lc6;
	TLabel *lc7;
	TBevel *Bevel1;
	TLabel *lt1;
	TLabel *lt2;
	TLabel *lt3;
	TLabel *lt4;
	TLabel *lt5;
	TBevel *Bevel2;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmStatsAirports(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmStatsAirports *frmStatsAirports;
//---------------------------------------------------------------------------
#endif
