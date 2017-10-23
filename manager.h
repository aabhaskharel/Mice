#ifndef MANAGER_H
#define MANAGER_H
#include "container.h"
#include  "flavor.h"
#include "topping.h"

using namespace std;

class Manager{
	public:
		vector<Container> containers;
		vector<Flavor> flavors;
		vector<Topping> toppings;
	
		void add_new_container(Container cont);
		void list_all_containers();
		int number_of_containers;

		void add_new_flavor(Flavor flav);
		void list_all_flavors();
		int number_of_flavors;

		void add_new_topping(Topping top);
		void list_all_top();
		int number_of_toppings;

};	
#endif
