//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EmployeesForm.h"
#include "Data\AllData.h"
#include "EmployeeInfoInputForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
    Form6->ShowModal();
}
//---------------------------------------------------------------------------
