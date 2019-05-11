#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "StringManipulator.h"

#include "defs.h"

using namespace std;

class Address{
private:
	string street; // street name
	unsigned short doorNumber; // door number
	string floor; // floor number ("-" is not applicable)
	string postalCode; // postal code
	string location; // site

public:
	Address();
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

	// outros metodos
  
	bool validPostalCode(); // Returns true if "xxxx-xxx", false otherwise

	bool validAddressText(string address);

	static bool equalsAddresses(Address address1, Address address2);

	void showAddress() const; // displays address in a nice format

	static Address addressTextConverter(string addressText);

	friend ostream& operator<<(ostream& out, const Address & address); //  << Operator overloading
	friend bool operator==(const Address& address1, const Address address2);

};
