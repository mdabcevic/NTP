//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ServerForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Codec"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Signatory"
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

	CriticalSection->Enter();
	// Read data about car
	String licensePlate = AContext->Connection->IOHandler->ReadLn();
	String internalMark = AContext->Connection->IOHandler->ReadLn();
	String assigned = AContext->Connection->IOHandler->ReadLn();
	String currentUser = AContext->Connection->IOHandler->ReadLn();
	String location = AContext->Connection->IOHandler->ReadLn();

	//crit section should start here I think
	XmlDoc->FileName = "companycars.xml";
	XmlDoc->Active = true;
	_di_IXMLcompanycarsType companycars = Getcompanycars(XmlDoc);
	companycars = Getcompanycars(XmlDoc);
	_di_IXMLcarType currentCar = companycars->Add();
	currentCar->licenseplate = licensePlate;
	currentCar->internalmark = internalMark;
	currentCar->assigned = assigned;
	currentCar->currentuser = currentUser;
	currentCar->location = location;
	XmlDoc->SaveToFile(XmlDoc->FileName);
	XmlDoc->Active = false;
	CriticalSection->Leave();

	//perform action (TO DO: add to xml hosted on server)
	//ShowMessage(licensePlate);

	// return successful signal - same for all actions
	return "done";
}
//---------------------------------------------------------------------------
String TForm1::EditXml(TIdContext *AContext){

	CriticalSection->Enter();
	// Read data about car
	int carindex = AContext->Connection->IOHandler->ReadInt32();
	String licensePlate = AContext->Connection->IOHandler->ReadLn();
	String internalMark = AContext->Connection->IOHandler->ReadLn();
	String assigned = AContext->Connection->IOHandler->ReadLn();
	String currentUser = AContext->Connection->IOHandler->ReadLn();
	String location = AContext->Connection->IOHandler->ReadLn();

	//crit section should start here I think
	XmlDoc->FileName = "companycars.xml";
	XmlDoc->Active = true;
	_di_IXMLcompanycarsType companycars = Getcompanycars(XmlDoc);
	companycars = Getcompanycars(XmlDoc);
	_di_IXMLcarType currentCar = companycars->car[carindex];
	currentCar->licenseplate = licensePlate;
	currentCar->internalmark = internalMark;
	currentCar->assigned = assigned;
	currentCar->currentuser = currentUser;
	currentCar->location = location;
	XmlDoc->SaveToFile(XmlDoc->FileName);
	XmlDoc->Active = false;
	CriticalSection->Leave();

	// return successful signal - same for all actions
	return "done";
}
//---------------------------------------------------------------------------
String TForm1::FindAction(String code, TIdContext *AContext){
	if(code == "AddToXML"){
		AContext->Connection->IOHandler->WriteLn("ok");
		String isCompleted = AddToXml(AContext);
		return isCompleted;
	}
	else if (code == "EditXML") {
		AContext->Connection->IOHandler->WriteLn("ok");
		String isCompleted = EditXml(AContext);
		return isCompleted;
		 }
	else if(code == "RequestXMLFile"){
		AContext->Connection->IOHandler->WriteLn("ok");
		String isCompleted = SendXml(AContext);
		return isCompleted;
	}
	else if(code == "SendPublicKey"){
		AContext->Connection->IOHandler->WriteLn("ok");
		String isCompleted = ReceivePublicKey(AContext);
		return isCompleted;
	}
	else if(code == "RequestSymKey"){
		AContext->Connection->IOHandler->WriteLn("ok");
		String isCompleted = SendSymKey(AContext);
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
 String TForm1::ReceivePublicKey(TIdContext *AContext){
	TMemoryStream *publicKeyStream = new TMemoryStream();
	//receive
	AContext->Connection->IOHandler->ReadStream(publicKeyStream, -1, false);

    publicKeyStream->Position = 0;
	publicKeyStream->SaveToFile("publickey.bin");
	return "done";
 }
 //---------------------------------------------------------------------------
 String TForm1::SendSymKey(TIdContext *AContext){
	std::unique_ptr<TMemoryStream> publickey (new TMemoryStream);
	String result;
	publickey->LoadFromFile("publickey.bin");
	AsymSign->LoadKeysFromStream(publickey.get(), TKeyStoragePartSet() << partPublic);
	AsymCodec->EncryptString(SymKey, result, TEncoding::UTF8);
	//ShowMessage(result);
    //send
	AContext->Connection->IOHandler->WriteLn(result);
	return "done";
 }


//---------------------------------------------------------------------------
void __fastcall TForm1::UDPFileServerUDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
		  TIdSocketHandle *ABinding)
{
	 std::unique_ptr<TMemoryStream> fileStream(new TMemoryStream());
	fileStream->WriteBuffer(&AData[0], AData.Length);
	fileStream->SaveToFile("clients.json.encrypted");

	SymCodec->Password = SymKey;
	std::unique_ptr<TMemoryStream> encrypted (new TMemoryStream);
	encrypted->LoadFromFile("clients.json.encrypted");
	std::unique_ptr<TFileStream> decrypted (new TFileStream("clients.json", fmCreate));
	decrypted->Position = 0;
	SymCodec->DecryptStream(decrypted.get(), encrypted.get());
	//decrypte

	//decrypted->SaveToFile("clients.json");

}
//---------------------------------------------------------------------------


