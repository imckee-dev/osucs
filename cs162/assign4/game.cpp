/*********************************************************************
** Program Filename: game.cpp
** Author: Ian McKee and skeleton code creator
** Date: 11/28/23
** Description: 
** Define Game class functions using  an instance of  Player, a 2D vector of a grid and calling all our Event-derived classes.
*********************************************************************/

#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"

#include <iostream>

using namespace std;

//Game Implementation

/*iterator + int; (e.g. )*/

Game::Game() {

}

Game::~Game() {

}


void Game::set_up(int rows, int cols){
	//set up the game
	this->length = rows;
	this->width = cols;
	encounter_choice = 0;
	p.is_alive = true;
	p.bat_infected = false;

	Room r; //here's our default room
	//this->grid = vector<vector<Room>>(l, vector<Room>(w, r));



	this->num_arrows = 3; 	//start with 3 arrows

	// Finish the remaining...
	//Your code here:
	
	// Create the game board: 2D vector of Room objects

	grid.resize(rows);

	for (int i = 0; i < rows; i++) {
		grid.at(i).resize(cols);
	}

	// randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold)
	// into the board

	insert_event(new Bat);
	insert_event(new Bat);
	
	insert_event(new Stalactite);
	insert_event(new Stalactite);

	insert_event(new Gold);

	insert_event(new Wumpus);

	insert_player();

}

void Game::insert_player() {
	int row_idx;
	int col_idx;

	do {
		row_idx = rand() % grid.size(); // the later Y variable
		col_idx = rand() % grid.at(0).size(); // the later X variable
	} while (grid.at(row_idx).at(col_idx).get_event() != nullptr);

	p.escape_y = p.y = row_idx;
	p.escape_x = p.x = col_idx;
}

void Game::insert_event(Event* new_event) {
	int row_idx;
	int col_idx;

	do {
		row_idx = rand() % grid.size();
		col_idx = rand() % grid.at(0).size();
	} while (grid.at(row_idx).at(col_idx).get_event() != nullptr);

	last_event_location_y = row_idx;
	last_event_location_x = col_idx;

	grid.at(row_idx).at(col_idx).set_event(new_event);
}


//Note: you need to modify this function
void Game::display_game() const {
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;
	
	// cout << "player position: " << p.x << p.y;
	// cout << "rope position: " << p.escape_x << p.escape_y;
	// cout << "Encounter choice: " << encounter_choice;
	// cout << "Bat boolean: " << p.bat_infected;
	// cout << "Bat count: " << p.bat_move_count;
	

	string line = "";
	for (int i = 0; i < this->width; ++i) 
		line += "-----";

	for (int i = 0; i < this->length; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->width; ++j)
		{
			//The first char indicates whether there is a player in that room or not
			//if the room does not have the player, print space " "

			//else, print "*"

			//Fix the following
			if (p.y != i || p.x != j) {
				cout << " ";
			} else {
				cout << "*";
			}

			//The next two chars indicate the event in the room
			//if the room does not have an event, print "  ||" (2 spaces + ||)

			//else, 
				//if debug_view is true
					//print the corresponding char of the event
				//else
					//print " " (1 space)
				// print " ||" (1 space + ||)

			//Fix the following...
			
			if (grid.at(i).at(j).get_event() == nullptr) {
				cout << "  ||";
			} else  {
				if (debug_view) {
					cout << grid.at(i).at(j).get_event()->get_char();
				} else {
					cout << " ";
				}
				cout << " ||";
			}
		}
		cout << endl;
	}
	cout << line << endl;

	//example output (when finished): 
	// --------------------
	//  B || G || B ||   ||
	// --------------------
	//    || W ||   || S ||
	// --------------------   
	//    ||   ||   || S ||
	// --------------------   
	// *  ||   ||   ||   ||
	// --------------------
}


