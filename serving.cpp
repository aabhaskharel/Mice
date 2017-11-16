#include <vector>
#include <iostream>
#include <iomanip>
#include "serving.h"

using namespace std;

//constructor
Serving::Serving(Containr container): _container{container} {}

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



std::ostream& operator<<(std::ostream& os, const Serving& serving) {
  /*  os << serving.get_container();
    for (Flavor s : serving.get_flavors()) os << std::endl << s;
    for (Topping t : serving.get_toppings()) os << std::endl << t;
    os << std::endl << std::setw(50) << "----------------------------" 
    << std::endl << std::setw(40) << "Serving Total: $ " << serving.total_retail_price() << endl;
    return os; */
}

