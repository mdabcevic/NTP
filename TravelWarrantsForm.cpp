//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TravelWarrantsForm.h"
#include "Data\AllData.h"
#include "TravelWarrantInputInfoForm.h"
#include "frxExportPDF.hpp"
#include "frxExportRTF.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
	translation["ReportWarrant"] = {
		{
			{"EN", "Generate report for selected warrant"},
			{"HR", "Ispišite izvještaj za označeni nalog"}

		}
	};

	translation["DeleteButton"] = {
		{
			{"EN", "Delete selected warrant"},
			{"HR", "Izbrišite označeni nalog"}

		}
	};

	translation["Title"] = {
		{
			{"EN", "Travel Warrants"},
			{"HR", "Putni nalozi"}

		}
	};

	translation["EditButton"] = {
		{
			{"EN", "Edit selected warrant"},
			{"HR", "Ažurirajte označeni nalog"}

		}
	};

}
//---------------------------------------------------------------------------
void __fastcall TForm9::DeleteButtonClick(TObject *Sender)
{
	int warrantID = DBGrid1->DataSource->DataSet->FieldByName("WarrantID")->AsInteger;
    TADOQuery *Query1 = new TADOQuery(NULL);
	Query1->Connection = DataModule1->Connection;
	Query1->SQL->Clear();
	Query1->SQL->Add("DELETE FROM TravelWarrants WHERE WarrantID = :ID");
	Query1->Parameters->ParamByName("ID")->Value = warrantID;
	Query1->ExecSQL();
	delete Query1;
	DataModule1->WarrantsQuery->Close();
	DataModule1->WarrantsQuery->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::EditButtonClick(TObject *Sender)
{
    Form7->EditMode();
	Form7->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::ReportWarrantClick(TObject *Sender)
{
	//DataModule1->JoinedReport->Open();
	int selectedWarrantID = DataModule1->WarrantsQuery->FieldByName("WarrantID")->AsInteger;
	DataModule1->JoinedReport->Parameters->ParamByName("WarrantID")->Value = selectedWarrantID;
	if(PDFOption->Checked){
        DataModule1->WarrantLayout->PrepareReport(true);
		DataModule1->WarrantLayout->FileName = "file.pdf";
		DataModule1->WarrantLayout->Export(DataModule1->PDFExport);
		return;
	}
	else{
        DataModule1->WarrantLayout->PrepareReport(true);
		DataModule1->WarrantLayout->FileName = "file.rtf";
		DataModule1->WarrantLayout->Export(DataModule1->RTFExport);
        return;
    }


}
//---------------------------------------------------------------------------

