//---------------------------------------------------------------------------

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
}
//---------------------------------------------------------------------------

void __fastcall TForm7::WarrantActionClick(TObject *Sender)
{
	//DataModule1->WarrantsQuery->Insert();
	DataModule1->WarrantsQuery->FieldByName("EmployeeID")->AsInteger = 5;
	DataModule1->WarrantsQuery->FieldByName("CreatedAt")->AsDateTime = Now();
	DataModule1->WarrantsQuery->FieldByName("Departure")->AsDateTime = DepartureDateTime->Date +  DepartureDateTime->Time;
	DataModule1->WarrantsQuery->FieldByName("Arrival")->AsDateTime = ArrivalDateTime->Date +  ArrivalDateTime->Time;
	DataModule1->WarrantsQuery->FieldByName("IsInternational")->AsBoolean = isInternational->Checked;
	DataModule1->WarrantsQuery->FieldByName("Partners")->AsString = "HARDCODED HARDCODED HARDCODED";
	DataModule1->WarrantsQuery->FieldByName("Purposes")->AsString = "HARDCODED HARDCODED HARDCODED";
	DataModule1->WarrantsQuery->FieldByName("StartingOdometer")->AsInteger = OdometerStart->Value;
	DataModule1->WarrantsQuery->FieldByName("EndingOdometer")->AsInteger = OdometerEnd->Value;
	DataModule1->WarrantsQuery->FieldByName("Toll")->AsString = "HARDCODED";
	DataModule1->WarrantsQuery->FieldByName("LicensePlate")->AsString = "HARDCODED";
	DataModule1->WarrantsQuery->FieldByName("AttachmentID")->AsInteger = 1;
	DataModule1->WarrantsQuery->Post();

}
//---------------------------------------------------------------------------

void  TForm7::EditMode(){
	DataModule1->WarrantsQuery->Edit();
	WarrantAction->Caption = "Edit selected warrant";
}
//---------------------------------------------------------------------------
void  TForm7::CreateMode(){
	DataModule1->WarrantsQuery->Insert();
	WarrantAction->Caption = "Create new warrant";
}
