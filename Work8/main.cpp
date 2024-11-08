#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

bool isConsonantsOrdered(const std::string& word) 
{
    std::string consonants;
    for (char c : word)
    {
        if (isalpha(c) && !strchr("aeiouAEIOU", c))
        {
            consonants += c;
        }
    }
    return std::is_sorted(consonants.begin(), consonants.end());
}

int main() 
{
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    std::vector<std::string> words;
    std::set<std::string> uniqueWords;
    std::string line;

    // Чтение файла и обработка слов
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) 
        {
            if (isConsonantsOrdered(word))
            {
                uniqueWords.insert(word);
            }
        }
    }

    // Перенос уникальных слов в вектор
    for (const auto & word : uniqueWords)
    {
        words.push_back(word);
    }

    // Сортировка слов по длине
    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b)
    {return a.length() > b.length(); });

    // Записываем N самых длинных слов в выходной файл
    int N = 2000; // Максимальное количество слов
    for (int i = 0; i < N && i < words.size(); ++i) {
        outputFile << words[i] << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}