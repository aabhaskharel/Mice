#include "emporium.h"
#include <fstream>
#include <stdexcept>

using namespace std;

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

    for(Serving s : _orders[_orders.size()-1].get_servings()) {
		for(Flavor f : s.get_flavors()) {
		    for(int i=0; i<_flavors.size();i++){
		        if(f.get_name() == _flavors[i].get_name()){
		            if(!_flavors[i].consume(0)){
		            	_flavors[i].restock();
		            	_stocking_cost += f.get_wholesale_price()*25;
		            	cash_register -= _flavors[i].get_wholesale_price()*25;
		            }
		            
		            _flavors[i].consume();
		            cash_register += _flavors[i].get_retail_price();
		        }
		    }
	    }
		for(Topping t : s.get_toppings()) {
		    for(int i = 0; i < _toppings.size(); i++) {
		        if(t.get_name() == _toppings[i].get_name()) {
			        if(!_toppings[i].consume()){
				        _toppings[i].restock(); 
				        _stocking_cost += t.get_wholesale_price()*25;
				        cash_register -= t.get_wholesale_price()*25;
			        }
			
			        _toppings[i].consume();
			        cash_register += t.get_retail_price();
			    }
			}
		}
		
		Containr c = s.get_container();
		for(int i = 0; i < _containers.size(); i++) {
		    if(c.get_name() == _containers[i].get_name()){
		        if(!_containers[i].consume()){
	            	_containers[i].restock();
	            	_stocking_cost += c.get_wholesale_price()*25;
	            	cash_register -= c.get_wholesale_price()*25;
	            }
	            
		        _containers[i].consume();
		        cash_register += c.get_retail_price();
		    }
		}
	}
	_orders[_orders.size()-1].fill();
	(_orders[_orders.size()-1].get_server()).filled();
	cash_register -= (_orders[_orders.size()-1].get_server()).get_hourly_salary();
	
	cout << "Cash Balance : " << cash_register << endl;
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
//get order id
int Emporium::get_order_id() {
    return _orders.size();
}

//report calls
string Emporium::get_servers_report() {
	string out="\n";
	
	for(int i=0; i<_servers.size(); i++){
		out += "\tName: "+_servers[i].get_name()+"\tEmployee #: "+to_string(_servers[i].get_employee_number())+"\tTotal Order Filled: "+
		to_string(_servers[i].get_total_filled())+"\tHourly Salary: "+to_string(_servers[i].get_hourly_salary())+"\tTotal earned: "+to_string(_servers[i].get_total_earned())+"\n";
	}
	
	return out;
}

string Emporium::get_customers_report() {
	string out = "\n";
	
	for(int i=0; i< _customers.size(); i++){
		out += "\tName: "+_customers[i].get_name()+"\t\tID: "+to_string(_customers[i].get_id())+"\tPhone: "+_customers[i].get_phone()+"\n";
	}
	
	return out;
}

string Emporium::get_inventory_report() {
	string out = "\n\nContainers Available:\n";
	
	for(int i=0; i<_containers.size(); i++){
		out += "\tContainer name: "+_containers[i].get_name()+"\tStock Remaining: "+to_string(_containers[i].get_stock())+"\n";
	}
	
	out += "\n\nFlavors Available:\n";
	
	for(int i=0; i<_flavors.size(); i++){
		out += "\tFlavor name: "+_flavors[i].get_name()+"\tStock Remaining: "+to_string(_flavors[i].get_stock())+"\n";
	}
	
	out += "\n\nToppingsAvailable:\n";
	
	for(int i=0; i<_toppings.size(); i++){
		out += "\tTopping name: "+_toppings[i].get_name()+"\tStock Remainig: "+to_string(_toppings[i].get_stock())+"\n";
	}
	
	return out;
}

string Emporium::get_orders_report() {
	string out = "\n";
	
	for(int i=0; i<_orders.size(); i++){
		out += "\nOrder #"+to_string(_orders[i].get_id())+"  State:"+_orders[i].get_state()+"\n";
		out +="\tWholesale cost: "+to_string(_orders[i].get_wholesale_price())+"\n\tRetail cost: "+to_string(_orders[i].get_total_price())+"\n\n";
	}
	
	return out;
}

string Emporium::get_pnl_report() {
	double orders_retail=0;
	double orders_wholesale=0;
	double total_paid=0;
	string out = "Profit & Loss Statement:\n\n";
	
	for(int i=0; i<_orders.size(); i++){
		orders_retail+=_orders[i].get_total_price();
	}
	
	
	//orders
	out += "Profit\tExpenses\nOrders\t" + to_string(orders_retail)+ "\n";
		
	for(int i=0; i<_servers.size(); i++){
		total_paid += _servers[i].get_total_earned();
	}
	
	//server's salar
 	out += "\nSalaries\t\t" + to_string(total_paid) + "\n";
	
	//Items stock cost
	out += "Items\t\t" + to_string(_stocking_cost);
	
	//total and profit
	out += "\n-------------------------------------------------------------";
	out += "\nNet Total\t$ "+to_string(orders_retail)+"\t$ "+to_string(total_paid+_stocking_cost)+" = $ "+to_string(orders_retail-total_paid-_stocking_cost);
	
	return out;
}

