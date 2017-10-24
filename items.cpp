#include <iostream>
#include <string>
#include "items.h"

using namespace std;

//Items class constructor 
Items::Items(string name, string description, int cost, int retail_price, int stock, string picture) : _name{name}, _description{description}, _cost{cost}, _retail_price{retail_price}, _stock{stock}, _picture{picture}{}

//Flavor class constructor
Flavor::Flavor(string name, string description, int cost, int retail_price, int stock, string picture) : _name{name}, _description{description}, _cost{cost}, _retail_price{retail_price}, _stock{stock}, _picture{picture}{}

//Topping class constructor
Topping::Topping(string name, string description, int cost, int retail_price, int stock, string picture, string type) : _name{name}, _description{description}, _cost{cost}, _retail_price{retail_price}, _stock{stock}, _picture{picture}, _type{type}{}

//Container class constructor
Container::Container(string name, string description, int cost, int retail_price, int stock, string picture, int scoop) : _name{name}, _description{description}, _cost{cost}, _retail_price{retail_price}, _stock{stock}, _picture{picture}, _scoop{scoop}{}
//get item's name
string Items::get_name(){return _name;}

//get item's description
string Items::get_description(){return _description;}

//get item's wholesale cost
int Items::get_cost(){return _cost;}

//get item's retail_price
int Items::get_retail_price(){return _retail_price;}

//get item's stock
int Items::get_stock(){return _stock;}

//get item's picture
string Items::get_picture(){return _picture;}

//get Topping's type
string Toppings::type(){return _type;}

//get Container's capacity
int Container::scoops(){return _scoop;}


