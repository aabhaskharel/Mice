#include "emporium.h"
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

Emporium::Emporium(int id, string location, string phone) : _id{id}, _location{location}, _phone{phone}, _stocking_cost{0}, cash_register{1000} {}

void Emporium::add_container(Containr cont){
	_containers.push_back(cont);
}

void Emporium::add_flavor(Flavor flav) {
    _flavors.push_back(flav);
}

void Emporium::add_topping(Topping top){
    _toppings.push_back(top);
}

void Emporium::add_server(Server server){
    _servers.push_back(server);
}

void Emporium::add_customer(Customer customer){
    _customers.push_back(customer);
}

void Emporium::add_manager(Manager manager) {
    _managers.push_back(manager);
}

void Emporium::add_order(Order order) {
    _orders.push_back(order);
}

void Emporium::set_order_state(Order order, string state) {
	order.set_state(state);
	if (state == "Filled")
	{
		double trp = order.get_total_retail_price();
		cash_register += trp;
		Server server = order.get_server();
		server.set_total_filled(1);
		if (server.pay())
		{
			cash_register -= server.get_hourly_salary();
			server.set_total_pay(server.get_hourly_salary());
		}
		
		vector<Serving> svg = order.get_servings();
		for (Serving s: svg) {
		Containr c = s.get_container();
		c.set_stock(-1);
		vector<Flavor> fv = s.get_flavors();
		for (Flavor f: fv)
		{
			f.set_stock(-1);
		}
		vector<Topping> tv = s.get_toppings();
		vector<int> kv = s.get_top_kind();
		for (int i = 0; i<tv.size(); i++)
		{
			switch (kv[i])
			{
			case 0:	tv[i].set_stock(-1); break;
			case 1:	tv[i].set_stock(-2); break;
			case 2:	tv[i].set_stock(-3); break;
			case 3:	tv[i].set_stock(-4); break;	
			}	
		}
		
		}
		
		
		
	}
}

//getters
vector<Containr> Emporium::get_containers() {
    return _containers;
}
vector<Topping> Emporium::get_toppings() {
    return _toppings;
}
vector<Flavor> Emporium::get_flavors() {
    return _flavors;
}
vector<Server> Emporium::get_servers() {
    return _servers;
}
vector<Containr> Emporium::get_retired_containers() {
    return _retired_containers;
}
vector<Topping> Emporium::get_retired_toppings() {
    return _retired_toppings;
}
vector<Flavor> Emporium::get_retired_flavors() {
    return _retired_flavors;
}
vector<Server> Emporium::get_retired_servers() {
    return _retired_servers;
}
vector<Customer> Emporium::get_customers(){
	return _customers;
}
vector<Manager> Emporium::get_managers() {
    return _managers;
}
vector<Order> Emporium::get_orders() {
    return _orders;
}


//report calls
string Emporium::get_servers_report() {
	string out = "\n";
	out += "		Mavs Ice Cream Emporium -- " + to_string(_id) + "		" + "\n";
	out += "		" + _location + "		" + "\n"; 
	out += "		" + _phone + "		    "  + "\n\n";
	out += "SERVERS REPORT\n\n";
	out += "Active Servers: \n\n";
	for(int i=0; i<_servers.size(); i++){
		out += "\tName: " +_servers[i].get_name() + "\tEmployee #: " + to_string(_servers[i].get_id()) + "\tTotal Order Filled: " +
		to_string(_servers[i].get_total_filled()) + "\tHourly Salary: "+ to_string(_servers[i].get_hourly_salary()) + "\tTotal earned: "+to_string(_servers[i].get_total_pay())+ "\n";
	}
	
	out += "\nSuspended Servers: \n\n";
	for(int i=0; i<_retired_servers.size(); i++){
		out += "\tName: " +_retired_servers[i].get_name() + "\tEmployee #: " + to_string(_retired_servers[i].get_id()) + "\tTotal Order Filled: " +
		to_string(_retired_servers[i].get_total_filled()) + "\tHourly Salary: "+ to_string(_retired_servers[i].get_hourly_salary()) + "\tTotal earned: "+to_string(_retired_servers[i].get_total_pay())+ "\n";
	}
	
	return out;
	
}

