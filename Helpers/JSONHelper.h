//---------------------------------------------------------------------------

#ifndef JSONHelperH
#define JSONHelperH
#include <System.hpp> // Include for UnicodeString
#include <vector>
#include "Client.h"

//---------------------------------------------------------------------------
class JSONHelper
{
public:
	//properties
	Client currentClient;
	std::vector<Client> allClients;

	//methods
	JSONHelper();
	void LoadClients();
	void AddClient();
	void DeleteClient(int index);
	void EditClient(int index);
	void RewriteFile();

};
//---------------------------------------------------------------------------
extern PACKAGE JSONHelper* jSONHelper;
//---------------------------------------------------------------------------
#endif
