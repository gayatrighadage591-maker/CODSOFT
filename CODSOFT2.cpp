#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Function to initialize the board
void initializeBoard() {
    char start = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = start++;
        }
    }
}

// Function to display the board
void displayBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2) cout << " | ";
        }
        if(i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

// Function to switch player
void switchPlayer() {
    if(currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

// Function to check win
bool checkWin() {
    // Check rows and columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

// Function to check draw
bool checkDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

// Function to make a move
void makeMove() {
    int choice;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        makeMove();
    } else {
        board[row][col] = currentPlayer;
    }
}

int main() {
    char playAgain;

    do {
        initializeBoard();
        currentPlayer = 'X';
        bool gameWon = false;

        while(true) {
            displayBoard();
            makeMove();

            if(checkWin()) {
                displayBoard();
                cout << "🎉 Player " << currentPlayer << " wins!\n";
                gameWon = true;
                break;
            }

            if(checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
