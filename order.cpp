#include "order.h"

using namespace std;

//constructor
Order::Order(int id, Server server, Customer customer): _id{id}, _server{server}, _customer{customer}, _state{"Unfilled"} {}

//add a serving to order
void Order::add_serving(Serving serving) {
    _servings.push_back(serving);
}

Server Order::get_server(){ return _server; }

Customer Order::get_customer(){ return _customer;}

vector<Serving> Order::get_servings() { return _servings;}

int Order::get_servings_size() {return _servings.size();}

//to get total price
double Order::get_total_retail_price(){
	double total;
	
	for(int i=0; i<_servings.size(); i++){
		total += _servings[i].get_total_retail_price();
	}	
	
	return total;
}

double Order::get_total_wholesale_price(){
	double total;
	
	for(int i=0; i<_servings.size(); i++){
		total += _servings[i].get_total_wholesale_price();
	}	
	
	return total;
}
	

//get id
int Order::get_id(){ return _id; }

//get state status
string Order::get_state(){ return _state; }

//check if it can be filled?
void Order::set_state(string state){
	_state = state;
}


//list a serving
string Order::list_serving(int index){
	/*string out;

    	out = "\n("+to_string(index+1)+")"+"\t"+"Container: "+(_servings[index].get_container()).get_name()+"\t"+"$"+to_string((_servings[index].get_container()).get_retail_price())+"\n";
	out+="\tFlavor:\n";
	for(int i=0; i<(_servings[index].get_flavors()).size(); i++)
		{
		out+="\t\t"+(_servings[index].get_flavors())[i].get_name()+"\t"+"\t$"+to_string((_servings[index].get_flavors())[i].get_retail_price())+"\n";
		}
	out+="\tTopping:\n";
	for(int i=0; i<(_servings[index].get_toppings()).size(); i++)
		{
		out+="\t\t"+(_servings[index].get_toppings())[i].get_name()+"\t"+"\t$"+to_string((_servings[index].get_toppings())[i].get_retail_price())+"\n";
		} 
	return out;*/
}

//list order
string Order::list_order(){

}

std::ostream& operator<<(std::ostream& os, Order& order) {
    /*os << "Your order:";
    for (Serving s : order.get_servings()) os << std::endl << s;
    os << std::endl << std::setw(50) << "----------------------------" 
    << std::endl << std::setw(40) << "Order Total: $ " << order.get_total_price() << endl;
    return os;*/
}


