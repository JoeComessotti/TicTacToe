/* 
* This program is a Tic Tac Toe game that runs in a terminal 
*/

#include <iostream>
#include <string>
using namespace std;

// The currentPlayers (currentPlayer X and currentPlayer O) are represented by numbers (1, and 2)
// This function returns the letter for the currentPlayer integer that is passed as a parameter
string currentPlayerLetter(int currentPlayer){
    if(currentPlayer == 1) {
        return "x";
    }
    return "o";
}

// This function is used to change the current currentPlayer variable to the next currentPlayer
// It is used in the checkWinner function, as well as the Board function
int nextPlayer(int currentPlayer) {
    if(currentPlayer == 1){
        return 2;
    }
    else {
        return 1;
    }
}

// This function is run after each turn
// It checks each possible win case to see if the currentPlayer has any of them, and if they do, the function returns true and outputs a string
// Otherwise it returns false 
// It takes a list of all of the spaces on the board, as well as the current currentPlayer for parameters
bool checkWinner(string spaces[9], int currentPlayer){
    
    int currentcurrentPlayer = nextPlayer(currentPlayer);
    string letter = currentPlayerLetter(currentcurrentPlayer);
    
    if(spaces[0] == letter && spaces[1] == letter && spaces[2] == letter){
        cout << "Player " + to_string(currentcurrentPlayer) + " wins!";
        return true;
    }
    if(spaces[3] == letter && spaces[4] == letter && spaces[5] == letter){
        cout << "Player " + to_string(currentcurrentPlayer) + " wins!";
        return true;
    }
    if(spaces[6] == letter && spaces[7] == letter && spaces[8] == letter){
        cout << "Player " + to_string(currentcurrentPlayer) + " wins!";
        return true;
    }
    if(spaces[0] == letter && spaces[3] == letter && spaces[6] == letter){
        cout << "Player " + to_string(currentcurrentPlayer) + " wins!";
        return true;
    }
    if(spaces[1] == letter && spaces[4] == letter && spaces[7] == letter){
        cout << "Player " + to_string(currentcurrentPlayer) + " wins!";
        return true;
    }
    if(spaces[2] == letter && spaces[5] == letter && spaces[8] == letter){
        cout << "Player " + to_string(currentcurrentPlayer) + " wins!";
        return true;
    }
    if(spaces[0] == letter && spaces[4] == letter && spaces[8] == letter){
        cout << "Player " + to_string(currentcurrentPlayer) + " wins!";
        return true;
    }
    if(spaces[2] == letter && spaces[4] == letter && spaces[6] == letter){
        cout << "Player " + to_string(currentcurrentPlayer) + " wins!";
        return true;
    }
    return false;
}

// This function draws the board at each turn, and checks if there is a winner
int board(){ 
    // These two variables are a list of the all of the spaces (The strings are empty here, but are updated to contain whatever letter is on that space)
    // And a boolean array of the spaces communicates whether or not that space is taken
    string spaces[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
    bool takenSpaces[9] = {false, false, false, false, false, false, false, false, false};
    
    int currentPlayer = 1;
    string selection;
    
    while(true){
        cout << "Player " + to_string(currentPlayer) + ", what space would you like? (1-9): ";
        getline(cin, selection);
        // The selection variable has a 1 subtracted from it to make gameplay a little less confusing
        // This way, the currentPlayer can choose from numbers 1-9 instead of 0-8 (because of array index)
        int select = stoi(selection) - 1;
        
        // This if statement checks if the selected space is already taken
        // if not, then that space is now equal to the currentPlayers letter
        if(!takenSpaces[select]){
            spaces[select] = currentPlayerLetter(currentPlayer);
            takenSpaces[select] = true;
            currentPlayer = nextPlayer(currentPlayer);
        } else {
            cout << "This place is already takenSpaces, try again." << endl;
        }
        

        // Draws the board, with all of the moves so far
        cout << " " << spaces[0] <<" | "<< spaces[1] <<" | "<< spaces[2] <<" " << endl;
        cout << "---|---|---" << endl;
        cout << " " << spaces[3] <<" | "<< spaces[4] <<" | "<< spaces[5] <<" " << endl;
        cout << "---|---|---" << endl;
        cout << " " << spaces[6] <<" | "<< spaces[7] <<" | "<< spaces[8] <<" " << endl;
        
        // If there is a winner, end the loop
        if(checkWinner(spaces, currentPlayer)){
            break;
        }
    }
    return 0;
}
int main(){
    //Before calling the board function, this is outputted to show the players what spaces the numbers represent
    cout << " 1 | 2 | 3 " << endl;
    cout << "---|---|---" << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << "---|---|---" << endl;
    cout << " 7 | 8 | 9 " << endl;

    // Calls the board function to start the game
    board();
    return 0;
}