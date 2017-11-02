#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<string>
#include "serving.h"
using namespace std;

class Customer{
	public:
		Customer(std::string name, int id, std::string phone);
		vector<Serving> servings;
		void create_serving(Serving serivng);
		string get_name();
		int get_id();
		string get_phone();
	private:
		string _name;
		int _id;
		string _phone;
		
};
#endif