#include "Client.h"

Client::Client(string name, unsigned int nif, unsigned short int familySize, Address address){
    this -> name = name;
    this -> nif = nif;
    this -> familySize = familySize;
    this -> address = address;
}

Client::Client(string name, unsigned nif, unsigned short familySize, Address address, vector<TravelPack> &TravelPacks, unsigned totalPurchased){
    this -> name = name;
    this -> nif = nif;
    this -> familySize = familySize;
    this -> address = address;
    this -> TravelPacks = TravelPacks;
    this -> totalPurchased = totalPurchased;
}

  // GET methods

string Client::getName() const{
    return name;
}
  
unsigned Client::getnif() const{
    return nif;
}

unsigned short Client::getFamilySize() const{
    return familySize;
}

Address Client::getAddress() const{
    return address;
}

vector<TravelPack> Client::getTravelPackList() const{
    return TravelPacks;
}

unsigned Client::getTotalPurchased() const{
    return totalPurchased;
}
  
  // metodos SET
	  
void Client::setName(string nome){
    this -> name = name;
}

void Client::setNif(unsigned nif){
    this -> nif = nif;
}

void Client::setFamilySize(unsigned short familySize){
    this -> familySize = familySize;
}
void Client::setAddress(Address address){
    this -> address = address;
}
void Client::setTravelPackList(vector<TravelPack> &TravelPacks){
    this -> TravelPacks = TravelPacks;
}
void Client::setTotalPurchased(unsigned totalPurchased){
    this -> totalPurchased = totalPurchased;
}
  
  // outros metodos

bool Client::checknif() const
{
    bool valid = true;

    if(nif < 100000000 || nif > 999999999) // The number has to be 9 digits long
        {    
            valid = false;
        }
    return valid;
}

void Client::showClient() const 
{
    cout << "*********************************" << endl;
	cout << "Name:" << name << endl;
    cout << "VAT Number: " << nif << endl;
    cout << "Family Size: " << familySize << endl;
    //cout << "Address: " << address.showAddress() << endl;
    //cout << "TravelPacks: " << TravelPacks.showTravelPacks() << endl;
    cout << "Total Value: " << totalPurchased << endl;
	cout << "*********************************" << endl;
}

/*ostream& operator<<(ostream& out, const Client &client){
    out << cout << "*********************************" << endl << "Name:" << name << endl << "VAT Number: " << nif << endl
    << "Family Size: " << familySize << endl << "Address: " << address.showAddress() << endl << "TravelPacks: " << TravelPacks.showTravelPacks() << endl
    << "Total Value: " << totalPurchased << endl << "*********************************" << endl;
    return out;
}*/
