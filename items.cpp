#include "items.h"
#include <iomanip>
#include <stdexcept>

using namespace std;

//Items class constructor
Items::Items(string name, string description, double wholesale_price, double retail_price, string image_path) : _name{name}, _description{description}, _wholesale_price{wholesale_price}, _retail_price{retail_price}, _image_path(image_path), _stock{0} {}
Items::Items() : _name{""}, _description{""}, _wholesale_price{0}, _retail_price{0}, _image_path{""}, _stock{0} { }

//Flavor class constructor
Flavor::Flavor(string name, string description, double wholesale_price, double retail_price, string image_path) : Items(name, description, wholesale_price, retail_price, image_path){}
Flavor::Flavor(std::istream& ist) {
    // The header must have been stripped from the incoming stream at this point
    getline(ist, _name);
    ist >> _wholesale_price; ist.ignore();
    ist >> _retail_price; ist.ignore();
    ist >> _stock; ist.ignore();
    ist >> _image_path; ist.ignore();
    getline(ist, _description);
}

void Flavor::save(std::ostream& ost) {
    ost << "#" << std::endl << "FLAVOR" << std::endl; // header
    ost << _name << std::endl;
    ost << _wholesale_price << std::endl;
    ost << _retail_price << std::endl;
    ost << _stock << std::endl;
    ost << _image_path << std::endl;
    ost << _description << std::endl;
}

//Topping class constructor
Topping::Topping(string name, string description, double wholesale_price, double retail_price, string image_path) : Items(name, description, wholesale_price, retail_price, image_path) {}
Topping::Topping(std::istream& ist) {
    // The header must have been stripped from the incoming stream at this point
    getline(ist, _name);
    ist >> _wholesale_price; ist.ignore();
    ist >> _retail_price; ist.ignore();
    ist >> _stock; ist.ignore();
    ist >> _amount; ist.ignore();
    ist >> _image_path; ist.ignore();
    getline(ist, _description);
}

void Topping::save(std::ostream& ost) {
    ost << "#" << std::endl << "TOPPING" << std::endl; // header
    ost << _name << std::endl;
    ost << _wholesale_price << std::endl;
    ost << _retail_price << std::endl;
    ost << _stock << std::endl;
    ost << _amount << std::endl;
    ost << _image_path << std::endl;
    ost << _description << std::endl;
}

//Container class constructor
Containr::Containr(string name, string description, double wholesale_price, double retail_price, string image_path, int scoop) : Items(name, description, wholesale_price, retail_price, image_path), _scoop{scoop}{}
Containr::Containr(std::istream& ist) {
    // The header must have been stripped from the incoming stream at this point
    getline(ist, _name);
    ist >> _wholesale_price; ist.ignore();
    ist >> _retail_price; ist.ignore();
    ist >> _stock; ist.ignore();
    ist >> _scoop; ist.ignore();
    ist >> _image_path; ist.ignore();
    getline(ist, _description);
}

void Containr::save(std::ostream& ost) {
    ost << "#" << std::endl << "CONTAINER" << std::endl; // header
    ost << _name << std::endl;
    ost << _wholesale_price << std::endl;
    ost << _retail_price << std::endl;
    ost << _stock << std::endl;
    ost << _scoop << std::endl;
    ost << _image_path << std::endl;
    ost << _description << std::endl;
}

//get item's name
string Items::get_name(){return _name;}

//get item's description
string Items::get_description(){return _description;}

//get item's wholesale cost
double Items::get_wholesale_price(){return _wholesale_price;}

//get item's retail_price
double Items::get_retail_price(){return _retail_price;}

//set item's retail price
void Items::set_retail_price(double price){_retail_price = price;}
//get item's stock
int Items::get_stock(){return _stock;}

string Items::get_image_path(){return _image_path;}

//get Container's capacity
int Containr::get_scoop(){return _scoop;}

int Topping::get_amount(){return _amount;};
void Topping::set_amount(int amount) {_amount = amount;}

void Items::set_stock(int quantity) {_stock += quantity;}

//return's what kind of item
string Items::get_type() {return "Item";}
string Containr::get_type() {return "Container";}
string Flavor::get_type() {return "Flavor";}
string Topping::get_type() {return "Topping";}

std::ostream& operator<<(std::ostream& os, Items& item) {
/*
    os << std::setw(40) << item.get_type() + ": " + item.get_name() << " $"
       << std::setprecision(2) << std::fixed << item.get_retail_price();
    return os;
*/
}
