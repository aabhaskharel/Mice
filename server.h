#ifndef SERVER_H
#define SERVER_H
#include <string>

using namespace std;

class Server{
	private:
		string _name;
		int _employee_number;
		int _total_filled; //total orders filled in career
		double _hourly_salary;
		double _total_earned = 0;
	public:
		Server(string name, int employee_number, double hourly_salary);
		string get_name();
		int get_employee_number();
		int get_total_filled();
		double get_hourly_salary();
		void pay_server();
		double get_total_earned();
		void filled();
};
#endif
