#include <iostream>
#include <string>
#include <vector>

#include "Agency.h"
//#include "Menu.h"
// #include "utils.h"


int main(){
	//Testar

	//DATE
	
	/*Date date;
	Date date1(10 / 12 / 1867);
	cout << date.getYear() << endl;
	cout << date.toString()<< endl;
	cout << date.daysInMonth(10,2019) << endl;
	date = date1; //Ainda nao funciona
	cout << date.getYear();*/


	//AGENCY

	Agency agency("agency.txt");
	cout << agency.getName() << endl;
	cout << agency.getClientsNameFile() << endl;
	cout << agency.getNif() << endl;
	agency.setName("Gosto");
	cout << agency.getName() << endl;



	system("Pause");

  
  return 0;
}
