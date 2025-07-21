#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main() {
    int secretNumber, guess;

    // Initialize random seed based on current time
    srand(time(0));

    // Generate random number between 1 and 100
    secretNumber = rand() % 100 + 1;

    cout << "===============================" << endl;
    cout << "    Welcome to Guessing Game!  " << endl;
    cout << "===============================" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Can you guess what it is? Let's try!" << endl;

    // Loop until the correct guess
    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        }
        else {
            cout << "Congratulations! You guessed it right: " << secretNumber << endl;
        }
    } while (guess != secretNumber);

    cout << "===============================" << endl;
    cout << " Thanks for playing! Goodbye!  " << endl;
    cout << "===============================" << endl;

    return 0;
}
