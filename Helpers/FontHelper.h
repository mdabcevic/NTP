//---------------------------------------------------------------------------

#ifndef FontHelperH
#define FontHelperH
#include <System.hpp> // Include for UnicodeString
#include <Registry.hpp> //Include for TIniFile
#include "IniSettingsHelper.h"
//---------------------------------------------------------------------------
#endif

class FontHelper : public IniSettingsHelper
{
public:
	UnicodeString fontName;
	UnicodeString textHeight;
	//UnicodeString highlightTextColour;

	FontHelper();
	void ResetToDefault();
	void LoadSection(UnicodeString name);
	void SaveCurrent();
};
