#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "serving.h"

using namespace std;

//constructor
Serving::Serving(Containr container): _container{container} {}
Serving::Serving(std::istream& ist) {
    // The header must have been stripped from the incoming stream at this point
    std::string header1, header2;
    while (true) {
        std::getline(ist, header1); // header
        std::getline(ist, header2);
        if (header1 != "#") throw std::runtime_error("missing # during input");
        if (header2 == "END SERVING") break;  // footer
        else if (header2 == "CONTAINER") _container = Containr{ist};
        else if (header2 == "FLAVOR") _flavors.push_back(Flavor{ist});
        else if (header2 == "TOPPING") _toppings.push_back(Topping{ist});
        else throw std::runtime_error("invalid item type in Serving");
    }
}

void Serving::save(std::ostream& ost) {
    ost << "#" << std::endl << "SERVING" << std::endl; // header
    _container.save(ost);
    for (Flavor& f : _flavors) f.save(ost);
    for (Topping& t : _toppings) t.save(ost);
    ost << "#" << std::endl << "END SERVING" << std::endl; // footer
}

//return container
Containr Serving::get_container() {return _container;}

//return flavors
vector<Flavor> Serving::get_flavors() {return _flavors;}

//return toppings
vector<Topping> Serving::get_toppings() {return _toppings;}

//set toppings
void Serving::set_topping(Topping topping) {
    _toppings.push_back(topping);
}

//set flavors
void Serving::set_flavor(Flavor flavor) {
    _flavors.push_back(flavor);
}

//total retail price
double Serving::get_total_retail_price() {
		double total=0; 
		total += _container.get_retail_price();

		for(int i=0; i<_flavors.size(); i++){
				total+=_flavors[i].get_retail_price();
		}

		for(int i=0; i<_toppings.size(); i++){
			total+=(_toppings[i].get_retail_price())*_toppings[i].get_amount();
		}

	return total;
}

//list serving
string Serving::get_report(){
	string out;

    	out = "\n("+to_string(1.)+")"+"\t"+"Container: "+(get_container()).get_name()+"\t"+"$"+to_string((get_container()).get_retail_price())+"\n";
	out+="\tFlavor:\n";
	for(int i=0; i<(get_flavors()).size(); i++)
		{
		out+="\t\t"+(get_flavors())[i].get_name()+"\t"+"\t$"+to_string((get_flavors())[i].get_retail_price())+"\n";
		}
	out+="\tTopping:\n";
	for(int i=0; i<(get_toppings()).size(); i++)
		{
		int amt = (get_toppings())[i].get_amount();
		out+="\t\t"+(get_toppings())[i].get_name()+"\t"+"\t$"+to_string(((get_toppings())[i].get_retail_price())*amt)+"\n";
		}
	return out;
}

double Serving::get_total_wholesale_price() {
		double total=0; 
		total += _container.get_wholesale_price();

		for(int i=0; i<_flavors.size(); i++){
				total+=_flavors[i].get_wholesale_price();
		}

		for(int i=0; i<_toppings.size(); i++){
			total+=(_toppings[i].get_wholesale_price())*_toppings[i].get_amount();
		}

	return total;
}



std::ostream& operator<<(std::ostream& os, Serving& serving) {
/*
    os << serving.get_container();
    for (Flavor s : serving.get_flavors()) os << std::endl << s;
    for (Topping t : serving.get_toppings()) os << std::endl << t;
    os << std::endl << std::setw(50) << "----------------------------"
    << std::endl << std::setw(40) << "Serving Total: $ " << serving.get_total_retail_price() << endl;
    return os;
*/
}
