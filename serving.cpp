#include <iostream>
#include <string>
#include "manager.h"
#include "serving.h"
#include "items.h"

using namespace std;

//constructor
Serving::Serving(int container, int flavor, int topping): _container{container}, _flavor{flavor}, _topping{topping}{}

//which container
string Serving::contianer(){
		return containers[container].get_name();
		}

//which flavor
string Serving::flavor(){
		return flavors[falvor].get_name();
		}
		
//which topping
string Serving::topping(){
		return topping[topping].get_name();
		}

//total retail price
double Serving::total_retail_price(){
		}