bool Game::check_win() const {
	//check if game over/win
	//Your code here:
	if (p.has_gold && p.y == p.escape_y && p.x == p.escape_x) {
		cout << "Wow you just escaped congratulations! " << endl;
		return true;
	}
	if (p.is_alive == false) {
		cout << "RIP" << endl;
		return true;
	}
	if (wumpus_alive == false) {
		cout << "THE WUMPUS HAS BEEN HUNTED Congratulations" << endl;
		return true;
	}

	cout << "Game::check_win() is not implemented..." << endl;
	return false;
}

void Game::check_invalid_move() {
	if (p.y < 0) {
		p.y = 0;
	}
	if (p.x < 0) {
		p.x = 0;
	}
	if (p.y == grid.size()) {
		p.y = grid.size() - 1;
	}	
	if (p.x == grid.at(0).size()) {
		p.x = grid.at(0).size() - 1;
	}
}

void Game::move_up() {
	//move player up
	//Your code here:
	
	if (p.bat_infected == false) {
		p.y--;// only if its not equal to the top of the game (column 0)
	} else {
		p.y++;
		p.bat_move_count--;
	}
	check_invalid_move();
	return;

}

void Game::move_down() {
	//move player down
	//Your code here:
	if (p.bat_infected == false) {
		p.y++;
	} else {
		p.y--;
		p.bat_move_count--;
	}
	check_invalid_move();

	return;
}

void Game::move_left() {
	//move player left
	//Your code here:
	if (p.bat_infected == false) {
		p.x--;
	} else {
		p.x++;
		p.bat_move_count--;
	}
	check_invalid_move();

	return;

}

void Game::move_right() {
	//move player right
	//Your code here:
	if (p.bat_infected == false) {
		p.x++; 
	} else {
		p.x--;
		p.bat_move_count--;
	}
	check_invalid_move();

	return;
}

char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!! 
	if (num_arrows == 0) {
		cout << "Out of arrows!!" << endl;
		return 'n';
	}

	//Your code here:
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	

	cout << "Enter direction: " << endl;
	cin >> dir;
	cin.ignore(256, '\n');

	num_arrows--;

	return dir;
}

void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room

	//How to get 75%? 
	//Hint: generate a random number from 0-3, if the number is not 0, then move

	//Your code here:
	int val;
	val = rand() % 4;
	if (val != 0) {
		grid.at(last_event_location_y).at(last_event_location_x).set_event(nullptr); //Sets original wumpus to Null
		insert_event(new Wumpus);
		cout << "Wumpus got scared!" << endl;
	}
	return;
}


/*
Justification:
Each arrow needs its own case (3 lines each including break, and 2 more for not enough arrows)

Besides those 14 necessary lines, we need 10 for finding character, setting arrow coords
and handling wumpus' either hit or miss result.
*/

void Game::fire_arrow(){
	// The player may fire arrow...
	char dir = get_dir();

	//Your code here:
	int arrow_x = p.x;
	int arrow_y = p.y;
	for (int i = 0; i < 3; i++) {
		switch (dir) {
			case 'n':
				return;

			case 'w':
				arrow_y--;

			break;

			case 'a':
				arrow_x--;

			break;

			case 's':
				arrow_y++;

			break;

			case 'd':
				arrow_x++;

			break;
		}

		check_invalid_arrow(arrow_x, arrow_y);//Through each iteration (room the arrow goes in) make sure we aren't putting the arrow out of bounds
		if (grid.at(arrow_y).at(arrow_x).get_event() != nullptr) { //This whole piece of junk sets the Wumpus to null.
			if (grid.at(arrow_y).at(arrow_x).get_event()->get_char() == 'W') {
				grid.at(arrow_y).at(arrow_x).set_event(nullptr);
				wumpus_alive = false;
			}
		}
	}
	if (grid.at(arrow_y).at(arrow_x).get_event() == nullptr) {
		wumpus_move();
	}
	return;

}


