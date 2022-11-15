#pragma once

struct DynamicArray
{
	/**
	 * @brief Количество элементов динамического массива.
	*/
	int Length;

	/**
	 * @brief Вместимость динамического массива.
	*/
	int Capacity;

	/**
	 * @brief Указатель на динамический массив.
	*/
	int* Array;

	/**
	 * @brief Число роста размера динамического массива.
	*/
	const int GrowthFactor = 2;

	bool IsSorted = false;
};

/**
 * @brief Создает динамический массив.
 * @param array Указатель на динамический массив.
*/
DynamicArray* CreateArray();

/**
 * @brief Добавлят элемент в конец динамического массива.
 * @param array Указатель на динамический массив.
 * @param value Значение, которое нужно вставить в конец динамического массива.
*/
void AddToEnd(DynamicArray* array, int value);

/**
 * @brief Заполняет динамический массив случайными значениями.
 * @param array Указатель на динамический массив.
 * @param length Количество элементов в массиве.
*/
void FillRandomArray(DynamicArray* array, int length);

/**
 * @brief Проверяет, хватает ли вместимости для добавления еще одного элемента.
 * @param array Указатель на динамический массив.
 * @return True или False
*/
bool CheckCapacity(DynamicArray* array);

/**
 * @brief Увеличивает динамический массив в GrowthFactor раз.
 * @param array Указатель на динамический массив.
*/
void Resize(DynamicArray* array);

/**
 * @brief Добавлять элемент в начало динамического массива.
 * @param array Указатель на динамический массив.
 * @param value Значение, которое нужно вставить в начало динамического массива.
*/
void AddToStart(DynamicArray* array, int value);

/**
 * @brief Удаляет элемент по индексу.
 * @param array Указатель на динамический массив.
 * @param index Индекс удаляемого элемента.
*/
void RemoveElement(DynamicArray* array, int index);

/**
 * @brief Добавляет элемент в динамический массив после определенного индекса.
 * @param array Указатель на динамический массив.
 * @param index Индекс, после которого нужно добавить элемент
 * @param value Значение, которое нужно добавить в динамический массив.
*/
void AddAfterIndex(DynamicArray* array, int index, int value);

/**
 * @brief Сортирует динамический массив методом пузырька по возрастанию.
 * @param array Указатель на динамический массив.
*/
void Sort(DynamicArray* array);

/**
 * @brief Осуществляет линейный поиск элемента в динамическом массиве.
 * @param array Указатель на динамический массив.
 * @param value Искомое значение.
 * @return Индекс искомого элемента.
*/
int LineSearch(DynamicArray* array, int value);

/**
 * @brief Осуществляет бинарный поиск элемента в динамическом массиве. Применять только для отсортированного массива.
 * @param array Указатель на динамический массив.
 * @param value Искомое значение.
 * @return Индекс искомого значения.
*/
int BinarySearch(DynamicArray* array, int value);





