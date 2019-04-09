#pragma once
#include "Menu.h"

void runClientsMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector);
void createClientOption(vector<Client> &clientsVector);
void modifyClientOption(vector<Client> &clientsVector);
void removeClientOption(vector<Client> &clientsVector);
void showClient(Client client);
void showAllClients(vector<Client> clientsVector);
Client askForClientsInformation();