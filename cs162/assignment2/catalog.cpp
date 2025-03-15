/*********************************************************************
** Program Filename: catalog.cpp
** Author: Ian McKee
** Date: 10/29/23
** Description: Holds all required functions and Ian's created functions for Assignment 2 (managing+playing with baskeball team data)
** Input: Catalog header (holding all functions defined here)
** Output:  Function definitions here to be used in run_catalog.cpp
*********************************************************************/

#include "catalog.h"

using namespace std;

//required function definitions go here

Team* create_teams(int teamQuantity) {
    Team* teamArray = new Team[teamQuantity];
    return teamArray;
}

//Possible length justification: all team struct data points need minimum 3 lines each to populate correctly. (Lines 14-24 are inevitable. We haven't learned quicker methods just yet.)
void populate_team_data(Team* teamArray, int teamPosition, ifstream &readFileInput) {
        string team_name;                   //create string to later use ifstream to read
        readFileInput >> team_name;         //use ifstream from reference to funnel next string in file to string var team_name.
        teamArray[teamPosition].name = team_name;       //finally assign found value to the team array's name position.
        string team_owner;                  //for owner, market value, num players, roughly same steps as team_name. (Just change type for next two)
        readFileInput >> team_owner;
        teamArray[teamPosition].owner = team_owner;
        int market_value;
        readFileInput >> market_value;
        teamArray[teamPosition].market_value = market_value;
        int num_players;
        readFileInput >> num_players;
        teamArray[teamPosition].num_player = num_players;//use this later also for creating team's player array
        float total_ppg = 0.0;//initialize total_ppg float before for loop so we can iterate through all.
        teamArray[teamPosition].p = create_players(num_players); //we need a dynamic array of player size for each of already dynamically allocated Team array's struct p*.
        for (int i = 0; i < teamArray[teamPosition].num_player; i++) {      //for all number of players in this current team:
            populate_player_data(teamArray[teamPosition].p, i, readFileInput);      //populate current player in current team with data (see populate_player_data)
            total_ppg += teamArray[teamPosition].p[i].ppg;      //since we created float earlier, we now add this value to it.
        }
        teamArray[teamPosition].total_ppg = total_ppg;
}

Player* create_players(int playerQuantity) {
    Player* playerArray = new Player[playerQuantity];
    return playerArray;
}


void populate_player_data(Player* playerArray, int playerPosition, ifstream &readFileInput){
    string name;
    readFileInput >> name;
    playerArray[playerPosition].name = name;
    int age;
    readFileInput >> age;
    playerArray[playerPosition].age = age;
    string nationality;
    readFileInput >> nationality;
    playerArray[playerPosition].nation = nationality;
    float pointsPerGame;
    readFileInput >> pointsPerGame;
    playerArray[playerPosition].ppg = pointsPerGame;
    float fieldGoalPercent;
    readFileInput >> fieldGoalPercent;
    playerArray[playerPosition].fg = fieldGoalPercent;
}


void delete_info(Team* teamArray, int teamQuantity) {
    for (int i = 0; i < teamQuantity; i++) {
        delete [] teamArray[i].p;
    }
    delete [] teamArray;
    teamArray = nullptr;
}

//nonrequired:

void promptFileInput(ifstream &readFileInput) {
    do {
    cout << "Enter the team info file name: ";
    string fileInput;
	cin >> fileInput;
    readFileInput.clear();
    readFileInput.open(fileInput);
    } while (readFileInput.fail());
}

void populate_file_data(Team* teamArray, int teamQuantity, ifstream &readFileInput) {
    
    for (int i = 0; i < teamQuantity; i++) {
        populate_team_data(teamArray, i, readFileInput);
    }
}

string promptOptionInput() {
	string option;
    do {
        cout << "Which option would you like to choose?" << endl;
        cout << "1. Search team by its name" << endl;
        cout << "2. Display the top scorer of each team" << endl;
        cout << "3. Search players by nationality" << endl;
        cout << "4. Quit" << endl; 
        cout << "5. Sort teams by total points per game" << endl; 
        cout << "Your Choice: ";
        cin >> option;
    } while (option != "1" && option != "2" && option != "3" && option != "4" && option != "5");
    return option;
}

string writeorprintOption() {
    string print_or_write;
    do {
        cout << "How would you like the information displayed?" << endl;
        cout << "1. Print to screen (Press 1)" << endl;
        cout << "2. Print to file (Press 2)" << endl;
        cout << "Your Choice: ";
        cin >> print_or_write;
    } while (print_or_write != "1" && print_or_write != "2");
    return print_or_write;
}

