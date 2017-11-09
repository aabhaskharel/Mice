#ifndef MANAGER_H
#define MANAGER_H
#include<string>

using namespace std;

class Manager{
	public:
		Manager(string name, int id, string phone);
		string get_name();
		int get_id();
		string get_phone();
	private:
		string _name;
		int _id;
		string _phone;	
};

std::ostream& operator<<(std::ostream& os, const Manager& manager);

#endif