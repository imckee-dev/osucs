/*********************************************************************
** Program Filename: order.cpp
** Author: Ian McKee and whoever made the assignment (Roger/Alex)
** Date: 11/12/23
** Description: Holds the Order class functions, which is just a print/appending to file of whatever order we just took.
** Input: n/a
** Output: n/a
*********************************************************************/

#include <iostream>

#include "order.h"

using namespace std;

Order::Order() {
    
}


//Non-default constructor necessary so that we can create our order we placed in Shop::place_order() and later add it to Order array
Order::Order(int imp_id, string imp_name, char imp_size, int imp_quantity) : 
id(imp_id), coffee_name(imp_name), coffee_size(imp_size), quantity(imp_quantity) {

}


void Order::print_order_information() {
    cout << id << " " << coffee_name << " " << coffee_size << " " << quantity << endl;
}

void Order::append_order_information(ofstream &append) const {
    append << id << " " << coffee_name << " " << coffee_size << " " << quantity << endl;
}





//function defintions from order.h goes here