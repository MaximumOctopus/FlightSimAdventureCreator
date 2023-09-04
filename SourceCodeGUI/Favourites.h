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

#ifndef FavouritesH
#define FavouritesH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <vector>

class TfrmFavourites : public TForm
{
__published:	// IDE-managed Components
	TImageList *ImageList1;
	TGroupBox *GroupBox1;
	TListBox *lbFavourites;
	TButton *bAdd;
	TButton *bDelete;
	TEdit *eICAO;
	TButton *bCancel;
	TButton *bOK;
	TLabel *Label1;
	TLabel *lName;
	TLabel *Label3;
	TLabel *lContinent;
	TLabel *Label5;
	TLabel *lCountry;
	TLabel *Label7;
	TLabel *lRegion;
	TButton *Button1;
	void __fastcall bAddClick(TObject *Sender);
	void __fastcall bDeleteClick(TObject *Sender);
	void __fastcall bOKClick(TObject *Sender);
	void __fastcall lbFavouritesClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations

	bool ModifiedFavourites = false;
	std::wstring _latitude = L"";
	std::wstring _longitude = L"";

	void PopulateFromSelected();

public:		// User declarations
	__fastcall TfrmFavourites(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmFavourites *frmFavourites;
//---------------------------------------------------------------------------
#endif
