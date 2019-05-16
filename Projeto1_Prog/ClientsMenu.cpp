#include "ClientsMenu.h"
#include "Client.h"
using namespace std;

//Asks all information and asks the user what option to choose
void runClientsMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency){
	int option;

	cout << "Welcome to the Clients Menu! Please choose what you want to do: ";
	cout << endl << endl;
	cout << "0. Go back" << endl;
	cout << "1. Create a new client." << endl;
	cout << "2. Change a client information." << endl;
	cout << "3. Remove a client" << endl;
	cout << "4. See information from all clients. " << endl;
	cout << "5. See information from all clients with recommendations. " << endl;
	cout << "6. See from a specific client. " << endl;
	cout << "7. Buy a touristic pack for a client" << endl << endl;
	cout << "Insert the number correspondent to your option: ";
	cin >> option;
	
	while (cin.fail() || option < 0 || option > 7)
	{
		cout << "Invalid option, please insert the option again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}

	cin.clear();
	cin.ignore(10000, '\n');

	menuSeparator();

	if (option == 0) { runMenu(clientsVector, travelPacksVector, agency); }
	if (option == 1) { createClientOption(clientsVector);}
	if (option == 2) { modifyClientOption(clientsVector);}
	if (option == 3) { removeClientOption(clientsVector);}
	if (option == 4) { showAllClients(clientsVector);}
	if (option == 5) { showAllClientsWithRecommendations(clientsVector,travelPacksVector);}
	if (option == 6) { showClientOption(clientsVector);}
	if (option == 7) { buyTravelPack(clientsVector, travelPacksVector);}

	runMenu(clientsVector, travelPacksVector,agency);
}


void showClientOption(vector<Client> clientsVector) {
	showClient(askForNIF(clientsVector));
	menuSeparator();
}


//Returns a Client of the database by inserting a NIF
Client askForNIF(vector<Client> clientsVector){
	Client client;
	int nif;
	bool inDatabase = false;
	cout << "Insert Clients NIF: ";
	cin >> nif;
	validNif(nif);
	cin.clear();
	cin.ignore(10000, '\n');

	for (int i = 0; i < clientsVector.size(); i++)
	{
		if (clientsVector[i].getnif() == nif) { return clientsVector[i]; }
		
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
			if (clientsVector[i].getnif() == nif) { return clientsVector[i]; }
		}
	}
	
}

