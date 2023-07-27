
//---------------------------------------------------------------------------
#include "WebModuleUnit1.h"
#include <System.NetEncoding.hpp>
#include <System.StrUtils.hpp>
#include <System.JSON.hpp>


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TComponentClass WebModuleClass = __classid(TWebModule1);
//---------------------------------------------------------------------------
__fastcall TWebModule1::TWebModule1(TComponent* Owner)
	: TWebModule(Owner)
{
	MessageList = new TStringList();
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
	//meaning user hasn't yet logged in
	if(Request->Authorization == ""){
		Response->StatusCode = 401;
		Response->ReasonString = "Unauthorized";
		Response->ContentType = "text/plain; charset=UTF-8";
		Response->Content = "You have to log in to access the resources!";
		Response->WWWAuthenticate = "Basic realm=\"MyRest login";
		Response->SendResponse();
		return;
	}

	//meaning user hasn't logged in yet
	bytes = TNetEncoding::Base64->DecodeStringToBytes(&Request->Authorization[6]);
	UnicodeString login = StringOf(bytes);
	if (login == ":") {
		Response->StatusCode = 401;
        Response->ReasonString = "Unauthorized";
		Response->Content = "You have to log in to access the resources!";
		Response->ContentType = "text/plain; charset=UTF-8";
		Response->SendResponse();
        return;
	}

	//get and check user credentials
	UnicodeString username = SplitString(login, ":")[0];
	UnicodeString password = SplitString(login, ":")[1];
	//Response->Content = "Successfully Authenticated";
	if(Request->MethodType == mtGet){
		//Response->Content = "Message: " + MessageList->Text;
		Response->StatusCode = 200;
		Response->Content = MessageList->Text;
		Response->ContentType = "text/plain; charset=UTF-8";
		Response->SendResponse();
		return;
	}

	else if(Request->MethodType == mtPost) {
		if(login == "mdabcevic:FF22DC28DBEDD5D9064C8A3B75D16E3B99EBDCBD"){
            MessageList->Add(Request->ContentFields->Values[0]);
			Response->StatusCode = 200;
			Response->Content = "Message added successfully";
			Response->ContentType = "text/plain; charset=UTF-8";
			Response->SendResponse();
			return;
		}

		else{
			Response->StatusCode = 401;
			Response->Content = "You're not authorized to perform this action";
			Response->ContentType = "xml; charset=UTF-8";
			Response->SendResponse();
            return;
		}
	}
}

//---------------------------------------------------------------------------


 UnicodeString TWebModule1::ExportEmployee(int id)
 {
	//get record from DB
	Query->SQL->Clear();
	Query->SQL ->Add(EmployeeQuery);
	Query->Parameters->ParamByName("EmployeeID")->Value = id;
	Query->Open();

	//convert it to xml
	String xml = "<employee>";

	xml += "<id>" + Query->FieldByName("EmployeeID")->AsString + "</id>";
	xml += "<firstName>" + Query->FieldByName("FirstName")->AsString + "</firstName>";
	xml += "<lastName>" + Query->FieldByName("LastName")->AsString + "</LastName>";
	xml += "<department>" + Query->FieldByName("DepartmentName")->AsString + "</department>";
	xml += "<email>" + Query->FieldByName("Email")->AsString + "</email>";
	xml += "<phone>" + Query->FieldByName("Phone")->AsString + "</phone>";

	xml += "</employee>";
	Query->Close();
	return xml;
 }

 //---------------------------------------------------------------------------

 UnicodeString TWebModule1::ExportWarrant(int id)
 {
	//get record from DB
	Query->SQL->Clear();
	Query->SQL ->Add(WarrantQuery);
	Query->Parameters->ParamByName("WarrantID")->Value = id;
	Query->Open();

    //convert it to xml
	String xml = "<warrant>";

	xml += "<id>" + Query->FieldByName("WarrantID")->AsString + "</id>";
	xml += "<employee>" + Query->FieldByName("FirstName")->AsString + " " + Query->FieldByName("LastName")->AsString + "</employee>";
	xml += "<department>" + Query->FieldByName("DepartmentName")->AsString + "</department>";
	xml += "<created>" + Query->FieldByName("CreatedAt")->AsString + "</created>";
	xml += "<international>" + Query->FieldByName("IsInternational")->AsString + "</international>";
	xml += "<departure>" + Query->FieldByName("Departure")->AsString + "</departure>";
	xml += "<arrival>" + Query->FieldByName("Arrival")->AsString + "</arrival>";
	xml += "<partners>" + Query->FieldByName("Partners")->AsString + "</partners>";
	xml += "<purposes>" + Query->FieldByName("Purposes")->AsString + "</purposes>";
	xml += "<toll>" + Query->FieldByName("Toll")->AsString + "</toll>";
	xml += "<vehicle>" + Query->FieldByName("LicensePlate")->AsString + "</vehicle>";
	xml += "<odometerStart>" + Query->FieldByName("StartingOdometer")->AsString + "</odometerStart>";
	xml += "<odometerEnd>" + Query->FieldByName("EndingOdometer")->AsString + "</odometerEnd>";

	xml += "</warrant>";
    Query->Close();
	return xml;

 }
void __fastcall TWebModule1::WebModule1ExpEmployeeAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled)
{
	if(Request->QueryFields->Count == 1)
	{
		int EmployeeID = Request->QueryFields->Values["id"].ToInt();
		UnicodeString result = ExportEmployee(EmployeeID);

		Response->StatusCode = 200;
		Response->ReasonString = "OK";
		Response->ContentType = "application/xml; charset=UTF-8";
		Response->Content = result;
	}
	else
	{
		Response->Content = "Bad input";
	}
}
//---------------------------------------------------------------------------

void __fastcall TWebModule1::WebModule1ExpWarrantAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled)
{
    if(Request->QueryFields->Count == 1)
	{
		int WarrantID = Request->QueryFields->Values["id"].ToInt();
		UnicodeString result = ExportWarrant(WarrantID);

		Response->StatusCode = 200;
		Response->ReasonString = "OK";
		Response->ContentType = "application/xml; charset=UTF-8";
		Response->Content = result;
	}
	else
	{
		Response->Content = "Bad input";
	}
}
//---------------------------------------------------------------------------

