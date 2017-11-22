#ifndef PERSON_H
#define PERSON_H
 
#include <string>

using namespace std;

class Person {
public:
	Person(string name, int id, string phone);
	string get_name();
	int get_id();
	string get_phone();
	virtual int get_type();

protected:
	string _name;
	int _id;
	string _phone;

};

/*
class Owner: public Person {
public:
	static Owner& getInstance();
	Owner (Owner const&);
	void operator=(Owner const&);	

private:
	Owner() {};
};
*/

class Manager: public Person {
public:
	Manager(string name, int id, string phone);
	int get_type() override;
};

class Server: public Person {
public:
	Server(string name, int id, string phone, double hourly_salary);
	int get_type() override;
	double get_total_pay();
	int get_total_filled();
	double get_hourly_salary();
	void set_hourly_salary(double salary);
	void set_total_filled(int fill);
	void set_total_pay(double total);
	bool pay();
private:
	double _hourly_salary;
	int _total_filled ;
	double total_pay;
	int x;

};

class Customer:public Person {
public:
	Customer(string name, int id, string phone);
	int get_type() override;
};


#endif