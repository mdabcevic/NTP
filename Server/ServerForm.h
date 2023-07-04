//---------------------------------------------------------------------------

#ifndef ServerFormH
#define ServerFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <IdContext.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TIdTCPServer *TCPServer;
	TXMLDocument *XmlDoc;
	void __fastcall TCPServerExecute(TIdContext *AContext);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

	// server actions
    String FindAction(String code, TIdContext *AContext);
	String AddToXml(TIdContext *AContext);
	String SendXml(TIdContext *AContext);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
