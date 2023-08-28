//---------------------------------------------------------------------------

#ifndef StatsAircraftH
#define StatsAircraftH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Samples.Gauges.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmStatsAircraft : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TGauge *g1;
	TGauge *g2;
	TGauge *g3;
	TGauge *g4;
	TGauge *g5;
	TGauge *g6;
	TGauge *g7;
	TLabel *Label1;
	TGauge *g8;
	TButton *Button1;
	TLabel *Label2;
	TLabel *Label10;
	TLabel *lLowestCruise;
	TLabel *lHighestCruise;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *lLowestRange;
	TLabel *lHighestRange;
	TBevel *Bevel2;
	TLabel *lt1;
	TLabel *lt2;
	TLabel *lt4;
	TLabel *lt3;
	TLabel *lt6;
	TLabel *lt5;
	TLabel *lt8;
	TLabel *lt7;
	TLabel *lCount;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmStatsAircraft(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmStatsAircraft *frmStatsAircraft;
//---------------------------------------------------------------------------
#endif
