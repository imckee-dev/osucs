/*********************************************************************
** Program Filename: gold.cpp
** Author: Ian McKee and skeleton code creator
** Date: 11/28/23
** Description: Defines three Gold-specific virtual functions: getting the character G, printing the precept, and returning the number 1
*********************************************************************/

#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation

char Gold::get_char() const {
    return 'G';
}

void Gold::percept() {
    cout << "You see a glimmer nearby." << endl;
}

int Gold::encounter() {
    return 1;
}
