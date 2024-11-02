#include <iostream>

using namespace std;

// Функция для проверки, является ли число палиндромом
bool isPalindrome(int num) 
{
    int original = num;
    int reversed = 0;

    while (num > 0) 
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return original == reversed;
}

// Функция для проверки, является ли число простым
bool isPrime(int num)
{
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0) return false;
    }
    return true;
}

int main() 
{
    const int MAX_SIZE = 10000; 
    int sequence[MAX_SIZE]; 
    int n;

    cout << "Введите количество элементов в последовательности (n <= 10000): ";
    cin >> n;
    while (n < 1 || n > 10000)
    {
        cout << "Введите некорректное количество элементов в последовательности \n";
        cout << "Введите количество элементов в последовательности (n <= 10000): ";
        cin >> n;
    }

    cout << "Введите элементы последовательности: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> sequence[i];
    }

    // Массив для хранения результата
    int result[MAX_SIZE];
    int resultSize = 0;

    // Удаляем палиндромы и дублируем простые числа
    for (int i = 0; i < n; ++i)
    {
        if (!isPalindrome(sequence[i]) && isPrime(sequence[i]))
        {
            result[resultSize++] = sequence[i]; 
            result[resultSize++] = sequence[i]; 
        }
    }

    // Выводим результат
    cout << "Полученная последовательность: ";

    for (int i = 0; i < resultSize; ++i)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}
