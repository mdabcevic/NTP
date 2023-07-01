//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EmployeesForm.h"
#include "Data\AllData.h"
#include "EmployeeInfoInputForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
	Form6->CreateMode();
	Form6->ShowModal();
	DataModule1->EmployeeQuery->Close();
	DataModule1->EmployeeQuery->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
    int employeeID = DBGrid1->DataSource->DataSet->FieldByName("EmployeeID")->AsInteger;
	//AnsiString temp = DataModule1->EmployeeQuery->SQL->Text;
	//DataModule1->EmployeeQuery->Clear();
    TADOQuery *Query1 = new TADOQuery(NULL);
	Query1->Connection = DataModule1->Connection;
	Query1->SQL->Clear();
	Query1->SQL->Add("DELETE FROM Employees WHERE EmployeeID = :ID");
	Query1->Parameters->ParamByName("ID")->Value = employeeID;
	Query1->ExecSQL();
	delete Query1;
	DataModule1->EmployeeQuery->Close();
	DataModule1->EmployeeQuery->Open();

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button3Click(TObject *Sender)
{
	Form6->EditMode();
	Form6->ShowModal();
	DataModule1->EmployeeQuery->Close();
	DataModule1->EmployeeQuery->Open();
}
//---------------------------------------------------------------------------
