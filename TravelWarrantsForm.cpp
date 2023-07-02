//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TravelWarrantsForm.h"
#include "Data\AllData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Button2Click(TObject *Sender)
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
