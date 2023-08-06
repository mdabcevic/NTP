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
	DataModule1->JoinedReport->SQL->Text =
	"WITH AllExpenses AS ( \n"
	"    SELECT tw.AttachmentID, tw.WarrantID, \n"
	"        CASE WHEN te.TransportationToll = 1 THEN 'Cestarina, ' ELSE '' END + \n"
	"        CASE WHEN te.Hospitality = 1 THEN 'Reprezentacija, ' ELSE '' END + \n"
	"        CASE WHEN te.Parking = 1 THEN 'Parking, ' ELSE '' END + \n"
	"        CASE WHEN te.Accomodation = 1 THEN 'Smještaj ' ELSE '' END + \n"
	"        CASE WHEN te.Other = 1 THEN 'Ostali troškovi ' ELSE '' END AS expensesList \n"
	"    FROM TravelExpenses AS te  \n"
	"    INNER JOIN TravelWarrants AS tw ON te.ExpensesID = tw.AttachmentID \n"
	") \n"
	"SELECT	tw.*,  \n"
	"        RTRIM(emp.FirstName) + ' ' + RTRIM(emp.LastName) as imePrezime,  \n"
    "        RTRIM( dep.DepartmentName) AS Department,\n"

	"        DATEDIFF(DAY,tw.Departure, tw.Arrival) as Duration,  \n"
	"        CASE WHEN tw.IsInternational = 1 THEN 'Da' ELSE 'Ne' END as \"Inozemno?\", \n"
	"        RTRIM(auth.FirstName) + ' ' + RTRIM(auth.LastName) as AuthorizedByName, \n"
	"        ae.AttachmentID, ae.expensesList \n"
	"FROM TravelWarrants as tw \n"
	"INNER JOIN Employees as emp on tw.EmployeeID = emp.EmployeeID \n"
	"INNER JOIN Departments as dep on emp.DepartmentCode = dep.DepartmentCode \n"
	"LEFT JOIN AllExpenses as ae on tw.WarrantID = ae.WarrantID \n"
	"LEFT JOIN Employees as auth on tw.AuthorizedBy = auth.EmployeeID \n"
	"WHERE tw.WarrantID = :WarrantID";

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

void __fastcall TForm9::Button1Click(TObject *Sender)
{
	DataModule1->MultiQuery->SQL->Clear();
	AnsiString updateSQL = "UPDATE TravelWarrants SET AuthorizedBy = :AuthorizedBy WHERE WarrantID = :WarrantID";
	DataModule1->MultiQuery->SQL->Text = updateSQL;
	DataModule1->MultiQuery->Parameters->ParamByName("AuthorizedBy")->Value = DataModule1->currentUser.ID;
	DataModule1->MultiQuery->Parameters->ParamByName("WarrantID")->Value = DataModule1->WarrantsQuery->FieldByName("WarrantID")->AsInteger; // Specify the ID of the record you want to update
	DataModule1->MultiQuery->ExecSQL();
    DataModule1->MultiQuery->SQL->Clear();
	DataModule1->WarrantsQuery->Close();
	DataModule1->WarrantsQuery->Open();

}
//---------------------------------------------------------------------------


