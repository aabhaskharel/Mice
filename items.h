#ifndef _ITEMS_H_
#define _ITEMS_H_
using namespace std;

class Items {
	public:
		Items(string name, string description, double cost, double retail_price, int stock);
		string get_name();
		string get_description();
		double get_cost();
		double get_retail_price();
		int get_stock();
	protected:
		string  _name;
		string _description;
		double _cost;
		double _retail_price;
		int _stock;
};

class Flavor : public Items{
	public:
		Flavor(string name, string description, double cost, double retail_price, int stock);
};
class Topping : public Items{
	public:
		Topping(string name, string description, double cost, double retail_price, int stock, string type);
		string type();	
	private:
		string _type;
};
class Container : public Items{
	public:
		Container(string name, string description, double cost, double retail_price, int stock, int scoop);
		int scoops();
	private:
		int _scoop;
};


#endif