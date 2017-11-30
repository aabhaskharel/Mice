#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include <string>
#include <iostream>
#include "emporium.h"
#include "items.h"
#include "serving.h"
#include "order.h"
#include "person.h"

class Main_window : public Gtk::Window
{
    public:
        Main_window();
        virtual ~Main_window();

    protected:
    	void on_new_mgmt_click();
    	void on_pop_mgmt_click();

        void on_new_role();

    	void on_new_item();
        void on_new_person(std::string role);
    	void on_new_server();
    	void on_new_order();
    	void on_new_customer();
    	void on_new_manager();

        //order states
        void on_cancel_order();
        void on_fill_order();
        void on_pay_order();

    	//file calls
    	void on_save_click();
        void on_load_click();

    	//edit calls
    	void on_edit_item_click();
        void on_edit_server_click();
        void on_edit_customer_click();
        void on_edit_manager_click();

        void on_happy_hour_click();

        void on_restore_person_click();
        void on_restore_item_click();

    	//report callbacks
        void on_receipt_click();
    	void on_servers_report();
    	void on_customers_report();
    	void on_inventory_report();
    	void on_orders_report();
    	void on_pnl_report();

    	void on_contents_click();
        void on_about_click();           // Display About dialog
        void on_quit_click();            // Exit

        void on_test();
        void on_order_update();
    	int select_from_vector(std::vector<std::string> names, std::string title);
        int select_from_grid(std::vector<std::string> names, std::vector<std::string> path, std::string title);
    	Serving create_serving();

    private:
        int emp_id = 0;
        vector<string> all_pnl;
        bool first_report = true;
        Emporium emp{ emp_id, "Euless", "817-722-1222"};

        Gtk::Box *vbox;

        Gtk::Label *msg;

        Gtk::ScrolledWindow *s_window;
        Gtk::Image *banner;
        bool present = false; //presence of ScrolledWindow
        bool p_banner = false;

        Gtk::MenuItem *menuitem_new;
        Gtk::MenuItem *menuitem_save;
        Gtk::MenuItem *menuitem_load;

        Gtk::MenuItem *menuitem_edit;
        Gtk::MenuItem *menuitem_eitem;
        Gtk::MenuItem *menuitem_happy_hour;
        Gtk::MenuItem *menuitem_ecustomer;
        Gtk::MenuItem *menuitem_eserver;
        Gtk::MenuItem *menuitem_emanager;
        Gtk::MenuItem *menuitem_restore_item;
        Gtk::MenuItem *menuitem_restore_person;

        Gtk::MenuItem *menuitem_add_customer;
        Gtk::MenuItem *menuitem_item;
        Gtk::MenuItem *menuitem_add_server;
        Gtk::MenuItem *menuitem_new_manager;

        Gtk::MenuItem *menuitem_fill;
        Gtk::MenuItem *menuitem_pay;

        Gtk::MenuItem *menuitem_reports;

        Gtk::ToolButton *new_customer_button;
        Gtk::ToolButton *new_item_button;
};
#endif
