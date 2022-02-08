#include<iostream>
#include"MyQuee.h"
using namespace std;

int main()
{
	// test MyQuee
	/*MyQuee q;
	for (int i = 0; i <= 5; i++)
	{
		q.Push(i + 1);
	}

	while (!q.Empty())
	{
		int val = q.Peek();
		cout << val << " ";
		q.Pop();
	} cout << endl;*/

	PrQuee q;
	for (int i = 0; i <= 5; i++)
	{
		int priority = rand() % 10;
		cout << priority << " ";
		q.Push(priority, i + 1);
	} cout << endl;

	while (!q.Empty())
	{
		int val = q.Peek();
		cout << val << " ";
		q.Pop();
	} cout << endl;
	return 0;
}