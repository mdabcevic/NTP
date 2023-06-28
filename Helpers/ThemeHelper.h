//---------------------------------------------------------------------------

#ifndef ThemeHelperH
#define ThemeHelperH
#include <System.hpp> // Include for UnicodeString
#include <Registry.hpp> //Include for TIniFile
#include <System.UITypes.hpp> //Include for TColor
#include "IniSettingsHelper.h"
//---------------------------------------------------------------------------


/*
* @brief Class that provides all operations for Theme settings stored in INI
file.
*
*
*/
class ThemeHelper : public IniSettingsHelper
{
public:
	TColor backgroundColour;
	TColor textColour;

	ThemeHelper();
	void ResetToDefault();
	void LoadSection(UnicodeString name);
    void SaveCurrent();
};

//---------------------------------------------------------------------------
extern PACKAGE ThemeHelper* themeHelper;
//---------------------------------------------------------------------------
#endif
