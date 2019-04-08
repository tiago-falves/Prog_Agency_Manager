#pragma once
#include <string>
#include <vector>
using namespace std;

void trimRight(std::string &s);
void trimLeft(std::string &s);
void trim(std::string &s);
vector<int> separateCharacter(string &s, char ch);
//bool stringIsNumber(string number);
bool string_is_number(string number);