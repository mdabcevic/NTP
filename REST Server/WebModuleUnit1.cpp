 
//---------------------------------------------------------------------------
#include "WebModuleUnit1.h"
#include <System.NetEncoding.hpp>
#include <System.StrUtils.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
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


void __fastcall TWebModule1::WebModule1AuthActAction(TObject *Sender, TWebRequest *Request,
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
	Response->Content = 8129;

	//use given code to avoid logging in on other res.

	//auth either by departments (racunovodstvo to have more control in app)
	//or by personnel


}
//---------------------------------------------------------------------------
