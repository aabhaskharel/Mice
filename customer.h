#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{

	public:
		std::string get_name();
		int get_id();
		std::string get_phone();
	private:
		std::string _name;
		int _id;
		std::string _phone;
		
};
#endif