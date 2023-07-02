//---------------------------------------------------------------------------

#ifndef ClientH
#define ClientH
#include <System.hpp> // Include for UnicodeString
//---------------------------------------------------------------------------

class Client
{
public:
	UnicodeString CompanyName;
	UnicodeString Address;
	UnicodeString IdentificationNumber;
	UnicodeString Email;
	UnicodeString ContactPerson;
};

//---------------------------------------------------------------------------
extern PACKAGE Client* client;
//---------------------------------------------------------------------------

#endif
