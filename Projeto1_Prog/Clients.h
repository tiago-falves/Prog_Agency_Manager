#pragma once
#include <string>
#include "Address.h"
#include <vector>
#include <fstream>
#include "Agency.h"

struct Client {
	const std::string separator = "::::::::::";
	std::string name;
	int NIF;
	int familyNumber;
	Address address;
	std::string touristicPacksIdentifier;
	double totalValue;
};
