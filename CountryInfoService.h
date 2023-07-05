// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://webservices.oorsprong.org/websamples.countryinfo/CountryInfoService.wso?WSDL
//  >Import : http://webservices.oorsprong.org/websamples.countryinfo/CountryInfoService.wso?WSDL>0
// Encoding : UTF-8
// Version  : 1.0
// (06/07/2023 00:25:53 - - $Rev: 108085 $)
// ************************************************************************ //

#ifndef   CountryInfoServiceH
#define   CountryInfoServiceH

#include <System.hpp>
#include <Soap.InvokeRegistry.hpp>
#include <Soap.XSBuiltIns.hpp>
#include <Soap.SOAPHTTPClient.hpp>

#if !defined(SOAP_REMOTABLE_CLASS)
#define SOAP_REMOTABLE_CLASS __declspec(delphiclass)
#endif
#if !defined(IS_OPTN)
#define IS_OPTN 0x0001
#endif
#if !defined(IS_UNBD)
#define IS_UNBD 0x0002
#endif
#if !defined(IS_NLBL)
#define IS_NLBL 0x0004
#endif
#if !defined(IS_REF)
#define IS_REF 0x0080
#endif


namespace NS_CountryInfoService {

// ************************************************************************ //
// The following types, referred to in the WSDL document are not being represented
// in this file. They are either aliases[@] of other types represented or were referred
// to but never[!] declared in the document. The types from the latter category
// typically map to predefined/known XML or Embarcadero types; however, they could also 
// indicate incorrect WSDL documents that failed to declare or import a schema type.
// ************************************************************************ //
// !:string          - "http://www.w3.org/2001/XMLSchema"[Gbl]

class SOAP_REMOTABLE_CLASS tCountryCodeAndNameGroupedByContinent;
class SOAP_REMOTABLE_CLASS tContinent;
class SOAP_REMOTABLE_CLASS tCountryCodeAndName;
class SOAP_REMOTABLE_CLASS tCurrency;
class SOAP_REMOTABLE_CLASS tCountryInfo;
class SOAP_REMOTABLE_CLASS tLanguage;

typedef DynamicArray<tCountryCodeAndName*> ArrayOftCountryCodeAndName; /* "http://www.oorsprong.org/websamples.countryinfo"[GblCplx] */


// ************************************************************************ //
// XML       : tCountryCodeAndNameGroupedByContinent, global, <complexType>
// Namespace : http://www.oorsprong.org/websamples.countryinfo
// ************************************************************************ //
class tCountryCodeAndNameGroupedByContinent : public TRemotable {
private:
  tContinent*     FContinent;
  ArrayOftCountryCodeAndName FCountryCodeAndNames;

public:
  __fastcall ~tCountryCodeAndNameGroupedByContinent();
__published:
  __property tContinent*  Continent = { read=FContinent, write=FContinent };
  __property ArrayOftCountryCodeAndName CountryCodeAndNames = { read=FCountryCodeAndNames, write=FCountryCodeAndNames };
};




// ************************************************************************ //
// XML       : tContinent, global, <complexType>
// Namespace : http://www.oorsprong.org/websamples.countryinfo
// ************************************************************************ //
class tContinent : public TRemotable {
private:
  UnicodeString   FsCode;
  UnicodeString   FsName;
__published:
  __property UnicodeString      sCode = { read=FsCode, write=FsCode };
  __property UnicodeString      sName = { read=FsName, write=FsName };
};




// ************************************************************************ //
// XML       : tCountryCodeAndName, global, <complexType>
// Namespace : http://www.oorsprong.org/websamples.countryinfo
// ************************************************************************ //
class tCountryCodeAndName : public TRemotable {
private:
  UnicodeString   FsISOCode;
  UnicodeString   FsName;
__published:
  __property UnicodeString   sISOCode = { read=FsISOCode, write=FsISOCode };
  __property UnicodeString      sName = { read=FsName, write=FsName };
};




// ************************************************************************ //
// XML       : tCurrency, global, <complexType>
// Namespace : http://www.oorsprong.org/websamples.countryinfo
// ************************************************************************ //
class tCurrency : public TRemotable {
private:
  UnicodeString   FsISOCode;
  UnicodeString   FsName;
__published:
  __property UnicodeString   sISOCode = { read=FsISOCode, write=FsISOCode };
  __property UnicodeString      sName = { read=FsName, write=FsName };
};


typedef DynamicArray<tCurrency*>  ArrayOftCurrency; /* "http://www.oorsprong.org/websamples.countryinfo"[GblCplx] */
typedef DynamicArray<tCountryCodeAndNameGroupedByContinent*> ArrayOftCountryCodeAndNameGroupedByContinent; /* "http://www.oorsprong.org/websamples.countryinfo"[GblCplx] */
typedef DynamicArray<tCountryInfo*> ArrayOftCountryInfo; /* "http://www.oorsprong.org/websamples.countryinfo"[GblCplx] */
typedef DynamicArray<tLanguage*>  ArrayOftLanguage; /* "http://www.oorsprong.org/websamples.countryinfo"[GblCplx] */


// ************************************************************************ //
// XML       : tCountryInfo, global, <complexType>
// Namespace : http://www.oorsprong.org/websamples.countryinfo
// ************************************************************************ //
class tCountryInfo : public TRemotable {
private:
  UnicodeString   FsISOCode;
  UnicodeString   FsName;
  UnicodeString   FsCapitalCity;
  UnicodeString   FsPhoneCode;
  UnicodeString   FsContinentCode;
  UnicodeString   FsCurrencyISOCode;
  UnicodeString   FsCountryFlag;
  ArrayOftLanguage FLanguages;

public:
  __fastcall ~tCountryInfo();
__published:
  __property UnicodeString   sISOCode = { read=FsISOCode, write=FsISOCode };
  __property UnicodeString      sName = { read=FsName, write=FsName };
  __property UnicodeString sCapitalCity = { read=FsCapitalCity, write=FsCapitalCity };
  __property UnicodeString sPhoneCode = { read=FsPhoneCode, write=FsPhoneCode };
  __property UnicodeString sContinentCode = { read=FsContinentCode, write=FsContinentCode };
  __property UnicodeString sCurrencyISOCode = { read=FsCurrencyISOCode, write=FsCurrencyISOCode };
  __property UnicodeString sCountryFlag = { read=FsCountryFlag, write=FsCountryFlag };
  __property ArrayOftLanguage  Languages = { read=FLanguages, write=FLanguages };
};




// ************************************************************************ //
// XML       : tLanguage, global, <complexType>
// Namespace : http://www.oorsprong.org/websamples.countryinfo
// ************************************************************************ //
class tLanguage : public TRemotable {
private:
  UnicodeString   FsISOCode;
  UnicodeString   FsName;
__published:
  __property UnicodeString   sISOCode = { read=FsISOCode, write=FsISOCode };
  __property UnicodeString      sName = { read=FsName, write=FsName };
};


typedef DynamicArray<tContinent*> ArrayOftContinent; /* "http://www.oorsprong.org/websamples.countryinfo"[GblCplx] */

// ************************************************************************ //
// Namespace : http://www.oorsprong.org/websamples.countryinfo
// transport : http://schemas.xmlsoap.org/soap/http
// style     : document
// use       : literal
// binding   : CountryInfoServiceSoapBinding
// service   : CountryInfoService
// port      : CountryInfoServiceSoap
// URL       : http://webservices.oorsprong.org/websamples.countryinfo/CountryInfoService.wso
// ************************************************************************ //
__interface INTERFACE_UUID("{5BC955F9-CE45-1DCA-E084-54EDABCE4BD7}") CountryInfoServiceSoapType : public IInvokable
{
public:
  virtual ArrayOftContinent ListOfContinentsByName() = 0; 
  virtual ArrayOftContinent ListOfContinentsByCode() = 0; 
  virtual ArrayOftCurrency ListOfCurrenciesByName() = 0; 
  virtual ArrayOftCurrency ListOfCurrenciesByCode() = 0; 
  virtual UnicodeString   CurrencyName(const UnicodeString sCurrencyISOCode) = 0; 
  virtual ArrayOftCountryCodeAndName ListOfCountryNamesByCode() = 0; 
  virtual ArrayOftCountryCodeAndName ListOfCountryNamesByName() = 0; 
  virtual ArrayOftCountryCodeAndNameGroupedByContinent ListOfCountryNamesGroupedByContinent() = 0; 
  virtual UnicodeString   CountryName(const UnicodeString sCountryISOCode) = 0; 
  virtual UnicodeString   CountryISOCode(const UnicodeString sCountryName) = 0; 
  virtual UnicodeString   CapitalCity(const UnicodeString sCountryISOCode) = 0; 
  virtual tCurrency*      CountryCurrency(const UnicodeString sCountryISOCode) = 0; 
  virtual UnicodeString   CountryFlag(const UnicodeString sCountryISOCode) = 0; 
  virtual UnicodeString   CountryIntPhoneCode(const UnicodeString sCountryISOCode) = 0; 
  virtual tCountryInfo*   FullCountryInfo(const UnicodeString sCountryISOCode) = 0; 
  virtual ArrayOftCountryInfo FullCountryInfoAllCountries() = 0; 
  virtual ArrayOftCountryCodeAndName CountriesUsingCurrency(const UnicodeString sISOCurrencyCode) = 0; 
  virtual ArrayOftLanguage ListOfLanguagesByName() = 0; 
  virtual ArrayOftLanguage ListOfLanguagesByCode() = 0; 
  virtual UnicodeString   LanguageName(const UnicodeString sISOCode) = 0; 
  virtual UnicodeString   LanguageISOCode(const UnicodeString sLanguageName) = 0; 
};
typedef DelphiInterface<CountryInfoServiceSoapType> _di_CountryInfoServiceSoapType;

_di_CountryInfoServiceSoapType GetCountryInfoServiceSoapType(bool useWSDL=false, System::String addr= System::String(), Soaphttpclient::THTTPRIO* HTTPRIO=0);


};     // NS_CountryInfoService

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace NS_CountryInfoService;
#endif



#endif // CountryInfoServiceH
