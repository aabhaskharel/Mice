#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "serving.h"

using namespace std;

//constructor
Serving::Serving(Containr container): _container{container} {}
Serving::Serving(std::istream& ist) {
    // The header must have been stripped from the incoming stream at this point
    std::string header1, header2;
    while (true) {
        std::getline(ist, header1); // header
        std::getline(ist, header2);
        if (header1 != "#") throw std::runtime_error("missing # during input");
        if (header2 == "END SERVING") break;  // footer
        else if (header2 == "CONTAINER") _container = Containr{ist};
        else if (header2 == "FLAVOR") _flavors.push_back(Flavor{ist});
        else if (header2 == "TOPPING") _toppings.push_back(Topping{ist});
        else throw std::runtime_error("invalid item type in Serving");
    }
}

void Serving::save(std::ostream& ost) {
    ost << "#" << std::endl << "SERVING" << std::endl; // header
    _container.save(ost);
    for (Flavor& f : _flavors) f.save(ost);
    for (Topping& t : _toppings) t.save(ost);
    ost << "#" << std::endl << "END SERVING" << std::endl; // footer
}

//return container
Containr Serving::get_container() {return _container;}

//return flavors
vector<Flavor> Serving::get_flavors() {return _flavors;}
vector<int> Serving::get_top_kind() {return _top_kind;}

//return toppings
vector<Topping> Serving::get_toppings() {return _toppings;}

//set toppings
void Serving::set_topping(Topping topping, int kind) {
    _toppings.push_back(topping);
    _top_kind.push_back(kind);
}

//set flavors
void Serving::set_flavor(Flavor flavor) {
    _flavors.push_back(flavor);
}

//total retail price
double Serving::get_total_retail_price() {
		double total=0; double f=0; double t;
		total = _container.get_retail_price();

		for(int i=0; i<_flavors.size(); i++){
				f+=_flavors[i].get_retail_price();
		}

		for(int i=0; i<_toppings.size(); i++){
			switch (_top_kind[i])
			{
			case 0:	t+=_toppings[i].get_retail_price()*1; break;
			case 1:	t+=_toppings[i].get_retail_price()*2; break;
			case 2:	t+=_toppings[i].get_retail_price()*3; break;
			case 3:	t+=_toppings[i].get_retail_price()*4; break;
			}
		}

	total = total + f + t;

	return total;
}

double Serving::get_total_wholesale_price() {
		double total=0; double f=0; double t;
		total = _container.get_wholesale_price();

		for(int i=0; i<_flavors.size(); i++){
				f+=_flavors[i].get_wholesale_price();
		}

		for(int i=0; i<_toppings.size(); i++){
			switch (_top_kind[i])
			{
			case 0:	t+=_toppings[i].get_wholesale_price()*1; break;
			case 1:	t+=_toppings[i].get_wholesale_price()*2; break;
			case 2:	t+=_toppings[i].get_wholesale_price()*3; break;
			case 3:	t+=_toppings[i].get_wholesale_price()*4; break;
			}
		}

	total = total + f + t;

	return total;
}



std::ostream& operator<<(std::ostream& os, Serving& serving) {
/*
    os << serving.get_container();
    for (Flavor s : serving.get_flavors()) os << std::endl << s;
    for (Topping t : serving.get_toppings()) os << std::endl << t;
    os << std::endl << std::setw(50) << "----------------------------"
    << std::endl << std::setw(40) << "Serving Total: $ " << serving.get_total_retail_price() << endl;
    return os;
*/
}
