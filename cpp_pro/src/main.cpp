#include <iostream>
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

int main()
{
	//1
	// cout << "Input first int(grater then second one):  ";
	// int f;
	// cin >> f;
	// cout << "Input secon int(less then first one):  ";
	// int s;
	// cin >> s;
	// cout << "The biggest denum: " << GetTheBiggestDenum(f, s) << endl;

	//3
	int row = 0;
	int col = 0;

	KnightWalk(row, col);
	DrawBoard();

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



