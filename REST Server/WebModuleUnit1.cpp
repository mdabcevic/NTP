 
//---------------------------------------------------------------------------
#include "WebModuleUnit1.h"
#include <System.NetEncoding.hpp>
#include <System.StrUtils.hpp>
#include <System.JSON.hpp>


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Signatory"
#pragma link "uTPLb_Codec"
#pragma resource "*.dfm"

TComponentClass WebModuleClass = __classid(TWebModule1);
//---------------------------------------------------------------------------
__fastcall TWebModule1::TWebModule1(TComponent* Owner)
	: TWebModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TWebModule1::WebModule1DefaultHandlerAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled)
{
  Response->Content =
    "<html>"
    "<head><title>Web Server Application</title></head>"
    "<body>Web Server Application</body>"
    "</html>";
}
//---------------------------------------------------------------------------




void __fastcall TWebModule1::WebModule1ActEmployeesAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled)
{
TBytes bytes;
	UnicodeString login;
	UnicodeString username;
	UnicodeString password;
	//meaning user hasn't yet logged in
	if(Request->Authorization == ""){
		Response->StatusCode = 401;
		Response->ReasonString = "Unauthorized";
		Response->ContentType = "text/plain; charset=UTF-8";
		Response->Content = "You have to log in before accessing resources!";
		Response->WWWAuthenticate = "Basic realm=\"MyRest login";
		Response->SendResponse();
	}

	//get and check user credentials
	bytes = TNetEncoding::Base64->DecodeStringToBytes(&Request->Authorization[6]);
	login = StringOf(bytes);
	username = SplitString(login, ":")[0];
	password = SplitString(login, ":")[0];
	//Response->Content = "Successfully Authenticated";

	if(Request->MethodType == mtGet){
		int employee = Request->QueryFields->Values["emp"].ToInt();
		MultiQuery->SQL->Clear();
		MultiQuery->SQL->Add("SELECT EmployeeID, FirstName, LastName FROM Employees WHERE EmployeeID = :id");
		 MultiQuery->Parameters->ParamByName("id")->Value = employee;
		MultiQuery->Open();

		String firstName = MultiQuery->FieldByName("FirstName")->AsString;
		String lastName = MultiQuery->FieldByName("LastName")->AsString;
		//String department = MultiQuery->FieldByName("DepartmentID")->AsI;
		String email = MultiQuery->FieldByName("email")->AsString;


	}
	else if(Request->MethodType ==mtDelete) {
	int employee = Request->QueryFields->Values["emp"].ToInt();
		if(username != "mdabcevic" || password != "test"){
			Response->Content = "You're not authorized to perform this action";
		}
        MultiQuery->SQL->Clear();
		MultiQuery->SQL->Add("DELETE FROM Employee WHERE EmployeeID = :id");
		MultiQuery->Parameters->ParamByName("EmployeeID")->Value = employee;
		MultiQuery->ExecSQL();
        Response->Content = "Employee with ID: " + IntToStr(employee) + " has been deleted.";
	}
	}

//---------------------------------------------------------------------------

