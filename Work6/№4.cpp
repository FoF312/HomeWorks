#include <iostream>

const int MAX_SIZE = 10000;

bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;

    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    int arr[MAX_SIZE];


    std::cout << "Введите количество элементов последовательности (n <= 10000): ";
    std::cin >> n;
    if (n < 1 || n > MAX_SIZE)
	{
		std::cout << "Некорректное значение повторите ввод";
		std::cin >> n;
	}

    std::cout << "Введите элементы последовательности:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int newIndex = 0;

    // Обработка элементов массива
    for (int i = 0; i < n; ++i) {
        if (!isPalindrome(arr[i]))
        { 
            arr[newIndex++] = arr[i]; 

            if (isPrime(arr[i]))
            { 
                arr[newIndex++] = arr[i]; 
            }
        }
    }

    std::cout << "Полученная последовательность:\n";
    for (int i = 0; i < newIndex; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}