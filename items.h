#ifndef _ITEMS_H_
#define _ITEMS_H_

#include <string>
#include <fstream>

using namespace std;

class Items {
	public:
		Items(string name, string description, double wholesale_price, double retail_price, string image_path);
		Items();
		string get_name();
		string get_description();
		double get_wholesale_price();
		double get_retail_price();
		void set_retail_price(double price);
		int get_stock();
		void set_stock(int quantity);
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

std::ostream& operator<<(std::ostream& os, const Items& item);

class Flavor : public Items{
	public:
		Flavor(string name, string description, double wholesale_price, double retail_price, string image_path);
		Flavor(std::istream& ist);
    	void save(std::ostream& ost);
		string get_type() override;
};
class Topping : public Items{
	public:
		Topping(string name, string description, double wholesale_price, double retail_price, string image_path);
		Topping(std::istream& ist);
    	void save(std::ostream& ost);
		string get_type() override;

		int get_amount();
		void set_amount(int amount);
	private:
		int _amount = 0; // 1 - Light, 2 - Normal, 3 - Extra, 4 - Drenched
};
class Containr : public Items{
	public:
		Containr(string name, string description, double wholesale_price, double retail_price, string image_path, int scoop);
		Containr(std::istream& ist);
    	void save(std::ostream& ost);
		int get_scoop();
		string get_type() override;
	private:
		int _scoop;
};



#endif
