#include "main_window.h"


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
