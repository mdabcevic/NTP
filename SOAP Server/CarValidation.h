// ************************************************************************ //
// Invokable interface declaration header for CarValidation
// ************************************************************************ //
#ifndef   CarValidationH
#define   CarValidationH

#include <System.hpp>
#include <Soap.InvokeRegistry.hpp>
#include <Soap.XSBuiltIns.hpp>
#include <System.Types.hpp>

// ************************************************************************ //
//  Enums exposed via SOAP must be byte-aligned
// ************************************************************************ //
#pragma option -b-
enum SampleEnum
{
  etNone,
  etAFew,
  etSome,
  etALot
};
#pragma option -b.

// ************************************************************************ //
//  To expose complex types via SOAP, the type must derive from TRemotable
//  All published members of the type will be exposed.
// ************************************************************************ //
class TSampleStruct : public TRemotable {
private:
  AnsiString         FLastName;
  AnsiString         FFirstName;
  double             FSalary;
__published:
  __property AnsiString    LastName = { read=FLastName, write=FLastName };
  __property AnsiString    FirstName = { read=FFirstName, write=FFirstName };
  __property double        Salary = { read=FSalary, write=FSalary };
};

// ************************************************************************ //
//  Remotable arrays must be Dynamic arrays since they must be discoverable
//  at runtime.
// ************************************************************************ //
typedef DynamicArray<double>  TDoubleArray;


// ************************************************************************ //
//  Invokable interfaces must derive from IInvokable
//  The methods of the interface will be exposed via SOAP
// ************************************************************************ //
__interface INTERFACE_UUID("{D28FE197-E1F8-4DF7-8512-DB1436E3A0C2}") ICarValidation : public IInvokable
{
public:
    virtual SampleEnum     echoEnum(SampleEnum eValue) = 0;
    virtual TDoubleArray   echoDoubleArray(const TDoubleArray daValue) = 0;
    virtual TSampleStruct* echoStruct(const TSampleStruct* pEmployee) = 0;
    virtual double         echoDouble(double dValue) = 0;
};
typedef DelphiInterface<ICarValidation> _di_ICarValidation;


#endif // CarValidationH
//---------------------------------------------------------------------------


