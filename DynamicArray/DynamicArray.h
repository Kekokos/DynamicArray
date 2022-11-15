#pragma once

struct DynamicArray
{
	/**
	 * @brief ���������� ��������� ������������� �������.
	*/
	int Length;

	/**
	 * @brief ����������� ������������� �������.
	*/
	int Capacity;

	/**
	 * @brief ��������� �� ������������ ������.
	*/
	int* Array;

	/**
	 * @brief ����� ����� ������� ������������� �������.
	*/
	const int GrowthFactor = 2;

	bool IsSorted = false;
};

/**
 * @brief ������� ������������ ������.
 * @param array ��������� �� ������������ ������.
*/
DynamicArray* CreateArray();

/**
 * @brief �������� ������� � ����� ������������� �������.
 * @param array ��������� �� ������������ ������.
 * @param value ��������, ������� ����� �������� � ����� ������������� �������.
*/
void AddToEnd(DynamicArray* array, int value);

/**
 * @brief ��������� ������������ ������ ���������� ����������.
 * @param array ��������� �� ������������ ������.
 * @param length ���������� ��������� � �������.
*/
void FillRandomArray(DynamicArray* array, int length);

/**
 * @brief ���������, ������� �� ����������� ��� ���������� ��� ������ ��������.
 * @param array ��������� �� ������������ ������.
 * @return True ��� False
*/
bool CheckCapacity(DynamicArray* array);

/**
 * @brief ����������� ������������ ������ � GrowthFactor ���.
 * @param array ��������� �� ������������ ������.
*/
void Resize(DynamicArray* array);

/**
 * @brief ��������� ������� � ������ ������������� �������.
 * @param array ��������� �� ������������ ������.
 * @param value ��������, ������� ����� �������� � ������ ������������� �������.
*/
void AddToStart(DynamicArray* array, int value);

/**
 * @brief ������� ������� �� �������.
 * @param array ��������� �� ������������ ������.
 * @param index ������ ���������� ��������.
*/
void RemoveElement(DynamicArray* array, int index);

/**
 * @brief ��������� ������� � ������������ ������ ����� ������������� �������.
 * @param array ��������� �� ������������ ������.
 * @param index ������, ����� �������� ����� �������� �������
 * @param value ��������, ������� ����� �������� � ������������ ������.
*/
void AddAfterIndex(DynamicArray* array, int index, int value);

/**
 * @brief ��������� ������������ ������ ������� �������� �� �����������.
 * @param array ��������� �� ������������ ������.
*/
void Sort(DynamicArray* array);

/**
 * @brief ������������ �������� ����� �������� � ������������ �������.
 * @param array ��������� �� ������������ ������.
 * @param value ������� ��������.
 * @return ������ �������� ��������.
*/
int LineSearch(DynamicArray* array, int value);

/**
 * @brief ������������ �������� ����� �������� � ������������ �������. ��������� ������ ��� ���������������� �������.
 * @param array ��������� �� ������������ ������.
 * @param value ������� ��������.
 * @return ������ �������� ��������.
*/
int BinarySearch(DynamicArray* array, int value);





