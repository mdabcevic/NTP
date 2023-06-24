//---------------------------------------------------------------------------

#pragma hdrstop

#include "FontHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

FontHelper::FontHelper()
{
	// Constructor implementation
	LoadSection("CURRENT FONT");
}

void FontHelper::resetToDefault()
{
	// Implementation of resetToDefault function
	LoadSection("DEFAULT FONT");
    SaveCurrent();

}

void FontHelper::LoadSection(UnicodeString name)
{
	// Implementation of LoadSection function
	fontName = ini->ReadString(name, "fontName", "Tahoma");
	textHeight = ini->ReadString(name, "textHeight", "13");
	//highlightTextColour = ini->ReadString(name, "highlightColour", "clWindowText");
}

void FontHelper::SaveCurrent()
{
	// Implementation of EditSection function
	ini->WriteString("CURRENT FONT", "fontName", fontName);
	ini->WriteString("CURRENT FONT", "textHeight", textHeight);
	//ini->WriteString("CURRENT FONT", "highlightColour", highlightTextColour);
}
