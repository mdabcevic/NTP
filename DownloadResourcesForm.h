//---------------------------------------------------------------------------

#ifndef DownloadResourcesFormH
#define DownloadResourcesFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include <Vcl.ComCtrls.hpp>
#include <IdIntercept.hpp>
#include <IdInterceptThrottler.hpp>
//---------------------------------------------------------------------------
class TForm13 : public TForm
{
__published:	// IDE-managed Components
	TButton *Download;
	TEdit *Link;
	TIdHTTP *HTTP;
	TLabel *Label1;
	TIdSSLIOHandlerSocketOpenSSL *IdSSLIOHandlerSocketOpenSSL1;
	TProgressBar *ProgressBar1;
	TIdInterceptThrottler *Throttler;
	TRadioButton *RadioButton1;
	TLabel *Label2;
	TRadioButton *speed10;
	TRadioButton *speed20;
	TRadioButton *speed30;
	TRadioButton *speed5;
	void __fastcall DownloadClick(TObject *Sender);
	void __fastcall HTTPWorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);
	void __fastcall HTTPWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount);
	void __fastcall RadioButton1Click(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TForm13(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm13 *Form13;
//---------------------------------------------------------------------------
#endif
