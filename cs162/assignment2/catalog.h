/*********************************************************************
** Program Filename: catalog.h
** Author: Ian McKee 
** Date: 10/29/23
** Description: header file for assignment 2, holds the two required structs and five required functions, and Ian's custom functions
                that are later defined in catalog.cpp.
** Input: input/output stream, filestreams for of/ifstream.
** Output: Defines structs and function prototypes required for assignment 2 and needed for assignment 2 to run.
*********************************************************************/

#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <fstream>

using namespace std;

//a struct to hold info of a team
struct Team {
  string name;        //name of the team
  string owner;       //owner of the team
  int market_value;   //market value of the team
  int num_player;     //number of players in the team
  struct Player *p;   //an array that holds all players
  float total_ppg;    //total points per game
};

//a struct to hold info of a player
struct Player {
  string name;      //name of the player
  int age;          //age of the player
  string nation;    //nationality of the player
  float ppg;        //points per game of the player
  float fg;         //field goal percentage
};


/**************************************************
 * Name: create_teams()
 * Description: This function will dynamically allocate
                an array of teams (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Team array of requested size is created and return
 ***********************************************/
Team* create_teams(int);


/**************************************************
 * Name: populate_team_data()
 * Description: This function will fill a single team struct 
                with information that is read in from the file
 * Parameters:  Team* - pointer to the Team array
                int - index of the Team in the array to be filled 
                ifstream& - input file to get information from
 * Pre-conditions: Team array has been allocated; 
                   provided index is less than the array size
 * Post-conditions: a Team at provided index is populated
 ***********************************************/
void populate_team_data(Team*, int, ifstream &); 


/**************************************************
 * Name: create_players()
 * Description: This function will dynamically allocate
                an array of players (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Player array of requested size is created and return
 ***********************************************/
Player* create_players(int);


/**************************************************
 * Name: populate_player_data()
 * Description: This function will fill a single player struct 
                with information that is read in from the file
 * Parameters:  Player* - pointer to the Player array
                int - index of the Player in the array to be filled 
                ifstream& - input file to get information from
 * Pre-conditions: Player array has been allocated; 
                   provided index is less than the array size
 * Post-conditions: a Player at provided index is populated
 ***********************************************/
void populate_player_data(Player*, int, ifstream &); 


/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically allocated
 * Parameters: Team* - the Team array
 * Pre-conditions: the provided Team array hasn't been freed yet
 * Post-conditions: the Team array, with all Players inside, is freed
 ***********************************************/
void delete_info(Team*, int);



//nonrequired:

/**************************************************
 * Name: promptFileInput();
 * Description: This function will take an input from user
 * Parameters: the ifstream we just created
 * Pre-conditions: none
 * Post-conditions: returns string of the filename the user decided on.
 ***********************************************/
void promptFileInput(ifstream &);

/**************************************************
 * Name: populate_file_data()
 * Description: This function will go through the full file of all teams and populate the Team* full array.
 * Parameters: Team* - the Team array, teamQuantity - int of the length of the teamArray, same ifstream to read full file
 * Pre-conditions: the team array has been created, and we've gathered the length already from the first line in teams.txt (or other file.)
 * Post-conditions: the full file has been gone through, such that Team* is fully populated, with each team array.
 ***********************************************/
void populate_file_data(Team*, int, ifstream &);

/**************************************************
 * Name: promptOptionInput()
 * Description: This function will continuously ask user for an input 1-5 for what option to choose.
 * Parameters: none
 * Pre-conditions: we've read the whole file of information.
 * Post-conditions: returns string 1-5 of user's decision
 ***********************************************/
string promptOptionInput();

/**************************************************
 * Name: writeorprintOption();
 * Description: This function will continuously ask user for an input 1-2 for printing to console or writing to a file.
 * Parameters: none
 * Pre-conditions: We've got an answer for what to do (see promptOptionInput)
 * Post-conditions: returns string 1-2 of user's decision
 ***********************************************/
string writeorprintOption();


//4 function descriptions:

//    function1: searchbyname

/**************************************************
 * Name: search_by_name()
 * Description: This function will go through the now populated Team array and see if a team matches the name of the user's input.
 * Parameters: Team* - the Team array, int- quantity of teams to search through
 * Pre-conditions: the Team array has been fully populated through populate_file_data/populate_team_data/populate_player_data, and user decides 1-4 from promptOptionInput.
 * Post-conditions: the full file has been gone through, and we return an int of team position in array, or a -1 to indicate not found.
 ***********************************************/
int search_by_name(Team*, int);

/**************************************************
 * Name: cout_search_by_name()
 * Description: This function will print to console results of search_by_name().
 * Parameters: int- Location of team searched; Team* - the Team array to search from
 * Pre-conditions: we have searched using search_by_name for a team int value.
 * Post-conditions: the console output will be all the results of this team inc. players, etc
 ***********************************************/
void cout_search_by_name(int, Team*);



