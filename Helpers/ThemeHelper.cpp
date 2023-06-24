//---------------------------------------------------------------------------

#pragma hdrstop

#include "ThemeHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ThemeHelper::ThemeHelper()
{
    // Constructor implementation
}

void ThemeHelper::resetToDefault()
{
    // Implementation of resetToDefault function
}

void ThemeHelper::LoadSection(UnicodeString name)
{
	// Implementation of LoadSection function
	backgroundColour = ini->ReadString(name, "backgroundColour", "clBtnFace");
	textColour = ini->ReadString(name, "fontColour", "clWindowText");
	highlightTextColour = ini->ReadString(name, "highlightColour", "clWindowText");
}

void ThemeHelper::EditSection(UnicodeString name)
{
    // Implementation of EditSection function
void ThemeHelper::SaveCurrent()
{
	// Implementation of EditSection function
	ini->WriteString("CURRENT THEME", "backgroundColour", backgroundColour);
	ini->WriteString("CURRENT THEME", "fontColour", textColour);
	ini->WriteString("CURRENT THEME", "highlightColour", highlightTextColour);
}
