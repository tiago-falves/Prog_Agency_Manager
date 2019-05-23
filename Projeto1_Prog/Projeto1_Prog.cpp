#include <iostream>
#include <string>
#include <vector>

#include "Agency.h"
#include "Menu.h"
#include "TravelPackMenu.h"
#include "ClientsMenu.h"


void runAgencyManager() {
	Agency agency;
	vector<Client> clientsVector;
	vector<TravelPack> travelPackVector;

	agency.readAgency("agency.txt");
	Client::readClients(agency.getClientsNameFile(), clientsVector);
	TravelPack::readTravelPacks(agency.getPacksNameFile(), travelPackVector);

	runMenu(clientsVector, travelPackVector, agency);
}

int main() {

	runAgencyManager();
	//ALTERAR FUN�AO IS AFTER DO DATE PARA OVERLOAD DE > - se houver tempo

	system("Pause");
	return 0;
}
