#include "Clients.h"
#include <iostream>
using namespace std;

vector<Client> readClients(Client &client, Agency agency) {

	string clientsText;
	ifstream clientsFile;
	vector<Client> clientsVector;

	int i = 0;
	clientsFile.open(agency.clientsNameFile);
	if (clientsFile.fail())
	{
		cerr << "Error opening " << agency.clientsNameFile;
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
				//addressTextConverterAgency(clientsText);
				break;
			case 4:
				client.touristicPacksIdentifier = clientsText;
				break;
			case 5:
				i=0;
				clientsVector.push_back(client);
				break;
			default:
				break;
			}
			i++;
		}
	}
	clientsFile.close();
	return clientsVector;
}
using namespace std;