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
    vector<int> travelPackIds; // vector to store client's packets bought
    unsigned int totalPurchased; // total value spent by the client - we're assuming each pack is bought for the whole family

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
    vector<int> getTravelPackIds() const;
    unsigned int getTotalPurchased() const;
  
    // SET methods
  
    void setName(string name);
    void setNif(unsigned int nif);
    void setFamilySize(unsigned short int familySize);
    void setAddress(Address address);
    void setTravelPackIds(vector<int> &travelPackId);
    void setTotalPurchased(unsigned int totalPurchased);
  
    
	//Reads the file clientsNameFile and put the result to a Client Vector
	static void readClients(string clientsNameFile, vector<Client> &clientsVector);

	//Adds client to the clientsVector
	void addClient(vector<Client> &clientsVector);

	//Removes clientToRemove from clientsVector
	void removeClient(vector<Client> &clientsVector);

	// Modify Client clientTModify to client
	void modifyClient(Client clientToModify, vector<Client> &clientVector);

	//Transorms the client.travelpacks in a string separated by ';'
	static string travelPacksToString(vector<int> travelPacks);

	// Returns True if the client is in the Vector
	bool clientInVector(vector<Client> clientsVector);

	//Returns true if the pack is valid
	static bool validPacksBought(string packs);

	// Returns true if number has 9 digits and valid int
    bool checknif() const; 

	//Outputs client in a different way
    void showClient() const;

	friend bool operator==(const Client &client1, const Client &client2);
	friend ostream& operator<<(ostream& out, const Client &client);
};
