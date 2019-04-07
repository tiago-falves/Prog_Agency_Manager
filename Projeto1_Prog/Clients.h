#pragma once
#include <string>
#include "Address.h"
#include <vector>
#include <fstream>
#include "Agency.h"
#include "StringManipulator.h"
#include "TravelPack.h"
using namespace std;

struct Client {
	const string separator = "::::::::::";
	string name;
	int NIF;
	int familyNumber;
	Address address;
	vector<int> touristicPacksIdentifier;
	double totalValue;

	/*Client& operator = (const Client& client) {
		this->name = client.name;
		this -> address = client.address;
		this -> familyNumber = client.familyNumber;
		this->NIF = client.NIF;
		this->touristicPacksIdentifier = client.touristicPacksIdentifier;
		return *this;
	}*/
};

void readClients(Agency agency, vector<Client> &clientsVector);

void addClient(vector<Client> &clientsVector, string name, int nif, int familyNumber, string addressText, string touristicPacksBought);

void removeClient(Client clientToRemove, vector<Client> &clientsVector);

bool equalClients(Client client1, Client client2);

void copyClient(Client &copy, Client &client);
