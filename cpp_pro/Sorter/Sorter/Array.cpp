#include <iostream>
#include <ctime>
#include <algorithm>
#include "Array.h"



void InitRandomIntArray(int** pArr, int size, int leftBound, int rightBound)
{
	using namespace std;
	srand(time(0));
	AllocIntArray(pArr, size);
	if (leftBound > rightBound)
	{
		swap(leftBound, rightBound);
	}
	int const DISPERSION = rightBound - leftBound + 1;
	for (int i = 0; i < size; i++)
	{
		(*pArr)[i] = leftBound + rand() % DISPERSION;
	}
}

static void AllocIntArray(int** pArr, int size)
{
	*pArr = new int[size];
}

void CleanArray(int** pArr)
{
	if (nullptr != *pArr)
		delete[] * pArr;
}

void PrintIntArray(int const* pArr, int size)
{
	using std::cout;
	using std::endl;
	if (pArr == nullptr || size == 0)
	{
		return;
	}
	for (int i = 0; i < size; i++)
	{
		cout << pArr[i];
		if ((i + 1) % 10 == 0 && i != 0)
		{
			cout << endl;
		}
		else
		{
			cout << " ";
		}
	}
	cout << endl;
}
