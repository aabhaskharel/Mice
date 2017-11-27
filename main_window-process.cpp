#include "main_window.h"


//process callbacks
void Main_window::on_cancel_order(){
	vector<string> names;
	vector<Order> orders = emp.get_orders();

	int offset = 0; //catches offset of other states

    for(Order s: orders) {
		if(s.get_state() == "Unfilled") {
			names.push_back(to_string(s.get_id()));
		} else offset++;
	}

	if(names.size()==0) {
		Gtk::MessageDialog dialog{*this, "No orders to Cancel!"};
	    dialog.run();
	    dialog.close();
		return;
	}

    int id = select_from_vector(names, "Cancel Order");

	if (id!=-1) {
		emp.set_order_state(id+offset, "Cancelled");
		offset = 0;
	}

	on_order_update();
}

void Main_window::on_fill_order() {
	vector<string> names;
	vector<Order> orders = emp.get_orders();

	int offset = 0; //catches offset of other states


    for(Order s: orders) {
		if(s.get_state() == "Unfilled") {
			names.push_back(to_string(s.get_id()));
		} else offset++;
	}

	if(names.size()==0) {
		Gtk::MessageDialog dialog{*this, "No orders to Fill!"};
	    dialog.run();
	    dialog.close();
		return;
	}

    int id = select_from_vector(names, "Fill Order");

	if (id!=-1) {
		emp.set_order_state(id+offset, "Filled");
		offset = 0;
	}

	on_order_update();
}

void Main_window::on_pay_order() {
	vector<string> names;
	vector<Order> orders = emp.get_orders();

	int offset = 0; //catches offset of other states


    for(Order s: orders) {
		if(s.get_state() == "Filled") {
			names.push_back(to_string(s.get_id()));
		} else offset++;
	}

	if(names.size()==0) {
		Gtk::MessageDialog dialog{*this, "No orders to Pay!"};
	    dialog.run();
	    dialog.close();
		return;
	}

    int id = select_from_vector(names, "Pay Order");

	if (id!=-1) {
		emp.set_order_state(id+offset, "Paid");
		offset = 0;
	}

	on_order_update();
}
