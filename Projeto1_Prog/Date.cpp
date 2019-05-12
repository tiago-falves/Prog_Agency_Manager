#include "Date.h"


Date::Date() {
	this->year = 1000;
	this->month = 1;
	this->day = 1;
}

Date::Date(unsigned short day, unsigned short month, unsigned year){
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(string date){

	this->day = stoi(date.substr(0, 2));
	this->month = stoi(date.substr(3, 2));
	this->year = stoi(date.substr(6, 4));

}
/*********************************
 * GET Methods
 ********************************/


unsigned short Date::getDay() const{return day;}
unsigned short Date::getMonth() const{return month;}
unsigned Date::getYear() const{return year;}


/*********************************
 * SET Methods
 ********************************/

void Date::setDay(unsigned short day){this -> day = day;}
void Date::setMonth(unsigned short month){this -> month = month;}
void Date::setYear(unsigned year){this -> year = year;}

/*********************************
 * Show Date
 ********************************/  

void Date::showDate() const{
	cout << "*********************************" << endl;
	cout << day << "/" << month << "/" << year << endl;
	cout << "*********************************" << endl;
}

//Converts a date into a string
string Date::toString()
{
	return to_string(day) + "/" + to_string(month) + "/" + to_string(year) ;
}

//True if valid Date
bool Date::isValid() {
	return (day <= daysInMonth(month, year)) && (month >= 1) && (month <= 12) && (day > 0);
}

//True if both dates are equal
bool Date::isEqualTo(const Date &d) {
	return (d.year == year && d.month == month && d.day == day);
}

//True if the date is after Date d
bool Date::isAfter(const Date &d) {
	if (d.year > year)
		return false;
	else if (d.year == year && d.month > month)
		return false;
	else if (d.year == year && d.month == month && d.day > day)
		return false;
	else
		return true;
}

bool operator==(const Date& date1, const Date& date2) { // Comparison operator overloading
	return date1.day == date2.day && date1.month == date2.month && date1.year == date2.year;
}

ostream& operator<<(ostream	&out, const Date &date){
	out << date.day << "/" << date.month << "/" << date.year;
	return out;
}



//STATIC METHODS

//Returns the number of days in a certain month

int Date::daysInMonth(int month, int year) {
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		if (isLeapYear(year)) return 29;
		else return 28;
	default:
		return -1;
	}
}

//True if leap year, false otherwise
bool Date::isLeapYear(int year) {
	// Divisible by 4 but not by 100, or divisible by 400
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
		return false;
}

void Date::copyDate(Date &copy, Date date) {
	copy.year = date.year;
	copy.month = date.month;
	copy.day = date.day;
}



