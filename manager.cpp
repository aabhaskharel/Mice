#include <string>
#include "manager.h"

using namespace std;
//constructor
Manager::Manager(string name, int id, string phone): _name{name}, _id{id}, _phone{phone} {}


//get manager's name
string Manager::get_name(){
    return _name;
}

//get manager's id
int Manager::get_id() {
    return _id;
}

//get manager's phone
string Manager::get_phone() {
    return _phone;
}	
