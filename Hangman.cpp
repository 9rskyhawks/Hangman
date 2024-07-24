#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to draw the hangman's gallows
void drawGallows(int lives) {
    switch (lives) {
        case 6:
            cout << " +---+ \n";
            cout << " |   | \n";
            cout << "     | \n";
            cout << "     | \n";
            cout << "     | \n";
            cout << "     | \n";
            break;
        case 5:
            cout << " +---+ \n";
            cout << " |   | \n";
            cout << " O   | \n";
            cout << "     | \n";
            cout << "     | \n";
            cout << "     | \n";
            break;
        case 4:
            cout << " +---+ \n";
            cout << " |   | \n";
            cout << " O   | \n";
            cout << " |   | \n";
            cout << "     | \n";
            cout << "     | \n";
            break;
        case 3:
            cout << " +---+ \n";
            cout << " |   | \n";
            cout << " O   | \n";
            cout << " /|   | \n";
            cout << "     | \n";
            cout << "     | \n";
            break;
        case 2:
            cout << " +---+ \n";
            cout << " |   | \n";
            cout << " O   | \n";
            cout << " /|\\  | \n";
            cout << "     | \n";
            cout << "     | \n";
            break;
        case 1:
            cout << " +---+ \n";
            cout << " |   | \n";
            cout << " O   | \n";
            cout << " /|\\  | \n";
            cout << " /    | \n";
            cout << "     | \n";
            break;
        case 0:
            cout << " +---+ \n";
            cout << " |   | \n";
            cout << " O   | \n";
            cout << " /|\\  | \n";
            cout << " / \\  | \n";
            cout << "     | \n";
            break;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    // List of words to guess from
    vector<string> words = {"apple", "banana", "cherry", "date", "elderberry"};

    // Choose a random word from the list
    string word = words[rand() % words.size()];

    int lives = 6; // Number of lives the player has
    string guess; // The player's guess
    string guessedWord(word.size(), '_'); // The word with guessed letters filled in

    cout << "Welcome to Hangman! I'm thinking of a word that is " << word.size() << " letters long.\n";

    while (lives > 0) {
        cout << "\n" << guessedWord << "\n";
        drawGallows(lives);
        cout << "Guess a letter: ";
        cin >> guess;

        if (guess.size() != 1) {
            cout << "Please guess one letter at a time.\n";
            continue;
        }

        bool correctGuess = false;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == guess[0]) {
                guessedWord[i] = guess[0];
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            lives--;
            cout << "Oops, that letter is not in my word. You have " << lives << " lives left.\n";
        }

        // Check if the player has guessed the word
        if (guessedWord == word) {
            cout << "\nCongratulations, you guessed my word! You won!\n";
            return 0;
        }
    }

    // The player has run out of lives
    cout << "\nSorry, you didn't guess my word. The word was " << word
