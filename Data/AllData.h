//---------------------------------------------------------------------------

#ifndef AllDataH
#define AllDataH

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxExportBaseDialog.hpp"
#include "frxExportPDF.hpp"
#include "frxExportRTF.hpp"
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Codec.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Signatory.hpp"
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>
#include <REST.Authenticator.Basic.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Dialogs.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <map>
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
#include "User.h"
#include "uTPLb_Signatory.hpp"
#include "uTPLb_Codec.hpp"
#include <System.SysUtils.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <REST.Authenticator.Basic.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>

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
	TCryptographicLibrary *AsymCryptLib;
	TADOQuery *MultiQuery;
	TSignatory *AsymSign;
	TCodec *AsymCodec;
	TCodec *SymCodec;
	THTTPBasicAuthenticator *HTTPBaseAuth;
	TRESTClient *RClient;
	TRESTRequest *RRequest;
	TRESTResponse *RResponse;
	TAutoIncField *EmployeeQueryEmployeeID;
	TWideStringField *EmployeeQueryFirstName;
	TWideStringField *EmployeeQueryLastName;
	TWideStringField *EmployeeQueryIdentificationNumber;
	TIntegerField *EmployeeQueryDepartmentCode;
	TIntegerField *EmployeeQueryJobID;
	TWideStringField *EmployeeQueryEducation;
	TBooleanField *EmployeeQueryDriverLicense;
	TWideStringField *EmployeeQueryAddress;
	TWideStringField *EmployeeQueryDepositAccountNumber;
	TIntegerField *EmployeeQueryTenure;
	TWideStringField *EmployeeQueryUsername;
	TWideStringField *EmployeeQueryPassword;
	TWideStringField *EmployeeQueryEmail;
	TWideStringField *EmployeeQueryPhone;
	TStringField *EmployeeQueryEmployeeDepartment;
	TDataSource *EmployeeTableDS;
	TADOQuery *ChartingQuery;
	TDataSource *ChartingDataSource;
	TIntegerField *ChartingQueryTotalWarrants;
	TIntegerField *ChartingQueryYear;
	TIntegerField *ChartingQueryInternationalTravels;
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

	//TCP requests
	void AddToXmlRequest();
    void EditXMLRequest(int index);
	void RequestXMLFile();

	//UDP requests
	void DeleteFromXml(int index);
	void SendJSON();

	//HASH and encryption
	UnicodeString GeneratePassword(UnicodeString username, UnicodeString password);

	//current user
    User currentUser;

	//App login - checks against DB
	void Registration(UnicodeString username, UnicodeString password, UnicodeString email);
	bool Login(UnicodeString username, UnicodeString password);

	//REST requests
	int Authentification();
	void CheckAuthentication();
	void CheckForAnnouncement();
    void MakeAnnouncement(String message);

	//Encryption
	std::unique_ptr<TMemoryStream> privateStream;
	std::unique_ptr<TMemoryStream> publicStream;
    UnicodeString SymKey;
	void GenerateAsymKeys();
	void SendPublicKey();
	void RequestSymKey();
	void DecryptAsym();
	//void SymEncryptFile();

	void translateForm(TForm* Form, String Language, const std::map<String, std::map<String, String>>& translation);

	//another process
	int StartProcess();

	//charting queries
	UnicodeString EmployeeTotal =
	"SELECT YEAR(Departure) AS Year, COUNT(*) AS TotalWarrants, SUM(CASE WHEN IsInternational = 1 THEN 1 ELSE 0 END) AS InternationalTravels "
	"FROM TravelWarrants "
	"WHERE EmployeeID = :id "
	"GROUP BY YEAR(Departure) ";


};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
