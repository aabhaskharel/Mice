#include "items.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Items class constructor 
Items::Items(string name, string description, double wholesale_price, double retail_price, int stock, string image_path) : _name{name}, _description{description}, _wholesale_price{wholesale_price}, _retail_price{retail_price}, _stock{stock}, _image_path(image_path){}

//Flavor class constructor
Flavor::Flavor(string name, string description, double wholesale_price, double retail_price, int stock, string image_path) : Items(name, description, wholesale_price, retail_price, stock, image_path){}

//Topping class constructor
Topping::Topping(string name, string description, double wholesale_price, double retail_price, int stock, string image_path, string amount) : Items(name, description, wholesale_price, retail_price, stock, image_path),_amount{amount}{}

//Container class constructor
Containr::Containr(string name, string description, double wholesale_price, double retail_price, int stock, string image_path, int scoop) : Items(name, description, wholesale_price, retail_price, stock, image_path), _scoop{scoop}{}

//get item's name
string Items::get_name() const {return _name;}

//get item's description
string Items::get_description() const {return _description;}

//get item's wholesale cost
double Items::get_wholesale_price() const {return _wholesale_price;}

//get item's retail_price
double Items::get_retail_price() const {return _retail_price;}

//get item's stock
int Items::get_stock() const {return _stock;}

//restock
void Items::restock(int value){
	_stock = value;
}

//consume
bool Items::consume(int value){
	if(_stock==0){
		return false;
	}
	_stock-=value;
	return true;
}

//get image's path
string Items::get_image_path(){return _image_path;}

//get Topping's type
string Topping::get_amount() const {return _amount;}

//set topping amount
void Topping::_set_amount(string amount) {_amount = amount;}

//get Container's capacity
int Containr::get_scoop()const {return _scoop;}

//return's what kind of item
string Items::get_type() const {return "Item";}
string Containr::get_type() const {return "Container";}
string Flavor::get_type() const {return "Flavor";}
string Topping::get_type() const {return "Topping";}

std::ostream& operator<<(std::ostream& os, const Items& item) {
    os << std::setw(40) << item.get_type() + ": " + item.get_name() << " $" 
       << std::setprecision(2) << std::fixed << item.get_retail_price(); 
    return os;
}

