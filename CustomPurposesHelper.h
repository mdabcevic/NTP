//---------------------------------------------------------------------------

#ifndef CustomPurposesHelperH
#define CustomPurposesHelperH
#include "CustomTravelPurposes.h"
#include <vector>
#include <System.Classes.hpp>
//---------------------------------------------------------------------------


class CustomPurposesHelper {
public:
	TravelPurposes Header;
	std::vector<Purpose> allPurposes;
	std::unique_ptr<TFileStream> purposeStream;

	CustomPurposesHelper();
	void SaveHardcoded();
    void SaveToFile();



};

#endif
