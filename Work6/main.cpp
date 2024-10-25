#include <iostream>

const int MAX_SIZE = 10000;

bool IsPrime(int num)
{
	if (num <= 1)
	{
		return false;
	}
	for (int i = 0; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

void sortDescending(int arr[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j) 
		{
			if (arr[j] < arr[j + 1]) 
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int n;
	int arr[MAX_SIZE];
	bool hasPrime = false;

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
	// Проверяем наличие простых чисел
	for (int i = 0; i < n; ++i) {
		if (IsPrime(arr[i]))
		{
			hasPrime = true;
			break;
		}
	}
	// Если простых чисел нет, сортируем массив
	if (!hasPrime) {
		sortDescending(arr, n);
		std::cout << "Отсортированный массив по невозрастанию:\n";
		for (int i = 0; i < n; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "В последовательности есть простые числа." << std::endl;
	}

	return 0;
}