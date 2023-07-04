//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ServerForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TCPServerExecute(TIdContext *AContext)
{
	// identified that all actions send
	String actionCode = AContext->Connection->IOHandler->ReadLn();

    //find and perform action
	String isDone = FindAction(actionCode, AContext);

	// after all specific communication, all requests wait for this confirmation
	AContext->Connection->IOHandler->WriteLn(isDone);


}
//---------------------------------------------------------------------------
String TForm1::AddToXml(TIdContext *AContext){

	// Read data about car
    String licensePlate = AContext->Connection->IOHandler->ReadLn();
    String internalMark = AContext->Connection->IOHandler->ReadLn();
    String assigned = AContext->Connection->IOHandler->ReadLn();
    String currentUser = AContext->Connection->IOHandler->ReadLn();
	String location = AContext->Connection->IOHandler->ReadLn();


	//perform action (TO DO: add to xml hosted on server)
	ShowMessage(licensePlate);

	// return successful signal - same for all actions
	return "done";
}

String TForm1::FindAction(String code, TIdContext *AContext){
	if(code == "AddToXML"){
		AContext->Connection->IOHandler->WriteLn("ok");
		String isCompleted = AddToXml(AContext);
		return isCompleted;
	}
}