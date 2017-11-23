#include "person.h"
#include <stdexcept>

using namespace std;

Person::Person(string name, int id, string phone): _name{name}, _id{id}, _phone{phone}  {}
Person::Person() : _name{""}, _id{-1}, _phone{""} { }

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
Manager::Manager(std::istream& ist) {
    // The header must have been stripped from the incoming stream at this point
    getline(ist, _name);
    ist >> _id; ist.ignore();
    getline(ist, _phone);
}

void Manager::save(std::ostream& ost) {
    ost << "#" << std::endl << "MANAGER" << std::endl; // header
    ost << _name << std::endl;
    ost << _id << std::endl;
    ost << _phone << std::endl;
}

Server::Server(string name, int id, string phone, double hourly_salary): Person(name, id, phone), _hourly_salary{hourly_salary}, _total_filled{0}, total_pay{0}, x{0} {}
Server::Server(std::istream& ist) {
    // The header must have been stripped from the incoming stream at this point
    getline(ist, _name);
    ist >> _id; ist.ignore();
    getline(ist, _phone);
    ist >> _hourly_salary; ist.ignore();
    ist >> _total_filled; ist.ignore();
}

void Server::save(std::ostream& ost) {
    ost << "#" << std::endl << "SERVER" << std::endl; // header
    ost << _name << std::endl;
    ost << _id << std::endl;
    ost << _phone << std::endl;
    ost << _hourly_salary << std::endl;
    ost << _total_filled << std::endl;
}

Customer::Customer(string name, int id, string phone) : Person(name, id, phone) {}
Customer::Customer(std::istream& ist) {
    // The header must have been stripped from the incoming stream at this point
    getline(ist, _name);
    ist >> _id; ist.ignore();
    getline(ist, _phone);
}

void Customer::save(std::ostream& ost) {
    ost << "#" << std::endl << "CUSTOMER" << std::endl; // header
    ost << _name << std::endl;
    ost << _id << std::endl;
    ost << _phone << std::endl;
}

string Person::get_name() {return _name;}

int Person::get_id() {return _id;}

string Person::get_phone() {return _phone;}

int Person::get_type() {return 1;}

int Manager::get_type() {return 2;}

int Server::get_type() {return 3;}

int Customer::get_type() {return 4;}


int Server::get_total_filled() {return _total_filled;}
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
