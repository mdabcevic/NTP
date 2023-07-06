// ************************************************************************ //
// Implementation class for interface ICarValidation
// ************************************************************************ //
#include <stdio.h>
#include <vcl.h>
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
  SampleEnum     echoEnum(SampleEnum eValue);
  TDoubleArray   echoDoubleArray(const TDoubleArray daValue);
  TSampleStruct* echoStruct(const TSampleStruct* pStruct);
  double         echoDouble(double dValue);

  /* IUnknown */
  HRESULT STDMETHODCALLTYPE QueryInterface(const GUID& IID, void **Obj)
                        { return GetInterface(IID, Obj) ? S_OK : E_NOINTERFACE; }
  ULONG STDMETHODCALLTYPE AddRef() { return TInvokableClass::_AddRef();  }
  ULONG STDMETHODCALLTYPE Release() { return TInvokableClass::_Release();  }
};


SampleEnum TCarValidationImpl::echoEnum(SampleEnum eValue)
{
  /* TODO : Implement method echoEnum */
  return eValue;
}

TDoubleArray TCarValidationImpl::echoDoubleArray(TDoubleArray daValue)
{
  /* TODO : Implement method echoDoubleArray */
  return daValue;
}

TSampleStruct* TCarValidationImpl::echoStruct(const TSampleStruct* pEmployee)
{
  /* TODO : Implement method echoMyEmployee */
  return new TSampleStruct();
}

double TCarValidationImpl::echoDouble(const double dValue)
{
  /* TODO : Implement method echoDouble */
  return dValue;
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

