#include "dialogs.h"


// A message is like cout, simply displaying information to the user
void Dialogs::message(string msg, string title) {
    Gtk::MessageDialog *dialog = new Gtk::MessageDialog(title);
    dialog->set_secondary_text(msg, true);
    dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete dialog;
}

vector<string> Dialogs::form(string title, int id) {
	vector<string> result;
	
        Gtk::Dialog *dialog = new Gtk::Dialog();
      // dialog->set_transient_for(win); // Solve this Safal, please
        dialog->set_title(title);
        
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
        e_desc.set_max_length(150);
        b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);
        
        //stock
        Gtk::HBox b_stock;
        Gtk::Label l_stock{"Stock Remaining: "};
        l_stock.set_width_chars(20);
        b_stock.pack_start(l_stock, Gtk::PACK_SHRINK);
        
        Gtk::SpinButton e_stock(0,0);
        e_stock.set_increments(1.0,1.0);
        e_stock.set_range(0,99999);
        e_stock.set_digits(0);
        e_stock.set_wrap(true);
        e_stock.set_numeric();
        e_stock.update();
        b_stock.pack_start(e_stock, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_stock, Gtk::PACK_SHRINK);
        
        //size  it can hold, id 1 refers to container and 0 refers to flavor and topping 
        
       
        
        
        Gtk::HBox b_scoop;
        Gtk::Label l_scoop{"Scoop Size: "};
        l_scoop.set_width_chars(20);
        b_scoop.pack_start(l_scoop, Gtk::PACK_SHRINK);
        
        
        Gtk::SpinButton e_scoop(0,0);
        e_scoop.set_increments(1.0,1.0);
        e_scoop.set_range(0,99999);
        e_scoop.set_digits(0);
        e_scoop.set_wrap(true);
        e_scoop.set_numeric();
        b_scoop.pack_start(e_scoop, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_scoop, Gtk::PACK_SHRINK);
        if (id !=1) {e_scoop.set_sensitive(false);}
        
        
        
        
        
        // id 2 refers to toppings
        
         Gtk::HBox b_type;
        Gtk::Label l_type{"Type: "};
        l_type.set_width_chars(20);
        b_type.pack_start(l_type, Gtk::PACK_SHRINK);
        
        
        Gtk::ComboBoxText c_type;
        c_type.set_size_request(50);
        vector<string> types = {"Light", "Normal", "Extra", "Drenched"};
        c_type.set_active(0);
        for(string s: types) {   c_type.append(s); }
        b_type.pack_start(c_type, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_type, Gtk::PACK_SHRINK);
          if (id !=2) {c_type.set_sensitive(false);}
        
        
        // wholesale price
        Gtk::HBox b_wprice;
        Gtk::Label l_wprice{"Wholesale Price: "};
        l_wprice.set_width_chars(20);
        b_wprice.pack_start(l_wprice, Gtk::PACK_SHRINK);
        
        Gtk::SpinButton e_wprice(0,0);
        e_wprice.set_increments(0.1,0.01);
        e_wprice.set_range(0.00,99999.00);
        e_wprice.set_digits(2);
        e_wprice.set_value(0.00);
        e_wprice.set_wrap(true);
        e_wprice.set_numeric();
        b_wprice.pack_start(e_wprice, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_wprice, Gtk::PACK_SHRINK);
        
        // retail price
        Gtk::HBox b_rprice;
        Gtk::Label l_rprice{"Retail Price: "};
        l_rprice.set_width_chars(20);
        b_rprice.pack_start(l_rprice, Gtk::PACK_SHRINK);
        
        Gtk::SpinButton e_rprice(0,0);
        e_rprice.set_increments(0.1,0.01);
        e_rprice.set_increments(0.1,0.01);
        e_rprice.set_range(0.00,99999.00);
        e_rprice.set_digits(2);
        e_rprice.set_wrap(true);
        e_rprice.set_numeric();
        b_rprice.pack_start(e_rprice, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_rprice, Gtk::PACK_SHRINK);
        
        Gtk::HBox b_image;
        Gtk::Label l_image{"Image: "};
        l_image.set_width_chars(20);
        b_image.pack_start(l_image, Gtk::PACK_SHRINK);
        
        Gtk::FileChooserButton f_image;
        b_image.pack_start(f_image, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_image, Gtk::PACK_SHRINK);
        
        //show dialog
        dialog->add_button("Cancel", 0);
        dialog->add_button("OK", 1);
        dialog->show_all();
        int x = dialog->run();

        
        //missing some exception handeling
      
    

         if (x == 1) {
         
        result.push_back(e_name.get_text());
        result.push_back(e_desc.get_text());
        result.push_back(std::to_string(e_wprice.get_value()));
        result.push_back(std::to_string(e_rprice.get_value()));
        result.push_back(std::to_string(e_stock.get_value_as_int()));
        result.push_back(f_image.get_filename());
        if (id ==1) {   result.push_back(std::to_string(e_scoop.get_value_as_int())); }
        if (id ==2) {   result.push_back(types[c_type.get_active_row_number()]); }
         
         for(string s: result)
         {
         if (s == "")
         {
         result.clear();
        Gtk::MessageDialog dlg("You did not enter all the fields." , true, Gtk::MESSAGE_WARNING, Gtk::BUTTONS_OK, true);
	dlg.run();
	dlg.hide();
         }
         }
	
	}
	delete dialog;
	return result;
}

// A question is a message that allows the user to respond with a button
int Dialogs::question(string msg, string title,
             vector<string> buttons) {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);

    Gtk::Label *label = new Gtk::Label(msg);
    label->set_use_markup(true);
    dialog->get_content_area()->pack_start(*label);
    label->show();

    for(int i=0; i<buttons.size(); ++i) dialog->add_button(buttons[i], i);

    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete label;
    delete dialog;

    return result;
}

// A request for a line of text input
string Dialogs::input(string msg, string title, string default_text, 
             string cancel_text) {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);

    Gtk::Label *label = new Gtk::Label(msg);
    label->set_use_markup(true);
    dialog->get_content_area()->pack_start(*label);
    label->show();

    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->set_default_response(1);

    Gtk::Entry *entry = new Gtk::Entry{};
    entry->set_text(default_text);
    entry->set_max_length(50);
    entry->show();
    dialog->get_vbox()->pack_start(*entry);

    int result = dialog->run();
    string text = entry->get_text();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete entry;
    delete label;
    delete dialog;

    if (result == 1)
        return text;
    else
        return cancel_text;
}

// Display an image from a disk file
void Dialogs::image(string filename, string title, string msg) {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);

    Gtk::Label *label = new Gtk::Label(msg);
    label->set_use_markup(true);
    dialog->get_content_area()->pack_start(*label);
    label->show();

    dialog->add_button("Close", 0);
    dialog->set_default_response(0);

    Gtk::Image *image = new Gtk::Image{filename};
    image->show();
    dialog->get_vbox()->pack_start(*image);

    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete image;
    delete label;
    delete dialog;

    return;
}


