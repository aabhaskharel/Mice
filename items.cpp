#include <iostream>
#include <string>
#include "items.h"

using namespace std;

//Items class constructor 
Items::Items(string name, string description, double cost, double retail_price, int stock) : _name{name}, _description{description}, _cost{cost}, _retail_price{retail_price}, _stock{stock}{}

//Flavor class constructor
Flavor::Flavor(string name, string description, double cost, double retail_price, int stock) : Items(name, description, cost, retail_price, stock){}

//Topping class constructor
Topping::Topping(string name, string description, double cost, double retail_price, int stock, string type) : Items(name, description, cost, retail_price, stock),_type{type}{}

//Container class constructor
Container::Container(string name, string description, double cost, double retail_price, int stock, int scoop) : Items(name, description, cost, retail_price, stock), _scoop{scoop}{}

//get item's name
string Items::get_name(){return _name;}

//get item's description
string Items::get_description(){return _description;}

//get item's wholesale cost
double Items::get_cost(){return _cost;}

//get item's retail_price
double Items::get_retail_price(){return _retail_price;}

//get item's stock
int Items::get_stock(){return _stock;}

//get Topping's type
string Topping::type(){return _type;}

//get Container's capacity
int Container::scoops(){return _scoop;}


