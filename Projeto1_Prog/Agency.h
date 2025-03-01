#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "defs.h"
#include "Address.h"



using namespace std;

class Agency{
private:
    string name; // Agency's name
    unsigned int nif; // Agency's VAT number
    Address address; // Agency's address
    string url; // Agency's Website URL
	string clientsNameFile; // Name of the clients file
	string packsNameFile;	// Name of the Travel Packs file
	int lastPackId; // Identifier of the last Travel Pack id added


public:
    Agency(string fileName); // Makes agency from filename
	Agency();

    // GET methods
  
    string getName() const;
    unsigned getNif() const;
    Address getAddress() const;
    string getUrl() const;
	string getClientsNameFile() const;
	string getPacksNameFile() const;

    // SET methods
  
    void setName(string name);
    void setNif(unsigned nif);
    void setAddress(Address address);
    void setURL(string url);
	void setClientsNameFile(string clientsNameFile);
	void setPacksNameFile(string packsNameFile);

	// Other methods

	/*Reads the agency from the specified file (that the user inputs)
	@param filename - string containing the name of the file the agency is to be read from
	@return void
	*/
	void readAgency();

	/*Shows information about the agency, formatted, as an alternative to the << operator
	@param - /
	@return void
	*/
	void showAgency() const;
  

    friend ostream& operator<<(ostream& out, const Agency & agency);
};
