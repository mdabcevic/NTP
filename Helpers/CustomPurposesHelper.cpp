//---------------------------------------------------------------------------

#pragma hdrstop

#include "CustomPurposesHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
CustomPurposesHelper::CustomPurposesHelper(){

	ReadFromFile();

}
//---------------------------------------------------------------------------

void CustomPurposesHelper::SaveHardcoded(){
	allPurposes =
	 {
		 Purpose(L"Promocija proizvoda", L"Upoznati kupce s proizvodima", 1, false),
		 Purpose(L"Potpisivanje ugovora", L"Zakljucivanje ugovora s kupcima", 2, true)
	 };
     SaveToFile();

}
//---------------------------------------------------------------------------
void CustomPurposesHelper::SaveToFile(){
	allPurposes.push_back(currentPurpose);
	purposeStreamWrite.reset(new TFileStream("purposes.ctp", fmCreate));
	//save header
	purposeStreamWrite->Write(&Header, sizeof(TravelPurposes));
	for(int i = 0; i < allPurposes.size(); i++){
		//save current purpose
		purposeStreamWrite->Write(&allPurposes[i], sizeof(Purpose));
	}
	purposeStreamWrite.reset(); // Close the file
    currentPurpose = Purpose();

}
//---------------------------------------------------------------------------
void CustomPurposesHelper::ReadFromFile(){
    allPurposes.clear();
	purposeStreamRead.reset(new TMemoryStream);
	//load
	purposeStreamRead->LoadFromFile("purposes.ctp");
	//get header
	purposeStreamRead->Read(&Header, sizeof(TravelPurposes));
	//header validation
	if(String(Header.name) != "TravelPurposes" || Header.version != 1.0){
		//do something
		return;
	}
	//read records
	int purposesCount = (purposeStreamRead->Size - sizeof(Header)) / sizeof(Purpose);
	for (int i = 0; i < purposesCount; i++) {
		purposeStreamRead->Read(&currentPurpose, sizeof(Purpose));
		allPurposes.push_back(currentPurpose);
	}
	purposeStreamRead.reset();
	currentPurpose = Purpose();
}
