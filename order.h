#ifndef ORDER_H
#define ORDER_H
#include <vector>
#include "server.h"
#include "customer.h"
#include "serving.h"

using namespace std;

class Order{
	public:
		Order(int id, Server server, Customer customer); 
		
		void add_serving(Serving serving);
		Server get_server();
		Customer get_customer();		

		double get_total_price();
		double get_wholesale_price();
		vector<Serving> get_servings();
		int get_servings_size();
		int get_id();
		string get_state();
         	void fill();
		void pay();
		void cancel();
		string list_serving(int index);
		string list_order();
	private:
		int _id;
		vector <Serving> _servings;
		Server _server;
		Customer _customer;
		string _state = "Unfilled";
		
};

std::ostream& operator<<(std::ostream& os, Order& order);

#endif