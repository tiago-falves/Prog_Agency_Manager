#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "Clients.h"
#include "TravelPack.h"

void runMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency);

void saveAndExit(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency);

void menuSeparator();

void validCin(int &option);