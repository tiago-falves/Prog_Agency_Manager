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

	//ERRO ESTRANHO, AO CRIAR UM CLIENTE E AO FAZER O OUTPUT ENTRE O CODIGO POSTAL E A LOCALITY DESAPARECE A BARRA
	//ALTERAR FUNÇAO IS AFTER DO DATE PARA OVERLOAD DE >
	//MUDAR FICHEIRO DE ESCRITA

	//ORDENAR DE MODO A SER MAIS EFICIENTE? - Vemos isto no fim, mesmo antes de comentar o código	

	system("Pause");
	return 0;
}
