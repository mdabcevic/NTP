//---------------------------------------------------------------------------

#pragma hdrstop

#include "CustomTravelPurposes.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------

TravelPurposes::TravelPurposes() {
	wcsncpy(name, L"TravelPurposes", 20);
	version = 1.0;
}
//---------------------------------------------------------------------------

Purpose::Purpose(wchar_t* _name, wchar_t* _description, int _code, bool _classified) {
	wcsncpy(name, _name, 50);
	wcsncpy(description, _description, 200);
	code = _code;
	classified = _classified;
}
