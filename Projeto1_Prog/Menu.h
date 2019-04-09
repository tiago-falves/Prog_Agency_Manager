#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Clients.h"
#include "TravelPack.h"

void runMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector);

void menuSeparator();
void validCin(int &option);