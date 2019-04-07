#include "Clients.h"
#include <iostream>
using namespace std;

vector<Client> readClients(Agency agency, vector<Client> clientsVector) {

	string clientsText;
	ifstream clientsFile;
	Client client;


	int i = 0;
	clientsFile.open(agency.clientsNameFile);
	if (clientsFile.fail())
	{
		cout << "Error opening " << agency.clientsNameFile;
		return clientsVector;
	}
	else
	{
		while (getline(clientsFile, clientsText))
		{
			switch (i)
			{
			case 0:
				client.name = clientsText;
				break;
			case 1:
				client.NIF = stoi(clientsText);
				break;
			case 2:
				client.familyNumber = stoi(clientsText);
				break;
			case 3:
				client.address = addressTextConverter(clientsText);
				break;
			case 4:
				client.touristicPacksIdentifier = separateSemicolon(clientsText);
				break;
			case 5:
				i=-1;
				clientsVector.push_back(client);
				break;
			default:
				break;
			}
			i++;
		}
	}
	clientsVector.push_back(client);
	clientsFile.close();
	return clientsVector;
}
