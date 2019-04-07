#pragma once
#include <string>
#include "Address.h"
#include <vector>
#include <fstream>
#include "Agency.h"
using namespace std;

struct Client {
	const string separator = "::::::::::";
	string name;
	int NIF;
	int familyNumber;
	Address address;
	string touristicPacksIdentifier;
	double totalValue;
};
vector<Client> readClients(Agency agency, vector<Client> clientsVector);
