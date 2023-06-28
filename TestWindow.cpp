﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TestWindow.h"
#include "Data/AllData.h"
#include <IniFiles.hpp> // Include the IniFiles header
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::LoadIni_testClick(TObject *Sender)
{
	DataModule1->themeHelper.LoadSection("DARK THEME");
	//ShowMessage(DataModule1->themeHelper.textColour);
	ShowMessage(DataModule1->themeHelper.TColorToRGBString(DataModule1->themeHelper.backgroundColour));
    Form2->Color =        DataModule1->themeHelper.backgroundColour;
	//load font
	DataModule1->fontHelper.LoadSection("CURRENT FONT");
	ShowMessage(DataModule1->fontHelper.fontName);
	ShowMessage(DataModule1->fontHelper.textHeight);
}
//---------------------------------------------------------------------------