int search_by_name(Team* teamArray, int teamQuantity) {
    string input_name;
    cout << "Enter desired team's name: ";
    cin >> input_name;
    for (int i = 0; i < teamQuantity; i++) {
        if (input_name == teamArray[i].name) {
            return i;
        }
    }
    return -1;
}

void cout_search_by_name(int searchVal, Team* teamArray) {
    if (searchVal != -1) {
        cout << teamArray[searchVal].name << " found. Owner ";
        cout << teamArray[searchVal].owner << "; team worth $";
        cout << teamArray[searchVal].market_value << "; with ";
        cout << teamArray[searchVal].num_player << " players: ";
        for (int i = 0; i < teamArray[searchVal].num_player; i++) {
            cout << teamArray[searchVal].p[i].name << ", ";
        }
    } else {
        cout << "Team not found." << endl;
    }
}

void outfile_search_by_name(int searchVal, Team* teamArray){
    ofstream fileOutput;
    cout << "Enter filename for output: ";
	string out_filename;
	cin >> out_filename;
	fileOutput.open(out_filename, ios::app);
    fileOutput << teamArray[searchVal].name << " found. Owner ";
    fileOutput << teamArray[searchVal].owner << "; team worth $";
    fileOutput << teamArray[searchVal].market_value << "; with ";
    fileOutput << teamArray[searchVal].num_player << " players: ";
    for (int i = 0; i < teamArray[searchVal].num_player; i++) {
        fileOutput << teamArray[searchVal].p[i].name << ", ";
    }
    cout << "Appended team info to file " << out_filename << endl;
}

void cout_top_scorers(Team* teamArray, int teamQuantity) {
    for (int i = 0; i < teamQuantity; i++) {            //go through all teams
        int top_scorer = 0;                             //set the first player to be the top scorer so far
        for (int j = 1; j < teamArray[i].num_player; j++) {        //go throuhg all players in current team (besides first one bc unnecessary)
            if (teamArray[i].p[j].ppg > teamArray[i].p[top_scorer].ppg) {           //if this current player's is greater than the top scorer so far, set topscoreplayer to that player's position.
                top_scorer = j;
            }
        }
        cout << teamArray[i].p[top_scorer].name << " is the top scorer of " << teamArray[i].name;//print the top scorer of that team
        cout << " with a score of " << teamArray[i].p[top_scorer].ppg << " points per game. " << endl;
    }
}

void outfile_top_scorers(Team* teamArray, int teamQuantity) {
    ofstream fileOutput;
    cout << "Enter filename for output: ";
	string out_filename;
	cin >> out_filename;
	fileOutput.open(out_filename, ios::app);
    for (int i = 0; i < teamQuantity; i++) {            //go through all teams
        int top_scorer = 0;                             //set the first player to be the top scorer so far
        for (int j = 1; j < teamArray[i].num_player; j++) {        //go throuhg all players in current team (besides first one bc unnecessary)
            if (teamArray[i].p[j].ppg > teamArray[i].p[top_scorer].ppg) {           //if this current player's is greater than the top scorer so far, set topscoreplayer to that player's position.
                top_scorer = j;
            }
        }
        fileOutput << teamArray[i].p[top_scorer].name << " is the top scorer of " << teamArray[i].name;//print the top scorer of that team
        fileOutput << " with a score of " << teamArray[i].p[top_scorer].ppg << " points per game. " << endl;
    }
    cout << "Appended top scorers of every team to file " << out_filename << endl;
}


//11 lines (ignore 4 close brackets)
void cout_search_nationality(Team* teamArray, int teamQuantity) {
    cout << "Enter a nationality to search for: ";
    string input;
    int amountFound = 0; //for if there's zero, we can say nothing found (factors in valid nationality thing)
    cin >> input;
    for (int i = 0; i < teamQuantity; i++) {            //go through all teams
        for (int j = 0; j < teamArray[i].num_player; j++) { //go through all players in current team
            if (teamArray[i].p[j].nation == input) {    //if current player's nationality matches inputted:
                cout << teamArray[i].p[j].name << ", age " << teamArray[i].p[j].age << endl;
                amountFound += 1;
            }
        }
    }
    if (amountFound == 0) {
        cout << "No players of " << input << " nationality found." << endl;
    }
}

