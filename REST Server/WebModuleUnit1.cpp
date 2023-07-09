
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

