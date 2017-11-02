#include "manager.h"

using std::vector;

/*
vector<Container> containers;
vector<Flavor> flavors;
vector<Topping> toppings;
vector<Server> servers;
*/

//create new server
void Manager::create_server(Server server, Emporium emp) {
		//servers.push_back(server);
		emp.set_server(server);
}
	
// to add a new container
void Manager::add_new_container(Emporium emp) {
	vector<string> res = Dialogs::form("Add a new container", 1);
	if (res.size() != 7) {
	}
	else {
		Container cont(res[0], res[1], stod(res[2]), stod(res[3]), stoi(res[4]), res[5], stoi(res[6]));
		//containers.push_back(cont);
		emp.set_container(cont);
		//Dialogs::message(list_all_containers(),"Title");
	}
}

// to list a single container
/*string Manager::list_container(int i){
	string out; --i;
	out = "("+to_string(i+1)+") "+containers[i].get_name()+"\t\t"
		+containers[i].get_description()+"\t\t"
		+to_string(containers[i].get_cost())+"\t\t"
		+to_string(containers[i].get_retail_price())+"\t\t"
		+to_string(containers[i].get_stock())+"    "
		+to_string(containers[i].scoops())+"\n";
	return out;}

	// to list all containers
	string Manager::list_all_containers(){
		string out;
		for(int i=0; i <containers.size(); i++){
			out += list_container(i+1);
		}
		return out;
	}

// to print number of containers available 
int Manager::number_of_containers(){
	return containers.size();}*/


	// to add a new flavor
void Manager::add_new_flavor(Emporium emp){
	vector<string> res = Dialogs::form("Add a new flavor",0);
	if (res.size() != 6) {}
	else {
		Flavor flav(res[0], res[1], stod(res[2]), stod(res[3]), stoi(res[4]), res[5]);
		//flavors.push_back(flav);
		emp.set_flavor(flav);
		//Dialogs::message(list_all_flavors(),"Title");
	}
}

// to list a single flavor
/*string Manager::list_flavor(int i){
	string out; --i;
	out = "("+to_string(i+1)+")"+flavors[i].get_name()+"\t\t"
		+flavors[i].get_description()+"\t\t"
		+to_string(flavors[i].get_cost())+"\t\t"
		+to_string(flavors[i].get_retail_price())+"\t\t"
		+to_string(flavors[i].get_stock())+"\n";
	return out;}

	// to list all flavors
	string Manager::list_all_flavors(){
		string out;
		for(int i=0; i <flavors.size(); i++){
			out += list_flavor(i+1);
		}
		return out;
	}

// to print number of flavors available 
int Manager::number_of_flavors(){
	return flavors.size();}*/



	// to add a new topping
void Manager::add_new_topping(Emporium emp){
	vector<string> res = Dialogs::form("Add a new topping", 2);
	if (res.size() != 7) {}
	else{
		Topping top(res[0], res[1], stod(res[2]), stod(res[3]), stoi(res[4]), res[5], res[6]);
		//toppings.push_back(top);
		emp.set_topping(top);
		//Dialogs::message(list_all_toppings(),"Title");
	}
}

// to list a single topping
/*string Manager::list_topping(int i){
	string out; --i;
	out = "("+to_string(i+1)+")"+toppings[i].get_name()+"\t\t"
		+toppings[i].get_description()+"\t\t"
		+to_string(toppings[i].get_cost())+"\t\t"
		+to_string(toppings[i].get_retail_price())+"\t\t"
		+to_string(toppings[i].get_stock())+"\n";
	return out;
}

// to list all toppings
string Manager::list_all_toppings(){
	string out;
	for(int i=0; i <toppings.size(); i++){
		out += list_topping(i+1);
	}
	return out;
}

// to print number of ctoppings available 
int Manager::number_of_toppings(){
	return toppings.size();}
*/

void Manager:: populate_mgmt(){
    Container cont("Waffle Cone", "A freshly baked waffle cone.", 0.49, 0.89, 20, "picture.png", 3);
    Container cont2("Regular Cone", "Everyone's Favroite", 0.05, 0.15, 20, "picture.png", 1);

    emp.set_container(cont2);
    emp.set_container(cont);

    Flavor flav("Chocolate", "Rich Dark Chocolate", 1, 1.99, 20, "picture.png");
    Flavor flav2("Vanilla", "Very Smooth Vanilla", 1, 1.99, 20, "picture.png");

    emp.set_flavor(flav);
    emp.set_flavor(flav2);

    Topping top("Whipped Cream", "An Irrestible topping", 0.05, 0.25, 20, "picture.png", "light");
    Topping top2("Hot Fudge", "Hot & Fresh chocolate", 0.25, 0.75, 20, "picture.png", "Drenched");

    emp.set_topping(top);
    emp.set_topping(top2);
}

/*
vector<Container> Manager::get_containers() {
    return containers;
}
vector<Topping> Manager::get_toppings() {
    return toppings;
}
vector<Flavor> Manager::get_flavors() {
    return flavors;
}
vector<Server> Manager::get_servers() {
    return servers;
}
*/



