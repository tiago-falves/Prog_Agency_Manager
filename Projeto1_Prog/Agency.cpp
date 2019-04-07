#include "Agency.h"
#include <iostream>


using namespace std;

// Opens the agency file and puts its contents in a Agency Strut
void readAgency(Agency &agency) {

	string agencyText;
	ifstream agencyFile;

	int i = 0;
	agencyFile.open("agency.txt");
	if (agencyFile.fail())
	{
		cerr << "Error opening agency.txt";
		
	}
	else
	{
		while (getline(agencyFile, agencyText))
		{
			switch (i)
			{
			case 0:
				agency.name =  agencyText;
				break;
			case 1:
				agency.NIF = stoi(agencyText);
				break;
			case 2:
				agency.URL = agencyText;
				break;
			case 3:
				
				agency.address = addressTextConverter(agencyText);
				break;
			case 4:
				agency.clientsNameFile = agencyText;
				break;
			case 5:
				agency.packsNameFile = agencyText;
				break;
			default:
				break;
			}
			i++;
		}
	}
	agencyFile.close();
	//return agency;
}