//14 lines (ignore 4 variable declarations and 5 curly brackets)
void outfile_search_nationality(Team* teamArray, int teamQuantity) {
    ofstream fileOutput;
    cout << "Enter filename for output: ";
	string out_filename;
	cin >> out_filename;
	fileOutput.open(out_filename, ios::app);
    string input;
    cout << "Enter a nationality to search for: ";
    int amountFound = 0; //for if there's zero, we can say nothing found (factors in valid nationality thing)
    cin >> input;
    for (int i = 0; i < teamQuantity; i++) {            //go through all teams
        for (int j = 0; j < teamArray[i].num_player; j++) { //go through all players in current team
            if (teamArray[i].p[j].nation == input) {    //if current player's nationality matches inputted:
                fileOutput << teamArray[i].p[j].name << ", age " << teamArray[i].p[j].age << endl;
                amountFound += 1;
            }
        }
    }
    if (amountFound == 0) {
        cout << "We made your file but no players of " << input << " nationality found." << endl;
    } else {
        cout << "Appended respected players to file " << out_filename << endl;
    }
}


//Adapted from https://www.geeksforgeeks.org/bubble-sort/ And My Lab 4 (more or less the same kind of function)

void sort_teams(Team* teamArray, int teamQuantity) {
    bool swapped;                       //create boolean early on to check if a current for loop iteration has been swapped yet, and if none stay that way do nothing
    for (int i = 0; i < teamQuantity; i++) { //for all teams
		swapped = false; //initialize this particular team as false swapped.
        for (int j = 0; j < teamQuantity - i - 1; j++) { //basically creates a new variable dependent on i and the full team quantity
            if (teamArray[j].total_ppg < teamArray[j + 1].total_ppg) { //if current team's total ppg is less than next team
                swap(teamArray[j].name, teamArray[j + 1].name);   //swap only the name and ppg (ignore rest)
                swap(teamArray[j].total_ppg, teamArray[j + 1].total_ppg);
                swapped = true;  //will check if anything has been swapped through this if condition
            }
        }
        // If no two elements were swapped
        // by inner loop, then break (written by geeksforgeeks)
        if (swapped == false)
            return;
    }
}

void cout_sort_teams(Team* teamArray, int teamQuantity) {
    sort_teams(teamArray, teamQuantity);//call sortteam function in here
    for (int i = 0; i < teamQuantity; i++) {
        cout << teamArray[i].name << endl;//for all teams, output these two to console:
        cout << teamArray[i].total_ppg << endl;
    }
}
void outfile_sort_teams(Team* teamArray, int teamQuantity) {
    ofstream fileOutput;//same 5 lines for standard making of an ofstream
    cout << "Enter filename for output: ";
	string out_filename;
	cin >> out_filename;
	fileOutput.open(out_filename, ios::app);
    sort_teams(teamArray, teamQuantity);//call sort team function in here
    for (int i = 0; i < teamQuantity; i++) {//for all teams, output these two:
        fileOutput << teamArray[i].name << endl;
        fileOutput << teamArray[i].total_ppg << endl;
    }
    cout << "Appended sorted teams to file " << out_filename << endl;
}



/*
Justification:
This is the most important action of the whole program, after the file's data has been read. What do we do with the read information?

#Needs 4 options of what to do. (Quit is separate, 4th is the extra credit stuff)
For each option, we need minimum 5 lines:
    1. If this option is chosen. (Search by name, find top scorers, etc.)
    2. If the print option is chosen,
    3.     Use print function
    4. If the write to file option is chosen:
    5.    Use write to file function.
                                    (an easier way to do these 5 lines has not been taught to us yet; switch is for ints)
5 * 4 = 20 lines minimum

Search by name function needs an extra 3 to factor in if a team has not been found.

*/

void userInputAction(string option, Team* teamArray, int teamQuantity) {
    if (option == "1") {
        int searchVal = search_by_name(teamArray, teamQuantity);
        if (searchVal == -1) {
            cout << "Team not found." << endl;
            return;
        } else if (writeorprintOption() == "1") {
            cout_search_by_name(searchVal, teamArray);
        } else {
            outfile_search_by_name(searchVal, teamArray);
        }
    } else if (option == "2") {
        if (writeorprintOption() == "1") {
            cout_top_scorers(teamArray, teamQuantity);            //print top scoring players
        } else {
            outfile_top_scorers(teamArray, teamQuantity);           //write top scoring players to file
        }
    } else if (option == "3") {
        if (writeorprintOption() == "1") {
            cout_search_nationality(teamArray, teamQuantity);            //print nationality matches
        } else {
            outfile_search_nationality(teamArray, teamQuantity);           //write top scoring players to file
        }
    } else if (option == "5") {
        if (writeorprintOption() == "1") {
            cout_sort_teams(teamArray, teamQuantity);
        } else {
            outfile_sort_teams(teamArray, teamQuantity);
        }
    } 
}
