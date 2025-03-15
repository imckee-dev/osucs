/*********************************************************************
** Program Filename: bats.cpp
** Author: Ian McKee and skeleton code creator
** Date: 11/28/23
** Description: Defines three Bat-specific virtual functions: getting the character B, printing the precept, and returning the number 3
*********************************************************************/

#include "bats.h"

#include <iostream>

using namespace std;

//Bats Implementation

char Bat::get_char() const {
    return 'B';
}

void Bat::percept() {
    cout << "You hear wings flapping." << endl;
}

int Bat::encounter() {
    //trigger bat boolean in move
    return 3;
}
