/*********************************************************************
** Program Filename: stalactites.cpp
** Author: Ian McKee and skeleton code creator
** Date: 11/28/23
** Description: Defines three Stalactite-specific virtual functions: getting the character S, printing the precept, and returning the number 2
*********************************************************************/

#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation

char Stalactite::get_char() const {
    return 'S';
}

void Stalactite::percept() {
    cout << "You hear water dripping." << endl;
}

int Stalactite::encounter() {
    return 2;
}

