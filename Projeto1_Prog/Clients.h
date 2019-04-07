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

void addClient(vector<Client> &clientsVector, string name, int nif, int familyNumber, string addressText, string touristicPacksBought);
