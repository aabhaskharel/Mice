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
		emp.set_order_state(id+offset, "Cancelled", Server{"TBD", -1, "TBD", 0});
		offset = 0;
	}

	on_order_update();
}

void Main_window::on_fill_order() {

	vector<string> names;
	vector<Server> _servers = emp.get_servers();
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

	for(Server s: _servers) {
		names.clear();
		names.push_back(s.get_name());
	}

	int s_c = select_from_vector(names, "Server");

	if (id!=-1 && s_c!=-1) {
		//orders[id+offset].set_server(_servers[s_c]);

		emp.set_order_state(id+offset, "Filled", _servers[s_c]);

		//orders[id+offset].process_event("Fill", _servers[s_c]);
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
		emp.set_order_state(id+offset, "Paid", Server{"TBD", -1, "TBD", 0});
		offset = 0;
	}

	on_order_update();
}
