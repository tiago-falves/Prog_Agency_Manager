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

using namespace std;





int main() {
	Agency agency;
	Client client;
	vector<Client> clientsVector;
	vector<TravelPack> travelPackVector;
	string x = "2019/08/01";
	Date v;
	
	
	
	readAgency(agency);
	clientsVector = readClients(agency, clientsVector);
	travelPackVector = readTravelPacks(agency, travelPackVector);


	//Testar Data
	cout << travelPackVector[0].lastPackIdentifier;
	cout << travelPackVector[1].identifier;
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

	/*Testar agencia
	cout << agency.address.street;
	cout << agency.address.doorNumber;
	cout << agency.address.floorNumber;
	cout << agency.address.locality << endl;*/
	

	system("Pause");
}