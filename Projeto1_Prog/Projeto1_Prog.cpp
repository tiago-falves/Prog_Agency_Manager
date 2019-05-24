#include <iostream>
#include <string>
#include <vector>

#include "Agency.h"
#include "Menu.h"
#include "TravelPackMenu.h"
#include "ClientsMenu.h"


void runAgencyManager(string agencyfile) {
	Agency agency;
	vector<Client> clientsVector;
	vector<TravelPack> travelPackVector;


	agency.readAgency(agencyfile);
	Client::readClients(agency.getClientsNameFile(), clientsVector);
	TravelPack::readTravelPacks(agency.getPacksNameFile(), travelPackVector);

	runMenu(clientsVector, travelPackVector, agency);
}

int main() {
	string agencyfile;

	while (true) // Asks for file until it suceeds
	{
		cout << "Please choose the agency you want to check (the .txt file): " << endl;
		cin >> agencyfile;

		ifstream in_file;
		in_file.open(agencyfile); // Open file for testing

		if (in_file.fail())
		{
			cerr << "File not found!" << endl;

			in_file.clear();
			in_file.ignore(1000, '\n');

		}
		else
		{
			in_file.close();
			break;
		}

	}

	runAgencyManager(agencyfile);

	system("Pause");
	return 0;
}
