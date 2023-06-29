//---------------------------------------------------------------------------

#pragma hdrstop

#include "WRSettingsHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// Constructor
WRSettingsHelper::WRSettingsHelper()
{
    registry->RootKey = HKEY_CURRENT_USER;
}

// Reads property values from key if it exists
void WRSettingsHelper::LoadSettings()
{
	if(registry->OpenKey(key, false)){
		isRememberMe = registry->ReadBool("isRememberMe");
		// Read other values only if they're expected to be loaded into app
		if (isRememberMe) {
			username = registry->ReadString("username");
			password = registry->ReadString("password");
		}
	}
    registry->CloseKey();
}

// Overwrites settings in key with instance's property values
void WRSettingsHelper::SaveSettings(){
	if(registry->OpenKey(key, true)){
		registry->WriteBool("isRememberMe", isRememberMe);
		//Save other settings only if they're supposed to be saved
		if(isRememberMe){
		//maybe move writing boolean here as well
			registry->WriteString("username", username);
			registry->WriteString("password", password);
		}
		//else set them to "" to overwrite them just in case.
		else{
			//replace this with 'DeleteSettings' and move Opening key into if
			registry->WriteString("username", "");
			registry->WriteString("password", "");
        }
	}
    registry->CloseKey();
}

// Deletes username and password values, and set loading to false
void WRSettingsHelper::DeleteSettings()
{
	if(registry->OpenKey(key, true)){
		registry->WriteBool("isRememberMe", false);
		registry->WriteString("username", "");
		registry->WriteString("password", "");
	}
    registry->CloseKey();
}
