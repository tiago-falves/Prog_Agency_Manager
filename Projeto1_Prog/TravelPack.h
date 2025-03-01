#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>

#include "StringManipulator.h"
#include "Agency.h"
#include "defs.h"
#include "Date.h"


using namespace std;

class TravelPack{

private:
	int id; // TravelPack unique getId()
	vector<string> touristicSpots; // touristic spots to visit
	Date begin;  // begin date
	Date end;  // end date
	double pricePerPerson; // price per person
	unsigned maxPersons; // number of persons still available in the TravelPack (updated whenever the TravelPack is sold to a new client)
	int soldTicketsNumber; // number of tickets sold to clients
	int lastPackId;
  
 public:
	  TravelPack();
	  //TravelPack(string fileName, vector<TravelPack> &travelPacksVector);
	  TravelPack(int getId(),vector<string> touristicSpots, Date begin, Date end, double pricePerPerson, unsigned maxPersons, int soldTicketsNumber);

	  // GET methods
	  int getId() const;
	  vector<string> getTouristicSpots() const;
	  Date getBeginDate() const;
	  Date getEndDate() const;
	  double getPricePerPerson() const;
	  unsigned getMaxPersons() const;
	  int getSoldTicketsNumber() const;
	  

	  // SET methods
	  void setId(unsigned id);  // to set negatve if "deprecated"
	  void setTouristicSpots(vector<string> touristicSpots);
	  void setBeginDate(Date begin);
	  void setEndDate(Date end);
	  void setPricePerPerson(double pricePerPerson);
	  void setMaxPersons(unsigned maxPersons);
	  void setSoldTicketsNumber(int soldTicketsNumber);
	  void setlastPackId(int lastPackId);


	  // other methods

	  //Reads the Travel Pack file and puts its information into a vector
	  static void readTravelPacks(string filename, vector<TravelPack> &travelPacksVector);

	  // Add a Travel Pack to travelPackVector
	  void addTravelPack(vector<TravelPack> &travelPackVector);

	  //Removes travelPackRemove from travelPackVector
	  void removeTravelPack(vector<TravelPack> &travelPackVector);

	  //Substitute travelPackToModify for travelPack
	  void modifyTravelPack(vector<TravelPack> &travelPackVector, TravelPack travelPack);
	  
	  //True if TravelPack is in vector 
	  bool travelPackInVector(vector<TravelPack> travelPackVector, TravelPack travelPack);

	  //Separate the touristic sopts in a vector, being the first element the city
	  static vector<string> separatedDestination(string destinations);		  


	  //Converts the destinations vector to a string
	  static string destinationToString(vector<string> destinationVector);

	  //Order Travel Packs by most visited
	  static vector<string> orderDestinations(vector<TravelPack> travelPackVector);

	  //Returns the best Travel Pack according to a recommendation list
	  static TravelPack bestDestination(vector<TravelPack> travelPacksVector, vector<string> recommendations);

	  //Shows TravelPacks in a different way
	  void showTravelPack() const;

	 
	  friend bool operator==(const TravelPack& travelpack1, const TravelPack& travelpack2);
	  friend ostream& operator<<(ostream& out, const TravelPack & TravelPack);
};
