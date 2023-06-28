//---------------------------------------------------------------------------

#pragma hdrstop

#include "ThemeHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ThemeHelper::ThemeHelper()
{
	// Constructor implementation
    LoadSection("CURRENT THEME");
}

void ThemeHelper::ResetToDefault()
{
	// Implementation of resetToDefault function
	LoadSection("DEFAULT THEME");
    SaveCurrent();

}

void ThemeHelper::LoadSection(UnicodeString name)
{
	// Implementation of LoadSection function
	backgroundColour = StringToRGBColor(ini->ReadString(name, "backgroundColour", "#DAFFFB"));
	textColour = StringToRGBColor(ini->ReadString(name, "fontColour", "#000000"));
}

void ThemeHelper::SaveCurrent()
{
	// Implementation of SaveCurrent function
	ini->WriteString("CURRENT THEME", "backgroundColour", backgroundColour);
	ini->WriteString("CURRENT THEME", "fontColour", textColour);
	ini->WriteString("CURRENT THEME", "highlightColour", highlightTextColour);
}
