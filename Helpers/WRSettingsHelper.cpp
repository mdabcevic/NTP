//---------------------------------------------------------------------------

#pragma hdrstop

#include "WRSettingsHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


WRSettingsHelper::WRSettingsHelper()
{
	// Constructor implementation
    registry->RootKey = HKEY_CURRENT_USER;
}

void WRSettingsHelper::LoadSettings()
{
	if(registry->OpenKey(key, false)){
		isRememberMe = registry->ReadBool("isRememberMe");
		if (isRememberMe) {
			username = registry->ReadString("username");
			password = registry->ReadString("password");
		}
	}
    registry->CloseKey();
}

void WRSettingsHelper::SaveSettings(){
	if(registry->OpenKey(key, true)){
		registry->WriteBool("isRememberMe", isRememberMe);
		if(isRememberMe){
			registry->WriteString("username", username);
			registry->WriteString("password", password);
		}
	}
    registry->CloseKey();
}

void WRSettingsHelper::DeleteSettings()
{
	if(registry->OpenKey(key, true)){
		registry->WriteBool("isRememberMe", false);
		registry->WriteString("username", "");
		registry->WriteString("password", "");
	}
    registry->CloseKey();
}
