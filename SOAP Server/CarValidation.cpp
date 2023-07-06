// ************************************************************************ //
// Implementation class for interface ICarValidation
// ************************************************************************ //
#include <stdio.h>
#include <vcl.h>
#include <regex>
#include <unordered_set>
#pragma hdrstop

#if !defined(__CarValidation_h__)
#include "CarValidation.h"
#endif

// ************************************************************************ //
//  TCarValidationImpl implements interface ICarValidation
// ************************************************************************ //
class TCarValidationImpl : public TInvokableClass, public ICarValidation
{
public:
    /* Sample methods of ICarValidation */
  //SampleEnum     echoEnum(SampleEnum eValue);
  //TDoubleArray   echoDoubleArray(const TDoubleArray daValue);
  //TSampleStruct* echoStruct(const TSampleStruct* pStruct);
 // double         echoDouble(double dValue);
	bool         validateLicensePlate(String plate);
    bool         isValidCityCode(String plate);

  /* IUnknown */
  HRESULT STDMETHODCALLTYPE QueryInterface(const GUID& IID, void **Obj)
                        { return GetInterface(IID, Obj) ? S_OK : E_NOINTERFACE; }
  ULONG STDMETHODCALLTYPE AddRef() { return TInvokableClass::_AddRef();  }
  ULONG STDMETHODCALLTYPE Release() { return TInvokableClass::_Release();  }
};



bool TCarValidationImpl::validateLicensePlate(String plate){
	//ruleset: 2letters - 3/4digits - 2letters
    std::regex pattern("^[A-Z]{2}-\\d{3,4}-[A-Z]{2}$");
	std::string licensePlateStr = AnsiString(plate).c_str();
	return std::regex_match(licensePlateStr, pattern);
}

bool TCarValidationImpl::isValidCityCode(String plate){
	TStringList *validCityCodes;
	validCityCodes->CommaText = "BJ,ZG,SB,OS,RI,BM,DA,DU,KR,KT,NG,PU,SK,ST,ZD";
	String extractedCode = plate.SubString(1, 2);
	bool result = validCityCodes->IndexOf(extractedCode) != -1;
	delete validCityCodes;
	return result;
}


static void __fastcall CarValidationFactory(System::TObject* &obj)
{
  static _di_ICarValidation iInstance;
  static TCarValidationImpl *instance = 0;
  if (!instance)
  {
    instance = new TCarValidationImpl();
    instance->GetInterface(iInstance);
  }
  obj = instance;
}

// ************************************************************************ //
//  The following routine registers the interface and implementation class
//  as well as the type used by the methods of the interface
// ************************************************************************ //
static void RegTypes()
{
  InvRegistry()->RegisterInterface(__delphirtti(ICarValidation));
  InvRegistry()->RegisterInvokableClass(__classid(TCarValidationImpl), CarValidationFactory);
}
#pragma startup RegTypes 32

