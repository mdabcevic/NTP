//---------------------------------------------------------------------------

#pragma hdrstop

#include "CustomTravelPurposes.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
//represents header of my file format
class TravelPurposes {
public:
	wchar_t name[20];
	float version;

	TravelPurposes() {
		wcsncpy(name, L"TravelPurposes", 20);
		version = 1.0;
	}
};
//---------------------------------------------------------------------------
//represents data of records stored inside my file format
class Purpose {
public:
	wchar_t name[25], description[100];
	int code;
	bool classified;

	Purpose() = default;
    //constructor
	Purpose(wchar_t* _name, wchar_t* _description, int _code, bool _classified) {
		wcsncpy(name, _name, 25);
		wcsncpy(description, _description, 100);
		code = _code;
		classified = _classified;
	}
};