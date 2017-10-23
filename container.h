#ifndef _CONTAINER_H_
#define _CONTAINER_H_

class Container {
	public:
		Contrainer(string _name, int flavor_capacity, int topping capacity);
		string get_name();
		int get_flav_capacity();
		int get_top_capacity();

	private:
		string _name;
		int _flavor_capacity;
		int _topping_capacity;
	
};

#endif