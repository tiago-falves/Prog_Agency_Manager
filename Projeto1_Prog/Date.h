#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "StringManipulator.h"
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
	Date(unsigned short day, unsigned short month, unsigned year);


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


	//Converts a date in a string day/month/year
	string toString();


	//True if valid Date
	bool isValid();

	//True if the Dates are equal
	bool isEqualTo(const Date &d);

	//True if the Date is after Date d
	bool isAfter(const Date &d);

	//Overload
	//Date operator=(Date date); Isto não

	//Static Methods, DESCOBRIR ONDE SE POE

	static int daysInMonth(int month, int year);
	static bool isLeapYear(int year);
	static void copyDate(Date &copy, Date date);

	//Converts dateTex in format year/month/day xxxx/xx/xx to a struct Date
	static Date dateTextConverter(string dateText);
	
	friend bool operator==(const Date& date1, const Date& date2); // Comparison operator overloading
    friend ostream& operator<<(ostream& out, const Date & date); // Extraction operator overloading, prints date normally

};
