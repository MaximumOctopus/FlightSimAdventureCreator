//---------------------------------------------------------------------------

#ifndef DistanceH
#define DistanceH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmDistanceCalc : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox4;
	TEdit *eFromICAO;
	TLabel *lTo;
	TEdit *eToICAO;
	TLabel *Label3;
	TButton *bCalculate;
	TLabel *Label1;
	TLabel *lError;
	TGroupBox *GroupBox1;
	TLabel *Label2;
	TLabel *lDistanceNM;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *lDistanceKM;
	TLabel *lDistanceMiles;
	TButton *Button1;
	void __fastcall bCalculateClick(TObject *Sender);
	void __fastcall eFromICAOKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmDistanceCalc(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDistanceCalc *frmDistanceCalc;
//---------------------------------------------------------------------------
#endif
