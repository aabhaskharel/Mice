#ifndef SERVING_H
#define SERVER_H

using namespace std;

class Serving{
	private:
		int _container; //index numbers
		int _flavor;
		int _topping;

	public:
		Serving(int container, int flavor, int toppping);
		string set_container();
		string set_flavor();
		string set_topping();
		double total_retail_price();
		
};
#endif

	