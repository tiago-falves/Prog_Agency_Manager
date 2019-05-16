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
	

	//Testar

	//DATE

	//Date date;
	//Date date1(10, 12 , 1867);
	//Date date2("10/13/210");
	//cout << date2.getYear() << endl;
	//cout << date2.getMonth() << endl;
	//cout << date2.toString()<< endl;
	//cout << date1.toString()<< endl;
	//cout << date2.isValid() << endl;
	//cout << date2.daysInMonth(10,2019) << endl;
	//if (date2.isEqualTo(date1))
	//	cout << "Iguais" << endl; 
	//else
	//	cout << "Não sao iguais" << endl;
	////date2 = date1; 
	//cout << date2.isAfter(date1) << endl;
	//date2.showDate();
	//cout << date2.getYear() << endl;
	//cout << (date1 == date2) << endl;



	//AGENCY

	//Agency agency("agency.txt");
	//cout << agency.getName() << endl;
	//cout << agency.getClientsNameFile() << endl;
	//cout << agency.getNif() << endl;
	//agency.setName("Gosto");
	//cout << agency.getName() << endl;
	//cout << agency.getAddress().getStreet() << endl;
	//cout << agency << endl;


	//ADDRESS

	//Address adress("zas",123,"2esq","4509-321","Porto");
	//Address adress1("zas", 123, "2esq", "4509-321", "Porto");
	//Address address2("zas/123/2esq/4509-321/Porto");

	//cout << adress.getStreet() << endl;
	//cout << adress.getFloor() << endl;
	//cout << adress.getDoorNumber() << endl;
	//cout << adress.getPostalCode() << endl;
	//cout << adress.getLocation() << endl;
	//cout << ".........................................";
	//cout << address2.getStreet() << endl;
	//cout << address2.getFloor() << endl;
	//cout << address2.getDoorNumber() << endl;
	//cout << address2.getPostalCode() << endl;
	//cout << address2.getLocation() << endl;

	//cout << (adress == adress1) << endl;
	//cout << (adress == address2) << endl;
	
	//Address adress("zas",123,"2esq","4509-321","Porto");
	//Address adress1("zas", 123, "2esq", "4509-321", "Porto");
	//cout << adress.getFloor() << endl;
	//cout << (adress1 == adress);


	//Client
	/*Agency agency;
	vector<Client> clients;
	agency.readAgency("agency.txt");

	Client client(agency.getClientsNameFile(),clients);
	cout << clients[0].getName() << endl;
	cout << clients[0].getAddress().getStreet() << endl;
	cout << clients[0].getnif() << endl;
	//cout << clients[0].getTravelPackList()[0] << endl;

	cout << clients[1].getName() << endl;
	cout << clients[1].getAddress().getStreet() << endl;
	cout << clients[1].getnif() << endl;

	Address adress1("zas", 123, "2esq", "4509-321", "Porto");
	Client client1("Gosto",111111111,4,adress1);
	Client client2("Sopa", 111111111, 4, adress1);
	cout << client1.getName();
	client1 = client2;
	cout << client1.getName();

	cout << clients.size();
	cout << clients[1].getFamilySize();*/

	// TRAVEL PACKS
	//vector<TravelPack> travelPacks;
	//vector<string> spots;
	//Date date1;
	//Date date2;
	//Date date3(5, 5, 2016);
	//spots.push_back("Gosto");
	//TravelPack travelPack(0,spots,date1,date2,0,0,0);
	//TravelPack travelPack2(2,spots,date3,date3,2,2,2);
	//
	//cout << travelPack.getId() << endl;
	//cout << travelPack.getEndDate().getDay() << endl;
	//cout << travelPack.getMaxPersons() << endl;
	//cout << "------------------------" << endl;
	//travelPack = travelPack2;
	//cout << travelPack.getId() << endl;
	//cout << travelPack.getEndDate().getDay() << endl;
	//cout << travelPack.getMaxPersons() << endl;
	//cout << "------------------------" << endl;
	//
	//cout << travelPack.getMaxPersons();
	//TravelPack travelPack1("packs.txt",travelPacks);
	//cout << travelPacks[0].getId() << endl;
	//cout << travelPacks[0].getEndDate().getDay() << endl;
	//cout << travelPacks[0].getMaxPersons() << endl;

	//cout << (travelPack == travelPack2) << endl;
	//cout << travelPack << endl;

	//TravelPack travelPack1(spots,date1,date2,0,0,0);
	//TravelPack travelPack("packs.txt", travelPacks);


	//vector<string> destinations = separateCharacterStr("Madeira - Funchal, Porto Santo", '-');
	//for (int i = 0; i < destinations.size(); i++) {
	//	cout << destinations.at(i) << endl;
	//}


	/*destinations = TravelPack::separatedDestination("Madeira - Funchal, Porto Santo");
	cout << destinations.size();*/

	
system("Pause");
return 0;
}
