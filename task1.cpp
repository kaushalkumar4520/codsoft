#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    int RandomNumber = rand() % 100 + 1; 
    int guess;
    int attempts = 0;

    cout << "Welcome to the Guessing Game!\n";
    cout << "Think of a number between 1 and 100.\n";

    do{
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > RandomNumber) {
            cout << "Too high! Try again.\n";
        } else if (guess < RandomNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Correct! You guessed the number in " << attempts << " attempts.\n";
        }
    } while (guess != RandomNumber);

    return 0;
}

