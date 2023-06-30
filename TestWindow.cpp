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
//make ListView columns have equally distributed width & fill entire space
if(ListView1->Columns->Count > 0)
  {
    int ColWidth = ListView1->ClientWidth / ListView1->Columns->Count;
    for(int i = 0; i < ListView1->Columns->Count; i++)
      ListView1->Columns->Items[i]->Width = ColWidth;
  }
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

void __fastcall TForm2::Button3Click(TObject *Sender)
{
	DataModule1->companycars = Getcompanycars(DataModule1->XmlDoc);
	ListView1->Items->Clear();
	for(int i = 0; i < DataModule1->companycars->Count; i++){
		ListView1->Items->Add();
		ListView1->Items->Item[i]->Caption =
				DataModule1->companycars->car[i]->licenseplate;
		ListView1->Items->Item[i]->
				Caption = DataModule1->companycars->car[i]->licenseplate;
		ListView1->Items->Item[i]->SubItems->
				Add(DataModule1->companycars->car[i]->internalmark);
        ListView1->Items->Item[i]->SubItems->
				Add(DataModule1->companycars->car[i]->assigned);
        ListView1->Items->Item[i]->SubItems->
				Add(DataModule1->companycars->car[i]->currentuser);
        ListView1->Items->Item[i]->SubItems->
				Add(DataModule1->companycars->car[i]->location);

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
	DataModule1->themeHelper.ResetToDefault();
    DataModule1->fontHelper.ResetToDefault();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button5Click(TObject *Sender)
{
	DataModule1->currentCar = DataModule1->companycars->Add();
	DataModule1->currentCar->licenseplate = "added";
	DataModule1->currentCar->internalmark = "Peugeot-508";
	DataModule1->currentCar->assigned = "K. D.";
	DataModule1->currentCar->currentuser = "K. S.";
	DataModule1->currentCar->location = "Zagreb";
    DataModule1->XmlDoc->SaveToFile(DataModule1->XmlDoc->FileName);
}
//---------------------------------------------------------------------------

