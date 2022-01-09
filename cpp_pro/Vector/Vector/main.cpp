#include <iostream>
#include "MyVector.h"
using namespace std;

int main()
{
	MyVector vec;
	for (int i = 1; i <= 5; i++)
	{
		vec.PushBack(i);
	}
	for (int i = 0; i < vec.GetSize(); i++)
	{
		cout << vec[i] << " ";
	}cout << endl;
	return 0;
}