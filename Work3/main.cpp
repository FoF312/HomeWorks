#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int x, i;

// Ввод числа x и индекса i
std::cout << "Enter number x (0 < x < 10^9): ";
std::cin >> x;
//Проверка числа
if (x <= 0 || x >= 1000000000) {
    std::cerr << "Error: x must be in range(0, 10^9)." << std::endl;
    return 1;
}
std::cout << "Enter bit index i (starting from 0): ";
std::cin >> i;
// Устанавливаем i-ый бит в 1
x |= (1 << i);
// Вывод результата
std::cout << "Number after setting the " << i << "-th bit to 1: " << x << std::endl;
system("pause");
    return 0;
}

