#pragma once
#include "StringManipulator.h"
using namespace std;

struct Date {
	int year;
	int month;
	int day;
	
};
Date dateTextConverter(string dateText);