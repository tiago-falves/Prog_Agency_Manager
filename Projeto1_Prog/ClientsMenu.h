#pragma once
#include "Menu.h"
#include "Client.h"

void runClientsMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency);

void createClientOption(vector<Client> &clientsVector);

void modifyClientOption(vector<Client> &clientsVector);

void removeClientOption(vector<Client> &clientsVector);

void showClient(Client client);

void showAllClients(vector<Client> clientsVector);

void buyTravelPack(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector);

void showClientOption(vector<Client> clientsVector);

void validNif(int &option);

Client askForClientsInformation();

Client askForNIF(vector<Client> clientsVector);