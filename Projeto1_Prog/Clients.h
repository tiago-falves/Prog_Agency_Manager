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

};

void readClients(Agency agency, vector<Client> &clientsVector);

void addClient(vector<Client> &clientsVector, Client client);

void removeClient(Client clientToRemove, vector<Client> &clientsVector);

bool equalClients(Client client1, Client client2);

void copyClient(Client &copy, Client client);

void modifyClient(Client clientToModify, vector<Client> &clientVector, Client client);

bool validPacksBought(string packs);

bool clientInVector(vector<Client> clientsVector, Client client);

string travelPacksToString(vector<int> travelPacks);