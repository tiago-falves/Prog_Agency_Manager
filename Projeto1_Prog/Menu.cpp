#include "Menu.h"
#include "ClientsMenu.h"
#include "TravelPackMenu.h"
using namespace std;


void runMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency) {
	int option;

	cout << "Welcome to the NiceHolidays Packs and Clients Manager! Here you can choose what you want to manage" << endl << endl;
	cout << "Please choose what your option:" << endl << endl;
	
	cout << "1. Clients" << endl;
	cout << "2. Touristic Packs" << endl;
	cout << "3. Save information and Exit" << endl << endl;
	cout << "Insert the number correspondent to your option: ";
	cin >> option;

	while (cin.fail() || (option != 1 && option != 2 && option != 3))
	{
		cout << "Invalid option, please insert the option again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}
	cin.clear();
	cin.ignore(10000, '\n');
	menuSeparator();

	if (option == 1) {runClientsMenu(clientsVector,travelPacksVector,agency); }
	else if (option == 2) {runTravelPackMenu(clientsVector, travelPacksVector,agency); }
	else if (option == 3) { saveAndExit(clientsVector, travelPacksVector, agency); }
}

void menuSeparator() {
	cout << endl << endl;
	for (int i = 0; i < 60; i++) { cout << "*"; }
	cout << endl;
	for (int i = 0; i < 60; i++) { cout << "*"; }
	cout << endl << endl;
}

void saveAndExit(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector,Agency agency) {
	string content;
	ofstream clientsFile("ClientsOutput.txt");

	for (int i = 0; i < clientsVector.size(); i++)
	{
		content += clientsVector[i].name + "\n";
		content += to_string(clientsVector[i].NIF) + "\n";
		content += to_string(clientsVector[i].familyNumber) + "\n";
		content += clientsVector[i].address.street + " / " +to_string( clientsVector[i].address.doorNumber) + " / " + clientsVector[i].address.floorNumber + " / " + clientsVector[i].address.floorNumber + " / " + clientsVector[i].address.locality  + "\n";
		for (int j = 0; j < clientsVector[i].touristicPacksIdentifier.size(); j++) {
			content += to_string(clientsVector[i].touristicPacksIdentifier[j]) + " ; ";
		}
		content.erase(content.find_last_of(" ; ") - 2, 3);
		content += "\n";
		if (i != clientsVector.size() - 1){
			content += "::::::::::\n";
		}
	}
	clientsFile << content;
	clientsFile.close();

	content = "";
	ofstream travelPacksFile("TravelPackOutput.txt");

	content += to_string(travelPacksVector.size()) + '\n';
	for (int i = 0; i < travelPacksVector.size(); i++)
	{
		content += to_string(travelPacksVector[i].identifier) + '\n';
		content += travelPacksVector[i].touristicSpots + '\n';
		content += to_string(travelPacksVector[i].beginningDate.year) + "/" + to_string(travelPacksVector[i].beginningDate.month) + "/" + to_string(travelPacksVector[i].beginningDate.day) + '\n';
		content += to_string(travelPacksVector[i].endDate.year) + "/" + to_string(travelPacksVector[i].endDate.month) + "/" + to_string(travelPacksVector[i].endDate.day) + '\n';
		content += to_string(travelPacksVector[i].PricePerson) + '\n';
		content += to_string(travelPacksVector[i].maxPersonNumber) + '\n';
		content += to_string(travelPacksVector[i].soldTicketsNumber) + '\n';

		if (i != travelPacksVector.size() - 1)
		{
			content += "::::::::::\n";
		}
	}
	travelPacksFile << content;
	travelPacksFile.close();

	exit(1);
}


void validCin(int &option) {
	while (cin.fail())
	{
		cout << "Invalid input, please insert your answer again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}
}
