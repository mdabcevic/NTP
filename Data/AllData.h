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
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Dialogs.hpp>
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
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule1(TComponent* Owner);
	ThemeHelper themeHelper;
	FontHelper fontHelper;
	WRSettingsHelper wrSettingsHelper;
	_di_IXMLcompanycarsType companycars = Getcompanycars(XmlDoc);
    _di_IXMLcarType currentCar;
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
