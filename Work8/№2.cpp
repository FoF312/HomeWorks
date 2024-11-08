#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <cctype>

bool isVowel(char c)
{
    return strchr("aeiouAEIOU", c) != nullptr;
}

int countConsonants(const std::string& word) 
{
    int count = 0;
    for (char c : word)
    {
        if (isalpha(c) && !isVowel(c)) 
        {
            count++;
        }
    }
    return count;
}

std::string processWord(const std::string& word) 
{
    std::string result;
    for (char c : word) 
    {
        if (!isVowel(c)) 
        {
            result += c; // Добавляем согласную
            result += c; // Дублируем согласную
        }
    }
    return result;
}

int main() 
{
    std::string input = "This is an example text with some words"; // Пример текста
    std::istringstream iss(input);
    std::vector<std::string> words;
    std::set<std::string> outputWords;

    // Чтение слов из строки
    std::string word;
    while (iss >> word)
    {
        int consonantCount = countConsonants(word);
        if (consonantCount <= 3) 
        {
            outputWords.insert(word); // Сохраняем слово для вывода
        }
        else
        {
            outputWords.insert(processWord(word)); // Обрабатываем слово
        }
    }

    // Выводим слова в алфавитном порядке
    for (const auto& w : outputWords)
    {
        std::cout << w << std::endl;
    }

    return 0;
}