/*********************************************************************
** Program Filename: menu.h
** Author: Ian McKee and whoever made the assignment (Roger/Alex)
** Date: 11/12/23
** Description: Holds the Menu class, which has many functions. Includes the big three because of its dynamic array.
** Input: n/a
** Output: a Menu class with a number of coffees and an Coffee array with that length.
*********************************************************************/

#ifndef MENU_H
#define MENU_H 

#include <string>
#include <fstream>
#include "coffee.h"

using namespace std;

class Menu {
  private:
    int num_coffee;
    Coffee* coffee_arr;
  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    //need to use 'const' when appropriate


    //lab6
    Menu();
    Menu (int size);
    ~Menu();

    Menu& operator=(const Menu &); //assignment operator overload
    Menu(const Menu &); //copy constructor

    // Suggested functions:
    void search_coffee_by_name(string name) const; 
    void search_coffee_by_price(float budget, Menu); 
    void add_to_menu(const Coffee&); //add a coffee object into the Menu
    void remove_from_menu(int index_of_coffee_on_menu); //remove a coffee object from the Menu

    // feel free to add more member functions
    void menu_load_data(ifstream &); //called in shop_load_data, populates our coffee array

    void print_coffees() const;
    void print_coffees_searchprice(float) const; 

    void edit_menu_file() const;

    float call_order(int &, char &, int &); //checks valid coffee choice and size choice and quantity
    float calculate_price(int, char, int);
    string call_order_coffee_name(int);

    
};

#endif