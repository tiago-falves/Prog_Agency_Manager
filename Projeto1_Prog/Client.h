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
    string name; // Client's name
    unsigned int nif; // Client's VAT number (NIF)
    unsigned short int familySize;  // Client's family size
    Address address; // Client's address
    vector<int> travelPackIds; // Vector that stores the clients' bought packs
    unsigned int totalPurchased; // Total value spent by the client

public:
	Client();
	Client(string clientsFileName, vector<Client> &clients);
	Client(string name, unsigned int nif, unsigned short int familySize, Address address);  // For a new client
    Client(string name, unsigned int nif, unsigned short int familySize, Address address, vector<TravelPack> &packets, unsigned int totalPurchased);  // Client read from file

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
  
    // Other methods

	/*Reads the clients from the agency's associated clients file and stores them to a vector 
	@param clientsNameFile - the file containing information about the clients
	@param clientsVector - the vector where the clients are stored to
	@return void
	*/
	static void readClients(string clientsNameFile, vector<Client> &clientsVector);

	/*Stores the client to the vector
	@param clientsVector - the vector where the clients are stored to
	@return void
	*/
	void addClient(vector<Client> &clientsVector);

	/*Removes the client from the vector
	@param - clientsVector - the vector where the clients are stored to
	@return void
	*/
	void removeClient(vector<Client> &clientsVector);

	/*Modifies the client in the vector and stores it again in the vector
	@param clientsVector - the vector where the clients are stored to
	@return void
	*/
	void modifyClient(Client clientToModify, vector<Client> &clientVector);

	/*Converts the client's travel packs vector to a single string for easier manipulation
	@param travelPacks - the vector where the client's bought travel packs are stored
	@return string - the string containing the aggregated travel packs
	*/
	static string travelPacksToString(vector<int> travelPacks);

	/*Returns true if the specified client is in the clients vector, false otherwise
	@param clientsVector - the vector where the clients are stored
	@return bool - represents if a client is present in the vector or not
	*/
	bool clientInVector(vector<Client> clientsVector);

	/*Returns true if the client's specified packs are valid
	@param packs - client's bought packs as a string
	@return bool - true if packs are in the format "x ; y ; z ; ..."
	*/
	static bool validPacksBought(string packs);

	/*Returns true if the VAT number is valid
	@param - /
	@return bool - true if VAT number has 9 digits in the format "xxxxxxxxx" and is an integer
	*/
	bool checknif() const;

	/*Shows information about the client, in slighty different format, as an alternative to the << operator
	@param - /
	@return void
	*/
	void showClient() const;


	friend bool operator==(const Client &client1, const Client &client2);
	friend ostream& operator<<(ostream& out, const Client &client);
};
