#ifndef SERVING_H
#define SERVER_H
#include <vector>
#include "items.h"

using namespace std;

class Serving{
	private:
		Container _cont; //index numbers
		vector<Flavor>  _flav;
		vector<Topping> _top;

	public:
		Serving(Container cont, vector<Flavor>  flav, vector<Topping> top);
		string container();
		string flavor(int index);
		string topping(int index);
		double total_retail_price();
		
};
#endif

	