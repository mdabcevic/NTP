//---------------------------------------------------------------------------

#ifndef AllDataH
#define AllDataH

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "FontHelper.h"
#include "IniSettingsHelper.h"
#include "ThemeHelper.h"
#include "WRSettingsHelper.h"
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule1(TComponent* Owner);
	ThemeHelper themeHelper;
	FontHelper fontHelper;
    WRSettingsHelper wrSettingsHelper;
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
