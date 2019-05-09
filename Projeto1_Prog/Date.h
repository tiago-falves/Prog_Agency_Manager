#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "defs.h"

using namespace std;

class Date{
private:
    unsigned short day;
    unsigned short month;
    unsigned year;

public:
   
    Date(string date); // Assuming "dd/mm/yyyy"
    Date(unsigned short day = 1, unsigned short month = 1, unsigned year = 1000);

    // GET methods
    
    unsigned short getDay() const;
    unsigned short getMonth() const;
    unsigned getYear() const;
  
    // SET methods
  
    void setDay(unsigned short day);
    void setMonth(unsigned short month);
    void setYear(unsigned year);

    //Outputs date in nice format
    void showDate() const;

	//Converts a date in a string
	string toString();

	
    friend ostream& operator<<(ostream& out, const Date & date); // Extraction operator overloading, prints date normally

};
