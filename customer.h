#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{

	public:
		Customer(std::string name, int id, std::string phone);
		std::string get_name();
		int get_id();
		std::string get_phone();
	private:
		std::string _name;
		int _id;
		std::string _phone;
		
};
#endif