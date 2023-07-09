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
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm8::FormShow(TObject *Sender)
{
    	AttachmentPreview->Visible = false;
}
//---------------------------------------------------------------------------