//change server's salary
void Emporium::change_salary(int server_id, double salary){
	_servers[server_id].change_salary(salary);
}

void Emproium::retire_item(Items item, int id){
	string type = item.get_type();
	if (type == "Container")
	{	_retired_containers.pushback(_containers[id]);
		_containers.erase(_containers.begin()+id);
	}
	else if (type == "Flavor")
	{
		_retired_flavors.pushback(_flavors[id]);
		_flavors.erase(_flavors.begin()+id);
	}
	else
	{
		_retired_toppings.pushback(_toppings[id]);
		_toppings.erase(_toppings.begin()+id);
	}
}

void Emproium::retire_person(Person person, int id){
	int type = person.get_type();
	if (type == 2)
	{
		_retired_managers.pushback(_managers[id]);
		_managers.erase(_managers.begin()+id);
	}
	else
	{
		_retired_servers.pushback(_servers[id]);
		_servers.erase(_servers.begin()+id);
	}
	
}

void Emproium::restore_item(Items item, int id){
	string type = item.get_type();
	if (type == "Container")
	{	_containers.pushback(_retired_containers[id]);
		_retired_containers.erase(_retired_containers.begin()+id);
	}
	else if (type == "Flavor")
	{
		_flavors.pushback(_retired_flavors[id]);
		_retired_flavors.erase(_retired_flavors.begin()+id);
	}
	else
	{
		_toppings.pushback(_retired_toppings[id]);
		_retired_toppings.erase(_retired_toppings.begin()+id);
	}
}

void Emproium::restore_person(Person person, int id){
	int type = person.get_type();
	if (type == 2)
	{
		_managers.pushback(_retired_managers[id]);
		_retired_managers.erase(_retired_managers.begin()+id);
	}
	else
	{
		_servers.pushback(_retired_servers[id]);
		_retired_servers.erase(_retired_servers.begin()+id);
	}
	
}

//write to a file
void Emporium::write(string filename){
	
	ofstream ofs {filename};
	if(!ofs) throw runtime_error("can't open output file " + filename);
	
	//writing containers data
	for(int i=0; i<_containers.size(); i++){
		ofs << _containers[i] << endl; 
	}
	
	//writing flavors data
	for(int i=0; i<_flavors.size(); i++){
		ofs << _flavors[i] << endl;
	}
	
	//writing toppings data
	for(int i=0; i<_toppings.size(); i++){
		ofs << _toppings[i] << endl;
	}
	
	//writing servings data
	for(int i=0; i<_orders.size(); i++){
		for(int j=0; j<(_orders[i].get_servings_size()); j++){
			ofs << (_orders[i].get_servings())[j] << endl;
		}
	}

}

//edit container
void Emporium::edit_container(int id, Containr container){
	int temp = _containers[id].get_stock();
	_containers[id] = container;
	_containers[id].set_stock(temp);
}

//edit flavor
void Emporium::edit_flavor(int id, Flavor flavor){
	int temp = _flavors[id].get_stock();
	_flavors[id] = flavor;
	_flavors[id].set_stock(temp);
}

//edit topping
void Emporium::edit_topping(int id, Topping topping){
	int temp = _toppings[id].get_stock();
	_toppings[id] = topping;
	_toppings[id].set_stock(temp);
}


void Emporium:: populate_emporium(){
    Containr cont("Cup", "A freshly baked waffle cone.", 0.03, 0, 0, "picture.png", 3);
    Containr cont2("Regular Cone", "Everyone's Favroite", 0.05, 0.15, 0, "picture.png", 1);

    _containers.push_back(cont2);
    _containers.push_back(cont);

    Flavor flav("Chocolate", "Rich Dark Chocolate", 1, 1.99, 0, "f_chocolate.png");
    Flavor flav2("Vanilla", "Very Smooth Vanilla", 1, 1.99, 0, "f_vanilla.png");
    Flavor flav3("Strawberry", "Refreshing Strawberry Flavor", 1.05, 2.09, 0, "f_strawberry.png");

    _flavors.push_back(flav);
    _flavors.push_back(flav2);
    _flavors.push_back(flav3);

    Topping top("Whipped Cream", "An Irrestible topping", 0.05, 0.25, 0, "picture.png", "light");
    Topping top2("Hot Fudge", "Hot & Fresh chocolate", 0.25, 0.75, 0, "picture.png", "light");
    Topping top3("Cherry", "Red and bright delight", 0.01, 0.1, 0, "t_cherry.png", "light");

    _toppings.push_back(top);
    _toppings.push_back(top2);
    _toppings.push_back(top3);
    
    _servers.push_back(Server{"Pujan B.", 0, 8.5});
    _servers.push_back(Server{"Ankit R.", 1, 8.5});
    
    _customers.push_back(Customer{"Jeevan G.", 0, "817-928-9301"});
    _customers.push_back(Customer{"Sumit N.", 1, "817-213-4123"});
    
    _managers.push_back(Manager{"Aabhas K.", 0, "817-391-9304"});
    
}