string Emporium::get_customers_report() {
	string out = "\n";
	out += "		Mavs Ice Cream Emporium -- " + to_string(_id) + "		" + "\n";
	out += "		" + _location + "		" + "\n"; 
	out += "		" + _phone + "		    "  + "\n\n";
	out += "CUSTOMERS REPORT\n\n";
	
	
	for(int i=0; i< _customers.size(); i++){
		out += "\tName: " + _customers[i].get_name() + "\t\tID: " + to_string(_customers[i].get_id()) + "\tPhone: "+_customers[i].get_phone() + "\n";
	}
	
	return out;
	
}

string Emporium::get_inventory_report() {
	string out = "\n";
	out += "		Mavs Ice Cream Emporium -- " + to_string(_id) + "		" + "\n";
	out += "		" + _location + "		" + "\n"; 
	out += "		" + _phone + "		    "  + "\n\n";
	out += "INVENTORY REPORT\n\n";
	
	out += "Containers Available:\n";
	
	for(int i=0; i<_containers.size(); i++){
		out += "\tContainer name: "+_containers[i].get_name()+"\tStock Remaining: "+to_string(_containers[i].get_stock())+"\n";
	}
	
	out += "\nFlavors Available:\n";
	
	for(int i=0; i<_flavors.size(); i++){
		out += "\tFlavor name: "+_flavors[i].get_name()+"\tStock Remaining: "+to_string(_flavors[i].get_stock())+"\n";
	}
	
	out += "\nToppingsAvailable:\n";
	
	for(int i=0; i<_toppings.size(); i++){
		out += "\tTopping name: "+_toppings[i].get_name()+"\tStock Remainig: "+to_string(_toppings[i].get_stock())+"\n";
	}
	
	return out;
}

string Emporium::get_orders_report() {
	string out = "\n";
	out += "		Mavs Ice Cream Emporium -- " + to_string(_id) + "		" + "\n";
	out += "		" + _location + "		" + "\n"; 
	out += "		" + _phone + "		    "  + "\n\n";
	out += "ORDER REPORT\n\n";
	out += "Filled/Paid Orders\n\n";
	
	for(int i=0; i<_orders.size(); i++){
		if (_orders[i].get_state() == "Filled") {
		out += "\nOrder #" + to_string(_orders[i].get_id()) + "\n";
		out += "\tWholesale cost: " + to_string(_orders[i].get_total_wholesale_price()) + "\n\tRetail cost: " + to_string(_orders[i].get_total_retail_price())+"\n";
		out += "\tProfit: " + to_string(_orders[i].get_total_retail_price()-_orders[i].get_total_wholesale_price()) + "\n\n";
		}	
	}
	
	out += "\nCancelled Orders\n\n";
	
	for(int i=0; i<_orders.size(); i++){
		if (_orders[i].get_state() == "Cancelled") {
		out += "\nOrder #" + to_string(_orders[i].get_id()) + "\n";
		}	
	}
	
	return out;
}

string Emporium::get_pnl_report() {
	string out = "\n";
	out += "		Mavs Ice Cream Emporium -- " + to_string(_id) + "		" + "\n";
	out += "		" + _location + "		" + "\n"; 
	out += "		" + _phone + "		    "  + "\n\n";
	out += "PROFIT AND LOSS STATEMENT\n\n";
	
	double orders_retail = 0;
	double total_salary = 0;
	
	for(int i=0; i<_orders.size(); i++){
		orders_retail += _orders[i].get_total_retail_price();
	}
	
	for(int i=0; i<_servers.size(); i++){
		total_salary += _servers[i].get_total_pay();
	}
	
	out += "Income:\n";
	out += "\tTotal earnings from orders: " + to_string(orders_retail) + "\n\n";
	out += "Expenses:make\n";
	out += "\tTotal cost of items: " + to_string(_stocking_cost) + "\n";
	out += "\tTotal salaries distributed: " + to_string(total_salary) + "\n\n";
	
	double net = orders_retail - _stocking_cost - total_salary;
	if (net < 0)
	{
		out += "Loss: " + to_string(net * -1);
	}
	else
	{
		out += "Profit: " + to_string(net);
	}	
	out += "\n\n";
	
	return out;
	
}

//change server's salary
void Emporium::change_salary(int server_id, double salary){
	_servers[server_id].set_hourly_salary(salary);
}

void Emporium::retire_item(Items item, int id){
	string type = item.get_type();
	if (type == "Container")
	{	_retired_containers.push_back(_containers[id]);
		_containers.erase(_containers.begin()+id);
	}
	else if (type == "Flavor")
	{
		_retired_flavors.push_back(_flavors[id]);
		_flavors.erase(_flavors.begin()+id);
	}
	else
	{
		_retired_toppings.push_back(_toppings[id]);
		_toppings.erase(_toppings.begin()+id);
	}
}

