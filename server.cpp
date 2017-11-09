#include <vector>
#include "server.h"
using namespace std;

//constructor
Server::Server(string name, int employee_number, int total_filled, double hourly_salary): _name{name}, _employee_number{employee_number}, _total_filled{0}, _hourly_salary{hourly_salary}{}	

//to get server's name
string Server::get_name(){ return _name; }

//to get server's employee number
int Server::get_employee_number(){ return _employee_number; }

//to get server's total orders filled in career
int Server::get_total_filled(){ return _total_filled; }

//to increment totall orders filled
void Server::filled(){
	_total_filled++;
	if(_total_filled == 10){
		pay_server();
		_total_filled == 0;
	}
}

//to get server's hourly salary/pay
double Server::get_hourly_salary(){ return _hourly_salary; }

//to pay the server
void Server::pay_server(){
	_total_earned += get_hourly_salary();
}

//get total earned salary
double Server::get_total_earned(){ return _total_earned; }


