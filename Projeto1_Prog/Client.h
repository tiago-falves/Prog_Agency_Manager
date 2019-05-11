#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "defs.h"
#include "TravelPack.h"
#include "Address.h"

using namespace std;

class Client{
private:
    string name; // name of the client
    unsigned int nif; // VAT number of client
    unsigned short int familySize;  // number of family members
    Address address; // client's address
    vector<TravelPack> TravelPacks; // vector to store client's packets bought
    unsigned int totalPurchased; // total value spent by the client

public:
    Client(string name, unsigned int nif, unsigned short int familySize, Address address);  // for a new client
    Client(string name, unsigned int nif, unsigned short int familySize, Address address, vector<TravelPack> &packets, unsigned int totalPurchased);  // client read from file

    // GET methods
  
    string getName() const;
    unsigned int getnif() const;
    unsigned short int getFamilySize() const;
    Address getAddress() const;
    vector<TravelPack> getTravelPackList() const;
    unsigned int getTotalPurchased() const;
  
    // SET methods
  
    void setName(string name);
    void setNif(unsigned int nif);
    void setFamilySize(unsigned short int familySize);
    void setAddress(Address address);
    void setTravelPackList(vector<TravelPack> &TravelPacks);
    void setTotalPurchased(unsigned int totalPurchased);
  
    // other methods

    bool checknif() const; // Returns true if number has 9 digits
    void showClient() const;
    friend ostream& operator<<(ostream& out, const Client &client); // Operator overloading
};
