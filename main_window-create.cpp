#include "main_window.h"
#include <regex>

void Main_window::on_new_item() {

    vector<Containr> _containers = emp.get_containers();
    vector<Flavor> _flavors = emp.get_flavors();
    vector<Topping> _toppings = emp.get_toppings();

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

    // //////////////////////////////
    // Define Item

    Gtk::Dialog dialog;
    if (type == CONTAINER) dialog.set_title("Create Container");
    else if (type == SCOOP) dialog.set_title("Create Flavor");
    else dialog.set_title("Create Topping");
    dialog.set_transient_for(*this);

    // Name
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(WIDTH);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(WIDTH*4);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
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

	//scoop size
	Gtk::HBox b_scoop;
    Gtk::Label l_scoop{"Scoop Size: "};
    l_scoop.set_width_chars(WIDTH);
    b_scoop.pack_start(l_scoop, Gtk::PACK_SHRINK);

    Gtk::SpinButton e_scoop(0,0);
    e_scoop.set_increments(1.0,1.0);
    e_scoop.set_range(0,99999);
    e_scoop.set_digits(0);
    e_scoop.set_wrap(true);
    e_scoop.set_numeric();
    b_scoop.pack_start(e_scoop, Gtk::PACK_SHRINK);
	if (type == CONTAINER) {
        dialog.get_vbox()->pack_start(b_scoop, Gtk::PACK_SHRINK);
    }

	// wholesale price
    Gtk::HBox b_wprice;
    Gtk::Label l_wprice{"Cost: "};
    l_wprice.set_width_chars(WIDTH);
    b_wprice.pack_start(l_wprice, Gtk::PACK_SHRINK);

    Gtk::SpinButton e_wprice(0,0);
    e_wprice.set_increments(0.1,0.01);
    e_wprice.set_range(0.00,99999.00);
    e_wprice.set_digits(2);
    e_wprice.set_value(0.00);
    e_wprice.set_wrap(true);
    e_wprice.set_numeric();
    b_wprice.pack_start(e_wprice, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_wprice, Gtk::PACK_SHRINK);

    // retail price
    Gtk::HBox b_rprice;
    Gtk::Label l_rprice{"Price: "};
    l_rprice.set_width_chars(WIDTH);
    b_rprice.pack_start(l_rprice, Gtk::PACK_SHRINK);

    Gtk::SpinButton e_rprice(0,0);
    e_rprice.set_increments(0.1,0.01);
    e_rprice.set_increments(0.1,0.01);
    e_rprice.set_range(0.00,99999.00);
    e_rprice.set_digits(2);
    e_rprice.set_wrap(true);
    e_rprice.set_numeric();
    b_rprice.pack_start(e_rprice, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_rprice, Gtk::PACK_SHRINK);

	//image path
	Gtk::HBox b_image;
    Gtk::Label l_image{"Image: "};
    l_image.set_width_chars(WIDTH);
    b_image.pack_start(l_image, Gtk::PACK_SHRINK);

    Gtk::FileChooserButton f_image;
    b_image.pack_start(f_image, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_image, Gtk::PACK_SHRINK);

    // Show dialog
    dialog.add_button("Cancel", 0);
    dialog.add_button("OK", 1);
    dialog.show_all();

	int result = dialog.run();

    // Instance item
    if (type == CONTAINER) {
		Containr cont(e_name.get_text(), e_desc.get_text(), e_wprice.get_value(), e_rprice.get_value(), f_image.get_filename(), e_scoop.get_value_as_int());
		emp.add_container(cont);

        //std::cout << c << std::endl;
    } else if (type == SCOOP) {
		Flavor f(e_name.get_text(), e_desc.get_text(), e_wprice.get_value(), e_rprice.get_value(),  f_image.get_filename());
		emp.add_flavor(f);

        //std::cout << f << std::endl;
    } else {
		Topping t(e_name.get_text(), e_desc.get_text(), e_wprice.get_value(), e_rprice.get_value(), f_image.get_filename());
		emp.add_topping(t);

        //std::cout << t << std::endl;
    }

    dialog.close();
}

void Main_window::on_new_order() {

    vector<Server> _servers = emp.get_servers();
    vector<Customer> _customers = emp.get_customers();
    vector<string> names;

	if(_servers.size() == 0 || _customers.size() == 0) {
		Gtk::MessageDialog dialog{*this, "Add at least one server, and one customer to start an order!"};
	    dialog.run();
	    dialog.close();
		return;
	}
/*
    for(Server s: _servers) names.push_back(s.get_name());
    int s_c = select_from_vector(names, "Server");
*/
    names.clear();
    for(Customer c: _customers) names.push_back(c.get_name());
    int c_c = select_from_vector(names, "Customer");

    if(/*s_c==-1 ||*/ c_c==-1) return;

	int next_id = emp.get_orders().size();
	Order order{next_id,  _customers[c_c]};

	Gtk::Dialog order_dialog{"New Order", *this};

	//buttons
	order_dialog.add_button("Cancel Order", 0);
	order_dialog.add_button("New Serving", 1);
	order_dialog.add_button("Finish Order", 2);

	//show dialog, and result
	order_dialog.show_all();
	int result = order_dialog.run();

	while(result==1) {
		try {
			Serving serving = create_serving();
			//cout << serving << endl;
			order.add_serving(serving);
		} catch (std::runtime_error e) {}

		result = order_dialog.run();
	}

	if(result == 0) return;
	if(result == 2) {
		if (order.get_servings_size()!=0) {
			emp.add_order(order);
			string out = "";
			for (int i =0; i< order.get_servings_size(); i++) {
			    out+= order.list_serving(i);
			}
			Gtk::Dialog o_dialog{"Your Order", *this};
			Gtk::Label l_text{out};
			o_dialog.get_vbox()->pack_start(l_text, Gtk::PACK_SHRINK);

			o_dialog.add_button("Ok", 1);
			o_dialog.show_all();
			o_dialog.run();
			o_dialog.close();

            on_order_update();
		}
	}
}

