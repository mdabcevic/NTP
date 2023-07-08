//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "LoadIconsThread.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall LoadIcons::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall LoadIcons::LoadIcons(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall LoadIcons::Execute()
{
	//---- Place thread code here ----
	loader = new TMemoryStream();
	DataModule1->HTTP->Get(DataModule1->service->CountryFlag("HR"), loader);
	loader->Position = 0;

	Synchronize(LoadHRFlag);

	loader = new TMemoryStream();
	DataModule1->HTTP->Get(DataModule1->service->CountryFlag("GB"), loader);
	loader->Position = 0;

	Synchronize(LoadENFlag);
	delete loader;

}
//---------------------------------------------------------------------------
void __fastcall LoadIcons::LoadHRFlag()
{
	Form1->ImgHr->Picture->LoadFromStream(loader);
}
//---------------------------------------------------------------------------
void __fastcall LoadIcons::LoadENFlag()
{
	Form1->ImgEn->Picture->LoadFromStream(loader);
}
