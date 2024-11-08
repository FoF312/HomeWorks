#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) 
    {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    std::string line;
    std::regex repeatedLetterRegex(R"(\b(\w*?(\w)\2\w*?)\b)");

    // Читаем файл построчно
    while (std::getline(inputFile, line))
    {
        std::string modifiedLine = line;

        // Используем регулярное выражение для поиска слов с повторяющимися буквами
        std::smatch match;
        while (std::regex_search(modifiedLine, match, repeatedLetterRegex))
        {
            std::string foundWord = match[0];
            char repeatedChar = match[2].str()[0];

            // Формируем новое слово
            std::string newWord = foundWord;
            std::transform(newWord.begin(), newWord.end(), newWord.begin(), ::toupper); // Преобразуем в верхний регистр
            newWord += " (" + std::string(1, repeatedChar) + ")"; // Добавляем букву в скобках

            // Заменяем слово в строке
            modifiedLine.replace(match.position(0), foundWord.length(), newWord);
        }

        // Записываем измененную строку в выходной файл
        outputFile << modifiedLine << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}