#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Include this header for std::find

std::string chooseWord()
{
    std::vector<std::string> words = {"programming", "hangman", "computer", "algorithm", "developer"};
    srand(time(0));
    return words[rand() % words.size()];
}

void displayWord(const std::string &word, const std::vector<char> &guessedLetters)
{
    for (char letter : word)
    {
        if (std::find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end())
        {
            std::cout << letter << " ";
        }
        else
        {
            std::cout << "_ ";
        }
    }
    std::cout << "\n";
}

bool isWordGuessed(const std::string &word, const std::vector<char> &guessedLetters)
{
    for (char letter : word)
    {
        if (std::find(guessedLetters.begin(), guessedLetters.end(), letter) == guessedLetters.end())
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string word = chooseWord();
    std::vector<char> guessedLetters;
    int attempts = 6;

    std::cout << "Welcome to Hangman!\n";
    while (attempts > 0)
    {
        std::cout << "\nAttempts left: " << attempts << "\n";
        displayWord(word, guessedLetters);

        char guess;
        std::cout << "Enter a letter: ";
        std::cin >> guess;

        if (std::find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end())
        {
            std::cout << "You already guessed that letter!\n";
            continue;
        }

        guessedLetters.push_back(guess);

        if (word.find(guess) == std::string::npos)
        {
            attempts--;
            std::cout << "Incorrect guess!\n";
        }

        if (isWordGuessed(word, guessedLetters))
        {
            std::cout << "Congratulations! You guessed the word: " << word << "\n";
            break;
        }
    }

    if (attempts == 0)
    {
        std::cout << "You lost! The word was: " << word << "\n";
    }

    return 0;
}