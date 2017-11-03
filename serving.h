#ifndef SERVING_H
#define SERVING_H
#include <vector>
#include "items.h"

using namespace std;

class Serving{
	private:
		Containr _container; 
		vector<Flavor>  _flavors;
		vector<Topping> _toppings;

	public:
		Serving(Containr container);
		void set_topping(Topping topping);
		void set_flavor(Flavor flavor);
		Containr get_container() const;
		vector<Flavor> get_flavors() const;
		vector<Topping> get_toppings() const;
		double total_retail_price() const;
		double total_wholesale_price() const;		
};

std::ostream& operator<<(std::ostream& os, const Serving& serving);

#endif

	