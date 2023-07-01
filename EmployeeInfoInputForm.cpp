//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EmployeeInfoInputForm.h"
#include "Data\AllData.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
	DataModule1->EmployeeTable->Insert();
	DataModule1->EmployeeTable->FieldByName("FirstName")->AsString = Form6->FirstNameBox->Text;
	DataModule1->EmployeeTable->FieldByName("LastName")->AsString = Form6->LastNameBox->Text;
	DataModule1->EmployeeTable->FieldByName("IdentificationNumber")->AsString = Form6->IDNumberBox->Text;
	DataModule1->EmployeeTable->FieldByName("DepartmentCode")->AsInteger = Form6->DepartmentLookup->KeyValue;
	DataModule1->EmployeeTable->FieldByName("Education")->AsString = Form6->EducationBox->Text;
	DataModule1->EmployeeTable->FieldByName("DriverLicense")->AsBoolean = Form6->isDriver->Checked;
	DataModule1->EmployeeTable->FieldByName("Address")->AsString = Form6->AddressBox->Text;
	DataModule1->EmployeeTable->FieldByName("DepositAccountNumber")->AsString = Form6->DepositAccBox->Text;
    DataModule1->EmployeeTable->Post();

}
//---------------------------------------------------------------------------
