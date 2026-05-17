#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// Global variables for game state
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;

// Arrays to track the snake's tail coordinates
int tailX[100], tailY[100];
int nTail;

// Enumeration for direction
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

// Function to initialize or reset the game state
void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail = 0;
}

// Function to draw the game board
void Draw() {
    system("cls"); // Clears the console screen

    // Top border
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // Game board
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Left border
            if (j == 0)
                cout << "#";

            // Snake head
            if (i == y && j == x)
                cout << "O";
            // Fruit
            else if (i == fruitY && j == fruitX)
                cout << "F";
            // Empty space and Snake tail
            else {
                bool printTail = false;
                // Loop through the tail array to check if a segment is at this position
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        printTail = true;
                    }
                }
                // If it's not a tail segment, print empty space
                if (!printTail)
                    cout << " ";
            }

            // Right border
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    // Bottom border
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    
    // Display score and controls
    cout << "Score: " << score << endl;
    cout << "Controls: W (Up), A (Left), S (Down), D (Right), X (Quit Game)" << endl;
}

// Function to handle user input
void Input() {
    if (_kbhit()) { // If a key is pressed
        switch (_getch()) {
        case 'a':
            if (dir != RIGHT) dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT) dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN) dir = UP;
            break;
        case 's':
            if (dir != UP) dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

// Function to handle the game logic (movement, collisions, eating)
void Logic() {
    // Logic to move the tail
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Logic to move the head
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // Loss Detection: Hitting the wall
    if (x >= width || x < 0 || y >= height || y < 0) {
        gameOver = true;
    }

    // Loss Detection: Hitting your own tail
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = true;
        }
    }

    // Win/Progression logic: Eating the fruit
    if (x == fruitX && y == fruitY) {
        score += 10;
        // Generate new fruit inside boundaries
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++; // Increase snake length
    }
}

int main() {
    char replayChoice;

    do {
        Setup(); // Initialize the game
        
        // Main Game Loop
        while (!gameOver) {
            Draw();
            Input();
            Logic();
            Sleep(50); // Slows down the game loop (50 milliseconds)
        }

        // Game Over Screen
        system("cls");
        cout << "=========================" << endl;
        cout << "       GAME OVER!        " << endl;
        cout << "   Final Score: " << score << endl;
        cout << "=========================" << endl;

        // Replay Option
        cout << "\nWould you like to play again? (Y/N): ";
        cin >> replayChoice;

    } while (replayChoice == 'Y' || replayChoice == 'y');

    cout << "Thanks for playing!" << endl;
    return 0;
}