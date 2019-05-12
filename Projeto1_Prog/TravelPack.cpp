#include "TravelPack.h"

TravelPack::TravelPack()
{
	Date begin;
	Date end;

	this->touristicSpots = {};
	this->begin = begin;
	this->end = end;
	this->pricePerPerson = 0;
	this->maxPersons = 0;
	this->soldTicketsNumber = 0;
}

TravelPack::TravelPack(string fileName, vector<TravelPack> &travelPacksVector)
{
	readTravelPacks(fileName,travelPacksVector);
}

TravelPack::TravelPack(int getId(),vector<string> touristicSpots, Date begin, Date end, double pricePerPerson, unsigned maxPersons, int soldTicketsNumber){
	
	this->id = getId();
	this->touristicSpots = touristicSpots;
	this->begin = begin;
	this->end = end;
	this->pricePerPerson = pricePerPerson;
	this->maxPersons = maxPersons;
	this->soldTicketsNumber = soldTicketsNumber;

}

 //GET methods

int TravelPack::getId() const { return id; }

vector<string> TravelPack::getTouristicSpots() const { return touristicSpots; }

Date TravelPack::getBeginDate() const { return begin; }

Date TravelPack::getEndDate() const { return end; }

double TravelPack::getPricePerPerson() const { return pricePerPerson; }

unsigned TravelPack::getMaxPersons() const { return maxPersons; }

int TravelPack::getSoldTicketsNumber() const { return soldTicketsNumber; }

//SET methods

void TravelPack::setId(unsigned id){ this->id = id; }

void TravelPack::setTouristicSpots(vector<string> touristicSpots){ this->touristicSpots = touristicSpots; }

void TravelPack::setBeginDate(Date begin) { this->begin = begin; }

void TravelPack::setEndDate(Date end) { this->end = end; }

void TravelPack::setPricePerPerson(double pricePerPerson) { this->pricePerPerson = pricePerPerson; }

void TravelPack::setMaxPersons(unsigned maxPersons){ this->maxPersons = maxPersons; }

void TravelPack::setSoldTicketsNumber(int soldTicketsNumber) { this->soldTicketsNumber = soldTicketsNumber; }

void TravelPack::setLastPackgetId()(int lastPackgetId()) { this->lastPackgetId() = lastPackgetId(); }


//Reads the Travel Pack file and puts its information into a struct
void TravelPack::readTravelPacks(string filename, vector<TravelPack> &travelPacksVector) {

	string travelPackText;
	ifstream travelPacksFile;
	TravelPack travelPack;


	int i = 0;
	travelPacksFile.open(filename);
	if (travelPacksFile.fail())
	{
		cout << "Error opening " << filename;
	}
	else
	{
		while (getline(travelPacksFile, travelPackText))
		{
			switch (i)
			{
			case 0:
				travelPack.setLastPackgetId()(stoi(travelPackText));
				break;
			case 1:
				travelPack.setId(stoi(travelPackText));
				break;
			case 2:
				//travelPack.setTouristicSpots(travelPackText);
				break;
			case 3:
				travelPack.setBeginDate( Date::dateTextConverter(travelPackText));
				break;
			case 4:
				travelPack.setEndDate(Date::dateTextConverter(travelPackText));
				break;
			case 5:
				travelPack.setPricePerPerson(stoi(travelPackText));
				break;
			case 6:
				travelPack.setMaxPersons(stoi(travelPackText));
				break;
			case 7:
				travelPack.setSoldTicketsNumber(stoi(travelPackText));
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
void TravelPack::addTravelPack(vector<TravelPack> &travelPackVector, TravelPack travelPack) {
	travelPackVector.push_back(travelPack);
}

//Removes travelPackRemove from travelPackVector
void TravelPack::removeTravelPack(TravelPack travelPackToRemove, vector<TravelPack> &travelPackVector) {
	TravelPack travelPack;
	int last_pos = travelPackVector.size() - 1;
	for (int i = 0; i < travelPackVector.size(); i++)
	{
		travelPack = travelPackVector[i];
		if (equalTravelPacks(travelPackToRemove, travelPack))
		{
			travelPackVector[i] = travelPackVector[last_pos];
			travelPackVector.pop_back();
			break;
		}
	}
}
//Substitute travelPackToModify for travelPack
void TravelPack::modifyTravelPack(TravelPack travelPackToModify, vector<TravelPack> &travelPackVector, TravelPack travelPack) {
	for (int i = 0; i < travelPackVector.size(); i++)
	{
		if (equalTravelPacks(travelPackToModify, travelPackVector[i])) {
			travelPackVector[i] = travelPack;
			break;
		}
	}
}

//True if Travel Packs are equal, False otherwise
bool TravelPack::equalTravelPacks(TravelPack travelPack1, TravelPack travelPack2) {
	if (travelPack1.id == travelPack2.id  &&travelPack1.begin.isEqualTo(travelPack2.begin) && travelPack1.end.isEqualTo( travelPack2.end) && travelPack1.pricePerPerson == travelPack2.pricePerPerson && travelPack1.maxPersons == travelPack2.maxPersons && travelPack1.soldTicketsNumber == travelPack2.soldTicketsNumber && travelPack1.touristicSpots == travelPack2.touristicSpots)
		return true;
	else
		return false;
}

//True if TravelPack is in vector 
bool TravelPack::travelPackInVector(vector<TravelPack> travelPackVector, TravelPack travelPack) {
	for (int i = 0; i < travelPackVector.size(); i++)
	{
		if (equalTravelPacks(travelPackVector[i], travelPack)) { return true; }
	}
	return false;
}

//Separate the touristic sopts in a vector, being the first element the city
vector<string> TravelPack::separatedDestination(string destinations) {
	vector<string> destinationVector;
	destinationVector = separateCharacterStr(destinations, '-');
	return destinationVector;
}


/*********************************
 * Show TravelPack information
 ********************************/  

// shows a TravelPack content 
/*ostream& operator<<(ostream& out, const TravelPack & TravelPack){

  // REQUIRES IMPLEMENTATION
}*/
