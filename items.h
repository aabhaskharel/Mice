#ifndef _ITEMS_H_
#define _ITEMS_H_
using namespace std;
class Items {
	public:
		Items(string name, string description, int cost, int retail_price, int stock, string picture);
		string get_name();
		string get_description();
		int get_cost();
		int get_retail_price();
		int get_stock();
		int get_picture();
	private:
		string _name;
		string _description;
		int _cost;
		int _retail_cost;
		int _stock;
		string _picture;
};

class Flavor : public Items{}
class Topping : public Items{
	public:
		Topping(string name, string description, int cost, int retail_price, int stock, string picture, string type);
		string type();	
	private:
		string _type;
}
class Container : public Items{
	public:
		Container(string name, string description, int cost, int retail_price, int stock, string picture, int scoop);
		int scoops();
	private:
		int _scoop;
}

#endif