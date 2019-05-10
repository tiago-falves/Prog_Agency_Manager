#include "Agency.h"



Agency::Agency(string fileName){

	readAgency(fileName);
}
Agency::Agency() {
	this->name = "";
	this->nif = 0;
	//this->address = "";
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

//vector<Client> Agency::getClients() const { return clients; }

//vector<TravelPack> Agency::getTravelPacks() const {	return TravelPacks;}


//SET METHODS

void Agency::setName(string name){ this->name = name; }

void Agency::setNif(unsigned nif){	this->nif = nif; }

void Agency::setAddress(Address address){ this->address = address; }

void Agency::setURL(string url) { this->url = url; }

void Agency::setClientsNameFile(string clientsNameFile){ this->clientsNameFile = clientsNameFile;}

void Agency::setPacksNameFile(string packsNameFile) { this->packsNameFile = packsNameFile;}

//void Agency::setClients(vector<Client>& clients) { this->clients = clients; }

//void Agency::setTravelPacks(vector<TravelPack>& TravelPacks){ this->TravelPacks = TravelPacks; }



void Agency::readAgency(string filename) {

	string agencyText;
	ifstream agencyFile;
	Agency agency;
	int i = 0;


	agencyFile.open("agency.txt");

	if (agencyFile.fail())
		cerr << "Error opening agency.txt, Please make sure the file is in the correct folder " << endl;
	else {
		while (getline(agencyFile, agencyText))
		{
			switch (i) {
			case 0:
				name = agencyText;
				break;
			case 1:
				nif = stoi(agencyText);
				break;
			case 2:
				url = agencyText;
				break;
			case 3:
				//agency.setAddress(addressTextConverter(agencyText));
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
	agencyFile.close();

}



/*********************************
 * Mostrar Loja
 ********************************/  

// mostra o conteudo de uma agencia
/*ostream& operator<<(ostream& out, const Agency & agency){

  // A IMPLEMENTATION REQUIRED 
}*/
