#include <string>
#include "customer.h"

using namespace std;
//constructor
Customer::Customer(string name, int id, string phone): _name{name}, _id{id}, _phone{phone} {}

//create surving
void Customer::create_serving(Serving serving){
	servings.push_back(serving);
}

//get customer's name
string Customer::get_name(){
    return _name;
}

//get customer's id
int Customer::get_id() {
    return _id;
}

//get customer's phone
string Customer::get_phone() {
    return _phone;
}	
