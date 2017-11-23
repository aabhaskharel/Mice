#ifndef ORDER_H
#define ORDER_H
#include <vector>
#include <fstream>
#include "person.h"
#include "serving.h"

using namespace std;

class Order{
	public:
		Order(int id, Server server, Customer customer);
		Order(std::istream& ist);
    	void save(std::ostream& ost);

		void add_serving(Serving serving);
		Server get_server();
		Customer get_customer();

		double get_total_retail_price();
		double get_total_wholesale_price();
		vector<Serving> get_servings();

		int get_servings_size();

		int get_id();
		string get_state();
        void set_state(string state);
		string list_serving(int index);
		string list_order();
	private:
		int _id;
		vector <Serving> _servings;
		Server _server{"TBD", -1, "TBD", 0};
		Customer _customer{"", -1, ""};
		string _state;

};

std::ostream& operator<<(std::ostream& os, Order& order);

#endif
