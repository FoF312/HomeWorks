#include <iostream>

using namespace std;

int main() {
  
    //Задание 1
    const short zero = 0;
    const short seven = 7;
    const int MassiveLenght = 6;
    int massive[MassiveLenght] = {20,37,80,32,64,107};
    int summ = 0;
    int HighestValue = INT32_MIN;
    int NumberOfHighestValue = 0;
    for (int i = 0; i < MassiveLenght; i++)
    {
        if (massive[i] %10 == 0 || massive[i] % 10 == 7)
        {
            summ += massive[i];
        }
        if (HighestValue < massive[i])
        {
            HighestValue = massive[i];
            NumberOfHighestValue = i;
        }
    }
    cout << "Сумма чисел, оканчивающихся цифрой 0 или 7 = " << summ << endl;
    cout << "Наибольшее число = " << HighestValue << endl;
    cout << "Номер наибольшего числа = " << NumberOfHighestValue << endl;


    // Задание 2
    long long N;
    int sum = 0;
    cout << "Введите натуральное число N (N < 10^9): ";
    cin >> N;

    if (N <= 0 || N >= 1000000000) {
        cout << "Число должно быть натуральным и меньше 10^9." << std::endl;
        return 1; 
    }
    while (N > 0) 
    {
        int digit = N % 10; 
        if (digit % 2 != 0)
        { 
            sum += digit; 
        }
        N /= 10; // Убираем последнюю цифру из числа
    }

    std::cout << "Сумма нечетных цифр: " << sum << std::endl;

    return 0;
}
