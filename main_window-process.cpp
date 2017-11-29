#include "main_window.h"


//process callbacks
void Main_window::on_cancel_order(){
	vector<string> names;
	vector<Order> orders = emp.get_orders();
	vector<int> o_id;

    for(Order s: orders) {
		if(s.get_state() == "Unfilled") {
			names.push_back(to_string(s.get_id()));
			o_id.push_back(s.get_id());
		}
	}

	if(names.size()==0) {
		Gtk::MessageDialog dialog{*this, "No orders to Cancel!"};
	    dialog.run();
	    dialog.close();
		return;
	}

    int id = select_from_vector(names, "Order to Canel");

	if (id!=-1) {
		emp.set_order_state(o_id[id], "Cancelled", Server{"TBD", -1, "TBD", 0});
	}

	on_order_update();
}

void Main_window::on_fill_order() {

	vector<string> names; vector<int> o_id;
	vector<Server> _servers = emp.get_servers();
	vector<Order> orders = emp.get_orders();

    for(Order s: orders) {
		if(s.get_state() == "Unfilled") {
			names.push_back(to_string(s.get_id()));
			o_id.push_back(s.get_id());
		}
	}

	if(names.size()==0) {
		Gtk::MessageDialog dialog{*this, "No orders to Fill!"};
		dialog.run();
		dialog.close();
		return;
	}

	int id = select_from_vector(names, "Order to Fill");

	if (id == -1) return;

	names.clear();
	for(Server s: _servers) {
		names.push_back(s.get_name());
	}

	int s_c = select_from_vector(names, "Server");

	if (id!=-1 && s_c!=-1) {
		bool status = emp.set_order_state(o_id[id], "Filled", _servers[s_c]);

		if (!status) {
			Gtk::Dialog ardlg{"Re-Stock Stragedy", *this};
			ardlg.add_button("Manuel", 0);
			ardlg.add_button("Auto Re-Stock", 1);

			if(ardlg.run() == 1) {
				emp.auto_restock(_servers[s_c], o_id[id]);
				emp.set_order_state(o_id[id], "Filled", _servers[s_c]);
			}
		}
	}

	on_order_update();
}

void Main_window::on_pay_order() {

	vector<string> names; vector<int> o_id;
	vector<Order> orders = emp.get_orders();

    for(Order s: orders) {
		if(s.get_state() == "Filled") {
			names.push_back(to_string(s.get_id()));
			o_id.push_back(s.get_id());
		}
	}

	if(names.size()==0) {
		Gtk::MessageDialog dialog{*this, "No orders to Pay!"};
	    dialog.run();
	    dialog.close();
		return;
	}

    int id = select_from_vector(names, "Order to Pay");

	if (id!=-1) {
		emp.set_order_state(o_id[id], "Paid", Server{"TBD", -1, "TBD", 0});
	}

	on_order_update();
}
