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
#include "Menu.h"
#include "TravelPackMenu.h"

using namespace std;


int main() {

	Agency agency;
	Client client,client1,client2;
	vector<Client> clientsVector;
	vector<TravelPack> travelPackVector;

	readAgency(agency);
	readClients(agency, clientsVector);
	readTravelPacks(agency, travelPackVector);
	runMenu(clientsVector,travelPackVector,agency);
	cout << "Hello";


	system("Pause");
}