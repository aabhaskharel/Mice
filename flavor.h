#ifndef _FLAVOR_H_
#define _FLAVOR_H_
using namespace std;

class Flavor {
	public:
		Flavor(string name, int stock);
		string get_name();
		int remaining();
	private:
		string _name;
		int _stock;
};
#endif