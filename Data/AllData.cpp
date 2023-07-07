//---------------------------------------------------------------------------


#pragma hdrstop

#include "AllData.h"
#include "Client.h"
#include <memory>
#include <System.Hash.hpp>
#include <idhashmessagedigest.hpp>
#include <idhashsha.hpp>
#include <System.NetEncoding.hpp>
#include <System.StrUtils.hpp>
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportBaseDialog"
#pragma link "frxExportPDF"
#pragma link "frxExportRTF"
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Codec"
#pragma link "uTPLb_Hash"
#pragma link "uTPLb_Signatory"
#pragma link "uTPLb_Signatory"
#pragma link "uTPLb_Codec"
#pragma resource "*.dfm"

TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
__fastcall TDataModule1::TDataModule1(TComponent* Owner)
	: TDataModule(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TDataModule1::WarrantsQueryCalcFields(TDataSet *DataSet)
{
	//Sleep(1000);  // Delay for 1 second

	int start = DataSet->FieldByName("StartingOdometer")->AsInteger;
	int end = DataSet->FieldByName("EndingOdometer")->AsInteger;
	DataSet->FieldByName("Mileage")->AsInteger = end - start;

}
//---------------------------------------------------------------------------

void TDataModule1::AddToXmlRequest(){
	DataModule1->TCPClient->Connect();
	XmlDoc->Active = false;
	// send request code - needed for server to figure out which action to perform
	DataModule1->TCPClient->IOHandler->WriteLn("AddToXML");

	// wait for server to find that action
	String response = DataModule1->TCPClient->IOHandler->ReadLn();

	// if it's found, send specific data for action
	if (response == "ok"){
		DataModule1->TCPClient->IOHandler->WriteLn(DataModule1->currentCar->licenseplate);
		DataModule1->TCPClient->IOHandler->WriteLn(DataModule1->currentCar->internalmark);
		DataModule1->TCPClient->IOHandler->WriteLn(DataModule1->currentCar->assigned);
		DataModule1->TCPClient->IOHandler->WriteLn(DataModule1->currentCar->currentuser);
		DataModule1->TCPClient->IOHandler->WriteLn(DataModule1->currentCar->location);

		// wait for server to confirm successful action
		response = DataModule1->TCPClient->IOHandler->ReadLn();
		if(response != "done")
		{
			// TODO: Handle server not confirming end of operation
		}
	}
	else
	{
		// TODO: Handle server not responding with 'ok'
	}
	// Disconnect from the server
	XmlDoc->Active = true;
   DataModule1->TCPClient->Disconnect();

}
//---------------------------------------------------------------------------
void TDataModule1::RequestXMLFile(){
	TCPClient->Connect();
	XmlDoc->Active = false;
	// send request code - needed for server to figure out which action to perform
	DataModule1->TCPClient->IOHandler->WriteLn("RequestXMLFile");

	// wait for server to find that action
	String response = DataModule1->TCPClient->IOHandler->ReadLn();

	// if it's found, send specific data for action
	if (response == "ok"){
		UnicodeString filename = TCPClient->IOHandler->ReadLn();
		int filesize =  TCPClient->IOHandler->ReadInt64();              //9.2GB max
		std::unique_ptr <TFileStream> fs(new TFileStream(filename, fmCreate));
		TCPClient->IOHandler->ReadStream(fs.get(), filesize);


		// wait for server to confirm successful action
		if(TCPClient->IOHandler->ReadLn() != "done"){
			// TODO: Handle server not confirming end of operation
		}

	}
	else
	{
		// TODO: Handle server not responding with 'ok'
	}
    XmlDoc->Active = true;
	// Disconnect from the server
   TCPClient->Disconnect();
   //ShowMessage("All OK");
}
//---------------------------------------------------------------------------
void TDataModule1::DeleteFromXml(int index){
	UDPClient->Port = 16138;
	UDPClient->SendBuffer(RawToBytes(&index, sizeof(index)));
	RequestXMLFile();
}
//---------------------------------------------------------------------------

UnicodeString TDataModule1::GeneratePassword(UnicodeString username, UnicodeString password){
	TIdHashMessageDigest5* md5 = new TIdHashMessageDigest5;
	UnicodeString first = md5->HashStringAsHex(password);
	TIdHashSHA1* sha1 = new TIdHashSHA1;
    // dynamic salt + static salt + dynamic salt
	UnicodeString final = sha1->HashStringAsHex(first + "somesupersuperlenghtystaticsalt" + username);
	delete md5;
	delete sha1;
	return final;
}
//---------------------------------------------------------------------------
void TDataModule1::Registration(UnicodeString username, UnicodeString password, UnicodeString email){
	UnicodeString hashedpw = GeneratePassword(username, password);
	EmployeeTable->Append();
	EmployeeTable->FieldByName("Username")->AsString = username;
	EmployeeTable->FieldByName("Password")->AsString = hashedpw;
	EmployeeTable->Post();
}
//---------------------------------------------------------------------------
void TDataModule1::Login(UnicodeString username, UnicodeString password){
	//get pw
	UnicodeString hashedpw = GeneratePassword(username, password);
	//handle check
	MultiQuery->SQL->Clear(); // Clear previous query
	//TO DO: upgrade query for joined search in order to get more info? Namely deparment name
	MultiQuery->SQL->Add("SELECT * FROM Employees WHERE Username = :username AND Password = :password");
	MultiQuery->Parameters->ParamByName("Username")->Value = username;
	MultiQuery->Parameters->ParamByName("Password")->Value = hashedpw;
    MultiQuery->Open();
	//get user info
	currentUser.Username = MultiQuery->FieldByName("Username")->AsString;
	//TO DO: handle password? what about other info?
	currentUser.Password = MultiQuery->FieldByName("Password")->AsString;
    currentUser.ID = MultiQuery->FieldByName("EmployeeID")->AsInteger;
	MultiQuery->SQL->Clear(); // clear it for next query just in case
}

 //---------------------------------------------------------------------------
 int TDataModule1::Authentification(){
	//just in case
	HTTP = new TIdHTTP(NULL);
	UnicodeString auth = "Basic " + TNetEncoding::Base64->Encode(currentUser.Username + ":" + currentUser.Password);
	UnicodeString url = "http://localhost:8085/auth";
	HTTP->Request->CustomHeaders->Values["Authorization"] = auth;
	currentUser.AuthToken  = HTTP->Get(url);

    //just in case again
	HTTP = new TIdHTTP(NULL);

 }
  //---------------------------------------------------------------------------
  void TDataModule1::GenerateAsymKeys(){


	AsymSign->GenerateKeys();

	privateStream.reset(new TMemoryStream());
	publicStream.reset(new TMemoryStream());
	AsymSign->StoreKeysToStream(privateStream.get(), TKeyStoragePartSet() << partPrivate);
	AsymSign->StoreKeysToStream(publicStream.get(), TKeyStoragePartSet() << partPublic);

	privateStream->Position = 0;
	publicStream->Position = 0;

	std::unique_ptr<TIdMultiPartFormDataStream> Stream(new TIdMultiPartFormDataStream());
	UnicodeString publicKeyFile = "asympublic.bin";
	publicStream->SaveToFile(publicKeyFile);

	UnicodeString privateKeyFile = "asymprivate.bin";
    privateStream->SaveToFile(privateKeyFile);
  }
  //---------------------------------------------------------------------------
void TDataModule1::SendPublicKey(){
	TCPClient->Connect();
	TCPClient->IOHandler->WriteLn("SendPublicKey");
	//expecting 'ok'
	String response = TCPClient->IOHandler->ReadLn();

	std::unique_ptr<TMemoryStream> publicKeyStream(new TMemoryStream());
	AsymSign->StoreKeysToStream(publicKeyStream.get(), TKeyStoragePartSet() << partPublic);
	publicKeyStream->Position = 0;
	TCPClient->IOHandler->Write(publicKeyStream.get(), 0, true);

	//expecting 'done'
	TCPClient->IOHandler->ReadLn();
	TCPClient->Disconnect();
	RequestSymKey();

}
  //---------------------------------------------------------------------------
  void TDataModule1::RequestSymKey(){
	TCPClient->Connect();
	TCPClient->IOHandler->WriteLn("RequestSymKey");
	//ok
	String response = TCPClient->IOHandler->ReadLn();

	SymKey = TCPClient->IOHandler->ReadLn();

	//done
	TCPClient->IOHandler->ReadLn();
	TCPClient->Disconnect();
	if (SymKey.Length() > 0) {
		DecryptAsym();
	}
  }
  //---------------------------------------------------------------------------
  void TDataModule1::DecryptAsym(){
	String key;
	std::unique_ptr<TMemoryStream> privatekey (new TMemoryStream);
	privatekey->LoadFromFile("asymprivate.bin");
	AsymSign->LoadKeysFromStream(privatekey.get(), TKeyStoragePartSet() << partPrivate);
	AsymCodec->DecryptString(key, SymKey, TEncoding::UTF8);
	SymKey = key;
  }
  //---------------------------------------------------------------------------
  void TDataModule1::SendJSON(){

	//encrypt - extract to another method?
	SymCodec->Password = SymKey;
	std::unique_ptr<TMemoryStream> original (new TMemoryStream);
	original->LoadFromFile("clients.json");
	std::unique_ptr<TFileStream> encrypted (new TFileStream("clients.json.encrypted", fmCreate));
    SymCodec->EncryptStream(original.get(), encrypted.get());
	encrypted.reset();
    //original.reset();

	UDPClient->Port = 16686;
	TMemoryStream* fileStream = new TMemoryStream();
	fileStream->LoadFromFile("clients.json.encrypted");
	fileStream->Position = 0;
	int size = fileStream->Size;
	TIdBytes buffer;
	buffer.Length = size;
	fileStream->ReadBuffer(&buffer[0], size);
    UDPClient->SendBuffer(buffer);
  }
  //---------------------------------------------------------------------------
  void TDataModule1::CheckAuthentication(){
	HTTPBaseAuth->Username = currentUser.Username;
	HTTPBaseAuth->Password = currentUser.Password;
    RClient->Authenticator = HTTPBaseAuth;
  }

  //---------------------------------------------------------------------------

 void TDataModule1::CheckForAnnouncement(){
	RRequest->Method = rmGET;
    RRequest->Params->Clear();

    RRequest->Execute();

	ShowMessage(" Latest announcement: " + RResponse->Content);
 }

 //---------------------------------------------------------------------------

 void TDataModule1::MakeAnnouncement(String message){
    RRequest->Method = rmPOST;
    RRequest->Params->Clear();

    RRequest->Params->AddItem()->Name = "message";
    RRequest->Params->Items[0]->Value = message;

    RRequest->Execute();
    if (RResponse->StatusCode == 200) {
        ShowMessage("Message posted successfully!");
    } else {
        ShowMessage("Failed to post message: " + RResponse->Content);
	}
 }
