#include "main_window.h"

Controller ctrl;

Main_window::Main_window() {
    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(500, 200);

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

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_quit);
    
    //Manager to the menu bar
    Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
    menubar->append(*menuitem_create);
    Gtk::Menu *create_menu = Gtk::manage(new Gtk::Menu());
    menuitem_create->set_submenu(*create_menu);

    // new falvor menu
    Gtk::MenuItem *menuitem_flavor = Gtk::manage(new Gtk::MenuItem("_New Flavor", true));
    menuitem_flavor->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_flavor));
    create_menu->append(*menuitem_flavor);
    
    // new topping menu
    Gtk::MenuItem *menuitem_topping = Gtk::manage(new Gtk::MenuItem("_New Topping", true));
    menuitem_topping->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_topping));
    create_menu->append(*menuitem_topping);
    
    // new container menu
    Gtk::MenuItem *menuitem_container = Gtk::manage(new Gtk::MenuItem("_New Container", true));
    menuitem_container->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_container));
    create_menu->append(*menuitem_container);

    // Make the box and everything in it visible
    vbox->show_all();
}

Main_window::~Main_window() { }

void Main_window::on_new_flavor() {
    ctrl.execute_cmd(1);
}

void Main_window::on_new_topping() {
    ctrl.execute_cmd(2);
}

void Main_window::on_new_container() {
    ctrl.execute_cmd(3);
}
void Main_window::on_quit_click() {
    hide();
}
