#include "main_window.h"

void Main_window::on_happy_hour_click() {

    bool hour = emp.happy_hour();
    if (p_banner && !hour) vbox->remove(*banner);

    if(hour) {
        banner = Gtk::manage(new Gtk::Image("data/pictures/banner.png"));
        vbox->pack_start(*banner);
        vbox->show_all();
        p_banner = true;
    }
}

void Main_window::on_edit_item_click() {

    vector<Containr> _containers = emp.get_containers();
    vector<Flavor> _flavors = emp.get_flavors();
    vector<Topping> _toppings = emp.get_toppings();
    vector<string> names;

    // /////////////////////////////
    // Select Item Type
    Gtk::Dialog dialog_type{"Select Item Type", *this};
    //dialog_type.set_title("Select Item Type");
    const int WIDTH = 15;

    // Type
    Gtk::HBox b_type;

    Gtk::Label l_type{"Type:"};
    l_type.set_width_chars(WIDTH);
    b_type.pack_start(l_type, Gtk::PACK_SHRINK);

    // TODO: Replace this with 3 large, colorful buttons
    Gtk::ComboBoxText c_type;
    c_type.set_size_request(WIDTH*10);
    const int CONTAINER = 0;
    c_type.append("Container");
    const int SCOOP = 1;
    c_type.append("Ice Cream Flavor");
    const int TOPPING = 2;
    c_type.append("Topping");
    b_type.pack_start(c_type, Gtk::PACK_SHRINK);
    dialog_type.get_vbox()->pack_start(b_type, Gtk::PACK_SHRINK);

    // Show dialog_type
    dialog_type.add_button("Cancel", 0);
    dialog_type.add_button("OK", 1);

    dialog_type.show_all();
    if (dialog_type.run() != 1) {
        dialog_type.close();
        return;
    }

    int type = c_type.get_active_row_number();

    dialog_type.close();

	//check for Available items
	if (type == CONTAINER) {
		if(_containers.size() == 0 ) {
			Gtk::MessageDialog dialog{*this, "Add at least one container to edit!"};
		    dialog.run();
		    dialog.close();
			return;
		}
	} else if (type == SCOOP) {
		if(_flavors.size() == 0 ) {
			Gtk::MessageDialog dialog{*this, "Add at least one flavor to edit!"};
		    dialog.run();
		    dialog.close();
			return;
		}
	} else {
		if(_toppings.size() == 0 ) {
			Gtk::MessageDialog dialog{*this, "Add at least one topping to edit!"};
		    dialog.run();
		    dialog.close();
			return;
		}
	}

    // //////////////////////////////
    // edit Item

    Gtk::Dialog dialog;
    if (type == CONTAINER) dialog.set_title("Edit Container");
    else if (type == SCOOP) dialog.set_title("Edit Flavor");
    else dialog.set_title("Edit Topping");
    dialog.set_transient_for(*this);

    // Name
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(WIDTH);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    //edit magic
    Gtk::ComboBoxText c_index;
    c_index.set_size_request(WIDTH*10);
    if(type==CONTAINER) {
        for(Containr c: _containers) names.push_back(c.get_name());
        for(std::string s : names) c_index.append(s);
    } else if(type==SCOOP) {
        names.clear();
        for(Flavor f: _flavors) names.push_back(f.get_name());
        for(std::string s : names) c_index.append(s);
    } else {
        for(Topping t: _toppings) names.push_back(t.get_name());
        for(std::string s : names) c_index.append(s);
    }
    b_name.pack_start(c_index, Gtk::PACK_SHRINK);

    //Gtk::Entry e_name;
    //e_name.set_max_length(WIDTH*4);
    //b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

    // TODO: Replace this with a Gtk::TextView inside a Gtk::ScrolledWindow
    // Description
    Gtk::HBox b_desc;

    Gtk::Label l_desc{"Description:"};
    l_desc.set_width_chars(WIDTH);
    b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);

    Gtk::Entry e_desc;
    e_desc.set_max_length(WIDTH*4);
    b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);

    // Cost
    Gtk::HBox b_cost;

    Gtk::Label l_cost{"Cost:"};
    l_cost.set_width_chars(WIDTH);
    b_cost.pack_start(l_cost, Gtk::PACK_SHRINK);

    Gtk::Entry e_cost;
    e_cost.set_max_length(WIDTH*4);
    b_cost.pack_start(e_cost, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_cost, Gtk::PACK_SHRINK);

    // Price
    Gtk::HBox b_price;

    Gtk::Label l_price{"Price:"};
    l_price.set_width_chars(WIDTH);
    b_price.pack_start(l_price, Gtk::PACK_SHRINK);

    Gtk::Entry e_price;
    e_price.set_max_length(WIDTH*4);
    b_price.pack_start(e_price, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_price, Gtk::PACK_SHRINK);

    // Max Scoops (Container only)
    Gtk::HBox b_max_scoops;

    Gtk::Label l_max_scoops{"Max Scoops:"};
    l_max_scoops.set_width_chars(WIDTH);
    b_max_scoops.pack_start(l_max_scoops, Gtk::PACK_SHRINK);

    Gtk::Entry e_max_scoops;
    e_max_scoops.set_max_length(WIDTH*4);
    b_max_scoops.pack_start(e_max_scoops, Gtk::PACK_SHRINK);
    if (type == CONTAINER) {
        dialog.get_vbox()->pack_start(b_max_scoops, Gtk::PACK_SHRINK);
    }

    // Show dialog
    dialog.add_button("Cancel", 0);
	dialog.add_button("Retire", 2);
	dialog.add_button("Re-Stock", 3);
    dialog.add_button("OK", 1);
    dialog.show_all();

    bool valid_data = false;
    bool cretire = false;
	bool restock = false;
    double d_cost;
    double d_price;
    int i_max_scoops;

    while(!valid_data) {

		int result = dialog.run();

        if (result == 0) {
            dialog.close();
            return;
        } else if(result == 2) {
            cretire = true;
			valid_data = true;
        } else if(result == 3) {
			restock = true;
			valid_data = true;
		} else {
	        valid_data = true;
	        try {
	            d_cost = std::stod(e_cost.get_text());
	        } catch(std::exception e) {
	            e_cost.set_text("*** invalid cost ***");
	            valid_data = false;
	        }
	        try {
	            d_price = std::stod(e_price.get_text());
	        } catch(std::exception e) {
	            e_price.set_text("*** invalid price ***");
	            valid_data = false;
	        }
	        if (type == CONTAINER) {
	            try {
	                i_max_scoops = std::stoi(e_max_scoops.get_text());
	            } catch(std::exception e) {
	                e_max_scoops.set_text("*** invalid max scoops ***");
	                valid_data = false;
	            }
	        }
		}
    }

    int index = c_index.get_active_row_number();
    string text = c_index.get_active_text();

    if (cretire) {
        if(index!=-1)
            emp.retire_item(type, index);
        else {
            Gtk::MessageDialog dialog{*this, "Invalid Choice!"};
			dialog.run();
			dialog.close();
        }
        return;
    }

	if (restock) {
		vector<Server> _servers = emp.get_servers();
		vector<string> names;

		if(_servers.size() == 0) {
			Gtk::MessageDialog dialog{*this, "No servers to restock items!"};
			dialog.run();
			dialog.close();
			return;
		}

		for(Server s: _servers) names.push_back(s.get_name());
		int s_c = select_from_vector(names, "Server");

		if(s_c == -1) return;

		emp.add_stock(_servers[s_c], type, index, 25);
		return;
	}

    // Instance item
    if (type == CONTAINER) {
        Containr cont(text, e_desc.get_text(), d_cost, d_price, "picture.png", i_max_scoops);
        emp.edit_container(index, cont);

       //std::cout << c << std::endl;
    } else if (type == SCOOP) {
        Flavor f(text, e_desc.get_text(), d_cost, d_price,  "picture.png");
        emp.edit_flavor(index, f);

        //std::cout << f << std::endl;
    } else {
        Topping t(text, e_desc.get_text(), d_cost, d_price, "picture.png");
        emp.edit_topping(index, t);

        //std::cout << t << std::endl;
    }

    dialog.close();
}


