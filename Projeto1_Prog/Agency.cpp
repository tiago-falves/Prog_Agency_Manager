#include "Agency.h"


Agency::Agency(string fileName){

	readAgency(fileName);
}

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




//Reads the agency file
void Agency::readAgency(string filename) {

	string agencyText;
	ifstream agencyFile;
	Agency agency;
	int i = 0;


	agencyFile.open(filename);

	if (agencyFile.fail())
		cerr << "Error opening agency.txt. Please make sure the file is in the correct folder " << endl;
	else {
		while (getline(agencyFile, agencyText))
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
	agencyFile.close();

}

/*********************************
 * Mostrar Loja
 ********************************/  

// mostra o conteudo de uma agencia

void Agency::showAgency() const{
	cout << "*********************************" << endl;
	cout << "Name: " << name << endl;
	cout << "VATnumber: " << nif << endl;
	cout << "Address: " << address << endl;
	cout << "URL: " << url << endl;
	//cout clients
	//cout travel packs
	cout << "*********************************" << endl;
}
ostream& operator<<(ostream& out, const Agency &agency){
	out << "*********************************" << endl << "Name: " << agency.name << endl << "VATnumber: " << agency.nif << endl
	<< "Address: " << agency.address << "URL: " << agency.url << endl //cout clients //cout travel packs
	<< "*********************************" << endl;
	
	return out;
}
