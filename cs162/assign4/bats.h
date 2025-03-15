/*********************************************************************
** Program Filename: bats.h
** Author: Ian McKee and skeleton code creator
** Date: 11/28/23
** Description: Defines class Bat and declares three Bat-specific virtual functions: getting the character B, printing the precept, and returning the number 3
*********************************************************************/

#ifndef BATS_H
#define BATS_H 

#include "event.h"

//Bats Interface

class Bat : public Event {
private:

public:
/*********************************************************************
** Function: get_char()
** Description: For this polymorphic Bat function, we just print the specific Bat char B
** Parameters:None
** Pre-Conditions: Our get_char const in Event is pure virtual. So this specific one will be called when printing different characters when a room is not empty.
** Post-Conditions: Return a B for bat to print.
*********************************************************************/
    char get_char() const;

/*********************************************************************
** Function: percept()
** Description: For this polymorphic Bat function, we just print the specific Bat precept, so"You hear wings flapping." 
** Parameters:None
** Pre-Conditions: Our percept() in Event is pure virtual. So this specific one will be called within the player being 1 away from a Bat-evented Room.
** Post-Conditions:"You hear wings flapping."  to console under print of whole grid.
*********************************************************************/
    void percept();

/*********************************************************************
** Function: encounter()
** Description: For this polymorphic Bat function, we return the integer 3 so the Game function can iterate from that switch function to do specific Bat things there.
** Parameters:None
** Pre-Conditions: Our encounter() in Event is pure virtual. This specific one wil be called if our player position is the same as the bat position.
** Post-Conditions: Returns integer 3 
*********************************************************************/
    int encounter();
    
};

#endif