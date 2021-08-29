#include <iostream>
#include <time.h>
void PrintIntMatrix(int arr[], int row, int col);
void FillIntMatrixRandomly(int arr[], int row, int col, int left_range = 0, int right_range = 100);
void FillIntMatrixCounterClockWiseSpiral(int arr[], int sz);
void FillIntMatrixFromTopLeftSpiral(int arr[], int sz);
void FillIntMatrixSimpleOrder(int arr[],  size_t const row, size_t const col);
void FillIntMatrixLikeSnake(int arr[],  size_t const row, size_t const col);
void FillIntMatrixBallStrike(int arr[],  size_t const row, size_t const col);
long long GetSumOfIntMatrix(int arr[], int row, int col);
void GetIndexOfMin(int arr[], int row, int col, int& min_row, int& min_col);
void GetIndexOfMax(int arr[], int row, int col, int& max_row, int& max_col);


int main()
{
	using namespace std;
	srand(time(0));

	//1
	/*size_t const M = 2;
	size_t const N = 5;
	int const LEFT = 0;
	int const RIGHT = 20;
	int matrix[M][N] { {0} };
	FillIntMatrixRandomly((int*)matrix, M, N, LEFT, RIGHT);
	PrintIntMatrix((int*)matrix, M, N);
	auto sum = GetSumOfIntMatrix((int*)matrix, M, N);
	int row_min = 0;
	int col_min = 0;
	int row_max = 0;
	int col_max = 0;
	GetIndexOfMin((int*)matrix, M, N, row_min, col_min);
	GetIndexOfMax((int*)matrix, M, N, row_max, col_max);
	cout << "\tArray specification:" << endl;
	cout << "sum\t" << sum << endl;
	cout << "average\t" << (double)sum / (M * N) << endl;
	cout << "min\t" << matrix[row_min][col_min] << endl;
	cout << "max\t" << matrix[row_max][col_max] << endl;*/

	//2
	/*size_t const M = 6;
	size_t const N = 4;
	int const LEFT = 0;
	int const RIGHT = 20;
	int matrix[M][N]{ {0} };
	FillIntMatrixRandomly((int*)matrix, M, N, LEFT, RIGHT);
	PrintIntMatrix((int*)matrix, M, N);
	for (size_t i = 0; i < M - 1; i += 2)
	{
		for (size_t j = 0; j < N; j++)
		{
			auto tmp = matrix[i][j];
			matrix[i][j] = matrix[i + 1][j];
			matrix[i + 1][j] = tmp;
		}
	}
	cout << endl;
	PrintIntMatrix((int*)matrix, M, N);*/

	//3
	/*size_t const M = 4;
	size_t const N = 5;
	int const LEFT = -100;
	int const RIGHT = 100;
	int matrix[M][N]{ {0} };
	FillIntMatrixRandomly((int*)matrix, M, N, LEFT, RIGHT);
	PrintIntMatrix((int*)matrix, M, N);
	int row_min = 0;
	int col_min = 0;
	int row_max = 0;
	int col_max = 0;
	GetIndexOfMin((int*)matrix, M, N, row_min, col_min);
	GetIndexOfMax((int*)matrix, M, N, row_max, col_max);

	int firstId = row_min * N + col_min;
	int secondtId = row_max * N + col_max;
	if (firstId > secondtId)
	{
		auto tmp = firstId;
		firstId = secondtId;
		secondtId = tmp;
	}
	cout << "#first =" << firstId << "\t#second=" << secondtId << endl;
	int sum = 0;
	for (size_t i = firstId + 1; i < secondtId; i++)
	{
		cout << matrix[i / N][i % N] << " ";
		sum += matrix[i / N][i % N];
	}
	cout << endl;
	cout << "\tsum=" << sum << endl;*/

	//4
	// size_t const N = 7;
	// int matrix[N][N]{ {0} };
	// FillIntMatrixCounterClockWiseSpiral((int*)matrix, N);
	// cout << endl;
	// PrintIntMatrix((int*)matrix, N, N);

	//5
	// size_t const N = 3;
	// int matrix[N][N]{ {0} };
	// FillIntMatrixFromTopLeftSpiral((int*)matrix, N);
	// cout << endl;
	// PrintIntMatrix((int*)matrix, N, N);

	//6
	// size_t const M = 4;
	// size_t const N = 6;
	// int matrix[M][N]{ {0} };
	// FillIntMatrixSimpleOrder((int*)matrix, M, N);
	// PrintIntMatrix((int*)matrix, M, N);

	//7
	// size_t const M = 5;
	// size_t const N = 6;
	// int matrix[M][N]{ {0} };
	// FillIntMatrixLikeSnake((int*)matrix, M, N);
	// PrintIntMatrix((int*)matrix, M, N);

	//8
	size_t const M = 6;
	size_t const N = 10;
	int matrix[M][N]{ {0} };
	//FillIntMatrixLikeSnake((int*)matrix, M, N);
	FillIntMatrixBallStrike((int*)matrix, M, N);
	PrintIntMatrix((int*)matrix, M, N);
	return 0;
}

void PrintIntMatrix(int arr[], int row, int col)
{
	using namespace std;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i*col + j] << "\t";
		}
		cout << endl;
	}
}

void FillIntMatrixRandomly(int arr[], int row, int col, int left_range, int right_range)
{
	using namespace std;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i * col + j] = left_range + rand() % (right_range - left_range + 1);
		}
	}
}

long long GetSumOfIntMatrix(int arr[], int row, int col)
{
	long long sum{ 0 };
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			sum += arr[i * col + j];
		}
	}
	return sum;
}

