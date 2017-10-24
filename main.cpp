#include <iostream>
#include <string>
#include <vector>
#include <gtkmm.h>
#include "manager.h"
#include "items.h"
#include "main_window.h"

using namespace std;

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.mice");
    
    Main_window win;
    win.set_title("Mav's Ice Cream Emporium");
    return app->run(win);
}