void Main_window::on_edit_manager_click() {

    const int WIDTH = 15;

    vector<Manager> _managers = emp.get_managers();
    vector<string> names;

	if(_managers.size() == 0) {
		Gtk::MessageDialog dialog{*this, "No managers to Edit!"};
	    dialog.run();
	    dialog.close();
		return;
	}

    for(Manager s: _managers) names.push_back(s.get_name());
    int s_c = select_from_vector(names, "Manager");

    if(s_c == -1) return;

    Gtk::Dialog dlg{"Edit "+_managers[s_c].get_name(), *this};

    //name
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name: "};
    l_name.set_width_chars(WIDTH);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
	e_name.set_max_length(WIDTH*4);
	b_name.pack_start(e_name, Gtk::PACK_SHRINK);
	dlg.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

	// Phone
	Gtk::HBox b_phone;

	Gtk::Label l_phone{"Phone:"};
	l_phone.set_width_chars(WIDTH);
	b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

	Gtk::Entry e_phone;
	e_phone.set_max_length(WIDTH*4);
	b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
	dlg.get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

    dlg.add_button("Cancel", 0);
	dlg.add_button("Suspend", 2);
    dlg.add_button("Done", 1);
    dlg.show_all();

	int result = dlg.run();

    if(result == 1) {
        if(e_name.get_text() == "" || e_phone.get_text() == "") {
            Gtk::MessageDialog dialog{*this, "Unable to Edit!"};
    	    dialog.run();
    	    dialog.close();
            return;
        }
        emp.edit_manager(e_name.get_text(), e_phone.get_text(), s_c);
    }

	if(result == 2) {
        //SUSPEND
        emp.retire_person(0, s_c);
    }
}

