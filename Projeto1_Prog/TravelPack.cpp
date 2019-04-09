#include "TravelPack.h"

using namespace std;

//Reads the Travel Pack file and puts its information into a struct
void readTravelPacks(Agency agency, vector<TravelPack> &travelPacksVector) {

	string travelPackText;
	ifstream travelPacksFile;
	TravelPack travelPack;


	int i = 0;
	travelPacksFile.open(agency.packsNameFile);
	if (travelPacksFile.fail())
	{
		cout << "Error opening " << agency.packsNameFile;
	}
	else
	{
		while (getline(travelPacksFile, travelPackText))
		{
			switch (i)
			{
			case 0:
				travelPack.lastPackIdentifier = stoi(travelPackText);
				break;
			case 1:
				travelPack.identifier = stoi(travelPackText);
				break;
			case 2:
				travelPack.touristicSpots = travelPackText; 
				break;
			case 3:
				travelPack.beginningDate = dateTextConverter(travelPackText);
				break;
			case 4:
				travelPack.endDate = dateTextConverter(travelPackText);
				break;
			case 5:
				travelPack.PricePerson = stoi(travelPackText);
				break;
			case 6:
				travelPack.maxPersonNumber = stoi(travelPackText);
				break;
			case 7:
				travelPack.soldTicketsNumber = stoi(travelPackText);
				break;
			case 8:
				i = 0;
				travelPacksVector.push_back(travelPack);
				break;
			default:
				break;
			}
			i++;
		}
	}
	travelPacksVector.push_back(travelPack);
	travelPacksFile.close();
}
// Add a Travel Pack to travelPackVector
//void addTravelPack(vector<TravelPack> &travelPackVector, int identifier, string touristicSpots, string begginningDate, string endDate, int pricePerson, int maxNumber, int soldTickets) {
void addTravelPack(vector<TravelPack> &travelPackVector, TravelPack travelPack) {
	/*TravelPack travelPack;
	travelPack.identifier = identifier;
	travelPack.touristicSpots = touristicSpots;
	travelPack.beginningDate = dateTextConverter(begginningDate);
	travelPack.endDate = dateTextConverter(endDate);
	travelPack.PricePerson = pricePerson;
	travelPack.maxPersonNumber = maxNumber;
	travelPack.soldTicketsNumber = soldTickets;*/
	travelPackVector.push_back(travelPack);
}

// Copy Travel Pack travelPack to copy
void copyTravelPack(TravelPack &copy, TravelPack travelPack) {
	copy.identifier = travelPack.identifier;
	copy.touristicSpots = travelPack.touristicSpots;
	copy.beginningDate = travelPack.beginningDate;
	copy.endDate = travelPack.endDate;
	copy.PricePerson = travelPack.PricePerson;
	copy.maxPersonNumber = travelPack.maxPersonNumber;
	copy.soldTicketsNumber = travelPack.soldTicketsNumber;
}

//True if Travel Packs are equal, False otherwise
bool equalTravelPacks(TravelPack travelPack1, TravelPack travelPack2) {
	//&&	travelPack1.touristicSpots == travelPack2.touristicSpots
	if (travelPack1.identifier == travelPack2.identifier  && equalDates(travelPack1.beginningDate,travelPack2.beginningDate) && equalDates(travelPack1.endDate,travelPack2.endDate) && travelPack1.PricePerson == travelPack2.PricePerson && travelPack1.maxPersonNumber == travelPack2.maxPersonNumber && travelPack1.soldTicketsNumber == travelPack2.soldTicketsNumber)
		return true;
	else
		return false;
}

//Removes travelPackRemove from travelPackVector
void removeTravelPack(TravelPack travelPackToRemove, vector<TravelPack> &travelPackVector) {
	TravelPack travelPack;
	int last_pos = travelPackVector.size() - 1;
	for (int i = 0; i < travelPackVector.size(); i++)
	{
		copyTravelPack(travelPack, travelPackVector[i]);
		if (equalTravelPacks(travelPackToRemove, travelPack))
		{
			copyTravelPack(travelPackVector[i], travelPackVector[last_pos]);                                                                      
			travelPackVector.pop_back();
			break;
		}
	}
}

//void modifyTravelPack(TravelPack travelPackToModify, vector<TravelPack> &travelPackVector, int identifier, string touristicSpots, Date begginningDate, Date endDate, int pricePerson, int maxNumberPerson, int ticketsSold) {
void modifyTravelPack(TravelPack travelPackToModify, vector<TravelPack> &travelPackVector, TravelPack travelPack) {
	for (int i = 0; i < travelPackVector.size(); i++)
	{
		if (equalTravelPacks(travelPackToModify,travelPackVector[i])){
			copyTravelPack(travelPackVector[i], travelPack);
			break;
		}
	}
}

bool travelPackInVector(vector<TravelPack> travelPackVector, TravelPack travelPack) {
	for (int i = 0; i < travelPackVector.size(); i++)
	{
		if (equalTravelPacks(travelPackVector[i], travelPack)) { return true; }
	}
	return false;
}
