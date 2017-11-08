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
	            	cash_register -= c.get_wholesale_price()*25;
	            }
	            
		        _containers[i].consume();
		        cash_register += c.get_retail_price();
		    }
		}
	}
	_orders[_orders.size()-1].fill();
	
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

}
string Emporium::get_customers_report() {

}
string Emporium::get_inventory_report() {

}
string Emporium::get_orders_report() {

}
string Emporium::get_pnl_report() {

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

