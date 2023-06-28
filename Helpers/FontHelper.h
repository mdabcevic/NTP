//---------------------------------------------------------------------------

#ifndef FontHelperH
#define FontHelperH
#include <System.hpp> // Include for UnicodeString
#include <Registry.hpp> //Include for TIniFile
#include "IniSettingsHelper.h"
//---------------------------------------------------------------------------


/*
* @brief Class that provides all operations for Font settings saved in INI
files.
*
*
*/
class FontHelper : public IniSettingsHelper
{
public:
	UnicodeString fontName;
	int textHeight;
	//UnicodeString highlightTextColour;

	FontHelper();
	void ResetToDefault();
	void LoadSection(UnicodeString name);
	void SaveCurrent();
};

//---------------------------------------------------------------------------
extern PACKAGE FontHelper *fontHelper;
//---------------------------------------------------------------------------
#endif
