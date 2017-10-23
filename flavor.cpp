#include <iostream>
#include "flavor.h"

using namespace std;

Flavor::Flavor(string name, int stock) : _name{name}, _stock{stock}{}

// get flavor's name
string Flavor::get_name(){return _name;}

// get the remaining number of flavors
int Flavor::remaining(){return _stock;}


