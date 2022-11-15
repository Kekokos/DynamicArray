#include <iostream>
#include "DynamicArray.h"

using namespace std;

void PrintArray(DynamicArray* array) 
{
    for (int i = 0; i < array->Length; i++)
    {
        cout << array->Array[i] << "   ";
    }
}

int InputValue() 
{
    char* choice = new char[256]{};
    int value;
    cin >> choice;
    value = atoi(choice);
    cout << endl;
    return value;
}

bool CheckArray(DynamicArray* array) 
{
    if (array == nullptr)
    {
        cout << "Ошибка! Массив не создан.";
        cout << endl;
        return false;
    }
    return true;
}

bool IndexValidator(DynamicArray* array, int index) 
{
    return index > 0 && index < array->Length - 1;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    DynamicArray* array = nullptr;
    while (true)
    {        
        cout << "Выберите действие:" << endl;
        cout << "1. Создать и заполнить массив случайными значениями" << endl;
        cout << "2. Добавить элемент в начало" << endl;
        cout << "3. Добавить элемент в конец" << endl;
        cout << "4. Удалить элемент по индексу" << endl;
        cout << "5. Вставка после опреденного элемента" << endl;
        cout << "6. Сортировка массива" << endl;
        cout << "7. Линейный поиск элемента в массиве" << endl;
        cout << "8. Бинарный поиск элемента в массиве" << endl;
        cout << "Действие: ";
        int choice = InputValue();

        switch (choice)
        {
            case 1:
            {
                array = CreateArray();
                cout << "Введите количество элементов массива: ";
                int length = InputValue();
                FillRandomArray(array, length);
                cout << "Массив: ";
                PrintArray(array);
                cout << endl;
                cout << endl;
                break;
            }
            case 2:
            {
                if (!(CheckArray(array))) 
                {
                    break;
                }
                cout << "Введите элемент, который хотите добавить в начало: ";
                int value = InputValue();
                AddToStart(array, value);
                cout << "Массив: ";
                PrintArray(array);
                cout << endl;
                cout << endl;
                break;
            }
            case 3:
            {
                if (!(CheckArray(array)))
                {
                    break;
                }
                cout << "Введите элемент, который хотите добавить в конец";
                int value = InputValue();
                AddToEnd(array, value);
                cout << "Массив: ";
                PrintArray(array);
                cout << endl;
                cout << endl;
                break; 
            }
            case 4:
            {
                if (!(CheckArray(array)))
                {
                    break;
                }
                cout << "Введите индекс элемента, который хотите удалить: ";
                int index = InputValue();
                if (!(IndexValidator(array, index))) 
                {
                    cout << "Индекс не найден" << endl;
                    cout << endl;
                    break;
                }
                RemoveElement(array, index);
                cout << "Массив: ";
                PrintArray(array);
                cout << endl;
                cout << endl;
                break;
            }
            case 5:
            {
                if (!(CheckArray(array)))
                {
                    break;
                }
                cout << "Введите индекс элемента, после которого нужно вставить элемент: ";
                int index = InputValue();
                if (!(IndexValidator(array, index)))
                {
                    cout << "Индекс не найден" << endl;
                    cout << endl;
                    break;
                }
                cout << "Введите элемент, который нужно вставить: ";
                int value = InputValue();
                AddAfterIndex(array, index, value);
                cout << "Массив: ";
                PrintArray(array);
                cout << endl;
                cout << endl;
                break;
            }
            case 6:
            {
                if (!(CheckArray(array)))
                {
                    break;
                }
                Sort(array);
                cout << "Массив: ";
                PrintArray(array);
                cout << endl;
                break;
            }
            case 7:
            {
                if (!(CheckArray(array)))
                {
                    break;
                }
                cout << "Введите значение, которое нужно найти в массиве: ";
                int value = InputValue();
                if (LineSearch(array, value) != -1)
                {
                    cout << "Значение " << value << " находится под индексом " << LineSearch(array, value);
                    cout << endl;
                }
                else
                {
                    cout << "Значение не найдено" << endl;
                }
                cout << endl;
                break;
            }
            case 8:
            {
                if (!(CheckArray(array)))
                {
                    break;
                }
                if (array->IsSorted == false) 
                {
                    cout << "Ошибка! Массив не отсортирован" << endl;
                    cout << endl;
                    break;
                }
                cout << "Введите значение, которое нужно найти в массиве: ";
                int value = InputValue();
                if (BinarySearch(array, value) != -1)
                {
                    cout << "Значение " << value << " находится под индексом " << BinarySearch(array, value);
                    cout << endl;
                }
                else
                {
                    cout << "Значение не найдено" << endl;
                    cout << endl;
                }
                cout << endl;
                break;
            }
            default:
            {
                cout << "Некорректное значение, введите число от 1 до 9" << endl;
                cout << endl;
                break;
            }
        }
    }
}