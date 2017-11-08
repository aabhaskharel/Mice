#include "main_window.h"
#include <iostream>
#include <sstream>

Emporium emp;

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
  
    Gtk::MenuItem *menuitem_pop_mgmt = Gtk::manage(new Gtk::MenuItem("_Populate Management", true));
    menuitem_pop_mgmt->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_pop_mgmt_click));
    filemenu->append(*menuitem_pop_mgmt);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_quit);
    
    //Manager to the menu bar
    Gtk::MenuItem *menuitem_manager = Gtk::manage(new Gtk::MenuItem("_Manager", true));
    menubar->append(*menuitem_manager);
    Gtk::Menu *manager_menu = Gtk::manage(new Gtk::Menu());
    menuitem_manager->set_submenu(*manager_menu);

    // new falvor menu
    Gtk::MenuItem *menuitem_flavor = Gtk::manage(new Gtk::MenuItem("_Add New Flavor", true));
    menuitem_flavor->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_flavor));
    manager_menu->append(*menuitem_flavor);
    
    // new topping menu
    Gtk::MenuItem *menuitem_topping = Gtk::manage(new Gtk::MenuItem("_Add New Topping", true));
    menuitem_topping->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_topping));
    manager_menu->append(*menuitem_topping);
    
    // new container menu
    Gtk::MenuItem *menuitem_container = Gtk::manage(new Gtk::MenuItem("_Add New Container", true));
    menuitem_container->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_container));
    manager_menu->append(*menuitem_container);
    
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
    Gtk::ToolButton *new_flavor_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ADD));
    new_flavor_button->set_tooltip_markup("Add a new Flavor");
    new_flavor_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_new_flavor));
    toolbar->append(*new_flavor_button);
    
    //new topping button
    //Gtk::Image *new_image = Gtk::manage(new Gtk::Image("new_topping.png"));
    Gtk::ToolButton *new_topping_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ADD));
    new_topping_button->set_tooltip_markup("Add a new Topping");
    new_topping_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_new_topping));
    toolbar->append(*new_topping_button);
    
    //new container button
    //Gtk::Image *new_image = Gtk::manage(new Gtk::Image("new_container.png"));
    Gtk::ToolButton *new_cont_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ADD));
    new_cont_button->set_tooltip_markup("Add a new Container");
    new_cont_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_new_container));
    toolbar->append(*new_cont_button);
    
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


void Main_window::on_pop_mgmt_click() {
	emp.populate_emporium();
}

void Main_window::on_new_container() {
    vector<string> res;
    res = Dialogs::form(1);
	if (res.size() == 7) {
	Containr cont(res[0], res[1], stod(res[2]), stod(res[3]), stoi(res[4]), res[5], stoi(res[6]));
	emp.add_new_container(cont);
	}
}

void Main_window::on_new_flavor() {
    vector<string> res;
    res = Dialogs::form(2);
	if (res.size() == 6) {
		Flavor flav(res[0], res[1], stod(res[2]), stod(res[3]), stoi(res[4]), res[5]);
	    emp.add_new_flavor(flav);
    }
}

void Main_window::on_new_topping() {
    vector<string> res;
    res = Dialogs::form(3);
	if (res.size() == 6) {
		Topping top(res[0], res[1], stod(res[2]), stod(res[3]), stoi(res[4]), res[5], "Light");
	    emp.add_new_topping(top);
    }
}

void Main_window::on_new_server() {
    vector<string> res;
    res = Dialogs::add_server();
	if (res.size() == 2) {
		Server ser(res[0], emp.get_servers().size()+1, 0, stod(res[1]));
	    emp.add_new_server(ser);
    }
}

void Main_window::on_new_order() {

    Order order{emp.get_order_id()};
    
    Gtk::Dialog order_dialog{"New Order", *this};
    
    Gtk::Label l_greeting{"Your Order:"};
    order_dialog.get_vbox()->pack_start(l_greeting, Gtk::PACK_SHRINK);
    //vbox->add(l_greeting);
    
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
            cout << serving << endl;
            order.add_serving(serving);
        } catch (std::runtime_error e) {}
        
        result = order_dialog.run();
    }
    
    if(result == 0) return;
    if(result == 2) {
        if (order.get_servings_size()!=0) { 
            emp.add_new_order(order);
            stringstream buf;
            buf << order ;
            string out = buf.str();
            cout << order << endl;
            Gtk::MessageDialog dialog(*this, out);
            dialog.run();
            dialog.close();
        }
    }
}

Serving Main_window::create_serving() {
    //get vectors
    vector<Containr> _containers = emp.get_containers();
    vector<Flavor> _flavors = emp.get_flavors();
    vector<Topping> _toppings = emp.get_toppings();

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
        else serving.set_topping(_toppings[topping]);
    }

    return serving;
}

void Main_window::on_new_customer() {
    vector<string> res;
    res = Dialogs::add_customer();
	if (res.size() == 2) {
		Customer cust(res[0], emp.get_customers().size()+1, res[2]);
	    emp.add_new_customer(cust);
    }
}

//report callbacks
void Main_window::on_servers_report() {
    string res = emp.get_servers_report();
}
void Main_window::on_customers_report() {
    string res = emp.get_customers_report();
}
void Main_window::on_inventory_report() {
    string res = emp.get_inventory_report();
}
void Main_window::on_orders_report() {
    string res = emp.get_orders_report();
}
void Main_window::on_pnl_report() {
    string res = emp.get_pnl_report();
}

void Main_window::on_contents_click() {   //shows help or program documentation
    Gtk::Dialog dialog{"Store Contents", *this};
    
    //flavor contents
    Gtk::Image c_img{"f_chocolate.png"};
    Gtk::Button but{"", 1};
    but.set_image(c_img);
    dialog.get_vbox()->pack_start(but, Gtk::PACK_SHRINK);
    
    Gtk::Image v_img{"f_vanilla.png"};
    Gtk::Button but1{"", 2};
    but1.set_image(v_img);
    dialog.get_vbox()->pack_start(but1, Gtk::PACK_SHRINK);
    
    Gtk::Image s_img{"f_strawberry.png"};
    Gtk::Button but2{"", 3};
    but2.set_image(s_img);
    dialog.get_vbox()->pack_start(but2, Gtk::PACK_SHRINK);
    
    //toppings contents
    Gtk::Image thf_img{"t_hot_fudge.png"};
    Gtk::Button but3{"", 4};
    but3.set_image(thf_img);
    dialog.get_vbox()->pack_start(but3, Gtk::PACK_SHRINK);
    
    Gtk::Image tc_img{"t_caramel.png"};
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


