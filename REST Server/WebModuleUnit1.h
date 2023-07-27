 
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
};
//---------------------------------------------------------------------------
extern PACKAGE TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
#endif


