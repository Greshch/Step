#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
	BinaryTree tree;
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
	cout << num << " had been found: " << tree.Search(num) << endl;
	return 0;
}