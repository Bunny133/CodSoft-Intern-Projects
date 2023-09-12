#include <iostream>
#include <cstdlib>

using namespace std;
int main()
{

    int secretNumber = rand() % 100 + 1;

    int attempts = 0;
    int guess;
    cout << "************************************************************" << endl;
    cout << "********Welcome to the Number Guessing Game !! *************" << endl;

    cout << "************************************************************" << endl
         << endl;
    cout << "I have selected a random number between 1 and 100." << endl;

    do
    {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber)
        {
            cout << "Too low! Try again." << std::endl;
        }
        else if (guess > secretNumber)
        {
            cout << "Too high! Try again." << std::endl;
        }
        else
        {
            cout << "Congratulations! You guessed the secret number " << secretNumber << " in " << attempts << " attempts." << endl;
        }
    } while (guess != secretNumber);

    return 0;
}
