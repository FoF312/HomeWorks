#include <iostream>
#include "Task1.h"

struct Node 
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insert(int val) 
    {
        Node* newNode = new Node(val);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp->next) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print()
    {
        Node* temp = head;
        while (temp)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    bool isSortedByFirstOrLastDigit()
    {
        if (!head || !head->next) return true; // Пустой или один элемент
        Node* current = head;

        int firstDigit = getFirstDigit(current->data);
        int lastDigit = getLastDigit(current->data);

        while (current->next) 
        {
            current = current->next;
            if (getLastDigit(current->data) < lastDigit || getFirstDigit(current->data) < firstDigit)
            {
                return false; // Если порядок нарушен
            }
            lastDigit = getLastDigit(current->data); // Обновляем последнюю цифру
            firstDigit = getFirstDigit(current->data); // Обновляем первую цифру
        }
        return true; // Если все проверки пройдены
    }

    void processList() 
    {
        if (isSortedByFirstOrLastDigit())
        {
            removeNumbersWithout246();
            duplicateNumbersWith69(); // Дублируем числа с 6 и 9
        }
        else         
        {
            sortList();
        }
    }

private:
    int getFirstDigit(int num)
    {
        while (num >= 10) num /= 10; // Уменьшаем число до первой цифры
        return num;
    }

    int getLastDigit(int num)
    {
        return num % 10; // Последняя цифра
    }

    void removeNumbersWithout246() 
    {
        Node* current = head;
        Node* prev = nullptr;

        while (current) 
        {
            if (!contains246(current->data)) 
            { // Удаляем числа, не содержащие 2, 4 или 6
                if (prev)
                {
                    prev->next = current->next; // Удаление узла
                    delete current;
                    current = prev->next; // Продолжаем с текущего узла
                }
                else 
                { 
                    head = current->next;
                    delete current;
                    current = head;
                }
            }
            else 
            {
                prev = current; // Переход к следующему узлу
                current = current->next;
            }
        }
    }

    bool contains246(int num)
    {
        while (num > 0) 
        {
            int digit = num % 10;
            if (digit == 2 || digit == 4 || digit == 6) return true; // Проверка на наличие цифр 2, 4 или 6
            num /= 10; 
        }
        return false; 
    }

    void duplicateNumbersWith69()
    {
        Node* current = head;

        while (current) 
        {
            if (contains6or9(current->data)) // Проверка на наличие цифр 6 и 9
            {                                                
                Node* newNode = new Node(current->data);
                newNode->next = current->next; // Вставляем новый узел после текущего
                current->next = newNode;
                current = newNode; // Переход к новому узлу
            }
            current = current->next; 
        }
    }

    bool contains6or9(int num)
    {
        while (num > 0) 
        {
            int digit = num % 10;
            if (digit == 6 || digit == 9) return true; // Проверка на наличие цифр 6 или 9
            num /= 10; 
        }
        return false; 
    }

    void sortList()
    {
        if (!head || !head->next) return; // Если список пуст или содержит один элемент

        int size = 0;
        Node* temp = head;

        while (temp) 
        {
            size++;
            temp = temp->next;
        }

        int* values = new int[size];

        temp = head;
        for (int i = 0; i < size; i++)
        {
            values[i] = temp->data;
            temp = temp->next;
        }

        // Сортируем массив значений 
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (values[j] > values[j + 1])
                {
                    std::swap(values[j], values[j + 1]); 
                }
            }
        }

        // Обновляем список на основе отсортированных значений
        temp = head;

        for (int i = 0; i < size; i++) 
        {
            temp->data = values[i];
            temp = temp->next;
        }

        delete[] values; // Освобождаем память
    }
};

void Task1() 
{
    LinkedList list;

    int n, value;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter the sequence of natural numbers:\n";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> value;
        list.insert(value);
    }

    list.processList();

    std::cout << "Resulting sequence:\n";
    list.print();
}