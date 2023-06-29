//---------------------------------------------------------------------------

#pragma hdrstop

#include "ThemeHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// Constructor - loads properties from "CURRENT THEME" section on app start
ThemeHelper::ThemeHelper()
{
	LoadSection("CURRENT THEME");
}

// Overwrites "CURRENT THEME" section properties with ones in "DEFAULT THEME"
void ThemeHelper::ResetToDefault()
{
	LoadSection("DEFAULT THEME");
    SaveCurrent();

}

// Loads properties from ini file for given section name into instance
void ThemeHelper::LoadSection(UnicodeString name)
{
	backgroundColour = StringToRGBColor(ini->ReadString(name, "backgroundColour", "#DAFFFB"));
	textColour = StringToRGBColor(ini->ReadString(name, "fontColour", "#000000"));
}

// Saves values from instance to "CURRENT THEME" section
void ThemeHelper::SaveCurrent()
{
	ini->WriteString("CURRENT THEME", "backgroundColour", TColorToRGBString(backgroundColour));
	ini->WriteString("CURRENT THEME", "fontColour", TColorToRGBString(textColour));
}

// Convert hex representation of color to TColor
TColor ThemeHelper::StringToRGBColor(const UnicodeString& hex){

	//remove leading # symbol if present
	UnicodeString str = hex;
    if (str.Pos("#") == 1)
    {
        str = str.SubString(2, str.Length() - 1);
	}

	// Split hex value to reg, green and blue components
	UnicodeString redStr = str.SubString(1, 2);
	UnicodeString greenStr = str.SubString(3, 2);
	UnicodeString blueStr = str.SubString(5, 2);

    // Convert the components to integers
    int red = StrToInt("0x" + redStr);
    int green = StrToInt("0x" + greenStr);
    int blue = StrToInt("0x" + blueStr);

    // Create the TColor using the RGB values
	return TColor(RGB(red, green, blue));
}

// Convert back from TColor instance into hex value
UnicodeString ThemeHelper::TColorToRGBString(TColor color)
{
    int red = GetRValue(color);
	int green = GetGValue(color);
    int blue = GetBValue(color);

    // Convert multiple int values into string
	return Format("#%.2x%.2x%.2x", ARRAYOFCONST((red, green, blue)));
}
