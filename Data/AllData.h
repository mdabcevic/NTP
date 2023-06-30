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
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
	TXMLDocument *XmlDoc;
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule1(TComponent* Owner);
	ThemeHelper themeHelper;
	FontHelper fontHelper;
	WRSettingsHelper wrSettingsHelper;
	_di_IXMLcompanycarsType companycars = Getcompanycars(XmlDoc);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
