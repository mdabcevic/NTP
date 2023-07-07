 
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
		return;
	}

	//get and check user credentials
	bytes = TNetEncoding::Base64->DecodeStringToBytes(&Request->Authorization[6]);
	login = StringOf(bytes);
	username = SplitString(login, ":")[0];
	password = SplitString(login, ":")[1];
	//Response->Content = "Successfully Authenticated";
	if(Request->MethodType == mtGet){
		Response->Content = "Message: " + MessageList->Text;
	}

	else if(Request->MethodType ==mtDelete) {
		if(username != "mdabcevic" || password != "FF22DC28DBEDD5D9064C8A3B75D16E3B99EBDCBD"){
			Response->Content = "You're not authorized to perform this action";
            return;
		}
		MessageList->Add(Request->ContentFields->Values["message"]);
        Response->StatusCode = 200;
		Response->Content = "Message added successfully";
	}
}

//---------------------------------------------------------------------------

