#ifndef _TOPPING_H_
#define _TOPPING_H_

class Topping {
	public:
		Topping(string name, int stock);
		string get_name();
		int remaining();
	private:
		string _name;
		int _stock;
};
#endif