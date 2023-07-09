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
	translation["SubmitButton"] = {
		{
			{"EN", "Submit "},
			{"HR", "Dodajte na popis"}

		}
	};

	translation["CodeLabel"] = {
		{
			{"EN", "Code "},
			{"HR", "Šifra"}

		}
	};

	translation["isClassified"] = {
		{
			{"EN", "Classified "},
			{"HR", "Povjerljivost"}

		}
	};

	translation["Title"] = {
		{
			{"EN", "Add a purpose.. "},
			{"HR", "Dodajte svrhu putovanja..."}

		}
	};

	translation["purposeNameBox"] = {
		{
			{"EN", "name "},
			{"HR", "naziv"}

		}
	};

	translation["purposeDescBox"] = {
		{
			{"EN", "Description "},
			{"HR", "Opis"}

		}
	};

	translation["Form11"] = {
		{
			{"EN", "Purpose information "},
			{"HR", "Podaci o razlogu putovanja"}

		}
	};
}
//---------------------------------------------------------------------------
void __fastcall TForm11::SubmitButtonClick(TObject *Sender)
{
	wcsncpy(DataModule1->purposesHelper.currentPurpose.name, purposeNameBox->Text.c_str(), 50);
	wcsncpy(DataModule1->purposesHelper.currentPurpose.description, purposeDescBox->Text.c_str(), 200);
	DataModule1->purposesHelper.currentPurpose.code = purposeCodeBox->Text.ToInt();
	DataModule1->purposesHelper.currentPurpose.classified = isClassified->Checked;
    DataModule1->purposesHelper.SaveToFile();


}
//---------------------------------------------------------------------------
