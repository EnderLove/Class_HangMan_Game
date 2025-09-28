#ifndef HANGMAN_GAME_H
#define HANGMAN_GAME_H

#include <iostream>
#include <vector>

class HangmanGame {
private:

    const char EMPTY_CHAR = '_';

    std::string wordToGuess;
    std::string currentGuess;

    int remainingAttempts;
    
    std::vector<char> guessedCharacters;

public:
    HangmanGame(const std::string& word);

    bool checkGameStatus() const;
    bool isCharGuessed(char guess) const;
    void displayStatus() const;
    void guessLetter(char guess);
    void play();
};

#endif //!HANGMAN_GAME_H