#include "Address.h"

Address::Address(){
	this->street = "UNSPECIFIED STREET";
	this->doorNumber = 0;
	this->floor = "UNSPECIFIED FLOOR";
	this->postalCode = "0000-000";
	this->location = "UNSPECIFIED SITE";
}

Address::Address(string street, unsigned short doorNumber, string floor, string postalCode, string location){
	this -> street = street;
	this -> doorNumber = doorNumber;
	this -> floor = floor;
    this -> postalCode = postalCode;
	this -> location = location;
}

Address::Address(string address) {
	this->street = addressTextConverter(address).street;
	this->doorNumber = addressTextConverter(address).doorNumber;
	this->floor = addressTextConverter(address).floor;
	this->postalCode = addressTextConverter(address).postalCode;
	this->location = addressTextConverter(address).location;
	
}

// GET methods

string Address::getStreet() const{ return street;}

unsigned short Address::getDoorNumber() const { return doorNumber; }

string Address::getFloor() const{ return floor; }

string Address::getPostalCode() const{ return postalCode; }

string Address::getLocation() const{ return location; }


// SET methods

void Address::setStreet(string street){	this -> street = street; }

void Address::setDoorNumber(unsigned short doorNumber){	this -> doorNumber = doorNumber; }

void Address::setFloor(string floor){ this -> floor = floor; }

void Address::setPostalCode(string postalCode){ this -> postalCode = postalCode; }

void Address::setLocation(string location){	this -> location = location; }



bool Address::validAddressText(string address)
{
	vector<string> stringVector;
	stringVector = separateCharacterStr(address, '/');
	if (stringVector.size() != 5) { return false; }
	if (!stringIsNumber(stringVector[1])) { return false; }
	if (!validPostalCode(stringVector[3])) { return false; }
	return true;
}

Address Address::addressTextConverter(string addressText) {
	Address address;
	string subString;

	subString = addressText.substr(0, addressText.find_first_of('/'));
	trim(subString);
	address.street = subString;
	addressText.erase(0, addressText.find_first_of('/') + 1);

	subString = addressText.substr(0, addressText.find_first_of('/'));
	trim(subString);
	address.doorNumber = stoi(subString);
	addressText.erase(0, addressText.find_first_of('/') + 1);

	subString = addressText.substr(0, addressText.find_first_of('/'));
	trim(subString);
	address.floor = subString;
	addressText.erase(0, addressText.find_first_of('/') + 1);

	subString = addressText.substr(0, addressText.find_first_of('/'));
	trim(subString);
	address.postalCode = subString;
	addressText.erase(0, addressText.find_first_of('/') + 1);

	subString = addressText.substr(0, addressText.find_first_of('/'));
	trim(subString);
	address.location = subString;
	addressText.erase(0, addressText.find_first_of('/') + 1);

	return address;
}


void Address::showAddress() const{
    cout << "*********************************" << endl;
	cout << street << " / " << doorNumber << " / " << floor << " / " << postalCode << " / " << location << endl;
	cout << "*********************************" << endl;
}

bool Address::validPostalCode(string postalCode) {

	for (int i = 0; i < 4; i++) {
		if (postalCode[i] < '0' || postalCode[i] > '9')
			return false;
	}

	if (postalCode[4] != '-')
		return false;

	for (int i = 5; i < 7; i++) {
		if (postalCode[i] < '0' || postalCode[i] > '9')
			return false;
	}

	return true;
}


ostream& operator<<(ostream& out, const Address &address){
    out << address.street << " / " << address.doorNumber << " / " << address.floor << " / " << address.postalCode << " / " << address.location << endl;   
    return out;
}

bool operator==(const Address &address1, const Address &address2) {
	return address1.street == address2.street && address1.doorNumber == address2.doorNumber && address1.floor == address2.floor && address1.postalCode == address2.postalCode && address1.location == address2.location; }
