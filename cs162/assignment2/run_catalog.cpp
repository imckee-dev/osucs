/*********************************************************************
** Program Filename: run_catalog.cpp
** Author: Ian McKee
** Date: 10/29/23
** Description: The main function for Ian's programming assignment 2. 
** Input: Includes header catalog.h, so we can use all of its function prototypes in this whole program.
** Output:	Console asking user for options, and then either outputting results to console again or to a file of user's choice.
*********************************************************************/

#include "catalog.h"

using namespace std;

int main()
{
	ifstream readFileInput; //create ifstream so we can take info from the file
	ofstream fileOutput;
	promptFileInput(readFileInput);//call function to ask user for a valid filename
	int teamQuantity;
	readFileInput >> teamQuantity; //using file ifstream, read first line of file for gathering quantity of teams 
	Team* teamArray = create_teams(teamQuantity); //call 1st req'd function and initialize team array
	cout << "File found. This file has " << teamQuantity << " teams." << endl;
	populate_file_data(teamArray, teamQuantity, readFileInput);
	string userOption;						//needs to be created before while loop
	while (userOption != "4") {				//will keep asking for inputs until user decides to quit.
		userOption = promptOptionInput();	//first decide what the user wants to do. (1-5).
		userInputAction(userOption, teamArray, teamQuantity);			//then take action after input has been decided.
	}
	delete_info(teamArray, teamQuantity);   
	cout << "Thank you for your service. Goodbye" << endl;
	return 0;
}