void Emporium::retire_person(Person person, int id){
	int type = person.get_type();
	if (type == 2)
	{
		_retired_managers.push_back(_managers[id]);
		_managers.erase(_managers.begin()+id);
	}
	else
	{
		_retired_servers.push_back(_servers[id]);
		_servers.erase(_servers.begin()+id);
	}
	
}

void Emporium::restore_item(Items item, int id){
	string type = item.get_type();
	if (type == "Container")
	{	_containers.push_back(_retired_containers[id]);
		_retired_containers.erase(_retired_containers.begin()+id);
	}
	else if (type == "Flavor")
	{
		_flavors.push_back(_retired_flavors[id]);
		_retired_flavors.erase(_retired_flavors.begin()+id);
	}
	else
	{
		_toppings.push_back(_retired_toppings[id]);
		_retired_toppings.erase(_retired_toppings.begin()+id);
	}
}

void Emporium::restore_person(Person person, int id){
	int type = person.get_type();
	if (type == 2)
	{
		_managers.push_back(_retired_managers[id]);
		_retired_managers.erase(_retired_managers.begin()+id);
	}
	else
	{
		_servers.push_back(_retired_servers[id]);
		_retired_servers.erase(_retired_servers.begin()+id);
	}
	
}

//write to a file
void Emporium::write(string filename){
	
	ofstream ofs {filename};
	if(!ofs) throw runtime_error("can't open output file " + filename);
	
	ofs << "-co" << endl;
	
	//writing containers data
	for(int i=0; i<_containers.size(); i++){
		ofs << _containers[i].get_name() << "," << _containers[i].get_description() << "," << _containers[i].get_wholesale_price() << "," << _containers[i].get_retail_price() << "," << _containers[i].get_stock() << "," << _containers[i].get_image_path() << "," << _containers[i].get_scoop() << endl; 
	}
	
	ofs << "-rc" << endl;
	//retired containers
	for(int i=0; i<_retired_containers.size(); i++){
		ofs << _retired_containers[i].get_name() << "," << _retired_containers[i].get_description() << "," << _retired_containers[i].get_wholesale_price() << "," << _retired_containers[i].get_retail_price() << "," << _retired_containers[i].get_stock() << "," << _retired_containers[i].get_image_path() << "," << _retired_containers[i].get_scoop() << endl; 
	}
	
	
	//writing flavors data
	ofs << "-fl" << endl;
	
	for(int i=0; i<_flavors.size(); i++){
		ofs << _flavors[i].get_name() << "," << _flavors[i].get_description() << "," << _flavors[i].get_wholesale_price() << "," << _flavors[i].get_retail_price() << "," << _flavors[i].get_stock() << "," << _flavors[i].get_image_path() << endl;
	}
	
	//retired flavors
	ofs << "-rf" << endl;
	
	for(int i=0; i<_retired_flavors.size(); i++){
		ofs << _retired_flavors[i].get_name() << "," << _retired_flavors[i].get_description() << "," << _retired_flavors[i].get_wholesale_price() << "," << _retired_flavors[i].get_retail_price() << "," << _retired_flavors[i].get_stock() << "," << _retired_flavors[i].get_image_path() << endl;
	}
	
	ofs << "-to" << endl;
	
	for(int i=0; i<_toppings.size(); i++){
		ofs << _toppings[i].get_name() << "," << _toppings[i].get_description() << "," << _toppings[i].get_wholesale_price() << "," << _toppings[i].get_retail_price() << "," << _toppings[i].get_stock() << "," << _toppings[i].get_image_path() << "," << endl;
	}
	
	ofs << "-rt" << endl;
	
	for(int i=0; i<_retired_toppings.size(); i++){
		ofs << _retired_toppings[i].get_name() << "," << _retired_toppings[i].get_description() << "," << _retired_toppings[i].get_wholesale_price() << "," << _retired_toppings[i].get_retail_price() << "," << _retired_toppings[i].get_stock() << "," << _retired_toppings[i].get_image_path() << "," << endl;
	}
	
	ofs << "-ma" << endl;
	
	for(int i=0; i<_managers.size(); i++){
		ofs << _managers[i].get_name() << "," << _managers[i].get_id() << "," << _managers[i].get_phone() << endl;
	}
	
	ofs << "-rm" << endl;
	
	for(int i=0; i<_retired_managers.size(); i++){
		ofs << _retired_managers[i].get_name() << "," << _retired_managers[i].get_id() << "," << _retired_managers[i].get_phone() << endl;
	}
	
	ofs << "-se" << endl;
	for(int i=0; i<_servers.size(); i++){
		ofs << _servers[i].get_name() << "," << _servers[i].get_id() << "," << _servers[i].get_phone() << "," << _servers[i].get_hourly_salary() << "," << _servers[i].get_total_filled() << endl;
	}
	
	ofs << "-rs" << endl;
	for(int i=0; i<_retired_servers.size(); i++){
		ofs << _retired_servers[i].get_name() << "," << _retired_servers[i].get_id() << "," << _retired_servers[i].get_phone() << "," << _retired_servers[i].get_hourly_salary() << "," << _retired_servers[i].get_total_filled() << endl;
	}
	
	ofs << "-cu" << endl;
	
	for(int i=0; i<_customers.size(); i++){
		ofs << _customers[i].get_name() << "," << _customers[i].get_id() << "," << _customers[i].get_phone() << endl;
	}
	
	ofs << "-or" << endl;

	for(int i=0; i<_orders.size(); i++) {
		string svng = "";
		vector<Serving> servng = _orders[i].get_servings();
		for (int j = 0; j<servng.size(); j++)
		{
			svng += servng[i].get_container().get_name();
			vector<Flavor> flv = servng[i].get_flavors();
			svng += "," + flv.size();
			for (Flavor f: flv)
			{
				svng += "," + f.get_name();
			}
			vector<Topping> tps = servng[i].get_toppings();
			vector<int> tk = servng[i].get_top_kind();
			svng += "," + tps.size();
			for (Topping t: tps)
			{
				svng += "," + t.get_name();
			}
			for (int x: tk)
			{
				svng += "," + x;
			}
		}
		
		ofs << _orders[i].get_id() << "," << _orders[i].get_server().get_id() << "," << _orders[i].get_customer().get_id() << "," << svng << "," << _orders[i].get_state() << "," << endl;
	}
	
	ofs << "-cr" << endl;
	ofs << cash_register << endl;
	
	
	
}

