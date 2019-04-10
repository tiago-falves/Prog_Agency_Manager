#pragma once
#include <string>
#include "StringManipulator.h"

struct Address {
	std::string street;
	int doorNumber;
	std::string floorNumber;
	std::string postalCode;
	std::string locality;
};

Address addressTextConverter(std::string addressText);

bool validAddressText(string address);

bool equalsAddresses(Address address1, Address address2);