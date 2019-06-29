#include "Agency.h"

Agency::Agency(){
	this->name = "";
	this->nif = 0;
	this->url = "";
	this->clientsNameFile = "";
	this->packsNameFile = "";
}

//GET METHODS

string Agency::getName() const{ return name; }

unsigned Agency::getNif() const{ return nif; }

Address Agency::getAddress() const{ return address; }

string Agency::getUrl() const { return url; }

string Agency::getClientsNameFile() const{ return clientsNameFile; }

string Agency::getPacksNameFile() const { return packsNameFile; }


//SET METHODS

void Agency::setName(string name){ this->name = name; }

void Agency::setNif(unsigned nif){	this->nif = nif; }

void Agency::setAddress(Address address){ this->address = address; }

void Agency::setURL(string url) { this->url = url; }

void Agency::setClientsNameFile(string clientsNameFile){ this->clientsNameFile = clientsNameFile;}

void Agency::setPacksNameFile(string packsNameFile) { this->packsNameFile = packsNameFile;}


//Reads the Agency's file
void Agency::readAgency() {


	string agencyText;
	ifstream file;
	Agency agency;
	int i = 0;

	string agencyfile;

	while (true) { // Asks for file until it suceeds
		cout << "Please choose the agency you want to check (the .txt file): " ;
		cin >> agencyfile;

		ifstream in_file;
		in_file.open(agencyfile); // Open file for testing

		if (in_file.fail())	{

			cerr << "File not found!" << endl;
			in_file.clear();
			in_file.ignore(1000, '\n');
		}
		else {
			in_file.close();
			break;
		}
	}


	file.open(agencyfile);

	if (file.fail())
		cerr << "Error opening agency.txt. Please make sure the file is in the correct folder " << endl;
	else {
		while (getline(file, agencyText))
		{
			switch (i) {
			case 0:
				setName(agencyText);
				break;
			case 1:
				setNif(stoi(agencyText));
				break;
			case 2:
				setURL(agencyText);
				break;
			case 3:
				setAddress(address.addressTextConverter(agencyText));
				break;
			case 4:
				clientsNameFile = agencyText;
				break;
			case 5:
				packsNameFile  = agencyText;
				break;
			default:
				break;
			}
			i++;
		}
	}
	file.close();

}


//Shows Agency in a formatted way
void Agency::showAgency() const{
	for (int i = 0; i < 60; i++) { cout << "*"; }
	cout << endl << endl;
	cout << "Name: " << name << endl;
	cout << "VATNumber: " << nif << endl;
	cout << "URL: " << url << endl << endl;
	cout << "Address: " << address;
	cout << "Associated Clients File: " << clientsNameFile << endl;
	cout << "Associated TravelPacks File: " << packsNameFile << endl;
	for (int i = 0; i < 60; i++) { cout << "*"; }
	cout << endl << endl;
}



ostream& operator<<(ostream& out, const Agency &agency){
	out << "***************************************" << endl << "Name: " << agency.name << endl;
	out << "NIF: " << agency.nif << endl;
	out << "Address: " << agency.address;
	out << "URL: " << agency.url << endl;
	out << "Associated Clients File: " << agency.clientsNameFile << endl;
	out << "Associated TravelPacks File: " << agency.packsNameFile << endl;
	out << "***************************************";
	out << endl << endl;
	return out;
}
