#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "defs.h"
#include "Packet.h"
#include "Address.h"

using namespace std;

class Client{
private:
    string name; // name of the client
    unsigned int VATnumber; // VAT number of client
    unsigned short int familySize;  // number of family members
    Address address; // client's address
    vector<Packet> packets; // vector to store client's packets bought
    unsigned int totalPurchased; // total value spent by the client

public:
    Client(string name, unsigned int VATnumber, unsigned short int familySize, Address address);  // for a new client
    Client(string name, unsigned int VATnumber, unsigned short int familySize, Address address, vector<Packet> & packets, unsigned int totalPurchased);  // client read from file

    // GET methods
  
    string getName() const;
    unsigned int getVATnumber() const;
    unsigned short int getFamilySize() const;
    Address getAddress() const;
    vector<Packet> getPacketList() const;
    unsigned int getTotalPurchased() const;
  
    // SET methods
  
    void setName(string name);
    void setVATnumber(unsigned int VATnumber);
    void setFamilySize(unsigned short int familySize);
    void setAddress(Address address);
    void setPacketList(vector<Packet> & packets);
    unsigned setTotalPurchased(unsigned int totalPurchased);
  
    // other methods

    bool checkVATnumber(unsigned int VATnumber) const; // Returns true if number has 9 digits

    friend ostream& operator<<(ostream& out, const Client & client);
};
