//Joshua Budd    Lab 2      This program will have 2 players play ticktactoe. First to three in a row wins. 
#include <iostream>
using namespace std;

class TicTacToeGame {
public:

    TicTacToeGame();//Constructor
 
    void playGame();
 
private:
 
    //Gets input from the user
    int getXCoord();
    int getYCoord();

    //Places a marker. If it returns false, it couldnt place!
    bool placeMarker(int x, int y, int currentPlayer);
 
    //Returns true if the current player won!
    bool checkForVictory(int currentPlayer);

    // Prints the board
    void printBoard();
 
    //This stores the board state
    int board[3][3];

};//end TicTacToeGame class definition

TicTacToeGame::TicTacToeGame() { //default constructor

	//populates the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }//end inner for loop

    }//end outer for loop

}//end default constructor

void TicTacToeGame::playGame() {
 
    int player1 = 1;
    int player2 = 2;
 
    int currentPlayer = player1;
    bool isDone = false;
 
    int x, y;
 
    int turn = 0;
 
    //Inner game loop
    while (isDone == false) {
 
        //Print out the board each time we loop
        printBoard();
 
        //Get the coordinates of where the user wants to place a marker
        x = getXCoord();
        y = getYCoord();
 
        //Try to place a marker
        if (placeMarker(x, y, currentPlayer) == false) {
            //If we failed to place a marker, tell him he failed!
            cout << "That spot is occupied!\n";
        } //end if
		else {
            //Otherwise, we successfully did this turn!
            turn++;
            //See if the player won!
            if (checkForVictory(currentPlayer) == true) {
                //He won!
                cout << "The game is over! Player " << currentPlayer << " has won!\n";
                isDone = true;
            }//end if
			else if (turn == 9) {
                //Tie game!
                cout << "Its a tie game!\n";
                isDone = true;
            }//end else if
 
            // Switch players
            if (currentPlayer == player1) {
                currentPlayer = player2;
            } //end if
			else {
                currentPlayer = player1;
            }//end else

        }//end else for successful turn

    }//end while loop for game status

}//end playGame function
 
int TicTacToeGame::getXCoord() {

    bool isInputBad = true;
    int x;
 
    while (isInputBad == true) {
        cout << "Enter the X coordinate: ";
        cin >> x;
 
        if (x < 1 || x > 3) {
            cout << "Invalid Coordinate!\n";
        }//end if
		else {
            isInputBad = false;
        }//end else
    }//end while loop

    return x - 1;

}//end getXCoord function
 
int TicTacToeGame::getYCoord() {

    bool isInputBad = true;
    int y;
 
    while (isInputBad == true) {
        cout << "Enter the Y coordinate: ";
        cin >> y;
 
        if (y < 1 || y > 3) {
            cout << "Invalid Coordinate!\n";
        }//end if statement 
		else {
            isInputBad = false;
        }//end else statement
    }//end while loop

    return y - 1;

}//end getYCoord function
 
bool TicTacToeGame::placeMarker(int x, int y, int currentPlayer) {
    if (board[y][x] != 0) {
        return false;
    }//end if statement
 
    board[y][x] = currentPlayer;
    return true;
}//end placeMarker function
 
bool TicTacToeGame::checkForVictory(int currentPlayer) {
    //Check the rows for winning combinations
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            return true; //We won!
        }//end if

    }//end for
 
    //Check the columns
    for (int i = 0; i < 3; i++) {
        if ((board[0][i] == currentPlayer) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            return true; //We won!
        }//end if
		
    }//end for
 
    //Check top left diagonal
    if ((board[0][0] == currentPlayer) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        return true; //We won!
    }//end if
 
    //Check top right diagonal
    if ((board[2][0] == currentPlayer) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) {
        return true; //We won!
    }//end if
 
    return false;
}//end check for victory function
 
void TicTacToeGame::printBoard() {

    cout << endl;
    cout << " |1 2 3|\n";
    for (int i = 0; i < 3; i++) {
        cout << " -------\n";
        cout << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|\n";
    }//end for statement
    cout << " -------\n";

}//end printBoard function

int main() {

    char input;
    bool isDone = false;
    TicTacToeGame game;   //instanciates a game of tictactoe

	cout << "Welcome to the TicTacToe program game!" << endl;
 
    //Outer Game Loop
    while (isDone == false) {
        //this plays a game of tic tac toe!
        game.playGame();
        // We have to see if they want to play again!
        cout << "Would you like to play again? (Y/N): ";
        cin >> input;
        if (input == 'N' || input == 'n') {
            isDone = true;
        }//end if statement

    }//end while loop
 
    cout << "Thanks for using the TicTacToe game program!" << endl; //closing message

}//end main method