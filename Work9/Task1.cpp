#include <iostream>
#include "Task1.h"

void printByteInBinary(unsigned char byte)
{
    for (int i = 7; i >= 0; --i)
    { 
        // Проверяем, установлен ли i-й бит
        if (byte & (1 << i))
        {
            std::cout << '1'; // Если установлен, выводим '1'
        }
        else
        {
            std::cout << '0'; // Если не установлен, выводим '0'
        }
    }
    std::cout << std::endl; // Переход на новую строку после вывода байта
}

void Task1()
{
    unsigned short number;
    std::cout << "Enter a number (0 - 65535): ";
    std::cin >> number;
    
    // Создаем указатель на unsigned char, чтобы работать с байтами
    unsigned char* bytePointer = (unsigned char*)&number;

    std::cout << "Contents of the number bytes " << number << ":" << std::endl;

    // Мы знаем, что unsigned short всегда занимает 2 байта
    for (int i = 0; i < 2; ++i) 
    {
        std::cout << "byte " << i << ": ";
        printByteInBinary(bytePointer[i]);
    }
}