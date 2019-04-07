#pragma once
#include <string>
#include "Address.h"
#include "FileOperations.h"
#include <fstream>


struct Agency {
	std::string name;
	int NIF;
	std::string URL;
	Address address;
	std::string clientsNameFile;
	std::string packsNameFile;
};

void readAgency(Agency &agency);