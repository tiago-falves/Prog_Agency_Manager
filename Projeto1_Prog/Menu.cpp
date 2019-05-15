#include "Menu.h"
#include "ClientsMenu.h"
#include "TravelPackMenu.h"
using namespace std;

//Runs the main Menu
void runMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency) {
	int option;

	agency.showAgency();
	cout << "Welcome to the NiceHolidays Packs and Clients Manager! Here you can choose what you want to manage" << endl << endl;
	cout << "Please choose what your option:" << endl << endl;
	
	cout << "0. Exit" << endl;
	cout << "1. Clients" << endl;
	cout << "2. Touristic Packs" << endl;
	cout << "3. Save information and Exit" << endl << endl;
	cout << "Insert the number correspondent to your option: ";
	cin >> option;

	while (cin.fail() || option < 0 || option > 3)
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
	else if (option == 2) {runTravelPackMenu(clientsVector, travelPacksVector,agency); }
	else if (option == 3) { saveAndExit(clientsVector, travelPacksVector, agency); }
}

//Outputs a separator made of *
void menuSeparator() {
	cout << endl << endl;
	for (int i = 0; i < 60; i++) { cout << "*"; }
	cout << endl;
	for (int i = 0; i < 60; i++) { cout << "*"; }
	cout << endl << endl;
}

//Exists the program and saves the information to new files: "ClientsOutput.txt" and "TravelPackOutput.txt"
void saveAndExit(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency) {
	string content;
	ofstream clientsFile("ClientsOutput.txt");

	for (int i = 0; i < clientsVector.size(); i++)
	{
		content += clientsVector[i].getName() + "\n";
		content += to_string(clientsVector[i].getnif()) + "\n";
		content += to_string(clientsVector[i].getFamilySize()) + "\n";
		content += clientsVector[i].getAddress().getStreet() + " / " + to_string( clientsVector[i].getAddress().getDoorNumber()) + " / " + clientsVector[i].getAddress().getFloor() + " / " + clientsVector[i].getAddress().getLocation()  + "\n";
		for (int j = 0; j < clientsVector[i].getTravelPackIds().size(); j++) {
			content += to_string(clientsVector[i].getTravelPackIds()[j]) + " ; ";
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
