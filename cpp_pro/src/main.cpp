#include <iostream>

///////////////////////////////////////////////////////////////////////////////////////
// functions for task_1
void PrintIntArray(int arr[], size_t const sz);
void FillIntArray(int arr[], size_t const sz, int const left, int const right);
size_t GetPlusCnt(int arr[], size_t const sz);
size_t GetPlusSum(int arr[], size_t const sz);
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// functions for task_2
void FillCharArray(char arr[], size_t const sz, int const left, int const right);
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// functions for task_4
void FillDoubleArray(double arr[], size_t const sz, int const top, int const bottom);
void PrintDoubleArray(double arr[], size_t const sz);
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// functions for task_5
void ReverseIntArray(int arr[], size_t const sz);
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// functions for task_6
typedef bool(*predicat)(int a);
bool Pluse(int a);
bool Zero(int a);
bool Minuse(int a);
void CopyIntArrayFromTo(int dest[], int const src[], size_t const src_sz, 
	int& src_pos, int& dest_pos, predicat = Pluse);
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// functions for task_7
bool IsExistElemInIntArray(int const arr[], int elem, size_t const sz);
///////////////////////////////////////////////////////////////////////////////////////


int main()
{
	using namespace std;
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	// 1 
	/*size_t const SIZE = 10;
	int const LEFT = -SIZE;
	int const RIGHT = SIZE;
	int arr[SIZE] { 0 };
	FillIntArray(arr, SIZE, LEFT, RIGHT);
	PrintIntArray(arr, SIZE);
	size_t pluses = GetPlusCnt(arr, SIZE);
	size_t sum = GetPlusSum(arr, SIZE);
	cout << "pluses -> " << pluses << endl;
	cout << "sum -> " << sum << endl;
	cout << "aveeage -> " << (double) sum / pluses << endl;*/

	//2
	/*size_t const SIZE = 100;
	char arr[SIZE + 1]{};
	arr[SIZE] = '\0';
	size_t digits = 0;
	size_t alphas = 0;
	size_t puncts = 0;
	FillCharArray(arr, SIZE, 32, 175);
	cout << arr << endl;

	for (size_t i = 0; i < SIZE; i++)
	{
		if (isdigit(arr[i]))
		{
			digits++;
		}
		else if (isalpha(arr[i]))
		{
			alphas++;
		}
		else if (ispunct(arr[i]))
		{
			puncts++;
		}
	}
	cout << "digits -> " << digits << endl;
	cout << "alphas -> " << alphas << endl;
	cout << "puncts -> " << puncts << endl;*/

	//3
	/*int const SIZE = 20;
	int const LEFT = 0;
	int const RIGHT = 100;
	int arr[SIZE]{ 0 };
	FillIntArray(arr, SIZE, LEFT, RIGHT);
	PrintIntArray(arr, SIZE);
	size_t min = 0;
	size_t max = 0;
	for (size_t i = 1; i < SIZE; i++)
	{
		if (arr[i] < arr[min])	min = i;
		else if (arr[i] > arr[max])	max = i;
	}
	cout << "min[id=" << min << ", value=" << arr[min] << "]" << endl;
	cout << "max[id=" << max << ", value=" << arr[max] << "]" << endl;*/

	//4
	/*size_t const SIZE = 100;
	int const TOP = 23;
	int const BOTTOM = 7;
	double arr[SIZE]{ 0 };
	FillDoubleArray(arr, SIZE, TOP, BOTTOM);
	PrintDoubleArray(arr, SIZE);
	int cnt_int = 0;
	double error = 0.0001;
	for (size_t i = 0; i < SIZE; i++)
	{
		if (arr[i] - (int)arr[i] <= error)
		{
			++cnt_int;
		}
	}
	cout << "without real part -> " << cnt_int << endl;*/

	//5
	/*size_t const SIZE = 10;
	int arr[SIZE]{ 0 };
	FillIntArray(arr, SIZE, 0, 100);
	PrintIntArray(arr, SIZE);
	ReverseIntArray(arr, SIZE);
	PrintIntArray(arr, SIZE);*/

	//6
	/*size_t const SIZE = 20;
	int src[SIZE]{ 0 };
	int dest[SIZE]{ 0 };
	FillIntArray(src, SIZE, -10, 10);
	PrintIntArray(src, SIZE);
	int i_src = 0;
	int j_dest = 0;
	CopyIntArrayFromTo(dest, src, SIZE, i_src, j_dest, Pluse);
	cout << "............................................\n";
	PrintIntArray(dest, SIZE);
	cout << "i_src = " << i_src << "\tj_dest = " << j_dest << endl;
	
	CopyIntArrayFromTo(dest, src, SIZE, i_src, j_dest, Zero);
	cout << "............................................\n";
	PrintIntArray(dest, SIZE);
	cout << "i_src = " << i_src << "\tj_dest = " << j_dest << endl;
	
	CopyIntArrayFromTo(dest, src, SIZE, i_src, j_dest, Minuse);
	cout << "............................................\n";
	PrintIntArray(dest, SIZE);
	cout << "i_src = " << i_src << "\tj_dest = " << j_dest << endl;*/

	//7
	/*size_t const N = 10;
	size_t const M = 15;
	int A[N] { 0 };
	int B[M] { 0 };
	int C[N] { 0 };
	FillIntArray(A, N, -10, 10);
	PrintIntArray(A, N);
	
	FillIntArray(B, M, -5, 10);
	PrintIntArray(B, M);

	int cnt = 0;
	for (size_t i = 0; i < N; i++)
	{
		auto elem = A[i];
		if (!IsExistElemInIntArray(B, elem, M)) continue;
		if (!IsExistElemInIntArray(C, elem, N))	C[cnt++] = elem;
	}

	cout << "....................................................\n";
	PrintIntArray(C, cnt);*/

	//8
	size_t const SZ = 20;
	int const LEFT = -10;
	int const RIGHT = 20;
	int A[SZ] {0};
	FillIntArray(A, SZ, LEFT, RIGHT);
	PrintIntArray(A, SZ);
	//bool flag = true;
	size_t cnt = 0;
	size_t max = 0;
	size_t max_id = -1;
	for (size_t i = 0; i < SZ; i++)
	{
		if (A[i] > 0)
		{
			cnt++;
			if (i == SZ - 1)
			{
				if (cnt > max)
				{
					max_id = i - cnt + 1;
					max = cnt;
				}
			}		
		} 
		else if (A[i] <= 0)
		{
			if (cnt)
			{
				if (cnt > max)
				{
					max_id = i - cnt;
					max = cnt;
				}
			}
			cnt = 0;
		}
	}
	cout << "#max=" << max << "\tmax_id=" << max_id << "\t" << A[max_id] << endl;
	for (size_t i = 0; i < max; i++)
	{
		cout << A[max_id + i] << " ";
	}
	cout << endl;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////
// functions for task_1
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

void FillIntArray(int arr[], size_t const sz, int const left, int const right)
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
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// functions for task_2
void FillCharArray(char arr[], size_t const sz, int const left, int const right)
{
	for (size_t i = 0; i < sz; i++)
	{
		arr[i] = left + rand() % (right - left + 1);
	}
}
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// functions for task_4
void FillDoubleArray(double arr[], size_t const sz, int const top, int const bottom)
{
	for (size_t i = 0; i < sz; i++)
	{
		arr[i] = (double) ( rand() % top ) / ( rand() % bottom + 1);
	}
}

void PrintDoubleArray(double arr[], size_t const sz)
{
	using namespace std;
	for (size_t i = 0; i < sz; i++)
	{
		cout << arr[i] << " ";
		if (0 == (i + 1) % 10)	cout << endl;
	}
	cout << endl;
}
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// functions for task_5
void ReverseIntArray(int arr[], size_t const sz)
{
	for (size_t i = 0; i < sz / 2; i++)
	{
		auto tmp = arr[i];
		arr[i] = arr[sz - 1 - i];
		arr[sz - 1 - i] = tmp;
	}
}
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// functions for task_6
bool Pluse(int a)
{
	return a > 0;
}

bool Zero(int a)
{
	return a == 0;
}

bool Minuse(int a)
{
	return a < 0;
}

void CopyIntArrayFromTo(int dest[], int const src[], 
	size_t const src_sz, int& src_pos, int& dest_pos, predicat pre)
{
	bool flag = true;
	for (int i = src_pos; i < src_sz; ++i)
	{
		if (pre(src[i]))
		{
			dest[dest_pos++] = src[i];
		}
		else if (flag)
		{
			src_pos = i;
			flag = false;
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// functions for task_7
bool IsExistElemInIntArray(int const arr[], int elem, size_t const sz)
{
	bool find = false;
	for (size_t i = 0; i < sz; i++)
	{
		if (arr[i] == elem)	return true;
	}
	return find;
}
///////////////////////////////////////////////////////////////////////////////////////


