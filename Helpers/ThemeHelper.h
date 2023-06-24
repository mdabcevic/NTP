//---------------------------------------------------------------------------

#ifndef ThemeHelperH
#define ThemeHelperH
#include <System.hpp> // Include for UnicodeString
#include <Registry.hpp> //Include for TIniFile
#include "IniSettingsHelper.h"
//---------------------------------------------------------------------------
#endif

class ThemeHelper : public IniSettingsHelper
{
public:
	UnicodeString backgroundColour;
	UnicodeString textColour;
	UnicodeString highlightTextColour;

	ThemeHelper();
	void ResetToDefault();
	void LoadSection(UnicodeString name);
    void SaveCurrent();
};
