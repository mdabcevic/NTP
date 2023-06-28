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
	ini->WriteString("CURRENT THEME", "backgroundColour", TColorToRGBString(backgroundColour));
	ini->WriteString("CURRENT THEME", "fontColour", TColorToRGBString(textColour));
}

// Convert string representation of RGB color to TColor
TColor ThemeHelper::StringToRGBColor(const UnicodeString& hex){
	UnicodeString str = hex;
    if (str.Pos("#") == 1)
    {
        str = str.SubString(2, str.Length() - 1);
    }
	//str = str.Delete(1,1);
	// Split the RGB string into separate components
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

UnicodeString ThemeHelper::TColorToRGBString(TColor color)
{
    int red = GetRValue(color);
	int green = GetGValue(color);
    int blue = GetBValue(color);

	return Format("#%.2x%.2x%.2x", ARRAYOFCONST((red, green, blue)));
}
