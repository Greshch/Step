#include "Array.h"
#include "Sorter.h"

int main()
{
	int* arr = nullptr;
	int size = 50;
	InitRandomIntArray(&arr, size, -10, 100);
	PrintIntArray(arr, size);
	//Sorter::BubleSort(arr, size);
	//Sorter::BubleSort(arr, size, Sorter::Lower);

	//Sorter::SelectSort(arr, size);
	//Sorter::SelectSort(arr, size, Sorter::Lower);

	//Sorter::InsertSort(arr, size, Sorter::Greater);
	//Sorter::InsertSort(arr, size, Sorter::Lower);

	//Sorter::QuickSortSort(arr, 0, size - 1, Sorter::Greater);
	//Sorter::QuickSortSort(arr, 0, size - 1, Sorter::Lower);
	PrintIntArray(arr, size);
	CleanArray(&arr);
	return 0;
}