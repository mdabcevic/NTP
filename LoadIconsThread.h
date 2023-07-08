//---------------------------------------------------------------------------

#ifndef LoadIconsThreadH
#define LoadIconsThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "LoginForm.h"
#include "AllData.h"
//---------------------------------------------------------------------------
class LoadIcons : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall LoadIcons(bool CreateSuspended);

	TMemoryStream *loader;
	void __fastcall LoadHRFlag();
	void __fastcall LoadENFlag();
};
//---------------------------------------------------------------------------
#endif
