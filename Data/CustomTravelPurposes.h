//---------------------------------------------------------------------------

#ifndef CustomTravelPurposesH
#define CustomTravelPurposesH
//---------------------------------------------------------------------------
#include <cstring> // Needed for wcsncpy

//represents header of my file format
class TravelPurposes {
public:
	wchar_t name[20];
	float version;

	TravelPurposes();

};

//represents data of records stored inside my file format
class Purpose {
public:
	wchar_t name[50], description[200];
	int code;
	bool classified;

	Purpose() = default;
	Purpose(wchar_t* _name, wchar_t* _description, int _code, bool _classified);
};

#endif
