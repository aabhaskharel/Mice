#include "order.h"
using namespace std;

//constructor
Order::Order(int id): _id{id} {}

//add a serving to order
void Order::add_serving(Serving serving) {
    _servings.push_back(serving);
}

//add a server who took the order
//void Order::add_server(Server server) {_server=server;}

//add a customer who took the order
//void Order::add_customer(Customer customer) {_customer=customer;}

//to get total price
double Order::get_total_price(){
	double total;
	
	for(int i=0; i<_servings.size(); i++){
		total += _servings[i].total_retail_price();
	}	
	
	return total;
}

//check if it can be filled?
void Order::fill(){
	_state = "Filled";
}

//pay status
void Order::pay() {

}

//cancle order
void Order::cancel(){
	_state = "Cancel";
}


