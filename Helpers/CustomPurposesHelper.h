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
    Purpose currentPurpose;
	std::vector<Purpose> allPurposes;
	std::unique_ptr<TFileStream> purposeStreamWrite;
	std::unique_ptr<TMemoryStream> purposeStreamRead;



	CustomPurposesHelper();
	void SaveHardcoded();
    void SaveToFile();
	void ReadFromFile();


};

#endif
