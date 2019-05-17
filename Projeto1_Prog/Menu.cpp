#include "Menu.h"
#include "ClientsMenu.h"
#include "TravelPackMenu.h"
using namespace std;

//Runs the main Menu
void runMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency) {
	int option;

	cout << agency << endl;

	cout << "Welcome to the NiceHolidays Packs and Clients Manager! Here you can choose what you want to manage" << endl << endl;
	cout << "Please choose what your option:" << endl << endl;
	
	cout << "0. Exit" << endl;
	cout << "1. Clients" << endl;
	cout << "2. Touristic Packs" << endl;
	cout << "3. Statistics" << endl;
	cout << "4. Save information and Exit" << endl << endl;
	cout << "Insert the number correspondent to your option: ";
	cin >> option;

	while (cin.fail() || option < 0 || option > 4)
	{
		cout << "Invalid option, please insert the option again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}
	cin.clear();
	cin.ignore(10000, '\n');
	menuSeparator();

	if (option == 0) { exit(0);}
	else if (option == 1) {runClientsMenu(clientsVector,travelPacksVector,agency); }
	else if (option == 2) {runTravelPackMenu(clientsVector, travelPacksVector, agency); }
	else if (option == 3) {runStatisticsMenu(clientsVector, travelPacksVector, agency); }
	else if (option == 4) {saveAndExit(clientsVector, travelPacksVector, agency); }
}

//Outputs a separator made of *
void menuSeparator() {
	cout << endl << endl;
	for (int i = 0; i < 60; i++) { cout << "*"; }
	cout << endl;
	for (int i = 0; i < 60; i++) { cout << "*"; }
	cout << endl << endl;
}

//Exists the program and saves the information to new files: "clients.txt" and "packs.txt"
void saveAndExit(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency) {
	string content;
	ofstream clientsFile("clients.txt");

	for (int i = 0; i < clientsVector.size(); i++)
	{
		content += clientsVector[i].getName() + "\n";
		content += to_string(clientsVector[i].getnif()) + "\n";
		content += to_string(clientsVector[i].getFamilySize()) + "\n";
		content += clientsVector[i].getAddress().getStreet() + " / " + to_string(clientsVector[i].getAddress().getDoorNumber()) + " / " + clientsVector[i].getAddress().getFloor() + " / " + clientsVector[i].getAddress().getPostalCode() + " / " + clientsVector[i].getAddress().getLocation() + "\n";
		for (int j = 0; j < clientsVector[i].getTravelPackIds().size(); j++) {
			content += to_string(clientsVector[i].getTravelPackIds()[j]) + " ; ";
		}
		content += "\n";
		content += to_string(clientsVector[i].getTotalPurchased()) + "\n";
		content.erase(content.find_last_of(" ; ") - 2, 3);
		if (i != clientsVector.size() - 1){
			content += "::::::::::\n";
		}
	}	



	clientsFile << content;
	clientsFile.close();

	content = "";
	ofstream travelPacksFile("packs.txt");

	content += to_string(travelPacksVector[ travelPacksVector.size()-1].getId()) + '\n';
	for (int i = 0; i < travelPacksVector.size(); i++)
	{
		content += to_string(travelPacksVector[i].getId()) + '\n';
		content += TravelPack::destinationToString(travelPacksVector[i].getTouristicSpots()) + '\n'; 
		content += to_string(travelPacksVector[i].getBeginDate().getYear()) + "/" + to_string(travelPacksVector[i].getBeginDate().getMonth()) + "/" + to_string(travelPacksVector[i].getBeginDate().getDay()) + '\n'; // Isto não devia estar ao contrário
		content += to_string(travelPacksVector[i].getEndDate().getYear()) + "/" + to_string(travelPacksVector[i].getEndDate().getMonth()) + "/" + to_string(travelPacksVector[i].getEndDate().getDay()) + '\n';
		content += to_string((int)travelPacksVector[i].getPricePerPerson()) + '\n';
		content += to_string(travelPacksVector[i].getMaxPersons()) + '\n';
		content += to_string(travelPacksVector[i].getSoldTicketsNumber()) + '\n';

		if (i != travelPacksVector.size() - 1)
		{
			content += "::::::::::\n";
		}
	}
	travelPacksFile << content;
	travelPacksFile.close();
	exit(0);
}


//Asks for a valid int until the user inputs it
void validCin(int &option) {
	
	while (cin.fail())
	{
		cout << "Invalid input, please insert your answer again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}
}

void runStatisticsMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency) {
	int option;

	cout << "Welcome to the Statistics Menu! Please choose what you want to do: ";
	cout << endl << endl;
	cout << "0. Go back" << endl;
	cout << "1. See information from all clients with recommendations. " << endl;
	cout << "2. See most visited destinations." << endl << endl;
	cin >> option;

	while (cin.fail() || option < 0 || option > 2)
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
	if (option == 1) { showAllClientsWithRecommendations(clientsVector, travelPacksVector); }
	if (option == 2) { showOrderedDestinations(TravelPack::orderDestinations(travelPacksVector)); }

	runMenu(clientsVector, travelPacksVector, agency);
}