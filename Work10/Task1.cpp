#include <iostream>
#include <vector>
#include "Task1.h"

// Функция для проверки наличия хотя бы одной из цифр 2, 4 или 6
bool containsDigits246(int number) 
{
    while (number > 0) 
    {
        int digit = number % 10; 
        if (digit == 2 || digit == 4 || digit == 6) 
        {
            return true; 
        }
        number /= 10; 
    }
    return false;
}

// Функция для проверки, отсортирован ли массив
bool isSorted(const std::vector<int>& numbers)
{
    for (size_t i = 1; i < numbers.size(); ++i) 
    {
        if (numbers[i] < numbers[i - 1]) 
        {
            return false; 
        }
    }
    return true;
}

// Функция сортировки выбором
void selectionSort(std::vector<int>& numbers)
{
    int n = numbers.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (numbers[j] < numbers[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(numbers[i], numbers[minIndex]);
    }
}

// Функция для обработки чисел: фильтрация и дублирование
void processNumbers(std::vector<int>& numbers) 
{
    std::vector<int> result;

    for (int number : numbers)
    {
        // Проверяем наличие цифр 2, 4 или 6
        if (containsDigits246(number))
        {
            result.push_back(number);

            // Проверяем наличие цифр 6 или 9 для дублирования
            int temp = number;
            bool has6Or9 = false;
            while (temp > 0)
            {
                int digit = temp % 10;
                if (digit == 6 || digit == 9) 
                {
                    has6Or9 = true; 
                    break; 
                }
                temp /= 10; 
            }
            if (has6Or9)
            {
                result.push_back(number); 
            }
        }
    }
    numbers = result; 
}

void Task1() 
{
    int n;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> numbers(n);

    std::cout << "Enter a sequence of natural numbers:" << std::endl;
    for (int& number : numbers)
    {
        std::cin >> number;
    }

    if (isSorted(numbers))
    {
        std::cout << "The list is sorted by the first or last digit." << std::endl;
        processNumbers(numbers);
        std::cout << "Filtered and duplicated list:" << std::endl;
    }
    else 
    {
        std::cout << "The list is not sorted. Sorting it now." << std::endl;
        processNumbers(numbers); // Обрабатываем числа после сортировки
        selectionSort(numbers); // Сортируем массив методом выбора    
    }

    for (int number : numbers) 
    {
        std::cout << number << " -> ";
    }
    std::cout << "nullptr" << std::endl;

}