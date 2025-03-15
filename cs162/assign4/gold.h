/*********************************************************************
** Program Filename: gold.h
** Author: Ian McKee and skeleton code creator
** Date: 11/28/23
** Description: Defines class Gold and declares three Gold-specific virtual functions: getting the character G, printing the precept, and returning the number 1
*********************************************************************/

#ifndef GOLD_H
#define GOLD_H 

#include "event.h"

//Gold Interface

class Gold : public Event {


public: 

/*********************************************************************
** Function: get_char()
** Description: For this polymorphic Gold function, we just print the specific Gold char, G.
** Parameters:None
** Pre-Conditions: Our percept() in Event is pure virtual. So this specific one will be called when we're ready to print the one gold G.
** Post-Conditions: Gold Character G returned
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