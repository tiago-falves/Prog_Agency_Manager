#include <iostream>
#include<string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Agency.h"
#include "Address.h"
#include "Clients.h"

using namespace std;



struct Date {
	int startingDate; //   year/month/day;
	int endDate;
	
};
struct TravelPack {
	const string separator = "::::::::::";
	string identifier;
	vector<string> touristicSpotsList;
	Date date;
	double PricePerson;
	int maxPersonNumber;

};






int main() {
	Agency agency;
	Client client;
	vector<Client> clientsVector;
	
	
	readAgency(agency);
	clientsVector = readClients(agency, clientsVector);
	//cout << clientsVector[1].name;
	//cout << clientsVector[1].address.locality;
	//cout << clientsVector[1].familyNumber;
	//cout << clientsVector[1].NIF;
	//cout << clientsVector[1].totalValue;
	cout << clientsVector[1].touristicPacksIdentifier;
	
	//cout << agency.address.street;
	//cout << agency.address.doorNumber;
	//cout << agency.address.floorNumber;
	//cout << agency.address.locality << endl;
	

	system("Pause");
}