void Main_window::on_edit_customer_click() {

    const int WIDTH = 15;

    vector<Customer> _customers = emp.get_customers();
    vector<string> names;

	if(_customers.size() == 0) {
		Gtk::MessageDialog dialog{*this, "No customers to Edit!"};
	    dialog.run();
	    dialog.close();
		return;
	}

    for(Customer s: _customers) names.push_back(s.get_name());
    int s_c = select_from_vector(names, "Customer");

    if(s_c == -1) return;

    Gtk::Dialog dlg{"Edit "+_customers[s_c].get_name(), *this};

    Gtk::HBox b_name;

    Gtk::Label l_name{"Name: "};
    l_name.set_width_chars(WIDTH);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
	e_name.set_max_length(WIDTH*4);
	b_name.pack_start(e_name, Gtk::PACK_SHRINK);
	dlg.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

	// Phone
	Gtk::HBox b_phone;

	Gtk::Label l_phone{"Phone:"};
	l_phone.set_width_chars(WIDTH);
	b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

	Gtk::Entry e_phone;
	e_phone.set_max_length(WIDTH*4);
	b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
	dlg.get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

    dlg.add_button("Cancel", 0);
	dlg.add_button("Suspend", 2);
    dlg.add_button("Done", 1);
    dlg.show_all();

	int result = dlg.run();

    if(result == 1) {
        if(e_name.get_text() == "" || e_phone.get_text() == "") {
            Gtk::MessageDialog dialog{*this, "Unable to Edit!"};
    	    dialog.run();
    	    dialog.close();
            return;
        }
        emp.edit_customer(e_name.get_text(), e_phone.get_text(), s_c);
    }

	if(result == 2) {
        //SUSPEND
		emp.retire_person(2, s_c);
	}

    dlg.close();
}

void Main_window::on_edit_server_click() {

    const int WIDTH = 15;

    vector<Server> _servers = emp.get_servers();
    vector<string> names;

	if(_servers.size() == 0) {
		Gtk::MessageDialog dialog{*this, "No servers to Edit!"};
	    dialog.run();
	    dialog.close();
		return;
	}

    for(Server s: _servers) names.push_back(s.get_name());
    int s_c = select_from_vector(names, "Server");

    if(s_c == -1) return;

    Gtk::Dialog dlg{"Edit "+_servers[s_c].get_name(), *this};

    //name
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name: "};
    l_name.set_width_chars(WIDTH);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
	e_name.set_max_length(WIDTH*4);
	b_name.pack_start(e_name, Gtk::PACK_SHRINK);
	dlg.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

	// Phone
	Gtk::HBox b_phone;

	Gtk::Label l_phone{"Phone:"};
	l_phone.set_width_chars(WIDTH);
	b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

	Gtk::Entry e_phone;
	e_phone.set_max_length(WIDTH*4);
	b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
	dlg.get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

    Gtk::HBox b_wage;
    Gtk::Label l_wage{"Hourly Salary: "};
    l_wage.set_width_chars(20);
    b_wage.pack_start(l_wage, Gtk::PACK_SHRINK);

    Gtk::SpinButton e_wage(0,0);
    e_wage.set_increments(0.1,0.01);
    e_wage.set_increments(0.1,0.01);
    e_wage.set_range(0.00,99999.00);
    e_wage.set_digits(2);
    e_wage.set_wrap(true);
    e_wage.set_numeric();
    b_wage.pack_start(e_wage, Gtk::PACK_SHRINK);
    dlg.get_vbox()->pack_start(b_wage, Gtk::PACK_SHRINK);

    dlg.add_button("Cancel", 0);
	dlg.add_button("Suspend", 2);
    dlg.add_button("Done", 1);
    dlg.show_all();

	int result = dlg.run();

    if(result == 1) {
        if(e_name.get_text() == "" || e_phone.get_text() == "") {
            Gtk::MessageDialog dialog{*this, "Unable to Edit!"};
    	    dialog.run();
    	    dialog.close();
            return;
        }
        emp.edit_server(e_name.get_text(), e_phone.get_text(), e_wage.get_value(), s_c);
    }

	if(result == 2) {
        //SUSPEND
		emp.retire_person(1, s_c);
	}

    dlg.close();
}


