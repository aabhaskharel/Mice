#include "main_window.h"

Controller ctrl;

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
    Gtk::MenuItem *menuitem_serving = Gtk::manage(new Gtk::MenuItem("_New Serving", true));
    menuitem_serving->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_serving));
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
    Gtk::MenuItem *menuitem_serving1 = Gtk::manage(new Gtk::MenuItem("_New Serving", true));
    menuitem_serving1->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_serving));
    customer_menu->append(*menuitem_serving1);
    
     Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *help_menu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*help_menu);
    
     Gtk::MenuItem *menuitem_contents = Gtk::manage(new Gtk::MenuItem("_Contents", true));
    menuitem_contents->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_contents_click));
    help_menu->append(*menuitem_contents);
    
    // new container menu
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
	ctrl.execute_cmd(42);
}

void Main_window::on_new_flavor() {
    ctrl.execute_cmd(2);
}

void Main_window::on_new_topping() {
    ctrl.execute_cmd(3);
}

void Main_window::on_new_container() {
    ctrl.execute_cmd(4);
}

void Main_window::on_new_server() {
    ctrl.execute_cmd(5);
}

void Main_window::on_new_serving() {
    ctrl.execute_cmd(6);
}

void Main_window::on_new_customer() {
    ctrl.execute_cmd(7);
}

void Main_window::on_contents_click() {   //shows help or program documentation
	ctrl.execute_cmd(8);
}

void Main_window::on_about_click() {   //shows company description
	ctrl.execute_cmd(9);
}

void Main_window::on_quit_click() {
    ctrl.execute_cmd(0);
}


