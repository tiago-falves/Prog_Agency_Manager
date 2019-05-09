#pragma once

#include <iostream>
#include <string>
#include <vector>


#include "defs.h"
#include "Address.h"
#include "Client.h"
#include "Packet.h"

using namespace std;

class Agency{
private:
    string name; // Agency's name
    unsigned int VATnumber; // Agency's VAT number
    Address address; // Agency's address
    string URL; // Agency's Website URL
    vector<Client> clients; // Vector to store the existing clients
    vector<Packet> packets; // Vector to store the existing packets
  
    bool clientsInfoHasChanged; // True if at least one client has been changed/added/deleted
    bool packetsInfoHasChanged; // True if at least one packet has been changed/added/deleted
    unsigned int maxClientsId; // Maximum value among all clients identifiers
    unsigned int maxPacketsId; // Maximum value among all packets identifiers

public:
    Agency(string fileName);

    // methods GET
  
    string getName() const;
    unsigned getVATnumber() const;
    Address getAddress() const;
    string getURL() const;
    vector<Client> getClients() const;
    vector<Packet> getPackets() const;

    // methods SET
  
    void setName(string name);
    void setVATnumber(unsigned VATnumber);
    void setAddress(Address address);
    void setURL(string url);
    void setClients(vector<Client> & clients);
    void setPackets(vector<Packet> & packets);

    // other methods */
  
    friend ostream& operator<<(ostream& out, const Agency & agency); // << Operator overloading

};
