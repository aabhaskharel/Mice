#include "person.h"

using namespace std;

Person::Person(string name, int id, string phone): _name{name}, _id{id}, _phone{phone}  {}

/*
Owner::Owner(Owner const&) : Person("Safal Lamsal", 1, "1111111111") {}

Owner::Owner& getInstance() {
	static Owner instance;
	return instance;
}

Owner::Owner(Owner const&) = delete;

Owner::void operator=(Owner const&) = delete;
*/

Manager::Manager(string name, int id, string phone) : Person(name, id, phone) {}

Server::Server(string name, int id, string phone, double hourly_salary): Person(name, id, phone), _hourly_salary{hourly_salary}, _total_filled{0}, total_pay{0}, x{0} {}	

Customer::Customer(string name, int id, string phone) : Person(name, id, phone) {}

string Person::get_name() {return _name;}

int Person::get_id() {return _id;}

string Person::get_phone() {return _phone;}

int Person::get_type() {return 1;}

int Manager::get_type() {return 2;}

int Server::get_type() {return 3;}

int Customer::get_type() {return 4;}


double Server::get_total_filled() {return _total_filled;}
double Server::get_hourly_salary() {return _hourly_salary;}
void Server::set_hourly_salary(double salary) { _hourly_salary = salary;}
	

double Server::get_total_pay() {return total_pay;}
void Server::set_total_pay(double total) { total_pay += total; }

bool Server::pay() {
	if (x >= 10)
	{
		x = x % 10;
		return true;
	}
	return false;	
}	

void Server::set_total_filled(int fill) {
	_total_filled += fill; 
	x += fill % 10;
		
}
