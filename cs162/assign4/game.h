/*********************************************************************
** Program Filename: game.h
** Author: Ian McKee and skeleton code creator
** Date: 11/28/23
** Description: Declares Player struct holding their values to initialie in later-defined Game class (including holding gold, is alive, their location, etc)
** Declares Game class that has an instance of that Player, a 2D vector of a grid so we can play, a length and width of such, a choice of which encounter to call later, etc.
*********************************************************************/

#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"

using namespace std;

struct Player {
	int x;
	int y;
	bool has_gold;
	bool is_alive;

	int escape_x;
	int escape_y;
	bool bat_infected;
	int bat_move_count;
	
};

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:
	vector<vector<Room>> grid;

	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not


	//feel free to add more variables...
	Player p; 
	int encounter_choice;
	bool wumpus_alive = true;

	int last_event_location_x; //Marks default Wumpus position so We can use it later
	int last_event_location_y;


public:

	//suggested functions:

//Our game defualt constructor and destructor (Both do nothing within them)
	Game();
	~Game();
	
/*********************************************************************
** Function: set_up(int, int)
** Description: This Game set up function will initialize vars for player and game,  as well as create the vector full of empty rooms. and populate them with events random.
** Parameters: Two integers (user inputted rows and columns in this case)
** Pre-Conditions: Our inputs in main() are set up so our grid can be designed to the players liking of specific number of rows and columns.
** Post-Conditions: The 2D vector is fully populated
*********************************************************************/
	void set_up(int, int);

/*********************************************************************
** Function: display_game()
** Description: Prints the whole game board. Largely done by skeleton code, but altered so we can print one player depending their position and where all the events are.
** Parameters:None
** Pre-Conditions: Our events are populated within rooms and player chosen (Set up function called) Also debug mode input should be taken already
** Post-Conditions: Whole board printed with events and plyer on debug, or just player when not debug
*********************************************************************/
	void display_game() const;


/*********************************************************************
** Function: check_win()
** Description: This Game set up function will initialize vars for player and game,  as well as create the vector full of empty rooms. and populate them with events random.
** Parameters:None
** Pre-Conditions: Repeatedly called in our play_game function to see if we've wun each turn.
** Post-Conditions: Reutnrs a true or false if we've wun or not.
*********************************************************************/
	bool check_win() const;

/*********************************************************************
** Function: get_dir()
** Description: This Game set up function will initialize vars for player and game,  as well as create the vector full of empty rooms. and populate them with events random.
** Parameters:None
** Pre-Conditions: Our percept() in Event is pure virtual. So this specific one will be called within the player being 1 away from a Gold-evented Room.
** Post-Conditions: "You see a glimmer nearby." to console under print of whole grid.
*********************************************************************/
	char get_dir();

	/*********************************************************************
** Function: wumpus_move()
** Description: This Game set up function will initialize vars for player and game,  as well as create the vector full of empty rooms. and populate them with events random.
** Parameters:None
** Pre-Conditions: Our percept() in Event is pure virtual. So this specific one will be called within the player being 1 away from a Gold-evented Room.
** Post-Conditions: "You see a glimmer nearby." to console under print of whole grid.
*********************************************************************/
	void wumpus_move();

/*********************************************************************
** Function: check_invalid_arrow()
** Description: Almost identical to the check_invalid_move().
** Parameters: Arrow_x and Arrow_y (to be fixed)
** Pre-Conditions: fire_arrow() being called.
** Post-Conditions: Fixed any arrow that is out of bounds.
*********************************************************************/
	void check_invalid_arrow(int &, int &);

/*********************************************************************
** Function: fire_arrow()
** Description: Edited from the skeleton code, we 
** Parameters:None
** Pre-Conditions: Called from the play game and if user types 'f' and they don't have 0 arrows.
** Post-Conditions: Depending on if we miss or hit, a Wumpus can move or get killed and we can potentially win. It depends.
*********************************************************************/
	void fire_arrow();

