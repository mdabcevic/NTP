//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CustomPurposeInfoInputForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm11 *Form11;
//---------------------------------------------------------------------------
__fastcall TForm11::TForm11(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm11::Button1Click(TObject *Sender)
{
	wcsncpy(DataModule1->purposesHelper.currentPurpose.name, purposeNameBox->Text.c_str(), 50);
	wcsncpy(DataModule1->purposesHelper.currentPurpose.description, purposeDescBox->Text.c_str(), 200);
	DataModule1->purposesHelper.currentPurpose.code = purposeCodeBox->Text.ToInt();
	DataModule1->purposesHelper.currentPurpose.classified = isClassified->Checked;
    DataModule1->purposesHelper.SaveToFile();


}
//---------------------------------------------------------------------------
