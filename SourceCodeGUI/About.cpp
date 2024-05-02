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

#include <vcl.h>
#pragma hdrstop

#include "About.h"
#include "Constants.h"
#include "WindowsUtility.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAbout *frmAbout;

__fastcall TfrmAbout::TfrmAbout(TComponent* Owner)
	: TForm(Owner)
{
	std::wstring v = SystemConstants::FSACVersion + L" / " + SystemConstants::FSACDate;

	lVersion->Caption = v.c_str();
}


void __fastcall TfrmAbout::Label2Click(TObject *Sender)
{
	TLabel *label = (TLabel*)Sender;

	std::wstring link = label->Caption.c_str();

	WindowsUtility::OpenWebsite(link);
}

