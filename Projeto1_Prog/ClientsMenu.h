#pragma once
#include "Menu.h"
#include "Client.h"
#include <vector>
#include <algorithm>

/*Prints the client menu to the screen and takes the user's desired option
@param clientsVector - the vector where the clients are stored to
@param travelPacksVector - the vector where the travel packs are stored to
@param agency - the information about the agency
@return void
*/
void runClientsMenu(vector<Client> &clientsVector, vector<TravelPack> &travelPacksVector, Agency agency);

/*Option that allows the user to create a client by asking for each parameter
@param clientsVector - the vector where the clients are stored to
@return void
*/
void createClientOption(vector<Client> &clientsVector);

/*Option that allows the user to modify a client and store the changes to the vector
@param clientsVector - the vector where the clients are stored to
@return void
*/
void modifyClientOption(vector<Client> &clientsVector);

/*Option that allows the user to remove a client from the vector
@param clientsVector - the vector where the clients are stored to
@return void
*/
void removeClientOption(vector<Client> &clientsVector);

/*Option that allows the user to print a specific client to the screen by asking the NIF of the client that the user is referring to
@param clientsVector - the vector where the clients are stored to
@return void
*/
void showClientOption(vector<Client> clientsVector);

/*Prints all clients registered to the screen
@param clientsVector - the vector where the clients are stored to

@return void
*/
void showAllClients(vector<Client> clientsVector);

/*Prints a specific client's packs by asking the client's VAT number, formatted
@param clientsVector - the vector where the clients are stored to
@param travelPacksVector - the vector where the travel packs are stored to
@return void
*/
void showPacksClient(vector<Client> clientsVector, vector<TravelPack> travelPacksVector);

/*Prints all clients' packs, formatted
@param clientsVector - the vector where the clients are stored to
@param travelPacksVector - the vector where the travel packs are stored to
@return void
*/
void showPacksAllClient(vector <Client> clientsVector, vector<TravelPack> travelPacksVector);

/*Buys a travel pack for a specific client by asking the VAT number, adds the pack to the client's travel pack list and updates travel pack information
@param clientsVector - the vector where the clients are stored to
@param travelPacksVector - the vector where the packs are stored to
@return void
*/
void buyTravelPack(vector<Client>& clientsVector, vector<TravelPack>& travelPacksVector);

/*Prints to the screen each client's recommended touristic spots to see, by determining which he hasn't seen yet
@param clientsVector - the vector where the clients are stored to
@param travelPacksVector - the vector where the packs are stored to
@return void
*/
void showAllClientsWithRecommendations(vector<Client> clientsVector, vector<TravelPack> travelPacksVector);

/*Returns the client that is specified by the VAT number
@param clientsVector - the vector where the clients are stored to
@return Client - Client Class
*/
Client askForNIF(vector<Client> clientsVector);

/*Returns a client composed by the inputs it receives
@param clientsVector - the vector where the clients are stored to
@return Client - Client Class
*/
Client askForClientsInformation(vector<Client> clientsVector);

/*Returns a vector of destination that a client has visited
@param client - client to see the destinations of
@param travelPacksVector - the vector where the packs are stored to
@return vector<string> - a vector containing the destinations in strings
*/
vector<string> destinationsOfClient(Client client, vector<TravelPack> travelPacksVector);

/*Verifies if a VAT number is valid, if not, prints an error message on screen
@param option - VAT number to be verified
@return void
*/
void validNif(int& option);

/*Prints a client's information to the screen
@param client - the client the information is to be displayed of
@return void
*/
void showClient(Client client);
