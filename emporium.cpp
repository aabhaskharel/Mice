#include "emporium.h"
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <ctime>

using namespace std;

Emporium::Emporium(int id, string location, string phone) : _id{id}, _location{location}, _phone{phone}, _stocking_cost{0}, cash_register{0}, _happy_hour{false} {}
Emporium::Emporium(std::istream& ist) {
    // WARNING: Do NOT strip the header - pass the FULL FILE to Emporium!
    std::string header1, header2;

    std::getline(ist, header1); // magic cookie
    std::getline(ist, header2);
    if (header1 != "MICE") throw std::runtime_error("NOT an Emporium file");
    if (header2 != "0.1") throw std::runtime_error("Incompatible file version");

    std::getline(ist, header1); // header
    std::getline(ist, header2);
    if (header1 != "#") throw std::runtime_error("No Emporium records in file");
    if (header2 != "EMPORIUM") throw std::runtime_error("Malformed Emporium record");

    //std::getline(ist, _name);
	std::getline(ist, _location);
	std::getline(ist, _phone);
    ist >> cash_register; ist.ignore();
    ist >> _id; ist.ignore();

    while(ist) {
        std::getline(ist, header1); // header
        std::getline(ist, header2);

        if (header1 != "#") throw std::runtime_error("missing # during input");
        if (header2 == "CONTAINER") _containers.push_back(Containr{ist});
        else if (header2 == "FLAVOR") _flavors.push_back(Flavor{ist});
        else if (header2 == "TOPPING") _toppings.push_back(Topping{ist});
        else if (header2 == "ORDER") _orders.push_back(Order{ist});
        else if (header2 == "SERVER") _servers.push_back(Server{ist});
        else if (header2 == "CUSTOMER") _customers.push_back(Customer{ist});
        else if (header2 == "END EMPORIUM") break;
        else throw std::runtime_error("invalid item type in Emporium");
    }
}

void Emporium::save(std::ostream& ost) {
        ost << "MICE" << std::endl << "0.1" << std::endl; // magic cookie
        ost << "#" << std::endl << "EMPORIUM" << std::endl; // header
        //ost << _name << std::endl;
		ost << _location << std::endl;
		ost << _phone << std::endl;
        ost << cash_register << std::endl;
        ost << _id << std::endl;

        for (Containr c : _containers) c.save(ost);
        for (Flavor s : _flavors) s.save(ost);
        for (Topping t : _toppings) t.save(ost);
        for (Order o : _orders) o.save(ost);
        for (Server s : _servers) s.save(ost);
        for (Customer c : _customers) c.save(ost);
        ost << "#" << std::endl << "END EMPORIUM" << std::endl; // footer
}

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

int Emporium::get_id(){
	return _id;
}

