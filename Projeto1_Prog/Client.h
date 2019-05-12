#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "defs.h"
#include "TravelPack.h"
#include "Address.h"
#include "StringManipulator.h"

using namespace std;

class Client{
private:
    string name; // name of the client
    unsigned int nif; // VAT number of client
    unsigned short int familySize;  // number of family members
    Address address; // client's address
    vector<int> travelPackIdentifiers; // vector to store client's packets bought
    unsigned int totalPurchased; // total value spent by the client

public:
	Client();
	Client(string clientsFileName, vector<Client> &clients);
	Client(string name, unsigned int nif, unsigned short int familySize, Address address);  // for a new client
    Client(string name, unsigned int nif, unsigned short int familySize, Address address, vector<TravelPack> &packets, unsigned int totalPurchased);  // client read from file

    // GET methods
  
    string getName() const;
    unsigned int getnif() const;
    unsigned short int getFamilySize() const;
    Address getAddress() const;
    vector<int> getTravelPackIdentifiers() const;
    unsigned int getTotalPurchased() const;
  
    // SET methods
  
    void setName(string name);
    void setNif(unsigned int nif);
    void setFamilySize(unsigned short int familySize);
    void setAddress(Address address);
    void setTravelPackIdentifiers(vector<int> &travelPackIdentifiers);
    void setTotalPurchased(unsigned int totalPurchased);
  
    
	//Reads the file clientsNameFile and put the result to a Client Vector
	static void readClients(string clientsNameFile, vector<Client> &clientsVector);

	//Adds client to the clientsVector
	void addClient(vector<Client> &clientsVector, Client client);

	//Removes clientToRemove from clientsVector
	void removeClient(Client clientToRemove, vector<Client> &clientsVector);

	// Modify Client clientTModify to client
	void modifyClient(Client clientToModify, vector<Client> &clientVector, Client client);

	//Transorms the client.travelpacks in a string separated by ';'
	string travelPacksToString(vector<int> travelPacks);

	//Copies client to copy
	void copyClient(Client &copy, Client client);

	// Returns True if the client is in the Vector
	bool clientInVector(vector<Client> clientsVector, Client client);

	//Returns true if the pack is valid
	bool validPacksBought(string packs);

	//Returns True if Clients are equal SUBSTITUIR POR OVERIDE DO ==
	bool equalClients(Client client1, Client client2);

    bool checknif() const; // Returns true if number has 9 digits
    void showClient() const;

	friend bool operator==(const Client &client1, const Client &client2); // Comparison operator overloading
	friend ostream& operator<<(ostream& out, const Client &client); // Operator overloading
};
