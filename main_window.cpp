#include "main_window.h"
#include <iostream>
#include <sstream>

Emporium emp{1,"Euless", "817-722-1222"};

Main_window::Main_window() {
	// /////////////////
	// G U I   S E T U P
	// /////////////////

	set_default_size(500, 250);

	// Put a vertical box container as the Window contents
	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	add(*vbox);

	// ///////
	// M E N U
	// Add a menu bar as the top item in the vertical box
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

	//     F I L E
	// Create a File menu and add to the menu bar
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);

	//new
	Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Emporium", true));
	menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_mgmt_click));
	filemenu->append(*menuitem_new);

	//save to a file
	Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save Emporium", true));
	menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_save_click));
	filemenu->append(*menuitem_save);

	//load an Emporium
	Gtk::MenuItem *menuitem_load = Gtk::manage(new Gtk::MenuItem("_Load Emporium", true));
	menuitem_load->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_load_click));
	filemenu->append(*menuitem_load);

    //easter egg
	Gtk::MenuItem *menuitem_pop_mgmt = Gtk::manage(new Gtk::MenuItem("_Populate Emporium", true));
	menuitem_pop_mgmt->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_pop_mgmt_click));
	filemenu->append(*menuitem_pop_mgmt);

	//         Q U I T
	// Append Quit to the File menu
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
	filemenu->append(*menuitem_quit);

	// EDIT
	Gtk::MenuItem *menuitem_edit = Gtk::manage(new Gtk::MenuItem("_Edit", true));
	menubar->append(*menuitem_edit);
	Gtk::Menu *editmenu = Gtk::manage(new Gtk::Menu());
	menuitem_edit->set_submenu(*editmenu);

	// edit item
	Gtk::MenuItem *menuitem_eitem = Gtk::manage(new Gtk::MenuItem("_Edit Item", true));
	menuitem_eitem->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_edit_item_click));
	editmenu->append(*menuitem_eitem);

	//edit server
	Gtk::MenuItem *menuitem_eserver = Gtk::manage(new Gtk::MenuItem("_Edit Server", true));
	menuitem_eserver->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_edit_server_click));
	editmenu->append(*menuitem_eserver);

	//restore person
	Gtk::MenuItem *menuitem_restore_person = Gtk::manage(new Gtk::MenuItem("_Restore Person", true));
	menuitem_restore_person->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_restore_person_click));
	editmenu->append(*menuitem_restore_person);

	//owner menu
	Gtk::MenuItem *menuitem_owner = Gtk::manage(new Gtk::MenuItem("_Owner", true));
	menubar->append(*menuitem_owner);
	Gtk::Menu *owner_menu = Gtk::manage(new Gtk::Menu());
	menuitem_owner->set_submenu(*owner_menu);

	// new manager menu
	Gtk::MenuItem *menuitem_new_manager = Gtk::manage(new Gtk::MenuItem("_Add New Manager", true));
	menuitem_new_manager->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_manager));
	owner_menu->append(*menuitem_new_manager);

	//Manager to the menu bar
	Gtk::MenuItem *menuitem_manager = Gtk::manage(new Gtk::MenuItem("_Manager", true));
	menubar->append(*menuitem_manager);
	Gtk::Menu *manager_menu = Gtk::manage(new Gtk::Menu());
	menuitem_manager->set_submenu(*manager_menu);

	// new flavor menu
	Gtk::MenuItem *menuitem_item = Gtk::manage(new Gtk::MenuItem("_Add New Item", true));
	menuitem_item->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_item));
	manager_menu->append(*menuitem_item);

	// new server menu
	Gtk::MenuItem *menuitem_add_server = Gtk::manage(new Gtk::MenuItem("_Add New Server", true));
	menuitem_add_server->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_server));
	manager_menu->append(*menuitem_add_server);

	// Create a Server menu and add to the menu bar
	Gtk::MenuItem *menuitem_server = Gtk::manage(new Gtk::MenuItem("_Server", true));
	menubar->append(*menuitem_server);
	Gtk::Menu *server_menu = Gtk::manage(new Gtk::Menu());
	menuitem_server->set_submenu(*server_menu);

	// new serving menu
	Gtk::MenuItem *menuitem_serving = Gtk::manage(new Gtk::MenuItem("_New Order", true));
	menuitem_serving->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_order));
	server_menu->append(*menuitem_serving);

	// new customer menu
	Gtk::MenuItem *menuitem_add_customer = Gtk::manage(new Gtk::MenuItem("_Add New Customer", true));
	menuitem_add_customer->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_customer));
	server_menu->append(*menuitem_add_customer);

	// Create a Customer menu and add to the menu bar
	Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
	menubar->append(*menuitem_customer);
	Gtk::Menu *customer_menu = Gtk::manage(new Gtk::Menu());
	menuitem_customer->set_submenu(*customer_menu);

	// new customer serving menu
	Gtk::MenuItem *menuitem_serving1 = Gtk::manage(new Gtk::MenuItem("_New Order", true));
	menuitem_serving1->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_order));
	customer_menu->append(*menuitem_serving1);

	// Create a Process menu and add to the menu bar
	Gtk::MenuItem *menuitem_process = Gtk::manage(new Gtk::MenuItem("_Process", true));
	menubar->append(*menuitem_process);
	Gtk::Menu *process_menu = Gtk::manage(new Gtk::Menu());
	menuitem_process->set_submenu(*process_menu);

	//cancel order
	Gtk::MenuItem *menuitem_cancel = Gtk::manage(new Gtk::MenuItem("_Cancel Order", true));
	menuitem_cancel->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_cancel_order));
	process_menu->append(*menuitem_cancel);

	//fill order
	Gtk::MenuItem *menuitem_fill = Gtk::manage(new Gtk::MenuItem("_Fill Order", true));
	menuitem_fill->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_fill_order));
	process_menu->append(*menuitem_fill);

	//pay order
	Gtk::MenuItem *menuitem_pay = Gtk::manage(new Gtk::MenuItem("_Pay Order", true));
	menuitem_pay->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_pay_order));
	process_menu->append(*menuitem_pay);

	//REPORTS
	Gtk::MenuItem *menuitem_reports = Gtk::manage(new Gtk::MenuItem("_Reports", true));
	menubar->append(*menuitem_reports);
	Gtk::Menu *report_menu = Gtk::manage(new Gtk::Menu());
	menuitem_reports->set_submenu(*report_menu);

	Gtk::MenuItem *menuitem_servers = Gtk::manage(new Gtk::MenuItem("_Servers Report", true));
	menuitem_servers->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_servers_report));
	report_menu->append(*menuitem_servers);

	Gtk::MenuItem *menuitem_customers = Gtk::manage(new Gtk::MenuItem("_Customers Report", true));
	menuitem_customers->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_customers_report));
	report_menu->append(*menuitem_customers);

	Gtk::MenuItem *menuitem_inventory = Gtk::manage(new Gtk::MenuItem("_Inventory Report", true));
	menuitem_inventory->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_inventory_report));
	report_menu->append(*menuitem_inventory);

	Gtk::MenuItem *menuitem_orders = Gtk::manage(new Gtk::MenuItem("_Orders Report", true));
	menuitem_orders->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_orders_report));
	report_menu->append(*menuitem_orders);

	Gtk::MenuItem *menuitem_pnl = Gtk::manage(new Gtk::MenuItem("_Profit & Loss Report", true));
	menuitem_pnl->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_pnl_report));
	report_menu->append(*menuitem_pnl);

	//help menu
	Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
	menubar->append(*menuitem_help);
	Gtk::Menu *help_menu = Gtk::manage(new Gtk::Menu());
	menuitem_help->set_submenu(*help_menu);

	Gtk::MenuItem *menuitem_contents = Gtk::manage(new Gtk::MenuItem("_Contents", true));
	menuitem_contents->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_contents_click));
	help_menu->append(*menuitem_contents);

	Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
	menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
	help_menu->append(*menuitem_about);

	//toolbar
	Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
	vbox->add(*toolbar);

	//new flavor button
	//Gtk::Image *new_image = Gtk::manage(new Gtk::Image("new_flavor.png"));
	Gtk::ToolButton *new_item_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ADD));
	new_item_button->set_tooltip_markup("Add a new Item");
	new_item_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_new_item));
	toolbar->append(*new_item_button);

	Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
	sep->set_expand(true);
	toolbar->append(*sep);

	Gtk::ToolButton *help_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::HELP));
	help_button->set_tooltip_markup("Show contents description.");
	help_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_contents_click));
	toolbar->append(*help_button);

	Gtk::ToolButton *exit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::CANCEL));
	exit_button->set_tooltip_markup("Exit program.");
	exit_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
	toolbar->append(*exit_button);

	// Make the box and everything in it visible
	vbox->show_all();
}

