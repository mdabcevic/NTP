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
	translation["Assigned_Label"] = {
		{
			{"EN", "Officially assigned to "},
			{"HR", "Zaduenik:"}

		}
	};

	translation["InternalName_Label"] = {
		{
			{"EN", "Internal Name "},
			{"HR", "Ime vozila:"}

		}
	};

	translation["LicensePlate_Label"] = {
		{
			{"EN", "License plate"},
			{"HR", "Registracijske tablice"}

		}
	};

	translation["Location_Label"] = {
		{
			{"EN", "Location"},
			{"HR", "Mjesto"}

		}
	};

		translation["User_Label"] = {
		{
			{"EN", "Currently used by"},
			{"HR", "Trenutno korisnik"}

		}
	};


}
//---------------------------------------------------------------------------
void TForm3::AddCarMode()
{
	Form3->SaveCarChanges_Button->Caption = "Add";
	Form3->LicensePlate_Box->Text = "";
	Form3->InternalName_Box->Text = "";
	Form3->Assigned_Box->Text = "";
	Form3->User_Box->Text = "";
	Form3->Location_Box->Text = "";

}
//---------------------------------------------------------------------------
void TForm3::EditCarMode(int index)
{
    carIndex = index;
	Form3->SaveCarChanges_Button->Caption = "Edit";
	Form3->LicensePlate_Box->Text = DataModule1->currentCar->licenseplate;
	Form3->InternalName_Box->Text = DataModule1->currentCar->internalmark;
	Form3->Assigned_Box->Text = DataModule1->currentCar->assigned;
	Form3->User_Box->Text = DataModule1->currentCar->currentuser;
	Form3->Location_Box->Text = DataModule1->currentCar->location;

}
//---------------------------------------------------------------------------
void __fastcall TForm3::SaveCarChanges_ButtonClick(TObject *Sender)
{
	//it's already in the Edit mode, so change only if Add is specified
	if(Form3->SaveCarChanges_Button->Caption == "Add"){
		DataModule1->XmlDoc->Active = false;
		DataModule1->XmlDoc->Active = true;
        DataModule1->companycars = Getcompanycars(DataModule1->XmlDoc);
		DataModule1->currentCar = DataModule1->companycars->Add();
	}
	//this part is the same for both actions
	DataModule1->currentCar->licenseplate = Form3->LicensePlate_Box->Text;
	DataModule1->currentCar->internalmark = Form3->InternalName_Box->Text;
	DataModule1->currentCar->assigned = Form3->Assigned_Box->Text;
	DataModule1->currentCar->currentuser = Form3->User_Box->Text;
	DataModule1->currentCar->location = Form3->Location_Box->Text;


	//SOAP validation for license plates
	if(CheckPlates()){
		if(Form3->SaveCarChanges_Button->Caption == "Add"){
            DataModule1->AddToXmlRequest();
		}
		else if(Form3->SaveCarChanges_Button->Caption == "Edit"){
			DataModule1->EditXMLRequest(carIndex);
            carIndex = -1;
		}
		//for automatic refresh
        DataModule1->XmlDoc->Active = false;
		DataModule1->RequestXMLFile();
		DataModule1->XmlDoc->Active = true;
		Form3->Close();
	}
	else{
        ShowMessage("Invalid license plate!");
    }
}
//---------------------------------------------------------------------------

bool TForm3::CheckPlates(){
	if(DataModule1->carValidation->validateLicensePlate(DataModule1->currentCar->licenseplate)){
		//ShowMessage("good license plate format");
		if(DataModule1->carValidation->isValidCityCode(DataModule1->currentCar->licenseplate)){
			//ShowMessage("valid");
			return true;
		}
	}
	return false;
}
