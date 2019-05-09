#pragma once

#include <iostream>
#include <string>
#include <vector>


#include "defs.h"
#include "Address.h"
#include "Client.h"
#include "TravelPack.h"

using namespace std;

class Agency{
private:
    string name; // Agency's name
    unsigned int VATnumber; // Agency's VAT number
    Address address; // Agency's address
    string URL; // Agency's Website URL
    vector<Client> clients; // Vector to store the existing clients
    vector<TravelPack> TravelPacks; // Vector to store the existing TravelPacks
  
    bool clientsInfoHasChanged; // True if at least one client has been changed/added/deleted
    bool TravelPacksInfoHasChanged; // True if at least one TravelPack has been changed/added/deleted
    unsigned int maxClientsId; // Maximum value among all clients identifiers
    unsigned int maxTravelPacksId; // Maximum value among all TravelPacks identifiers

public:
    Agency(string fileName);

    // methods GET
  
    string getName() const;
    unsigned getVATnumber() const;
    Address getAddress() const;
    string getURL() const;
    vector<Client> getClients() const;
    vector<TravelPack> getTravelPacks() const;

    // methods SET
  
    void setName(string name);
    void setVATnumber(unsigned VATnumber);
    void setAddress(Address address);
    void setURL(string url);
    void setClients(vector<Client> & clients);
    void setTravelPacks(vector<TravelPack> & TravelPacks);

    // other methods */
  
    friend ostream& operator<<(ostream& out, const Agency & agency); // << Operator overloading

};
