
// ********************************************************************************************************* //
//                                                                                                         
//                                            XML Data Binding                                             
//                                                                                                         
//         Generated on: 30/06/2023 19:04:24                                                               
//       Generated from: C:\Users\Maja\Documents\Embarcadero\Studio\Projects\NTP projekt\companycars.xml   
//   Settings stored in: C:\Users\Maja\Documents\Embarcadero\Studio\Projects\NTP projekt\companycars.xdb   
//                                                                                                         
// ********************************************************************************************************* //

#ifndef   companycarsH
#define   companycarsH

#include <System.hpp>
#include <System.Variants.hpp>
#include <System.SysUtils.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLcompanycarsType;
typedef System::DelphiInterface<IXMLcompanycarsType> _di_IXMLcompanycarsType;
__interface IXMLcarType;
typedef System::DelphiInterface<IXMLcarType> _di_IXMLcarType;

// IXMLcompanycarsType 

__interface INTERFACE_UUID("{989ADAD4-A5DD-4215-9B96-8A2966DBFE6D}") IXMLcompanycarsType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLcarType __fastcall Get_car(const int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLcarType __fastcall Add() = 0;
  virtual _di_IXMLcarType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLcarType car[const int Index] = { read=Get_car };/* default */
};

// IXMLcarType 

__interface INTERFACE_UUID("{5B4EBB5F-0AC6-4F5E-8DE2-3E974B67C730}") IXMLcarType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual System::UnicodeString __fastcall Get_licenseplate() = 0;
  virtual System::UnicodeString __fastcall Get_internalmark() = 0;
  virtual System::UnicodeString __fastcall Get_assigned() = 0;
  virtual System::UnicodeString __fastcall Get_currentuser() = 0;
  virtual System::UnicodeString __fastcall Get_location() = 0;
  virtual void __fastcall Set_licenseplate(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_internalmark(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_assigned(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_currentuser(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_location(const System::UnicodeString Value) = 0;
  // Methods & Properties 
  __property System::UnicodeString licenseplate = { read=Get_licenseplate, write=Set_licenseplate };
  __property System::UnicodeString internalmark = { read=Get_internalmark, write=Set_internalmark };
  __property System::UnicodeString assigned = { read=Get_assigned, write=Set_assigned };
  __property System::UnicodeString currentuser = { read=Get_currentuser, write=Set_currentuser };
  __property System::UnicodeString location = { read=Get_location, write=Set_location };
};

// Forward Decls 

class TXMLcompanycarsType;
class TXMLcarType;

// TXMLcompanycarsType 

class TXMLcompanycarsType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLcompanycarsType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLcompanycarsType 
  virtual _di_IXMLcarType __fastcall Get_car(const int Index);
  virtual _di_IXMLcarType __fastcall Add();
  virtual _di_IXMLcarType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLcarType 

class TXMLcarType : public Xml::Xmldoc::TXMLNode, public IXMLcarType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLcarType 
  virtual System::UnicodeString __fastcall Get_licenseplate();
  virtual System::UnicodeString __fastcall Get_internalmark();
  virtual System::UnicodeString __fastcall Get_assigned();
  virtual System::UnicodeString __fastcall Get_currentuser();
  virtual System::UnicodeString __fastcall Get_location();
  virtual void __fastcall Set_licenseplate(const System::UnicodeString Value);
  virtual void __fastcall Set_internalmark(const System::UnicodeString Value);
  virtual void __fastcall Set_assigned(const System::UnicodeString Value);
  virtual void __fastcall Set_currentuser(const System::UnicodeString Value);
  virtual void __fastcall Set_location(const System::UnicodeString Value);
};

// Global Functions 

_di_IXMLcompanycarsType __fastcall Getcompanycars(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLcompanycarsType __fastcall Getcompanycars(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLcompanycarsType __fastcall Loadcompanycars(const System::UnicodeString& FileName);
_di_IXMLcompanycarsType __fastcall  Newcompanycars();

#define TargetNamespace ""

#endif