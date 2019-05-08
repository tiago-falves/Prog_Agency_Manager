#include "Address.h"


Address::Address(){
}

Address::Address(string street, unsigned short doorNumber, string floor, string postalCode, string location){

  // REQUIRES IMPLEMENTATION
}

  // metodos GET


string Address::getStreet() const{

  // REQUIRES IMPLEMENTATION
}

unsigned short Address::getDoorNumber() const{

  // REQUIRES IMPLEMENTATION
}

string Address::getFloor() const{
  
  // REQUIRES IMPLEMENTATION
}

string Address::getPostalCode() const{

  // REQUIRES IMPLEMENTATION
}

string Address::getLocation() const{

  // REQUIRES IMPLEMENTATION
}


  // metodos SET

void Address::setStreet(string street){

  // REQUIRES IMPLEMENTATION
}

void Address::setDoorNumber(unsigned short doorNumber){

  // REQUIRES IMPLEMENTATION
}

void Address::setFloor(string floor){

  // REQUIRES IMPLEMENTATION
}

void Address::setPostalCode(string postalCode){

  // REQUIRES IMPLEMENTATION
}

void Address::setLocation(string  location){

  // REQUIRES IMPLEMENTATION
}

bool checkPostalCode(string &postalCode){

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




/*********************************
 * Mostrar Address
 ********************************/  

// displays an address in a nice format

ostream& operator<<(ostream& out, const Address & address){

  // REQUIRES IMPLEMENTATION

}
