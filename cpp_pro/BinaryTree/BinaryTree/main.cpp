#include "BinaryTree.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	//Test Search and Add
	/*BinaryTree tree;
	tree.Add(5);
	tree.Add(3);
	tree.Add(2);
	tree.Add(4);
	tree.Add(7);
	tree.Add(6);
	tree.Add(8);
	tree.Print();
	int num{};
	cout << "num: ";
	cin >> num;
	cout << num << " had been found: " << tree.Search(num) << endl;*/

	/*BinaryTree tree;
	tree.Add(5);
	tree.Add(3);
	tree.Add(2);
	tree.Add(4);
	tree.Add(7);
	tree.Add(6);
	tree.Add(8);
	tree.Print();*/

	BinaryTree tree;
	for (int i = 0; i < 10; i++)
	{
		int cur = rand() % 100;
		cout << cur << " ";
		tree.Add(cur);
	}
	cout << endl;
	tree.Print();
	int num{};
	cout << "num: ";
	cin >> num;
	tree.Remove(num);
	//tree.Clear();
	tree.Print();
	//tree.PrintLefterRighter();
	return 0;
}