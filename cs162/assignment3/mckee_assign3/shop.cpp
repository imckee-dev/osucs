/*********************************************************************
** Program Filename: shop.cpp
** Author: Ian McKee and whoever made the assignment (Roger/Alex)
** Date: 11/12/23
** Description: Holds the Shop class functions, which includes the big three, loading data, and pretty much all 7 functions
** Input: n/a
** Output: n/a
*********************************************************************/

#include "shop.h"

using namespace std;

//function defintions from shop.h goes here

void Shop::shop_load_data(ifstream &shopinfo_input, ifstream &menu_input){
	//reads from files to correctly populate coffee, menu, etc.
	//Your code goes here: 
	m.menu_load_data(menu_input);
	shopinfo_input.open("shop_info.txt");
	if (shopinfo_input.fail()) {
		cout << "The shop info file was unable to open. Ending program!" << endl;
		return;
	}
	getline(shopinfo_input, phone);
	getline(shopinfo_input, address);
	revenue = 0.00;
	num_orders = 0;
	order_arr = nullptr;

	return;
}


void Shop::view_shop_detail() {
	//handle "View shop detail" option
	//print shop address, phone number, revenue, menu, and order
	//Your code goes here: 
	cout << "Address: " << address << endl;
	cout << "Contact: " << phone << endl;
	cout << "Revenue: $" << revenue << endl;
	m.print_coffees();
	if (num_orders == 0) {
		cout << "No orders are available to display. " << endl;
	} else {
		cout << "All orders: " << endl;
		for (int i = 0; i < num_orders; i++) {
			order_arr[i].print_order_information();
		}
	}
}

void Shop::add_to_menu(){
	//handle "Add coffee to menu" option
	//Hint: call Menu::add_to_menu(Coffee& coffee_to_add);
	//Your code goes here: 
	Coffee drink;
	drink.get_new_drink();
	m.add_to_menu(drink);
	//now we can add this to file:
	m.edit_menu_file();
	cout << "Added to menu???!??!?!?!/!?" << endl;

	return;
}

void Shop::remove_from_menu(){
	//handle "Remove coffee from menu" option
	//Hint: call Menu::remove_from_menu(int index_of_coffee_on_menu);
	//Your code goes here: 
	cout << "What do you want to remove from from this menu: " << endl;
	m.print_coffees();
	int requested_index;
	cin >> requested_index;
	m.remove_from_menu(requested_index);
	cout << "this MAY have been removed successfully." << endl;

	return;
}


void Shop::search_by_name() {
	//handle "Search by coffee name" option
	//Hint: call Menu::search_coffee_by_name(string name);
	//Your code goes here: 
	m.print_coffees();
	string requested_name;
	cout << "What do you want to search from from this menu (Enter name): " << endl;
	cin >> requested_name;
	
	m.search_coffee_by_name(requested_name);

	return;
}

void Shop::search_by_price() {
	//handle "Search by coffee price" option
	//Hint: call Menu::search_coffee_by_price(float budget);
	//Your code goes here: 
	float budget = -1;
	do {
		cout << "Enter a price value and I will taell you all of the items under or equal to that price: " << endl;
		cin >> budget;
	} while (budget < 0);

	Menu searchedMenu;
	searchedMenu.search_coffee_by_price(budget, m);


	return;
}


//16 lines (excl. cout and all initalizations)
/*********************************************************************
** Function: place_order()
** Description: print menu, ask user for info and record price, confirm, and add price to revenue and order to order array of current shop
** Parameters: none
** Pre-Conditions: populated shop and menu
** Post-Conditions: if confirmed, new item in order array, and revenue
*********************************************************************/

void Shop::place_order() {
	//handle "Place order" option
	//Your code goes here: 

	m.print_coffees(); //

	//all initializations
	int menu_choice = -1;
	char size_choice = ' ';
	int quantity_choice = -1;
	string choice_name;
	float price;
	int id = num_orders + 1;
	bool confirmation;

	price = m.call_order(menu_choice, size_choice, quantity_choice);

	choice_name = m.call_order_coffee_name(menu_choice); //uses accessor in here to print right under

	cout << "So you want " << quantity_choice << " " << choice_name << "s? It would be " << price << ",  Confirm with 1, cancel with 0: ";
	cin >> confirmation;
	if (confirmation == false) {
		return;
	}

	revenue += price;
	Order new_order(id, choice_name, size_choice, quantity_choice); //call non default constructor to make rthis new order
	

	Order* new_array = new Order[num_orders + 1]; //make the new dynamic with +1 length
	for (int i = 0; i < num_orders; i++) { //for original length:
		new_array[i] = order_arr[i]; //add to new array like normal
	}
	delete [] order_arr; //delete old (no longer needed)
	order_arr = new_array; //old pointer goes to new pointer
	num_orders++; //length can finally be +1
	order_arr[num_orders - 1] = new_order; //at end of array (-1 for num items -1), add the new Order just created

	//now we can add this to file:
	edit_order_file();
	
	

	return;
}

Shop::Shop() {
	order_arr = nullptr;
}

Shop Shop::clone_shop() {
	//handle "Clone a shop" option
	//note: the purpose of this option is to test
	//your big three implementation

	Shop cloned_shop;

	cloned_shop = *this; // test AOO        

    Shop cloned_shop2 = *this; // test CC 

    cout << "Shop cloned successfully!" << endl; 

    return cloned_shop;
}


Shop::~Shop() {
	if (this->order_arr != NULL) { //for our destructor we need to manually get rid of the allocated dynamic memory (the Order* array)
		delete [] this->order_arr;
		this->order_arr = NULL;
	}
}

Shop& Shop::operator=(const Shop& s) {
	if (this == &s) {//if we're copying same shop to itself, return the original
		return *this;
	}
	if (this->order_arr != nullptr) { //if the order array of the to-copy shop is not empty, delete whatever was in it
		delete [] this->order_arr;
	}

	this->m = s.m; //copy all std values
	this->phone = s.phone;
	this->address = s.address;
	this->revenue = s.revenue;
	num_orders = s.num_orders;
	this->order_arr = new Order[this->num_orders]; //new dynamic array with std value of num orders
	for (int i = 0; i < num_orders; ++i) {
		this->order_arr[i] = s.order_arr[i]; //copy all data within it
	}
	return *this; //return the new copy's pointer
}


Shop::Shop(const Shop& s) {
	this->m = s.m;
	this->phone = s.phone;
	this->address = s.address;
	this->revenue = s.revenue;
	num_orders = s.num_orders;
	this->order_arr = new Order[this->num_orders];
	for (int i = 0; i < num_orders; ++i) {
		this->order_arr[i] = s.order_arr[i];
	}
}


void Shop::edit_order_file() {
	ofstream append;
	append.open("orders.txt");
	append << num_orders << endl;
	for (int i = 0; i < num_orders; i++) {
		order_arr[i].append_order_information(append); //for each order, output to order file
	}
}