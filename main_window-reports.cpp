#include "main_window.h"

void Main_window::on_receipt_click() {
	vector<string> names;
	vector<Order> _orders = emp.get_orders();

	if(_orders.size()==0) {
		Gtk::MessageDialog dialog{*this, "No orders in the system!"};
	    dialog.run();
	    dialog.close();
		return;
	}

	for(Order o: _orders) {
		names.push_back("Order "+ to_string(o.get_id()));
	}

	int id = select_from_vector(names, "Order");

	if(id!=-1) {
		string out = _orders[id].list_serving(id);

		Gtk::Dialog o_dialog{"Order " + to_string(id), *this};
		Gtk::Label l_text{out};
		o_dialog.get_vbox()->pack_start(l_text, Gtk::PACK_SHRINK);

		o_dialog.add_button("Ok", 1);
		o_dialog.show_all();
		o_dialog.run();
		o_dialog.close();
	}

}

//report callbacks
void Main_window::on_servers_report() {

	int size = emp.get_servers().size();

	if(size==0) {
		Gtk::MessageDialog dialog{*this, "No servers in the system!"};
	    dialog.run();
	    dialog.close();
		return;
	}

	string res = emp.get_servers_report();

	Gtk::Dialog s_dialog{"Servers Report", *this};
	Gtk::Label l_text{res};
	s_dialog.get_vbox()->pack_start(l_text, Gtk::PACK_SHRINK);

	s_dialog.add_button("Ok", 1);
	s_dialog.show_all();
	s_dialog.run();
}

void Main_window::on_customers_report() {

	int size = emp.get_customers().size();

	if(size==0) {
		Gtk::MessageDialog dialog{*this, "No customers in the system!"};
	    dialog.run();
	    dialog.close();
		return;
	}

	string res = emp.get_customers_report();

	Gtk::Dialog c_dialog{"Customers Report", *this};
	Gtk::Label lc_text{res};
	c_dialog.get_vbox()->pack_start(lc_text, Gtk::PACK_SHRINK);

	c_dialog.add_button("Ok", 1);
	c_dialog.show_all();
	c_dialog.run();
}

void Main_window::on_inventory_report() {

	int size = emp.get_containers().size();
	size += emp.get_flavors().size();
	size+= emp.get_toppings().size();

	if(size==0) {
		Gtk::MessageDialog dialog{*this, "No items in the system!"};
	    dialog.run();
	    dialog.close();
		return;
	}

	string res = emp.get_inventory_report();

    Gtk::Dialog i_dialog{"Inventory Report", *this};
	Gtk::Label li_text{res};
	i_dialog.get_vbox()->pack_start(li_text, Gtk::PACK_SHRINK);

	i_dialog.add_button("Ok", 1);
	i_dialog.show_all();
	i_dialog.run();
}

void Main_window::on_orders_report() {

	int size = emp.get_orders().size();

	if(size==0) {
		Gtk::MessageDialog dialog{*this, "No orders in the system!"};
	    dialog.run();
	    dialog.close();
		return;
	}

	string res = emp.get_orders_report();

    Gtk::Dialog o_dialog{"Orders Report", *this};
	Gtk::Label lo_text{res};
	o_dialog.get_vbox()->pack_start(lo_text, Gtk::PACK_SHRINK);

	o_dialog.add_button("Ok", 1);
	o_dialog.show_all();
	o_dialog.run();
}

void Main_window::on_pnl_report() {
	string res = emp.get_pnl_report();
/*
	if(first_report) {
		//all_pnl.push_back(emp.get_pnl_report());
		first_report = false;
	}	else all_pnl[emp_id] = emp.get_pnl_report();
*/
	Gtk::Dialog p_dialog{"Profit & Loss Report", *this};
	Gtk::Label lp_text{res};
	p_dialog.get_vbox()->pack_start(lp_text, Gtk::PACK_SHRINK);

	p_dialog.add_button("Ok", 1);
	p_dialog.show_all();
	p_dialog.run();
}

void Main_window::on_all_pnl_report() {
	string res = emp.get_pnl_report();

	for(int i = 0; i < all_pnl.size(); i++) {
		res += all_pnl[i];
	}

	Gtk::Dialog p_dialog{"Aggregate Profit & Loss Report", *this};
	Gtk::Label lp_text{res};
	p_dialog.get_vbox()->pack_start(lp_text, Gtk::PACK_SHRINK);

	p_dialog.add_button("Ok", 1);
	p_dialog.show_all();
	p_dialog.run();
}
