#ifndef SERVER_H
#define SERVER_H
#include "customer.h"
using namespace std;

class Server{
	private:
		string _name;
		int _employee_number;
		int _total_filled; //total orders filled in career
		int _hourly_salary;
	public:
		vector<Serving> servings;
		vector<Customer> customers;
		Server(string name, int employee_number, int total_filled, int hourly_salary);
		void create_serving(Serving serving);
		void create_customer(Customer customer);
		string get_name();
		int get_employee_number();
		int get_total_filled();
		int get_hourly_salary();
};
#endif

	