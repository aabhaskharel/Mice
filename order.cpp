#include "order.h"
#include <iostream>
#include <iomanip>
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

vector<Serving> Order::get_servings() { return _servings;}

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

//list a serving
string Order::list_serving(int index){
	int i; string out;
/*
	i = _servings.size();
	out = to_string(i);
*/
    out = "("+to_string(index)+")"+"\t"+"Container: "+(_servings[index].get_container()).get_name()+"\t"+"$"+to_string((_servings[index].get_container()).get_retail_price())+"\n";
	out+="\t\tFlavor: ";
	for(int i=0; i<(_servings[index].get_flavors()).size(); i++)
		{
		out+="\t"+(_servings[index].get_flavors())[i].get_name()+"\t"+"$"+to_string((_servings[index].get_flavors())[i].get_retail_price())+"\n";
		}
	out+="\t\tTopping: ";
	for(int i=0; i<(_servings[index].get_toppings()).size(); i++)
		{
		out+="\t"+(_servings[index].get_toppings())[i].get_name()+"\t"+"$"+to_string((_servings[index].get_toppings())[i].get_retail_price())+"\n";
		} 
	return out;
}

//list order
string Order::list_order(){

}

std::ostream& operator<<(std::ostream& os, Order& order) {
    os << "Your order:";
    for (Serving s : order.get_servings()) os << std::endl << s;
    os << std::endl << std::setw(45) << "----------------------------" 
    << std::endl << std::setw(40) << "Order Total: $ " << order.get_total_price();
    return os;
}


