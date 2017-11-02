#include "manager.h"

using std::vector;

vector<Container> containers;
vector<Flavor> flavors;
vector<Topping> toppings;
vector<Server> servers;

//create new server
void Manager::create_server(Server server) {
		servers.push_back(server);
}
	
// to add a new container
void Manager::add_new_container() {
	vector<string> res = Dialogs::form("Add a new container", 1);
	if (res.size() != 7) {
	}
	else {
		Container cont(res[0], res[1], stod(res[2]), stod(res[3]), stoi(res[4]), res[5], stoi(res[6]));
		containers.push_back(cont);
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
void Manager::add_new_flavor(){
	vector<string> res = Dialogs::form("Add a new flavor",0);
	if (res.size() != 6) {}
	else {
		Flavor flav(res[0], res[1], stod(res[2]), stod(res[3]), stoi(res[4]), res[5]);
		flavors.push_back(flav);
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
void Manager::add_new_topping(){
	vector<string> res = Dialogs::form("Add a new topping", 2);
	if (res.size() != 7) {}
	else{
		Topping top(res[0], res[1], stod(res[2]), stod(res[3]), stoi(res[4]), res[5], res[6]);
		toppings.push_back(top);
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
	
	}










