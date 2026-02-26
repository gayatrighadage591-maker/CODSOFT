#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "--- Welcome to the Number Guessing Game!---" << endl;
    cout << "I have selected a number between 1 and 100." << endl;

    do {
        cout << "\nEnter your guess: ";
        
        cin >> guess;

        
        if (guess >100 || guess < 1) {
            cout << " Error: Please enter a number between 1 and 100 only!";
            continue;  
        }

        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again.";
        }
        else if (guess < secretNumber) {
            cout << "Too low! Try again.";
        }
        else {
            cout << "\n🎉 Congratulations! You guessed the number in "
                 << attempts << " attempts.";
        }

    } while (guess != secretNumber);

    return 0;
}
