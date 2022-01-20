#include <iostream>
#include "MyStack.h"
using namespace std;

int main()
{
	MyStack obj;
	int const times = 5;
	for (int i = 0; i < times; i++)
	{
		obj.Push(i + 1);
	}
	cout << "sz = " << obj.Size() << endl;
	while (!obj.Empty())
	{
		cout << obj.Peek() << " ";
		obj.Pop();
	}cout << endl;
	return 0;
}