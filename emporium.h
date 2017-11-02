#ifndef EMPORIUM_H
#define EMPORIUM_H
#include <vector>
#include "items.h"
#include "server.h"
#include "order.h"
#include "manager.h"
using namespace std;

class Emporium{
	public:
		
		vector<Container> get_containers();
		vector<Topping> get_toppings();
		vector<Flavor> get_flavors();
		vector<Server> get_servers();
		
		void set_container(Container cont);
		void set_topping(Topping top);
		void set_flavor(Flavor flav);
		void set_server(Server serv);

	//private:
		vector<Container> _containers;
		vector<Flavor> _flavors;
		vector<Topping> _toppings;
		vector<Order> _orders;
		vector<Manager> _managers;
		vector<Server> _servers;
	
		double cash_register = 0;
};
#endif
