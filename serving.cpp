#include <vector>
#include <iostream>
#include "serving.h"

using namespace std;

//constructor
Serving::Serving(Containr container): _container{container} {}

//return container
Containr Serving::get_container() const {return _container;}

//return flavors
vector<Flavor> Serving::get_flavors() const {return _flavors;}
		
//return toppings
vector<Topping> Serving::get_toppings() const {return _toppings;}

//set toppings
void Serving::set_topping(Topping topping) {
    _toppings.push_back(topping);
}

//set flavors
void Serving::set_flavor(Flavor flavor) {
    _flavors.push_back(flavor);
}

//total retail price
double Serving::total_retail_price() const {
		double total=0; double f=0; double t;
		total = _container.get_retail_price();
		
		for(int i=0; i<_flavors.size(); i++){
				f+=_flavors[i].get_retail_price();	
		}
		
		for(int i=0; i<_toppings.size(); i++){
				t+=_toppings[i].get_retail_price();
		}
		
	total = total + f + t;
	
	return total;
}

//total wholesale price
double Serving::total_wholesale_price() const {
		double total=0; double f=0; double t;
		total = _container.get_wholesale_price();
		
		for(int i=0; i<_flavors.size(); i++){
				f+=_flavors[i].get_wholesale_price();	
		}
		
		for(int i=0; i<_toppings.size(); i++){
				t+=_toppings[i].get_wholesale_price();
		}
		
	total = total + f + t;
	
	return total;
}

std::ostream& operator<<(std::ostream& os, const Serving& serving) {
    os << serving.get_container();
    for (Flavor s : serving.get_flavors()) os << std::endl << s;
    for (Topping t : serving.get_toppings()) os << std::endl << t;
    return os;
}

