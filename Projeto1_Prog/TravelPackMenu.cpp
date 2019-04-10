#include "TravelPackMenu.h"

void runTravelPackMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector) {
	int option;

	cout << "Welcome to the Touristic Packs Menu! Please choose what you want to do: ";
	cout << endl << endl;
	cout << "0. Create a new touristic pack." << endl;
	cout << "1. Change a touristic pack." << endl;
	cout << "2. Remove a touristic pack" << endl;
	cout << "3. See information from touristic packs. " << endl;
	
	cout << "Insert the number correspondent to your option: ";
	cin >> option;


	while (cin.fail() || (option != 0 && option != 1 && option != 2 && option != 3))// && option != 4 && option != 5 && option != 6))
	{
		cout << "Invalid option, please insert the option again: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> option;
	}
	menuSeparator();

	if (option == 0) { createTravelPackOption(travelPacksVector); }
	if (option == 1) { modifyTravelPackOption(travelPacksVector); }
	if (option == 2) { removeClientOption(travelPacksVector); }
	if (option == 3) { showTravelPacks( travelPacksVector,clientsVector); }
	runMenu(clientsVector, travelPacksVector);
}

void showTravelPacks(vector<TravelPack> travelPacksVector,vector<Client> clientsVector) {
	int option;
	cout << "Please choose what you want to see: ";
	cout << endl << endl;

	cout << "1. See information from all touristic packs. " << endl;
	cout << "2. See information from touristic packs between two dates. " << endl;
	cout << "3. See information from touristic packs to a certain destination. " << endl;
	cout << "4. See information from touristic packs to a certain destination and between two dates. " << endl << endl;
	cout << "5. See information from all the sold touristic packs. " << endl << endl;

	cout << "Insert the number correspondent to your option: ";
	cin >> option;
	while (cin.fail() || (option != 1 && option != 2 && option != 3 && option != 4 ))
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

}

void createTravelPackOption(vector<TravelPack> &travelPackVector) {
	TravelPack travelPack;
	cout << "Please insert the data of your new Touristic Pack" << endl << endl;
	copyTravelPack(travelPack, askForTravelPacks(true,travelPackVector));
	addTravelPack(travelPackVector, travelPack);
	cout << endl << endl << "Touristic Pack created successfully!";
	menuSeparator();
}

void modifyTravelPackOption(vector<TravelPack> &travelPackVector) {
	TravelPack travelPackToModify;
	TravelPack modifiedTravelPack;

	cout << "Please insert the data of the Touristic Pack you want to modify" << endl << endl;
	copyTravelPack(travelPackToModify, askForTravelPacks(false,travelPackVector));

	cout << travelPackToModify.identifier << endl;
	cout << travelPackToModify.touristicSpots << endl;
	cout << travelPackToModify.soldTicketsNumber << endl;
	cout <<  travelPackToModify.beginningDate.month << endl;
	cout << travelPackToModify.PricePerson;


	if (travelPackToModify.identifier == travelPackVector[0].identifier && travelPackToModify.touristicSpots == travelPackVector[0].touristicSpots)
	{
		cout << "cona";
	}


	while (!travelPackInVector(travelPackVector, travelPackToModify))
	{
		cout << "The Touristic Pack is not in the database, please insert the data again" << endl << endl;
		copyTravelPack(travelPackToModify, askForTravelPacks(false,travelPackVector));
	}

	cout << endl << endl << "Insert the new informations about the Touristic Pack: " << endl << endl;
	copyTravelPack(modifiedTravelPack, askForTravelPacks(true,travelPackVector));
	//Perguntar porque que Ele aqui pergunta o name duas vezes
	modifyTravelPack(travelPackToModify, travelPackVector, modifiedTravelPack);
	cout << endl << endl << "Touristic Pack modified successfully!";
	menuSeparator();
}

void removeClientOption(vector<TravelPack> &travelPackVector) {
	TravelPack travelPack;
	cout << "Please insert the data of the touristic pack you want to remove" << endl << endl;
	copyTravelPack(travelPack, askForTravelPacks(false,travelPackVector));
	removeTravelPack(travelPack, travelPackVector);
	cout << endl << endl << "Touristic Pack removed successfully!";
	menuSeparator();
}




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
					cin.ignore(10000, '\n');
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
		cout << "Invalid address, please insert again: ";
		getline(cin, endDateText);
	}


	cout << "Price per person: ";
	cin >> pricePerson;
	validCin(pricePerson);
	cin.clear();
	

	cout << "Max number of people: ";
	cin >> maxPersonNumber;
	validCin(maxPersonNumber);
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "Sold tikets number: ";
	cin >> soldTicketsNumber;
	validCin(soldTicketsNumber);
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