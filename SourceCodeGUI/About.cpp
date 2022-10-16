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

	std::wstring link = L"";

	switch (label->Tag)
	{
		case 0:
			link = L"";
			break;
		case 1:
			link = L"http://ourairports.com";
			break;
		case 2:
			link = L"https://icon-icons.com";
			break;
		case 3:
			link = L"https://learn.microsoft.com/en-us/windows/apps/design/style/segoe-ui-symbol-font";
			break;
		case 4:
			link = L"https://github.com/MaximumOctopus/FlightSimAdventureCreator";
			break;
		case 5:
			link = L"";
			break;
    }

	WindowsUtility::OpenWebsite(link);
}

