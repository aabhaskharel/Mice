#ifndef EMPORIUM_H
#define EMPORIUM_H
#include <vector>
#include "items.h"
#include "server.h"
#include "order.h"
#include "person.h"
using namespace std;

class Emporium{
	public:
		vector<Containr> get_containers();
		vector<Topping> get_toppings();
		vector<Flavor> get_flavors();
		vector<Server> get_servers();
		vector<Containr> get_retired_containers();
		vector<Topping> get_retired_toppings();
		vector<Flavor> get_retired_flavors();
		vector<Server> get_retired_servers();
		vector<Customer> get_customers();
		vector<Order> get_orders();
		vector<Manager> get_managers();

		void add_container(Containr cont);
		void add_flavor(Flavor flav);
		void add_topping(Topping flav);
		void add_server(Server server);
		void add_customer(Customer customer);
		void add_manager(Manager manager);
		void retire_item(Items item, int id);
		void retire_person(Person person, int id);
		void restore_item(Items item, int id);
		void restore_person(Person person, int id);

		void add_order(Order order);
		int get_order_id();
	
		void edit_container(int id, Containr container);
		void edit_flavor(int id, Flavor flavor);
		void edit_topping(int id, Topping topping);

		void change_salary(int server_id, double salary);
		void write(string filename);

		//report calls
		string get_servers_report();
		string get_customers_report();
		string get_inventory_report();
		string get_orders_report();
		string get_pnl_report();

		void populate_emporium();
	private:
		vector<Containr> _containers;
		vector<Flavor> _flavors;
		vector<Topping> _toppings;
		vector<Containr> _retired_containers;
		vector<Flavor> _retired_flavors;
		vector<Topping> _retired_toppings;
		vector<Order> _orders;
		vector<Manager> _managers;
		vector<Manager> _retired_managers;
		vector<Customer> _customers;
		vector<Server> _servers;
		vector<Server> _retired_servers;
		double cash_register;
};
#endif