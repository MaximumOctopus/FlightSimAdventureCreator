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

#ifndef AirportSearchDialogH
#define AirportSearchDialogH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TfrmAirportSearchDialog : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox4;
	TEdit *eSearch;
	TButton *bSearch;
	TComboBox *cbContinent;
	TLabel *Label1;
	TComboBox *cbCountry;
	TLabel *Label2;
	TStringGrid *StringGrid1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall bSearchClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmAirportSearchDialog(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAirportSearchDialog *frmAirportSearchDialog;
//---------------------------------------------------------------------------
#endif
