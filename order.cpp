#include "order.h"
#include <iomanip>
#include <stdexcept>
#include <iostream>

using namespace std;

//constructor
Order::Order(int id, Customer customer): _id{id}, _customer{customer}, _state{"Unfilled"} {}

void Order::save(std::ostream& ost) {
    ost << "#" << std::endl << "ORDER" << std::endl; // header
    ost << _id << std::endl;
    ost << _state << std::endl;
    _customer.save(ost);
    _server.save(ost);
    for (Serving s : _servings) s.save(ost);
    ost << "#" << std::endl << "END ORDER" << std::endl; // header
}

Order::Order(std::istream& ist) {
    std::string header1, header2;

    // The header must have been stripped from the incoming stream at this point
    ist >> _id; ist.ignore();
    ist >> _state; ist.ignore();
/*
    string state;
    std::getline(ist, header1);

    _state = (state == "Cancelled") ? "Cancelled" :
             (state == "Unfilled") ? "Unfilled" :
             (state == "Filled") ? "Filled" : "Paid";
*/
    std::getline(ist, header1);
    std::getline(ist, header2);
    if (header1 != "#") throw std::runtime_error("missing # during Order's Customer input");
    if (header2 != "CUSTOMER") throw std::runtime_error("missing CUSTOMER during Order input");
    _customer = Customer{ist};

    std::getline(ist, header1);
    std::getline(ist, header2);
    if (header1 != "#") throw std::runtime_error("missing # during Order's Server input");
    if (header2 != "SERVER") throw std::runtime_error("missing SERVER during Order input");
    _server = Server{ist};

    while (true) {
        std::getline(ist, header1); // header
        std::getline(ist, header2);
        if (header1 != "#") throw std::runtime_error("missing # during Order input");

        if (header2 == "END ORDER") break;  // footer
        else if (header2 == "SERVING") _servings.push_back(Serving{ist});
        else throw std::runtime_error("invalid serving in Order");
    }
}

//STATE MACHINE
void Order::process_event(string event, Server server){
    if (_state == "Unfilled") {
        if (event == "Fill") {
            _state = "Filled";
            _server = server;
        } else if (event == "Cancel") {
            _state = "Cancelled";
        } else {
            throw std::runtime_error("Invalid state transition in Unfilled");
        }
    } else if (_state == "FIlled") {
        if (event == "Pay") {
            _state = "Paid";
        } else {
            throw std::runtime_error("Invalid state transition in Filled");
        }
    } else if (_state == "Paid") {
        throw std::runtime_error("State transition attempted in Paid");
    } else if (_state == "Cancelled") {
        throw std::runtime_error("State transition attempted in Canceled");
    } else {
        throw std::runtime_error("Invalid state");
    }
}

void Order::set_server(Server server){
	_server = server;
}

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
	string out;

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
	return out;
}

//list order
string Order::list_order(){

}

std::ostream& operator<<(std::ostream& os, Order& order) {
/*
    os << "Your order:";
    for (Serving s : order.get_servings()) os << std::endl << s;
    os << std::endl << std::setw(50) << "----------------------------"
    << std::endl << std::setw(40) << "Order Total: $ " << order.get_total_retail_price() << endl;
    return os;
*/
}
