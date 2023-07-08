//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "PreparationThread.h"
#include "Data\AllData.h"   // for thread to be aware of all methods on DM1
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Preparation::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall Preparation::Preparation(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall Preparation::Execute()
{
    FreeOnTerminate = true;
	//---- Place thread code here ----
	DataModule1->RequestXMLFile();
	DataModule1->GenerateAsymKeys();
	DataModule1->SendPublicKey();
	DataModule1->SendJSON();

}
//---------------------------------------------------------------------------
