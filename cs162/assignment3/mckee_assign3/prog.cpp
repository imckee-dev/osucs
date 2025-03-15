/*********************************************************************
** Program Filename: prog.cpp
** Author: Ian McKee and whoever made the assignment (Roger/Alex)
** Date: 11/12/23
** Description: Main function. Creates our shop, creates the ifstreams for pre-populating said shop with menu.txt and shop_info.txt. 
//Consistently ask user for choice as written in display.cpp by the skeleton code creators 
** Input: n/a
** Output: 0
*********************************************************************/

#include <iostream>
#include "display.h"

using namespace std;

int main()
{
	//your main function lives here
	cout << "Welcome to Coffee++" << endl;
	int choice = -1;
	Shop s;
	//populate your Shop:
	ifstream menu_input, shopinfo_input;
	ofstream order_input;
	s.shop_load_data(shopinfo_input, menu_input);

	while (choice != QUIT && shopinfo_input.fail() != true && menu_input.fail() != true && order_input.fail() != true){ 
		//^^^^constantly run as we don't quit and all three file fail booleans don't activate
		choice = get_choice();
		perform_action(s, choice);
	}

	cout << "Bye!" << endl;

	return 0;
}
