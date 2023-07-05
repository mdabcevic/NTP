// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://webservices.oorsprong.org/websamples.countryinfo/CountryInfoService.wso?WSDL
//  >Import : http://webservices.oorsprong.org/websamples.countryinfo/CountryInfoService.wso?WSDL>0
// Encoding : UTF-8
// Version  : 1.0
// (06/07/2023 00:25:53 - - $Rev: 108085 $)
// ************************************************************************ //

#include <System.hpp>
#pragma hdrstop

#include "CountryInfoService.h"



namespace NS_CountryInfoService {

_di_CountryInfoServiceSoapType GetCountryInfoServiceSoapType(bool useWSDL, System::String addr, Soaphttpclient::THTTPRIO* HTTPRIO)
{
  static const char* defWSDL= "http://webservices.oorsprong.org/websamples.countryinfo/CountryInfoService.wso?WSDL";
  static const char* defURL = "http://webservices.oorsprong.org/websamples.countryinfo/CountryInfoService.wso";
  static const char* defSvc = "CountryInfoService";
  static const char* defPrt = "CountryInfoServiceSoap";
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
  _di_CountryInfoServiceSoapType service;
  rio->QueryInterface(service);
  if (!service && !HTTPRIO)
    delete rio;
  return service;
}


__fastcall tCountryCodeAndNameGroupedByContinent::~tCountryCodeAndNameGroupedByContinent()
{
  delete FContinent;
  for(int i=0; i<FCountryCodeAndNames.Length; i++)
    if (FCountryCodeAndNames[i])
      delete FCountryCodeAndNames[i];
}

__fastcall tCountryInfo::~tCountryInfo()
{
  for(int i=0; i<FLanguages.Length; i++)
    if (FLanguages[i])
      delete FLanguages[i];
}

// ************************************************************************ //
// This routine registers the interfaces and types exposed by the WebService.
// ************************************************************************ //
static void RegTypes()
{
  /* CountryInfoServiceSoapType */
  InvRegistry()->RegisterInterface(__delphirtti(CountryInfoServiceSoapType), L"http://www.oorsprong.org/websamples.countryinfo", L"UTF-8");
  InvRegistry()->RegisterDefaultSOAPAction(__delphirtti(CountryInfoServiceSoapType), L"");
  InvRegistry()->RegisterInvokeOptions(__delphirtti(CountryInfoServiceSoapType), ioDocument);
  /* CountryInfoServiceSoapType.ListOfContinentsByName */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfContinentsByName", "",
                                    "[ReturnName='ListOfContinentsByNameResult']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfContinentsByName", "ListOfContinentsByNameResult", L"",
                                   L"[ArrayItemName='tContinent']");
  /* CountryInfoServiceSoapType.ListOfContinentsByCode */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfContinentsByCode", "",
                                    "[ReturnName='ListOfContinentsByCodeResult']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfContinentsByCode", "ListOfContinentsByCodeResult", L"",
                                   L"[ArrayItemName='tContinent']");
  /* CountryInfoServiceSoapType.ListOfCurrenciesByName */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfCurrenciesByName", "",
                                    "[ReturnName='ListOfCurrenciesByNameResult']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfCurrenciesByName", "ListOfCurrenciesByNameResult", L"",
                                   L"[ArrayItemName='tCurrency']");
  /* CountryInfoServiceSoapType.ListOfCurrenciesByCode */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfCurrenciesByCode", "",
                                    "[ReturnName='ListOfCurrenciesByCodeResult']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfCurrenciesByCode", "ListOfCurrenciesByCodeResult", L"",
                                   L"[ArrayItemName='tCurrency']");
  /* CountryInfoServiceSoapType.CurrencyName */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "CurrencyName", "",
                                    "[ReturnName='CurrencyNameResult']" );
  /* CountryInfoServiceSoapType.ListOfCountryNamesByCode */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfCountryNamesByCode", "",
                                    "[ReturnName='ListOfCountryNamesByCodeResult']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfCountryNamesByCode", "ListOfCountryNamesByCodeResult", L"",
                                   L"[ArrayItemName='tCountryCodeAndName']");
  /* CountryInfoServiceSoapType.ListOfCountryNamesByName */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfCountryNamesByName", "",
                                    "[ReturnName='ListOfCountryNamesByNameResult']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfCountryNamesByName", "ListOfCountryNamesByNameResult", L"",
                                   L"[ArrayItemName='tCountryCodeAndName']");
  /* CountryInfoServiceSoapType.ListOfCountryNamesGroupedByContinent */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfCountryNamesGroupedByContinent", "",
                                    "[ReturnName='ListOfCountryNamesGroupedByContinentResult']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfCountryNamesGroupedByContinent", "ListOfCountryNamesGroupedByContinentResult", L"",
                                   L"[ArrayItemName='tCountryCodeAndNameGroupedByContinent']");
  /* CountryInfoServiceSoapType.CountryName */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "CountryName", "",
                                    "[ReturnName='CountryNameResult']" );
  /* CountryInfoServiceSoapType.CountryISOCode */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "CountryISOCode", "",
                                    "[ReturnName='CountryISOCodeResult']" );
  /* CountryInfoServiceSoapType.CapitalCity */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "CapitalCity", "",
                                    "[ReturnName='CapitalCityResult']" );
  /* CountryInfoServiceSoapType.CountryCurrency */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "CountryCurrency", "",
                                    "[ReturnName='CountryCurrencyResult']" );
  /* CountryInfoServiceSoapType.CountryFlag */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "CountryFlag", "",
                                    "[ReturnName='CountryFlagResult']" );
  /* CountryInfoServiceSoapType.CountryIntPhoneCode */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "CountryIntPhoneCode", "",
                                    "[ReturnName='CountryIntPhoneCodeResult']" );
  /* CountryInfoServiceSoapType.FullCountryInfo */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "FullCountryInfo", "",
                                    "[ReturnName='FullCountryInfoResult']" );
  /* CountryInfoServiceSoapType.FullCountryInfoAllCountries */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "FullCountryInfoAllCountries", "",
                                    "[ReturnName='FullCountryInfoAllCountriesResult']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(CountryInfoServiceSoapType), "FullCountryInfoAllCountries", "FullCountryInfoAllCountriesResult", L"",
                                   L"[ArrayItemName='tCountryInfo']");
  /* CountryInfoServiceSoapType.CountriesUsingCurrency */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "CountriesUsingCurrency", "",
                                    "[ReturnName='CountriesUsingCurrencyResult']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(CountryInfoServiceSoapType), "CountriesUsingCurrency", "CountriesUsingCurrencyResult", L"",
                                   L"[ArrayItemName='tCountryCodeAndName']");
  /* CountryInfoServiceSoapType.ListOfLanguagesByName */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfLanguagesByName", "",
                                    "[ReturnName='ListOfLanguagesByNameResult']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfLanguagesByName", "ListOfLanguagesByNameResult", L"",
                                   L"[ArrayItemName='tLanguage']");
  /* CountryInfoServiceSoapType.ListOfLanguagesByCode */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfLanguagesByCode", "",
                                    "[ReturnName='ListOfLanguagesByCodeResult']" );
  InvRegistry()->RegisterParamInfo(__delphirtti(CountryInfoServiceSoapType), "ListOfLanguagesByCode", "ListOfLanguagesByCodeResult", L"",
                                   L"[ArrayItemName='tLanguage']");
  /* CountryInfoServiceSoapType.LanguageName */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "LanguageName", "",
                                    "[ReturnName='LanguageNameResult']" );
  /* CountryInfoServiceSoapType.LanguageISOCode */
  InvRegistry()->RegisterMethodInfo(__delphirtti(CountryInfoServiceSoapType), "LanguageISOCode", "",
                                    "[ReturnName='LanguageISOCodeResult']" );
  /* ArrayOftCountryCodeAndName */
  RemClassRegistry()->RegisterXSInfo(__delphirtti(ArrayOftCountryCodeAndName), L"http://www.oorsprong.org/websamples.countryinfo", L"ArrayOftCountryCodeAndName");
  /* tCountryCodeAndNameGroupedByContinent */
  RemClassRegistry()->RegisterXSClass(__classid(tCountryCodeAndNameGroupedByContinent), L"http://www.oorsprong.org/websamples.countryinfo", L"tCountryCodeAndNameGroupedByContinent");
  RemClassRegistry()->RegisterExternalPropName(__typeinfo(tCountryCodeAndNameGroupedByContinent), L"CountryCodeAndNames", L"[ArrayItemName='tCountryCodeAndName']");
  /* tContinent */
  RemClassRegistry()->RegisterXSClass(__classid(tContinent), L"http://www.oorsprong.org/websamples.countryinfo", L"tContinent");
  /* tCountryCodeAndName */
  RemClassRegistry()->RegisterXSClass(__classid(tCountryCodeAndName), L"http://www.oorsprong.org/websamples.countryinfo", L"tCountryCodeAndName");
  /* tCurrency */
  RemClassRegistry()->RegisterXSClass(__classid(tCurrency), L"http://www.oorsprong.org/websamples.countryinfo", L"tCurrency");
  /* ArrayOftCurrency */
  RemClassRegistry()->RegisterXSInfo(__delphirtti(ArrayOftCurrency), L"http://www.oorsprong.org/websamples.countryinfo", L"ArrayOftCurrency");
  /* ArrayOftCountryCodeAndNameGroupedByContinent */
  RemClassRegistry()->RegisterXSInfo(__delphirtti(ArrayOftCountryCodeAndNameGroupedByContinent), L"http://www.oorsprong.org/websamples.countryinfo", L"ArrayOftCountryCodeAndNameGroupedByContinent");
  /* ArrayOftCountryInfo */
  RemClassRegistry()->RegisterXSInfo(__delphirtti(ArrayOftCountryInfo), L"http://www.oorsprong.org/websamples.countryinfo", L"ArrayOftCountryInfo");
  /* ArrayOftLanguage */
  RemClassRegistry()->RegisterXSInfo(__delphirtti(ArrayOftLanguage), L"http://www.oorsprong.org/websamples.countryinfo", L"ArrayOftLanguage");
  /* tCountryInfo */
  RemClassRegistry()->RegisterXSClass(__classid(tCountryInfo), L"http://www.oorsprong.org/websamples.countryinfo", L"tCountryInfo");
  RemClassRegistry()->RegisterExternalPropName(__typeinfo(tCountryInfo), L"Languages", L"[ArrayItemName='tLanguage']");
  /* tLanguage */
  RemClassRegistry()->RegisterXSClass(__classid(tLanguage), L"http://www.oorsprong.org/websamples.countryinfo", L"tLanguage");
  /* ArrayOftContinent */
  RemClassRegistry()->RegisterXSInfo(__delphirtti(ArrayOftContinent), L"http://www.oorsprong.org/websamples.countryinfo", L"ArrayOftContinent");
}
#pragma startup RegTypes 32

};     // NS_CountryInfoService

