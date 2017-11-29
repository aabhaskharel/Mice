#include "main_window.h"

Main_window::Main_window() {
	// /////////////////
	// G U I   S E T U P
	// /////////////////

	set_default_size(500, 250);

	// Put a vertical box container as the Window contents
	vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
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
	menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Emporium", true));
	menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_mgmt_click));
	filemenu->append(*menuitem_new);

	//save to a file
	menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save Emporium", true));
	menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_save_click));
	filemenu->append(*menuitem_save);

	//load an Emporium
	menuitem_load = Gtk::manage(new Gtk::MenuItem("_Load Emporium", true));
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
	menuitem_edit = Gtk::manage(new Gtk::MenuItem("_Edit", true));
	menubar->append(*menuitem_edit);
	Gtk::Menu *editmenu = Gtk::manage(new Gtk::Menu());
	menuitem_edit->set_submenu(*editmenu);

	// edit item
	menuitem_eitem = Gtk::manage(new Gtk::MenuItem("_Edit Item", true));
	menuitem_eitem->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_edit_item_click));
	editmenu->append(*menuitem_eitem);

	//edit server
	menuitem_eserver = Gtk::manage(new Gtk::MenuItem("_Edit Server", true));
	menuitem_eserver->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_edit_server_click));
	editmenu->append(*menuitem_eserver);

	//restore person
	menuitem_restore_person = Gtk::manage(new Gtk::MenuItem("_Restore Person", true));
	menuitem_restore_person->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_restore_person_click));
	editmenu->append(*menuitem_restore_person);

	//happy hour
	menuitem_happy_hour = Gtk::manage(new Gtk::MenuItem("_Happy Hour", true));
	menuitem_happy_hour->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_happy_hour_click));
	editmenu->append(*menuitem_happy_hour);

	//create menu
	Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
	menubar->append(*menuitem_create);
	Gtk::Menu *create_menu = Gtk::manage(new Gtk::Menu());
	menuitem_create->set_submenu(*create_menu);

	//new order option
	Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_New Order", true));
	menuitem_order->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_order));
	create_menu->append(*menuitem_order);

	// new customer menu
	menuitem_add_customer = Gtk::manage(new Gtk::MenuItem("_New Customer", true));
	menuitem_add_customer->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_customer));
	create_menu->append(*menuitem_add_customer);

	//new item menu
	menuitem_item = Gtk::manage(new Gtk::MenuItem("_New Item", true));
	menuitem_item->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_item));
	create_menu->append(*menuitem_item);

	// new server menu
	menuitem_add_server = Gtk::manage(new Gtk::MenuItem("_New Server", true));
	menuitem_add_server->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_server));
	create_menu->append(*menuitem_add_server);

	// new manager menu
	menuitem_new_manager = Gtk::manage(new Gtk::MenuItem("_New Manager", true));
	menuitem_new_manager->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_manager));
	create_menu->append(*menuitem_new_manager);

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
	menuitem_fill = Gtk::manage(new Gtk::MenuItem("_Fill Order", true));
	menuitem_fill->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_fill_order));
	process_menu->append(*menuitem_fill);

	//pay order
	menuitem_pay = Gtk::manage(new Gtk::MenuItem("_Pay Order", true));
	menuitem_pay->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_pay_order));
	process_menu->append(*menuitem_pay);

	//REPORTS
	menuitem_reports = Gtk::manage(new Gtk::MenuItem("_Reports", true));
	menubar->append(*menuitem_reports);
	Gtk::Menu *report_menu = Gtk::manage(new Gtk::Menu());
	menuitem_reports->set_submenu(*report_menu);

	Gtk::MenuItem *menuitem_receipt = Gtk::manage(new Gtk::MenuItem("_Receipt", true));
	menuitem_receipt->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_receipt_click));
	report_menu->append(*menuitem_receipt);

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

	Gtk::Image *new_order_image = Gtk::manage(new Gtk::Image("data/pictures/new_order.png"));
	Gtk::ToolButton *new_order_button = Gtk::manage(new Gtk::ToolButton(*new_order_image));
	new_order_button->set_tooltip_markup("Start a new order");
	new_order_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_new_order));
	toolbar->append(*new_order_button);

	//new customer button
	Gtk::Image *new_customer_image = Gtk::manage(new Gtk::Image("data/pictures/new_customer.png"));
	new_customer_button = Gtk::manage(new Gtk::ToolButton(*new_customer_image));
	new_customer_button->set_tooltip_markup("Add a new Customer");
	new_customer_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_new_customer));
	toolbar->append(*new_customer_button);

	//new item button
	Gtk::Image *new_item_image = Gtk::manage(new Gtk::Image("data/pictures/new_item.png"));
	new_item_button = Gtk::manage(new Gtk::ToolButton(*new_item_image));
	new_item_button->set_tooltip_markup("Add a new Item");
	new_item_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_new_item));
	toolbar->append(*new_item_button);

	Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
	sep->set_expand(true);
	toolbar->append(*sep);

	Gtk::ToolButton *test_button = Gtk::manage(new Gtk::ToolButton("Test"));
	test_button->set_tooltip_markup("Test a feature");
	test_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_test));
	toolbar->append(*test_button);

	//Login
	Gtk::Image *change_role_image = Gtk::manage(new Gtk::Image("data/pictures/change_role.png"));
	Gtk::ToolButton *new_role_button = Gtk::manage(new Gtk::ToolButton(*change_role_image));
	new_role_button->set_tooltip_markup("Logout/Login to new Role");
	new_role_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_new_role));
	toolbar->append(*new_role_button);

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

void Main_window::on_test() {
	std::cout << "TEST" << '\n';

	vector<string> names;
	for(int i = 0; i < 27; i++) {
		names.push_back("test "+to_string(i));
	}

	int choice = select_from_grid(names, names, "test");

}

