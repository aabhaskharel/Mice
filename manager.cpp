#include <iostream>
#include <string>
#include <vector>
#include "manager.h"
#include "items.h"

using namespace std;


// to add a new container
void Manager::add_new_container(Container cont){
	containers.push_back(cont);}
	
	// to list a single container
		string Manager::list_container(int i){
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
					return containers.size();}


// to add a new flavor
void Manager::add_new_flavor(Flavor flav){
	flavors.push_back(flav);}
		
	// to list a single flavor
		string Manager::list_flavor(int i){
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
					return flavors.size();}



// to add a new topping
void Manager::add_new_topping(Topping top){
	toppings.push_back(top);}
	
	// to list a single topping
		string Manager::list_topping(int i){
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









