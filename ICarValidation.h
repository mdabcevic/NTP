// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : C:\Users\Maja\Documents\Embarcadero\Studio\Projects\NTP projekt\ICarValidation.xml
// Version  : 1.0
// (06/07/2023 11:00:37 - - $Rev: 108085 $)
// ************************************************************************ //

#ifndef   ICarValidationH
#define   ICarValidationH

#include <System.hpp>
#include <Soap.InvokeRegistry.hpp>
#include <Soap.XSBuiltIns.hpp>
#include <Soap.SOAPHTTPClient.hpp>

#if !defined(SOAP_REMOTABLE_CLASS)
#define SOAP_REMOTABLE_CLASS __declspec(delphiclass)
#endif

namespace NS_ICarValidation {

// ************************************************************************ //
// The following types, referred to in the WSDL document are not being represented
// in this file. They are either aliases[@] of other types represented or were referred
// to but never[!] declared in the document. The types from the latter category
// typically map to predefined/known XML or Embarcadero types; however, they could also 
// indicate incorrect WSDL documents that failed to declare or import a schema type.
// ************************************************************************ //
// !:string          - "http://www.w3.org/2001/XMLSchema"[]
// !:boolean         - "http://www.w3.org/2001/XMLSchema"[]


// ************************************************************************ //
// Namespace : urn:CarValidation-ICarValidation
// soapAction: urn:CarValidation-ICarValidation#%operationName%
// transport : http://schemas.xmlsoap.org/soap/http
// style     : rpc
// use       : encoded
// binding   : ICarValidationbinding
// service   : ICarValidationservice
// port      : ICarValidationPort
// URL       : http://localhost:8080/soap/ICarValidation
// ************************************************************************ //
__interface INTERFACE_UUID("{75CC4ACF-7120-1868-D8B3-AF6607EA8031}") ICarValidation : public IInvokable
{
public:
  virtual bool            validateLicensePlate(const UnicodeString plate) = 0; 
  virtual bool            isValidCityCode(const UnicodeString plate) = 0; 
};
typedef DelphiInterface<ICarValidation> _di_ICarValidation;

_di_ICarValidation GetICarValidation(bool useWSDL=false, System::String addr= System::String(), Soaphttpclient::THTTPRIO* HTTPRIO=0);


};     // NS_ICarValidation

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace NS_ICarValidation;
#endif



#endif // ICarValidationH
