//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DepartmentsForm.h"
#include "Data\AllData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
		translation["Title"] = {
		{
			{"EN", "Departments "},
			{"HR", "Odjeli"}

		}
	};

	translation["Form5"] = {
		{
			{"EN", "Information about departments "},
			{"HR", "Podaci o odjelima"}

		}
	};
}
//---------------------------------------------------------------------------
