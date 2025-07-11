#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    //srand(time(0)); // seed for randomness

    int userFingers, userGuess;
    int computerFingers, computerGuess;
    int userScore = 0, computerScore = 0;
    char playAgain;

    cout << " Welcome to the Game of Morra!\n";
    cout << " Choose 0 to 5 fingers, and guess the total fingers (you + computer).\n";
    cout << "You get a point if your guess is correct. Let's play!\n\n";

    do {
        // User input
        cout << "Enter number of fingers (0-5): ";
        cin >> userFingers;
        while (userFingers < 0 || userFingers > 5) {
            cout << "Invalid! Enter a number between 0 and 5: ";
            cin >> userFingers;
        }

        cout << "Guess the total fingers (0-10): ";
        cin >> userGuess;
        while (userGuess < 0 || userGuess > 10) {
            cout << "Invalid! Enter a number between 0 and 10: ";
            cin >> userGuess;
        }

        // Computer random move
        computerFingers = rand() % 6;
        computerGuess = rand() % 11;

        int total = userFingers + computerFingers;

        cout << "\n Computer showed: " << computerFingers << " fingers\n";
        cout << " Computer guessed: " << computerGuess << endl;
        cout << " Total fingers: " << total << endl;

        // Result
        bool userCorrect = (userGuess == total);
        bool computerCorrect = (computerGuess == total);

        if (userCorrect && !computerCorrect) {
            cout << " You guessed right! +1 point\n";
            userScore++;
        } else if (!userCorrect && computerCorrect) {
            cout << " Computer guessed right. +1 point\n";
            computerScore++;
        } else if (userCorrect && computerCorrect) {
            cout << " Both guessed right. No points.\n";
        } else {
            cout << " No correct guesses. No points.\n";
        }

        cout << " Score -> You: " << userScore << " | Computer: " << computerScore << endl;

        // Ask to play again
        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
        cout << "-----------------------------\n";

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n Final Score -> You: " << userScore << " | Computer: " << computerScore << endl;
    if (userScore > computerScore) cout << " You win the game!\n";
    else if (userScore < computerScore) cout << " Computer wins the game!\n";
    else cout << " It's a tie!\n";

    return 0;
}
