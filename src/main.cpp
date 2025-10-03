#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "hangmangame.h"
#include "wordslib.h"

int main() 
{
    //WE START INSTANTIATING THE OBJ WORDSLIB, LOADING IN IT THE FILE WITH THE DICITONARY AND SETING THE SEED TO THE SRAND FUNCTION
    WordsLibrary wordsLib;
    wordsLib.loadFromFile("../resources/dictionary.txt");
    std::srand(std::time(nullptr));

    //========================  WITH THE DICTIONARY LOADED THEN WE CAN START WITH THE GAME ========================

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
    //game.play();



    enum class MenuOptions {NONE = -1, PLAY, SETTINGS, EXIT};

    MenuOptions mUserOption = MenuOptions::NONE;

    unsigned short int option = 0;

    do
    {
        std::cout << "Welcome to the hangmangame" << std::endl;
        std::cout << "1)Play\n2)Settings\n3)Exit" << std::endl;
        std::cin >> option;
        mUserOption = static_cast<MenuOptions>(option);

    } while (mUserOption != MenuOptions::PLAY && mUserOption != MenuOptions::SETTINGS && mUserOption != MenuOptions::EXIT);
    
    return 0;
}
