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
	string street; // Street name
	unsigned short doorNumber; // Door number
	string floor; // Floor number ("-" means not applicable)
	string postalCode; // Postal code
	string location; // Site

public:
	Address();
	Address(string address); // Constructor as a string
	Address(string street, unsigned short doorNumber, string floor, string postalCode, string location);

	// Get Methods

	string getStreet() const;
	unsigned short getDoorNumber() const;
	string getFloor() const;
	string getPostalCode() const;
	string getLocation() const;
  
	// Set Methods

	void setStreet(string street);
	void setDoorNumber(unsigned short doorNumber);
	void setFloor(string floor);
	void setPostalCode(string postalCode);
	void setLocation(string location);

	// Other methods

	/*Returns a boolean that indicates if a postal code is valid
	@param postalCodeString - string containing the postal code to be evaluated
	@return bool - true if postal code follows the format "xxxx-xxx", false otherwise
	*/
	static bool validPostalCode(string postalCodeString); 

	/*Returns a boolean that indicates if an is valid
	@param address - string containing the address to be evaluated
	@return bool - true if address follows the format "Street / Door Number / Floor / Postal Code / Location", false otherwise
	*/
	static bool validAddressText(string address);

	/*Shows the address, formatted, as an alternative to the << operator
	@param - /
	@return void
	*/
	void showAddress() const; 

	/*Converts the given string to a usable address from the Address Class in the format "Street / Door Number / Floor / Postal Code / Location"
	@return bool - true if address follows the format 
	@param - addressText - a string ready to be converted to an address from the Address Class
	@return Address - Address Class
	*/
	static Address addressTextConverter(string addressText);


	friend ostream& operator<<(ostream &out, const Address &address); 
	friend bool operator==(const Address& address1, const Address &address2);

};
