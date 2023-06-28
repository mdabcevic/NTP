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

void FontHelper::ResetToDefault()
{
	// Implementation of resetToDefault function
	LoadSection("DEFAULT FONT");
    SaveCurrent();

}

void FontHelper::LoadSection(UnicodeString name)
{
	// Implementation of LoadSection function
	fontName = ini->ReadString(name, "fontName", "Segoe UI");
	textHeight = ini->ReadInteger(name, "textHeight", 9);
}

void FontHelper::SaveCurrent()
{
	// Implementation of EditSection function
	ini->WriteString("CURRENT FONT", "fontName", fontName);
	ini->WriteInteger("CURRENT FONT", "textHeight", textHeight);
}
