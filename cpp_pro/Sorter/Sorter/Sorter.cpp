#include <algorithm>
#include "Sorter.h"
using std::swap;

void Sorter::BubleSort(int* arr, int size, comparisonFcn comp)
{
	using namespace std;
	for (int i = 0; i < size - 1; i++)
	{
		bool flag = false;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (!comp(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
		if (!flag)
		{
			break;
		}
	}
}

void Sorter::InsertSort(int* arr, int size, comparisonFcn comp)
{
	for (int j = 1; j < size; j++)
	{
		int key = arr[j];
		int i = j - 1;
		while (i >= 0 && !comp(arr[i], key))
		{
			arr[i + 1] = arr[i];
			--i;
		}
		arr[i + 1] = key;
	}
}

void Sorter::SelectSort(int* arr, int size, comparisonFcn comp)
{
	using namespace std;
	for (int i = 0; i < size; i++)
	{
		int id = i;
		for (int j = i + 1; j < size; j++)
		{
			if (!comp(arr[id], arr[j]))
			{
				id = j;
			}
		}
		if (id != i)
		{
			swap(arr[id], arr[i]);
		}
	}
}

void Sorter::QuickSortSort(int* arr, int left, int right, comparisonFcn comp)
{
	using std::swap;
	int l = left;
	int r = right;
	int elem = arr[(l + r) / 2];
	while (l <= r)
	{
		while (/*arr[l] < elem*/ comp(arr[l], elem) && arr[l] != elem)
			l++;
		while (/*arr[r] > elem*/ !comp(arr[r], elem) && arr[r] != elem)
			r--;
		if (l <= r)
		{
			swap(arr[l++], arr[r--]);
		}
	}
	if (left < r)
	{
		QuickSortSort(arr, left, r, comp);
	}
	if (right > l)
	{
		QuickSortSort(arr, l, right, comp);
	}
}

bool Sorter::Greater(int a, int b)
{
	return a < b;
}

bool Sorter::Lower(int a, int b)
{
	return !Greater(a, b);
}
