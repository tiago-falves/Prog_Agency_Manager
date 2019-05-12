#include "Client.h"


Client::Client() {

	this->name = "";
	this->nif = 0;
	this->familySize = 0;
	this->address = address; //Como inicalizar isto? 
	/*Eu acho que neste tipo de cenas é literalmente como está. 
	Ao instanciar um cliente é que temos de ter um objeto (neste caso de endereço) já pronto a passsar à classe Client. 
	Julgo isso é fora do alcance da classe. Portanto: cria-se um Address address com o construtor que queremos e depois fazemos
	client.setAddress()*/
	this->travelPackIdentifiers ; // Como inicializar isto?
	this->totalPurchased = 0;
	
}
Client::Client(string clientsFileName, vector<Client> &clients) {

	readClients(clientsFileName,clients);
}


Client::Client(string name, unsigned int nif, unsigned short int familySize, Address address){
    this -> name = name;
    this -> nif = nif;
    this -> familySize = familySize;
    this -> address = address;
	//this->travelPackIdentifiers; // Como inicializar isto?
	//this->totalPurchased = 0; Acho que não precisamos de incluir estes dois já que como é um cliente não tem pacotes comprados
}



Client::Client(string name, unsigned int nif, unsigned short int familySize, Address address, vector<TravelPack> &packets, unsigned int totalPurchased) {


	this->name = name;
	this->nif = nif;
	this->familySize = familySize;
	this->address = address;
	this->travelPackIdentifiers = travelPackIdentifiers;
	this->totalPurchased = totalPurchased;
}


// GET methods

string Client::getName() const{ return name; }
  
unsigned Client::getnif() const{ return nif; }

unsigned short Client::getFamilySize() const{ return familySize; }

Address Client::getAddress() const{ return address; }

vector<int> Client::getTravelPackIdentifiers() const{ return travelPackIdentifiers; }

unsigned Client::getTotalPurchased() const{ return totalPurchased; }
  

// metodos SET
	  
void Client::setName(string name){ this -> name = name; }

void Client::setNif(unsigned int nif) { this->nif = nif; }

void Client::setFamilySize(unsigned short int familySize){ this -> familySize = familySize; }

void Client::setAddress(Address address){ this -> address = address; }

void Client::setTravelPackIdentifiers(vector<int> &travelPackIdentifiers){ this ->travelPackIdentifiers = travelPackIdentifiers; }

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
				client.setAddress(Address::addressTextConverter(clientsText));
				break;
			case 4:

				//client.setTravelPackIdentifiers(separateCharacterInt(clientsText, ';'));

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

//Adds client to clientsVector

void Client::addClient(vector<Client> &clientsVector, Client client) {
	clientsVector.push_back(client);
}

//Copies client to copy

void Client::copyClient(Client &copy, Client client) {
	copy.name = client.name;
	copy.address = client.address;
	copy.familySize = client.familySize;
	copy.nif = client.nif;
	copy.travelPackIdentifiers = client.travelPackIdentifiers;
}


//Removes clientToRemove from clientsVector

void Client::removeClient(Client clientToRemove, vector<Client> &clientsVector) {
	Client client;

	int last_pos = clientsVector.size() - 1;
	for (int i = 0; i < clientsVector.size(); i++)
	{
		copyClient(client, clientsVector[i]);
		if (equalClients(clientToRemove, client)) {
			copyClient(clientsVector[i], clientsVector[last_pos]);
			clientsVector.pop_back();
			break;
		}
	}
}

// Modify Client client
void Client::modifyClient(Client clientToModify, vector<Client> &clientVector, Client client) {
	for (int i = 0; i < clientVector.size(); i++)
	{
		if (equalClients(clientToModify, clientVector[i])) {
			copyClient(clientVector[i], client);
			break;
		}
	}
}

// Returns True if the client is in the Vector
bool Client::clientInVector(vector<Client> clientsVector, Client client) { //Como substiruir aqui de modo a que fique client.clientsinVector(vetor)?? ou seja chamar o proprio
	for (int i = 0; i < clientsVector.size(); i++)
	{
		if (equalClients(clientsVector[i], client)) { return true; }
	}
	return false;
}

//Returns true if the pack is valid
bool Client::validPacksBought(string packs) {
	vector<string> vector;						//separateChStr esta a dar erros!
	vector = separateCharacterStr(packs, ';');		
	for (int i = 0; i < vector.size(); i++) {
		if (!stringIsNumber(vector[i])) { return false; }
	}
	return true;
}

//Returns True if it is a valid Nif
bool Client::checknif() const
{
    bool valid = true;

    if(nif < 100000000 || nif > 999999999) // The number has to be 9 digits long    
        valid = false;

    return valid;
}

//Transforms the client.travelpacks in a string separated by ';'
string Client::travelPacksToString(vector<int> travelPacks) {
	string textPacks = "";
	for (int i = 0; i < travelPacks.size(); i++)
	{
		textPacks += to_string(travelPacks[i]) + " ; ";
	}
	textPacks = textPacks.substr(0, textPacks.size() - 3);
	return textPacks;
}


//Returns True if Clients are equal SUBSTITUIR POR OVERIDE DE ==
bool Client::equalClients(Client client1, Client client2) {
	if (Address::equalsAddresses(client1.address, client2.address) && client1.familySize == client2.familySize && client1.name == client1.name && client1.nif == client2.nif && client1.travelPackIdentifiers == client2.travelPackIdentifiers)
		return true;
	else
		return false;
}


void Client::showClient() const 
{
    cout << "*********************************" << endl;
	cout << "Name:" << name << endl;
    cout << "NIF: " << nif << endl;
    cout << "Family Size: " << familySize << endl;
    cout << "Address: " << endl;
	address.showAddress();
    cout << "TravelPacks: " << endl;
	//travelPackIdentifiers.showTravelPacks();
    cout << "Total Value: " << totalPurchased << endl;
	cout << "*********************************" << endl;
}


//ostream& operator<<(ostream& out, const Client &client){
//    out << "*********************************" << endl << "Name:" << client.name << endl << "VAT Number: " << client.nif << endl
//    << "Family Size: " << client.familySize << endl << "Address: " << client.address << endl << "TravelPacks: " << client.travelPackIdentifiers << endl
//    << "Total Value: " << client.totalPurchased << endl << "*********************************" << endl;
//    return out;
//}

bool operator==(const Client &client1, const Client &client2) {
	return client1.name == client2.name && client1.nif == client2.nif && client1.familySize == client2.familySize && client1.address == client2.address && client1.travelPackIdentifiers == client2.travelPackIdentifiers && client1.totalPurchased == client2.totalPurchased;
}

