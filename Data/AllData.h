//---------------------------------------------------------------------------

#ifndef AllDataH
#define AllDataH

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "FontHelper.h"
#include "IniSettingsHelper.h"
#include "ThemeHelper.h"
#include "WRSettingsHelper.h"
#include "Helpers/companycars.h"  //include for handling companycars.xml
#include "JSONHelper.h"
//#include "ICarValidation.h"
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Dialogs.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "Helpers/CustomPurposesHelper.h"
#include "frxExportBaseDialog.hpp"
#include "frxExportPDF.hpp"
#include "frxExportRTF.hpp"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>
#include <IdHTTP.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Hash.hpp"

//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
	TXMLDocument *XmlDoc;
	TADOConnection *Connection;
	TADOTable *EmployeeTable;
	TDataSource *EmployeeDataSource;
	TADOQuery *EmployeeQuery;
	TADOQuery *DepartmentsQuery;
	TDataSource *DepartmentsDataSource;
	TADOTable *DepartmentsTable;
	TOpenDialog *OpenDialog1;
	TADOQuery *ExpensesQuery;
	TDataSource *ExpensesDataSource;
	TADOQuery *WarrantsQuery;
	TDataSource *WarrantsDataSource;
	TIntegerField *WarrantsQueryMileage;
	TAutoIncField *WarrantsQueryWarrantID;
	TIntegerField *WarrantsQueryEmployeeID;
	TDateTimeField *WarrantsQueryCreatedAt;
	TDateTimeField *WarrantsQueryDeparture;
	TDateTimeField *WarrantsQueryArrival;
	TBooleanField *WarrantsQueryIsInternational;
	TWideStringField *WarrantsQueryPartners;
	TWideStringField *WarrantsQueryPurposes;
	TIntegerField *WarrantsQueryAttachmentID;
	TIntegerField *WarrantsQueryStartingOdometer;
	TIntegerField *WarrantsQueryEndingOdometer;
	TWideStringField *WarrantsQueryToll;
	TWideStringField *WarrantsQueryLicensePlate;
	TWideStringField *WarrantsQueryOtherVehicles;
	TIntegerField *WarrantsQueryAuthorizedBy;
	TfrxReport *EmployeeLayout;
	TfrxDBDataset *frxDBEmployee;
	TADOQuery *JoinedReport;
	TfrxDBDataset *WarrantReport;
	TfrxReport *WarrantLayout;
	TfrxPDFExport *PDFExport;
	TfrxRTFExport *RTFExport;
	TfrxDBDataset *WarrantDetail;
	TADOTable *WarrantsTable;
	TIdTCPClient *TCPClient;
	TIdUDPClient *UDPClient;
	TIdHTTP *HTTP;
	TIdSSLIOHandlerSocketOpenSSL *SSLHandler;
	THash *HashIt;
	TCryptographicLibrary *CryptLib;
	void __fastcall WarrantsQueryCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule1(TComponent* Owner);

	//INI and REG
	ThemeHelper themeHelper;
	FontHelper fontHelper;
	WRSettingsHelper wrSettingsHelper;

	//XML
	_di_IXMLcompanycarsType companycars = Getcompanycars(XmlDoc);
	_di_IXMLcarType currentCar;

	//JSON
	JSONHelper jsonHelper;
	CustomPurposesHelper purposesHelper;

	//SOAP
	_di_CountryInfoServiceSoapType service = GetCountryInfoServiceSoapType();
    _di_ICarValidation carValidation = GetICarValidation();


	//ClientRequests
	void AddToXmlRequest();
	void RequestXMLFile();
	void DeleteFromXml(int index);
	//to do: send client files to the server

	//HASH and encryption
    UnicodeString GeneratePassword(UnicodeString username, UnicodeString password);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
