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
LoadListView();

}
//---------------------------------------------------------------------------
void __fastcall TForm10::AddClientClick(TObject *Sender)
{
	//DataModule1->jsonHelper.currentClient = new Client();
	DataModule1->jsonHelper.currentClient.CompanyName = CompanyNameBox->Text;
	DataModule1->jsonHelper.currentClient.Address = AddressBox->Text;
	DataModule1->jsonHelper.currentClient.IdentificationNumber = IDBox->Text;
	DataModule1->jsonHelper.currentClient.Email = EmailBox->Text;
	DataModule1->jsonHelper.currentClient.ContactPerson = ContactPersonBox->Text;
	DataModule1->jsonHelper.AddClient();
    //DataModule1->jsonHelper.RewriteFile();
	LoadListView();
}
//---------------------------------------------------------------------------
void TForm10::LoadListView(){
//fill the list view
ListView1->Items->Clear();
  for(int i = 0; i < DataModule1->jsonHelper.allClients.size(); i++){
	ListView1->Items->Add();
		ListView1->Items->Item[i]->Caption = DataModule1->jsonHelper.allClients[i].CompanyName;
		ListView1->Items->Item[i]->SubItems->Add(DataModule1->jsonHelper.allClients[i].Address);
		ListView1->Items->Item[i]->SubItems->Add(DataModule1->jsonHelper.allClients[i].IdentificationNumber);
		ListView1->Items->Item[i]->SubItems->Add(DataModule1->jsonHelper.allClients[i].Email);
		ListView1->Items->Item[i]->SubItems->Add(DataModule1->jsonHelper.allClients[i].ContactPerson);
  }
}
void __fastcall TForm10::DeleteClientClick(TObject *Sender)
{
	if(ListView1->ItemIndex == -1){
		return;
	}
	DataModule1->jsonHelper.DeleteClient(ListView1->ItemIndex);
    DataModule1->jsonHelper.RewriteFile();
	LoadListView();
    ListView1->ItemIndex = -1;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm10::ListView1SelectItem(TObject *Sender, TListItem *Item, bool Selected)

{
	if(ListView1->ItemIndex == -1){
		DataModule1->jsonHelper.currentClient.CompanyName = "";
		DataModule1->jsonHelper.currentClient.Address = "";
		DataModule1->jsonHelper.currentClient.IdentificationNumber = "";
		DataModule1->jsonHelper.currentClient.Email = "";
		DataModule1->jsonHelper.currentClient.ContactPerson = "";
		return;
	}
	DataModule1->jsonHelper.currentClient.CompanyName = ListView1->Selected->Caption;
	DataModule1->jsonHelper.currentClient.Address = ListView1->Selected->SubItems->Strings[0];
	DataModule1->jsonHelper.currentClient.IdentificationNumber = ListView1->Selected->SubItems->Strings[1];
	DataModule1->jsonHelper.currentClient.Email = ListView1->Selected->SubItems->Strings[2];
	DataModule1->jsonHelper.currentClient.ContactPerson = ListView1->Selected->SubItems->Strings[3];
}
//---------------------------------------------------------------------------

void __fastcall TForm10::EditClientClick(TObject *Sender)
{
	if(ListView1->ItemIndex == -1){
		return;
	}
    DataModule1->jsonHelper.currentClient.CompanyName = CompanyNameBox->Text;
	DataModule1->jsonHelper.currentClient.Address = AddressBox->Text;
	DataModule1->jsonHelper.currentClient.IdentificationNumber = IDBox->Text;
	DataModule1->jsonHelper.currentClient.Email = EmailBox->Text;
	DataModule1->jsonHelper.currentClient.ContactPerson = ContactPersonBox->Text;
	DataModule1->jsonHelper.EditClient(ListView1->ItemIndex);
    LoadListView();
}
//---------------------------------------------------------------------------

