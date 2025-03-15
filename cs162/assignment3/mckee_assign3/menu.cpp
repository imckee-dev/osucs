/*********************************************************************
** Program Filename: menu.cpp
** Author: Ian McKee and whoever made the assignment (Roger/Alex)
** Date: 11/12/23
** Description: Defines Menu class's functions. Includes the big three because of its dynamic array.
** Input: n/a
** Output: a Menu class with a number of coffees and an Coffee array with that length.
*********************************************************************/

#include "menu.h"
#include <iostream>

using namespace std;

//function defintions from menu.h goes here


void Menu::search_coffee_by_name(string name) const {
	Coffee found; 
	//search coffee with a specific name 
	//return the coffee if found 
	//Your code goes here: 
	for (int i = 0; i < num_coffee; i++) {
		if (coffee_arr[i].check_name(name) == "found") {
			cout << "This is such an awesome tasty drink from our menu: " << endl;
			coffee_arr[i].print_coffee();
			return;
		}
	}
	cout << "No coffee with that name was found I am so sorry" << endl;

}


void Menu::search_coffee_by_price(float budget, Menu m) {

	//search coffee with a specific budget 
	//return all coffee that is under the budget
	//Hint: Since a Menu object contains an array of coffee
	//      You may return a Menu object that contains all valid coffees
	//Your code goes here: 
	num_coffee = 0;
	for (int i = 0; i < m.num_coffee; i++) {
		if (m.coffee_arr[i].get_small_cost() <= budget) {
			add_to_menu(m.coffee_arr[i]);
		}
	}
	if (num_coffee == 0) {
		cout << "No coffees matched that budget of $" << budget << " I am so sorry." << endl;
		return;
	}
	print_coffees_searchprice(budget);

}

void Menu::add_to_menu(const Coffee& new_coffee) {
	Coffee* new_array = new Coffee[num_coffee + 1]; //make the new dynamic with +1 length
	for (int i = 0; i < num_coffee; i++) { //for original length:
		new_array[i] = coffee_arr[i]; //add to new array like normal
	}
	delete [] coffee_arr; //delete old (no longer needed)
	coffee_arr = new_array; //old pointer goes to new pointer
	num_coffee++; //length can finally be +1
	coffee_arr[num_coffee - 1] = new_coffee; //at end of array (-1 for num items -1), add the new desired coffee passed in
}


void Menu::remove_from_menu(int index_of_coffee_on_menu){
	//remove a coffee object from the Menu
	//Your code goes here: 
	Coffee* new_array = new Coffee[num_coffee - 1]; //make the new dynamic with -1 length
	for (int i = 0; i < index_of_coffee_on_menu; i++) { //for length up to the index:
		new_array[i] = coffee_arr[i]; //add to new array like normal
	}
	for (int i = index_of_coffee_on_menu; i < num_coffee; i++) { //for length from index to the normal length:
		new_array[i - 1] = coffee_arr[i]; //add to new array one less position, of current coffee
	}

	delete [] coffee_arr; //delete old (no longer needed)
	coffee_arr = new_array; //old pointer goes to new pointer
	num_coffee--; //length can finally be -1

	//now we can try to remove this from file:
	edit_menu_file();
	return;
} 

//lab6:

Menu::Menu () {
	this->num_coffee = 0;
	this->coffee_arr = nullptr;
}
    
Menu::Menu (int size) {
	this->num_coffee = size;
	this->coffee_arr = new Coffee[size];
}

Menu::~Menu() {
	if (this->coffee_arr != NULL) {
		delete [] this->coffee_arr;
		this->coffee_arr = NULL;
	}
}

Menu& Menu::operator=(const Menu& m) {
	if (this == &m) {
		return *this;
	}

	if (this->coffee_arr != NULL) {
		delete [] this->coffee_arr;
	}

	this->num_coffee = m.num_coffee;
	this->coffee_arr = new Coffee[this->num_coffee];
	for (int i = 0; i < this->num_coffee; ++i) {
		this->coffee_arr[i] = m.coffee_arr[i];
	}
	return *this;
}

Menu::Menu(const Menu& m) {
	this->num_coffee = m.num_coffee;
	this->coffee_arr = new Coffee[this->num_coffee];
	for (int i = 0; i < this->num_coffee; ++i) {
		this->coffee_arr[i] = m.coffee_arr[i];
	}
}

//other functions:

void Menu::menu_load_data(ifstream &menu_input) {
	menu_input.open("menu.txt");
	if (menu_input.fail()) {
		cout << "The menu file was unable to open. Ending program!" << endl;
		return;
	}
	menu_input >> num_coffee;

	//HERE: create dynamic array for num_coffee();
	coffee_arr = new Coffee[num_coffee];
	
	for (int i = 0; i < num_coffee; i++) {
		coffee_arr[i].coffee_load_data(menu_input);
	}
	
	return;
}

void Menu::print_coffees() const {
	cout << "Choices: " << num_coffee << endl;
	for (int i = 0; i < num_coffee; i++) {
		cout << i + 1 << ". ";
		coffee_arr[i].print_coffee();
	}
}

void Menu::edit_menu_file() const {
	ofstream menu_append;
    menu_append.open("menu.txt");
	menu_append << num_coffee << endl;
    for (int i = 0; i < num_coffee; i++) {
		coffee_arr[i].append_new_coffee(menu_append);
    }
}


float Menu::call_order(int &menu_choice, char &size_choice, int &quantity_choice) {
	do {
	cout << "Out of the items above, which one would you like to order: " << endl;
	cin >> menu_choice;
	} while (menu_choice < 1 || menu_choice > num_coffee);
	menu_choice--; //offbyone use for calling array later

	do {
	cout << "Enter the size: s-small, m-medium, l-large: " << endl;
	cin >> size_choice;
	} while (size_choice != 's' && size_choice != 'm' && size_choice != 'l');

	do {
	cout << "Enter quantity: " << endl;
	cin >> quantity_choice;
	} while (quantity_choice < 1);

	return calculate_price(menu_choice, size_choice, quantity_choice);
}

float Menu::calculate_price(int menu_choice, char size_choice, int quantity_choice) {
	float price;
	if (size_choice == 's') {
		price = coffee_arr[menu_choice].get_small_cost() * quantity_choice;
		return price;
	} else if (size_choice == 'm') {
		price = coffee_arr[menu_choice].get_medium_cost() * quantity_choice;
		return price;
	} else {
		price = coffee_arr[menu_choice].get_large_cost() * quantity_choice;
		return price;
	}
}

string Menu::call_order_coffee_name(int menu_choice) {
	return coffee_arr[menu_choice].get_name(); //call accessor to print this name in order
}


void Menu::print_coffees_searchprice(float budget) const {
	cout << "Choices: " << num_coffee << endl;
	for (int i = 0; i < num_coffee; i++) {
		cout << i + 1 << ". ";
		coffee_arr[i].print_coffee_searchprice(budget);
	}
}