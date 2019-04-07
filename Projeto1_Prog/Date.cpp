#include "Date.h"




Date dateTextConverter(string dateText) {
	Date date;
	vector<int> dateVector;
	dateVector = separateCharacter(dateText, '/');
	date.year = dateVector[0];
	date.month = dateVector[1];
	date.day = dateVector[2];
	return date;
}
bool equalDates(Date date1, Date date2) {
	if (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year)
		return true;
	else
		return false;
}