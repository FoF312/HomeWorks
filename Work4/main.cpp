#include <iostream>

using namespace std;

int main() {
    // Задание 1
    int A;
    int B;
    int C;
    cout << "Введите натуральные числа A, B и C: ";
    cin >> A >> B >> C;

    // Проверка условий и вывод результата
    if ((A + B) % C == 0) {
        if (C % B == 0) {
            cout << (A + B) / C - C / B << endl;
        }
        else {
            cout << (A + B) / C + B * C << endl;
        }
    }
    else {
        cout  << A - B + C << endl;
    }

    //Задание 2

     // Ввод числа N, обозначающего ошибку
    int N;
    cin >> N;

    // Обработка ошибок с помощью оператора switch
    switch (N) {
    case 0:
        cout << "Всё хорошо" << endl;
        break;
    case 1:
        cout << "Ошибка чтения файла" << endl;
        break;
    case 2:
        cout << "Ошибка записи файла" << endl;
        break;
    case 3:
        cout << "He все поля определены" << endl;
        break;
    default:
        cout << "Неизвестный код ошибки" << endl;
        break;
    }

    //Задание 3

    int x;
    cin >> x;
    // Обработка ошибок с помощью оператора switch
    switch (x)
    {
    case -1:
            cout << "Negative number" << endl;
            break;
    case 1:
           cout << "Positive number" << endl;
           break;
    default:
        cout << "Invalid input, please enter -1 or 1" << endl;
        break;
    }  
    return 0;
}

