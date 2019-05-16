#pragma once
#include "Menu.h"
#include "Client.h"
#include <vector>
#include <algorithm>

void runClientsMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency);

void createClientOption(vector<Client> &clientsVector);

void modifyClientOption(vector<Client> &clientsVector);

void removeClientOption(vector<Client> &clientsVector);

void showClient(Client client);

void showAllClients(vector<Client> clientsVector);

void buyTravelPack(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector);

void showClientOption(vector<Client> clientsVector);

void validNif(int &option);

//Outputs all clients and adds a destination as a recommendation
void showAllClientsWithRecommendations(vector<Client> clientsVector, vector<TravelPack> travelPacksVector);

//Returns a vector with all the destinations of a Client
vector<string> destinationsOfClient(Client client, vector<TravelPack> travelPacksVector);

Client askForClientsInformation(vector<Client> clientsVector);

Client askForNIF(vector<Client> clientsVector);