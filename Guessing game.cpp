#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void playGame() 
{
    int guess;
    int num = 0;
    int attempts = 4;

    srand(time(0));

    guess = rand() % 100 + 1;
    cout << "\n\n\t\t\t\t\tWELCOME TO THE NUMBER GUESSING GAME!!\n\n" << endl;
    cout << "\t**Guess a number between 1 and 100**\n\n" << endl;
    do {
        cout << "The turns remaining = " << attempts + 1 << endl;
        cin >> num;
        if (num == guess) {
            cout << "Congratulations!!\nYou guessed the number " << endl;
            return;
        } else if (num < guess) {
            cout << "The guess is too low!" << endl;
        } else if (num > guess) {
            cout << "The guess is too high!" << endl;
        }
    } while (attempts--);

    cout << "Better luck next time." << endl;
}

int main() 
{
    char choice;
    do 
	{
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for playing the Number Guessing Game!" << endl;

    return 0;
}

