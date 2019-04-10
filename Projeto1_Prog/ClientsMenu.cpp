#include "ClientsMenu.h"
#include "Clients.h"
using namespace std;

//Asks all information and asks the user what option to choose
void runClientsMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector,Agency agency){
	int option;

	cout << "Welcome to the Clients Menu! Please choose what you want to do: ";
	cout << endl << endl;
	cout << "1. Create a new client." << endl;
	cout << "2. Change a client information." << endl;
	cout << "3. Remove a client" << endl;
	cout << "4. See information from all clients. " << endl;
	cout << "5. Buy a touristic pack for a client" << endl << endl;
	cout << "Insert the number correspondent to your option: ";
	cin >> option;
	
	while (cin.fail() || (option != 1 && option != 2 && option != 3 && option != 4 && option != 5))
	{
		cout << "Invalid option, please insert the option again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}
	menuSeparator();

	if (option == 1) { createClientOption(clientsVector);}
	if (option == 2) { modifyClientOption(clientsVector);}
	if (option == 3) { removeClientOption(clientsVector);}
	if (option == 4) { showAllClients(clientsVector);}
	if (option == 5) { buyTravelPack(clientsVector, travelPacksVector);}

	runMenu(clientsVector, travelPacksVector,agency);
}

//Returns a Client of the database by inserting a NIF
Client askForNIF(vector<Client> clientsVector){
	Client client;
	int nif;
	bool inDatabase = false;
	cout << "NIF: ";
	cin >> nif;
	validCin(nif);
	cin.clear();
	cin.ignore(10000, '\n');

	for (int i = 0; i < clientsVector.size(); i++)
	{
		if (clientsVector[i].NIF == nif) { return clientsVector[i]; }
		
	}
	while (!inDatabase)
	{
		cout << "NIF not in the database, please insert again: ";
		cin >> nif;
		validCin(nif);
		cin.clear();
		cin.ignore(10000, '\n');
		for (int i = 0; i < clientsVector.size(); i++)
		{
			if (clientsVector[i].NIF == nif) { return clientsVector[i]; }
		}
	}
}

//Adds the travel pack identiier to the client, alters the bought travelPack
void buyTravelPack(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector) {
	Client client;
	int identifier;
	bool validIdentifier = false;

	cout << "Insert the Clients information you want to buy the touristic pack: " << endl;
	copyClient(client, askForNIF(clientsVector));
	
	cout << endl << "Insert the Touristic Pack identifier you want to buy: ";
	cin >> identifier;
	validCin(identifier);
	while (!validIdentifier)
	{
		for (int i = 0; i < travelPacksVector.size(); i++)
		{
			if (identifier == travelPacksVector[i].identifier && travelPacksVector[i].identifier > 0 && (travelPacksVector[i].maxPersonNumber-travelPacksVector[i].soldTicketsNumber) > 0)
			{
				validIdentifier = true;
				travelPacksVector[i].soldTicketsNumber += 1;
				if ((travelPacksVector[i].maxPersonNumber - travelPacksVector[i].soldTicketsNumber) <= 0) {
					travelPacksVector[i].identifier = -travelPacksVector[i].identifier;
				}
				cout << endl << "Touristic pack bought successfuly!" << endl;
				break;
			}
		}
		if (!validIdentifier)
		{
			cout << "Identifier not in the database, please insert again: ";
			cin >> identifier;
			validCin(identifier);
		}
	}

	for (int i = 0; i < clientsVector.size(); i++)
	{
		if (equalClients(client, clientsVector[i])) {
			clientsVector[i].touristicPacksIdentifier.push_back(identifier);
		}
	}
	menuSeparator();
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

	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Name: ";
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
	getline(cin, addressText);

	while (!validAddressText(addressText) || addressText == "////")
	{
		cout << "Invalid address, please insert again: ";
		getline(cin, addressText);
	}

	cout << "Tourist Packs bought (separated by ';'): ";
	getline(cin, touristicPacksBought);

	while (!validPacksBought(touristicPacksBought) || touristicPacksBought == "")
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

//Asks the user for data and adds a new client to clientsvector
void createClientOption(vector<Client> &clientsVector) {
	Client client;
	cout << "Please insert the data of your new client" << endl << endl;
	copyClient(client, askForClientsInformation());
	addClient(clientsVector, client);
	cout << endl << endl << "Client created successfully!";
	menuSeparator();
}

//Asks the user which client he wants to modify, and changes it
void modifyClientOption(vector<Client> &clientsVector) {
	Client clientToModify;
	Client modifiedClient;

	cout << "Please insert the data of the client you want to modify" << endl << endl;
	copyClient(clientToModify, askForNIF(clientsVector));

	cout << endl << endl << "Insert the new informations about the client: " << endl << endl;
	cin.clear();
	//cin.ignore(10000, '\n');
	copyClient(modifiedClient, askForClientsInformation());
	//Perguntar porque que Ele aqui pergunta o name duas vezes
	modifyClient(clientToModify, clientsVector, modifiedClient);
	cout << endl << endl << "Client modified successfully!";
	menuSeparator();
}

//Asks the user the nif of the client it wants to removes, and removes it from clientsVector
void removeClientOption(vector<Client> &clientsVector) {
	Client client;
	cout << "Please insert the data of the client you want to remove" << endl << endl;
	copyClient(client, askForNIF(clientsVector));
	
	removeClient(client, clientsVector);
	cout << endl << endl << "Client removed successfully!";
	menuSeparator();
}