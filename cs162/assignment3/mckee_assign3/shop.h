/*********************************************************************
** Program Filename: shop.h
** Author: Ian McKee and whoever made the assignment (Roger/Alex)
** Date: 11/12/23
** Description: Holds the Shop class, which has a Menu, and an Order array. the rest are standard data types. Includes the big three for copying the shop.
** Input: n/a
** Output: n/a
*********************************************************************/

#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>
#include <iostream>
#include "menu.h"
#include "order.h"

using namespace std;

class Shop {
  private:
    Menu m;
    string phone;
    string address; 
    float revenue;      //shop revenue
    Order* order_arr;   //order array
    int num_orders;     //number or orders
  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

    //to add: accessor and mutator for revenue
    //accessor and mutator for num_orders;
    Shop();
    ~Shop();
    Shop& operator=(const Shop &); //assignment operator overload
    Shop(const Shop &); //copy constructor

    //Suggested functions
    void shop_load_data(ifstream &shopinfo_input, ifstream &menu_input); //reads from files to correctly populate coffee, menu, etc.
    void view_shop_detail();
    void add_to_menu();
    void remove_from_menu();
    void search_by_name();
    void search_by_price();
    void place_order();
    Shop clone_shop();

    //custom:
    void edit_order_file();
    
};

#endif
