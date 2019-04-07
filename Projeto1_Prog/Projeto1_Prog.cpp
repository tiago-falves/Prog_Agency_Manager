#include <iostream>
#include<string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Agency.h"
#include "Address.h"

using namespace std;


struct Client {
	const string separator = "::::::::::";
	string name;
	int NIF;
	int familyNumber;
	Address address;
	string touristicPacksIdentifier;
	double totalValue;

};

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
	readAgency(agency);
	cout << agency.name;
	cout << agency.address.postalCode << endl;
	system("Pause");
}