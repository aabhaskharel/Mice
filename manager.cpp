#include <iostream>
#include <string>
#include "manager.h"
#include "container.h"
#include "flavor.h"
#include "topping.h"

using namespace std;


// to add a new container
void Manager::add_new_container(Container cont){
	containers.push_back(cont);}

// to list all containers
void Manager::list_all_containers(){
	cout << "\n\n\n\n\n";
		for(int i=0; i <containers.size(); i++){
		cout << "("<<i<<")"<< containers[i].name();}

// to print number of containers available 
int Manager::number_of_containers(){
		return containers.size();}


// to add a new flavor
void Manager::add_new_flavor(Flavor flav){
	flavors.push_back(flav);}

// to list all flavors
void Manager::list_all_flavors(){
	cout << "\n\n\n\n\n";
		for(int i=0; i < flavors.size(); i++){
		cout << "("<<i<<")"<< flavors[i].name();}

// to print number of flavors available 
int Manager::number_of_flavors(){
		return flavors.size();}



// to add a new topping
void Manager::add_new_topping(String topping){
	toppings.push_back(top);}

// to list all toppings
void Manager::list_all_toppings(){
	cout << "\n\n\n\n\n";
		for(int i=0; i < toppings.size(); i++){
		cout << "("<<i<<")"<< toppings[i].name();}

// to print number of ctoppings available 
int Manager::number_of_toppings(){
		return toppings.size();}






	