Serving Main_window::create_serving() {
	//get vectors
	vector<Containr> _containers = emp.get_containers();
	vector<Flavor> _flavors = emp.get_flavors();
	vector<Topping> _toppings = emp.get_toppings();
/*
	if(_containers.size() == 0 || _flavors.size() == 0 || _toppings.size() == 0) {
		Gtk::MessageDialog dialog{*this, "Add at least one container, one topping, and one flavor to start an serving!"};
	    dialog.run();
	    dialog.close();
		return Serving s;
	}
*/

	std::vector<std::string> names;
	for (Containr c : _containers) names.push_back(c.get_name());
	int container = select_from_vector(names, "Container");

	if (container == -1) throw std::runtime_error("Canceled");

	Serving serving{_containers[container]};

	bool has_no_flavors = true;
	for (int i=0; i<_containers[container].get_scoop(); ++i) {
		names.clear();
		for (Flavor s : _flavors) names.push_back(s.get_name());
		int flavor = select_from_vector(names, "Flavor");
		if (flavor == -1) break;
		serving.set_flavor(_flavors[flavor]);
		has_no_flavors = false;
	}
	if (has_no_flavors) throw std::runtime_error("Canceled");

	while (true) {
		names.clear();
		for (Topping t : _toppings) names.push_back(t.get_name());
		int topping = select_from_vector(names, "Topping");
		//int topping = select_topping();
		if (topping == -1) break;
		else serving.set_topping(_toppings[topping], 1);
	}

	return serving;
}

void Main_window::on_new_person(string role) {

	const int WIDTH = 15;

	Gtk::Dialog dialog{"Create " + role, *this};

	// Name
	Gtk::HBox b_name;

	Gtk::Label l_name{"Name:"};
	l_name.set_width_chars(WIDTH);
	b_name.pack_start(l_name, Gtk::PACK_SHRINK);

	Gtk::Entry e_name;
	e_name.set_max_length(WIDTH*4);
	b_name.pack_start(e_name, Gtk::PACK_SHRINK);
	dialog.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

	// Phone
	Gtk::HBox b_phone;

	Gtk::Label l_phone{"Phone:"};
	l_phone.set_width_chars(WIDTH);
	b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

	Gtk::Entry e_phone;
	e_phone.set_max_length(WIDTH*4);
	b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
	dialog.get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

	// Salary (Server only)
	Gtk::HBox b_wage;
    Gtk::Label l_wage{"Hourly Salary: "};
    l_wage.set_width_chars(WIDTH);
    b_wage.pack_start(l_wage, Gtk::PACK_SHRINK);

    Gtk::SpinButton e_wage(0,0);
	//e_wage.set_width_chars(WIDTH);
    e_wage.set_increments(0.1,0.01);
    e_wage.set_increments(0.1,0.01);
    e_wage.set_range(0.00,99999.00);
    e_wage.set_digits(2);
    e_wage.set_wrap(true);
    e_wage.set_numeric();
    b_wage.pack_start(e_wage, Gtk::PACK_SHRINK);
	if (role== "Server")
    	dialog.get_vbox()->pack_start(b_wage, Gtk::PACK_SHRINK);

	// Show dialog
	dialog.add_button("Cancel", 0);
	dialog.add_button("OK", 1);
	dialog.show_all();

	//double d_salary;
	bool valid_data = false;

	while(!valid_data) {
        if (dialog.run() != 1) {
            dialog.close();
            return;
        }

        // Data validation
        valid_data = true;

        if (e_name.get_text().length() == 0) {
            e_name.set_text("*** name is required ***");
            valid_data = false;
        }
		regex phone_number{"[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]"}; //REGEX
		string out_phone = e_phone.get_text();
		if (regex_match(out_phone, phone_number)) {  //REGEX

		} else {
			std::cout << "Format: xxx-xxx-xxxx" << '\n';
			e_phone.set_text("*** invalid format ***");
			valid_data = false;
		}
/*
        for (int s=0; s < _emp->num_servers(); ++s) {
            if (_emp->server(s).name() == e_name.get_text()) {
                e_name.set_text("*** duplicate name ***");
                valid_data = false;
            }
    	}
*/
	}

	// Instance person
    if (role == "Server") {
		int size = emp.get_servers().size();
        Server s{e_name.get_text(), size, e_phone.get_text(), e_wage.get_value()};
        emp.add_server(s);
    } else if (role == "Customer") {
		int size = emp.get_customers().size();
        Customer c{e_name.get_text(), size, e_phone.get_text()};
        emp.add_customer(c);
    } else {
		int size = emp.get_managers().size();
        Manager m{e_name.get_text(), size, e_phone.get_text()};
        emp.add_manager(m);
	}

    dialog.close();

}

void Main_window::on_new_server() {
	on_new_person("Server");
}

void Main_window::on_new_customer() {
	on_new_person("Customer");
}

void Main_window::on_new_manager() {
	on_new_person("Manager");
}
