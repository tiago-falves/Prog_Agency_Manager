#include "Address.h"

Address::Address(){
}

Address::Address(string street = "UNSPECIFIED STREET", unsigned short doorNumber = 0, string floor = "UNSPECIFIED FLOOR", string postalCode = "0000-000", string location = "UNSPECIFIED SITE"){
	this -> street = street;
	this -> doorNumber = doorNumber;
	this -> floor = floor;
    this -> postalCode = postalCode;
	this -> location = location;
}

  // metodos GET

string Address::getStreet() const{
	return street;
}

unsigned short Address::getDoorNumber() const{
	return doorNumber;
}

string Address::getFloor() const{
	return floor;
}

string Address::getPostalCode() const{
	return postalCode;
}

string Address::getLocation() const{
	return location;
}

  // metodos SET

void Address::setStreet(string street){
	this -> street = street;
}

void Address::setDoorNumber(unsigned short doorNumber){
	this -> doorNumber = doorNumber;
}

void Address::setFloor(string floor){
	this -> floor = floor;
}

void Address::setPostalCode(string postalCode){
	this -> postalCode = postalCode;
}

void Address::setLocation(string location){
	this -> location = location;
}

// outros metodos

bool Address::checkPostalCode() const{

    bool valid = true;

    for (int i = 0; i < 4; i++)
    {
        if (postalCode[i] < '0' || postalCode[i] > '9')
        {   
            valid = false;
            break;
        }
        
    }

    if (postalCode[4] != '-')
    {
        valid = false;
    }
    
    for (int i = 5; i < 7; i++)
    {
        if (postalCode[i] < '0' || postalCode[i] > '9')
        {
            valid = false;
            break;
        }
    }
   
   return valid; 
}

void Address::showAddress() const{
    cout << "*********************************" << endl;
	cout << street << " / " << doorNumber << " / " << floor << " / " << postalCode << " / " << location << endl;
	cout << "*********************************" << endl;
}

ostream& operator<<(ostream& out, const Address & address){
    out << address.street << " / " << address.doorNumber << " / " << address.floor << " / " << address.postalCode << " / " << address.location << endl;   
    
    return out;
}

