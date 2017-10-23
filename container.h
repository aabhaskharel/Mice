#ifndef _CONTAINER_H_
#define _CONTAINER_H_
using namespace std;

class Container {
	public:
		Container(string _name, int flavor_capacity, int topping_capacity);
		string get_name();
		int get_flav_capacity();
		int get_top_capacity();

	private:
		string _name;
		int _flavor_capacity;
		int _topping_capacity;
	
};

#endif