void GetIndexOfMin(int arr[], int row, int col, int& min_row, int& min_col)
{
	min_row = min_col = 0;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			if (arr[i * col + j] < arr[min_row * col + min_col])
			{
				min_row = i;
				min_col = j;
			}
		}
	}
}

void GetIndexOfMax(int arr[], int row, int col, int& max_row, int& max_col)
{
	max_row = max_col = 0;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			if (arr[i * col + j] > arr[max_row * col + max_col])
			{
				max_row = i;
				max_col = j;
			}
		}
	}
}

void FillIntMatrixCounterClockWiseSpiral(int arr[], int sz)
{
	int cnt = 1;
	int row = (sz % 2) ? sz / 2 : (sz - 1) / 2;
	int col = sz / 2;
	int len = 1;
	arr[row * sz + col] = cnt;
	int cnts = sz * sz;

	while (true)
	{
		//left
		for (size_t i = 0; i < len; i++)
		{
			if (cnt == cnts) break;
			arr[row * sz + --col] = ++cnt;
		}
		//check end
		if (cnt >= cnts)	break;

		//down
		for (size_t i = 0; i < len; i++)
		{
			if (cnt == cnts) break;
			arr[++row * sz + col] = ++cnt;
		}
		len++;
		//check end
		if (cnt >= cnts)	break;

		//right
		for (size_t i = 0; i < len; i++)
		{
			if (cnt == cnts) break;
			arr[row * sz + ++col] = ++cnt;
		}
		//check end
		if (cnt >= cnts)	break;

		//up
		for (size_t i = 0; i < len; i++)
		{
			if (cnt == cnts) break;
			arr[--row * sz + col] = ++cnt;
		}
		len++;
		//check end
		if (cnt >= cnts)	break;
	}
}

void FillIntMatrixFromTopLeftSpiral(int arr[], int sz)
{
	int row = 0;
	int col = 0;
	int dx = 1;
	int dy = 0;
	//arr[row * sz + col] = cnt;
	int cnts = sz * sz;

	for (size_t i = 0; i < cnts; i++)
	{                            
		arr[row * sz + col] = i + 1;
		//change from right to down
		if (dx == 1 && (col == sz - 1 || arr[row * sz + col + 1]))
		{
			dx = 0;
			dy = 1;
			//break;
		}
		//change from down to left
		else if (dy == 1 && (row == sz - 1 || arr[(row + 1) * sz + col]))
		{
			dx = -1;
			dy = 0;
			//break;
		}
		//change from left to up
		else if (dx == -1 && (col == 0 || arr[row * sz + col - 1]))
		{
			dx = 0;
			dy = -1;
			//break;
		}//change from up to right
		else if (dy == -1 && (row == 0 || arr[(row - 1) * sz + col]))
		{
			dx = 1;
			dy = 0;
			//break;
		}
		row += dy;
		col += dx;
	}
}

void FillIntMatrixSimpleOrder(int arr[], size_t const row, size_t const col)
{
	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < col; ++j)
		{
			arr[i * col + j] = i * col + j + 1;
		}
	}
}

void FillIntMatrixLikeSnake(int arr[],  size_t const row, size_t const col)
{
	for (size_t i = 0, k = 1; i < row; ++i)
	{
		if ( 0 == i % 2 )
		{
			for (size_t j = 0; j < col; ++j, ++k)
			{
				arr[i * col + j] = k;
			}
		}
		else
		{
			for (int j = col - 1; j >= 0; --j, ++k)
			{
				arr[i * col + j] = k;
			}
		}
	}
}



void FillIntMatrixBallStrike(int arr[],  size_t const row, size_t const col)
{
	using namespace std;
	int r = 0;
	int c = 0;
	int dx = 1;
	int dy = 1;
	int cnt = 0;
	arr[r * col + c] = cnt;
	int cnts = row * col;
	for (size_t i = 0; i < cnts;)
	{   
		if (arr[r * col + c] == 0) 
		{
			arr[r * col + c] = ++i;
		}  
		                  
		if (dx == 1 && dy == 1)
		{
			if (r == row - 1 && c == col - 1)
			{
				//check left bottom corner
				if (arr[(row - 1) * col + 0] == 0)
				{
					dx = 1;
					dy = -1;
					r = row - 1;
					c = 0;
					continue;
				}
				else if (arr[0 * col + col] == 0)
				{
					dx = -1;
					dy = 1;
					r = 0;
					c = col - 1;
					continue;
				}
				//break;
			}
			else if (r == row - 1)
			{
				dy = -1;
				//break;
			}
			else if (c == col - 1)
			{
				dx = -1;
				//break;
			}
		}
		else if (dx == 1 && dy == -1)
		{
			if (r == 0 && c == col - 1)
			{
				//check right bottom
				if (arr[(row - 1) * col + col] == 0)
				{
					dx = -1;
					dy = -1;
					r = row - 1;
					c = col - 1;
					continue;
				}
				//check left bottom
				else if (arr[(row - 1) * col + 0] == 0)
				{
					dx = 1;
					dy = -1;
					r = row - 1;
					c = 0;
					continue;
				}
			}
			else if (r == 0)
			{
				dy = 1;
				//break;
			}
			else if (c == col - 1)
			{
				dx = -1;
				//break;
			}
		}
		else if (dx == -1 && dy == -1)
		{
			if (r == 0)
			{
				dy = 1;
				//break;
			}
			else if (c == 0)
			{
				dx = 1;
				//break;
			}
		}
		else if (dx == -1 && dy == 1)
		{
			if (r == row - 1)
			{
				dy = -1;
				//break;
			}
			else if (c == 0)
			{
				dx = 1;
				//break;
			}
		}

		r += dy;
		c += dx;
	}
}
