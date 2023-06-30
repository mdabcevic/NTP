
// ********************************************************************************************************* //
//                                                                                                         
//                                            XML Data Binding                                             
//                                                                                                         
//         Generated on: 30/06/2023 19:04:24                                                               
//       Generated from: C:\Users\Maja\Documents\Embarcadero\Studio\Projects\NTP projekt\companycars.xml   
//   Settings stored in: C:\Users\Maja\Documents\Embarcadero\Studio\Projects\NTP projekt\companycars.xdb   
//                                                                                                         
// ********************************************************************************************************* //

#include <System.hpp>
#pragma hdrstop

#include "companycars.h"


// Global Functions 

_di_IXMLcompanycarsType __fastcall Getcompanycars(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLcompanycarsType) Doc->GetDocBinding("companycars", __classid(TXMLcompanycarsType), TargetNamespace);
};

_di_IXMLcompanycarsType __fastcall Getcompanycars(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return Getcompanycars(DocIntf);
};

_di_IXMLcompanycarsType __fastcall Loadcompanycars(const System::UnicodeString& FileName)
{
  return (_di_IXMLcompanycarsType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("companycars", __classid(TXMLcompanycarsType), TargetNamespace);
};

_di_IXMLcompanycarsType __fastcall  Newcompanycars()
{
  return (_di_IXMLcompanycarsType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("companycars", __classid(TXMLcompanycarsType), TargetNamespace);
};

// TXMLcompanycarsType 

void __fastcall TXMLcompanycarsType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("car"), __classid(TXMLcarType));
  ItemTag = "car";
  ItemInterface = __uuidof(IXMLcarType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

_di_IXMLcarType __fastcall TXMLcompanycarsType::Get_car(const int Index)
{
  return (_di_IXMLcarType) List->Nodes[Index];
};

_di_IXMLcarType __fastcall TXMLcompanycarsType::Add()
{
  return (_di_IXMLcarType) AddItem(-1);
};

_di_IXMLcarType __fastcall TXMLcompanycarsType::Insert(const int Index)
{
  return (_di_IXMLcarType) AddItem(Index);
};

// TXMLcarType 

System::UnicodeString __fastcall TXMLcarType::Get_licenseplate()
{
  return GetChildNodes()->Nodes[System::UnicodeString("licenseplate")]->Text;
};

void __fastcall TXMLcarType::Set_licenseplate(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("licenseplate")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLcarType::Get_internalmark()
{
  return GetChildNodes()->Nodes[System::UnicodeString("internalmark")]->Text;
};

void __fastcall TXMLcarType::Set_internalmark(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("internalmark")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLcarType::Get_assigned()
{
  return GetChildNodes()->Nodes[System::UnicodeString("assigned")]->Text;
};

void __fastcall TXMLcarType::Set_assigned(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("assigned")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLcarType::Get_currentuser()
{
  return GetChildNodes()->Nodes[System::UnicodeString("currentuser")]->Text;
};

void __fastcall TXMLcarType::Set_currentuser(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("currentuser")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLcarType::Get_location()
{
  return GetChildNodes()->Nodes[System::UnicodeString("location")]->Text;
};

void __fastcall TXMLcarType::Set_location(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("location")]->NodeValue = Value;
};
