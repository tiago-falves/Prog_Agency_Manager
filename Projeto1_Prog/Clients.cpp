#include "Clients.h"
#include <iostream>
using namespace std;


//Reads the file information and puts its information in a struct

void readClients(Agency agency, vector<Client> &clientsVector) {

	string clientsText;
	ifstream clientsFile;
	Client client;
	
	int i = 0;
	clientsFile.open(agency.clientsNameFile);
	if (clientsFile.fail())
	{
		cout << "Error opening " << agency.clientsNameFile;
	}
	else
	{
		while (getline(clientsFile, clientsText))
		{
			switch (i)
			{
			case 0:
				client.name = clientsText;
				break;
			case 1:
				client.NIF = stoi(clientsText);
				break;
			case 2:
				client.familyNumber = stoi(clientsText);
				break;
			case 3:
				client.address = addressTextConverter(clientsText);
				break;
			case 4:
				client.touristicPacksIdentifier = separateCharacter(clientsText,';');
				break;
			case 5:
				i=-1;
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

// Add a Client to clientsVector
//void addClient(vector<Client> &clientsVector,Client client) {
void addClient(vector<Client> &clientsVector, string name, int nif, int familyNumber, string addressText, string touristicPacksBought) {
	Client client;
	client.name = name;
	client.NIF = nif;
	client.familyNumber = familyNumber;
	client.address = addressTextConverter(addressText);
	client.touristicPacksIdentifier = separateCharacter(touristicPacksBought, ';');
	clientsVector.push_back(client);
}

//Copies client client to copy
void copyClient(Client &copy, Client &client) {
	copy.name = client.name;
	copy.address = client.address;
	copy.familyNumber = client.familyNumber;
	copy.NIF = client.NIF;
	copy.touristicPacksIdentifier = client.touristicPacksIdentifier;
}

//Removes clientToRemove from clientsVector
//void removeClient(Client clientToRemove, vector<Client> &clientsVector) {
void removeClient(vector<Client> &clientsVector, string name, int nif, int familyNumber, string addressText, string touristicPacksBought) {
	Client clientToRemove;
	Client client;
	clientToRemove.name = name;
	clientToRemove.NIF = nif;
	clientToRemove.familyNumber = familyNumber;
	clientToRemove.address = addressTextConverter(addressText);
	clientToRemove.touristicPacksIdentifier = separateCharacter(touristicPacksBought, ';');
		
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

//Returns True if Clients are equal
bool equalClients(Client client1, Client client2) {
	if (equalsAddresses(client1.address,client2.address) && client1.familyNumber == client2.familyNumber && client1.name == client1.name && client1.NIF == client2.NIF && client1.touristicPacksIdentifier == client2.touristicPacksIdentifier)
		return true;
	else
		return false;
}
// Modify Client clientTModify to client
void modifyClient(Client clientToModify, vector<Client> &clientVector, Client client) {
	for (int i = 0; i < clientVector.size(); i++)
	{
		if (equalClients(clientToModify, clientVector[i])) {
			copyClient(clientVector[i], client);
			break;
		}
	}
}






