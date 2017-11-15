#include "items.h"

using namespace std;

//Items class constructor 
Items::Items(string name, string description, double wholesale_price, double retail_price, string image_path) : _name{name}, _description{description}, _wholesale_price{wholesale_price}, _retail_price{retail_price}, _image_path(image_path), _stock{0} {}

//Flavor class constructor
Flavor::Flavor(string name, string description, double wholesale_price, double retail_price, string image_path) : Items(name, description, wholesale_price, retail_price, image_path){}

//Topping class constructor
Topping::Topping(string name, string description, double wholesale_price, double retail_price, string image_path) : Items(name, description, wholesale_price, retail_price, image_path){}

//Container class constructor
Containr::Containr(string name, string description, double wholesale_price, double retail_price, string image_path, int scoop) : Items(name, description, wholesale_price, retail_price, image_path), _scoop{scoop}{}

//get item's name
string Items::get_name(){return _name;}

//get item's description
string Items::get_description(){return _description;}

//get item's wholesale cost
double Items::get_wholesale_price(){return _wholesale_price;}

//get item's retail_price
double Items::get_retail_price(){return _retail_price;}

//get item's stock
int Items::get_stock(){return _stock;}

string Items::get_image_path(){return _image_path;}

//get Topping's type
int Topping::get_kind(){return _kind;}

int Topping::set_kind(int kind) { _kind = kind;}

//get Container's capacity
int Containr::get_scoop(){return _scoop;}

int Items::restock(int quantity) {_stock += quantity;}

int Items::consume(int quantity) {_stock -= quantity;}

//return's what kind of item
string Items::get_type() {return "Item";}
string Containr::get_type() {return "Container";}
string Flavor::get_type() {return "Flavor";}
string Topping::get_type() {return "Topping";}

std::ostream& operator<<(std::ostream& os, const Items& item) {
    os << std::setw(40) << item.get_type() + ": " + item.get_name() << " $" 
       << std::setprecision(2) << std::fixed << item.get_retail_price(); 
    return os;
}
