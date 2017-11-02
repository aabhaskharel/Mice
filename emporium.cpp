#include "emporium.h"

using namespace std;

//constructor
Emporium::Emporium(vector<Container> containers, vector<Flavor> flavors, vector<Topping> toppings, vector<Order> orders, vector<Manager> managers, vector<Server> servers): _flavors{flavors}, _containers{containers}, _toppings{toppings}, _orders{orders}, _managers{managers}, _servers{servers} {}

//