void __fastcall TForm9::UpdateFilters(TObject *Sender)
{
	if(CheckBox1->Checked && CheckBox2->Checked)
	{
		DataModule1->WarrantsQuery->SQL->Text =
	"WITH AllExpenses AS (\n"
	"    SELECT tw.AttachmentID, tw.WarrantID,\n"
	"        CASE WHEN te.TransportationToll = 1 THEN 'Cestarina, ' ELSE '' END +\n"
	"        CASE WHEN te.Hospitality = 1 THEN 'Reprezentacija, ' ELSE '' END +\n"
	"        CASE WHEN te.Parking = 1 THEN 'Parking, ' ELSE '' END +\n"
	"        CASE WHEN te.Accomodation = 1 THEN 'Smještaj ' ELSE '' END +\n"
	"        CASE WHEN te.Other = 1 THEN 'Ostali troškovi ' ELSE '' END AS expensesList\n"
	"        FROM TravelExpenses AS te \n"
	"    INNER JOIN TravelWarrants AS tw ON te.ExpensesID = tw.AttachmentID\n"
	")\n"
	"SELECT tw.*, \n"
	"        RTRIM(emp.FirstName) + ' ' + RTRIM(emp.LastName) as imePrezime, \n"
	"        DATEDIFF(DAY,tw.Departure, tw.Arrival) as Duration, \n"
	"        CASE WHEN tw.IsInternational = 1 THEN 'Da' ELSE 'Ne' END as \"Inozemno?\",\n"
	"        RTRIM(auth.FirstName) + ' ' + RTRIM(auth.LastName) as AuthorizedByName,\n"
	"        ae.AttachmentID, ae.expensesList\n"
	"FROM TravelWarrants as tw\n"
	"INNER JOIN Employees as emp on tw.EmployeeID = emp.EmployeeID\n"
	"INNER JOIN Departments as dep on emp.DepartmentCode = dep.DepartmentCode\n"
	"LEFT JOIN AllExpenses as ae on tw.WarrantID = ae.WarrantID\n"
	"LEFT JOIN Employees as auth on tw.AuthorizedBy = auth.EmployeeID\n"
	"ORDER BY tw.Departure DESC;";

		DataModule1->WarrantsQuery->Close();
		DataModule1->WarrantsQuery->Open();
		return;
	}
	else if (CheckBox2->Checked)
	{
		DataModule1->WarrantsQuery->SQL->Text =
	"WITH AllExpenses AS (\n"
	"    SELECT tw.AttachmentID, tw.WarrantID,\n"
	"        CASE WHEN te.TransportationToll = 1 THEN 'Cestarina, ' ELSE '' END +\n"
	"        CASE WHEN te.Hospitality = 1 THEN 'Reprezentacija, ' ELSE '' END +\n"
	"        CASE WHEN te.Parking = 1 THEN 'Parking, ' ELSE '' END +\n"
	"        CASE WHEN te.Accomodation = 1 THEN 'Smještaj ' ELSE '' END +\n"
	"        CASE WHEN te.Other = 1 THEN 'Ostali troškovi ' ELSE '' END AS expensesList\n"
	"        FROM TravelExpenses AS te \n"
	"    INNER JOIN TravelWarrants AS tw ON te.ExpensesID = tw.AttachmentID\n"
	")\n"
	"SELECT tw.*, \n"
	"        RTRIM(emp.FirstName) + ' ' + RTRIM(emp.LastName) as imePrezime, \n"
	"        DATEDIFF(DAY,tw.Departure, tw.Arrival) as Duration, \n"
	"        CASE WHEN tw.IsInternational = 1 THEN 'Da' ELSE 'Ne' END as \"Inozemno?\",\n"
	"        RTRIM(auth.FirstName) + ' ' + RTRIM(auth.LastName) as AuthorizedByName,\n"
	"        ae.AttachmentID, ae.expensesList\n"
	"FROM TravelWarrants as tw\n"
	"INNER JOIN Employees as emp on tw.EmployeeID = emp.EmployeeID\n"
	"INNER JOIN Departments as dep on emp.DepartmentCode = dep.DepartmentCode\n"
	"LEFT JOIN AllExpenses as ae on tw.WarrantID = ae.WarrantID\n"
	"LEFT JOIN Employees as auth on tw.AuthorizedBy = auth.EmployeeID\n"
	"WHERE tw.AuthorizedBy IS NULL\n"
	"ORDER BY tw.Departure DESC;";
		DataModule1->WarrantsQuery->Close();
		DataModule1->WarrantsQuery->Open();
	}
	else if(CheckBox1->Checked)
	{
		DataModule1->WarrantsQuery->SQL->Text =
	"WITH AllExpenses AS (\n"
	"    SELECT tw.AttachmentID, tw.WarrantID,\n"
	"        CASE WHEN te.TransportationToll = 1 THEN 'Cestarina, ' ELSE '' END +\n"
	"        CASE WHEN te.Hospitality = 1 THEN 'Reprezentacija, ' ELSE '' END +\n"
	"        CASE WHEN te.Parking = 1 THEN 'Parking, ' ELSE '' END +\n"
	"        CASE WHEN te.Accomodation = 1 THEN 'Smještaj ' ELSE '' END +\n"
	"        CASE WHEN te.Other = 1 THEN 'Ostali troškovi ' ELSE '' END AS expensesList\n"
	"        FROM TravelExpenses AS te \n"
	"    INNER JOIN TravelWarrants AS tw ON te.ExpensesID = tw.AttachmentID\n"
	")\n"
	"SELECT tw.*, \n"
	"        RTRIM(emp.FirstName) + ' ' + RTRIM(emp.LastName) as imePrezime, \n"
	"        DATEDIFF(DAY,tw.Departure, tw.Arrival) as Duration, \n"
	"        CASE WHEN tw.IsInternational = 1 THEN 'Da' ELSE 'Ne' END as \"Inozemno?\",\n"
	"        RTRIM(auth.FirstName) + ' ' + RTRIM(auth.LastName) as AuthorizedByName,\n"
	"        ae.AttachmentID, ae.expensesList\n"
	"FROM TravelWarrants as tw\n"
	"INNER JOIN Employees as emp on tw.EmployeeID = emp.EmployeeID\n"
	"INNER JOIN Departments as dep on emp.DepartmentCode = dep.DepartmentCode\n"
	"LEFT JOIN AllExpenses as ae on tw.WarrantID = ae.WarrantID\n"
	"LEFT JOIN Employees as auth on tw.AuthorizedBy = auth.EmployeeID\n"
	"WHERE tw.AuthorizedBy IS NOT NULL\n"
	"ORDER BY tw.Departure DESC;";
		DataModule1->WarrantsQuery->Close();
		DataModule1->WarrantsQuery->Open();
	}
	else
	{
        DataModule1->WarrantsQuery->SQL->Text =
	"WITH AllExpenses AS (\n"
	"    SELECT tw.AttachmentID, tw.WarrantID,\n"
	"        CASE WHEN te.TransportationToll = 1 THEN 'Cestarina, ' ELSE '' END +\n"
	"        CASE WHEN te.Hospitality = 1 THEN 'Reprezentacija, ' ELSE '' END +\n"
	"        CASE WHEN te.Parking = 1 THEN 'Parking, ' ELSE '' END +\n"
	"        CASE WHEN te.Accomodation = 1 THEN 'Smještaj ' ELSE '' END +\n"
	"        CASE WHEN te.Other = 1 THEN 'Ostali troškovi ' ELSE '' END AS expensesList\n"
	"        FROM TravelExpenses AS te \n"
	"    INNER JOIN TravelWarrants AS tw ON te.ExpensesID = tw.AttachmentID\n"
	")\n"
	"SELECT tw.*, \n"
	"        RTRIM(emp.FirstName) + ' ' + RTRIM(emp.LastName) as imePrezime, \n"
	"        DATEDIFF(DAY,tw.Departure, tw.Arrival) as Duration, \n"
	"        CASE WHEN tw.IsInternational = 1 THEN 'Da' ELSE 'Ne' END as \"Inozemno?\",\n"
    "        RTRIM(auth.FirstName) + ' ' + RTRIM(auth.LastName) as AuthorizedByName,\n"
	"        ae.AttachmentID, ae.expensesList\n"
	"FROM TravelWarrants as tw\n"
	"INNER JOIN Employees as emp on tw.EmployeeID = emp.EmployeeID\n"
	"INNER JOIN Departments as dep on emp.DepartmentCode = dep.DepartmentCode\n"
	"LEFT JOIN AllExpenses as ae on tw.WarrantID = ae.WarrantID\n"
	"LEFT JOIN Employees as auth on tw.AuthorizedBy = auth.EmployeeID\n"
	"WHERE tw.AuthorizedBy IS NOT NULL AND tw.AuthorizedBy IS NULL\n"
	"ORDER BY tw.Departure DESC;";
		DataModule1->WarrantsQuery->Close();
		DataModule1->WarrantsQuery->Open();
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm9::FormShow(TObject *Sender)
{
    WindowState = wsMaximized;
}
//---------------------------------------------------------------------------

