#include "person.h"

using namespace std;

Person::Person(string name, int id, string phone): _name{name}, _id{id}, _phone{phone}  {}

Owner::Owner(Owner const&) : Person("Safal Lamsal", 1, "1111111111") {}

Owner::Owner& getInstance() {
	static Owner instance;
	return instance;
}

Owner::Owner(Owner const&) = delete;

Owner::void operator=(Owner const&) = delete;

Manager::Manager(string name, int id, string phone) : Person(name, id, phone) {}

Server::Server(string name, int id, string phone, double hourly_salary): Person(name, id, phone), _hourly_salary{hourly_salary} {}	

Customer::Customer(string name, int id, string phone) : Person(name, id, phone) {}

Person::string get_name() {return _name}

Person::int get_id() {return _id}

Person::string phone() {return _phone}

Person::int get_type() {return 1;}

Manager::int get_type() {return 2;}

Server::int get_type() {return 3;}

Customer::int get_type() {return 4;}


Server::double get_total_filled() {return _total_filled;}
Server::double get_hourly_salary() {return _hourly_salary;}
Server::void set_hourly_salary(double salary) { _hourly_salary = salary;}
	

Server::double get_total_pay() {return total_pay};

Server::void set_total_filled(int fill) {
	_total_filled += fill; 
	if(_total_filled % 10 == 0 && _total_filled!=0){
		_total_pay += _hourly_salary;
	}
		
}
