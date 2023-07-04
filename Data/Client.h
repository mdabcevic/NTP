//---------------------------------------------------------------------------

#ifndef ClientH
#define ClientH
#include <System.hpp> 			// Include for UnicodeString
#include <System.JSON.hpp>     //Include for JSON serialize and deserialize process

//---------------------------------------------------------------------------

class Client
{
public:
	UnicodeString CompanyName;
	UnicodeString Address;
	UnicodeString IdentificationNumber;
	UnicodeString Email;
	UnicodeString ContactPerson;

	//Added for UDPClient purposes - this is a string packet
	String SerializeNode(){     //Client object to string
        TJSONObject *json = new TJSONObject;
        json->AddPair("CompanyName", CompanyName);
        json->AddPair("Address", Address);
        json->AddPair("IdentificationNumber", IdentificationNumber);
        json->AddPair("Email", Email);
        json->AddPair("ContactPerson", ContactPerson);

        String jsonString = json->ToString();
        delete json;

		return jsonString;
	}

	//Added for UDPServer purposes - back to Client so it can be added to cache before placed into file
	Client DeserializeNode(String jsonString) {
        Client client;

        TJSONObject* json = (TJSONObject*)TJSONObject::ParseJSONValue(jsonString);
        if (json != NULL) {
            client.CompanyName = json->GetValue("CompanyName")->Value();
            client.Address = json->GetValue("Address")->Value();
            client.IdentificationNumber = json->GetValue("IdentificationNumber")->Value();
            client.Email = json->GetValue("Email")->Value();
            client.ContactPerson = json->GetValue("ContactPerson")->Value();
            delete json;
        }

        return client;
	}
};

//---------------------------------------------------------------------------
extern PACKAGE Client* client;
//---------------------------------------------------------------------------

#endif
