#include <sstream>
#include <fstream>
#include <string>
#include "wordslib.h"

void WordsLibrary::loadFromFile(const std::string& filePath)
{
    std::ifstream stream(filePath);
    if (!stream.is_open())
    {
        std::cerr << "Failed to open " << filePath << std::endl;
        return;
    }

    std::string line;
    std::string currentMainCategory;
    std::string currentDifficulty;

    while (getline(stream, line))
    {
        if (line.empty()) continue;

        if (line[0] == TAG_CHAR)
        {
            std::string tag = line.substr(1);

            if (tag == "EASY" || tag == "MID" || tag == "HARD")
            {
                currentDifficulty = tag;
            }
            else
            {
                currentMainCategory = tag;
                currentDifficulty.clear();
            }
        }
        else if (!currentMainCategory.empty() && !currentDifficulty.empty())
        {
            data[currentMainCategory][currentDifficulty].push_back(line);
        }
    }
}

void WordsLibrary::showCategories() const 
{
    std::cout << "Available categories:\n";
    for (const auto& mainCat : data)
    {
        std::cout << "- " << mainCat.first << "\n";
    }
}

void WordsLibrary::showDifficulties(const std::string& category) const
{
    auto it = data.find(category);
    if (it != data.end())
    {
        std::cout << "Difficulties in " << category << ":\n";
        
        for (const auto& diff : it -> second)
        {
            std::cout << "- " << diff.first << "\n";
        }
    }
    else 
    {
        std::cout << "Category not found\n";
    }
}

std::string WordsLibrary::getRandomWord(const std::string& category, const std::string& difficulty) const
{
    auto catIt = data.find(category);
    if (catIt == data.end()) return "";

    auto diffIt = catIt->second.find(difficulty);
    if (diffIt == catIt->second.end()) return "";

    const auto& words = diffIt->second;
    if (words.empty()) return "";

    int index = rand() % words.size();
    return words[index];
}
