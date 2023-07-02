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
	std::unique_ptr<TFileStream> purposeStreamWrite;
	std::unique_ptr<TMemoryStream> purposeStreamRead;
    Purpose currentPurpose;


	CustomPurposesHelper();
	void SaveHardcoded();
    void SaveToFile();
	void ReadFromFile();


};

#endif
