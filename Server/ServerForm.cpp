//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ServerForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <windows.h>


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
	else if(code == "RequestXMLFile"){
		AContext->Connection->IOHandler->WriteLn("ok");
		String isCompleted = SendXml(AContext);
		return isCompleted;
	}
}
//---------------------------------------------------------------------------
 String TForm1::SendXml(TIdContext *AContext){

	//critical section - avoids multiple users meddling with file at same time
	CriticalSection->Enter();
	std::unique_ptr<TFileStream> fs(new TFileStream("companycars.xml", fmOpenRead));  //load into memory
	AContext->Connection->IOHandler->WriteLn(ExtractFileName(fs->FileName));          //send name
	AContext->Connection->IOHandler->Write(fs->Size);                                 //send size
	AContext->Connection->IOHandler->Write(fs.get());                                 //send content
    CriticalSection->Leave();
	// return successful signal - same for all actions
	return "done";
 }
 //---------------------------------------------------------------------------
void __fastcall TForm1::UDPServerUDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
		  TIdSocketHandle *ABinding)
{
CriticalSection->Enter();
	int recordToDelete;
	BytesToRaw(AData, &recordToDelete, sizeof(recordToDelete));
	XmlDoc->FileName = "companycars.xml";
	XmlDoc->Active = true;
	_di_IXMLcompanycarsType companycars = Getcompanycars(XmlDoc);
	companycars = Getcompanycars(XmlDoc);
	if (companycars->Count > recordToDelete)
{
	companycars->Delete(recordToDelete);
	XmlDoc->SaveToFile(XmlDoc->FileName);

}
	XmlDoc->Active = false;
	CriticalSection->Leave();
}
//---------------------------------------------------------------------------

