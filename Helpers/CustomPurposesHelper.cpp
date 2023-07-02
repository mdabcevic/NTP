//---------------------------------------------------------------------------

#pragma hdrstop

#include "CustomPurposesHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
CustomPurposesHelper::CustomPurposesHelper(){
	 purposeStream.reset(new TFileStream("purposes.ctp", fmCreate));
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
	//save header
	purposeStream->Write(&Header, sizeof(TravelPurposes));
	for(int i; i < allPurposes.size(); i++){
		//save current purpose
		purposeStream->Write(&allPurposes[i], sizeof(Purpose));
	}

}
