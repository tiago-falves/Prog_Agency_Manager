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
void readTravelPacks(Agency agency, vector<TravelPack> &travelPacksVector);
void addTravelPack(vector<TravelPack> &travelPackVector, int identifier, string touristicSpots, string begginningDate, string endDate, int pricePerson, int maxNumber, int soldTickets);
