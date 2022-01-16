#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	// Test Add
	/*SinglyLinkedList obj;
	for (int i = 1; i <= 3; i++)
	{
		obj.Add(i);
	}
	obj.Print();*/

	// Test Insert and Add
	/*SinglyLinkedList obj;
	for (int i = 1; i <= 3; i++)
	{
		obj.Add(i);
	}
	obj.Print();
	obj.Insert(3, 777);
	obj.Print();
	obj.Add(911);
	obj.Print();*/

// Tests Remove
	/*SinglyLinkedList obj;
	for (int i = 1; i <= 4; i++)
	{
		obj.Add(i);
	}
	obj.Print();
	obj.Remove(0);
	obj.Print();*/

	/*SinglyLinkedList obj;
	for (int i = 1; i <= 4; i++)
	{
		obj.Add(i);
	}
	obj.Print();
	obj.Remove(3);
	obj.Print();*/

	/*SinglyLinkedList obj;
	for (int i = 1; i <= 4; i++)
	{
		obj.Add(i);
	}
	obj.Print();
	obj.Remove(1);
	obj.Print();*/

	//Test LastIndexOf
	/*SinglyLinkedList obj;
	for (int i = 1; i <= 4; i++)
	{
		obj.Add(i);
	}
	obj.Add(2);
	obj.Add(3);
	obj.Print();
	int num = 0;
	cout << "num: ";
	cin >> num;
	cout << "last index of " << num << ": " << obj.LastIndexOf(num) << endl;*/

	//Test PrintReverse
	/*SinglyLinkedList obj;
	for (int i = 1; i <= 4; i++)
	{
		obj.Add(i);
	}
	obj.Print();
	obj.PrintReverse();*/

	//Test CopyConstructor
	/*SinglyLinkedList a;
	for (int i = 1; i <= 4; i++)
	{
		a.Add(i);
	}
	a.Print();
	SinglyLinkedList b = a;
	b.Print();*/

	//Test operator =
	//SinglyLinkedList a;
	//for (int i = 1; i <= 4; i++)
	//{
	//	a.Add(i);
	//}
	//a.Print();
	//SinglyLinkedList b;
	//b.Print();
	//b = a;
	////a = b;
	//a.Print();

	//Test Reverse
	/*SinglyLinkedList a;
	for (int i = 1; i <= 4; i++)
	{
		a.Add(i);
	}
	a.Print();
	a.Reverse();
	a.Print();*/

	//Test GetVector
	/*SinglyLinkedList a;
	for (int i = 0; i < 8; i++)
	{
		a.Add(rand() % 35);
	}
	a.Print();
	MyVector v = a.GetMyVector();
	v.Print();*/

	//Test SortAsc
	/*SinglyLinkedList a;
	for (int i = 0; i < 8; i++)
	{
		a.Add(rand() % 35);
	}
	a.Print();
	a.SortAsc();
	a.Print();*/

	//Test SortAsc
	/*SinglyLinkedList a;
	for (int i = 0; i < 8; i++)
	{
		a.Add(rand() % 35);
	}
	a.Print();
	a.SortDesc();
	a.Print();*/

	//Test Shuffle
	/*SinglyLinkedList a;
	for (int i = 0; i < 8; i++)
	{
		a.Add(rand() % 35);
	}
	a.Print();
	a.Shuffle();
	a.Print();*/

	//Test Equals
	//SinglyLinkedList a, b;
	//for (int i = 1; i <= 4; i++)
	//{
	//	a.Add(i);
	//	b.Add(i);
	//}
	////b.Add(-1);
	////b.Remove(0);
	//a.Print();
	//b.Print();
	//cout << "a == b: " << a.Equals(b) << endl;

	//Test Contains
	/*SinglyLinkedList obj;
	for (int i = 1; i <= 4; i++)
	{
		obj.Add(i);
	}
	obj.Print();
	int num = 0;
	cout << "num: ";
	cin >> num;
	cout << "Contains " << num << ": " << obj.Contains(num) << endl;*/

	//Test SetAt
	/*SinglyLinkedList obj;
	for (int i = 0; i < 5; i++)
	{
		obj.Add(i);
	}
	obj.Print();
	int index = 0;
	int num = 0;
	cout << "index: ";
	cin >> index;
	cout << "num: ";
	cin >> num;
	obj.SetAt(index, num);
	obj.Print();*/

	//Test Merge
	/*SinglyLinkedList a, b;
	for (int i = 0; i < 5; i++)
	{
		a.Add(i);
	}
	a.Print();
	for (int i = 10; i < 13; i++)
	{
		b.Add(i);
	}
	b.Print();
	a.MergeWith(b);
	a.Print();

	b.Print();
	b.MergeWith(b);
	b.Print();*/

	// Test operator+
	/*SinglyLinkedList a, b;
	for (int i = 0; i < 5; i++)
	{
		a.Add(i);
	}
	a.Print();
	for (int i = 10; i < 13; i++)
	{
		b.Add(i);
	}
	b.Print();
	SinglyLinkedList c = a + b;
	c.Print();
	SinglyLinkedList d;
	d = b + a;
	d.Print();*/

	//Test operator +=
	SinglyLinkedList a, b;
	for (int i = 0; i < 5; i++)
	{
		a.Add(i);
	}
	a.Print();
	for (int i = 10; i < 13; i++)
	{
		b.Add(i);
	}
	b.Print();
	//a += a;
	a += b;
	a.Print();
	return 0;
}