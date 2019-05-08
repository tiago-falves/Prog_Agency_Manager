#include "Date.h"

//Converts dateTex in format year/month/day xxxx/xx/xx to a struct Date
Date dateTextConverter(string dateText) {
	Date date;
	vector<int> dateVector;
	dateVector = separateCharacterInt(dateText, '/');
	date.year = dateVector[0];
	date.month = dateVector[1];
	date.day = dateVector[2];
	return date;
}

//Returns true if dates are equal
bool equalDates(Date date1, Date date2) {
	if (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year)
		return true;
	else
		return false;
}

//Copies date to copy
void copyDate(Date &copy, Date date) {
	copy.year = date.year;
	copy.month = date.month;
	copy.day = date.day;
}

//Returns true if date text is a valid date
bool validDateText(string dateText)
{
	vector<string> dateVector;
	dateVector = separateCharacterStr(dateText,'/');
	if (dateVector.size() != 3) {return false;}
	for (int i = 0; i < dateVector.size(); i++)	{
		if (!stringIsNumber(dateVector[i])) { return false;}
	}
	if (stoi(dateVector[0]) < 1000 || dateVector[0].size() != 4) {return false;}
	if (dateVector[1].size() != 2 || stoi(dateVector[1]) < 1 || stoi(dateVector[1]) > 12) { return false; }
	if (dateVector[1].size() != 2 || stoi(dateVector[1]) < 1 || stoi(dateVector[1]) > 31) { return false; }
	return true;
}

//Returns true if bigDate is after smallDate
bool biggerDate(Date bigDate, Date smallDate) {
	if (bigDate.year > smallDate.year) {	return true;}
	if (bigDate.month > smallDate.month) {return true;}
	if (bigDate.day >= smallDate.day) {return true;}
	return false;
}
