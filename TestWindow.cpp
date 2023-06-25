//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TestWindow.h"
#include "Data/AllData.h"
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
	DataModule1->themeHelper.LoadSection("CURRENT THEME");
	ShowMessage(DataModule1->themeHelper.textColour);
	ShowMessage(DataModule1->themeHelper.backgroundColour);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SaveIni_TestClick(TObject *Sender)
{
	DataModule1->fontHelper.LoadSection("CURRENT FONT");
	ShowMessage(DataModule1->fontHelper.fontName);
	ShowMessage(DataModule1->fontHelper.textHeight);
}
//---------------------------------------------------------------------------

