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
		void fill();
		void pay();
		void cancel();
	private:
		int _id;
		vector <Serving> _servings;
		//Server _server;
		//Customer _customer;
		string _state = "Unfilled";
		
};
#endif