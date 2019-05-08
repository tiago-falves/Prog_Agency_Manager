#include "Client.h"

Client::Client(string name, unsigned int VATnumber, unsigned short int familySize, Address address){
  
  // REQUIRES IMPLEMENTATION 
}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<Packet> & packets, unsigned totalPurchased){
  
  // REQUIRES IMPLEMENTATION 
}

  // GET methods

string Client::getName() const{
  
  // REQUIRES IMPLEMENTATION 
}
  
unsigned Client::getVATnumber() const{
  
  // REQUIRES IMPLEMENTATION 
}

unsigned short Client::getFamilySize() const{
  
  // REQUIRES IMPLEMENTATION 
}

Address Client::getAddress() const{
  
  // REQUIRES IMPLEMENTATION 
}

vector<Packet> Client::getPacketList() const{
  
  // REQUIRES IMPLEMENTATION 
}

unsigned Client::getTotalPurchased() const{
  
  // REQUIRES IMPLEMENTATION 
}
  
  // metodos SET
	  
void Client::setName(string nome){
  
  // REQUIRES IMPLEMENTATION 
}

void Client::setVATnumber(unsigned VATnumber){
  
  // REQUIRES IMPLEMENTATION 
}

void Client::setFamilySize(unsigned short familySize){
  
  // REQUIRES IMPLEMENTATION 
}
void Client::setAddress(Address address){
  
  // REQUIRES IMPLEMENTATION 
}
void Client::setPacketList(vector<Packet> & packets){
  
  // REQUIRES IMPLEMENTATION 
}
unsigned Client::setTotalPurchased(unsigned totalPurchased){
  
  // REQUIRES IMPLEMENTATION 
}
  
  // outros metodos

bool checkVATnumber(unsigned int VATnumber)
{
    bool valid = true;

    if(VATnumber < 100000000 || VATnumber > 999999999) // The number has to be 9 digits long
        {    
            valid = false;
        }
    return valid;
}


ostream& operator<<(ostream& out, const Client & client){

  // REQUIRES IMPLEMENTATION 

}
