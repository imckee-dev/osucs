/*********************************************************************
** Program Filename: main.cpp
** Author: Ian McKee and skeleton code creator
** Date: 11/28/23
** Description: Plays our Hunt the WUmpus game, largely calling a functions within Game class that we've defined early on in the main function.
** Input: None, except setting the random seed and initializing things like width length and debug values that will be useful as we call our Game object.
** Output: Hunt the Wumpus (or 0 if the game is over)
*********************************************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;


int main()
{
	//set the random seed
	srand(time(NULL));
	
	int wid = 5, len = 5;
	bool debug = false;
	
	Game g;

	//get two inputs: size of the cave(wid and len)
	cout << "Enter input for width: ";
	do {
		cin >> wid;
	} while (wid < 4);
	cout << "Enter input for length: ";
	do {
		cin >> len;
	} while (len < 4);

	//get the 3rd input --> debug mode or not
	g.input_debug(debug);

	//Play game
	g.play_game(wid, len, debug);


	return 0;
}