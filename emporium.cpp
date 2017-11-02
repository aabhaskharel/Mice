#include "emporium.h"

using namespace std;

//constructor
/*Emporium::Emporium(vector<Container> containers, vector<Flavor> flavors, vector<Topping> toppings, vector<Server> servers): _flavors{flavors}, _containers{containers}, _toppings{toppings}, _servers{servers} {}
*/
void Emporium::set_container(Container cont){
    _containers.push_back(cont);
}
void Emporium::set_topping(Topping top){
    _toppings.push_back(top);
}
void Emporium::set_flavor(Flavor flav){
    _flavors.push_back(flav);
}
void Emporium::set_server(Server serv){
    _servers.push.back(serv)
}

//professional programmer
vector<Container> Emporium::get_containers() {
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
