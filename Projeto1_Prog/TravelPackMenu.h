#pragma once
#include "Menu.h"

void runTravelPackMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector);
TravelPack askForTravelPacks(bool isCreatingTravelPack, vector<TravelPack> travelPackVector);
void createTravelPackOption(vector<TravelPack> &travelPackVector);
void modifyTravelPackOption(vector<TravelPack> &travelPackVector);
void removeClientOption(vector<TravelPack> &travelPackVector);
void showAllTravelPacks(vector<TravelPack> travelPackVector);
void showAllTravelPacksByDate(vector<TravelPack> travelPackVector);
void showAllTravelPacksByDestination(vector<TravelPack> travelPackVector);
void showAllTravelPacksByDateDestination(vector<TravelPack> travelPackVector);
void showTravelPacks(vector<TravelPack> &travelPacksVector,vector<Client> &clientsVector);
void showSoldTouristicPacks(vector<TravelPack> travelPacksVector, vector<Client> clientsVector);
void calculateNumberPacks(vector<TravelPack> travelPackVector);