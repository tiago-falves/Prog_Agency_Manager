#include "Date.h"


Date::Date(unsigned short day, unsigned short month , unsigned year ) : day(day), month(month), year(year){}

Date::Date(string date){

	day = stoi(date.substr(0, 2));
	month = stoi(date.substr(3, 2));
	year = stoi(date.substr(6, 4));

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


ostream& operator<<(ostream	&out, const Date &date){
	out << date.day << "/" << date.month << "/" << date.year;
	return out;
}

