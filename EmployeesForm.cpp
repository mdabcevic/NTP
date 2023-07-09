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
	//GroupBox1->SendToBack();
	//RadioButton1->BringToFront();
	translation["AddButton"] = {
		{
			{"EN", "Add new employee "},
			{"HR", "Unesite novog zaposlenika"}

		}
	};

	translation["ClearFilter"] = {
		{
			{"EN", "Clear Filter "},
			{"HR", "Očistite filtere"}

		}
	};

	translation["DeleteButton"] = {
		{
			{"EN", "Delete selected employee "},
			{"HR", "Izbrišite odabranog zaposlenika"}

		}
	};

	translation["DepartmentFilterOption"] = {
		{
			{"EN", "Department Name"},
			{"HR", "Ime odjela"}

		}
	};

	translation["EditButton"] = {
		{
			{"EN", "Edit selected employee"},
			{"HR", "Ažurirajte odabranog zaposlenika"}

		}
	};

	translation["FilteringBox"] = {
		{
			{"EN", "Filtering field"},
			{"HR", "Stupac za filtriranje"}

		}
	};

	translation["FnFilterOption"] = {
		{
			{"EN", "First Name"},
			{"HR", "Ime"}

		}
	};

    translation["Title"] = {
		{
			{"EN", "Employees"},
			{"HR", "Zaposlenici"}

		}
	};

	translation["LnFilterOption"] = {
		{
			{"EN", "Last Name"},
			{"HR", "Prezime"}

		}
	};

	translation["ReportPrint"] = {
		{
			{"EN", "Print report for selected employee"},
			{"HR", "Ispišite izvješće za odabranog zaposlenika"}

		}
	};

	translation["Sorting2Box"] = {
		{
			{"EN", "Sorting Direction"},
			{"HR", "Smjer sortiranja"}

		}
	};

	translation["AscSortOption"] = {
		{
			{"EN", "Ascending"},
			{"HR", "Uzlazno"}

		}
	};

	translation["DescSortOption"] = {
		{
			{"EN", "Descending"},
			{"HR", "Silazno"}

		}
	};

	translation["SortingBox"] = {
		{
			{"EN", "Sorting Field"},
			{"HR", "Stupac za sortiranje"}

		}
	};

	translation["DepartmentSortOption"] = {
		{
			{"EN", "Department"},
			{"HR", "Odjel"}

		}
	};

	translation["FnSortOption"] = {
		{
			{"EN", "First Name"},
			{"HR", "Ime"}

		}
	};

	translation["LnSortOption"] = {
		{
			{"EN", "Last Name"},
			{"HR", "Prezime"}

		}
	};

	translation["NoSortOption"] = {
		{
			{"EN", "None"},
			{"HR", "Bez sortiranja"}

		}
	};
}
//---------------------------------------------------------------------------
void __fastcall TForm4::AddButtonClick(TObject *Sender)
{
	Form6->CreateMode();
	Form6->ShowModal();
	DataModule1->EmployeeQuery->Close();
	DataModule1->EmployeeQuery->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::DeleteButtonClick(TObject *Sender)
{
	DataModule1->CheckAuthentication();

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
void __fastcall TForm4::EditButtonClick(TObject *Sender)
{
	Form6->EditMode();
	Form6->ShowModal();
	//DataModule1->EmployeeQuery->Close();
	//DataModule1->EmployeeQuery->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Sort(TObject *Sender)
{
	String field;
	String direction;

     // Check which field radio button was selected
	if(FnSortOption->Checked)
		field = "FirstName";
	else if(LnSortOption->Checked)
		field = "LastName";
    else if(DepartmentSortOption->Checked)
		field = "DepartmentName";
	else{
		// if there is no sorting, go out
		DataModule1->EmployeeQuery->Sort = "";
		return;
	}

    // Check which sort direction radio button was selected
	if(DescSortOption->Checked)
		direction = "DESC";
	else
		//default
		direction = "ASC";
	DataModule1->EmployeeQuery->Sort = field + " " + direction;



}
//---------------------------------------------------------------------------
void __fastcall TForm4::Filter(TObject *Sender)
{
	if(FilterBox->Text == "")
		return;
	if(FnFilterOption->Checked)
		DataModule1->EmployeeQuery->Filter = "FirstName LIKE '%" + FilterBox->Text + "%'";
else if (LnFilterOption->Checked)
		DataModule1->EmployeeQuery->Filter = "LastName LIKE '%" + FilterBox->Text + "%'";
else if (DepartmentFilterOption->Checked)
		DataModule1->EmployeeQuery->Filter = "DepartmentName LIKE '%" + FilterBox->Text + "%'";

DataModule1->EmployeeQuery->Filtered = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ClearFilterClick(TObject *Sender)
{
	FnFilterOption->Checked = false;
	LnFilterOption->Checked = false;
	DepartmentFilterOption->Checked = false;
    DataModule1->EmployeeQuery->Filtered = false;
	DataModule1->EmployeeQuery->Filter = "";
    FilterBox->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ReportPrintClick(TObject *Sender)
{
	DataModule1->EmployeeLayout->PrepareReport(true);
	DataModule1->EmployeeLayout->FileName = "EmployeeReport.pdf";
	DataModule1->EmployeeLayout->Export(DataModule1->PDFExport);
}
//---------------------------------------------------------------------------

