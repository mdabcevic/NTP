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
	backgroundColour = ini->ReadString(name, "backgroundColour", "clBtnFace");
	textColour = ini->ReadString(name, "fontColour", "clWindowText");
	highlightTextColour = ini->ReadString(name, "highlightColour", "clWindowText");
}

void ThemeHelper::SaveCurrent()
{
	// Implementation of EditSection function
	ini->WriteString("CURRENT THEME", "backgroundColour", backgroundColour);
	ini->WriteString("CURRENT THEME", "fontColour", textColour);
	ini->WriteString("CURRENT THEME", "highlightColour", highlightTextColour);
}
