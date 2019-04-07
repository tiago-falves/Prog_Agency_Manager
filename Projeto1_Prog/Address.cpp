#include "Address.h"
#include "StringManipulator.h"
using namespace std;

Address addressTextConverterAgency(string addressText) {
	Address address;
	address.street = addressText.substr(0, addressText.find_first_of('/'));
	trim(address.street);
	addressText.erase(0, addressText.find_first_of('/'));

	address.doorNumber = stoi(addressText.substr(0, addressText.find_first_of('/')));
	
	addressText.erase(0, addressText.find_first_of('/'));

	address.floorNumber = addressText.substr(0, addressText.find_first_of('/'));
	trim(address.floorNumber);
	addressText.erase(0, addressText.find_first_of('/'));

	address.postalCode = addressText.substr(0, addressText.find_first_of('/'));
	trim(address.postalCode);
	addressText.erase(0, addressText.find_first_of('/'));

	address.locality = addressText.substr(0, addressText.find_first_of('/'));
	trim(address.locality);
	addressText.erase(0, addressText.find_first_of('/'));

	return address;
}