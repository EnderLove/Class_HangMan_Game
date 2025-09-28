#include <iostream>
#include "hangmangame.h"

HangmanGame::HangmanGame(const std::string& word) : wordToGuess(word), remainingAttempts(7), guessedCharacters() 
{
    currentGuess.resize(word.size());
    for (size_t i = 0; i < word.size(); ++i) 
    {
        if (word[i] == ' ')
            currentGuess[i] = ' ';
        else
            currentGuess[i] = EMPTY_CHAR;
    }
}

bool HangmanGame::checkGameStatus() const 
{
    if (currentGuess.find(EMPTY_CHAR) == std::string::npos)
    {
        std::cout << "YOU WIN!!! THE WORD IS: " << wordToGuess << "\n";
        return true;
    }
    if (remainingAttempts <= 0)
    {
        std::cout << "YOU LOSE!!! THE WORD WAS: " <<wordToGuess << "\n";
        return true;
    }
    return false;
}

bool HangmanGame::isCharGuessed(char guess) const
{
    for (char c : guessedCharacters)
    {
        if (c == guess) return true;
    }
    return false;
}

void HangmanGame::displayStatus() const
{
    std::cout << "Word: " << currentGuess << "\n";
    std::cout << "Remaining Attempts: " << remainingAttempts << "\n";
    std::cout << "Guessed letters: ";
    
    for (char c : guessedCharacters) std::cout << c << " ";
    std::cout << "\n";
}

void HangmanGame::guessLetter(char guess)
{
    if (isCharGuessed(guess))
    {
        std::cout << "YOU ALREADY GUESSED THAT LETTER... TRY AGAIN\n";
        return;
    }

    guessedCharacters.push_back(guess);

    bool correct = false;
    for (size_t i = 0; i < wordToGuess.size(); i++)
    {
        if (wordToGuess[i] == guess)
        {
            currentGuess[i] = guess;
            correct = true;
        }
    }

    if (!correct)
    {
        --remainingAttempts;
        std::cout << "Wrong guess\n";
    }
    else
    {
        std::cout << "Correct guess\n";
    }
}

void HangmanGame::play()
{
    while (!checkGameStatus())
    {
        displayStatus();

        std::cout << "Guess a character: ";
        char guess;
        std::cin >> guess;
        guess = std::tolower(guess);

        guessLetter(guess);
        std::cout << "-------------------------------\n";
    }
}