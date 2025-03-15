/*********************************************************************
** Program Filename: order.h
** Author: Ian McKee and whoever made the assignment (Roger/Alex)
** Date: 11/12/23
** Description: Holds the Order class, which has many functions. Has a non-default constructor.
** Input: n/a
** Output: a Order class that can have an order id, the coffee name, size and quantity of that drink.
*********************************************************************/

#ifndef ORDER_H
#define ORDER_H 

#include <string>
#include <fstream>

using namespace std;

class Order
{
private:
	int id;
	string coffee_name;
	char coffee_size;
	int quantity;

public:
	//need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

	Order();
	Order(int, string, char, int); //ID, name, size, quantity (Nondefault constructor)


	void print_order_information();

	void place(string, char, int);
	void append_order_information(ofstream &) const;
	
};
#endif