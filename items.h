#ifndef _ITEMS_H_
#define _ITEMS_H_

#include <string>
using namespace std;

class Items {
	public:
		Items(string name, string description, double wholesale_price, double retail_price, int stock, string image_path);
		string get_name();
		string get_description();
		double get_wholesale_price();
		double get_retail_price();
		int get_stock();
		string get_image_path();
		
		virtual string get_type();

	protected:
		string  _name;
		string _description;
		double _wholesale_price;
		double _retail_price;
		int _stock;
		string _image_path;
};

class Flavor : public Items{
	public:
		Flavor(string name, string description, double wholesale_price, double retail_price, int stock, string image_path);
		string get_type() override;
};
class Topping : public Items{
	public:
		Topping(string name, string description, double cost, double retail_price, int stock, string image_path, string type);
		string get_amount();	
		string get_type() override;
	private:
		string _amount;
};
class Container : public Items{
	public:
		Container(string name, string description, double cost, double retail_price, int stock, string image_path, int scoop);
		int get_scoop();
		string get_type() override;
	private:
		int _scoop;
};


#endif