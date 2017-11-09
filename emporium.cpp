#include "emporium.h"
#include <iostream>

using namespace std;

//setters
void Emporium::add_new_container(Containr cont){
	_containers.push_back(cont);
}

void Emporium::add_new_flavor(Flavor flav) {
    _flavors.push_back(flav);
}

void Emporium::add_new_topping(Topping top){
    _toppings.push_back(top);
}

void Emporium::add_new_server(Server server){
    _servers.push_back(server);
}

void Emporium::add_new_customer(Customer customer){
    _customers.push_back(customer);
}

void Emporium::add_new_order(Order order) {

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
vector<Customer> Emporium::get_customers(){
	return _customers;
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
	string out = "Server details: \n";
	
	for(int i=0; i<_servers.size(); i++){
		out += "\tName: "+_servers[i].get_name()+"\tEmployee #: "+to_string(_servers[i].get_employee_number())+"\tTotal Order Filled: "+
		to_string(_servers[i].get_total_filled())+"\tHourly Salary: "+to_string(_servers[i].get_hourly_salary())+"\tTotal earned: "+to_string(_servers[i].get_total_earned())+"\n";
	}
	
	return out;
}

string Emporium::get_customers_report() {
	string out = "Customer details: \n";
	
	for(int i=0; i< _customers.size(); i++){
		out += "\tName: "+_customers[i].get_name()+"\t\tID: "+to_string(_customers[i].get_id())+"\tPhone: "+_customers[i].get_phone()+"\n";
	}
	
	return out;
}

string Emporium::get_inventory_report() {
	string out = "Inventory Report: \n\nContainers Available:\n";
	
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
	string out = "Orders Report:\n";
	
	for(int i=0; i<_orders.size(); i++){
		out += "\nOrder #"+to_string(_orders[i].get_id())+"  State:"+_orders[i].get_state()+"\n";
		out +="\tWholesale cost: "+_orders[i].get_wholesale_price()+"\n\tRetail cost: "+_orders[i].get_total_price()+"\n\n";
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
	
	for(int i=0; i<_orders.size(); i++){
		orders_wholesale += _orders[i].get_wholesale_price();
	}
	
	//orders
	out += "\t\tProfit\tExpenses\nOrders\t" + to_string(orders_retail-orders_wholesale)+ "\n";
		
	for(int i=0; i<_servers.size(); i++){
		total_paid += _servers[i].get_total_earned();
	}
	
	//server's salar
 	out += "\nSalaries\t\t" + to_string(total_paid) + "\n";
	
	//Items stock cost
	out += "Items\t\t" + to_string(_stocking_cost);
	
	//total and profit
	out += "\n-------------------------------------------------------------";
	out += "\nNet Total\t$ "+to_string(orders_retail-orders_wholesale)+"\t$ "+to_string(total_paid+_stocking_cost)+" = $ "+to_string(orders_retail-orders_wholesale-total_paid-_stocking_cost);
	
	return out;
}


void Emporium:: populate_emporium(){
    Containr cont("Waffle Cone", "A freshly baked waffle cone.", 0.49, 0.89, 0, "picture.png", 3);
    Containr cont2("Regular Cone", "Everyone's Favroite", 0.05, 0.15, 0, "picture.png", 1);

    _containers.push_back(cont2);
    _containers.push_back(cont);

    Flavor flav("Chocolate", "Rich Dark Chocolate", 1, 1.99, 0, "picture.png");
    Flavor flav2("Vanilla", "Very Smooth Vanilla", 1, 1.99, 0, "picture.png");

    _flavors.push_back(flav);
    _flavors.push_back(flav2);

    Topping top("Whipped Cream", "An Irrestible topping", 0.05, 0.25, 0, "picture.png", "light");
    Topping top2("Hot Fudge", "Hot & Fresh chocolate", 0.25, 0.75, 0, "picture.png", "Drenched");

    _toppings.push_back(top);
    _toppings.push_back(top2);
}

