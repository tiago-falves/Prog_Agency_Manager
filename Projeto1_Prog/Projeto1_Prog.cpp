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
	//VERIFICAR SE AS FUNCIONALIDADES TODAS FUNCIONAM!
	//Poder alterar um pacote para ficar negativo
	//ALTERAR FUNÇAO IS AFTER DO DATE PARA OVERLOAD DE > - se houver tempo
	//ORDENAR DE MODO A SER MAIS EFICIENTE? - Vemos isto no fim, mesmo antes de comentar o código	

	system("Pause");
	return 0;
}
