#include <iostream>

const int MAX_SIZE = 100;

int main() {

    int minRowIndex = 0;
    int minRowSum = INT_MAX;
    int n, m;
    int A[MAX_SIZE][MAX_SIZE];

    // Ввод размеров матрицы
    std::cout << "Введите количество строк (n <= 100): ";
    std::cin >> n;
    if (n < 1 || n > 100)
    {
        std::cout << "Koличecтвo строк введено некорректно,введите (n <= 100) ";
        std::cin >> n;
    }
    std::cout << "Введите количество столбцов (m <= 100): ";
    std::cin >> m;
    if (n < 1 || n > 100)
    {
        std::cout << "Koличecтвo строк столбцов некорректно,введите (m <= 100) ";
        std::cin >> n;
    }

    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> A[i][j];
        }
    } 
    // Поиск строки с наименьшей суммой элементов
    for (int i = 0; i < n; ++i) {
        int currentRowSum = 0;
        for (int j = 0; j < m; ++j) {
            currentRowSum += A[i][j];
        }
        if (currentRowSum < minRowSum) {
            minRowSum = currentRowSum;
            minRowIndex = i;
        }
    }

    // Замена всех элементов найденной строки на её сумму
    for (int j = 0; j < m; ++j) {
        A[minRowIndex][j] = minRowSum;
    }

    std::cout << "Измененная матрица:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}