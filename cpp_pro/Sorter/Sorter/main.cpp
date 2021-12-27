#include "Array.h"
#include "Sorter.h"

int main()
{
	int* arr = nullptr;
	int size = 50;
	InitRandomIntArray(&arr, size, 0, 10);
	PrintIntArray(arr, size);

	PrintIntArray(arr, size);
	CleanArray(&arr);
	return 0;
}