Main_window::~Main_window() { }

void Main_window::on_new_mgmt_click() {

	Gtk::Dialog dlg{"Do you want to save your current emporium?", *this};
	dlg.set_default_size(450,10);
	dlg.add_button("Cancel", 2);
	dlg.add_button("No", 0);
	dlg.add_button("Yes", 1);

	int result = dlg.run();

	if(result == 2) return;

	if(result == 1) on_save_click();

    Emporium new_emp{1, "Bedford", "817-464-1293"};
    emp = new_emp;
}

void Main_window::on_pop_mgmt_click() {
	emp.populate_emporium();

	Gtk::MessageDialog dialog{*this, "Populate Succesful"};
    dialog.run();
    dialog.close();
}

void Main_window::on_save_click() {

    Gtk::Dialog dlg{"Enter File Name", *this};
    Gtk::Entry e;
    dlg.get_vbox()->pack_start(e, Gtk::PACK_SHRINK);

    dlg.add_button("Save", 1);

    dlg.show_all();
    dlg.run();

    string s = e.get_text() + ".emp";

	if(s=="") return;
    //emp.write(s);
    dlg.close();

	try {
        std::ofstream ofs{s, std::ofstream::out};
        emp.save(ofs);
    } catch (std::exception& e) {
        Gtk::MessageDialog dialog{*this, "Unable to save "+s};
        dialog.set_secondary_text(e.what());
        dialog.run();
        dialog.close();
    }

}

