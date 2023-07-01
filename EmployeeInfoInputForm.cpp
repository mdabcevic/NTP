//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EmployeeInfoInputForm.h"
#include "Data\AllData.h"
#include "EmployeesForm.h"

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
void __fastcall TForm6::EmployeeActionButtonClick(TObject *Sender)
{
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
void TForm6::EditMode(){
	Form6->EmployeeActionButton->Caption = "Edit employee";
	Form6->FirstNameBox->Text = Form4->DBGrid1->DataSource->DataSet->FieldByName("FirstName")->AsString;
	Form6->LastNameBox->Text = Form4->DBGrid1->DataSource->DataSet->FieldByName("LastName")->AsString;
	//Form6->IDNumberBox->Text = Form4->DBGrid1->DataSource->DataSet->FieldByName("IdentificationNumber")->AsString;
	//Form6->DepartmentLookup->KeyValue = Form4->DBGrid1->DataSource->DataSet->FieldByName("EmployeeID")->AsInteger;
	//Form6->EducationBox->Text = Form4->DBGrid1->DataSource->DataSet->FieldByName("Education")->AsString;
	//Form6->isDriver->Checked = Form4->DBGrid1->DataSource->DataSet->FieldByName("DriverLicense")->AsBoolean;
	//Form6->AddressBox->Text = Form4->DBGrid1->DataSource->DataSet->FieldByName("Address")->AsString;
	//Form6->DepositAccBox->Text = Form4->DBGrid1->DataSource->DataSet->FieldByName("DepositAccountNumber")->AsString;
	DataModule1->EmployeeTable->Edit();
}
//---------------------------------------------------------------------------
void TForm6::CreateMode(){
	Form6->EmployeeActionButton->Caption = "Create employee";
	Form6->FirstNameBox->Text = "";
	Form6->LastNameBox->Text = "";
	Form6->IDNumberBox->Text = "";
	Form6->DepartmentLookup->KeyValue = -1;
	Form6->EducationBox->Text = "";
	Form6->isDriver->Checked = false;
	Form6->AddressBox->Text = "";
	Form6->DepositAccBox->Text = "";
	DataModule1->EmployeeTable->Insert();
}
