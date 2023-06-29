//---------------------------------------------------------------------------

#ifndef IniSettingsHelperH
#define IniSettingsHelperH
#include <System.hpp> // Include for UnicodeString
#include <Registry.hpp> //Include for TIniFile
//---------------------------------------------------------------------------
/*
* @brief Class that provides all that is necessary for operating INI settings.
*
*
*/
 class IniSettingsHelper
{
public:
	//properties
	TIniFile *ini = new TIniFile(GetCurrentDir() + "\\settings.ini");

    //methods
	virtual void ResetToDefault() {}
	virtual void LoadSection(UnicodeString name) {}
	virtual void SaveCurrent() {}

    virtual ~IniSettingsHelper()
	{
		delete ini;
	}

};
//---------------------------------------------------------------------------
extern PACKAGE IniSettingsHelper *iniSettingsHelper;
//---------------------------------------------------------------------------
#endif
