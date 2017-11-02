#include <iostream>
#include <string>
#include <vector>
#include "manager.h"
#include "serving.h"
#include "items.h"

using namespace std;

//constructor
Serving::Serving(Container cont, vector<Flavor> flav, vector<Topping> top): _cont{cont}, _flav{flav}, _top{top}{}

//which container
string Serving::container(){
		return _cont.get_name();
		}

//which flavor
string Serving::flavor(int index){
		return _flav[index].get_name();
		}
		
//which topping
string Serving::topping(int index){
		return _top[index].get_name();
		}

//total retail price
double Serving::total_retail_price(){
		int total=0; int f=0; int t;
		total = _cont.get_retail_price();
		
		for(int i=0; i<_flav.size(); i++){
				f+=_flav[i].get_retail_price();	
		}
		
		for(int i=0; i<_top.size(); i++){
				t+=_top[i].get_retail_price();
		}
		
	total = total + f + t;
	
	return total;
}

		
