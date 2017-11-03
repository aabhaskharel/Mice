#ifndef EMPORIUM_H
#define EMPORIUM_H
#include <vector>
#include "items.h"
#include "server.h"
#include "serving.h"
#include "order.h"
#include "manager.h"
#include "customer.h"
using namespace std;

class Emporium{
	public:
		
		vector<Containr> get_containers();
		vector<Topping> get_toppings();
		vector<Flavor> get_flavors();
		vector<Server> get_servers();
		vector<Customer> get_customers();

		void add_new_container(Containr cont);
		void add_new_flavor(Flavor flav);
		void add_new_topping(Topping flav);
		void add_new_server(Server server);
		void add_new_customer(Customer customer);
		void create_servings(Serving ser);

		void populate_emporium();

	private:
		vector<Containr> _containers;
		vector<Flavor> _flavors;
		vector<Topping> _toppings;
		vector<Order> _orders;
		vector<Manager> _managers;
		vector<Server> _servers;
		vector<Customer> _customers;
		double cash_register = 0;
};
#endif
