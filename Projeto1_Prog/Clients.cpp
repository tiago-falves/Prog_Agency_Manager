#include "Client.h"


Client::Client() {
	Address address;
	this->name = "";
	this->nif = 0;
	this->familySize = 0;
	this->address = address; 
	this->travelPackIds;
	this->totalPurchased = 0;
	
}
Client::Client(string clientsFileName, vector<Client> &clients) {

	readClients(clientsFileName, clients);
}


Client::Client(string name, unsigned int nif, unsigned short int familySize, Address address){
    this -> name = name;
    this -> nif = nif;
    this -> familySize = familySize;
    this -> address = address;
}


Client::Client(string name, unsigned int nif, unsigned short int familySize, Address address, vector<TravelPack> &packets, unsigned int totalPurchased) {
	this->name = name;
	this->nif = nif;
	this->familySize = familySize;
	this->address = address;
	this->travelPackIds = travelPackIds;
	this->totalPurchased = totalPurchased;
}


// GET methods

string Client::getName() const{ return name; }
  
unsigned Client::getnif() const{ return nif; }

unsigned short Client::getFamilySize() const{ return familySize; }

Address Client::getAddress() const{ return address; }

vector<int> Client::getTravelPackIds() const{ return travelPackIds; }

unsigned Client::getTotalPurchased() const{ return totalPurchased; }
  

// metodos SET
	  
void Client::setName(string name){ this -> name = name; }

void Client::setNif(unsigned int nif) { this->nif = nif; }

void Client::setFamilySize(unsigned short int familySize){ this -> familySize = familySize; }

void Client::setAddress(Address address){ this -> address = address; }

void Client::setTravelPackIds(vector<int> &travelPackIds){ this ->travelPackIds = travelPackIds; }

void Client::setTotalPurchased(unsigned int totalPurchased){ this -> totalPurchased = totalPurchased; }
  


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
			vector<int> temporary;
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
				client.setAddress(Address::addressTextConverter(clientsText));
				break;
			case 4:
				temporary = separateCharacterInt(clientsText, ';');
				client.setTravelPackIds(temporary);
				break;
			case 5:
				client.setTotalPurchased(stoi(clientsText));
				break;
			case 6:
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


void Client::addClient(vector<Client> &clientsVector) {
	clientsVector.push_back(*this);
}


void Client::removeClient(vector<Client> &clientsVector) {
	Client client;

	int last_pos = clientsVector.size() - 1;
	for (int i = 0; i < clientsVector.size(); i++)
	{
		client = clientsVector[i];
		if (*this == client) {
			clientsVector[i] = clientsVector[last_pos];
			clientsVector.pop_back();
			break;
		}
	}
}

void Client::modifyClient(Client clientToModify, vector<Client> &clientVector) {
	for (int i = 0; i < clientVector.size(); i++)
	{
		if (clientToModify == clientVector[i]) {
			clientVector[i] = *this;		
			break;
		}
	}
	
}

bool Client::clientInVector(vector<Client> clientsVector) { 
	for (int i = 0; i < clientsVector.size(); i++)
	{
		if (clientsVector[i] == *this) { return true; }
	}
	return false;
}

bool Client::validPacksBought(string packs) {
	vector<string> vector;						
	vector = separateCharacterStr(packs, ';');		
	for (int i = 0; i < vector.size(); i++) {
		if (!stringIsNumber(vector[i])) { return false; }
	}
	return true;
}

bool Client::checknif() const
{
    bool valid = true;

    if(nif < 100000000 || nif > 999999999) // The number has to be 9 digits long    
        valid = false;

    return valid;
}

string Client::travelPacksToString(vector<int> travelPacks) {
	string textPacks = "";
	for (int i = 0; i < travelPacks.size(); i++)
	{
		textPacks += to_string(travelPacks[i]) + " ; ";
	}
	textPacks = textPacks.substr(0, textPacks.size() - 3);
	return textPacks;
}


void Client::showClient() const 
{
    cout << "*********************************" << endl;
	cout << "Name:" << name << endl;
    cout << "NIF: " << nif << endl;
    cout << "Family Size: " << familySize << endl;
    cout << "Address: " << endl;
	address.showAddress();
    cout << "TravelPacks: " <<  travelPacksToString(travelPackIds) << endl;
    cout << "Total Value: " << totalPurchased << endl;
	cout << "*********************************" << endl;
}


ostream& operator<<(ostream& out, const Client &client){
	out << "*********************************" << endl;
	out << "Name:" << client.name << endl;
	out << "VAT Number: " << client.nif << endl;
	out << "Family Size: " << client.familySize << endl;
	out << "Address: " << client.address;
	for (int i = 0; i < client.travelPackIds.size(); i++) {
		out << "TravelPack " << i << " : " << client.travelPackIds[i] << endl;
	}
	out << "Total Value: " << client.totalPurchased << endl;
	out << "*********************************" << endl;
    return out;
}

bool operator==(const Client &client1, const Client &client2) {
	return client1.getName() == client2.getName() && client1.getnif() == client2.getnif() && client1.getFamilySize() == client2.getFamilySize() && client1.getAddress() == client2.getAddress() && client1.getTravelPackIds() == client2.getTravelPackIds() && client1.getTotalPurchased() == client2.getTotalPurchased();
}

