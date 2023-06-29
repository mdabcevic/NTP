//---------------------------------------------------------------------------

#pragma hdrstop

#include "FontHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

FontHelper::FontHelper()
{
	// Constructor - always loads CURRENT FONT section first
	// Invoked on starting the app.
	LoadSection("CURRENT FONT");
}

void FontHelper::ResetToDefault()
{
	// Loads the default options and overwrites CURRENT THEME with them.
	LoadSection("DEFAULT FONT");
    SaveCurrent();

}

void FontHelper::LoadSection(UnicodeString name)
{
	// Load properties in ini for given FONT section name into instance
	fontName = ini->ReadString(name, "fontName", "Segoe UI");
	textHeight = ini->ReadInteger(name, "textHeight", 9);
}

void FontHelper::SaveCurrent()
{
	// Saves values from object instance into CURRENT theme properties
	ini->WriteString("CURRENT FONT", "fontName", fontName);
	ini->WriteInteger("CURRENT FONT", "textHeight", textHeight);
}
