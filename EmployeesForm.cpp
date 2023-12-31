﻿//---------------------------------------------------------------------------

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
			{"EN", "Department Code"},
			{"HR", "Šifra odjela"}

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
			{"EN", "Department Code"},
			{"HR", "Šifra odjela"}

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
		field = "DepartmentCode";
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
		DataModule1->EmployeeQuery->Filter = "DepartmentCode LIKE '%" + FilterBox->Text + "%'";

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
	//TO DO: change name to name od the employee
	if (PDFRadio->Checked) {
		DataModule1->EmployeeLayout->FileName = "EmployeeReport.pdf";
		DataModule1->EmployeeLayout->Export(DataModule1->PDFExport);
		return;
	}
	else
	DataModule1->EmployeeLayout->FileName = "EmployeeReport.rtf";
    DataModule1->EmployeeLayout->Export(DataModule1->RTFExport);

}
//---------------------------------------------------------------------------
 void TForm4::chartEmployeeTotal(int id)
 {
	DataModule1->ChartingQuery->SQL->Text = DataModule1->EmployeeTotal;
	DataModule1->ChartingQuery->Parameters->ParamByName("id")->Value = id;
	DataModule1->ChartingQuery->Open();
 }
 //---------------------------------------------------------------------------
void __fastcall TForm4::DBGrid1CellClick(TColumn *Column)
{
	chartEmployeeTotal(DataModule1->EmployeeQuery->FieldByName("EmployeeID")->AsInteger);

	UnicodeString fullname = TrimRight(DataModule1->EmployeeQuery->FieldByName("FirstName")->AsString) +   " " +
							TrimRight(DataModule1->EmployeeQuery->FieldByName("LastName")->AsString);
	DBChart1->Title->Text->Clear();
	DBChart1->Title->Text->Add("Ukupna analiza: " + fullname);

	chartEmployeeYearly(DataModule1->EmployeeQuery->FieldByName("EmployeeID")->AsInteger, YearSelection->Text.ToInt());
	UnicodeString monthly = fullname + " - " + YearSelection->Text;
	DBChart2->Title->Text->Clear();
	DBChart2->Title->Text->Add("Godišnja analiza: " + monthly);

}
//---------------------------------------------------------------------------

void TForm4::chartEmployeeYearly(int id, int year)
 {
	DataModule1->ChartingYearly->SQL->Text = DataModule1->EmployeeYearly;
	DataModule1->ChartingYearly->Parameters->ParamByName("id")->Value = id;
	DataModule1->ChartingYearly->Parameters->ParamByName("year")->Value = year;
	DataModule1->ChartingYearly->Open();
 }

void __fastcall TForm4::Button1Click(TObject *Sender)
{
	chartEmployeeYearly(DataModule1->EmployeeQuery->FieldByName("EmployeeID")->AsInteger, YearSelection->Text.ToInt());
	UnicodeString fullname = TrimRight(DataModule1->EmployeeQuery->FieldByName("FirstName")->AsString) +   " " +
							TrimRight(DataModule1->EmployeeQuery->FieldByName("LastName")->AsString);
	UnicodeString monthly = fullname + " - " + YearSelection->Text;
	DBChart2->Title->Text->Clear();
	DBChart2->Title->Text->Add("Godišnja analiza: " + monthly);

}
//---------------------------------------------------------------------------

void __fastcall TForm4::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
    chartEmployeeYearly(DataModule1->EmployeeQuery->FieldByName("EmployeeID")->AsInteger, YearSelection->Text.ToInt());
	UnicodeString fullname = TrimRight(DataModule1->EmployeeQuery->FieldByName("FirstName")->AsString) +   " " +
							TrimRight(DataModule1->EmployeeQuery->FieldByName("LastName")->AsString);
	UnicodeString monthly = fullname + " - " + YearSelection->Text;
	DBChart2->Title->Text->Clear();
	DBChart2->Title->Text->Add("Godišnja analiza: " + monthly);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::DBGrid1MouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled)
{
    chartEmployeeTotal(DataModule1->EmployeeQuery->FieldByName("EmployeeID")->AsInteger);

	UnicodeString fullname = TrimRight(DataModule1->EmployeeQuery->FieldByName("FirstName")->AsString) +   " " +
							TrimRight(DataModule1->EmployeeQuery->FieldByName("LastName")->AsString);
	DBChart1->Title->Text->Clear();
	DBChart1->Title->Text->Add("Ukupna analiza: " + fullname);

	chartEmployeeYearly(DataModule1->EmployeeQuery->FieldByName("EmployeeID")->AsInteger, YearSelection->Text.ToInt());
	UnicodeString monthly = fullname + " - " + YearSelection->Text;
	DBChart2->Title->Text->Clear();
	DBChart2->Title->Text->Add("Godišnja analiza: " + monthly);
}
//---------------------------------------------------------------------------

