#include "TravelPack.h"

using namespace std;

vector<TravelPack> readTravelPacks(Agency agency, vector<TravelPack> travelPacksVector) {

	string travelPackText;
	ifstream travelPacksFile;
	TravelPack travelPack;


	int i = 0;
	travelPacksFile.open(agency.packsNameFile);
	if (travelPacksFile.fail())
	{
		cout << "Error opening " << agency.packsNameFile;
		return travelPacksVector;
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
	return travelPacksVector;
}
