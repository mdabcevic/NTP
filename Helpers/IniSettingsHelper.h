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
	TIniFile *ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	//UnicodeString path;
	//UnicodeString sectionName;

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
