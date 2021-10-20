/**
 * @file main.cpp
 * @author your name (Greshch)
 * @brief 
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright DimaGres(c) 2021
 */
#include <iostream>
#include <time.h>
#include <random>
#include <algorithm>
#include "my_array.h"
using namespace std;

enum CONTROLS
{ 
	EXIT,
	PRINT,
	ADD_BEGIN,
	ADD_END,
	INSERT,
	REMOVE_BEGIN,
	REMOVE_END,
	ERASE
};

typedef int** ARR_2d;

void Add_Row(ARR_2d* p, int* p_row, int const p_col, int num, int* src);
void Del_Row(ARR_2d* p, int* p_row, int const p_col, int num);
void Del_Col(ARR_2d* p, int const p_row, int* p_col, int num);
void Add_Col(ARR_2d* p, int const p_row, int* p_col, size_t pos, int const* src);
void Copy_Array(int* dest, int const* src, int const Len);
void Free_2D(ARR_2d* p, int const row);
void Print_2D(ARR_2d const m, size_t const row, size_t const col);
///////////////////////////////////////////////////////////////////////////////////
/*Only for sorted array*/
int BinarySearch(int const* arr, int left, int right, int value);
/*Only for sorted array*/
int GetNewsize(int* arr, int len);
/*Only for sorted arrays*/
int GetMinSize(int const* a, size_t a_sz, int const* b, size_t b_sz);
/*Only for sorted arrays*/
void FillUniqueArray(int* dest, size_t dest_sz, int const* a, size_t a_sz, int const* b, size_t b_sz);

