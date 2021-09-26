#include <iostream>
#include <time.h>
using namespace std;

int const SZ = 8;
int const DIR = 8;
int board[SZ][SZ]{ 0 };
int turns[DIR][2] {
	{2, -1},
	{1, -2},
	{-1, -2},
	{-2, -1},
	{-2, 1},
	{-1, 2},
	{1, 2},
	{2, 1}
};
bool KnightWalk(int row, int col);
void DrawBoard();

int GetTheBiggestDenum(int a, int b);
long long GetPowOfNum(int a, int pow);
int GetSumFromFirstToSecond(int first, int second);
////////////////////////////////////////////////////
////////////////////////////////////////////////////

void PrintArray(int arr[], int sz);
void CopyIntArray(int dest[], int src[], int sz);
void FillArrayRandomly(int arr[], int sz);
void ReverseArray(int arr[], int sz);
void ReverseCopyIntArray(int dest[], int src[], int sz);
long long GetSumOfArray(int arr[], int sz);

typedef double (*operation)(double a, double b);
double Sum(double a, double b);
double Diff(double a, double b);
double Prod(double a, double b);
double Div(double a, double b);
double Calculator(operation op, double a, double b);

int main()
{
	srand(time(0));
	//Recurtion
	//1
	// cout << "Input first int(grater then second one):  ";
	// int f;
	// cin >> f;
	// cout << "Input secon int(less then first one):  ";
	// int s;
	// cin >> s;
	// cout << "The biggest denum: " << GetTheBiggestDenum(f, s) << endl;

	//3
	/*int row = 0;
	int col = 0;
	KnightWalk(row, col);
	DrawBoard();*/

	//4
	// cout << "Input int num: " ;
	// int num;
	// cin >> num;
	// cout << "Input int pow: ";
	// int pow;
	// cin >> pow;
	// printf("pow(%d, %d) = %d\n", num, pow, GetPowOfNum(num, pow)); 

	//6
	// cout << "Input first int(grater then second one):  ";
	// int f;
	// cin >> f;
	// cout << "Input secon int(less then first one):  ";
	// int s;
	// cin >> s;
	// cout << "Sum of ranges nums: " << GetSumFromFirstToSecond(f, s) << endl;

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//Pointers
	//1
	/*int const SZ = 10;
	int a[SZ]{ 0 };
	int b[SZ]{ 0 };
	FillArrayRandomly(a, SZ);
	PrintArray(a, SZ);
	CopyIntArray(b, a, SZ);
	PrintArray(b, SZ);*/

	//2
	/*int const SZ = 10;
	int a[SZ]{ 0 };
	FillArrayRandomly(a, SZ);
	PrintArray(a, SZ);
	ReverseArray(a, SZ);
	PrintArray(a, SZ);*/

	//3
	/*int const SZ = 10;
	int a[SZ]{ 0 };
	int b[SZ]{ 0 };
	FillArrayRandomly(a, SZ);
	PrintArray(a, SZ);
	ReverseCopyIntArray(b, a, SZ);
	PrintArray(b, SZ);*/

	//4
	/*int a = 5, b = 7;
	int *pA = &a, *pB = &b;
	int max = (*pA > *pB) ? *pA : *pB;
	printf("a=%d b=%d\n", a, b);
	cout << "max: " << max << endl;*/
	
	//5
	/*short num{};
	cout << "Input num: ";
	cin >> num;
	short* pNum = &num;
	cout << ((*pNum >= 0) ? "+" : "-") << endl;*/

	//6
	/*int a = 777, b = 911;
	printf("a = %3d\tb = %3d\n", a, b);
	int *pA = &a, *pB = &b;
	int tmp = *pA;
	*pA = *pB;
	*pB = tmp;
	printf("a = %3d\tb = %3d\n", a, b);*/

	//7
	cout << "a: ";
	double a;
	cin >> a;
	cout << "(+ - * \\): ";
	char ch;
	cin >> ch;
	cout << "b: ";
	double b;
	cin >> b;
	double res = 0;
	switch (ch)
	{
	case '+':
		res = Calculator(Sum, a, b);
		break;

	case '-':
		res = Calculator(Diff, a, b);
		break;
	
	case '*':
		res = Calculator(Prod, a, b);
		break;

	case '\\':
		res = Calculator(Div, a, b);
		break;

	default:
		cout << "Undefined operation ERROR\n";
		return 101;
		break;
	}
	cout << "res: " << res << endl;

	//8
	/*int const SZ = 5;
	int a[SZ]{ 1, 2, 3, 4, 5 };
	PrintArray(a, SZ);
	cout << "\nsum: " << GetSumOfArray(a, SZ) << endl;*/
	return 0;
}

int GetTheBiggestDenum(int a, int b)
{
	int greater = (a > b) ? a : b;
	int smaller = (a < b) ? a : b;
	if (greater % smaller == 0)
	{
		return smaller;
	}
	return GetTheBiggestDenum(greater % smaller, smaller);
}

long long GetPowOfNum(int a, int pow)
{
	if (pow == 0)	return 1;
	if (pow == 1)	return a;
	return a * GetPowOfNum(a, pow - 1);
}

int GetSumFromFirstToSecond(int f, int s)
{
	int greater = (f > s) ? f : s;
	int smaller = (f < s) ? f : s;
	if (smaller	 == greater) return smaller;
	return smaller + GetSumFromFirstToSecond(smaller + 1, greater);
}

void PrintArray(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%4d", arr[i]);
		if (i != 0 && (i + 1) % 10 == 0)
			printf("\n");
	}
}

void CopyIntArray(int dest[], int src[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		*dest++ = *src++;
	}
}

void FillArrayRandomly(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		arr[i] = rand() % 100;
	}
}

void ReverseArray(int arr[], int sz)
{
	int *b = arr, *e = b + sz - 1;
	for (int i = 0; i < sz / 2; i++, b++, e--)
	{
		auto tmp = *b;
		*b = *e;
		*e = tmp;
	}
}

void ReverseCopyIntArray(int dest[], int src[], int sz)
{
	int* e = src + sz - 1;
	for (int i = 0; i < sz; i++)
	{
		*dest++ = *e--;
	}
}

long long GetSumOfArray(int arr[], int sz)
{
	long long sum = 0;
	int* end = arr + sz;
	for (int* i = arr; i != end; i++)
	{
		sum += *i;
	}
	return sum;
}

double Sum(double a, double b)
{
	return a + b;
}

double Diff(double a, double b)
{
	return a - b;
}

double Prod(double a, double b)
{
	return a * b;
}

double Div(double a, double b)
{
	return a / b;
}

double Calculator(operation op, double a, double b)
{
	return op(a, b);
}

bool KnightWalk(int row, int col)
{
	static int n = 0;
	if (row < 0 || row >= SZ || col < 0 || col >= SZ || board[row][col] != 0)
	{
		return false;
	}

	n++;
	board[row][col] = n;
	if (n == SZ * SZ)
	{
		return true;
	}
	
	for (size_t i = 0; i < DIR; i++)
	{
		int y = row +  turns[i][0];
		int x = col + turns[i][1];
		if (KnightWalk(y, x))
		{
			return true;
		}
	}

	n--;
	board[row][col] = 0;
	return false;
}

void DrawBoard()
{
	for (size_t row = 0; row < SZ; row++)
	{
		for (size_t col = 0; col < SZ; col++)
		{
			printf(" %2d", board[row][col]);
		}
		printf("\n");
	}
}



