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

using namespace std;





int main() {
	Agency agency;
	Client client;
	vector<Client> clientsVector;
	vector<TravelPack> travelPackVector;
	string x = "10 ; 36 ; 2";
	
	
	readAgency(agency);
	readClients(agency, clientsVector);
	readTravelPacks(agency, travelPackVector);
	
	

	
	//travelPackVector = readTravelPacks(agency, travelPackVector);


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
	*/
	addClient(clientsVector, "Joao", 2, 4, "Rua Sopa/ 200 / 5Esq / 1200‐001 / Porto", "10 ; 36 ; 2");
	addClient(clientsVector, "Joao", 2, 4, "Rua Sopa/ 200 / 5Esq / 1200‐001 / Porto", "10 ; 36 ; 2");
	cout << clientsVector.size();
	client.name = "Joao";
	client.NIF = 2;
	client.familyNumber = 4;
	client.address = addressTextConverter("Rua Sopa/ 200 / 5Esq / 1200‐001 / Porto");
	client.touristicPacksIdentifier = separateCharacter(x, ';');
	cout << equalClients(clientsVector[2], clientsVector[3]);
	removeClient(client, clientsVector);
	cout << clientsVector.size();
	
	

	/*Testar agencia
	cout << agency.address.street;
	cout << agency.address.doorNumber;
	cout << agency.address.floorNumber;
	cout << agency.address.locality << endl;*/

	/*Testar TravelPacks
	cout << travelPackVector[3].touristicSpots;
	addTravelPack(travelPackVector, 7, "Gosto de sopa", "2100 / 08 / 1", "2019 / 08 / 01", 5, 100, 5);
	addTravelPack(travelPackVector, 7, "Gosto de sopa", "2100 / 08 / 1", "2019 / 08 / 01", 5, 100, 5);

	*/
	

	system("Pause");
}