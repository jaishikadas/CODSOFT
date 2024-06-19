#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void playGame(int maxattempts) {
    srand(time(0));
    int secretnumber = 1 + (rand() % 100); 
    int playerChoice;
    for (int i = 1; i <= maxattempts; i++) {
        cout << "\nEnter your guess: ";
        cin >> playerChoice;
        if (playerChoice == secretnumber)
        {
            cout << "You won the game and " << playerChoice << " is the secret number that you find" << endl<< "Thanks for playing! Play the game again with us!!\n\n";
            return;
        } 
        else 
        {
            cout << "Nope " << playerChoice << " is not the right number\n";
            if (playerChoice > secretnumber) {
                cout << "The secret number is smaller than the number you entered" << endl;
            } else {
                cout << "The secret number is greater than the number you entered" << endl;
            }
            cout << maxattempts - i << " attempts left." << endl;
        }
    }
    cout << "You couldn't find the secret number. It was " << secretnumber << ". You lose!!\n\n";
    cout << "Play the game again to win!!!\n\n";
}
int main() {
    cout << "Welcome to [THE NUMBER GUESSING GAME]!" << endl;
    cout << "Guess a number between 1 and 100" << endl;
    while (true) {
        cout << "\nEnter the difficulty level:\n";
        cout << "[Press 1 for EASY level]\t\t\t [Press 2 for MEDIUM level]\t\t\t [Press 3 for HARD level]\t\t\t [Press 0 for ENDING THE GAME]\n";
        cout << "Enter which level you want to play : ";
        int Choice;
        cin >> Choice;
        switch (Choice) {
            case 1:cout << "\nYou have 10 attempts to find the secret number between 1 and 100." << endl;
                playGame(10);
                break;
            case 2:cout << "\nYou have 7 attempts to find the secret number between 1 and 100." << endl;
                playGame(7);
                break;
            case 3:cout << "\nYou have 5 attempts to find the secret number between 1 and 100." << endl;
                playGame(5);
                break;
            case 0:cout << "Thanks for playing The game" << endl;
                return 0;
            default:cout << "Invalid choice , Please enter a valid option (0, 1, 2, 3)." << endl;
        }
    }
    return 0;
}