//edit container
void Emporium::edit_container(int id, Containr container){
	_containers[id] = container;
	
}

//edit flavor
void Emporium::edit_flavor(int id, Flavor flavor){
	_flavors[id] = flavor;
	
}

//edit topping
void Emporium::edit_topping(int id, Topping topping){
	_toppings[id] = topping;

}

void Emporium::add_stock(Server server, Items item, int quantity) {
	item.set_stock(quantity);
	double wp = quantity * item.get_wholesale_price();
	_stocking_cost += wp;
	cash_register -= wp;
	server.set_total_filled(2);
		if (server.pay())
		{
			cash_register -= server.get_hourly_salary();
			server.set_total_pay(server.get_hourly_salary());
		}
	
}

void Emporium:: populate_emporium(){
    Containr cont("Cup", "A freshly baked waffle cone.", 0.1, 0.6, "picture.png", 3);
    Containr cont2("Regular Cone", "Everyone's Favroite", 0.2, 0.8, "picture.png", 1);

    _containers.push_back(cont2);
    _containers.push_back(cont);

    Flavor flav("Chocolate", "Rich Dark Chocolate", 1, 1.99, "f_chocolate.png");
    Flavor flav2("Vanilla", "Very Smooth Vanilla", 1, 1.99, "f_vanilla.png");
    Flavor flav3("Strawberry", "Refreshing Strawberry Flavor", 1.05, 2.09, "f_strawberry.png");

    _flavors.push_back(flav);
    _flavors.push_back(flav2);
    _flavors.push_back(flav3);

    Topping top("Whipped Cream", "An Irrestible topping", 0.05, 0.25, "picture.png");
    Topping top2("Hot Fudge", "Hot & Fresh chocolate", 0.25, 0.75, "picture.png");
    Topping top3("Cherry", "Red and bright delight", 0.01, 0.1, "t_cherry.png");

    _toppings.push_back(top);
    _toppings.push_back(top2);
    _toppings.push_back(top3);
    
    _servers.push_back(Server{"Pujan B.", 0, "817-928-9301",  8.5});
    _servers.push_back(Server{"Ankit R.", 1, "817-928-9301",  8.5});
    
    _customers.push_back(Customer{"Jeevan G.", 0, "817-928-9301"});
    _customers.push_back(Customer{"Sumit N.", 1, "817-213-4123"});
    
    _managers.push_back(Manager{"Aabhas K.", 0, "817-391-9304"}); 
    
}