bool Emporium::set_order_state(int id, string state, Server server) {

	bool check = true;

	if (state == "Filled")
	{
		double trp = _orders[id].get_total_retail_price();
		cash_register += trp;
		double twp = _orders[id].get_total_wholesale_price();
		_stocking_cost += twp;

		int sid = server.get_id();
		_servers[sid].set_total_filled(1);

		if (_servers[sid].pay())
		{
			cash_register -= server.get_hourly_salary();
			_servers[sid].set_total_pay(server.get_hourly_salary());
		}

		vector<Serving> svg = _orders[id].get_servings();

		for (Serving s: svg) {
		Containr c = s.get_container();
			for(int i=0; i< _containers.size(); i++){
				if(_containers[i].get_name() == c.get_name()){
					if(_containers[i].get_stock() == 0) { check = false; }
					else{_containers[i].set_stock(-1);}
				}
			}

		vector<Flavor> fv = s.get_flavors();
		for (int i=0; i<_flavors.size(); i++)
		{
			for(int j=0; j<fv.size(); j++){
				if(_flavors[i].get_name() == fv[j].get_name()){
					if(_flavors[i].get_stock() == 0) {check = false;}
					else{_flavors[i].set_stock(-1);}
				}
			}
		}

		vector<Topping> tv = s.get_toppings();

		for (int i=0; i<_toppings.size(); i++)
		{
			for(int j=0; j<tv.size(); j++){
				if(_toppings[i].get_name() == tv[j].get_name()){
					int amount = tv[j].get_amount();
					if(_toppings[i].get_stock() < amount){check = false;}
					else{_toppings[i].set_stock(-amount);}
				}
			}
		}

		}
	}

	if (check) _orders[id].process_event(state, server);

	return check;
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
vector<Manager> Emporium::get_retired_managers() {
    return _retired_managers;
}
vector<Customer> Emporium::get_retired_customers(){
	return _retired_customers;
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
	out += "		" + _phone + "		    "  + "\n______________________________\n";
	out += "INVENTORY REPORT\n------------------------------\n";

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

	out += "\n______________________________\n";
	return out;
}

string Emporium::get_orders_report() {
	string out = "\n";
	out += "		Mavs Ice Cream Emporium -- " + to_string(_id) + "		" + "\n";
	out += "		" + _location + "		" + "\n";
	out += "		" + _phone + "		    "  + "\n______________________________\n";
	out += "ORDER REPORT\n------------------------------\n";
	for(int i=0; i<_orders.size(); i++){
		if (_orders[i].get_state() == "Paid") {
			out += "Paid Orders:\n";
			break;
		}
	}

	for(int i=0; i<_orders.size(); i++){
		if (_orders[i].get_state() == "Paid") {
		out += "\nOrder #" + to_string(_orders[i].get_id()) + "\n";
		double retail = _orders[i].get_total_retail_price();
		out += "\tWholesale cost: " + to_string(_orders[i].get_total_wholesale_price()) + "\n\tRetail cost: " + to_string(retail)+"\n";
		double profit = retail - _orders[i].get_total_wholesale_price();
		out += "\tProfit: " + to_string(profit) + "\n______________________________\n";
		}
	}

	for(int i=0; i<_orders.size(); i++){
		if (_orders[i].get_state() == "Cancelled") {
			out += "\nCancelled Orders:\n";
			break;
		}
	}

	for(int i=0; i<_orders.size(); i++){
		if (_orders[i].get_state() == "Cancelled") {
		out += "\n\tOrder #" + to_string(_orders[i].get_id()) + "\n______________________________\n";
		}
	}

	return out;
}

string Emporium::get_pnl_report() {
	string out = "\n";
	out += "		Mavs Ice Cream Emporium -- " + to_string(_id) + "		" + "\n";
	out += "		" + _location + "		" + "\n";
	out += "		" + _phone + "		    "  + "\n______________________________\n";
	out += "PROFIT AND LOSS STATEMENT\n------------------------------\n";

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
	out += "\n______________________________\n";

	return out;

}

//aggregate Profit and Loss statement
string Emporium::get_all_pnl_report(){

}

//change server's salary
void Emporium::change_salary(int server_id, double salary){
	_servers[server_id].set_hourly_salary(salary);
}

void Emporium::retire_item(int item, int id){
	if (item == 0)
	{	_retired_containers.push_back(_containers[id]);
		_containers.erase(_containers.begin()+id);
	}
	else if (item == 1)
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

void Emporium::retire_person(int type, int id){
	
	if (type == 0)
	{
		_retired_managers.push_back(_managers[id]);
		_managers.erase(_managers.begin()+id);
	}
	else if (type == 1)
	{
		_retired_servers.push_back(_servers[id]);
		_servers.erase(_servers.begin()+id);
	}
	else if (type == 2)
	{
		_retired_customers.push_back(_customers[id]);
		_customers.erase(_customers.begin()+id);
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

//restore person
void Emporium::restore_person(int type, int id){
	
	if (type == 0)
	{
		_managers.push_back(_retired_managers[id]);
		_retired_managers.erase(_retired_managers.begin()+id);
	}
	else if (type == 1)
	{
		_servers.push_back(_retired_servers[id]);
		_retired_servers.erase(_retired_servers.begin()+id);
	}
	else if (type == 2)
	{
		_customers.push_back(_retired_customers[id]);
		_retired_customers.erase(_retired_customers.begin()+id);
	}

}

//Happy Hour
bool Emporium::happy_hour(){

	if(_happy_hour == false){
		for(int i=0; i<_containers.size(); i++){
			_containers[i].set_retail_price(_containers[i].get_retail_price()*0.7);
		}

		for(int i=0; i<_flavors.size(); i++){
			_flavors[i].set_retail_price(_flavors[i].get_retail_price()*0.7);
		}

		for(int i=0; i<_toppings.size(); i++){
			_toppings[i].set_retail_price(_toppings[i].get_retail_price()*0.7);
		}

		_happy_hour = true;
	}

	else{
		for(int i=0; i<_containers.size(); i++){
			_containers[i].set_retail_price(_containers[i].get_retail_price()/0.7);
		}

		for(int i=0; i<_flavors.size(); i++){
			_flavors[i].set_retail_price(_flavors[i].get_retail_price()/0.7);
		}

		for(int i=0; i<_toppings.size(); i++){
			_toppings[i].set_retail_price(_toppings[i].get_retail_price()/0.7);
		}
		_happy_hour = false;
	}
	return _happy_hour;
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

//edit customer
void Emporium::edit_customer(string name, string phone, int id){
	_customers[id].set_name(name);
	_customers[id].set_phone(phone);
}

//edit server
void Emporium::edit_server(string name, string phone, double salary, int id){
	_servers[id].set_name(name);
	_servers[id].set_phone(phone);
	_servers[id].set_hourly_salary(salary);
}

//edit manager
void Emporium::edit_manager(string name, string phone, int id){
	_managers[id].set_name(name);
	_managers[id].set_phone(phone);
}

//add stock
void Emporium::add_stock(Server server, int type, int index, int quantity) {

	if(type == 0){
		_containers[index].set_stock(quantity);

		double wp = quantity * _containers[index].get_wholesale_price();
		_stocking_cost += wp;
		cash_register -= wp;
	}

	if(type == 1){
		_flavors[index].set_stock(quantity);

		double wp = quantity * _flavors[index].get_wholesale_price();
		_stocking_cost += wp;
		cash_register -= wp;
	}

	if(type == 2){
		_toppings[index].set_stock(quantity);

		double wp = quantity * _toppings[index].get_wholesale_price();
		_stocking_cost += wp;
		cash_register -= wp;
	}


	int sid = server.get_id();
	_servers[sid].set_total_filled(2);
		if (_servers[sid].pay())
		{
			cash_register -= server.get_hourly_salary();
			_servers[sid].set_total_pay(server.get_hourly_salary());
		}
	}

//auto restock item
void Emporium::auto_restock(Server server, int id){
		int Q = 25; //default auto stock amount

		double twp = _orders[id].get_total_wholesale_price();
		_stocking_cost += twp;

		int sid = server.get_id();

		if (_servers[sid].pay())
		{
			cash_register -= server.get_hourly_salary();
			_servers[sid].set_total_pay(server.get_hourly_salary());
		}

		vector<Serving> svg = _orders[id].get_servings();

		for (Serving s: svg) {
		Containr c = s.get_container();
			for(int i=0; i< _containers.size(); i++){
				if(_containers[i].get_name() == c.get_name()){
					if(_containers[i].get_stock() < 1){
						_containers[i].set_stock(Q);
					}
				}
			}

		vector<Flavor> fv = s.get_flavors();
		for (int i=0; i<_flavors.size(); i++)
		{
			for(int j=0; j<fv.size(); j++){
				if(_flavors[i].get_name() == fv[j].get_name()){
					if(_flavors[i].get_stock() < 1){
						_flavors[i].set_stock(Q);
					}
				}
			}
		}

		vector<Topping> tv = s.get_toppings();
		if(tv.size()!=0){
			for (int i=0; i<_toppings.size(); i++)
			{
				for(int j=0; j<tv.size(); j++){
					if(_toppings[i].get_name() == tv[j].get_name()){
						if(_toppings[i].get_stock() < 5){
							_toppings[i].set_stock(Q);
						}
					}
				}
			}

			}
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
