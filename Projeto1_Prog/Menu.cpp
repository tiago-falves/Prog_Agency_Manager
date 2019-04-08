#include "Menu.h"
#include "ClientsMenu.h"
using namespace std;


void runMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector) {

	int option;

	cout << "Welcome to the NiceHolidays Packs and Clients Manager! Here you can choose what you want to manage" << endl << endl;
	
	cout << "Please choose what your option:" << endl << endl;
	
	
	cout << "0. Clients" << endl << endl;
	cout << "1. Touristic Packs" << endl << endl;
	cout << "Insert the number correspondent to your option: ";
	cin >> option;

	while (cin.fail() || (option != 0 && option != 1))
	{
		cout << "Invalid option, please insert the option again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}
	menuSeparator();

	if (option == 0) {runClientsMenu(clientsVector); }
	else if (option == 1) { runTouristicPacksMenu(); }
}

void menuSeparator() {
	cout << endl << endl;
	for (int i = 0; i < 60; i++) { cout << "*"; }
	cout << endl;
	for (int i = 0; i < 60; i++) { cout << "*"; }
	cout << endl << endl;
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

void runTouristicPacksMenu() {

}