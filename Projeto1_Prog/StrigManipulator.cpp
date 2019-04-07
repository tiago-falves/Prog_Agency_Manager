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
vector<int> separateSemicolon(string &s) {
	vector<int> vetor;
	while (s.find_first_of(";") != s.npos)	{
		vetor.push_back(stoi(s.substr(0, s.find_first_of(";"))));
		s.erase(0, s.find_first_of(";") + 1);
	}
	vetor.push_back(stoi(s.substr(0, s.find_first_of(";"))));
	return vetor;
}
