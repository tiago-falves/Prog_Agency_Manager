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
	//trim(address.locality);
	//addressText.erase(0, addressText.find_first_of('/'));

	return address;
}