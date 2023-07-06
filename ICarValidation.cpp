// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://localhost/SOAPISAPI.dll/wsdl/ICarValidation
// Version  : 1.0
// (06/07/2023 23:25:56 - - $Rev: 108085 $)
// ************************************************************************ //

#include <System.hpp>
#pragma hdrstop

#include "ICarValidation.h"



namespace NS_ICarValidation {

_di_ICarValidation GetICarValidation(bool useWSDL, System::String addr, Soaphttpclient::THTTPRIO* HTTPRIO)
{
  static const char* defWSDL= "http://localhost/SOAPISAPI.dll/wsdl/ICarValidation";
  static const char* defURL = "http://localhost/SOAPISAPI.dll/soap/ICarValidation";
  static const char* defSvc = "ICarValidationservice";
  static const char* defPrt = "ICarValidationPort";
  if (addr=="")
    addr = useWSDL ? defWSDL : defURL;
  Soaphttpclient::THTTPRIO* rio = HTTPRIO ? HTTPRIO : new Soaphttpclient::THTTPRIO(0);
  if (useWSDL) {
    rio->WSDLLocation = addr;
    rio->Service = defSvc;
    rio->Port = defPrt;
  } else {
    rio->URL = addr;
  }
  _di_ICarValidation service;
  rio->QueryInterface(service);
  if (!service && !HTTPRIO)
    delete rio;
  return service;
}


// ************************************************************************ //
// This routine registers the interfaces and types exposed by the WebService.
// ************************************************************************ //
static void RegTypes()
{
  /* ICarValidation */
  InvRegistry()->RegisterInterface(__delphirtti(ICarValidation), L"urn:CarValidation-ICarValidation", L"");
  InvRegistry()->RegisterDefaultSOAPAction(__delphirtti(ICarValidation), L"urn:CarValidation-ICarValidation#%operationName%");
  /* ICarValidation->validateLicensePlate */
  InvRegistry()->RegisterParamInfo(__delphirtti(ICarValidation), "validateLicensePlate", "return_", L"return", L"");
  /* ICarValidation->isValidCityCode */
  InvRegistry()->RegisterParamInfo(__delphirtti(ICarValidation), "isValidCityCode", "return_", L"return", L"");
}
#pragma startup RegTypes 32

};     // NS_ICarValidation

