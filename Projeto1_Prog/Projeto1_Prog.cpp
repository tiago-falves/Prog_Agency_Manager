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

	//Atribuir o lastPackId e aumenta-lo automaticamente?

	//Alterar a funçao is after para um overload do >
	//O IDENTIFICADOR DOS PACKS NÃO DEVE SER ATRIBUIDO AUTOMATICAMENTE? TIPO ADICIONAR UM AO ID DO ULTIMO PACKS ADICIONADO
	//CORRIGIR OS OPERATOR OVERLOADING E DESCOMENTAR (TÉCNICA DO FOR)
	//VERIFICAR A DATA DE FORMA MELHOR (EX: MÊS DE FEVEREIRO COM MAIS DE 29 DIAS)

	//ORDENAR DE MODO A SER MAIS EFICIENTE? - Vemos isto no fim, mesmo antes de comentar o código
	//ADICIONAR AS CENAS DA AGENCY DO PROF SE HOUVER TEMPO
	

	system("Pause");
	return 0;
}
