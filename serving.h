#ifndef SERVING_H
#define SERVING_H
#include <vector>
#include <fstream>
#include "items.h"

using namespace std;

class Serving{
	private:
		Containr _container{"", "", 0, 0, "", 0};
		vector<Flavor>  _flavors;
		vector<Topping> _toppings;

	public:
		Serving(Containr container);
		Serving(std::istream& ist);
    	void save(std::ostream& ost);
		void set_topping(Topping topping);
		void set_flavor(Flavor flavor);

		Containr get_container() ;
		vector<Flavor> get_flavors() ;
		vector<Topping> get_toppings() ;
		double get_total_retail_price() ;
		double get_total_wholesale_price();
};

std::ostream& operator<<(std::ostream& os, const Serving& serving);

#endif
