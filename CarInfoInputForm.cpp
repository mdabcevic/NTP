//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CarInfoInputForm.h"
#include "Data/AllData.h"
#include "TestWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TForm3::AddCarMode()
{
	Form3->SaveCarChanges_Button->Caption = "Add car";
	Form3->LicensePlate_Box->Text = "";
	Form3->InternalName_Box->Text = "";
	Form3->Assigned_Box->Text = "";
	Form3->User_Box->Text = "";
	Form3->Location_Box->Text = "";

}
//---------------------------------------------------------------------------
void TForm3::EditCarMode()
{
	Form3->SaveCarChanges_Button->Caption = "Edit car";
	Form3->LicensePlate_Box->Text = DataModule1->currentCar->licenseplate;
	Form3->InternalName_Box->Text = DataModule1->currentCar->internalmark;
	Form3->Assigned_Box->Text = DataModule1->currentCar->assigned;
	Form3->User_Box->Text = DataModule1->currentCar->currentuser;
	Form3->Location_Box->Text = DataModule1->currentCar->location;

}
//---------------------------------------------------------------------------
void __fastcall TForm3::SaveCarChanges_ButtonClick(TObject *Sender)
{
	if(Form3->SaveCarChanges_Button->Caption == "Add car"){
		DataModule1->currentCar = DataModule1->companycars->Add();

	}
	DataModule1->currentCar->licenseplate = Form3->LicensePlate_Box->Text;
	DataModule1->currentCar->internalmark = Form3->InternalName_Box->Text;
	DataModule1->currentCar->assigned = Form3->Assigned_Box->Text;
	DataModule1->currentCar->currentuser = Form3->User_Box->Text;
	DataModule1->currentCar->location = Form3->Location_Box->Text;
	//DataModule1->XmlDoc->SaveToFile(DataModule1->XmlDoc->FileName);

	DataModule1->AddToXmlRequest();
	DataModule1->XmlDoc->Active = false;
	DataModule1->RequestXMLFile();
    DataModule1->XmlDoc->Active = true;
	Form3->Close();
}
//---------------------------------------------------------------------------