/**************************************************
 * Name: outfile_search_by_name()
 * Description: This function will output to a file results of search_by_name().
 * Parameters: int- Location of team searched; Team* - the Team array to search from; ofstream- used for file appending.
 * Pre-conditions: we have searched using search_by_name for a team int value.
 * Post-conditions: A new file by name of the user's choice has all the results of this team inc. players, etc
 ***********************************************/
void outfile_search_by_name(int, Team*);

//function2: display top scorer of every team

/**************************************************
 * Name: cout_top_scorers()
 * Description: This function will go through the now populated Team array and for each team, find a player score that is largest, and print that score.
 * Parameters: Team* - the Team array, int- quantity of teams to search through
 * Pre-conditions: the Team array has been fully populated through populate_file_data/populate_team_data/populate_player_data, and user decides 1-4 from promptOptionInput.
 * Post-conditions: the console receives information about each team's highest scoring player.
 ***********************************************/
void cout_top_scorers(Team*, int);

/**************************************************
 * Name: outfile_top_scorers()
 * Description: This function will go through the now populated Team array and for each team, find a player score that is largest, and output that score to desired filename.
 * Parameters: Team* - the Team array, int- quantity of teams to search through
 * Pre-conditions: the Team array has been fully populated through populate_file_data and user decides 1-4 from promptOptionInput.
 * Post-conditions: a file in directory with user-desired name gets appended information about each team's highest scoring player.
 ***********************************************/
void outfile_top_scorers(Team* teamArray, int teamQuantity);

//function3: display all players of certain nationality of user's choosing

/**************************************************
 * Name: cout_search_nationality()
 * Description: This function will go through the now populated Team array and ask user to input a nationality; and for each team and player in that team,
 *              check if the player is equal to user's nation input. Prints all of them.
 *              Also uses integer amountFound to both factor in unfound and/or invalid nations inputted.
 * Parameters: Team* - the Team array, int- quantity of teams to search through
 * Pre-conditions: the Team array has been fully populated through populate_file_data/populate_team_data/populate_player_data, and user decides 1-4 from promptOptionInput.
 * Post-conditions: the console receives information about each player that matches user-inputted nationality. Or a message if not found.
 ***********************************************/
void cout_search_nationality(Team*, int);

/**************************************************
 * Name: outfile_search_nationality()
 * Description: This function will go through the now populated Team array and ask user to input a nationality; and for each team and player in that team,
 *              check if the player is equal to user's nation input. Outputs all to a file of user's name choice.
 *              Also uses integer amountFound to both factor in unfound and/or invalid nations inputted.
 * Parameters: Team* - the Team array, int- quantity of teams to search through
 * Pre-conditions: the Team array has been fully populated through populate_file_data/populate_team_data/populate_player_data, and user decides 1-4 from promptOptionInput.
 * Post-conditions: a file in directory with user-desired name gets appended information about each player that matches user-inputted nationality. 
 *               Or a *console printed* message if nothing found.
 ***********************************************/
void outfile_search_nationality(Team*, int);


//extra credit: sort array descending:

/**************************************************
 * Name: sort_teams()
 * Description: This function goes through the team array and sorts from large to small of total points per game. Only swaps names 
 * and points per game of current team array.
 * Parameters: Team* - the Team array, int- quantity of teams to search through
 * Pre-conditions: the Team array has been fully populated through populate_file_data/populate_team_data/populate_player_data, and user decides 1-4 from promptOptionInput.
 * Post-conditions: a file in directory with user-desired name gets appended information of teams, from largest ppg to smallest.
 ***********************************************/
void sort_teams(Team*, int);

/**************************************************
 * Name: cout_sort_teams()
 * Description: This function prints the result of sort_teams() function, all teams' names and total points per game.
 *              (They should be in order already after calling sort_teams()
 * Parameters: Team* - the Team array, int- quantity of teams to search through
 * Pre-conditions: the Team array has been fully populated through populate_file_data/populate_team_data/populate_player_data, and user decides 1-4 from promptOptionInput.
 * Post-conditions: console receives information of teams, from largest ppg to smallest.
 ***********************************************/
void cout_sort_teams(Team*, int);

/**************************************************
 * Name: outfile_sort_teams()
 * Description: This function creates an ofstream to output the result of sort_teams() function, to a file.
 *              (Names and ppg should be in order already after calling sort_teams()
 * Parameters: Team* - the Team array, int- quantity of teams to search through
 * Pre-conditions: the Team array has been fully populated through populate_file_data/populate_team_data/populate_player_data, and user decides 1-4 from promptOptionInput.
 * Post-conditions: a file in directory with user-desired name gets appended information of teams, from largest ppg to smallest.
 ***********************************************/
void outfile_sort_teams(Team*, int);


/**************************************************
 * Name: userInputAction()
 * Description: choopse options from 1-4, decide what to do next
 * Parameters: string- received input for what to do, Team* - the Team array, int- quantity of teams for file index
 * Pre-conditions: the Team array has been fully populated through populate_file_data/populate_team_data/populate_player_data, and user decides 1-4 from promptOptionInput.
 * Post-conditions: triggers one of 4 options of how to use our file teams.txt (or something else)
 ***********************************************/
void userInputAction(string, Team*, int);


#endif
