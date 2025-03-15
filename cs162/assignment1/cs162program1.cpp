/******************************************************
** Program: hooping.cpp
** Author: Ian McKee
** Date: 10/7/2023
** Description: Programming assignment 1, simulates the NBA 3-Point Contest
** Input:
** Output:
******************************************************/


/*
Current steps:
- move functions to stuff
- fix bugs if there are any for those
*/

#include <iostream>
#include <cmath>

using namespace std;

//userInput function is used for gathering our two int values for money-rack positions the players want.

int userInput() {
    string inputString;
    bool validInput = false;
    int intVal;
    while (!validInput) {
        cout << "Enter player's money-rack choice: ";
        cin >> inputString;
        intVal = stoi(inputString);
        if (intVal < 1 || intVal > 5) {
            cout << "Invalid input. " << endl;
        }
        else {
                validInput = true;
        }
    }
    return intVal;
}

//playAgain function is used at end of main() so we can effectively repeat the game over and over.
void playAgain(bool &play) {
    string answer;
    while (play == true) {
        cout << "Play again? ";
        cin >> answer;
        if (answer == "Yes" || answer == "Y") {
            return;

        } else {
            cout << "Thank you for playing. " << endl;
            play = false;
            return;
        }
    }
}

//storeGamePlay() function takes our player's 2D array storing point values of each rack and position in the rack.

void storeGamePlay(int player[7][5], int rackChoice) {
    int pointValues[4] = {0, 1, 2, 3};
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            player[i][j] = rand() % 2;
            if (player[i][j] == 1) {
                if (i == 2 || i == 4) {
                    if (player[i][0] == 1) player[i][0] = 3;
                    if (j > 0) player[i][j] = 0;
                } else if (j==4 || i == rackChoice) {//for Money racks and Money shots at the end of each Rack
                    player[i][j] = 2;
                } 
                }
        }
            }
}

//calculateBigScore() function takes our player's 2D array representing point values, and adds them all up. Returns an int score.

int calculateBigScore(int player[][5]) {
    int score = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            if (player[i][j] != 0) {
                score += player[i][j];
            }

        }
    }
    return score;
}

//printGameResult function takes our player's 2D array representing point values, and converts 0s, 1s, 2s and 3s to XOMWs. Also keeps track of the rack# to print the context.
//my justification for this taking 27 lines is that the switch() function uses a lot of lines. I also used the Starry in the same array to save # of arrays.

void printGameResult(int player[][5]) {
    int rackNumber = 1;
    for (int i = 0; i < 7; i++) {
        if (i != 2 && i != 4) {
            cout << "Rack " << rackNumber << ": ";
            rackNumber++;
        for (int j = 0; j < 5; j++) {
            switch (player[i][j]) {
            case 0:
                cout << "X ";
                break;
            case 1:
                cout << "O ";
                break;
            case 2:
                cout << "M ";
                break;
            }
            }
         } else {
            cout << "Starry: ";
                if (player[i][0]) {
                    cout << "W";
                } else {
                    cout << "X";
                }
            }
        cout << " |" << endl;
        }
}

//Justification: Over 15 lines because it's the main function. We need a conditional to repeatedly play, and 4 lines to effectively let the players choose their Money Racks.
int main() {
    srand(time(0)); //seed, time since 1/1/70
    bool play = true;
    cout << "Welcome to the basketball shooting contest!!" << endl;
    while (play) {
    int rackChoice[2];//change following 2s to n if we wanted to do many players
    for (int player = 0; player < 2; player++) {
        rackChoice[player] = userInput();
        int scores[2];
        int currentPlayer[7][5];
        storeGamePlay(currentPlayer, rackChoice[player]);
        int finalScore = scores[player] = calculateBigScore(currentPlayer);
        printGameResult(currentPlayer);
        cout << "Score: " << finalScore << " points" << endl;
        if (player == 1) {
            if (scores[1] > scores[0]) cout << "2nd player wins! ";
            else cout << "1st player wins! ";  }
    }
    playAgain(play);
    }
}
