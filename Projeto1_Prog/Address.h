#pragma once
#include <string>


struct Address {
	std::string street;
	int doorNumber;
	std::string floorNumber;
	std::string postalCode;
	std::string locality;
};


Address addressTextConverter(std::string addressText);