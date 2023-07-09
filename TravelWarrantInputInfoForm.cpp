﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TravelWarrantInputInfoForm.h"
#include "Data\AllData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
	TollInfo->Items->Clear();
	TollInfo->Items->Add("Cash");
	TollInfo->Items->Add("ENC device");
	TollInfo->Items->Add("Smart card");
	//ExpensesID = 0;

	translation["AddAttachments"] = {
		{
			{"EN", "Provide attachments"},
			{"HR", "Priložite račune"}

		}
	};

	translation["ArrivalLabel"] = {
		{
			{"EN", "Arrival"},
			{"HR", "Dolazak"}

		}
	};

	translation["PartnersButton"] = {
		{
			{"EN", "Partners"},
			{"HR", "Partneri"}

		}
	};

	translation["CarSelect"] = {
		{
			{"EN", "Select car"},
			{"HR", "Odaberite vozilo"}

		}
	};

	translation["DepartureLabel"] = {
		{
			{"EN", "Departure"},
			{"HR", "Polazak"}

		}
	};

	translation["isInternationalLabel"] = {
		{
			{"EN", "International Travel"},
			{"HR", "Inozemno Putovanje"}

		}
	};

	translation["TitleGeneral"] = {
		{
			{"EN", "General Information"},
			{"HR", "Općenite informacije"}

		}
	};

	translation["CarTitle"] = {
		{
			{"EN", "Company car information"},
			{"HR", "Podaci o službenom vozilu"}

		}
	};

	translation["AttachmentTitle"] = {
		{
			{"EN", "Attachment information"},
			{"HR", "Podaci o računima"}

		}
	};

	translation["PurposeLabel"] = {
		{
			{"EN", "Purposes"},
			{"HR", "Razlozi"}

		}
	};

	translation["TollInfoLabel"] = {
		{
			{"EN", "Toll paid with"},
			{"HR", "Cestarina plaćena putem"}

		}
	};
}
//---------------------------------------------------------------------------

void __fastcall TForm7::WarrantActionClick(TObject *Sender)
{
	UnicodeString partners = MergeIntoString(PartnersList);
	UnicodeString purposes = MergeIntoString(PurposesList);

	//DataModule1->WarrantsQuery->Insert();
	//DataModule1->WarrantsQuery->FieldByName("EmployeeID")->AsInteger = 5;
	if(WarrantAction->Caption == "Create new warrant"){
		DataModule1->WarrantsQuery->FieldByName("EmployeeID")->AsInteger = DataModule1->currentUser.ID;
		if(ExpensesID == 0){
		ShowMessage("Please upload recepits file before proceeding!");
		return;
		}
        DataModule1->WarrantsQuery->FieldByName("AttachmentID")->AsInteger = ExpensesID;
	}
	DataModule1->WarrantsQuery->FieldByName("CreatedAt")->AsDateTime = Now();
	//time is always now, there is no selection :/
	DataModule1->WarrantsQuery->FieldByName("Departure")->AsDateTime = DepartureDateTime->Date +  DepartureDateTime->Time;
	DataModule1->WarrantsQuery->FieldByName("Arrival")->AsDateTime = ArrivalDateTime->Date +  ArrivalDateTime->Time;
	DataModule1->WarrantsQuery->FieldByName("IsInternational")->AsBoolean = isInternational->Checked;
	DataModule1->WarrantsQuery->FieldByName("Partners")->AsString = partners;
	DataModule1->WarrantsQuery->FieldByName("Purposes")->AsString = purposes;
	DataModule1->WarrantsQuery->FieldByName("StartingOdometer")->AsInteger = OdometerStart->Value;
	DataModule1->WarrantsQuery->FieldByName("EndingOdometer")->AsInteger = OdometerEnd->Value;
	DataModule1->WarrantsQuery->FieldByName("Toll")->AsString = TollInfo->Text;
	DataModule1->WarrantsQuery->FieldByName("LicensePlate")->AsString = CarSelection->Text;
	DataModule1->WarrantsQuery->Post();
    ExpensesID = 0;

}
//---------------------------------------------------------------------------

void  TForm7::EditMode(){
	DataModule1->WarrantsQuery->Edit();
	WarrantAction->Caption = "Edit selected warrant";
	ExpensesID = DataModule1->WarrantsQuery->FieldByName("AttachmentID")->AsInteger;
}
//---------------------------------------------------------------------------
void  TForm7::CreateMode(){
	DataModule1->WarrantsQuery->Insert();
	WarrantAction->Caption = "Create new warrant";
    ExpensesID = 0;
}

void __fastcall TForm7::FormShow(TObject *Sender)
{
    ExpensesID = 0;
	DataModule1->purposesHelper.ReadFromFile();
	PurposesList->Clear();
	for(const Purpose& purpose : DataModule1->purposesHelper.allPurposes) {
		UnicodeString name = purpose.name;
		PurposesList->Items->Add(name);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm7::CarSelectClick(TObject *Sender)
{
	Form12->ShowModal();
    CarSelection->Text = DataModule1->currentCar->Get_licenseplate();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::PartnersListClick(TObject *Sender)
{
    //ShowMessage("clicked");   -- doesn't work on CheckListBox
	Form10->ShowModal();
	for(int i = 0; i < PartnersList->Count; i++){
		if(PartnersList->Items->Strings[i] == DataModule1->jsonHelper.currentClient.CompanyName){
			return;
		}
	}
	PartnersList->Items->Add(DataModule1->jsonHelper.currentClient.CompanyName);
}
//---------------------------------------------------------------------------


void __fastcall TForm7::AddAttachmentsClick(TObject *Sender)
{
    Form8->ShowModal();
}
//---------------------------------------------------------------------------

UnicodeString TForm7::MergeIntoString(TCheckListBox* list){
	UnicodeString selectedValues;
	for (int i = 0; i < list->Items->Count; i++) {
  if (list->Checked[i]) {
	selectedValues += list->Items->Strings[i] + " ";
  }
}
selectedValues = selectedValues.Trim();  // Remove trailing space if needed
//ShowMessage(selectedValues);  // Display the concatenated string
return selectedValues;
}
