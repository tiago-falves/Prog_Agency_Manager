#include "StringManipulator.h"

using namespace std;

void trimRight(string &s) {
	s.erase(s.find_last_not_of(" ") + 1);
}
void trimLeft(string &s) {
	s.erase(0, s.find_first_not_of(" "));
}
void trim(string &s) {
	trimRight(s);
	trimLeft(s);
}