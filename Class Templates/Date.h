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
    Date();
    Date(string date); // Assuming "dd/mm/yyyy"
    Date(unsigned short day = 0, unsigned short month = 0, unsigned year = 1900);

    // GET methods
    
    unsigned short getDay() const;
    unsigned short getMonth() const;
    unsigned getYear() const;
  
    // SET methods
  
    void setDay(unsigned short day);
    void setMonth(unsigned short month);
    void setYear(unsigned year);

    // other methods */

    void showDate() const; // shows date in a nice format
    friend ostream& operator<<(ostream& out, const Date & date); // Extraction operator overloading, prints date normally

};
