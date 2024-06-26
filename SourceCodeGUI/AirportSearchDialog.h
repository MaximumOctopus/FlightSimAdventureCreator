//
// FlightSimAdventureCreator 1.0 (GUI Version)
//
// (c) Paul Alan Freshney 2022-2024
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
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Dialogs.hpp>
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
	TStringGrid *sgResults;
	TCheckBox *cbLargeAirports;
	TCheckBox *cbHeliports;
	TCheckBox *cbSeaplaneBases;
	TCheckBox *cbSmallAirports;
	TCheckBox *cbMediumAirports;
	TStatusBar *sbSearch;
	TBevel *Bevel1;
	TEdit *eRange;
	TLabel *Label4;
	TEdit *eICAO;
	TLabel *Label5;
	TCheckBox *cbWithinRange;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TLabel *Label3;
	TBevel *Bevel4;
	TButton *bSelect;
	TImageList *ImageList1;
	TButton *bSave;
	TSaveDialog *sdSearch;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall bSearchClick(TObject *Sender);
	void __fastcall eSearchKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall sgResultsDblClick(TObject *Sender);
	void __fastcall bSelectClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall bSaveClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    std::wstring SelectedICAO = L"";

	__fastcall TfrmAirportSearchDialog(TComponent* Owner);

    void SetSelectionMode(bool);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAirportSearchDialog *frmAirportSearchDialog;
//---------------------------------------------------------------------------
#endif