void Game::check_invalid_arrow(int& arrow_x, int& arrow_y) {
	if (arrow_y < 0) {
		arrow_y = 0;
	}
	if (arrow_x < 0) {
		arrow_x = 0;
	}
	if (arrow_y == grid.size()) {
		arrow_y = grid.size() - 1;
	}	
	if (arrow_x == grid.at(0).size()) {
		arrow_x = grid.at(0).size() - 1;
	}
}

void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}
	switch(c){
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
	}
}

char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	cin >> c;
	cin.ignore(256, '\n');

	
	return c;
}

//Note: you need to modify this function
void Game::play_game(int w, int l, bool d){


	Game::set_up(w, l);
	this->debug_view = d;

	char input, arrow_input;
	
	while (Game::check_win() == false){
		//print game board
		Game::display_game();

		//display percerts around player's location
		//Your code here:

		//Player move...
		//1. get input
		input = Game::get_input();

		//2. move player
		if (p.bat_move_count == 0) { //When the 5 moves ended (we decrement 5 times within move():)
			p.bat_infected = false; //we are no longer infected.
		}
		Game::move(input);

		//3. may or may not encounter events
		//Your code here:
		Game::percept_check(); //print percepts
		if (encounter_choice > 0) {
			Game::encounter_switch();
		}

	}
	
	return;

}


void Game::input_debug(bool &debug) {
	char input = ' ';
	cout << "Debug mode? Type y for yes, or n for no.";
	do {
		cin >> input;
	} while (input != 'y' && input != 'n'); // will keep going until we get a y or n from user

	if (input == 'y') {//if we get a y:
		debug = 1; //change debug to 1
		
	} //we've exhausted all inputs to n, so the function will end. Debug defaults to false anyway in main.
}

void Game::percept_check() {

	if (p.x > 0) { // If not in top row
		if ((grid.at(p.y).at(p.x - 1).get_event() != nullptr)) { // check same event but above (1 of 4 possible)
			grid.at(p.y).at(p.x - 1).get_event()->percept();
		}
	}


	if (p.y > 0) { // If not in left column
		if ((grid.at(p.y - 1).at(p.x).get_event() != nullptr)) { /// check if theres an event to the left
			grid.at(p.y - 1).at(p.x).get_event()->percept();
		}
	}


	if (p.y < (grid.at(0).size() - 1)) { //If not in the right column 
		if ((grid.at(p.y + 1).at(p.x).get_event() != nullptr)) { /// check if theres an event to the right
			grid.at(p.y + 1).at(p.x).get_event()->percept();
		}
	}	


	if (p.x < (grid.size() - 1)) { //If not in the bottom row
		if ((grid.at(p.y).at(p.x + 1).get_event() != nullptr)) { /// check if theres an event to the bottom
			grid.at(p.y).at(p.x + 1).get_event()->percept();
		}
	}

//Now also check which event the player is on
	if (grid.at(p.y).at(p.x).get_event() != nullptr) {
		encounter_choice = grid.at(p.y).at(p.x).get_event()->encounter(); //sets int encounterchocie to whichever event it cencounters
	}

}


//~17 lines (one break and one case counted, my justification is we need to know which cases for each four derived functions to call.
//Within this function we are doing one thing just alternating between an integer we defined earlier.

void Game::encounter_switch() {
	switch (encounter_choice) {

		case 1: //Encounters gold
			p.has_gold = true;
			grid.at(p.y).at(p.x).set_event(nullptr); //sets this golsd one to nothing.

			cout << "You found the gold!" << endl;
			break;



		case 2: //Encounters stalactite
			int val; 
			val = rand() % 2; //random between 0 and 1
			if (val == 0) {
				p.is_alive = false; 

				cout << "Stalactite falls on you. ";
			} 
			break;

		case 3: //Encounters Bats
			p.bat_infected = true;//first get infected and the counter starts
			p.bat_move_count = 5;

			break;

		case 4: //Encounters Wumpus
			p.is_alive = false;

			cout << "Wumpus has found omething good to eat!! kqejrhgqiegjrh ";
			break;

	}


	encounter_choice = 0;//after this encounter is done set this basck to neutral.
}