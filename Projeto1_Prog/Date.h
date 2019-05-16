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

	//True if the Dates are equal (same as == operator)
	bool isEqualTo(const Date &d);

	//True if the Date is after Date d
	bool isAfter(const Date &d);


	//Static Methods

	//Returns days of a month in a given year
	static int daysInMonth(int month, int year);

	//Returns true if year is a leap year
	static bool isLeapYear(int year);

	//Copies date
	static void copyDate(Date &copy, Date date);

	//Converts dateText in format year/month/day DD/MM/YYYY to a Date
	static Date dateTextConverter(string dateText);

	//Converts dateText in format YYYY/MM/DD to a Date
	static Date dateTextConverterFile(string dateText);

	//Returns true if date text is a valid date
	static bool validDateText(string dateText);

	
	friend bool operator==(const Date& date1, const Date& date2);
    friend ostream& operator<<(ostream& out, const Date & date);

};
