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
		Emporium(vector<Container> containers, vector<Flavor> flavors, vector<Topping> toppings, vector<Order> orders, vector<Manager> managers, vector<Server> servers);

	private:
		vector<Container> _containers;
		vector<Flavor> _flavors;
		vector<Topping> _toppings;
		vector<Order> _orders;
		vector<Manager> _managers;
		vector<Server> _servers;
	
		double cash_register = 0;
};
#endif