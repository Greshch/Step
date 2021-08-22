#include <iostream>
void PrintIntArray(int arr[], size_t const sz);
void FillIntArray(int arr[], size_t sz, int const left, int const right);
size_t GetPlusCnt(int arr[], size_t const sz);
size_t GetPlusSum(int arr[], size_t const sz);


int main()
{
	using namespace std;
	srand(time(0));
	// 1 
	size_t const SIZE = 10;
	int const LEFT = -SIZE;
	int const RIGHT = SIZE;
	int arr[SIZE] { 0 };
	FillIntArray(arr, SIZE, LEFT, RIGHT);
	PrintIntArray(arr, SIZE);
	size_t pluses = GetPlusCnt(arr, SIZE);
	size_t sum = GetPlusSum(arr, SIZE);
	cout << "pluses -> " << pluses << endl;
	cout << "sum -> " << sum << endl;
	cout << "aveeage -> " << (double) sum / pluses << endl;
	return 0;
}

void PrintIntArray(int arr[], size_t const sz)
{
	using namespace std;
	for (size_t i = 0; i < sz; i++)
	{
		cout << arr[i] << " ";
		if (0 == (i + 1) % 10)	cout << endl;
	}
	cout << endl;
}

void FillIntArray(int arr[], size_t sz, int const left, int const right)
{
	for (size_t i = 0; i < sz; i++)
	{
		arr[i] = left + rand() % (right - left + 1);
	}
}

size_t GetPlusCnt(int arr[], size_t const sz)
{
	size_t cnt = 0;
	for (size_t i = 0; i < sz; i++)
	{
		if (arr[i] > 0) ++cnt;
	}
	return cnt;
}

size_t GetPlusSum(int arr[], size_t const sz)
{
	size_t sum = 0;
	for (size_t i = 0; i < sz; i++)
	{
		if (arr[i] > 0) sum += arr[i];
	}
	return sum;
}
