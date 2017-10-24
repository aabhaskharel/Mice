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
        void on_new_container();
        void on_new_flavor();        
        void on_new_topping();        
        //void on_about_click();           // Display About dialog
        void on_quit_click();            // Exit

};
#endif 

