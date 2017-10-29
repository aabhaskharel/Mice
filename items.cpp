#include "items.h"

using namespace std;

//Items class constructor 
Items::Items(string name, string description, double wholesale_price, double retail_price, int stock, string image_path) : _name{name}, _description{description}, _wholesale_price{wholesale_price}, _retail_price{retail_price}, _stock{stock}, _image_path(image_path){}

//Flavor class constructor
Flavor::Flavor(string name, string description, double wholesale_price, double retail_price, int stock, string image_path) : Items(name, description, wholesale_price, retail_price, stock, image_path){}

//Topping class constructor
Topping::Topping(string name, string description, double wholesale_price, double retail_price, int stock, string image_path, string type) : Items(name, description, wholesale_price, retail_price, stock, image_path),_type{type}{}

//Container class constructor
Container::Container(string name, string description, double wholesale_price, double retail_price, int stock, string image_path, int scoop) : Items(name, description, wholesale_price, retail_price, stock, image_path), _scoop{scoop}{}

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
string Topping::get_type(){return _type;}

//get Container's capacity
int Container::get_scoop(){return _scoop;}


