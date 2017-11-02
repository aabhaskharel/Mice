#include <string>
#include "customer.h"

using namespace std;

Customer::Customer(string name, int id, string phone): _name{name}, _id{id}, _phone{phone} {}

string Customer::get_name(){
    return _name;
}

int Customer::get_id() {
    return _id;
}

string Customer::get_phone() {
    return _phone;
}	
