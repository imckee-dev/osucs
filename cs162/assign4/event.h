/*********************************************************************
** Program Filename: event.h
** Author: Ian McKee and skeleton code creator
** Date: 11/28/23
** Description: Defines abastract Event class and defines three pure virtual functions: getting a character, printing a precept, and returning a number for encounter-calling purposes.
*********************************************************************/

#ifndef EVENT_H
#define EVENT_H 

using namespace std;

class Event
{

protected: 
	

public:
/*********************************************************************
** Function: VIRTUAL get_char()
** Description: For this virtual event function get_char(), it does nothing, although it is a placeholder for what will come with the derived Event classes. All return a char.
** Parameters:None
** Pre-Conditions: There are existing events  of different classes
** Post-Conditions: Nothing
*********************************************************************/
    virtual char get_char() const = 0;

/*********************************************************************
** Function: VIRTUAL percept()
** Description: For this virtual event function percept(), it does nothing, although it is a placeholder for what will come with the derived Event classes. All don't return anything and will just print something specific.
** Parameters:None
** Pre-Conditions: There are existing events  of different classes
** Post-Conditions: Nothing
*********************************************************************/
	virtual void percept() = 0; //virtual function: call percept for each event (message)
	
/*********************************************************************
** Function: VIRTUAL encounter()
** Description: For this virtual event function encounter(), it does nothing, although it is a placeholder for what will come with the derived Event classes. All return an int.
** Parameters:None
** Pre-Conditions: There are existing events of different classes
** Post-Conditions: Nothing
*********************************************************************/
    virtual int encounter() = 0;

/*********************************************************************
** Function: Virtual destructor ~Event()
** Description: For this virtual destructor, it will do nothing on its own, but allows us to destruct all of our specific events.
** Parameters:None
** Pre-Conditions: There are existing events of certain classes
** Post-Conditions: Deleted event (depends on the event)
*********************************************************************/
    virtual ~Event();
};
#endif