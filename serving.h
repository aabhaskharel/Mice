#ifndef SERVING_H
#define SERVER_H

using namespace std;

class Serving{
	private:
		Container _cont; //index numbers
		vector<Flavor>  _flav;
		vector<Flavor> _top;

	public:
		Serving(Container cont, vector<Flavor>  flav, vector<Topping> top);
		string set_container();
		string set_flavor(int index);
		string set_topping(int index);
		double total_retail_price();
		
};
#endif

	