int main()
{
	srand(time(0));

	//1
	 /*int const Left = -20;
	 int const Right = 35;
	 int  Len = 8;
	 int* pArr = nullptr;
	 AllocatedMemory(&pArr, Len);
	 InitArrayRandomely(pArr, Len, Left, Right);
	 PrintArray(pArr, Len);
	 int min, max, sum;
	 long product;
	 Get_Min_Max_Sum_Product_From_Array(pArr, Len, &min, &max, &sum, &product);
	 cout << "min: " << min << endl;
	 cout << "max: " << max << endl;
	 cout << "sum: " << sum << endl;
	 cout << "product: " << product << endl;
	 FreeMemory(&pArr);*/

	//2
	 /*int const Left = -20;
	 int const Right = 35;
	 int  Len = 8;
	 int* pArr = nullptr;
	 AllocatedMemory(&pArr, Len);
	 InitArrayRandomely(pArr, Len, Left, Right);
	 PrintArray(pArr, Len);

	 int action = -1;
	 int pos = 0, num = 0;
	 while (action)
	 {
	 	cout << "\tMenu\n\n";
	 	cout << "PRINT -> 1\n";
	 	cout << "ADD_BEGIN -> 2 -> 1\n";
	 	cout << "ADD_END -> 3\n";
	 	cout << "INSERT -> 4\n";
	 	cout << "REMOVE_BEGIN -> 5\n";
	 	cout << "REMOVE_END -> 6\n";
	 	cout << "ERASE -> 7\n";
	 	cout << "EXIT -> 0\n";
	 	cout << "\nKEY_PRESSED: ";

	 	cin >> action;
	 	system("cls");

	 	switch (action)
	 	{
	 	case EXIT:
	 		break;

	 	case PRINT:
	 		PrintArray(pArr, Len);
	 		break;

	 	case ADD_BEGIN:
	 		cout << "Input num: ";
	 		cin >> num;
	 		PushFront(&pArr, &Len, num);
	 		break;	

	 	case ADD_END:
	 		cout << "Input num: ";
	 		cin >> num;
	 		PushBack(&pArr, &Len, num);
	 		break;

	 	case INSERT:
	 		cout << "Input num: ";
	 		cin >> num;
	 		cout << "Input position: " ;
	 		cin >> pos;
	 		Insert(&pArr, &Len, pos, num);
	 		break;

	 	case REMOVE_BEGIN:
	 		RemoveFront(&pArr, &Len);
	 		break;

	 	case REMOVE_END:
	 		RemoveBack(&pArr, &Len);
	 		break;

	 	case ERASE:
	 		cout << "Input position: " ;
	 		cin >> pos;
	 		Erase(&pArr, pos, &Len);
	 		break;		
		
	 	default:
	 		break;
	 	}
	 }
	 FreeMemory(&pArr);*/

	//3

	int N = 40;
	int M = 30;
	int left = 0;
	int right = 20;
	int* a = nullptr;
	int* b = nullptr;
	cout << "Input N: " ;
	cin >> N;
	cout << "Input M: " ;
	cin >> M;

	AllocatedMemory(&a, N);
	AllocatedMemory(&b, M);
	InitArrayRandomely(a, N, left, right);
	InitArrayRandomely(b, M, left, right);
	sort(a, a + N);
	sort(b, b + M);
	PrintArray(a, N);
	PrintArray(b, M);
	int n_N = GetNewsize(a, N);
	int n_M = GetNewsize(b, M);
	
	cout << "\n\t\t..................\n\n";

	PrintArray(a, n_N);
	PrintArray(b, n_M);

	int min_size = GetMinSize(a, n_N, b, n_M);
	cout << "min_size = " << min_size << endl;
	int* c = nullptr;
	AllocatedMemory(&c, min_size);
	FillUniqueArray(c, min_size, a, n_N, b, n_M);
	sort(c, c + min_size);
	PrintArray(c, min_size);
	
	FreeMemory(&a);
	FreeMemory(&b);
	FreeMemory(&c);

	
	//4
	//int const Left = -20;
	//int const Right = 35;
	//int  COL = 5;
	//int ROW = 3;
	//int pos = 0;
	//
	//int** matrix = new int*[ROW];

	//int* src = nullptr;
	//int arr_len = COL;
	//AllocatedMemory(&src, arr_len);
	//InitArrayRandomely(src, COL, Left, Right);

	//for (size_t i = 0; i < ROW; i++)
	//{
	//	AllocatedMemory(matrix + i, COL);
	//	InitArrayRandomely(matrix[i], COL, Left, Right);
	//}
	//
	//PrintArray(src, arr_len);
	//Print_2D(matrix, ROW, COL);
	//
	//int key = -1;

	//while (key)
	//{
	//	cout << endl;
	//	cout << "Exit\t\t0\n";
	//	cout << "Print 2D array:\t1\n";
	//	cout << "Add row:\t2\n";
	//	cout << "Remove row:\t3\n";
	//	cout << "Add col:\t4\n";
	//	cout << "Remove col:\t5\n";
	//	cout << "Key Pressed[0-5]: ";
	//	
	//	cin >> key;
	//	switch (key)
	//	{
	//	case 0:
	//		break;

	//	case 1:
	//		//Print matrix
	//		Print_2D(matrix, ROW, COL);
	//		break;

	//	case 2:
	//		//ADD Row
	//		cout << "Input num of row: ";
	//		cin >> pos;
	//		//Realocate src and fill randomly 
	//		if (arr_len < COL)
	//		{
	//			arr_len = COL;
	//			FreeMemory(&src);
	//			AllocatedMemory(&src, arr_len);
	//			InitArrayRandomely(src, arr_len, Left, Right);
	//		}
	//		Add_Row(&matrix, &ROW, COL, pos, src);
	//		break;

	//	case 3:
	//		//Remove Row
	//		cout << "Input num of row: ";
	//		cin >> pos;
	//		Del_Row(&matrix, &ROW, COL, pos);
	//		break;

	//	case 4:
	//		//ADD COL
	//		cout << "Input num of col: ";
	//		cin >> pos;
	//		//Realocate src and fill randomly 
	//		if (arr_len < ROW)
	//		{
	//			arr_len = ROW;
	//			FreeMemory(&src);
	//			AllocatedMemory(&src, arr_len);
	//			InitArrayRandomely(src, arr_len, Left, Right);
	//		}
	//		Add_Col(&matrix, ROW, &COL, pos, src);
	//		break;

	//	case 5:
	//		//Remove Col
	//		cout << "Input num of col: ";
	//		cin >> pos;
	//		Del_Col(&matrix, ROW, &COL, pos);
	//		break;

	//	default:
	//		break;
	//	}
	//	
	//}
	//
	//FreeMemory(&src);
	//Free_2D(&matrix, ROW);
	return 0;
}