void Main_window::on_restore_item_click() {
    vector<string> names;
    names.push_back("Container"); names.push_back("Flavor"); names.push_back("Topping");

    int c_item = select_from_vector(names, "Item");

    if(c_item==-1) return;

    if(c_item == 0) {
        vector<Containr> _containers = emp.get_retired_containers();
        if(_containers.size() == 0 ) {
            Gtk::MessageDialog dialog{*this, "No containers eligible to Restore"};
		    dialog.run();
		    dialog.close();
			return;
        }
        names.clear();
        for(Containr c: _containers) names.push_back(c.get_name());

        int c_c = select_from_vector(names, "Container");
        if(c_c == -1) return;

        emp.restore_item(_containers[c_c], c_c);
    }

    if(c_item == 1) {
        vector<Flavor> _flavors = emp.get_retired_flavors();
        if(_flavors.size() == 0 ) {
            Gtk::MessageDialog dialog{*this, "No flavors eligible to Restore"};
		    dialog.run();
		    dialog.close();
			return;
        }
        names.clear();
        for(Flavor f: _flavors) names.push_back(f.get_name());

        int c_f = select_from_vector(names, "Flavor");
        if(c_f == -1) return;

        emp.restore_item(_flavors[c_f], c_f);
    }

    if(c_item == 2) {
        vector<Topping> _toppings = emp.get_retired_toppings();
        if(_toppings.size() == 0 ) {
            Gtk::MessageDialog dialog{*this, "No toppings eligible to Restore"};
		    dialog.run();
		    dialog.close();
			return;
        }
        names.clear();
        for(Topping t: _toppings) names.push_back(t.get_name());

        int c_top = select_from_vector(names, "Topping");
        if(c_top == -1) return;

        emp.restore_item(_toppings[c_top], c_top);
    }
}

void Main_window::on_restore_person_click() {
	vector<string> names;
	names.push_back("Manager");
	names.push_back("Server");
    names.push_back("Customer");

	int mos = select_from_vector(names, "Person");

	if(mos==-1) return;

    if (mos == 2) {
		vector<Customer> rcustomers = emp.get_retired_customers();
		if(rcustomers.size() == 0) {
			Gtk::MessageDialog dialog{*this, "No customer eligible to Restore"};
		    dialog.run();
		    dialog.close();
			return;
		}
		names.clear();
		for(Customer s: rcustomers) names.push_back(s.get_name());

		int sc = select_from_vector(names, "Customer");
		if(sc == -1) return;

		emp.restore_person(2, sc);
	}

	if (mos == 1) {
		vector<Server> rservers = emp.get_retired_servers();
		if(rservers.size() == 0) {
			Gtk::MessageDialog dialog{*this, "No servers eligible to Restore"};
		    dialog.run();
		    dialog.close();
			return;
		}
		names.clear();
		for(Server s: rservers) names.push_back(s.get_name());

		int sc = select_from_vector(names, "Server");
		if(sc == -1) return;

		emp.restore_person(1, sc);
	}

	if (mos == 0) {
		vector<Manager> rmanagers = emp.get_retired_managers();
		if(rmanagers.size() == 0) {
			Gtk::MessageDialog dialog{*this, "No managers eligible to Restore"};
		    dialog.run();
		    dialog.close();
			return;
		}
		names.clear();
		for(Manager m: rmanagers) names.push_back(m.get_name());

		int mc = select_from_vector(names, "Manager");
		if(mc == -1) return;

		emp.restore_person(0, mc);
	}
}
