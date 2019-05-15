#pragma once
#include "Menu.h"
#include "Client.h"


TravelPack askForTravelPacks(bool isCreatingTravelPack, vector<TravelPack> travelPackVector);

TravelPack askForTravelPacksgetId(vector<TravelPack> travelPackVector);

void runTravelPackMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency);

void createTravelPackOption(vector<TravelPack> &travelPackVector);

void modifyTravelPackOption(vector<TravelPack> &travelPackVector);

void removeClientOption(vector<TravelPack> &travelPackVector);

void showAllTravelPacks(vector<TravelPack> travelPackVector);

void showAllTravelPacksByDate(vector<TravelPack> travelPackVector);

void showAllTravelPacksByDestination(vector<TravelPack> travelPackVector);

void showAllTravelPacksByDateDestination(vector<TravelPack> travelPackVector);

void showTravelPacks(vector<TravelPack> &travelPacksVector,vector<Client> &clientsVector);

void showSoldTouristicPacks(vector<TravelPack> travelPacksVector, vector<Client> clientsVector);

//Outputs an ordered list of the most visited places
void showOrderedDestinations(vector<TravelPack> travelPackVector);

void calculateNumberPacks(vector<TravelPack> travelPackVector);