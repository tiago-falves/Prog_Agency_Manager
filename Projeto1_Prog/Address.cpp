#include "Address.h"
#include "StringManipulator.h"
using namespace std;


//Converts Address in the format 'Street / Door Number / Floor Number / Postal Code / Locality' to a struct Address
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
//Returns True if two addresses are equal
bool equalsAddresses(Address address1, Address address2) {
	if (address1.doorNumber == address2.doorNumber && address1.floorNumber == address2.floorNumber && address1.locality == address2.locality && address1.postalCode == address2.postalCode && address1.street == address2.street)
		return true;
	else
		return false;
}

//Returns True if it is a valid Address
bool validAddressText(string address)
{
	vector<string> stringVector;
	stringVector = separateCharacterStr(address, '/');
	if (stringVector.size() != 5){return false;}
	if (!stringIsNumber(stringVector[1])) {return false;}
	return true;
}