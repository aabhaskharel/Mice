#include <vector>
#include "serving.h"

using namespace std;

//constructor
Serving::Serving(Container container): _container{container} {}

//return container
Container Serving::get_container(){
		return _container;
}

//return flavors
vector<Flavor> Serving::get_flavors(){
		return _flavors;
}
		
//return toppings
vector<Topping> Serving::get_toppings(){
		return _toppings;
		}

//total retail price
double Serving::total_retail_price(){
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
double Serving::total_wholesale_price(){
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

