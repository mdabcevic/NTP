//---------------------------------------------------------------------------


#pragma hdrstop

#include "AllData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
__fastcall TDataModule1::TDataModule1(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TDataModule1::WarrantsQueryCalcFields(TDataSet *DataSet)
{
	//Sleep(1000);  // Delay for 1 second

	int start = DataSet->FieldByName("StartingOdometer")->AsInteger;
	int end = DataSet->FieldByName("EndingOdometer")->AsInteger;
	DataSet->FieldByName("Mileage")->AsInteger = end - start;

}
//---------------------------------------------------------------------------

