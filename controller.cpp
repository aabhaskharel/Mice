#include <iostream>
#include "controller.h"
#include "dialogs.h"
#include "main_window.h"
#include "manager.h"

using namespace std;

void Controller::execute_cmd(int cmd) {

    if(cmd==1) {
        string name, desc; int stock;
        double wholesale, retail;
        bool cancel = false;
        
        // dialog for new flavor
        Gtk::Dialog *dialog = Gtk::manage(new Gtk::Dialog());
        //dialog->set_transient_for(win);
        dialog->set_title("Create a New Flavor");
        
        // name
        Gtk::HBox b_name;
        Gtk::Label l_name{"Name: "};
        l_name.set_width_chars(20);
        b_name.pack_start(l_name, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_name;
        e_name.set_max_length(50);
        b_name.pack_start(e_name, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);
        
        // desc
        Gtk::HBox b_desc;
        Gtk::Label l_desc{"Description: "};
        l_desc.set_width_chars(20);
        b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_desc;
        e_desc.set_max_length(50);
        b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);
        
        //stock
        Gtk::HBox b_stock;
        Gtk::Label l_stock{"Stock Remaining: "};
        l_stock.set_width_chars(20);
        b_stock.pack_start(l_stock, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_stock;
        e_stock.set_max_length(50);
        b_stock.pack_start(e_stock, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_stock, Gtk::PACK_SHRINK);
        
        // wholesale price
        Gtk::HBox b_wprice;
        Gtk::Label l_wprice{"Wholesale Price: "};
        l_wprice.set_width_chars(20);
        b_wprice.pack_start(l_wprice, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_wprice;
        e_wprice.set_max_length(50);
        b_wprice.pack_start(e_wprice, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_wprice, Gtk::PACK_SHRINK);
        
        // retail price
        Gtk::HBox b_rprice;
        Gtk::Label l_rprice{"Retail Price: "};
        l_rprice.set_width_chars(20);
        b_rprice.pack_start(l_rprice, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_rprice;
        e_rprice.set_max_length(50);
        b_rprice.pack_start(e_rprice, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_rprice, Gtk::PACK_SHRINK);
        
        //show dialog
        dialog->add_button("Cancel", 0);
        dialog->add_button("OK", 1);
        dialog->show_all();
        int result = dialog->run();

        dialog->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        
        //missing some exception handeling
        name = e_name.get_text();
        desc = e_desc.get_text();
        stock = stoi(e_stock.get_text());
        wholesale = stod(e_wprice.get_text());
        retail = stod(e_rprice.get_text());
        
        if (result == 1)
            cout << "Success" << endl; //this is where model code goes.
        
    } else if (cmd==2) {
        string name, desc; int stock;
        double wholesale, retail;
        bool cancel = false;
        
        // dialog for new topping
        Gtk::Dialog *dialog = new Gtk::Dialog();
        dialog->set_title("Create a New Topping");
        
        // name
        Gtk::HBox b_name;
        Gtk::Label l_name{"Name: "};
        l_name.set_width_chars(20);
        b_name.pack_start(l_name, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_name;
        e_name.set_max_length(50);
        b_name.pack_start(e_name, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);
        
        // desc
        Gtk::HBox b_desc;
        Gtk::Label l_desc{"Description: "};
        l_desc.set_width_chars(20);
        b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_desc;
        e_desc.set_max_length(50);
        b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);
        
        //stock
        Gtk::HBox b_stock;
        Gtk::Label l_stock{"Stock Remaining: "};
        l_stock.set_width_chars(20);
        b_stock.pack_start(l_stock, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_stock;
        e_stock.set_max_length(50);
        b_stock.pack_start(e_stock, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_stock, Gtk::PACK_SHRINK);
        
        // wholesale price
        Gtk::HBox b_wprice;
        Gtk::Label l_wprice{"Wholesale Price: "};
        l_wprice.set_width_chars(20);
        b_wprice.pack_start(l_wprice, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_wprice;
        e_wprice.set_max_length(50);
        b_wprice.pack_start(e_wprice, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_wprice, Gtk::PACK_SHRINK);
        
        // retail price
        Gtk::HBox b_rprice;
        Gtk::Label l_rprice{"Retail Price: "};
        l_rprice.set_width_chars(20);
        b_rprice.pack_start(l_rprice, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_rprice;
        e_rprice.set_max_length(50);
        b_rprice.pack_start(e_rprice, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_rprice, Gtk::PACK_SHRINK);
        
        //show dialog
        dialog->add_button("Cancel", 0);
        dialog->add_button("OK", 1);
        dialog->show_all();
        int result = dialog->run();

        dialog->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        
        //missing some exception handeling
        name = e_name.get_text();
        desc = e_desc.get_text();
        stock = stoi(e_stock.get_text());
        wholesale = stod(e_wprice.get_text());
        retail = stod(e_rprice.get_text());
        
        if (result == 1)
            cout << "Success" << endl; //this is where model code goes.
        
    } else if (cmd==3) {
        string name, desc; int stock, size;
        double wholesale, retail;
        bool cancel = false;
        
        // dialog for new flavor
        Gtk::Dialog *dialog = new Gtk::Dialog();
        dialog->set_title("Create a New Container");
        
        // name
        Gtk::HBox b_name;
        Gtk::Label l_name{"Name: "};
        l_name.set_width_chars(20);
        b_name.pack_start(l_name, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_name;
        e_name.set_max_length(50);
        b_name.pack_start(e_name, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);
        
        // desc
        Gtk::HBox b_desc;
        Gtk::Label l_desc{"Description: "};
        l_desc.set_width_chars(20);
        b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_desc;
        e_desc.set_max_length(50);
        b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);
        
        //stock
        Gtk::HBox b_stock;
        Gtk::Label l_stock{"Stock Remaining: "};
        l_stock.set_width_chars(20);
        b_stock.pack_start(l_stock, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_stock;
        e_stock.set_max_length(50);
        b_stock.pack_start(e_stock, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_stock, Gtk::PACK_SHRINK);
        
        //size  it can hold
        Gtk::HBox b_size;
        Gtk::Label l_size{"Scoop Size: "};
        l_size.set_width_chars(20);
        b_size.pack_start(l_size, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_size;
        e_size.set_max_length(50);
        b_size.pack_start(e_size, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_size, Gtk::PACK_SHRINK);
        
        // wholesale price
        Gtk::HBox b_wprice;
        Gtk::Label l_wprice{"Wholesale Price: "};
        l_wprice.set_width_chars(20);
        b_wprice.pack_start(l_wprice, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_wprice;
        e_wprice.set_max_length(50);
        b_wprice.pack_start(e_wprice, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_wprice, Gtk::PACK_SHRINK);
        
        // retail price
        Gtk::HBox b_rprice;
        Gtk::Label l_rprice{"Retail Price: "};
        l_rprice.set_width_chars(20);
        b_rprice.pack_start(l_rprice, Gtk::PACK_SHRINK);
        
        Gtk::Entry e_rprice;
        e_rprice.set_max_length(50);
        b_rprice.pack_start(e_rprice, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_rprice, Gtk::PACK_SHRINK);
        
        //show dialog
        dialog->add_button("Cancel", 0);
        dialog->add_button("OK", 1);
        dialog->show_all();
        int result = dialog->run();

        dialog->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        
        //missing some exception handeling
        name = e_name.get_text();
        desc = e_desc.get_text();
        stock = stoi(e_stock.get_text());
        size = stoi(e_size.get_text());
        wholesale = stod(e_wprice.get_text());
        retail = stod(e_rprice.get_text());
        
        if (result == 1)
            cout << "Success" << endl; //this is where model code goes
        
    } else {
        cout << "Invalid Input!" << endl;
        exit(0);
    }
}

