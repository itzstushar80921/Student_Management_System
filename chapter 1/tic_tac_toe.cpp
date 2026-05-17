#include <iostream>
#include <cstdlib> // Included for system("cls")

using namespace std;

// Global 2D array to represent the 3x3 board
char board[3][3];
int currentPlayer;
char currentMarker;

// Function to initialize or reset the game board for replays
void setupGame() {
    char slotNumber = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = slotNumber++;
        }
    }
    currentPlayer = 1;
    currentMarker = 'X';
}

// Function to draw the dynamic game board
void drawBoard() {
    system("cls"); // Clears the console screen (Windows)
    // Use system("clear") instead if you are on Mac/Linux

    cout << "=======================\n";
    cout << "      TIC TAC TOE      \n";
    cout << "=======================\n\n";
    cout << " Player 1 (X)  -  Player 2 (O)\n\n";

    cout << "       |       |       \n";
    cout << "   " << board[0][0] << "   |   " << board[0][1] << "   |   " << board[0][2] << "   \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |       \n";
    cout << "   " << board[1][0] << "   |   " << board[1][1] << "   |   " << board[1][2] << "   \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |       \n";
    cout << "   " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << "   \n";
    cout << "       |       |       \n\n";
}

// Function to place a marker on the board
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    // Check if the slot is not already taken by 'X' or 'O'
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

// Function to check all win conditions
bool checkWin() {
    // Check Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
    }
    // Check Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // Check Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

// Function to swap the active player
void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
        currentPlayer = 2;
    } else {
        currentMarker = 'X';
        currentPlayer = 1;
    }
}

int main() {
    char replayChoice;

    do {
        setupGame();
        int turnsTaken = 0;
        bool gameWon = false;

        // Main game loop for a single round
        while (!gameWon && turnsTaken < 9) {
            drawBoard();
            
            cout << "Player " << currentPlayer << "'s turn (" << currentMarker << ")." << endl;
            cout << "Enter a slot number (1-9): ";
            
            int slot;
            cin >> slot;

            // Conditional Logic: Input Validation
            if (slot < 1 || slot > 9) {
                cout << "Invalid slot! Press Enter to try again.";
                cin.ignore(); cin.get(); // Pauses for user
                continue;
            }

            // Conditional Logic: Check if spot is empty
            if (!placeMarker(slot)) {
                cout << "That slot is already occupied! Press Enter to try again.";
                cin.ignore(); cin.get();
                continue;
            }

            turnsTaken++;
            gameWon = checkWin();

            if (!gameWon) {
                swapPlayerAndMarker();
            }
        }

        // Game Over Screen
        drawBoard();
        cout << "=======================\n";
        if (gameWon) {
            cout << " WINNER: Player " << currentPlayer << " (" << currentMarker << ")!\n";
        } else {
            cout << " DRAW: No winner this time!\n";
        }
        cout << "=======================\n";

        // Replay Logic
        cout << "\nWould you like to play again? (Y/N): ";
        cin >> replayChoice;

    } while (replayChoice == 'Y' || replayChoice == 'y');

    cout << "Thanks for playing!" << endl;
    return 0;
}