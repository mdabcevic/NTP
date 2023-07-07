//---------------------------------------------------------------------------

#ifndef UserH
#define UserH
#include <System.hpp> 			// Include for UnicodeString
//---------------------------------------------------------------------------

class User
{
public:
    int ID;
	UnicodeString FirstName;
	UnicodeString LastName;
	UnicodeString IDNum;
	UnicodeString DepartmentName;
	UnicodeString Username;
	UnicodeString Password;
	UnicodeString Email;
	UnicodeString Phone;
    UnicodeString AuthToken;
};

//---------------------------------------------------------------------------
extern PACKAGE User* user;
//---------------------------------------------------------------------------

#endif
