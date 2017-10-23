#include <iostream>
#include "container.h"
#include "flavor.h"
#include "topping.h"

using namespace std;

Container::Container(string name, int flavor_capacity, int topping_capacity) : _name{name}, _flavor_capacity{flavor_capacity}, _topping_capacity{topping_capacity}{}


//get containe's name
string Container::get_name(){return _name;}

//flavor holding capacity of the container
int Container::get_flav_capacity(){return _flavor_capacity;}

//topping holding capacity of the container
int Container::get_top_capacity(){return _topping_capacity;}




