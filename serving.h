#ifndef SERVING_H
#define SERVING_H
#include <vector>
#include "items.h"

using namespace std;

class Serving{
	private:
		Container _container; 
		vector<Flavor>  _flavors;
		vector<Topping> _toppings;

	public:
		Serving(Container container);
		void set_topping(Topping topping);
		void set_flavor(Flavor flavor);
		Container get_container();
		vector<Flavor> get_flavors();
		vector<Topping> get_toppings();
		double total_retail_price();
		double total_wholesale_price();		
};
#endif

	