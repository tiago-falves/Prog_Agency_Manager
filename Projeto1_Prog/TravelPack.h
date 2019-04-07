#pragma once
#include <string>
#include <vector>
#include "Date.h"
#include "Agency.h"
#include <iostream>
using namespace std;

struct TravelPack {
	int lastPackIdentifier;
	int identifier;
	string touristicSpots;
	Date beginningDate;
	Date endDate;
	int PricePerson;
	int maxPersonNumber;
	int soldTicketsNumber;
	const string separator = "::::::::::";
};
vector<TravelPack> readTravelPacks(Agency agency, vector<TravelPack> travelPacksVector);
