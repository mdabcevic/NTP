//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ExpensesInputInfoForm.h"
#include "Data\AllData.h"
#include <jpeg.hpp>
#include <pngimage.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
	translation["Upload"] = {
		{
			{"EN", "Upload merged recepits"},
			{"HR", "Spremite spojene račune"}
		}
	};

	translation["isAccomodation"] = {
		{
			{"EN", "Accomodation"},
			{"HR", "Smještaj"}

		}
	};

	translation["isHospitality"] = {
		{
			{"EN", "Hospitality (Entertainment)"},
			{"HR", "Ugošćavanje (Reprezentacija)"}

		}
	};

	translation["isOther"] = {
		{
			{"EN", "Other expenses"},
			{"HR", "Ostali troškovi"}

		}
	};

	translation["isToll"] = {
		{
			{"EN", "Toll (Road, Tunnel, Ferry, Vignette)"},
			{"HR", "Cestarina (Tunelarina, Vinjeta, Trajekt)"}

		}
	};

	translation["Title"] = {
		{
			{"EN", "Travel expenses information"},
			{"HR", "Podaci o putnim troškovima"}

		}
	};

}
//---------------------------------------------------------------------------
void __fastcall TForm8::UploadClick(TObject *Sender)
{
	if(DataModule1->OpenDialog1->Execute()){
		DataModule1->ExpensesQuery->Insert();
		static_cast<TBlobField*>(DataModule1->ExpensesQuery->FieldByName("Attachments"))->LoadFromFile(DataModule1->OpenDialog1->FileName);
		DataModule1->ExpensesQuery->FieldByName("TransportationToll")->AsBoolean = isToll->Checked;
		DataModule1->ExpensesQuery->FieldByName("Hospitality")->AsBoolean = isHospitality->Checked;
		DataModule1->ExpensesQuery->FieldByName("Parking")->AsBoolean = isParking->Checked;
		DataModule1->ExpensesQuery->FieldByName("Accomodation")->AsBoolean = isAccomodation->Checked;
        DataModule1->ExpensesQuery->FieldByName("Other")->AsBoolean = isOther->Checked;
		DataModule1->ExpensesQuery->Post();
		AttachmentPreview->Visible = true;
		ExpenseIDVal->Visible = true;
		ExpenseID->Visible = true;
		Form7->ExpensesID = DataModule1->ExpensesQuery->FieldByName("ExpensesID")->AsInteger;

	}
}

//---------------------------------------------------------------------------
void __fastcall TForm8::EditExpenses(TObject *Sender)
{
	if(DataModule1->OpenDialog1->Execute()){
		DataModule1->ExpensesQuery->SQL->Text = "SELECT * FROM TravelExpenses WHERE ExpensesID = :ExpenseID";
		DataModule1->ExpensesQuery->Parameters->ParamByName("ExpenseID")->Value = DataModule1->WarrantsQuery->FieldByName("AttachmentID")->AsInteger;
        DataModule1->ExpensesQuery->Open();
		DataModule1->ExpensesQuery->Edit();

		static_cast<TBlobField*>(DataModule1->ExpensesQuery->FieldByName("Attachments"))->LoadFromFile(DataModule1->OpenDialog1->FileName);
		DataModule1->ExpensesQuery->FieldByName("TransportationToll")->AsBoolean = isToll->Checked;
		DataModule1->ExpensesQuery->FieldByName("Hospitality")->AsBoolean = isHospitality->Checked;
		DataModule1->ExpensesQuery->FieldByName("Parking")->AsBoolean = isParking->Checked;
		DataModule1->ExpensesQuery->FieldByName("Accomodation")->AsBoolean = isAccomodation->Checked;
		DataModule1->ExpensesQuery->FieldByName("Other")->AsBoolean = isOther->Checked;
		DataModule1->ExpensesQuery->Post();
		DataModule1->ExpensesQuery->Close();
		DataModule1->ExpensesQuery->Open();
		//Form7->ExpensesID = DataModule1->ExpensesQuery->FieldByName("ExpensesID")->AsInteger;
		DataModule1->ExpensesQuery->SQL->Text = "SELECT * FROM TravelExpenses";
        Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm8::FormShow(TObject *Sender)
{
		AttachmentPreview->Visible = false;
		ExpenseIDVal->Visible = false;
		ExpenseID->Visible = false;
}
//---------------------------------------------------------------------------
