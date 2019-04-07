#include "Address.h"
#include "StringManipulator.h"
using namespace std;


Address addressTextConverter(string addressText) {
	Address address;
	string subString;

	address.street = addressText.substr(0, addressText.find_first_of('/'));
	addressText.erase(0, addressText.find_first_of('/') + 1);

	subString = addressText.substr(0, addressText.find_first_of('/'));
	trim(subString);
	address.doorNumber = stoi(subString);
	addressText.erase(0, addressText.find_first_of('/') + 1);

	subString = addressText.substr(0, addressText.find_first_of('/'));
	trim(subString);
	address.floorNumber = subString;
	addressText.erase(0, addressText.find_first_of('/') + 1);

	subString = addressText.substr(0, addressText.find_first_of('/'));
	trim(subString);
	address.postalCode = subString;
	addressText.erase(0, addressText.find_first_of('/') + 1);

	subString = addressText.substr(0, addressText.find_first_of('/'));
	trim(subString);
	address.locality = subString;
	addressText.erase(0, addressText.find_first_of('/') + 1);
	

	return address;
}

bool equalsAddresses(Address address1, Address address2) {
	if (address1.doorNumber == address2.doorNumber && address1.floorNumber == address2.floorNumber && address1.locality == address2.locality && address1.postalCode == address2.postalCode && address1.street == address2.street)
		return true;
	else
		return false;
}