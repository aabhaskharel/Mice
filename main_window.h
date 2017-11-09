#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include <string>
#include "emporium.h"
#include "dialogs.h"
#include "items.h"
#include "server.h"
#include "serving.h"
#include "order.h"

class Main_window : public Gtk::Window
{
    public:
        Main_window();
        virtual ~Main_window();

    protected:
	void on_new_mgmt_click();
	void on_pop_mgmt_click();	
        void on_new_container();
        void on_new_flavor();        
        void on_new_topping();
	void on_new_server();
	void on_new_order();
	void on_new_customer();
	void on_new_manager();

	//report callbacks
	void on_servers_report();
	void on_customers_report();
	void on_inventory_report();
	void on_orders_report();
	void on_pnl_report();
    
	void on_contents_click();    
        void on_about_click();           // Display About dialog
        void on_quit_click();            // Exit

	int select_from_vector(std::vector<std::string> names, std::string title);
	Serving create_serving();

};
#endif 

