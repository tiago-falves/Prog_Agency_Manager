#include "TravelPackMenu.h"

void runTravelPackMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency) {
	int option;

	cout << "Welcome to the Touristic Packs Menu! Please choose what you want to do: ";
	cout << endl << endl;
	cout << "1. Create a new touristic pack." << endl;
	cout << "2. Change a touristic pack." << endl;
	cout << "3. Remove a touristic pack" << endl;
	cout << "4. See information from touristic packs. " << endl;
	cout << "5. Total profit." << endl << endl;
	
	cout << "Insert the number correspondent to your option: ";
	cin >> option;


	while (cin.fail() || (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 ))//&& option != 5 && option != 6))
	{
		cout << "Invalid option, please insert the option again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}
	menuSeparator();

	if (option == 1) { createTravelPackOption(travelPacksVector); }
	if (option == 2) { modifyTravelPackOption(travelPacksVector); }
	if (option == 3) { removeClientOption(travelPacksVector); }
	if (option == 4) { showTravelPacks( travelPacksVector,clientsVector); }
	if (option == 5) {calculateNumberPacks ( travelPacksVector); }
	runMenu(clientsVector, travelPacksVector, agency);
}


// Opens the See Touristic Packs options
void showTravelPacks(vector<TravelPack> &travelPacksVector,vector<Client> &clientsVector) {
	int option;
	cout << "Please choose what you want to see: ";
	cout << endl << endl;

	cout << "1. See information from all touristic packs. " << endl;
	cout << "2. See information from touristic packs between two dates. " << endl;
	cout << "3. See information from touristic packs to a certain destination. " << endl;
	cout << "4. See information from touristic packs to a certain destination and between two dates. " << endl ;
	cout << "5. See information from all the sold touristic packs. " << endl << endl;

	cout << "Insert the number correspondent to your option: ";
	cin >> option;
	while (cin.fail() || (option != 1 && option != 2 && option != 3 && option != 4 && option != 5))
	{
		cout << "Invalid option, please insert the option again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}

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
		for (int j = 0; j < clientsVector[i].touristicPacksIdentifier.size(); j++) {
			inTravelPack = false;

			for (int k = 0; k < travelPacksVector.size(); k++)
			{
				if (travelPacksVector[k].identifier == clientsVector[i].touristicPacksIdentifier[j] || travelPacksVector[k].identifier == -clientsVector[i].touristicPacksIdentifier[j]) {
					inTravelPack = true;
					c = k;
					break;
				}
			}
			if (inTravelPack)
			{
				showTravelPack(travelPacksVector[c]);
				cout << endl;
			}
			else
			{
				cout << "Identifier: " << clientsVector[i].touristicPacksIdentifier[j] << " Not in the database" << endl;
			}
		}
	}
	menuSeparator();
}

// Asks the user for a new Travel pack information and adds it to the travelPackVector
void createTravelPackOption(vector<TravelPack> &travelPackVector) {
	TravelPack travelPack;
	cout << "Please insert the data of your new Touristic Pack" << endl << endl;
	copyTravelPack(travelPack, askForTravelPacks(true,travelPackVector));
	addTravelPack(travelPackVector, travelPack);
	cout << endl << endl << "Touristic Pack created successfully!";
	menuSeparator();
}

//Asks the user for a new Travel pack information and substitutes it for the old one
void modifyTravelPackOption(vector<TravelPack> &travelPackVector) {
	TravelPack travelPackToModify;
	TravelPack modifiedTravelPack;

	cout << "Please insert the data of the Touristic Pack you want to modify" << endl << endl;
	copyTravelPack(travelPackToModify, askForTravelPacksIdentifier(travelPackVector));

	cout << endl << endl << "Insert the new informations about the Touristic Pack: " << endl << endl;
	copyTravelPack(modifiedTravelPack, askForTravelPacks(true,travelPackVector));
	//Perguntar porque que Ele aqui pergunta o name duas vezes
	modifyTravelPack(travelPackToModify, travelPackVector, modifiedTravelPack);
	cout << endl << endl << "Touristic Pack modified successfully!";
	menuSeparator();
}

//Asks the user for the Travel pack he wants to remove, and removes it from the vector
void removeClientOption(vector<TravelPack> &travelPackVector) {
	TravelPack travelPack;
	cout << "Please insert the data of the touristic pack you want to remove" << endl << endl;
	copyTravelPack(travelPack, askForTravelPacksIdentifier(travelPackVector));
	removeTravelPack(travelPack, travelPackVector);
	cout << endl << endl << "Touristic Pack removed successfully!";
	menuSeparator();
}

TravelPack askForTravelPacksIdentifier(vector<TravelPack> travelPackVector) {
	int identifier;
	bool inDatabase = false;
	cout << "Identifier: ";
	cin >> identifier;
	validCin(identifier);
	cin.clear();
	cin.ignore(10000, '\n');

	for (int i = 0; i < travelPackVector.size(); i++)
	{
		if (travelPackVector[i].identifier == identifier){ return travelPackVector[i]; }
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
			if (travelPackVector[i].identifier == identifier) { return travelPackVector[i]; }
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
	bool validIdentifier = true;

	cout << "Identifier: ";
	cin >> identifier;
	validCin(identifier);
	if (isCreatingTravelPack)
	{
		do
		{
			for (int i = 0; i < travelPackVector.size(); i++)
			{
				if (identifier == travelPackVector[i].identifier)
				{
					cout << "Identifier already in the database, please insert again: ";
					cin >> identifier;
					validCin(identifier);
					cin.clear();
					//cin.ignore(10000, '\n');
					validIdentifier = false;
					break;
				}
			}
			validIdentifier = true;
		} while (!validIdentifier);
	}
	
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Touristic Spots (Main touristic destination - main toristic spots): ";
	getline(cin, touristicSpots);

	cout << "Begginning date(xxxx/xx/xx): ";
	cin.clear();
	//cin.ignore(10000, '\n');
	getline(cin, begginningDateText);

	while (!validDateText(begginningDateText))
	{
		cout << "Invalid date, please insert again: ";
		getline(cin, begginningDateText);
	}

	cout << "End date (xxxx/xx/xx): ";
	cin.clear();
	getline(cin, endDateText);

	while (!validDateText(endDateText))
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

	cout << "Sold tikets number: ";
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

	travelPack.identifier = identifier;
	travelPack.touristicSpots = touristicSpots;
	travelPack.beginningDate = dateTextConverter(begginningDateText);
	travelPack.endDate = dateTextConverter(endDateText);
	travelPack.PricePerson = pricePerson;
	travelPack.maxPersonNumber = maxPersonNumber;
	travelPack.soldTicketsNumber = soldTicketsNumber;

	return travelPack;
}

//Shows all the Travel Packs
void showAllTravelPacks(vector<TravelPack> travelPackVector) {
	menuSeparator();

	for (int i = 0; i < travelPackVector.size(); i++)
	{
		cout << "Touristic Pack " << i + 1 << ":" << endl;
		showTravelPack(travelPackVector[i]);
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
	} while (!validDateText(begginningDateText));
	copyDate(begginningDate, dateTextConverter(begginningDateText));

	do
	{
		cout << "Please insert the end date: ";
		cin >> endDateText;
	} while (!validDateText(endDateText));

	copyDate(endDate, dateTextConverter(endDateText));

	cout << endl << endl;
	for (int i = 0; i < travelPackVector.size(); i++)
	{
		if (biggerDate(travelPackVector[i].beginningDate,begginningDate) && biggerDate(endDate, travelPackVector[i].endDate))
		{
			cout << "Touristic Pack " << i + 1 << ":" << endl;
			showTravelPack(travelPackVector[i]);
			cout << endl << endl;
		}
	}
	menuSeparator();
}


//Show a certain Touristic Pack information
void showTravelPack(TravelPack travelPack) {
	
	cout << "Identifier: " << travelPack.identifier << endl;
	cout << "Touristic spots: " << travelPack.touristicSpots << endl;
	cout << "Beggining date: " <<  travelPack.beginningDate.year << "/" << travelPack.beginningDate.month << "/" << travelPack.beginningDate.day << endl;
	cout << "End date: " <<  travelPack.endDate.year << "/" << travelPack.endDate.month << "/" << travelPack.endDate.day << endl;
	cout << "Price per person: " << travelPack.PricePerson << endl;
	cout << "Maximum number of people: " << travelPack.maxPersonNumber<< endl;
	cout << "Sold Tickets number: " << travelPack.soldTicketsNumber << endl;

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
	cout << travelPackVector[0].touristicSpots;
	for (int i = 0; i < travelPackVector.size(); i++)
	{
		if (separateCharacterStr(travelPackVector[i].touristicSpots,'-')[0] == separateCharacterStr(destination,'-')[0])
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
	} while (!validDateText(begginningDateText));
	copyDate(begginningDate, dateTextConverter(begginningDateText));

	do
	{
		cout << "Please insert the end date: ";
		cin >> endDateText;
	} while (!validDateText(endDateText));

	copyDate(endDate, dateTextConverter(endDateText));

	cout << "Please insert the destination: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, destination);

	cout << endl << endl;
	for (int i = 0; i < travelPackVector.size(); i++)
	{
		if (biggerDate(travelPackVector[i].beginningDate, begginningDate) && biggerDate(endDate, travelPackVector[i].endDate) && (separateCharacterStr(travelPackVector[i].touristicSpots, '-')[0] == separateCharacterStr(destination, '-')[0]))
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
		number += travelPackVector[i].soldTicketsNumber;
		price += travelPackVector[i].PricePerson * travelPackVector[i].soldTicketsNumber;
	}
	cout << price <<"$" << endl;
	cout << "Number of tickets sold: " << number;

	menuSeparator();

}