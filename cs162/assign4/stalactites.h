/*********************************************************************
** Program Filename: stalactites.h
** Author: Ian McKee and skeleton code creator
** Date: 11/28/23
** Description: Creats class Stalactite that declares three Gold-specific virtual functions: getting the character S, printing the precept, and returning the number 2
*********************************************************************/

#ifndef STALACTITES_H
#define STALACTITES_H 

#include "event.h"

//Stalactites Interface



class Stalactite : public Event {
private:

public:
    
/*********************************************************************
** Function: get_char()
** Description: For this polymorphic Stalactite function, we just print the specificStalactite char S
** Parameters:None
** Pre-Conditions: Our get_char const in Event is pure virtual. So this specific one will be called when printing different characters when a room is not empty.
** Post-Conditions: Return a S for stalactite to print.
*********************************************************************/
    char get_char() const;

/*********************************************************************
** Function: percept()
** Description: For this polymorphic Stalactite function, we just print the specific Gold precept, so "You see a glimmer nearby."
** Parameters:None
** Pre-Conditions: Our percept() in Event is pure virtual. So this specific one will be called within the player being 1 away from a Gold-evented Room.
** Post-Conditions: "You see a glimmer nearby." to console under print of whole grid.
*********************************************************************/
    void percept();

/*********************************************************************
** Function: encounter()
** Description: For this polymorphic gold function, we will do specific Gold encounter things, like change the boolean to true for player.
** Parameters:None
** Pre-Conditions: Our percept() in Event is pure virtual. So this specific one will be called within the player being 1 away from a Gold-evented Room.
** Post-Conditions: "You see a glimmer nearby." to console under print of whole grid.
*********************************************************************/
    int encounter();

};


#endif