void Main_window::on_load_click() {
	Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FILE_CHOOSER_ACTION_OPEN);
  	dialog.set_transient_for(*this);

  	//Add response buttons the the dialog:
  	dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  	dialog.add_button("_Open", Gtk::RESPONSE_OK);

	//Show the dialog and wait for a user response:
	int result = dialog.run();
	string filename;

	//Handle the response:
	switch(result)
	{
	  case(Gtk::RESPONSE_OK):
	  {
		std::cout << "Open clicked." << std::endl;

		//Notice that this is a std::string, not a Glib::ustring.
		filename = dialog.get_filename();
		std::cout << "File selected: " <<  filename << std::endl;
		break;
	  }
	  case(Gtk::RESPONSE_CANCEL):
	  {
		std::cout << "Cancel clicked." << std::endl;
		break;
	  }
	  default:
	  {
		std::cout << "Unexpected button clicked." << std::endl;
		break;
	  }
	}

	try {
        std::ifstream ifs{filename, std::ifstream::in};
		Emporium new_emp{ifs};
        emp = new_emp;
    } catch (std::exception& e) {
        Gtk::MessageDialog dialog{*this, "Unable to open file"};
        dialog.set_secondary_text(e.what());
        dialog.run();
        dialog.close();
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
        emp.retire_item(type, index);
        return;
    }

	if (restock) {
		vector<Server> _servers = emp.get_servers();
		vector<string> names;

		if(_servers.size() == 0) {
			Gtk::MessageDialog dialog{*this, "No servers to restock!"};
			dialog.run();
			dialog.close();
			return;
		}

		for(Server s: _servers) names.push_back(s.get_name());
		int s_c = select_from_vector(names, "Server");

		if(s_c == -1) return;

		//emp.add_stock(_servers[s_c], type, index, 25);
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

void Main_window::on_restore_person_click() {
	vector<string> names;
	names.push_back("Manager");
	names.push_back("Server");

	int mos = select_from_vector(names, "Manager or Server:");

	if(mos==-1) return;

	if (mos == 1) {
		vector<Server> rservers = emp.get_retired_servers();
		if(rservers.size() == 0) {
			Gtk::MessageDialog dialog{*this, "No servers to Restore"};
		    dialog.run();
		    dialog.close();
			return;
		}
		names.clear();
		for(Server s: rservers) names.push_back(s.get_name());

		int sc = select_from_vector(names, "Select an Server");
		if(sc == -1) return;

		emp.restore_person(rservers[sc], sc);
	}

	if (mos == 0) {
		vector<Manager> rmanagers = emp.get_retired_managers();
		if(rmanagers.size() == 0) {
			Gtk::MessageDialog dialog{*this, "No managers to Restore"};
		    dialog.run();
		    dialog.close();
			return;
		}
		names.clear();
		for(Manager m: rmanagers) names.push_back(m.get_name());

		int mc = select_from_vector(names, "Select an Manager");
		if(mc == -1) return;

		emp.restore_person(rmanagers[mc], mc);
	}
}

void Main_window::on_edit_server_click() {

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

    Gtk::Dialog dlg{"New Salary Input", *this};

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
        double m = e_wage.get_value();
        emp.change_salary(s_c, m);
    }

	if(result == 2) {
		emp.retire_person(_servers[s_c], s_c);
	}

    dlg.close();
}

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

    for(Server s: _servers) names.push_back(s.get_name());
    int s_c = select_from_vector(names, "Server");

    names.clear();
    for(Customer c: _customers) names.push_back(c.get_name());
    int c_c = select_from_vector(names, "Customer");

    if(s_c==-1 || c_c==-1) return;

	int next_id = emp.get_orders().size();
	Order order{next_id, _servers[s_c], _customers[c_c]};

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
        if (e_phone.get_text().length() == 0) {
            e_phone.set_text("*** phone is required ***");
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

//process callbacks
void Main_window::on_cancel_order(){
	vector<string> names;
	vector<Order> orders = emp.get_orders();

    for(Order s: orders) {
		if(s.get_state() == "Unfilled")
			names.push_back(to_string(s.get_id()));
	}

	if(names.size()==0) {
		Gtk::MessageDialog dialog{*this, "No orders to Cancel!"};
	    dialog.run();
	    dialog.close();
		return;
	}

    int id = select_from_vector(names, "Cancel Order");

	if (id!=-1) {
		emp.set_order_state(id, "Cancelled");
	}
}

void Main_window::on_fill_order() {
	vector<string> names;
	vector<Order> orders = emp.get_orders();

    for(Order s: orders) {
		if(s.get_state() == "Unfilled")
			names.push_back(to_string(s.get_id()));
	}

	if(names.size()==0) {
		Gtk::MessageDialog dialog{*this, "No orders to Fill!"};
	    dialog.run();
	    dialog.close();
		return;
	}

    int id = select_from_vector(names, "Fill Order");

	if (id!=-1) {
		emp.set_order_state(id, "Filled");
	}
}

void Main_window::on_pay_order() {
	vector<string> names;
	vector<Order> orders = emp.get_orders();

    for(Order s: orders) {
		if(s.get_state() == "Filled")
			names.push_back(to_string(s.get_id()));
	}

	if(names.size()==0) {
		Gtk::MessageDialog dialog{*this, "No orders to Pay!"};
	    dialog.run();
	    dialog.close();
		return;
	}

    int id = select_from_vector(names, "Pay Order");

	if (id!=-1) {
		emp.set_order_state(id, "Paid");
	}
}

//report callbacks
void Main_window::on_servers_report() {
	string res = emp.get_servers_report();

	Gtk::Dialog s_dialog{"Servers Report", *this};
	Gtk::Label l_text{res};
	s_dialog.get_vbox()->pack_start(l_text, Gtk::PACK_SHRINK);

	s_dialog.add_button("Ok", 1);
	s_dialog.show_all();
	s_dialog.run();
}
void Main_window::on_customers_report() {
	string res = emp.get_customers_report();

	Gtk::Dialog c_dialog{"Customers Report", *this};
	Gtk::Label lc_text{res};
	c_dialog.get_vbox()->pack_start(lc_text, Gtk::PACK_SHRINK);

	c_dialog.add_button("Ok", 1);
	c_dialog.show_all();
	c_dialog.run();
}
void Main_window::on_inventory_report() {
	string res = emp.get_inventory_report();

    Gtk::Dialog i_dialog{"Inventory Report", *this};
	Gtk::Label li_text{res};
	i_dialog.get_vbox()->pack_start(li_text, Gtk::PACK_SHRINK);

	i_dialog.add_button("Ok", 1);
	i_dialog.show_all();
	i_dialog.run();
}
void Main_window::on_orders_report() {
	string res = emp.get_orders_report();

    Gtk::Dialog o_dialog{"Orders Report", *this};
	Gtk::Label lo_text{res};
	o_dialog.get_vbox()->pack_start(lo_text, Gtk::PACK_SHRINK);

	o_dialog.add_button("Ok", 1);
	o_dialog.show_all();
	o_dialog.run();
}
void Main_window::on_pnl_report() {
	string res = emp.get_pnl_report();

	Gtk::Dialog p_dialog{"Profit & Loss Report", *this};
	Gtk::Label lp_text{res};
	p_dialog.get_vbox()->pack_start(lp_text, Gtk::PACK_SHRINK);

	p_dialog.add_button("Ok", 1);
	p_dialog.show_all();
	p_dialog.run();
}

void Main_window::on_contents_click() {   //shows help or program documentation
	Gtk::Dialog dialog{"Store Contents", *this};

	//flavor contents
	Gtk::Image c_img{"data/pictures/f_chocolate.png"};
	Gtk::Button but{"", 1};
	but.set_image(c_img);
	dialog.get_vbox()->pack_start(but, Gtk::PACK_SHRINK);

	Gtk::Image v_img{"data/pictures/f_vanilla.png"};
	Gtk::Button but1{"", 2};
	but1.set_image(v_img);
	dialog.get_vbox()->pack_start(but1, Gtk::PACK_SHRINK);

	Gtk::Image s_img{"data/pictures/f_strawberry.png"};
	Gtk::Button but2{"", 3};
	but2.set_image(s_img);
	dialog.get_vbox()->pack_start(but2, Gtk::PACK_SHRINK);

	//toppings contents
	Gtk::Image thf_img{"data/pictures/t_hot_fudge.png"};
	Gtk::Button but3{"", 4};
	but3.set_image(thf_img);
	dialog.get_vbox()->pack_start(but3, Gtk::PACK_SHRINK);

	Gtk::Image tc_img{"data/pictures/t_caramel.png"};
	Gtk::Button but4{"", 5};
	but4.set_image(tc_img);
	dialog.get_vbox()->pack_start(but4, Gtk::PACK_SHRINK);

	dialog.show_all();
	dialog.run();
}

void Main_window::on_about_click() {   //shows company description
	Gtk::AboutDialog dialog{};
	dialog.set_transient_for(*this);
	dialog.set_program_name("Mav's Ice Cream Emporium");
	auto logo = Gdk::Pixbuf::create_from_file("logo.png");
	dialog.set_logo(logo);
	dialog.set_version("Sprint 3");
	dialog.set_copyright("Copyright 2017");
	dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
	std::vector< Glib::ustring > authors = {"Safal Lamsal, Aabhas Kharel, Roshan Shrestha, Bibek Sapkota"};
	dialog.set_authors(authors);
	std::vector< Glib::ustring > artists = {"Logo by weewilliewinkie https://pixabay.com/en/ice-cream-cup-summer-glass-wafer-2109460/\nStore Contents design by Jeevan Gyawali"};
	dialog.set_artists(artists);
	dialog.run();
}

void Main_window::on_quit_click() {
	hide();
}

int Main_window::select_from_vector(std::vector<std::string> names, std::string title) {

	Gtk::Dialog dialog_index{"Select " + title, *this};
	const int WIDTH = 15;

	// Container
	Gtk::HBox b_index;

	Gtk::Label l_index{title + ":"};
	l_index.set_width_chars(WIDTH);
	b_index.pack_start(l_index, Gtk::PACK_SHRINK);

	// Create dropdown list
	Gtk::ComboBoxText c_index;
	c_index.set_size_request(WIDTH*10);
	for (std::string s : names) c_index.append(s);
	b_index.pack_start(c_index, Gtk::PACK_SHRINK);
	dialog_index.get_vbox()->pack_start(b_index, Gtk::PACK_SHRINK);

	// Show dialog_index
	dialog_index.add_button("Cancel", 0);
	dialog_index.add_button("OK", 1);
	dialog_index.show_all();
	if (dialog_index.run() != 1) return -1;

	int index = c_index.get_active_row_number();

	dialog_index.close();

	return index;
}
