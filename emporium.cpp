#include "emporium.h"

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

	for(Serving s : order.get_servings()) {
	
		for(Flavor f : s.get_flavors()) {
			if(!f.consume()){
				f.restock();
				cash_register -= f.get_wholesale_price()*25;
			}
			
			f.consume();
			cash_register += f.get_retail_price();
		}

		for(Topping t : s.get_toppings()) {
			if(!t.consume()){
				t.restock(); 
				cash_register -= t.get_wholesale_price()*25;
			}
			
			t.consume();
			cash_register += t.get_retail_price();
		}
		
		Containr c = s.get_container();
		if(!c.consume()){
	    	c.restock();
	    	cash_register -= s.get_wholesale_price()*25;
	    }
	    
		c.consume();
		cash_register += s.get_retail_price();
	}
	order.fill();

    _orders.push_back(order);
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

void Emporium:: populate_emporium(){
    Containr cont("Waffle Cone", "A freshly baked waffle cone.", 0.49, 0.89, 20, "picture.png", 3);
    Containr cont2("Regular Cone", "Everyone's Favroite", 0.05, 0.15, 20, "picture.png", 1);

    _containers.push_back(cont2);
    _containers.push_back(cont);

    Flavor flav("Chocolate", "Rich Dark Chocolate", 1, 1.99, 20, "picture.png");
    Flavor flav2("Vanilla", "Very Smooth Vanilla", 1, 1.99, 20, "picture.png");

    _flavors.push_back(flav);
    _flavors.push_back(flav2);

    Topping top("Whipped Cream", "An Irrestible topping", 0.05, 0.25, 20, "picture.png", "light");
    Topping top2("Hot Fudge", "Hot & Fresh chocolate", 0.25, 0.75, 20, "picture.png", "Drenched");

    _toppings.push_back(top);
    _toppings.push_back(top2);
}

