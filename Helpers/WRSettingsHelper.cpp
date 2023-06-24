//---------------------------------------------------------------------------

#pragma hdrstop

#include "WRSettingsHelper.h"
#include <Registry.hpp> //include for TRegistry
//---------------------------------------------------------------------------
#pragma package(smart_init)

/*
* @brief Class that provides all operations for App settings stored in Windows
Registry.
*
*
*/
 class WRSettingsHelper
{
public:
	TRegistry *registry = new TRegistry;
	UnicodeString key = "Software\\PutniNalozi";
	//UnicodeString sectionName;

	virtual void ResetToDefault();
	virtual void LoadSection(UnicodeString name);
	virtual void SaveCurrent();

	~WRSettingsHelper()
	{
		delete registry;
	}

};
//---------------------------------------------------------------------------
extern PACKAGE WRSettingsHelper *WRSettingsHelper;
//---------------------------------------------------------------------------
