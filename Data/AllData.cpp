//---------------------------------------------------------------------------


#pragma hdrstop

#include "AllData.h"
#include "Client.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportBaseDialog"
#pragma link "frxExportPDF"
#pragma link "frxExportRTF"
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

		// wait for server to confirm successfull action
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
   DataModule1->TCPClient->Disconnect();

}
