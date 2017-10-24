#ifndef MANAGER_H
#define MANAGER_H
#include "items.h"

using namespace std;

class Manager{
	public:
		vector<Container> containers;
		vector<Flavor> flavors;
		vector<Topping> toppings;
	
		void add_new_container(Container cont);
		string list_container(int i);
		string list_all_containers();
		int number_of_containers();

		void add_new_flavor(Flavor flav);
		string list_flavor(int i);
		string list_all_flavors();
		int number_of_flavors();

		void add_new_topping(Topping top);
		string list_topping(int i);
		string list_all_toppings();
		int number_of_toppings();

};	
#endif
