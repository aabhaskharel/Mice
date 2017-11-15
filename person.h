#ifndef PERSON_H
#define PERSON_H

//#include "cashregister.h"

using namespace std;

Class Person {
public:
	Person(string name, int id, string phone);
	string get_name();
	int get_id();
	string phone();
	virtual int get_type();

protected:
	string _name;
	int _id;
	string _phone;

};

Class Owner: public Person {
public:
	static Owner& getInstance();
	Owner (Owner const&);
	void operator=(Owner const&);	

private:
	Owner() {};
};

Class Manager: public Person {
public:
	Manager(string name, int id, string phone);
	int get_type() override;
};

Class Server: public Person {
public:
	Server(string name, int id, string phone, double hourly_salary);
	int get_type() override;
	double get_total_pay();
	double get_total_filled();
	double get_hourly_salary();
	void set_hourly_salary(double salary);
	void set_total_filled(int fill);
private:
	double _hourly_salary;
	int _total_filled = 0;
	double total_pay = 0;

};

Class Customer:public Person {
	Customer(string name, int id, string phone);
	int get_type() override;
};


#endif