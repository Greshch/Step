#pragma once

typedef bool (*comparisonFcn)(int, int);



class Sorter
{
public:
	static bool Greater(int a, int b);
	static bool Lower(int a, int b);
	static void BubleSort(int* arr, int size, comparisonFcn = Greater);
	static void InsertSort(int* arr, int size, comparisonFcn = Greater);
	static void SelectSort(int* arr, int size, comparisonFcn = Greater);
	static void QuickSortSort(int* arr, int left, int right, comparisonFcn = Greater);
};

