#include <iostream>
#include<string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Agency.h"
#include "Address.h"
#include "Clients.h"
#include "TravelPack.h"
#include "Date.h"
#include "TravelPack.h"
#include "Menu.h"

using namespace std;





int main() {
	Agency agency;
	Client client,client1,client2;
	vector<Client> clientsVector;
	vector<TravelPack> travelPackVector;
	string x = "10 ; 36 ; 2";

	readAgency(agency);
	readClients(agency, clientsVector);
	readTravelPacks(agency, travelPackVector);
	runMenu();
	

	


	//Testar Data
	//cout << travelPackVector[0].lastPackIdentifier;
	//cout << travelPackVector[1].identifier;
	//cout << travelPackVector[1].touristicSpots;
	//cout << travelPackVector[1].beginningDate.day;
	//cout << travelPackVector[1].endDate.year;
	//cout << travelPackVector[2].PricePerson;
	//cout << travelPackVector[1].maxPersonNumber;
	//cout << travelPackVector[1].soldTicketsNumber;
	


	/*Testar Clients

	cout << clientsVector[1].name;
	cout << clientsVector[1].address.locality;
	cout << clientsVector[1].familyNumber;
	cout << clientsVector[1].NIF;
	cout << clientsVector[1].totalValue;
	cout << clientsVector[1].touristicPacksIdentifier[2];

	client.name = "Joao";
	client.NIF = 2;
	client.familyNumber = 4;
	client.address = addressTextConverter("Rua Sopa/ 200 / 5Esq / 1200‐001 / Porto");
	client.touristicPacksIdentifier = separateCharacter(x, ';');

	client2.name = "Joao";
	client2.NIF = 2;
	client2.familyNumber = 4;
	client2.address = addressTextConverter("Rua GOSTO DE SOPA/ 200 / 5Esq / 1200‐001 / Porto");
	client2.touristicPacksIdentifier = separateCharacter(x, ';');
	
	cout << clientsVector.size() << endl;
	addClient(clientsVector, client);
	cout << clientsVector[2].address.street;
	cout << clientsVector.size() << endl;
	copyClient(client1, client);
	addClient(clientsVector, client1);
	cout << clientsVector[3].address.street;
	cout << clientsVector.size() << endl;
	removeClient(client, clientsVector);
	cout << clientsVector.size() << endl;
	modifyClient(client1, clientsVector, client2);
	cout << clientsVector[2].address.street;*/

	

	
	
	

	/*Testar agencia
	cout << agency.address.street;
	cout << agency.address.doorNumber;
	cout << agency.address.floorNumber;
	cout << agency.address.locality << endl;*/

	/*Testar TravelPacks
	TravelPack travelPack;
	TravelPack travelPack1;

	travelPack.identifier = 10;
	travelPack.touristicSpots = "SOPA";
	travelPack.beginningDate = dateTextConverter("2001/01/01");
	travelPack.endDate = dateTextConverter("2001/01/02");
	travelPack.PricePerson = 1;
	travelPack.maxPersonNumber = 69;
	travelPack.soldTicketsNumber = 69;

	travelPack1.identifier = 10;
	travelPack1.touristicSpots = "GOSTO DE SOPA";
	travelPack1.beginningDate = dateTextConverter("2001/01/01");
	travelPack1.endDate = dateTextConverter("2001/01/02");
	travelPack1.PricePerson = 1;
	travelPack1.maxPersonNumber = 69;
	travelPack1.soldTicketsNumber = 69;

	cout << travelPackVector.size() << endl;
	addTravelPack(travelPackVector, travelPack);
	cout << travelPackVector.size() << endl;
	copyTravelPack(travelPack, travelPackVector[3]);
	travelPackVector.push_back(travelPack);
	cout << travelPackVector.size() << endl;
	removeTravelPack(travelPack, travelPackVector);
	cout << travelPackVector.size() << endl;
	cout << travelPackVector[3].touristicSpots << endl;
	modifyTravelPack(travelPack, travelPackVector, travelPack1);
	cout << travelPackVector[3].touristicSpots;*/
	
	

	system("Pause");
}