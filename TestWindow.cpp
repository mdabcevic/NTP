//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TestWindow.h"
#include "Data/AllData.h"
#include <IniFiles.hpp>  //Include the IniFiles header
#include "CarInfoInputForm.h"   //Include for showing Form3
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
    FillListView();
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
	//open separate window for entering car info
	Form3->AddCarMode();
	Form3->ShowModal();
	//get changes
    FillListView();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click(TObject *Sender)
{
	//delete car based on index
	DataModule1->companycars->Delete(ListView1->ItemIndex);
	DataModule1->XmlDoc->SaveToFile(DataModule1->XmlDoc->FileName);
    //avoid double click deleting next node in line
	ListView1->ItemIndex = -1;
	FillListView();

}
//---------------------------------------------------------------------------


void __fastcall TForm2::ListView1SelectItem(TObject *Sender, TListItem *Item, bool Selected)

{
	//get the selected node from xml on selecting the listview item
	if(ListView1->ItemIndex == -1){
		return;
	}
	DataModule1->currentCar = DataModule1->companycars->car[ListView1->ItemIndex];

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender)
{
	//open separate window for entering car info
	Form3->EditCarMode();
	Form3->ShowModal();
	FillListView();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FillListView(){
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
