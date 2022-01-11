#include <iostream>
#include "MyVector.h"
using namespace std;

int main()
{
	//Test PushBack
	/*MyVector vec;
	for (int i = 1; i <= 5; i++)
	{
		vec.PushBack(i);
	}
	for (int i = 0; i < vec.GetSize(); i++)
	{
		cout << vec[i] << " ";
	}cout << endl;*/

	//Test PushFront
	/*MyVector vec;
	for (int i = 1; i <= 5; i++)
	{
		vec.PushFront(i);
	}
	for (int i = 0; i < vec.GetSize(); i++)
	{
		cout << vec[i] << " ";
	}cout << endl;*/

	//Test Insert
	/*MyVector vec;
	for (int i = 1; i <= 5; i++)
	{
		vec.PushBack(i);
	}
	for (int i = 0; i < vec.GetSize(); i++)
	{
		cout << vec[i] << " ";
	}cout << endl;
	
	vec.Insert(1, 77);

	for (int i = 0; i < vec.GetSize(); i++)
	{
		cout << vec[i] << " ";
	}cout << endl;*/

	//Test RemoveAt
	/*MyVector vec;
	for (int i = 1; i <= 5; i++)
	{
		vec.PushBack(i);
	}
	for (int i = 0; i < vec.GetSize(); i++)
	{
		cout << vec[i] << " ";
	}cout << endl;

	vec.RemoveAt(2);

	for (int i = 0; i < vec.GetSize(); i++)
	{
		cout << vec[i] << " ";
	}cout << endl;*/

	//Test Print
	/*MyVector vec;
	for (int i = 1; i <= 5; i++)
	{
		vec.PushBack(i);
	}
	vec.Print();*/

	//Test Remove
	/*MyVector vec;
	vec.PushBack(1);
	vec.PushBack(2);
	vec.PushBack(1);
	vec.PushBack(1);
	vec.PushBack(3);
	vec.PushBack(4);
	vec.PushBack(1);
	vec.PushBack(5);
	vec.Print();
	vec.Remove(1);
	vec.Print();*/

	//Test PopFront
	/*MyVector vec;
	for (int i = 1; i <= 5; i++)
	{
		vec.PushBack(i);
	}
	vec.Print();
	vec.PopFront();
	vec.Print();*/

	//Test PopBack
	/*MyVector vec;
	for (int i = 1; i <= 5; i++)
	{
		vec.PushBack(i);
	}
	vec.Print();
	vec.PopBack();
	vec.Print();*/

	//Test IndexOf LastIndexOf
	/*MyVector vec;
	vec.PushBack(3);
	vec.PushBack(2);
	vec.PushBack(1);
	vec.PushBack(6);
	vec.PushBack(2);
	vec.PushBack(7);
	vec.PushBack(5);
	vec.Print();
	cout << "First 2 - " << vec.IndexOf(2) << endl;
	cout << "Last 2 - " << vec.LastIndexOf(2) << endl;*/

	/*MyVector vec;
	vec.PushBack(1);
	vec.PushBack(2);
	vec.PushBack(3);
	vec.PushBack(4);
	vec.PushBack(5);
	vec.PushBack(6);
	vec.Print();
	vec.Reverse();
	vec.Print();*/

	//Test SortAsc 
	/*MyVector vec;
	vec.PushBack(3);
	vec.PushBack(2);
	vec.PushBack(1);
	vec.PushBack(6);
	vec.PushBack(7);
	vec.Print();
	vec.SortAsc();
	vec.Print();*/

	// Sort desc Test
	/*MyVector vec;
	vec.PushBack(3);
	vec.PushBack(2);
	vec.PushBack(1);
	vec.PushBack(6);
	vec.PushBack(7);
	vec.Print();
	vec.SortDesc();
	vec.Print();*/

	//Test Shuffle	
	MyVector vec;
	for (int i = 0; i < 10; i++)
	{
		vec.PushBack(i + 1);
	}
	vec.Print();
	vec.Shuffle();
	vec.Print();
	return 0;
}