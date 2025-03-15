#include <iostream>

#include "coffee.h"

using namespace std;

//function defintions from coffee.h goes here

Coffee::Coffee() : name("Default coffee drink."), small_cost(0.50), medium_cost(1.00), large_cost(1.50) {
    //default constructor:
    
    //cout << "Coffee default constructor called" << endl; //for testing purposes
}



// void Coffee::set_name(string name) {
//     this->name = name;
// }

// void Coffee::set_small_cost(float small_cost) {
//     this->small_cost = small_cost;
// }

// void Coffee::set_medium_cost(float medium_cost) {
//     this->medium_cost = medium_cost;
// }

// void Coffee::set_large_cost(float large_cost) {
//     this->large_cost = large_cost;
// }


string Coffee::get_name() const {
    return this->name;
}

float Coffee::get_small_cost() const {
    return this->small_cost;
}

float Coffee::get_medium_cost() const {
    return this->medium_cost;
}

float Coffee::get_large_cost() const {
    return this->large_cost;
}


void Coffee::print_coffee() const {
    cout << name << endl;
    cout << "Small: $" << small_cost << endl;
    cout << "Medium: $" << medium_cost << endl;
    cout << "Large: $" << large_cost << endl;
}



//other functions

void Coffee::coffee_load_data(ifstream &file) {
    file >> name;
    file >> small_cost;
    file >> medium_cost;
    file >> large_cost;    
}

void Coffee::append_new_coffee(ofstream &menu_append) const {
    menu_append << this->name << " " << this->small_cost << " " << this->medium_cost << " " << this->large_cost << endl;
}

void Coffee::get_new_drink() {
	cout << "Enter the name of the new coffee drink (in 1 word): " << endl;
	cin >> name;
	cout << "Enter price of small size (8oz): " << endl;
    cin >> small_cost;
	cout << "Enter price of medium size (12oz): " << endl;
    cin >> medium_cost;
	cout << "Enter price of large size (16oz): " << endl;
    cin >> large_cost;
}


string Coffee::check_name(string name) {
    if (this->name == name) {
        return "found";
    }
    return "what";
}


void Coffee::print_coffee_searchprice(float budget) const {
    cout << name << endl;
    cout << "Small: $" << small_cost << endl;
    if (budget >= medium_cost) {
        cout << "Medium: $" << medium_cost << endl;
    }    
    if (budget >= large_cost) {
        cout << "Large: $" << large_cost << endl;
    }
}