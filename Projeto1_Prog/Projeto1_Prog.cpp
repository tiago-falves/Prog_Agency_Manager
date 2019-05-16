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

	//Alterar a fun�ao is after para um overload do >
	//O IDENTIFICADOR DOS PACKS N�O DEVE SER ATRIBUIDO AUTOMATICAMENTE? TIPO ADICIONAR UM AO ID DO ULTIMO PACKS ADICIONADO
	//CORRIGIR OS OPERATOR OVERLOADING E DESCOMENTAR (T�CNICA DO FOR)
	//VERIFICAR A DATA DE FORMA MELHOR (EX: M�S DE FEVEREIRO COM MAIS DE 29 DIAS)

	//ORDENAR DE MODO A SER MAIS EFICIENTE? - Vemos isto no fim, mesmo antes de comentar o c�digo
	//ADICIONAR AS CENAS DA AGENCY DO PROF SE HOUVER TEMPO
	

	system("Pause");
	return 0;
}
