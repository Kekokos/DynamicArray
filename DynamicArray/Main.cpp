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
        cout << "������! ������ �� ������.";
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
        cout << "�������� ��������:" << endl;
        cout << "1. ������� � ��������� ������ ���������� ����������" << endl;
        cout << "2. �������� ������� � ������" << endl;
        cout << "3. �������� ������� � �����" << endl;
        cout << "4. ������� ������� �� �������" << endl;
        cout << "5. ������� ����� ����������� ��������" << endl;
        cout << "6. ���������� �������" << endl;
        cout << "7. �������� ����� �������� � �������" << endl;
        cout << "8. �������� ����� �������� � �������" << endl;
        cout << "��������: ";
        int choice = InputValue();

        switch (choice)
        {
            case 1:
            {
                array = CreateArray();
                cout << "������� ���������� ��������� �������: ";
                int length = InputValue();
                FillRandomArray(array, length);
                cout << "������: ";
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
                cout << "������� �������, ������� ������ �������� � ������: ";
                int value = InputValue();
                AddToStart(array, value);
                cout << "������: ";
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
                cout << "������� �������, ������� ������ �������� � �����";
                int value = InputValue();
                AddToEnd(array, value);
                cout << "������: ";
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
                cout << "������� ������ ��������, ������� ������ �������: ";
                int index = InputValue();
                if (!(IndexValidator(array, index))) 
                {
                    cout << "������ �� ������" << endl;
                    cout << endl;
                    break;
                }
                RemoveElement(array, index);
                cout << "������: ";
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
                cout << "������� ������ ��������, ����� �������� ����� �������� �������: ";
                int index = InputValue();
                if (!(IndexValidator(array, index)))
                {
                    cout << "������ �� ������" << endl;
                    cout << endl;
                    break;
                }
                cout << "������� �������, ������� ����� ��������: ";
                int value = InputValue();
                AddAfterIndex(array, index, value);
                cout << "������: ";
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
                cout << "������: ";
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
                cout << "������� ��������, ������� ����� ����� � �������: ";
                int value = InputValue();
                if (LineSearch(array, value) != -1)
                {
                    cout << "�������� " << value << " ��������� ��� �������� " << LineSearch(array, value);
                    cout << endl;
                }
                else
                {
                    cout << "�������� �� �������" << endl;
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
                    cout << "������! ������ �� ������������" << endl;
                    cout << endl;
                    break;
                }
                cout << "������� ��������, ������� ����� ����� � �������: ";
                int value = InputValue();
                if (BinarySearch(array, value) != -1)
                {
                    cout << "�������� " << value << " ��������� ��� �������� " << BinarySearch(array, value);
                    cout << endl;
                }
                else
                {
                    cout << "�������� �� �������" << endl;
                    cout << endl;
                }
                cout << endl;
                break;
            }
            default:
            {
                cout << "������������ ��������, ������� ����� �� 1 �� 9" << endl;
                cout << endl;
                break;
            }
        }
    }
}