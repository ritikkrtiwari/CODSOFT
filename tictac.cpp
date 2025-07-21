#include <iostream>
using namespace std;

char board[3][3]; // game board
char currentPlayer; // 'X' or 'O'

// Function to set up the board
void initBoard() {
    char pos = '1';
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            board[i][j] = pos++;
}

// Function to show the board
void printBoard() {
    cout << "\n";
    for(int i=0; i<3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if(i<2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to check if player wins
bool checkWin() {
    // rows and columns
    for(int i=0; i<3; i++) {
        if(board[i][0]==currentPlayer && board[i][1]==currentPlayer && board[i][2]==currentPlayer)
            return true;
        if(board[0][i]==currentPlayer && board[1][i]==currentPlayer && board[2][i]==currentPlayer)
            return true;
    }
    // diagonals
    if(board[0][0]==currentPlayer && board[1][1]==currentPlayer && board[2][2]==currentPlayer)
        return true;
    if(board[0][2]==currentPlayer && board[1][1]==currentPlayer && board[2][0]==currentPlayer)
        return true;

    return false;
}

// Function to check draw
bool checkDraw() {
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i][j]!='X' && board[i][j]!='O')
                return false;
    return true;
}

// Function to switch player
void switchPlayer() {
    if(currentPlayer=='X')
        currentPlayer='O';
    else
        currentPlayer='X';
}

// Function to make a move
bool makeMove() {
    int choice;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> choice;

    if(choice<1 || choice>9) {
        cout << "Invalid number! Try again.\n";
        return false;
    }

    int row = (choice-1)/3;
    int col = (choice-1)%3;

    if(board[row][col]!='X' && board[row][col]!='O') {
        board[row][col]=currentPlayer;
        return true;
    } else {
        cout << "Cell already taken! Try another.\n";
        return false;
    }
}

int main() {
    char playAgain;

    do {
        initBoard();
        currentPlayer='X';
        bool gameOver=false;

        cout << "=== TIC-TAC-TOE GAME ===\n";
        cout << "Player 1: X  |  Player 2: O\n";

        while(!gameOver) {
            printBoard();

            if(makeMove()) {
                if(checkWin()) {
                    printBoard();
                    cout << "Player " << currentPlayer << " wins! 🎉\n";
                    gameOver=true;
                }
                else if(checkDraw()) {
                    printBoard();
                    cout << "It's a draw! 🤝\n";
                    gameOver=true;
                }
                else {
                    switchPlayer();
                }
            }
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while(playAgain=='y' || playAgain=='Y');

    cout << "Thanks for playing!\n";
    return 0;
}
