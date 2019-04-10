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
				client.touristicPacksIdentifier = separateCharacterInt(clientsText,';');
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

//Adds a Client to clientsVector
void addClient(vector<Client> &clientsVector,Client client) {
	clientsVector.push_back(client);
}

//Copies client to copy
void copyClient(Client &copy, Client client) {
	copy.name = client.name;
	copy.address = client.address;
	copy.familyNumber = client.familyNumber;
	copy.NIF = client.NIF;
	copy.touristicPacksIdentifier = client.touristicPacksIdentifier;
}

//Removes clientToRemove from clientsVector
void removeClient(Client clientToRemove, vector<Client> &clientsVector) {
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

// Returns True if the client is in the Vector
bool clientInVector(vector<Client> clientsVector, Client client) {
	for (int i = 0; i < clientsVector.size(); i++)
	{
		if (equalClients(clientsVector[i], client)) { return true; }
	}
	return false;
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

//Returns true if the pack is valid
bool validPacksBought(string packs) {
	vector<string> vector;
	vector = separateCharacterStr(packs, ';');
	for (int i = 0; i < vector.size(); i++)	{
		if (!stringIsNumber(vector[i])) { return false;}
	}
	return true;
}

//Transorms the client.travelpacks in a string separated by ';'
string travelPacksToString(vector<int> travelPacks) {
	string textPacks ="";
	for (int i = 0; i < travelPacks.size(); i++)
	{
		textPacks += to_string(travelPacks[i]) + " ; ";
	}
	textPacks = textPacks.substr(0, textPacks.size() - 3);
	return textPacks;
}





