//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CompanyCarsForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm12 *Form12;
//---------------------------------------------------------------------------
__fastcall TForm12::TForm12(TComponent* Owner)
	: TForm(Owner)
{
    //make ListView columns have equally distributed width & fill entire space
	if(ListView1->Columns->Count > 0)
	{
		int ColWidth = ListView1->ClientWidth / ListView1->Columns->Count;
		for(int i = 0; i < ListView1->Columns->Count; i++)
		ListView1->Columns->Items[i]->Width = ColWidth;
	}
    DataModule1->RequestXMLFile();
	FillListView();



}
//---------------------------------------------------------------------------
 //update company cars and fill the list view with most recent info
void __fastcall TForm12::FillListView(){
		DataModule1->companycars = Getcompanycars(DataModule1->XmlDoc);
	ListView1->Items->Clear();
	for(int i = 0; i < DataModule1->companycars->Count; i++){
		TListItem *Item = ListView1->Items->Add();
		Item->Caption = DataModule1->companycars->car[i]->licenseplate;
		Item->SubItems->Add(DataModule1->companycars->car[i]->internalmark);
		Item->SubItems->Add(DataModule1->companycars->car[i]->assigned);
		Item->SubItems->Add(DataModule1->companycars->car[i]->currentuser);
		Item->SubItems->Add(DataModule1->companycars->car[i]->location);
	}

	translation["LoadAll"] = {
		{
			{"EN", "Load all cars"},
			{"HR", "Učitajte sve podatke "}

		}
	};

	translation["AddNewCar"] = {
		{
			{"EN", "Add new car"},
			{"HR", "Unesite novo vozilo "}

		}
	};

	translation["EditCar"] = {
		{
			{"EN", "Edit selected car"},
			{"HR", "Ažurirajte odabrano vozilo "}

		}
	};

	translation["RemoveCar"] = {
		{
			{"EN", "Remove selected car"},
			{"HR", "Izbrišite odabrano vozilo "}

		}
	};

	translation["Title"] = {
		{
			{"EN", "Information about company cars"},
			{"HR", "Podaci o službenim vozilima "}

		}
	};




}
void __fastcall TForm12::AddNewCarClick(TObject *Sender)
{
	//open separate window for entering car info
	Form3->AddCarMode();
	Form3->ShowModal();
	//get changes
	FillListView();
}
//---------------------------------------------------------------------------
void __fastcall TForm12::EditCarClick(TObject *Sender)
{
	//open separate window for entering car info with selected info
	Form3->EditCarMode(ListView1->ItemIndex);
	Form3->ShowModal();
	FillListView();
}
//---------------------------------------------------------------------------
void __fastcall TForm12::RemoveCarClick(TObject *Sender)
{
	DataModule1->XmlDoc->Active = false;
	DataModule1->DeleteFromXml(ListView1->ItemIndex);
	DataModule1->XmlDoc->Active = true;
	DataModule1->XmlDoc->Active = false;
	DataModule1->RequestXMLFile();
	DataModule1->XmlDoc->Active = true;
	//delete car based on index
	//DataModule1->companycars->Delete(ListView1->ItemIndex);
	//DataModule1->XmlDoc->SaveToFile(DataModule1->XmlDoc->FileName);
	//avoid double click deleting next node in line
	ListView1->ItemIndex = -1;
	FillListView();
}
//---------------------------------------------------------------------------
void __fastcall TForm12::ListView1SelectItem(TObject *Sender, TListItem *Item, bool Selected)

{
	//get the selected node from xml on selecting the listview item
	if(ListView1->ItemIndex == -1){
		return;
	}
	DataModule1->currentCar = DataModule1->companycars->car[ListView1->ItemIndex];
}
//---------------------------------------------------------------------------
void __fastcall TForm12::LoadAllClick(TObject *Sender)
{
    DataModule1->RequestXMLFile();
    FillListView();
}
//---------------------------------------------------------------------------
