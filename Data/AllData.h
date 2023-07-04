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
	void __fastcall WarrantsQueryCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule1(TComponent* Owner);

	ThemeHelper themeHelper;
	FontHelper fontHelper;
	WRSettingsHelper wrSettingsHelper;

	_di_IXMLcompanycarsType companycars = Getcompanycars(XmlDoc);
	_di_IXMLcarType currentCar;

	JSONHelper jsonHelper;
	CustomPurposesHelper purposesHelper;

	//ClientRequests
	void AddToXmlRequest();
	void RequestXMLFile();
    void AddToJsonRequest();




};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
