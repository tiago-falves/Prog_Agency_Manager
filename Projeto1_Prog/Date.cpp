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