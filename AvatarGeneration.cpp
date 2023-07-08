//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AvatarGeneration.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm14 *Form14;
//---------------------------------------------------------------------------
__fastcall TForm14::TForm14(TComponent* Owner)
	: TForm(Owner)
{
	
}
//---------------------------------------------------------------------------
void __fastcall TForm14::FormShow(TObject *Sender)
{
    RESTRequest1->Execute();
}
//---------------------------------------------------------------------------

