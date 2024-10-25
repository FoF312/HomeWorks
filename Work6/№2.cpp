#include <iostream>

const int MAX_SIZE = 1000;

// Функция для получения первой цифры числа
int getFirstDigit(int num) {
    num /= 10;
    return num;
}

// Функция для получения наименьшей цифры числа
int getMinDigit(int num) {
    int minDigit = 9; 
    while (num > 0) {
        int digit = num % 10;
        if (digit < minDigit) {
            minDigit = digit;
        }
        num /= 10;
    }
    return minDigit;
}

// Функция для сортировки массива
void customSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i)
   {
        for (int j = 0; j < n - i - 1; ++j) 
		{
            int firstDigitA = getFirstDigit(arr[j]);
            int firstDigitB = getFirstDigit(arr[j + 1]);
            int minDigitA = getMinDigit(arr[j]);
            int minDigitB = getMinDigit(arr[j + 1]);

            // Сравнение по первой цифре
            if (firstDigitA > firstDigitB || (firstDigitA == firstDigitB && minDigitA > minDigitB) 
                || (firstDigitA == firstDigitB && minDigitA == minDigitB && arr[j] > arr[j + 1])) 
            {                            
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n;
    int arr[MAX_SIZE];

    std::cout << "Введите количество элементов последовательности (n <= 1000): ";
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
    customSort(arr, n);
    std::cout << "Отсортированный массив:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}