void Main_window::on_order_update() {
	if(present) vbox->remove(*s_window);

	s_window = Gtk::manage(new Gtk::ScrolledWindow());
	s_window->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);

	vector<Order> orders = emp.get_orders();

	Gtk::Table *table = Gtk::manage(new Gtk::Table(orders.size()+1,2,true));
	Gtk::Label *l1 = Gtk::manage(new Gtk::Label("Order No."));
	Gtk::Label *l2 = Gtk::manage(new Gtk::Label("State"));

	table->attach(*l1,0,1,0,1);
	table->attach(*l2,1,2,0,1);

	for(int i = 0; i < orders.size(); i++) {
		Gtk::Label *l_id = Gtk::manage(new Gtk::Label(to_string(orders[i].get_id())));
		table->attach(*l_id, 0, 1, i+1, i+2);

		Gtk::Label *l_state = Gtk::manage(new Gtk::Label(orders[i].get_state()));
		table->attach(*l_state, 1, 2, i+1, i+2);
	}

	vbox->pack_start(*s_window);
	s_window->add(*table);
	vbox->show_all();
	present = true;
}

void Main_window::on_new_mgmt_click() {

	Gtk::Dialog dlg{"New Emporium", *this};

	Gtk::Label l_st{"Do you want to save your current emporium?"};
	dlg.get_vbox()->pack_start(l_st, Gtk::PACK_SHRINK);

	dlg.add_button("Cancel", 2);
	dlg.add_button("No", 0);
	dlg.add_button("Yes", 1);

	dlg.show_all();
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
	dlg.set_default_size(250,10);
    Gtk::Entry e;
    dlg.get_vbox()->pack_start(e, Gtk::PACK_SHRINK);

    dlg.add_button("Save", 1);

    dlg.show_all();
    dlg.run();

	bool valid_data = false;

	while(!valid_data) {
		if(e.get_text()=="" || e.get_text() == "*Invalid Name*") {
			valid_data = false;
			e.set_text("*Invalid Name*");
			dlg.run();
		} else valid_data = true;
	}

    string s = "data/" + e.get_text() + ".txt";

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

void Main_window::on_new_role() {

	vector<string> names;
	names.push_back("Owner");
	names.push_back("Manager");
	names.push_back("Server");
	names.push_back("Customer");

	int role = select_from_vector(names, "Role");

	if (role == -1) return;

	switch (role) {
		case 0: {
			std::cout << "Owner" << '\n';

			menuitem_new->show();
			menuitem_save->show();
			menuitem_load->show();

			menuitem_edit->show();
			menuitem_eitem->show();
			menuitem_eserver->show();
			menuitem_restore_person->show();

			menuitem_add_customer->show();
			menuitem_item->show();
			menuitem_add_server->show();
			menuitem_new_manager->show();

			menuitem_fill->show();
			menuitem_pay->show();

			menuitem_reports->show();

			new_customer_button->show();
			new_item_button->show();

			break;
		}
		case 1: {
			std::cout << "Manager" << '\n';

			menuitem_new->hide();
			menuitem_save->hide();
			menuitem_load->hide();

			menuitem_edit->show();
			menuitem_eitem->show();
			menuitem_eserver->show();
			menuitem_restore_person->hide();

			menuitem_add_customer->show();
			menuitem_item->show();
			menuitem_add_server->show();
			menuitem_new_manager->hide();

			menuitem_fill->show();
			menuitem_pay->show();

			menuitem_reports->show();

			new_customer_button->show();
			new_item_button->show();

			break;
		}
		case 2: {
			std::cout << "Server" << '\n';

			menuitem_new->hide();
			menuitem_save->hide();
			menuitem_load->hide();

			menuitem_edit->hide();

			menuitem_add_customer->show();
			menuitem_item->hide();
			menuitem_add_server->hide();
			menuitem_new_manager->hide();

			menuitem_fill->show();
			menuitem_pay->show();

			menuitem_reports->hide();

			new_customer_button->show();
			new_item_button->hide();

			break;
		}
		case 3: {
			std::cout << "Customer" << '\n';

			menuitem_new->hide();
			menuitem_save->hide();
			menuitem_load->hide();

			menuitem_edit->hide();

			menuitem_add_customer->hide();
			menuitem_item->hide();
			menuitem_add_server->hide();
			menuitem_new_manager->hide();

			menuitem_fill->hide();
			menuitem_pay->hide();

			menuitem_reports->hide();

			new_customer_button->hide();
			new_item_button->hide();

			break;
		}
		default : std::cerr << "Invalid Choice" << '\n'; break;
	}
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
	std::cout << "ID:" << dialog.run() << '\n';
}

void Main_window::on_about_click() {   //shows company description
	Gtk::AboutDialog dialog{};
	dialog.set_transient_for(*this);
	dialog.set_program_name("Mav's Ice Cream Emporium");
	auto logo = Gdk::Pixbuf::create_from_file("data/pictures/logo.png");
	dialog.set_logo(logo);
	dialog.set_version("Sprint 3");
	dialog.set_copyright("Copyright 2017");
	dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
	std::vector< Glib::ustring > authors = {"Safal Lamsal, Aabhas Kharel, Roshan Shrestha, Bibek Sapkota"};
	dialog.set_authors(authors);
	std::vector< Glib::ustring > artists = {"Logo by weewilliewinkie https://pixabay.com/en/ice-cream-cup-summer-glass-wafer-2109460"
	, "Store Contents design by Jeevan Gyawali", "Icons by Iconsflow https://iconsflow.com/"};
	dialog.set_artists(artists);
	dialog.run();
}

void Main_window::on_quit_click() {
	hide();
}
