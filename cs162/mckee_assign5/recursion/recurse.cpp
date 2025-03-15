/*********************************************************************
** Program Filename: recurse.cpp
** Author: Skeleton code creator (Alex or Roger probably) + Ian McKee
** Date: 12/8/2023
** Description: Tests our ways_to_top a few times and allows us to get an input from the user
** Input: Nothing on its own
** Output: User's choise on stairs and their output
*********************************************************************/

// The following is an example program that
// does some basic, limited testing of your
// ways_to_top() implementation.

#include <iostream>

#include "stairs.h"

using namespace std;

int main() {
	cout << ways_to_top(3) << endl; // Should print 4
	cout << ways_to_top(4) << endl; // Should print 7
	cout << ways_to_top(5) << endl; // Should print 13

	string n;
	do {
		cin >> n;
		cout << ways_to_top(stoi(n)) << endl;
	} while (n != "n"); //we can end the loop / program when inputting a 'n'.
}
