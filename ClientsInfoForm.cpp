//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ClientsInfoForm.h"
#include "Data\AllData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{
    //make ListView columns have equally distributed width & fill entire space
if(ListView1->Columns->Count > 0)
  {
    int ColWidth = ListView1->ClientWidth / ListView1->Columns->Count;
    for(int i = 0; i < ListView1->Columns->Count; i++)
	  ListView1->Columns->Items[i]->Width = ColWidth;
  }

  //fill the list view
  for(int i = 0; i < DataModule1->jsonHelper.allClients.size(); i++){
    ListView1->Items->Add();
		ListView1->Items->Item[i]->Caption = DataModule1->jsonHelper.allClients[i]->CompanyName;
		ListView1->Items->Item[i]->SubItems->Add(DataModule1->jsonHelper.allClients[i]->Address);
		ListView1->Items->Item[i]->SubItems->Add(DataModule1->jsonHelper.allClients[i]->IdentificationNumber);
		ListView1->Items->Item[i]->SubItems->Add(DataModule1->jsonHelper.allClients[i]->Email);
		ListView1->Items->Item[i]->SubItems->Add(DataModule1->jsonHelper.allClients[i]->ContactPerson);
  }
}
//---------------------------------------------------------------------------
