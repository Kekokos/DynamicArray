#include <iostream>
#include "DynamicArray.h"
#include <ctime>

using namespace std;

bool CheckCapacity(DynamicArray* array) 
{
    return array->Length <= array->Capacity;
}

DynamicArray* CreateArray()
{
    DynamicArray* array = new DynamicArray();
    int capacity = 8;

    array->Length = 0;
    array->Capacity = capacity;
    array->Array = new int[array->Capacity];
    return array;
}

void Resize(DynamicArray* array)
{
    array->Capacity *= array->GrowthFactor;
    int* tempArray = new int[array->Capacity];

    for (int i = 0; i < array->Length; i++)
    {
        tempArray[i] = array->Array[i];
    }

    delete[] array->Array;
    array->Array = tempArray;
}

void AddToEnd(DynamicArray* array, int value) 
{
    if (array->Length == 0) 
    {
        return;
    }
    array->Length++;
    if (!CheckCapacity(array))
    {
        Resize(array);
    }
    array->Array[array->Length - 1] = value;
    array->IsSorted = false;
}

void FillRandomArray(DynamicArray* array, int length) 
{
    if (length >= array->Capacity) 
    {
        Resize(array);
    }

    srand(time(nullptr));

    for (int i = 0; i < length; i++) 
    {
        array->Array[i] = rand() % 20 + 1;
        array->Length++;
    }
    array->IsSorted = false;
}

void AddToStart(DynamicArray* array, int value) 
{
    array->Length++;

    if (!CheckCapacity(array)) 
    {
        Resize(array);
    }

    for (int i = array->Length; i > 0; i--) 
    {
        array->Array[i] = array->Array[i - 1];
    }
    array->Array[0] = value;
    array->IsSorted = false;
}

void RemoveElement(DynamicArray* array, int index) 
{
    for (int i = index; i < array->Length - 1; i++) 
    {
        array->Array[i] = array->Array[i + 1];
    }
    array->Length--;
    array->IsSorted = false;
}

void AddAfterIndex(DynamicArray* array, int index, int value) 
{
    array->Length++;
    if (!CheckCapacity(array))
    {
        Resize(array);
    }

    for (int i = array->Length; i > index; i--) 
    {
        array->Array[i] = array->Array[i - 1];
    }
    array->Array[index + 1] = value;
    array->IsSorted = false;
}

void Sort(DynamicArray* array) 
{
    for (int i = 0; i < array->Length; i++)
    {
        for (int j = 0; j < array->Length - 1; j++) 
        {
            if (array->Array[j] > array->Array[j + 1]) 
            {
                int buffer = array->Array[j];
                array->Array[j] = array->Array[j + 1];
                array->Array[j + 1] = buffer;
            }
        }
    }
    array->IsSorted = true;
}

int LineSearch(DynamicArray* array, int value) 
{
    for (int i = 0; i < array->Length; i++) 
    {
        if (array->Array[i] == value) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(DynamicArray* array, int value) 
{
    bool flag = false;
    int left = 0;
    int right = array->Length; 
    int searchableIndex = -1;

    while ((left <= right) && (flag != true)) 
    {
        searchableIndex = (left + right) / 2; 

        if (array->Array[searchableIndex] == value)
        {
            flag = true;
        }

        if (array->Array[searchableIndex] > value) 
        {
            right = searchableIndex - 1;
        }
        else
        {
            left = searchableIndex + 1;
        }
    }
    return searchableIndex;
}
