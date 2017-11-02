#include "order.h"
using namespace std;

//constructor
Order::Order(int id, vector<Serving> servings, Server server, Customer customer): _id{id}, _servings{servings}, _server{server}, _customer{customer} {}

//to get total price
double Order::get_total_price(){
	double total;
	
	for(int i=0; i<_servings.size(); i++){
		total += _servings[i].total_retail_price();
	}	
	
	return total;
}

//pay status


//who filled
void Order::fill(){
	_state = "Filled";
}

//cancle order
void Order::cancel(){
	_state = "Cancel";
}


