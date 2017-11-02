#include "controller.h"
#include <vector>

void Controller::execute_cmd(int cmd) {

	switch (cmd)
	{
	case 1:manager = new Manager();
		break;
	case 2:manager->add_new_flavor(emp);
		break;
	case 3:manager->add_new_topping(emp);
		break;
	case 4:manager->add_new_container(emp);
		break;
	case 8:help.contents();
		break;
	case 9:help.about();
		break;
	case 42:manager->populate_mgmt();
		break;
	case 0:	exit(0);
		break;
	}
}

/*
void Controller::create_emporium(){
    vector<Container> conts = manager->get_containers();
    vector<Flavor> flavs = manager->get_flavors();
    vector<Topping> tops = manager->get_toppings();
    vector<Server> servs = manager->get_servers();
    
    emp = new Emporium {conts, flavs, tops, servs};
}
*/
