//---------------------------------------------------------------------------

#ifndef WRSettingsHelperH
#define WRSettingsHelperH
#include <System.hpp> // Include for UnicodeString
#include <Registry.hpp> //include for TRegistry
//---------------------------------------------------------------------------
/*
* @brief Class that provides all operations for App settings stored in Windows
Registry.
*
*
*/
#ifdef EXPORTS
	#define DLL_EXPORT __declspec(dllexport)
#else
	#define DLL_EXPORT __declspec(dllimport)
#endif

 class DLL_EXPORT WRSettingsHelper
{
public:
	TRegistry *registry = new TRegistry;
	UnicodeString key = "Software\\PutniNalozi";
	bool isRememberMe;
	UnicodeString username;
	//TO DO: remove this, make separate function that returns string and
	//put it directly into box)
    UnicodeString password;

	WRSettingsHelper();
	void DeleteSettings();
	void LoadSettings();
	void SaveSettings();

	~WRSettingsHelper()
	{
		delete registry;
	}

};
//---------------------------------------------------------------------------
extern PACKAGE WRSettingsHelper *wrSettingsHelper;
//---------------------------------------------------------------------------


#endif

