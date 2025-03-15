/*********************************************************************
** Program Filename: wumpus.cpp
** Author: Ian McKee and skeleton code creator
** Date: 11/28/23
** Description: Defines three Wumpus-specific virtual functions: getting the character W, printing the precept, and returning the number 4.
*********************************************************************/

#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation

char Wumpus::get_char() const {
    return 'W';
}

void Wumpus::percept() {
    cout << "You smell a terrible stench." << endl;
}

int Wumpus::encounter() {
    return 4;
    //die
}


