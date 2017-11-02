#include "controller.h"

void Controller::execute_cmd(int cmd) {

	switch (cmd)
	{
	case 1:manager = new Manager();
		break;
	case 2:manager->add_new_flavor();
		break;
	case 3:manager->add_new_topping();
		break;
	case 4:manager->add_new_container();
		break;
	case 8:help.contents();
		break;
	case 9:help.about();
		break;
	case 42:manager->populate_mgmt();
		break;
	case 21:Dialogs::serving();
		break;
		
	case 0:	exit(0);

		break;
	}
}

