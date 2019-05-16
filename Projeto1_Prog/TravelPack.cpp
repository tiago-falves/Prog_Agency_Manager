#include "TravelPack.h"

TravelPack::TravelPack()
{
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

void TravelPack::setLastPackId(int lastPackId) { this->lastPackId = lastPackId; }


//Reads the Travel Pack file and puts its information into a class
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
				travelPack.setLastPackId(stoi(travelPackText));
				break;
			case 1:
				travelPack.setId(stoi(travelPackText));
				break;
			case 2:
				travelPack.setTouristicSpots(TravelPack::separatedDestination(travelPackText)); 
				break;
			case 3:
				travelPack.setBeginDate(Date::dateTextConverter(travelPackText));
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
		if (travelPackToRemove == travelPack)
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
		if (travelPackToModify == travelPackVector[i]) {
			travelPackVector[i] = travelPack;
			break;
		}
	}
}

//True if Travel Packs are equal
bool TravelPack::equalTravelPacks(TravelPack travelPack1, TravelPack travelPack2) {
	if (travelPack1.id == travelPack2.id  && travelPack1.begin.isEqualTo(travelPack2.begin) && travelPack1.end.isEqualTo( travelPack2.end) && travelPack1.pricePerPerson == travelPack2.pricePerPerson && travelPack1.maxPersons == travelPack2.maxPersons && travelPack1.soldTicketsNumber == travelPack2.soldTicketsNumber && travelPack1.touristicSpots == travelPack2.touristicSpots)
		return true;
	else
		return false;
}

//True if TravelPack is in vector 
bool TravelPack::travelPackInVector(vector<TravelPack> travelPackVector, TravelPack travelPack) {
	for (int i = 0; i < travelPackVector.size(); i++)
	{
		if (travelPackVector[i] == travelPack) { return true; }
	}
	return false;
}

//Separate the touristic spots in a vector, being the first element the city
vector<string> TravelPack::separatedDestination(string destinations) {
	vector<string> destinationVector1;
	vector<string> destinationVector;
	vector<string> destinationVector2;
	if (destinations.find_first_of('-') == destinations.npos){
		destinationVector.push_back(destinations);
		return destinationVector;
	}

	destinationVector = separateCharacterStr(destinations, '-');
	destinationVector1 = separateCharacterStr(destinationVector[1], ',');
	destinationVector2.push_back(destinationVector[0]);
	destinationVector2.insert(destinationVector2.end(), destinationVector1.begin(), destinationVector1.end());
	return destinationVector2;
}

//Converts the destinations vector to a string
string TravelPack::destinationToString(vector<string> destinationVector) {
	string destinations = destinationVector[0];
	if (destinationVector.size() == 1)
		return destinations;
	destinations += " -";
	for (int i = 1; i < destinationVector.size(); i++)
		destinations += " " + destinationVector[i] + ",";
	destinations.pop_back();
	return destinations;
}


/*********************************
 * Show TravelPack information
 ********************************/  

void TravelPack::showTravelPack() const {
	cout << "*********************************" << endl;
	cout << "ID: " << abs(id) << endl; // Est� a mostrar o valor absoluto mas internamente � representado por um signed, portanto n�o se perde a informa��o da disponibilidade do pacote
	cout << "Touristic Spots: " << TravelPack::destinationToString(touristicSpots) << endl;
	cout << "Begin Date: ";
	begin.showDate();
	cout << "End Date: ";
	end.showDate();
	cout << "Price per Person: " << pricePerPerson << endl;
	cout << "Total Number of Travel Packs: " << maxPersons << endl;
	cout << "Sold Tickets: " << soldTicketsNumber << endl;
	cout << "*********************************" << endl;
}

//Order Travel Packs by most visited
vector<string> TravelPack::orderDestinations(vector<TravelPack> travelPackVector) {

	map<string, int> mapDestinations;
	vector<string> places;

	for (int i = 0; i < travelPackVector.size(); i++)
		mapDestinations[travelPackVector[i].getTouristicSpots()[0]] += travelPackVector[i].getSoldTicketsNumber();

	for (const auto &element : mapDestinations)
		places.push_back(element.first);

	sort(places.begin(), places.end(), [mapDestinations](string s1, string s2) {
		return (mapDestinations.at(s1) > mapDestinations.at(s2)) || (mapDestinations.at(s1) == mapDestinations.at(s2) && s1 <= s2);
	});

	return places;

}

bool operator==(const TravelPack & travelpack1, const TravelPack & travelpack2)
{
	return travelpack1.getId() == travelpack2.getId() && travelpack1.getTouristicSpots() == travelpack2.getTouristicSpots() && travelpack1.getBeginDate() == travelpack2.getBeginDate() && travelpack1.getEndDate() == travelpack2.getEndDate() && travelpack1.getPricePerPerson() == travelpack2.getPricePerPerson() && travelpack1.getMaxPersons() == travelpack2.getMaxPersons();

}

ostream& operator<<(ostream& out, const TravelPack &TravelPack){
	out << "ID:" << TravelPack.id << endl << "Touristic Spots: " << /*TravelPack.touristicSpots <<*/ endl << "Begin Date: " << TravelPack.begin << endl << "End Date: " << TravelPack.end << endl << "Price per Person: " << TravelPack.pricePerPerson << endl << "Packs left: " << TravelPack.maxPersons << endl;
	return out;
}

//ostream& operator<<(ostream& out, const vector<string> touristicSpots) { N�o consigo por isto a dar
//	for (int i = 0; i < touristicSpots.size(); i++)
//	{
//		out << touristicSpots.at(i) << endl;
//	}
//	return out;
//}
