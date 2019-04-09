#include "ClientsMenu.h"
#include "Clients.h"
using namespace std;

void runClientsMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector){
	int option;


	cout << "Welcome to the Clients Menu! Please choose what you want to do: ";
	cout << endl << endl;
	cout << "0. Create a new client." << endl;
	cout << "1. Change a client information." << endl;
	cout << "2. Remove a client" << endl;
	cout << "3. See information from all clients. " << endl << endl;
	cout << "Insert the number correspondent to your option: ";
	cin >> option;
	

	while (cin.fail() || (option != 0 && option != 1 && option != 2 && option != 3))
	{
		cout << "Invalid option, please insert the option again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}
	menuSeparator();

	if (option == 0) { createClientOption(clientsVector);}
	if (option == 1) { modifyClientOption(clientsVector);}
	if (option == 2) { removeClientOption(clientsVector);}
	if (option == 3) { showAllClients(clientsVector);}

	runMenu(clientsVector, travelPacksVector);
	

}


// Show information from all clients
void showAllClients(vector<Client> clientsVector){
	
	for (int i = 0; i < clientsVector.size(); i++)
	{
		cout << "Client " << i + 1 << ":" << endl;
		showClient(clientsVector[i]);
		cout << endl << endl;
	}
	menuSeparator();
}
//Show a certain client information
void showClient(Client client) {
	
	cout << "Name: " <<client.name << endl;
	cout << "NIF: " << client.NIF << endl;
	cout << "Number of people in the family: " << client.familyNumber << endl;
	cout << "Address: " << client.address.street << " / " << client.address.doorNumber << " / " << client.address.floorNumber << " / " << client.address.postalCode << " / " << client.address.locality << endl;
	cout << "Tourist Packs bought: " << travelPacksToString(client.touristicPacksIdentifier);
	
}

//Asks for Client information and returns a Client
Client askForClientsInformation() {
	Client client;

	string name;
	int nif;
	int familyNumber;
	string addressText;
	string touristicPacksBought;

	

	cout << "Name: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, name);

	cout << "NIF: ";
	cin >> nif;
	validCin(nif);
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "Number of people in the family: ";
	cin >> familyNumber;
	validCin(familyNumber);
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "Address (Street / Door Number / Floor Number / Postal Code / Locality): ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, addressText);

	while (!validAddressText(addressText))
	{
		cout << "Invalid address, please insert again: ";
		getline(cin, addressText);
	}

	cout << "Tourist Packs bought (separated by ';'): ";
	getline(cin, touristicPacksBought);

	while (!validPacksBought(touristicPacksBought))
	{
		cout << "Invalid Touristic Pack, please insert again: ";
		getline(cin, touristicPacksBought);
	}

	client.name = name;
	client.NIF = nif;
	client.familyNumber = familyNumber;
	client.address = addressTextConverter(addressText);
	client.touristicPacksIdentifier = separateCharacterInt(touristicPacksBought, ';');

	return client;

}

void createClientOption(vector<Client> &clientsVector) {
	Client client;
	cout << "Please insert the data of your new client" << endl << endl;
	copyClient(client, askForClientsInformation());
	addClient(clientsVector, client);
	cout << endl << endl << "Client created successfully!";
	menuSeparator();
}

void modifyClientOption(vector<Client> &clientsVector) {
	Client clientToModify;
	Client modifiedClient;

	cout << "Please insert the data of the client you want to modify" << endl << endl;
	copyClient(clientToModify, askForClientsInformation());

	while (!clientInVector(clientsVector, clientToModify))
	{
		cout << "The Client is not in the database, please insert the data again" << endl << endl;
		copyClient(clientToModify, askForClientsInformation());
	}

	cout << endl << endl << "Insert the new informations about the client: " << endl << endl;
	copyClient(modifiedClient, askForClientsInformation());
	//Perguntar porque que Ele aqui pergunta o name duas vezes
	modifyClient(clientToModify, clientsVector, modifiedClient);
	cout << endl << endl << "Client modified successfully!";
	menuSeparator();
}

void removeClientOption(vector<Client> &clientsVector) {
	Client client;
	cout << "Please insert the data of the client you want to remove" << endl << endl;
	copyClient(client, askForClientsInformation());
	while (!clientInVector(clientsVector, client))
	{
		cout << "The Client is not in the database, please insert the data again" << endl << endl;
		copyClient(client, askForClientsInformation());
	}
	removeClient(client, clientsVector);
	cout << endl << endl << "Client removed successfully!";
	menuSeparator();
}