#include <iostream>
#include "topping.h"

using namespace std;

Topping::Topping(string name, int stock) : _name{name}, _stock{stock}{}

// get topping's name
string Topping::get_name(){return _name;}

// get the remaining number of toppings
int Topping::remaining(){return _stock;}


