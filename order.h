#ifndef ORDER_H
#define ORDER_H
#include <vector>
#include "server.h"
#include "customer.h"
#include "serving.h"

using namespace std;

class Order{
	public:
		Order(int id); 
		
		void add_serving(Serving serving);
		//void add_server(Server server);
		//void add_customer(Customer customer);
		
		double get_total_price();
		vector<Serving> get_servings();

		void fill();
		void pay();
		void cancel();
		string list_serving(int index);
		string list_order();
	private:
		int _id;
		vector <Serving> _servings;
		//Server _server;
		//Customer _customer;
		string _state = "Unfilled";
		
};

std::ostream& operator<<(std::ostream& os, Order& order);

#endif