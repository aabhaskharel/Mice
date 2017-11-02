#include "controller.h"
#include <vector>

void Controller::execute_cmd(int cmd) {
	res.clear();
	switch (cmd)
	{
	case 42:emp.populate_emporium();
		break;
		
	case 4:{res = Dialogs::form(1);
		if (res.size() == 7) { 
			Container cont(res[0], res[1], stod(res[2]), stod(res[3]), stoi(res[4]), res[5], stoi(res[6]));
		emp.add_new_container(cont);
		}
		break;
		}
		
	case 2:{res = Dialogs::form(2);
		if (res.size() == 6) {
			Flavor flav(res[0], res[1], stod(res[2]), stod(res[3]), stoi(res[4]), res[5]);
		emp.add_new_flavor(flav);
		}
		break;
		}
		
	case 3:{res = Dialogs::form(3);
		if (res.size() == 6) {
			Topping top(res[0], res[1], stod(res[2]), stod(res[3]), stoi(res[4]), res[5], "Light");
		emp.add_new_topping(top);
		}
		break;
		}
		
	case 5:{res = Dialogs::add_server();
		if (res.size() == 2) {
			Server ser(res[0], emp.get_servers().size()+1, 0, stod(res[1]));
		emp.add_new_server(ser);
		}
		break;
		}
		
	case 7:{res = Dialogs::add_customer();
		if (res.size() == 2) {
			Customer cust(res[0], emp.get_customers().size()+1, res[2]);
		emp.add_new_customer(cust);
		}
		break;
		}
		
	case 6://emp.create_servings(Dialogs::create_serving(emp));
		break;
		
	case 8: break;
	case 9: break;
		
	case 0:	exit(0);

		break;
	}
}

