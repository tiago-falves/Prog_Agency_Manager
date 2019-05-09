#include "Client.h"

Client::Client(string name, unsigned int VATnumber, unsigned short int familySize, Address address){
    this -> name = name;
    this -> VATnumber = VATnumber;
    this -> familySize = familySize;
    this -> address = address;
}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<TravelPack> &TravelPacks, unsigned totalPurchased){
    this -> name = name;
    this -> VATnumber = VATnumber;
    this -> familySize = familySize;
    this -> address = address;
    this -> TravelPacks = TravelPacks;
    this -> totalPurchased = totalPurchased;
}

  // GET methods

string Client::getName() const{
    return name;
}
  
unsigned Client::getVATnumber() const{
    return VATnumber;
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

void Client::setVATnumber(unsigned VATnumber){
    this -> VATnumber = VATnumber;
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

bool Client::checkVATnumber() const
{
    bool valid = true;

    if(VATnumber < 100000000 || VATnumber > 999999999) // The number has to be 9 digits long
        {    
            valid = false;
        }
    return valid;
}

void Client::showClient() const 
{
    cout << "*********************************" << endl;
	cout << "Name:" << name << endl;
    cout << "VAT Number: " << VATnumber << endl;
    cout << "Family Size: " << familySize << endl;
    //cout << "Address: " << address.showAddress() << endl;
    //cout << "TravelPacks: " << TravelPacks.showTravelPacks() << endl;
    cout << "Total Value: " << totalPurchased << endl;
	cout << "*********************************" << endl;
}

/*ostream& operator<<(ostream& out, const Client &client){
    out << cout << "*********************************" << endl << "Name:" << name << endl << "VAT Number: " << VATnumber << endl
    << "Family Size: " << familySize << endl << "Address: " << address.showAddress() << endl << "TravelPacks: " << TravelPacks.showTravelPacks() << endl
    << "Total Value: " << totalPurchased << endl << "*********************************" << endl;
    return out;
}*/
