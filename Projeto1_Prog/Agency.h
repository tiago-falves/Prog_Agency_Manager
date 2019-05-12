#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "defs.h"
#include "Address.h"
#include "Client.h"
#include "TravelPack.h"

using namespace std;

class Agency{
private:
    string name; // Agency's name
    unsigned int nif; // Agency's VAT number
    Address address; // Agency's address
    string url; // Agency's Website URL
    //vector<Client> clients; // Vector to store the existing clients
    //vector<TravelPack> TravelPacks; // Vector to store the existing TravelPacks
	string clientsNameFile; // Name of the clients file
	string packsNameFile;	// Name of the Travel Packs file
  
    //bool clientsInfoHasChanged; // True if at least one client has been changed/added/deleted
    //bool TravelPacksInfoHasChanged; // True if at least one TravelPack has been changed/added/deleted
    //unsigned int maxClientsId; // Maximum value among all clients getId()s
    //unsigned int maxTravelPacksId; // Maximum value among all TravelPacks getId()s

public:
    Agency(string fileName);
	Agency();

    // GET methods
  
    string getName() const;
    unsigned getNif() const;
    Address getAddress() const;
    string getUrl() const;
	string getClientsNameFile() const;
	string getPacksNameFile() const;
	//vector<Client> getClients() const;
    //vector<TravelPack> getTravelPacks() const;

    // SET methods
  
    void setName(string name);
    void setNif(unsigned nif);
    void setAddress(Address address);
    void setURL(string url);
	void setClientsNameFile(string clientsNameFile);
	void setPacksNameFile(string packsNameFile);

    //void setClients(vector<Client> & clients);
    //void setTravelPacks(vector<TravelPack> & TravelPacks);

	// other methods */

	void readAgency(string filename);
	void showAgency() const;
  
    friend ostream& operator<<(ostream& out, const Agency & agency); // << Operator overloading

};
