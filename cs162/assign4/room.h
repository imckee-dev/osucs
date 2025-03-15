#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

//One class has big three – Room, to delete the event effectively

//from assignment: Each Room contains at most one Event, but it's possible that it contains no Event. The
//design of your Room class should reflect this.

class Room
{
private: 
	Event* e = nullptr;
	//suggestion: get rid of: and maybe do Player* p = nullptr;. bool player;
	bool arrow;
public:

	/*********************************************************************
** Function: ~Room()
** Description: Destrucrts our room and allows us to free our dynamically allocated event (if we have one)
** Parameters: None
** Pre-Conditions: Room is fully used up and the game is over
** Post-Conditions: If there is an event in this room we get rid of it otherwise do nothing
*********************************************************************/
	~Room();

/*********************************************************************
** Function: set_event()
** Description: This is our mutator for setting a new event. Deletes whatevers in this room and creates a new event of whatever's passed..
** Parameters: Passed a new event
** Pre-Conditions: Our inputs in main() are set up so our grid can be designed to the players liking of specific number of rows and columns.
** Post-Conditions: The 2D vector is fully populated
*********************************************************************/
	void set_event(Event* new_event);

	/*********************************************************************
** Function: get_event()
** Description: This is our accessor for our event in this room.
** Parameters: None
** Pre-Conditions: There is an event in this room
** Post-Conditions: Receive the event we're referring to
*********************************************************************/
	Event* get_event() const;

    //member function to call different events

};

#endif
