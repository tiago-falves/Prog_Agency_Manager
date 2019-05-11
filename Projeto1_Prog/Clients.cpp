#include "Client.h"


Client::Client() {

	this->name = "";
	this->nif = 000000000;
	this->familySize = 0;
	this->address = address; //Como inicalizar isto?
	this->TravelPacks ; // Como inicializar isto?
	this->totalPurchased = 0;
	
}
Client::Client(string clientsFileName,vector<Client> &clients) {

	readClients(clientsFileName,clients);
}


Client::Client(string name, unsigned int nif, unsigned short int familySize, Address address){
    this -> name = name;
    this -> nif = nif;
    this -> familySize = familySize;
    this -> address = address;
	this->TravelPacks; // Como inicializar isto?
	this->totalPurchased = 0;
	//
}



Client::Client(string name, unsigned int nif, unsigned short int familySize, Address address, vector<TravelPack>& TravelPacks, unsigned int totalPurchased){

	this->name = name;
	this->nif = nif;
	this->familySize = familySize;
	this->address = address;
	this->TravelPacks = TravelPacks;
	this->totalPurchased = totalPurchased;
}


// GET methods

string Client::getName() const{ return name; }
  
unsigned Client::getnif() const{ return nif; }

unsigned short Client::getFamilySize() const{ return familySize; }

Address Client::getAddress() const{ return address; }

vector<TravelPack> Client::getTravelPackList() const{ return TravelPacks; }

unsigned Client::getTotalPurchased() const{ return totalPurchased; }
  

// metodos SET
	  
void Client::setName(string name){ this -> name = name; }

void Client::setNif(unsigned int nif) { this->nif = nif; }

void Client::setFamilySize(unsigned short int familySize){ this -> familySize = familySize; }

void Client::setAddress(Address address){ this -> address = address; }

void Client::setTravelPackList(vector<TravelPack> &TravelPacks){ this -> TravelPacks = TravelPacks; }

void Client::setTotalPurchased(unsigned int totalPurchased){ this -> totalPurchased = totalPurchased; }
  

//Read Clients File

void Client::readClients(string clientsNameFile, vector<Client> &clientsVector) {

	string clientsText;
	ifstream clientsFile;
	Client client;

	int i = 0;
	clientsFile.open(clientsNameFile);
	if (clientsFile.fail())
	{
		cout << "Error opening " << clientsNameFile;
	}
	else
	{
		while (getline(clientsFile, clientsText))
		{
			switch (i)
			{
			case 0:
				client.setName(clientsText);
				break;
			case 1:
				client.setNif(stoi(clientsText));
				break;
			case 2:
				client.setFamilySize(stoi(clientsText));
				break;
			case 3:
				client.setAddress( Address::addressTextConverter(clientsText));
				break;
			case 4:
				//client.setTravelPackList(separateCharacterInt(clientsText, ';'));
				break;
			case 5:
				i = -1;
				clientsVector.push_back(client);
				break;
			default:
				break;
			}
			i++;
		}
	}
	clientsVector.push_back(client);
	clientsFile.close();
}




//Returns True if it is a valid Nif
bool Client::checknif() const
{
    bool valid = true;

    if(nif < 100000000 || nif > 999999999) // The number has to be 9 digits long    
        valid = false;

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
