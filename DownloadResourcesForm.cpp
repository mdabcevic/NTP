//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DownloadResourcesForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm13 *Form13;
//---------------------------------------------------------------------------
__fastcall TForm13::TForm13(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm13::DownloadClick(TObject *Sender)
{
	TFileStream* fs = new TFileStream("cars.json", fmCreate);
	HTTP->Get(Link->Text, fs);

	delete fs;
}
//---------------------------------------------------------------------------
void __fastcall TForm13::HTTPWorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax)

{
	ProgressBar1->Position = 0;
	ProgressBar1->Max = AWorkCountMax;

}
//---------------------------------------------------------------------------
void __fastcall TForm13::HTTPWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount)

{
	ProgressBar1->Position = AWorkCount;
	Application->ProcessMessages();

}
//---------------------------------------------------------------------------

void __fastcall TForm13::RadioButton1Click(TObject *Sender)
{
    if (speed5->Checked) {
		Throttler->BitsPerSec = 40960;
		return;
	}
	else if(speed10->Checked){
		Throttler->BitsPerSec = 81920;
		return;
	}
	else if(speed20->Checked){
		Throttler->BitsPerSec = 163840;
		return;
	}
	else if(speed30->Checked){
		Throttler->BitsPerSec = 245760;

		return;
}
}

//---------------------------------------------------------------------------
