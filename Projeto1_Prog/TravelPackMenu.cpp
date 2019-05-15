#include "TravelPackMenu.h"

void runTravelPackMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency) {
	int option;

	cout << "Welcome to the Touristic Packs Menu! Please choose what you want to do: ";
	cout << endl << endl;
	cout << "0. Go back" << endl;
	cout << "1. Create a new touristic pack." << endl;
	cout << "2. Change a touristic pack." << endl;
	cout << "3. Remove a touristic pack" << endl;
	cout << "4. See information from touristic packs. " << endl;
	cout << "5. Total profit." << endl << endl;
	
	cout << "Insert the number correspondent to your option: ";
	cin >> option;


	while (cin.fail() || option < 0 || option > 5)
	{
		cout << "Invalid option, please insert the option again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}
	menuSeparator();

	if (option == 0) { runMenu(clientsVector, travelPacksVector, agency); }
	if (option == 1) { createTravelPackOption(travelPacksVector); }
	if (option == 2) { modifyTravelPackOption(travelPacksVector); }
	if (option == 3) { removeClientOption(travelPacksVector); }
	if (option == 4) { showTravelPacks( travelPacksVector,clientsVector); }
	if (option == 5) { calculateNumberPacks ( travelPacksVector); }
	runMenu(clientsVector, travelPacksVector, agency);
}


// Opens the See Touristic Packs options
void showTravelPacks(vector<TravelPack> &travelPacksVector,vector<Client> &clientsVector) {
	int option;
	cout << "Please choose what you want to see: ";
	cout << endl << endl;

	cout << "0. Go back" << endl;
	cout << "1. See information from all touristic packs. " << endl;
	cout << "2. See information from touristic packs between two dates. " << endl;
	cout << "3. See information from touristic packs to a certain destination. " << endl;
	cout << "4. See information from touristic packs to a certain destination and between two dates. " << endl ;
	cout << "5. See information from all the sold touristic packs. " << endl << endl;

	cout << "Insert the number correspondent to your option: ";
	cin >> option;
	while (cin.fail() || (option < 0 && option > 5))
	{
		cout << "Invalid option, please insert the option again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}

	if (option == 0) { return; }
	if (option == 1) { showAllTravelPacks(travelPacksVector); }
	if (option == 2) { showAllTravelPacksByDate(travelPacksVector); }
	if (option == 3) { showAllTravelPacksByDestination(travelPacksVector); }
	if (option == 4) { showAllTravelPacksByDateDestination(travelPacksVector); }
	if (option == 5) { showSoldTouristicPacks (travelPacksVector,clientsVector); }

}

// Outputs all the sold touristic packs
void showSoldTouristicPacks(vector<TravelPack> travelPacksVector, vector<Client> clientsVector) {
	menuSeparator();
	bool inTravelPack = false;
	int c;
	for (int i = 0; i < clientsVector.size(); i++)
	{
		cout << "Client " << i + 1 << endl << endl ;
		for (int j = 0; j < clientsVector[i].getTravelPackIds().size(); j++) {
			inTravelPack = false;

			for (int k = 0; k < travelPacksVector.size(); k++)
			{
				if (travelPacksVector[k].getId() == clientsVector[i].getTravelPackIds()[j] || travelPacksVector[k].getId() == -clientsVector[i].getTravelPackIds()[j]) {
					inTravelPack = true;
					c = k;
					break;
				}
			}
			if (inTravelPack)
			{
				travelPacksVector[c].showTravelPack();
				cout << endl;
			}
			else
			{
				cout << "getId(): " << clientsVector[i].getTravelPackIds()[j] << " Not in the database" << endl;
			}
		}
	}
	menuSeparator();
}

// Asks the user for a new Travel pack information and adds it to the travelPackVector
void createTravelPackOption(vector<TravelPack> &travelPackVector) {
	TravelPack travelPack;
	cout << "Please insert the data of your new Touristic Pack" << endl << endl;
	travelPack = askForTravelPacks(true,travelPackVector);
	TravelPack::addTravelPack(travelPackVector, travelPack);
	cout << endl << endl << "Touristic Pack created successfully!";
	menuSeparator();
}

//Asks the user for a new Travel pack information and substitutes it for the old one
void modifyTravelPackOption(vector<TravelPack> &travelPackVector) {
	TravelPack travelPackToModify;
	TravelPack modifiedTravelPack;

	cout << "Please insert the data of the Touristic Pack you want to modify" << endl << endl;
	travelPackToModify = askForTravelPacksgetId(travelPackVector);

	cout << endl << endl << "Insert the new informations about the Touristic Pack: " << endl << endl;
	modifiedTravelPack = askForTravelPacks(true,travelPackVector);
	//Perguntar porque que Ele aqui pergunta o name duas vezes
	TravelPack::modifyTravelPack(travelPackToModify, travelPackVector, modifiedTravelPack);
	cout << endl << endl << "Touristic Pack modified successfully!";
	menuSeparator();
}

//Asks the user for the Travel pack he wants to remove, and removes it from the vector
void removeClientOption(vector<TravelPack> &travelPackVector) {
	TravelPack travelPack;
	cout << "Please insert the data of the touristic pack you want to remove" << endl << endl;
	travelPack = askForTravelPacksgetId(travelPackVector);
	TravelPack::removeTravelPack(travelPack, travelPackVector);
	cout << endl << endl << "Touristic Pack removed successfully!";
	menuSeparator();
}

TravelPack askForTravelPacksgetId(vector<TravelPack> travelPackVector) {
	int identifier;
	bool inDatabase = false;
	cout << "identifier: ";
	cin >> identifier;
	validCin(identifier);
	cin.clear();
	cin.ignore(10000, '\n');

	for (int i = 0; i < travelPackVector.size(); i++)
	{
		if (travelPackVector[i].getId() == identifier){ return travelPackVector[i]; }
	}

	
	while (!inDatabase)
	{
		cout << "Identifier not in the database, please insert again: ";
		cin >> identifier;
		validCin(identifier);
		cin.clear();
		cin.ignore(10000, '\n');
		for (int i = 0; i < travelPackVector.size(); i++)
		{
			if (travelPackVector[i].getId() == identifier) { return travelPackVector[i]; }
		}
	}
}

//Function which asks the user for a TravelPack informations and stores the information in a TravelPack struct
TravelPack askForTravelPacks(bool isCreatingTravelPack, vector<TravelPack> travelPackVector) {
	TravelPack travelPack;

	int identifier;
	string touristicSpots;
	string begginningDateText;
	string endDateText;
	int pricePerson;
	int maxPersonNumber;
	int soldTicketsNumber;
	bool validId = true;

	cout << "Identifier: ";
	cin >> identifier;
	validCin(identifier);
	if (isCreatingTravelPack)
	{
		do
		{
			for (int i = 0; i < travelPackVector.size(); i++)
			{
				if (identifier == travelPackVector[i].getId())
				{
					cout << "Identifier already in the database, please insert again: ";
					cin >> identifier;
					validCin(identifier);
					cin.clear();
					validId = false;
					break;
				}
			}
			validId = true;
		} while (!validId);
	}
	
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Touristic Spots (Main touristic destination - main touristic spots): ";
	getline(cin, touristicSpots);

	cout << "Begginning date(xx/xx/xxxx): ";
	cin.clear();
	getline(cin, begginningDateText);

	while (!Date::validDateText(begginningDateText))
	{
		cout << "Invalid date, please insert again: ";
		getline(cin, begginningDateText);
	}

	cout << "End date (xx/xx/xxxx): ";
	cin.clear();
	getline(cin, endDateText);

	while (!Date::validDateText(endDateText))
	{
		cout << "Invalid date, please insert again: ";
		getline(cin, endDateText);
	}


	cout << "Price per person: ";
	cin >> pricePerson;
	validCin(pricePerson);
	cin.clear();
	cin.ignore(10000, '\n');
	

	cout << "Max number of people: ";
	cin >> maxPersonNumber;
	validCin(maxPersonNumber);
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "Sold tickets: ";
	cin >> soldTicketsNumber;
	validCin(soldTicketsNumber);
	while (maxPersonNumber < soldTicketsNumber)
	{
		cout << "Invalid sold tickets number, please insert again: ";
		cin >> soldTicketsNumber;
		validCin(soldTicketsNumber);
	}
	cin.clear();
	cin.ignore(10000, '\n');

	travelPack.setId(identifier);
	travelPack.setTouristicSpots(TravelPack::separatedDestination( touristicSpots));
	travelPack.setBeginDate(Date::dateTextConverter(begginningDateText));
	travelPack.setEndDate(Date::dateTextConverter(endDateText));
	travelPack.setPricePerPerson(pricePerson);
	travelPack.setMaxPersons(maxPersonNumber);
	travelPack.setSoldTicketsNumber(soldTicketsNumber);

	return travelPack;
}

//Shows all the Travel Packs
void showAllTravelPacks(vector<TravelPack> travelPackVector) {
	menuSeparator();

	for (int i = 0; i < travelPackVector.size(); i++)
	{
		cout << "Touristic Pack " << i + 1 << ":" << endl;
		travelPackVector[i].showTravelPack();
		cout << endl << endl;
	}
	menuSeparator();
}

//Shows all the Travel Packs between two dates
void showAllTravelPacksByDate(vector<TravelPack> travelPackVector) {
	menuSeparator();
	string begginningDateText;
	string endDateText;
	Date begginningDate;
	Date endDate;

	do
	{
		cout << "Please insert the beggining date: ";
		cin >> begginningDateText;
	} while (!Date::validDateText(begginningDateText));
	begginningDate = Date::dateTextConverter(begginningDateText);

	do
	{
		cout << "Please insert the end date: ";
		cin >> endDateText;
	} while (!Date::validDateText(endDateText));

	endDate = Date::dateTextConverter(endDateText);

	cout << endl << endl;
	for (int i = 0; i < travelPackVector.size(); i++)
	{
		if (travelPackVector[i].getBeginDate().isAfter(begginningDate) && endDate.isAfter(travelPackVector[i].getEndDate()))
		{
			cout << "Touristic Pack " << i + 1 << ":" << endl;
			travelPackVector[i].showTravelPack();
			cout << endl << endl;
		}
	}
	menuSeparator();
}


//Show a certain Touristic Pack information
void showTravelPack(TravelPack travelPack) {
	
	cout << "Identifier: " << travelPack.getId() << endl; 
	cout << "Touristic spots: " << TravelPack::destinationToString(travelPack.getTouristicSpots()) << endl;
	cout << "Beggining date: " << travelPack.getBeginDate().getDay() << "/" << travelPack.getBeginDate().getMonth() << "/" << travelPack.getBeginDate().getYear() << endl;
	cout << "End date: " << travelPack.getEndDate().getDay() << "/" << travelPack.getEndDate().getMonth() << "/" << travelPack.getEndDate().getYear() << endl;
	cout << "Price per person: " << travelPack.getPricePerPerson() << endl;
	cout << "Maximum number of people: " << travelPack.getMaxPersons()<< endl;
	cout << "Sold Tickets number: " << travelPack.getSoldTicketsNumber() << endl;

}

void showAllTravelPacksByDestination(vector<TravelPack> travelPackVector) {

	menuSeparator();
	string destination;
	vector<string> destVector;
	
	cout << "Please insert the destination: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, destination);
	
	cout << endl << endl;
	cout << TravelPack::destinationToString(travelPackVector[0].getTouristicSpots());
	for (int i = 0; i < travelPackVector.size(); i++)
	{																
		if (travelPackVector[i].getTouristicSpots()[0] == TravelPack::separatedDestination(destination)[0])
		{
			cout << "Touristic Pack " << i + 1 << ":" << endl;
			showTravelPack(travelPackVector[i]);
			cout << endl << endl;
		}
	}
	menuSeparator();
}

//Shows all the Travel Packs with a certain destination
void showAllTravelPacksByDateDestination(vector<TravelPack> travelPackVector) {

	menuSeparator();
	string begginningDateText;
	string endDateText;
	string destination;
	Date begginningDate;
	Date endDate;

	do
	{
		cout << "Please insert the beggining date: ";
		cin >> begginningDateText;
	} while (!Date::validDateText(begginningDateText));
	begginningDate = Date::dateTextConverter(begginningDateText);

	do
	{
		cout << "Please insert the end date: ";
		cin >> endDateText;
	} while (!Date::validDateText(endDateText));

	endDate = Date::dateTextConverter(endDateText);

	cout << "Please insert the destination: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, destination);

	cout << endl << endl;
	for (int i = 0; i < travelPackVector.size(); i++)
	{													
		if (travelPackVector[i].getBeginDate().isAfter(begginningDate) && endDate.isAfter(travelPackVector[i].getEndDate()) && (travelPackVector[i].getTouristicSpots()[0] == TravelPack::separatedDestination(destination)[0]))
		{
			cout << "Touristic Pack " << i + 1 << ":" << endl;
			showTravelPack(travelPackVector[i]);
			cout << endl << endl;
		}
	}
	menuSeparator();
}

//Outputs the total profit and number of tickets
void calculateNumberPacks(vector<TravelPack> travelPackVector) {
	cout << "The Total profit is: ";
	int price=0;
	int number=0;
	for (int i = 0; i < travelPackVector.size(); i++)
	{
		number += travelPackVector[i].getSoldTicketsNumber();
		price += travelPackVector[i].getPricePerPerson() * travelPackVector[i].getSoldTicketsNumber();
	}
	cout << price <<"$" << endl;
	cout << "Number of tickets sold: " << number;

	menuSeparator();

}