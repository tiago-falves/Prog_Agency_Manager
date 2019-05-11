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

	/* Agency agency("agency.txt");
	cout << agency.getName() << endl;
	cout << agency.getClientsNameFile() << endl;
	cout << agency.getNif() << endl;
	agency.setName("Gosto");
	cout << agency.getName() << endl; */


	//ADDRESS

	//Address adress("zas",123,"2esq","4509-321","Porto");
	//Address adress1("zas", 123, "2esq", "4509-321", "Porto");

	//cout << adress.getFloor() << endl;
	//cout << (adress == adress1) << endl;
	
	/*Address adress("zas",123,"2esq","4509-321","Porto");
	Address adress1("zas", 123, "2esq", "4509-321", "Porto");
	cout << adress.getFloor() << endl;
	cout << adress1 == adress;*/

	//Client
	Agency agency;
	vector<Client> clients;
	agency.readAgency("agency.txt");
	
	Client client(agency.getClientsNameFile(),clients);
	cout << clients[0].getName() << endl;
	cout << clients[0].getAddress().getStreet() << endl;
	cout << clients[0].getnif() << endl;
	//cout << clients[0].getTravelPackList()[0] << endl;

	cout << clients[1].getName() << endl;
	cout << clients[1].getAddress().getStreet() << endl;
	cout << clients[1].getnif() << endl;


	cout << clients.size();
	cout << clients[1].getFamilySize();

	system("Pause");

  
  return 0;
}
