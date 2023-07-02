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
	Client* currentClient = new Client();
	std::vector<Client*> allClients;

	//methods
	JSONHelper();
	~JSONHelper(){
		delete currentClient;
		for(Client* client : allClients) {
			delete client;
		}
	}
	void LoadClients();
	void AddClient();
	void DeleteClient();
    void EditClient();

};
//---------------------------------------------------------------------------
extern PACKAGE JSONHelper* jSONHelper;
//---------------------------------------------------------------------------
#endif
