#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
#include "items.h"
#include "server.h"
#include "dialogs.h"

using namespace std;

class Manager{
	public:
		void create_server(Server server);
		void add_new_container();
		string list_container(int i);
		string list_all_containers();
		int number_of_containers();

		void add_new_flavor();
		string list_flavor(int i);
		string list_all_flavors();
		int number_of_flavors();

		void add_new_topping();
		string list_topping(int i);
		string list_all_toppings();
		int number_of_toppings();

		void populate_mgmt();



};	
#endif