/*********************************************************************
** Function: check_invalid_move()
** Description: Used at the end of each move function defined below, in case we are positioned out of bounds we need to correct.
** Parameters:None
** Pre-Conditions: move functions being called.
** Post-Conditions: Fixed any attempted move that is out of bounds.
*********************************************************************/
	void check_invalid_move();

/*********************************************************************
** Functions: move_(up,down,left,right)()
** Description: All of these subtract the y or x value we declared earlier by 1, depending on both out of bounds and if we're currently stunned by a Bat.
** Parameters:None
** Pre-Conditions: Called a move from move()
** Post-Conditions: Player's position is updated in one direction by a factor of one. Unless theyre at the edge
*********************************************************************/
	void move_up();
	void move_down();
	void move_left();
	void move_right();

/*********************************************************************
** Function: move()
** Description:  Not altered from skeleton code, a switch function that lets us either fire an arrow or move the four directions.
** Parameters: character passed from previous
** Pre-Conditions: We've chosen an area to move
** Post-Conditions: Call each move function
*********************************************************************/
	void move(char);

/*********************************************************************
** Function: get_input()
** Description: This Game set up function will initialize vars for player and game,  as well as create the vector full of empty rooms. and populate them with events random.
** Parameters:None
** Pre-Conditions: Our percept() in Event is pure virtual. So this specific one will be called within the player being 1 away from a Gold-evented Room.
** Post-Conditions: "You see a glimmer nearby." to console under print of whole grid.
*********************************************************************/
	char get_input();

/*********************************************************************
** Function: play_game()
** Description: This Game set up function will initialize vars for player and game,  as well as create the vector full of empty rooms. and populate them with events random.
** Parameters:None
** Pre-Conditions: Our percept() in Event is pure virtual. So this specific one will be called within the player being 1 away from a Gold-evented Room.
** Post-Conditions: "You see a glimmer nearby." to console under print of whole grid.
*********************************************************************/
	void play_game(int, int, bool);






	//feel free (and you will need) to add more functions...

/*********************************************************************
** Function: insert_player()
** Description: This Game set up function will initialize vars for player and game,  as well as create the vector full of empty rooms. and populate them with events random.
** Parameters:None
** Pre-Conditions: Our events are all inserted (see function below), so our player isn't immediately dead.
** Post-Conditions: player put somewhere on the map
*********************************************************************/
	void insert_player();

/*********************************************************************
** Function: insert_event(Event* new_event)
** Description: Given a new specific event creted on the heap, we will place them randomly within this grid we created in setup.
** Parameters: Pointer to any class inherited from Event (abstract class)
** Pre-Conditions: Our percept() in Event is pure virtual. So this specific one will be called within the player being 1 away from a Gold-evented Room.
** Post-Conditions: new event placed in a randomly chosen room
*********************************************************************/
	void insert_event(Event* new_event);

/*********************************************************************
** Function: input_debug()
** Description: Repeatedly ask user for a debug mode yes or no response and modify this boolean as a result. Will default false but can change in here.
** Parameters: Boolean passed by reference
** Pre-Conditions: Declared a boolean in main. that we can passby refernec
** Post-Conditions: Passed boolean maybe altered to true or stayed the same (false).
*********************************************************************/
	void input_debug(bool &);

/*********************************************************************
** Function: percept_check()
** Description: This Game set up function will initialize vars for player and game,  as well as create the vector full of empty rooms. and populate them with events random.
** Parameters:None
** Pre-Conditions: Our percept() in Event is pure virtual. So this specific one will be called within the player being 1 away from a Gold-evented Room.
** Post-Conditions: "You see a glimmer nearby." to console under print of whole grid.
*********************************************************************/
	void percept_check();

/*********************************************************************
** Function: encounter_switch()
** Description: When we declare an encounter variable (from percept check) We use a switch function to decid what to do
** Parameters:None
** Pre-Conditions: Our percepts are checked and thus our player's current position is checked for any encounter.
** Post-Conditions: Depends on the event that's present, 4 cases. Player could die or they could even win
*********************************************************************/
	void encounter_switch();

};
#endif