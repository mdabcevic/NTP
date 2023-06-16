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
	ThemeHelper();
	void resetToDefault();
	void LoadSection(UnicodeString name);
	void EditSection(UnicodeString name);
};
