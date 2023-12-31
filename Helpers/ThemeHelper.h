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
	//properties
	TColor backgroundColour;
	TColor textColour;

    //methods
	ThemeHelper();
	void ResetToDefault();
	void LoadSection(UnicodeString name);
	void SaveCurrent();
	TColor StringToRGBColor(const UnicodeString& hex);
    UnicodeString TColorToRGBString(TColor color);
};

//---------------------------------------------------------------------------
extern PACKAGE ThemeHelper* themeHelper;
//---------------------------------------------------------------------------
#endif
