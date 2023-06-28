//---------------------------------------------------------------------------

#ifndef TestWindowH
#define TestWindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Data/AllData.h"
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *LoadIni_test;
	TButton *SaveIni_Test;
	TButton *LoadWR_Test;
	void __fastcall LoadIni_testClick(TObject *Sender);
private:	// User declarations
public:		// User declarations

	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif