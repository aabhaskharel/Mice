#ifndef _ITEMS_H_
#define _ITEMS_H_

#include <string>
using namespace std;

class Items {
	public:
		Items(string name, string description, double wholesale_price, double retail_price, int stock, string image_path);
		string get_name() const;
		string get_description() const;
		double get_wholesale_price() const;
		double get_retail_price() const;
		int get_stock() const;
		void restock(int value = 25);
		bool consume(int value = 1);
		string get_image_path();
		
		virtual string get_type() const;

	protected:
		string  _name;
		string _description;
		double _wholesale_price;
		double _retail_price;
		int _stock;
		string _image_path;
};

//Operator Overloading
std::ostream& operator<<(std::ostream& os, const Items& item);

class Containr : public Items{
	public:
		Containr(string name, string description, double cost, double retail_price, int stock, string image_path, int scoop);
		int get_scoop() const;
		string get_type() const override;
	private:
		int _scoop;
};

class Flavor : public Items{
	public:
		Flavor(string name, string description, double wholesale_price, double retail_price, int stock, string image_path);
		string get_type() const override;
};
class Topping : public Items{
	public:
		Topping(string name, string description, double cost, double retail_price, int stock, string image_path, string type);
		string get_amount() const;	
		string get_type() const override;
	private:
		void _set_amount(string amount);
		string _amount;
};

#endif