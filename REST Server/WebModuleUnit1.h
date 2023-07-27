 
//---------------------------------------------------------------------------
#ifndef WebModuleUnit1H
#define WebModuleUnit1H
//---------------------------------------------------------------------------
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Web.HTTPApp.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Signatory.hpp"
#include "uTPLb_Codec.hpp"
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TWebModule1 : public TWebModule
{
__published:	// IDE-managed Components
	TADOConnection *Connection;
	TADOQuery *Query;
	void __fastcall WebModule1DefaultHandlerAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled);
	void __fastcall WebModule1ActEmployeesAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled);
private:	// User declarations
public:		// User declarations
	__fastcall TWebModule1(TComponent* Owner);
	TStringList* MessageList = new TStringList();
	UnicodeString EmployeeQuery =
		"SELECT emp.EmployeeID, emp.FirstName, emp.LastName, emp.Email, emp.Phone, dep.DepartmentName "
		"FROM Employees as emp "
		"INNER JOIN Departments as dep ON emp.DepartmentCode = dep.DepartmentCode "
		"WHERE emp.EmployeeID = :EmployeeID";
	UnicodeString WarrantQuery =
        "SELECT tw.WarrantID, emp.FirstName, emp.LastName, dep.DepartmentName, "
				"tw.CreatedAt, tw.IsInternational, tw.Departure, tw.Arrival, tw.Partners, tw.Purposes, tw.Toll, "
				"tw.LicensePlate, tw.StartingOdometer, tw.EndingOdometer "
		"FROM TravelWarrants as tw "
		"INNER JOIN Employees as emp ON tw.EmployeeID = emp.EmployeeID "
		"INNER JOIN Departments as dep ON emp.DepartmentCode = dep.DepartmentCode "
		"WHERE tw.WarrantID = :WarrantID";

	UnicodeString ExportEmployee(int id);
    UnicodeString ExportWarrant(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
#endif


