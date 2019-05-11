#include <iostream>
#include <string>
#include <vector>

#include "Agency.h"
//#include "Menu.h"
// #include "utils.h"


int main(){
	//Testar



	//DATE
	
	//Date date;						//NAO ESTOU A PERCEBER O ERRO QUE ISTO DA
	/*Date date1(10, 12 , 1867);
	Date date2("10/13/210");
	cout << date2.getYear() << endl;
	cout << date2.getMonth() << endl;
	cout << date2.toString()<< endl;
	cout << date1.toString()<< endl;
	cout << date2.isValid() << endl;
	cout << date2.daysInMonth(10,2019) << endl;
	if (date2.isEqualTo(date1))
		cout << "Iguais" << endl; 
	else
		cout << "Não sao iguais";
	date2 = date1; 
	cout << date2.isAfter(date1) << endl;
	date2.showDate();
	cout << date2.getYear();*/


	//AGENCY

	/*Agency agency("agency.txt");
	cout << agency.getName() << endl;
	cout << agency.getClientsNameFile() << endl;
	cout << agency.getNif() << endl;
	agency.setName("Gosto");
	cout << agency.getName() << endl;
	cout << agency.getAddress().getStreet();*/


	//ADDRESS

	Address adress("zas",123,"2esq","4509-321","Porto");
	Address adress1("zas", 123, "2esq", "4509-321", "Porto");
	Address address2("zas/123/2esq/4509-321/Porto");

	cout << adress.getStreet() << endl;
	cout << adress.getFloor() << endl;
	cout << adress.getDoorNumber() << endl;
	cout << adress.getPostalCode() << endl;
	cout << adress.getLocation() << endl;
	cout << ".........................................";
	cout << address2.getStreet() << endl;
	cout << address2.getFloor() << endl;
	cout << address2.getDoorNumber() << endl;
	cout << address2.getPostalCode() << endl;
	cout << address2.getLocation() << endl;

	cout << (adress == adress1) << endl;
	cout << (adress == address2) << endl;
	
	/*Address adress("zas",123,"2esq","4509-321","Porto");
	Address adress1("zas", 123, "2esq", "4509-321", "Porto");
	cout << adress.getFloor() << endl;
	cout << adress1 == adress;*/



	//Client
	/*Agency agency;
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
	cout << clients[1].getFamilySize();*/

	system("Pause");

  
  return 0;
}
