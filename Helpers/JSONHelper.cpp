//---------------------------------------------------------------------------

#pragma hdrstop

#include "JSONHelper.h"
#include <System.JSON.hpp>
#include <System.Classes.hpp> //for unidentified TStringStream
#include <memory>


//---------------------------------------------------------------------------
#pragma package(smart_init)

JSONHelper::JSONHelper(){
    LoadClients();
}
//---------------------------------------------------------------------------
void JSONHelper::LoadClients(){


	// load file into memory
	std::unique_ptr<TStringStream> jsonStream(new TStringStream);
	jsonStream->LoadFromFile("clients.json");

	//parse file
	TJSONObject* jsonFile = (TJSONObject*)TJSONObject::ParseJSONValue(jsonStream->DataString);

	//parse array
	TJSONArray* clientsArray = (TJSONArray*)TJSONObject::ParseJSONValue(jsonFile->GetValue("clients")->ToString());
		for(int i = 0; i<clientsArray->Count; i++){
		//avoid sharing same address space for all clients
		//currentClient = new Client();
		currentClient.CompanyName = clientsArray->Items[i]->GetValue<UnicodeString>("CompanyName");
		currentClient.Address = clientsArray->Items[i]->GetValue<UnicodeString>("Address");
		currentClient.IdentificationNumber = clientsArray->Items[i]->GetValue<UnicodeString>("IdentificationNumber");
		currentClient.Email = clientsArray->Items[i]->GetValue<UnicodeString>("Email");
		currentClient.ContactPerson = clientsArray->Items[i]->GetValue<UnicodeString>("ContactPerson");
		allClients.push_back(currentClient);
	}
}
//---------------------------------------------------------------------------
void JSONHelper::AddClient(){
	allClients.push_back(currentClient);
	//currentClient = new Client();
    RewriteFile();
}
//---------------------------------------------------------------------------
void JSONHelper::RewriteFile(){
    String jsonDoc;
	jsonDoc = "{";
		jsonDoc += "\"clients\":";
		jsonDoc += "[";
		// add existing contacts...
		for(int i = 0; i < allClients.size(); i++){
			jsonDoc +=
			"{"
				"\"CompanyName\":\"" + allClients[i].CompanyName + "\"," +
				"\"Address\":\"" + allClients[i].Address + "\"," +
				"\"IdentificationNumber\":\"" + allClients[i].IdentificationNumber + "\"," +
				"\"Email\":\"" + allClients[i].Email + "\"," +
				"\"ContactPerson\":\"" + allClients[i].ContactPerson + "\"" +
			"}";
			jsonDoc += (i+1 != allClients.size()) ? "," : "";
		}
		jsonDoc += "]";
	jsonDoc += "}";

	//Application->MessageBoxW(jsonDoc.w_str(), L"", 0);
	// format json document (line breaks, indents..)
	jsonDoc = ((TJSONObject*)TJSONObject::ParseJSONValue(jsonDoc))->Format(2);

	std::unique_ptr<TStringStream> ss(new TStringStream);
	ss->WriteString(jsonDoc);
	ss->SaveToFile("clients.json");
}
//---------------------------------------------------------------------------
void JSONHelper::DeleteClient(int index){
	//delete allClients[index];
	allClients.erase(allClients.begin() + index);
	RewriteFile();
}
//---------------------------------------------------------------------------