//Adds the travel pack identiier to the client, alters the bought travelPack
void buyTravelPack(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector) {
	Client client;
	int identifier;
	bool validId = false;
	int travel_pack_position;

	cout << "Insert the Clients information you want to buy the touristic pack: " << endl;
	client = askForNIF(clientsVector);
	
	cout << endl << "Insert the Touristic Pack identifier you want to buy: ";
	cin >> identifier;
	validCin(identifier);
	while (!validId)
	{
		for (int i = 0; i < travelPacksVector.size(); i++)
		{
			if (identifier == travelPacksVector[i].getId() && travelPacksVector[i].getId() > 0  )
			{
				if ((travelPacksVector[i].getMaxPersons() - travelPacksVector[i].getSoldTicketsNumber() - client.getFamilySize() + 1) > 0)
				{
				validId = true;
				travel_pack_position = i;
				cout << "BBBBBBBBBBBBBBB" << to_string(travelPacksVector[i].getSoldTicketsNumber()) << "BBBBBBBBBBBBBBBBBBBB";
				cout << "CCCCCCCCCCCCCCCC" << to_string(client.getFamilySize()) << "ccccccccccccccccccc";
				cout << "AAAAAAAAAAAAAAAAAA" << to_string(travelPacksVector[i].getSoldTicketsNumber() + client.getFamilySize()) << "AAAAAAAAAAAAAA";
				travelPacksVector[i].setSoldTicketsNumber(travelPacksVector[i].getSoldTicketsNumber() + client.getFamilySize());
				if ((travelPacksVector[i].getMaxPersons() - travelPacksVector[i].getSoldTicketsNumber()) <= 0) {
					travelPacksVector[i].setId( -travelPacksVector[i].getId());
				}
				cout << endl << "Touristic pack bought successfuly!" << endl;
				break;
				}
				else
				{
					if (!validId)
					{
						cout << "There are not enough Touristic packs! please insert a new identifier: ";
						cin >> identifier;
						validCin(identifier);
					}
				}
			}
		}
		if (!validId)
		{
			cout << "Identifier not in the database, please insert again: ";
			cin >> identifier;
			validCin(identifier);
		}
	}

	for (int i = 0; i < clientsVector.size(); i++)
	{
		if (client == clientsVector[i]) {
			vector<int> temporaryIdentifiers;
			temporaryIdentifiers = clientsVector[i].getTravelPackIds();
			temporaryIdentifiers.push_back(identifier);

			clientsVector[i].setTravelPackIds(temporaryIdentifiers);
			clientsVector[i].setTotalPurchased(client.getFamilySize() * travelPacksVector[travel_pack_position].getPricePerPerson() + client.getTotalPurchased());

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

//Outputs all clients and adds a destination as a recommendation
void showAllClientsWithRecommendations(vector<Client> clientsVector, vector<TravelPack> travelPacksVector) {
	vector<string> recommendations = TravelPack::orderDestinations(travelPacksVector);
	string recommendation ="";
	
	for (int i = 0; i < clientsVector.size(); i++)
	{
		vector<string> listPerClient = destinationsOfClient(clientsVector[i], travelPacksVector);
		
		for (int j = 0; j < recommendations.size(); j++)
		{
			if (find(listPerClient.begin(), listPerClient.end(), recommendations[j]) == listPerClient.end()) {
				recommendation = recommendations[j];
				break;
			}
		}
		cout << "Client " << i + 1 << ":" << endl;
		showClient(clientsVector[i]);

		cout << "Recomended destination: " << recommendation;
		cout << endl << endl;
		
	}
	menuSeparator();
}

//Returns a vector with all the destinations of a Client
vector<string> destinationsOfClient(Client client, vector<TravelPack> travelPacksVector) {
	vector<string> destinationsVector;
	for (int i = 0; i < client.getTravelPackIds().size(); i++)
	{
		for (int j = 0; j < travelPacksVector.size(); j++)
		{
			if (client.getTravelPackIds()[i] == travelPacksVector[j].getId() || -client.getTravelPackIds()[i] == travelPacksVector[j].getId()) {
				destinationsVector.push_back(travelPacksVector[j].getTouristicSpots()[0]);
			}
		}
	}
	return destinationsVector;
}


//Show a certain client information
void showClient(Client client) {
	
	cout << "Name: " << client.getName() << endl;
	cout << "NIF: " << client.getnif() << endl;
	cout << "Number of people in the family: " << client.getFamilySize() << endl;
	cout << "Address: " << client.getAddress().getStreet() << " / " << client.getAddress().getDoorNumber() << " / " << client.getAddress().getFloor() << " / " << client.getAddress().getPostalCode() << " / " << client.getAddress().getLocation() << endl;
	cout << "Tourist Packs bought: " << Client::travelPacksToString(client.getTravelPackIds()) << endl;
	cout << "Total spent: " << client.getTotalPurchased() << endl << endl;
	
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
	getline(cin, name);

	cout << "NIF: ";
	cin >> nif;
	validNif(nif);
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "Number of people in the family: ";
	cin >> familyNumber;
	validCin(familyNumber);
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "Address (Street / Door Number / Floor Number / Postal Code / Locality): ";
	getline(cin, addressText);

	while (!Address::validAddressText(addressText) || addressText == "////")
	{
		cout << "Invalid address, please insert again: ";
		getline(cin, addressText);
	}

	/*cout << "Tourist Packs bought (separated by ';'): ";
	getline(cin, touristicPacksBought);

	while (!Client::validPacksBought(touristicPacksBought) || touristicPacksBought == "")
	{
		cout << "Invalid Touristic Pack, please insert again: ";
		getline(cin, touristicPacksBought);
	}*/

	client.setName(name);
	client.setNif( nif);
	client.setFamilySize(familyNumber);
	client.setAddress(Address::addressTextConverter(addressText));
	return client;
}

//Asks the user for data and adds a new client to clientsvector
void createClientOption(vector<Client> &clientsVector) {
	Client client;
	cout << "Please insert the data of your new client" << endl << endl;
	client = askForClientsInformation();
	client.addClient(clientsVector);
	cout << endl << endl << "Client created successfully!";
	menuSeparator();
}

//Asks the user which client he wants to modify, and changes it
void modifyClientOption(vector<Client> &clientsVector) {
	Client clientToModify;
	Client modifiedClient;

	cout << "Please insert the data of the client you want to modify" << endl << endl;
	clientToModify = askForNIF(clientsVector);

	cout << endl << endl << "Insert the new informations about the client: " << endl << endl;
	modifiedClient = askForClientsInformation();
	//Perguntar porque que Ele aqui pergunta o name duas vezes
	modifiedClient.modifyClient(clientToModify, clientsVector);
	cout << endl << endl << "Client modified successfully!";
	menuSeparator();
}

//Asks the user the nif of the client it wants to removes, and removes it from clientsVector
void removeClientOption(vector<Client> &clientsVector) {
	Client client;
	cout << "Please insert the data of the client you want to remove" << endl << endl;
	(client = askForNIF(clientsVector));
	
	client.removeClient(clientsVector);
	cout << endl << endl << "Client removed successfully!";
	menuSeparator();
}

void validNif(int &option) {

	while (cin.fail() || option < 100000000 || option > 999999999)
	{
		cout << "Invalid NIF, please insert your answer again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}
}