void Add_Row(ARR_2d* p, int* p_row, int const p_col, int num, int* src)
{
	int row_new = *p_row + 1;
	ARR_2d p_new = new int*[row_new];

	for (size_t i = 0; i < row_new; i++)
	{
		if (i < num)
			p_new[i] = (*p)[i];
		
		else if (i == num)
		{
			p_new[i] = new int[p_col];
			Copy_Array(p_new[i], src, p_col);
		}
		else 
			p_new[i] = (*p)[i - 1];
	}

	delete[] (*p);
	*p = p_new;
	*p_row = row_new;
}

void Copy_Array(int* dest, int const* src, int const Len)
{
	for (size_t i = 0; i < Len; i++)
	{
		dest[i] = src[i];
	}
}

void Free_2D(ARR_2d* p, int const row)
{
	for (size_t i = 0; i < row; i++)
	{
		delete[] (*p)[i];
	}
	
	delete[] (*p);
}

void Del_Row(ARR_2d* p, int* p_row, int const p_col, int num)
{
	*p_row -= 1;
	for (size_t i = num; i < *p_row; i++)
	{
		(*p)[i] = (*p)[i + 1];
	}	
}

void Print_2D(ARR_2d const m, size_t const row, size_t const col)
{
	cout << "\tMatrix" << endl;
	for (size_t i = 0; i < row; i++)
	{
		PrintArray(m[i], col);
	}
	cout << "\tEnd_matrix" << endl << endl;
}

void Del_Col(ARR_2d* p, int const p_row, int* p_col, int num)
{
	for (size_t i = 0; i < p_row; i++)
	{
		Erase(&((*p)[i]), num, p_col);
		// !!! Why this code isnt work???
		//Erase(p[i], num, p_col);
		(*p_col)++;
	}
	(*p_col)--;
}

void Add_Col(ARR_2d* p, int const p_row, int* p_col, size_t pos, int const* src)
{
	for (size_t i = 0; i < p_row; i++)
	{
		Insert(&((*p)[i]), p_col, pos, src[i]);
		(*p_col)--;
	}
	(*p_col)++;
}

/////////////////////////////////////////////////////////////////////////////////////////

int BinarySearch(int const* arr, int left, int right, int value)
{
	while (left < right)
	{
		int midle = (left + right) / 2;
		if (arr[left] == value)
		{
			return left;
		}
		else if (arr[right] == value)
		{
			return right;
		}
		else if (value <= arr[midle])
		{
			right = midle;
		}
		else
		{
			left = midle + 1;
		}
	}
	return -1;
}

int GetNewsize(int* arr, int len)
{
	int new_len = len;
	for (size_t i = 1, j = 0, k = 0; i < len; i++)
	{
		if (arr[i] == arr[j])
		{
			new_len--;
		}
		else
		{
			j = i;
			//cout << "# " << arr[j] << endl;
			arr[++k] = arr[j];
		}
	}
	return new_len;
}

int GetMinSize(int const* a, size_t a_sz, int const* b, size_t b_sz)
{
	int len = b_sz;
	for (size_t i = 0; i < a_sz; i++)
	{
		if (-1 == BinarySearch(b, 0, b_sz - 1, a[i]))
		{
			//cout << "# " << a[i] << endl;
			len++;
		}
	}
	return len;
}

void FillUniqueArray(int* dest, size_t dest_sz, int const* a, 
	size_t a_sz, int const* b, size_t b_sz)
{
	size_t i = 0;
	// copy from b
	for (; i < b_sz; i++)
	{
		dest[i] = b[i];
	}

	// copy unique from a
	for (size_t j = 0; j < a_sz; j++)
	{
		if (-1 == BinarySearch(b, 0, b_sz - 1, a[j]))
		{
			//cout << "# " << a[i] << endl;
			dest[i++] = a[j];
		}
	}
}
