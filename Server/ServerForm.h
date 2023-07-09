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
#include <IdUDPBase.hpp>
#include <IdUDPServer.hpp>
#include <IdGlobal.hpp>
#include <IdSocketHandle.hpp>
#include "../Helpers/JSONHelper.h"
#include "../Data/Client.h"
#include "companycars.h"
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Codec.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include <System.SysUtils.hpp>
#include "uTPLb_Signatory.hpp"
#include <Xml.adomxmldom.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TIdTCPServer *TCPServer;
	TXMLDocument *XmlDoc;
	TIdUDPServer *UDPServer;
	TCodec *AsymCodec;
	TCryptographicLibrary *AsymLib;
	TSignatory *AsymSign;
	TIdUDPServer *UDPFileServer;
	TCodec *SymCodec;
	void __fastcall TCPServerExecute(TIdContext *AContext);
	void __fastcall UDPServerUDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding);
	void __fastcall UDPFileServerUDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

	String SymKey = "somereallylongandcomplicatedsymstringkey";

	TCriticalSection *CriticalSection = new TCriticalSection;
	// server actions
	String FindAction(String code, TIdContext *AContext);
	String AddToXml(TIdContext *AContext);
	String SendXml(TIdContext *AContext);
	String ReceivePublicKey(TIdContext *AContext);
	String SendSymKey(TIdContext *AContext);

    __fastcall TForm1::~TForm1()
{
	delete CriticalSection;
}
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
