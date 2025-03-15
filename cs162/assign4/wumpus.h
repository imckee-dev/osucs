/*********************************************************************
** Program Filename: wumpus.h
** Author: Ian McKee and skeleton code creator
** Date: 11/28/23
** Description: Defines class Wumpus and declares three Wumpus-specific virtual functions: getting the character W, printing the precept, and returning the number 4.
*********************************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H 

#include "event.h"

//Wumpus Interface

class Wumpus : public Event {
private:


public:
/*********************************************************************
** Function: get_char()
** Description: For this polymorphic Bat function, we just print the specific Wumpus char W. Used when both printing and when Wumpus moves and misses an arrow.
** Parameters:None
** Pre-Conditions: Our get_char const in Event is pure virtual. So this specific one will be called when printing different characters when a room is not empty.
** Post-Conditions: Return a W for Wumpus to print.
*********************************************************************/
    char get_char() const;

/*********************************************************************
** Function: percept()
** Description: For this polymorphic gold function, we just print the specific Gold precept, so "You see a glimmer nearby."
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