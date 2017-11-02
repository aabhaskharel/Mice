#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include "controller.h"

class Main_window : public Gtk::Window
{
    public:
        Main_window();
        virtual ~Main_window();

    protected:
	void on_new_mgmt_click();
	void on_pop_mgmt_click();	//still to be coded
        void on_new_container();
        void on_new_flavor();        
        void on_new_topping();    
	void on_contents_click();    
        void on_about_click();           // Display About dialog
        void on_quit_click();            // Exit
	void on_create_server();


};
#endif 

