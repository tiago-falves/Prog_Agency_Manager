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

bool validAddressText(string address)
{
	string substr, codigo_postal;
	bool valid_address = false;

	while (address.find_first_of(" ") != address.npos)
	{
		address.erase(address.find_first_of(" "), 1);
	}
	substr = address.substr(0, address.find_first_of("/"));
	address.erase(address.find_first_of(substr), substr.size() + 1);
	substr = address.substr(0, address.find_first_of("/"));
	address.erase(address.find_first_of(substr), substr.size() + 1);

	if (!string_is_number(substr))
		return false;

	substr = address.substr(0, address.find_first_of("/"));
	address.erase(address.find_first_of(substr), substr.size() + 1);
	substr = address.substr(0, address.find_first_of("/"));
	address.erase(address.find_first_of(substr), substr.size() + 1);
	codigo_postal = substr.substr(0, substr.find_first_of("-"));
	substr.erase(substr.find_first_of(substr), codigo_postal.size() + 1);

	if (!string_is_number(codigo_postal))
		return false;

	if (codigo_postal.size() != 4)
		return false;

	if (!string_is_number(substr))
		return false;

	if (substr.size() != 3)
		return false;

	substr = address.substr(0, address.find_first_of("/"));
	address.erase(address.find_first_of(substr), substr.size() + 1);

	return true;
}