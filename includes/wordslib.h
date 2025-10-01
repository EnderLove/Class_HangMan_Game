#ifndef WORDS_LIB_H
#define WORDS_LIB_H

#include <unordered_map>
#include <iostream>
#include <vector>

class WordsLibrary
{
private:
    const char TAG_CHAR = '#';
    std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> data;
    
public: 
    void loadFromFile(const std::string& filepath);
    void showCategories() const;
    void showDifficulties(const std::string& category) const;
    
    std::string getRandomWord(const std::string& category, const std::string& difficulty) const;
};

#endif //!WORDS_LIB_H