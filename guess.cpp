#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));  // random seed
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "===== NUMBER GUESSING GAME =====\n";
    cout << "Guess a number between 1 and 100\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too High!\n";
        } 
        else if (guess < secretNumber) {
            cout << "Too Low!\n";
        } 
        else {
            cout << "Correct! 🎉\n";
            cout << "You guessed it in " << attempts << " attempts.\n";
        }

    } while (guess != secretNumber);

    return 0;
}
