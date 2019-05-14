#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "StringManipulator.h"

#include "defs.h"

using namespace std;

class Address
{
private:
	string street; // street name
	unsigned short doorNumber; // door number
	string floor; // floor number ("-" is not applicable)
	string postalCode; // postal code
	string location; // site

public:
	Address();
	Address(string address);
	Address(string street, unsigned short doorNumber, string floor, string postalCode, string location);

	// metodos GET

	string getStreet() const;
	unsigned short getDoorNumber() const;
	string getFloor() const;
	string getPostalCode() const;
	string getLocation() const;
  
	// metodos SET

	void setStreet(string street);
	void setDoorNumber(unsigned short doorNumber);
	void setFloor(string floor);
	void setPostalCode(string postalCode);
	void setLocation(string location);


	//Returns true if "xxxx-xxx", false otherwise
	static bool validPostalCode(string postalCodeString); 

	//Return True if it is a valid Address
	static bool validAddressText(string address);

	//Outputs a formated Address
	void showAddress() const; 

	//Converts a string to an Address
	static Address addressTextConverter(string addressText);

	friend ostream& operator<<(ostream &out, const Address &address); //  << ESTE NAO DEVERIA SER O SHOW ADDRESS? Está duplicado de propósito para haver mais "overloads" mas tem o mesmo efeito

	//Overrides == 
	friend bool operator==(const Address& address1, const Address &address2);

};
