//---------------------------------------------------------------------------

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
	DataModule1->themeHelper.LoadSection("LIGHT THEME");
	DataModule1->fontHelper.LoadSection("TEST FONT");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
	DataModule1->wrSettingsHelper.DeleteSettings();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
	DataModule1->wrSettingsHelper.isRememberMe = true;
	DataModule1->wrSettingsHelper.username = "test1";
	DataModule1->wrSettingsHelper.password = "test2";
	DataModule1->wrSettingsHelper.SaveSettings();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SaveIni_TestClick(TObject *Sender)
{
	DataModule1->themeHelper.SaveCurrent();
	DataModule1->fontHelper.SaveCurrent();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LoadWR_TestClick(TObject *Sender)
{
	DataModule1->wrSettingsHelper.LoadSettings();
	ShowMessage(DataModule1->wrSettingsHelper.username);
    ShowMessage(DataModule1->wrSettingsHelper.password);
}
//---------------------------------------------------------------------------

