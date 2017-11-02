#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "manager.h"
#include "help.h"
#include "items.h"
#include "server.h"
#include "emporium.h"
#include "dialogs.h"

class Controller {
    public:
	    void execute_cmd(int cmd);
	    //void create_emporium();
   
   private:
	Emporium emp;
	Help help;
	vector<string> res;
}; 
#endif
