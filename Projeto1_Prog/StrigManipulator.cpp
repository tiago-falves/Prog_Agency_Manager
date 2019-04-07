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
vector<int> separateCharacter(string &s, char ch) {
	vector<int> vetor;
	while (s.find_first_of(ch) != s.npos)	{
		vetor.push_back(stoi(s.substr(0, s.find_first_of(ch))));
		s.erase(0, s.find_first_of(ch) + 1);
	}
	vetor.push_back(stoi(s.substr(0, s.find_first_of(ch))));
	return vetor;
}
