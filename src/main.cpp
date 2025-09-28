#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "hangmangame.h"
#include "wordslib.h"

int main() {
    WordsLibrary wordsLib;
    wordsLib.loadFromFile("../resources/dictionary.txt");
    std::srand(std::time(nullptr));

    std::cout << "Welcome to Hangman!\n";

    wordsLib.showCategories();
    std::cout << "Select a category: ";
    std::string chosenCategory;
    std::getline(std::cin, chosenCategory);

    wordsLib.showDifficulties(chosenCategory);
    std::cout << "Select difficulty: ";
    std::string chosenDifficulty;
    std::getline(std::cin, chosenDifficulty);

    std::string secretWord = wordsLib.getRandomWord(chosenCategory, chosenDifficulty);
    if (secretWord.empty()) {
        std::cout << "No words found for that category and difficulty.\n";
        return 1;
    }

    HangmanGame game(secretWord);
    game.play();

    return 0;
}
