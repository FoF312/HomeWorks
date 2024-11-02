#include <iostream>

using namespace std;

// Функция для проверки, является ли число простым
bool isPrime(int num) 
{
    if (num < 2) 
    {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0) 
        {
            return false; 
        }
    }
    return true;
}

// Функция для вычисления произведения элементов строки
long long productOfRow(int matrix[][100], int row, int n)
{
    long long product = 1;
    for (int j = 0; j < n; ++j)
    {
        product *= matrix[row][j];
    }
    return product;
}

// Функция для сортировки строк по произведению элементов
void sortRows(int matrix[][100], int n) 
{
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (productOfRow(matrix, j, n) < productOfRow(matrix, j + 1, n))
            {
                for (int k = 0; k < n; ++k) 
                {
                    swap(matrix[j][k], matrix[j + 1][k]);
                }
            }
        }
    }
}

int main() 
{
    unsigned int n;
    cout << "Введите размерность матрицы n (n <= 100): ";
    cin >> n;
    if (n > 100 || n == 0)
    {
        cout << "Некорректная размерность матрицы,";
        cout << "Введите размерность матрицы n (n <= 100): ";
        cin >> n;
    }

    int matrix[100][100];

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cin >> matrix[i][j];
        }
    }

    // Поиск минимального элемента
    int minElement = INT32_MAX;
    int minCount = 0;
    int primeCount = 0;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (matrix[i][j] == minElement)
            {
                minCount++;
            }
            if (isPrime(abs(matrix[i][j])))
            {
                primeCount++;
            }
            if (matrix[i][j] < minElement)
            {
                minElement = matrix[i][j];
                minCount = 1; // сбрасываем счетчик, так как нашли новый минимум
            }
        }
    }

    // Проверка условий
    if (minCount > 1 && primeCount >= 2) 
    {
        // Сортировка строк по произведению элементов
        sortRows(matrix, n);

        cout << "Упорядоченная матрица:\n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else 
    {
        cout << "Условия для упорядочивания не выполнены." << endl;
    }

    return 0;
}


