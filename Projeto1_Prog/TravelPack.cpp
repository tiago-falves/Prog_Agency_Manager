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

void TravelPack::setlastPackId(int lastPackId) { this->lastPackId = lastPackId; }




//Reads the Travel Pack file and puts its information into a class
void TravelPack::readTravelPacks(string filename , vector<TravelPack> &travelPacksVector) {

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
				travelPack.setlastPackId(stoi(travelPackText));
				break;
			case 1:
				travelPack.setId(stoi(travelPackText));
				break;
			case 2:
				travelPack.setTouristicSpots(TravelPack::separatedDestination(travelPackText)); 
				break;
			case 3:
				travelPack.setBeginDate(Date::dateTextConverterFile(travelPackText));
				break;
			case 4:
				travelPack.setEndDate(Date::dateTextConverterFile(travelPackText));
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
void TravelPack::addTravelPack(vector<TravelPack> &travelPackVector) {
	travelPackVector.push_back(*this);
}

//Removes travelPackRemove from travelPackVector
void TravelPack::removeTravelPack(vector<TravelPack> &travelPackVector) {
	TravelPack travelPack;
	int last_pos = travelPackVector.size() - 1;
	for (int i = 0; i < travelPackVector.size(); i++)
	{
		travelPack = travelPackVector[i];
		if ((id == travelPackVector[i].getId() || id == -travelPackVector[i].getId()))
		{
			travelPackVector.erase(travelPackVector.begin() + i);
			break;
		}
	}
}
//Substitute travelPackToModify for travelPack
void TravelPack::modifyTravelPack(vector<TravelPack> &travelPackVector, TravelPack travelPack) {
	for (int i = 0; i < travelPackVector.size(); i++)
	{
		if (id == travelPackVector[i].getId() || id == -travelPackVector[i].getId()) {
			travelPackVector[i] = travelPack;
			break;
		}
	}
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
	bool available = true;
	if (id < 0) { available = false; }
	
	cout << "*********************************" << endl;
	cout << "ID: " << abs(id) << " (Pack is "; // Está a mostrar o valor absoluto mas internamente é representado por um signed
	
	if (available) { cout << "available) " << endl; }
	else { cout << "not available) " << endl; }
	
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
	out << "ID:" << TravelPack.id << endl;
	for (int i = 0; i < TravelPack.touristicSpots.size(); i++){
		out << "Touristic Spot " << i << " : " << TravelPack.touristicSpots[i] << endl;
	} 
	out << "Begin Date: " << TravelPack.begin << endl;
	out << "End Date: " << TravelPack.end << endl;
	out << "Price per Person: " << TravelPack.pricePerPerson << endl;
	out << "Packs left: " << TravelPack.maxPersons << endl;
	return out;
}