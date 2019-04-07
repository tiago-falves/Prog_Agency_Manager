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

void addTravelPack(vector<TravelPack> &travelPackVector, int identifier, string touristicSpots, string begginningDate, string endDate, int pricePerson, int maxNumber, int soldTickets) {
	TravelPack travelPack;
	travelPack.identifier = identifier;
	travelPack.touristicSpots = touristicSpots;
	travelPack.beginningDate = dateTextConverter(begginningDate);
	travelPack.endDate = dateTextConverter(endDate);
	travelPack.PricePerson = pricePerson;
	travelPack.maxPersonNumber = maxNumber;
	travelPack.soldTicketsNumber = soldTickets;
	travelPackVector.push_back(travelPack);
}
